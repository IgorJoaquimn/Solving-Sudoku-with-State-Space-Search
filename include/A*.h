#ifndef A_STAR_H
#define A_STAR_H

#include "UCS.h"

class A_STAR : public UCS
{
public:
    // Constructor
    A_STAR(State *initial_state) : UCS(initial_state) {}

    // Redefined h() function implementing a heuristic
    int h(State *state) override
    {
        int placed_tiles = 0;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                placed_tiles += (state->state[i][j] != 0);
        return 2*(81 - placed_tiles);
    }
};

#endif /* A_STAR_H */
