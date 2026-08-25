// RGE_Action_Move_To::is_in_range
// Natural range checks use the action object's distance and inRange members.

#ifndef ACT_MOVE_CANONICAL_TU
#include "../../include/act_move_context.h"
#endif

unsigned char RGE_Action_Move_To::is_in_range() {
    float distance;

    if (this->range > 0.0f) {
        if (this->target_obj != 0) {
            distance = this->obj->distance_to_object(this->target_obj);
        } else {
            distance = this->obj->distance_to_position(this->target_x, this->target_y, this->target_z);
        }
        if (distance <= this->range) {
            return 1;
        }
    } else {
        if (this->target_obj != 0 && this->obj->inRange(this->target_obj, 0.25f) != 0) {
            return 1;
        }
    }
    return 0;
}
