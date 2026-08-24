#include "../../include/tact_rep_context.h"

void TRIBE_Action_Repair::first_in_stack(unsigned char value) {
    if (value != 0 && this->target_obj != 0) {
        this->set_state(4);
        return;
    }
    this->set_state(3);
}
