#include "state.h"

// Constructor with another State object as argument
State::State(State &otherState)
{
    // Copy the state from the other State object
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            state[i][j] = otherState.state[i][j];
    
    cost = otherState.cost;
    path_cost = otherState.path_cost;
}

// Default constructor
State::State()
{
    // Initialize matrix to all zeros
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            state[i][j] = 0;
}

// Copy constructor with a pointer to another State object
State::State(State *otherStatePtr) {
    if (otherStatePtr != nullptr) {
        // Copy the state matrix from the other State object
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                state[i][j] = otherStatePtr->state[i][j];
            }
        }
        // Copy the cost
        cost = otherStatePtr->cost;
        path_cost = otherStatePtr->path_cost;
        this->father = otherStatePtr;
    }
}

bool State::operator<(const State& other) const
{
    return this->cost < other.cost;
}


// Function to find the (i,j) of the first zero in the matrix
std::pair<int, int> State::find_free() const
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (state[i][j] == 0)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1}; // No free cell found
}

// Function to find possible values for a given cell
uint32_t State::find_possible(std::pair<int, int> coordinates) const
{
    int row = coordinates.first;
    int col = coordinates.second;

    if (row == -1)
        return 0;

    uint32_t rowMask = 0;
    uint32_t colMask = 0;
    uint32_t subgridMask = 0;

    // Populate masks for row, column, and subgrid
    for (int i = 0; i < N; ++i)
    {
        if (state[row][i] != 0)
            rowMask |= (1 << state[row][i]);
        if (state[i][col] != 0)
            colMask |= (1 << state[i][col]);
    }

    int subgridRow = row / 3;
    int subgridCol = col / 3;
    for (int i = 3 * subgridRow; i < 3 * (subgridRow + 1); ++i)
    {
        for (int j = 3 * subgridCol; j < 3 * (subgridCol + 1); ++j)
        {
            if (state[i][j] != 0)
                subgridMask |= (1 << state[i][j]);
        }
    }

    // Combine masks to get the forbidden values
    uint32_t forbiddenValues = rowMask | colMask | subgridMask;
    return ~forbiddenValues;
}

std::vector<State *> State::get_children()
{
    std::vector<State *> children;
    std::pair<int, int> cell = this->find_free();
    int possible_values = this->find_possible(cell);

    // Create a new child state for each possible value
    for (int value = 1; value <= 9; ++value)
    {
        if (possible_values & (1 << value))
        {                                                        // Check if value is possible
            State *child_state = new State(this);               // Create a copy of the parent state
            child_state->state[cell.first][cell.second] = value; // Assign the value to the empty cell
            child_state->path_cost = this->path_cost + 1;                  // Set the cost
            child_state->father = this;
            children.push_back(child_state);                     // Add the child state to the vector
        }
    }

    return children;
}

bool State::is_final()
{
    std::pair<int, int> cell = this->find_free();
    return (cell.first == -1);
}

State& State::operator=(const State& otherState) {
    // Check for self-assignment
    if (this == &otherState) {
        return *this;
    }
    
    // Copy the state matrix from the otherState
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            state[i][j] = otherState.state[i][j];
        }
    }
    // Copy the cost
    cost = otherState.cost;

    // Return *this to allow chaining of assignment
    return *this;
}

State& State::operator=(const State* otherState) {
    // Check for self-assignment
    if (this == otherState) {
        return *this;
    }
    
    // Copy the state matrix from the otherState
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            state[i][j] = otherState->state[i][j];
        }
    }
    // Copy the cost
    cost = otherState->cost;

    // Return *this to allow chaining of assignment
    return *this;
}