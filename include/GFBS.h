#ifndef GBFS_H
#define GBFS_H

#include "UCS.h"

class GBFS : public UCS {
public:
    // Constructor
    GBFS(State* initial_state) : UCS(initial_state) {
        initial_state->h_cost = h(initial_state);
    }

    // Redefined g() function that always returns 0
    int g(State* state) override {
        return 0;
    }

    // Redefined h() function implementing a different heuristic
    int h(State* state) override {
        int misplaced_tiles = 0;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                misplaced_tiles += (state->state[i][j] == 0);
        
        int possible_values = state->find_possible(state->find_free());
        int aux = 0;
        for (int value = 1; value <= 9; ++value)
            if (possible_values & (1 << value))
                aux++;
        return (misplaced_tiles + aux/(state->path_cost + 0.001))/2;
    }

private:
    // Helper function to calculate the Manhattan distance of a tile from its goal position
    int manhattan_distance(int row, int col, int value) const {
        // Calculate the goal position of the tile
        int goal_row = (value - 1) / N;
        int goal_col = (value - 1) % N;
        // Calculate and return the Manhattan distance
        int val = abs(row - goal_row) + abs(col - goal_col);
        return val;
    }
};

#endif /* GBFS_H */
