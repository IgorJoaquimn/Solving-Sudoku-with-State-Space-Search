#include "SearchBasic.h"

State *Search_Base::search()
{
    // Start at the initial state
    this->current_state = this->initial_state;
    // Control if this method is in Iterative Search Mode
    bool limited_search = (this->lim != -1);
    //  While there is no solution
    while (true)
    {
        // Get the next state to consider ( it depends if the Search is a BFS, IDS, UCS or etc.)
        this->current_state = this->get_next_state(); // Check each class src code to get the details

        if (this->current_state->is_final())
            break; // Termination occurs when we are in the final state

        // Otherwise, add the neighbors of the current state and process it
        this->update_tree(this->current_state->get_children()); // Check each class src code to get the details

        // In limited search, check if limit is passed
        if ((limited_search && (!(this->lim--))))
            break; // If this is the last iteration, terminates

        // Desalloc from memory
        // delete this->current_state;
        // for (int i = 0; i < N; ++i)
        // {
        //     for (int j = 0; j < N; ++j)
        //     {
        //         std::cout << char(this->current_state->state[i][j] + '0') << " ";
        //     }
        //     std::cout << std::endl;
        // }

        // std::cout << std::endl;
    }

    // Recurrence to the Iterative Search Mode always return
    if (!this->current_state->is_final())
    {
        this->max_lim += this->max_lim * 2;
        this->lim = this->max_lim;
        this->clear();
        return this->search();
    }

    return this->current_state;
};
