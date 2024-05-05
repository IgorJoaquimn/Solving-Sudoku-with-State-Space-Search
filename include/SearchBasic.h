#ifndef SEARCH_BASE
#define SEARCH_BASE

#include "state.h"
#include <queue>
#include <iostream>

class Search_Base {
public:
    State *initial_state;
    State *current_state;
    State *initial_state_copy;
    int max_lim = -1;
    uint expanded_states = 0; 
    // Constructor with another State object as argument
    Search_Base(State * initial_state) {
        this->initial_state = initial_state;
        this->initial_state_copy = new State(*initial_state);
    }

    State * search(); // Pure virtual function for search
    virtual State* get_next_state() = 0;  // Pure virtual function for top
    virtual void update_tree(std::vector<State *>) = 0;  // Pure virtual function for top
    virtual bool exists_next() = 0;  // Pure virtual function for top
    virtual void clear() = 0;
    virtual ~Search_Base() { };
};


#endif /* COMPRESSION */