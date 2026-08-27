#include "../../include/tact_hea.h"
int TRIBE_Action_Heal::work(RGE_Static_Object* target, float, float, float) {
    if (target != 0) {
        if (target == this->target_obj) {
            unsigned char s = this->state;
            if (s == 4 || s == 6 || s == 7) return 1;
        }
        this->set_target_obj(target);
        this->target_x = target->world_x;
        this->target_y = target->world_y;
        this->target_z = target->world_z;
        this->first_in_stack(1);
        return 1;
    }
    return 0;
}
