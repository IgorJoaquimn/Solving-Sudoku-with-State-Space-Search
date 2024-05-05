#include "SearchBasic.h"

State *Search_Base::search()
{
    // Start at the initial state
    this->current_state = this->initial_state;
    this->update_tree(this->current_state->get_children());
    //  While there is no solution
    while ((!this->current_state->is_final()) and (this->exists_next()))
    {
        this->expanded_states++;
        
        // Desalloc from memory
        delete this->current_state;

        // Get the next state to consider ( it depends if the Search is a BFS, IDS, UCS or etc.)
        this->current_state = this->get_next_state(); // Check each class src code to get the details
        
        // Otherwise, add the neighbors of the current state and process it
        this->update_tree(this->current_state->get_children()); // Check each class src code to get the details
    }

    // Control if this method is in Iterative Search Mode
    bool limited_search = (this->max_lim != -1);
    // Recurrence to the Iterative Search Mode always return
    if (limited_search && (!this->current_state->is_final()))
    {
        if(this->max_lim > 9*9)
            return this->current_state;
            
        this->max_lim = this->max_lim * 2;
        this->clear();
        return this->search();
    }

    return this->current_state;
};
