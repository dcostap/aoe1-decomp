#include "../com_obj_phase2_context.h"

void RGE_Combat_Object::get_speed_of_attack(float& a, float& b) {
    a = this->master_obj->speed_of_attack;
    b = this->master_obj->orig_speed_of_attack;
}
