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
        {
            for (int j = 0; j < N; ++j)
            {
                misplaced_tiles += (state->state[i][j] == 0);
            }
        }
        return misplaced_tiles;
    }
};

#endif /* GBFS_H */
