#ifndef UCS_H
#define UCS_H

#include <queue>
#include "SearchBasic.h"

class UCS : public Search_Base {
private:
    std::priority_queue<State*> pq;

public:
    // Constructor
    UCS(State* initial_state) : Search_Base(initial_state) {
        pq.push(initial_state);
    }

    State* get_next_state() override {
        auto t = pq.top();
        pq.pop();
        return t;
    }

    void update_tree(std::vector<State*> states) override {
        for (State* state : states) {
            state->cost = f(state);
            pq.push(state);
        }
    }

    int f(State* state) {
        return g(state) + h(state);
    }

    virtual int g(State* state) {
        return state->cost;
    }

    virtual int h(State* state) {
        return 0;
    }

    void clear() {
        while (!pq.empty()) {
            delete pq.top();
            pq.pop();
        }
        pq.push(new State(*initial_state_copy));
    }   

    // Destructor
    ~UCS() {
        while (!pq.empty()) {
            delete pq.top();
            pq.pop();
        }

        delete this->initial_state_copy;
    }
};

#endif /* UCS_H */
