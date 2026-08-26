#include "../com_obj_phase2_context.h"

void RGE_Combat_Object::get_weapon_range(float& a, float& b) {
    a = this->master_obj->weapon_range;
    b = this->master_obj->orig_weapon_range;
}
