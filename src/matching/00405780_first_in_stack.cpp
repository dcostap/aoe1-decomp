// attempt 1: natural first-in-stack checks with direct object and position calls
// The target branch uses inRange, then the action-object speed and state methods.

#ifndef ACT_MOVE_CANONICAL_TU
#include "../../include/act_move_context.h"
#endif

void RGE_Action_Move_To::first_in_stack(unsigned char param_1) {
    if (this->target_obj != 0) {
        if (this->obj->inRange(this->target_obj, this->range) != 0) {
            this->set_state(1);
            return;
        }
    }

    if (this->obj->maximumSpeed() == 0.0) {
        this->set_state(0x0D);
        return;
    }

    this->set_state(3);
}
