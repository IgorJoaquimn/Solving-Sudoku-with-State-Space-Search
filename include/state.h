#ifndef STATE_H
#define STATE_H

#include <cstdint>
#include <utility>
#include <vector>
#include <memory>


const int N = 9;

class State {
public:
    uint8_t state[N][N];
    int cost = 0;
    int path_cost = 0;
    int h_cost = 0;

    State * father = nullptr;

    // Default constructor
    State();

    // Constructor with another State object as argument
    State(State& otherState); 
    State(State* otherState); 

    // Assignment operator
    State& operator=(const State& otherState);
    State& operator=(const State* otherState);

    // Function to find the (i,j) of the first zero in the matrix
    std::pair<int, int> find_free() const;

    uint32_t find_possible(std::pair<int, int> coordinates) const;
    std::vector<State *> get_children();
    bool is_final();

    bool operator<(const State& other) const;

};

class StateComparator {
public:
    bool operator()(State* lhs, State* rhs) const {
        // Define your custom comparison logic here
        // For example, compare cost or some other metric:
        return lhs->cost > rhs->cost;
    }
};

#endif /* STATE_H */
