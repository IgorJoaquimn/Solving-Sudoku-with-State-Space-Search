#ifndef BFS_H
#define BFS_H

#include <queue>
#include "SearchBasic.h"

class BFS : public Search_Base {
private:
    std::queue<State*> q;

public:
    // Constructor
    BFS(State* initial_state) : Search_Base(initial_state) {
        q.push(initial_state);
    }

    State* get_next_state() override
    {
        auto t = q.front();
        q.pop();
        return t;
    };
    void update_tree(std::vector<State*> states) override {
        for (State* state : states) {
            q.push(state); // Enqueue each pointer to the queue
        }
    }
    
    // Clear the queue
    void clear() {
        while (!q.empty()) {
            delete q.front();
            q.pop();
        }
    }

    // Destructor
    ~BFS() {
        while (!q.empty()) {
            delete q.front();
            q.pop();
        }
    }
};

#endif /* BFS_H */