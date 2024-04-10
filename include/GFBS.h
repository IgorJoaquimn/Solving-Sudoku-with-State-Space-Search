#ifndef GBFS_H
#define GBFS_H

#include "UCS.h"

class GBFS : public UCS {
public:
    // Constructor
    GBFS(State* initial_state) : UCS(initial_state) {}

    // Redefined g() function that always returns 0
    int g(State* state) override {
        return 0;
    }

    // Redefined h() function implementing a different heuristic
    int h(State* state) override {
        int total_manhattan_distance = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (state->state[i][j] != 0) { // Skip the empty cell
                    total_manhattan_distance += manhattan_distance(i, j, state->state[i][j]);
                }
            }
        }
        return total_manhattan_distance;
    }

private:
    // Helper function to calculate the Manhattan distance of a tile from its goal position
    int manhattan_distance(int row, int col, int value) const {
        // Calculate the goal position of the tile
        int goal_row = (value - 1) / N;
        int goal_col = (value - 1) % N;
        // Calculate and return the Manhattan distance
        return abs(row - goal_row) + abs(col - goal_col);
    }
};

#endif /* GBFS_H */
