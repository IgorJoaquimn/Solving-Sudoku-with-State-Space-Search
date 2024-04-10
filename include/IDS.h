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
        s.push(initial_state);
        this->lim = 1;
        this->max_lim = 1;
    }

    State* get_next_state() override {
        auto t = s.top();
        s.pop();
        return t;
    }

    void update_tree(std::vector<State*> states) override {
        for (State* state : states) {
            s.push(state); // Push each pointer to the stack
        }
    }
    
    void clear() {
        while (!s.empty()) {
            delete s.top();
            s.pop();
        }
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
