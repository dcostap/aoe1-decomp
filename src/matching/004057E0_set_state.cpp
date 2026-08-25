// 004057E0 RGE_Action_Move_To::set_state
// The state transitions use the action object's real new_sprite virtual.

#ifndef ACT_MOVE_CANONICAL_TU
#include "../../include/act_move_context.h"
#endif

void RGE_Action_Move_To::set_state(unsigned char param_1)
{
    this->state = param_1;

    switch (param_1) {
    case 4:
        this->obj->new_sprite(this->sprite);
        return;
    case 1:
    case 13:
    case 14:
        if (this->subActionValue == 0) {
            this->obj->new_sprite(this->obj->master_obj->sprite);
        }
        return;
    default:
        return;
    }
}
