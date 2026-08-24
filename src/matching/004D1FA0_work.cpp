// VA: 004D1FA0 TRIBE_Action_Repair::work

#include "../../include/tact_rep_context.h"

int TRIBE_Action_Repair::work(RGE_Static_Object* target, float param_2, float param_3, float z) {
    if (target != 0) {
        if (target == this->target_obj) {
            unsigned char state = this->state;
            if (state == 4 || state == 6) {
                return 1;
            }
        }
        this->set_target_obj(target);
        this->target_x = target->world_x;
        this->target_y = target->world_y;
        this->target_z = target->world_z;
        this->meet_target();
        this->set_state(4);
        return 1;
    }
    this->target_x = param_2;
    this->target_y = param_3;
    this->target_z = z;
    this->set_target_obj(0);
    this->set_state(11);
    return 1;
}
