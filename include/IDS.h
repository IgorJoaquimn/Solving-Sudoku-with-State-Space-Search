#ifndef IDS_H
#define IDS_H

#include <stack>
#include "SearchBasic.h"

class IDS : public Search_Base {
private:
    std::stack<State*> s;

public:
    // Constructor
    IDS(State* initial_state) : Search_Base(initial_state) {
        // s.push(initial_state);
        this->max_lim = 1;
    }

    bool exists_next() override
    {
        return s.size() != 0;
    };

    State* get_next_state() override {
        auto t = s.top();
        s.pop();
        return t;
    }

    void update_tree(std::vector<State*> states) override {
        for (State* state : states) {
            if(state->path_cost > this->max_lim)
                break;
            s.push(state); // Push each pointer to the stack
        }
    }
    
    void clear() {
        while (!s.empty()) {
            delete s.top();
            s.pop();
        }
        initial_state = new State(*initial_state_copy);
        s.push(new State(*initial_state_copy));
    }

    // Destructor
    ~IDS() {
        while (!s.empty()) {
            delete s.top();
            s.pop();
        }

        delete this->initial_state_copy;
    }
};

#endif /* IDS_H */
