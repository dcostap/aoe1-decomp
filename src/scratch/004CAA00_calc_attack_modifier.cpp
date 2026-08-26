// VA: 004CAA00 TRIBE_Combat_Object::calc_attack_modifier
// Canonical ownership is the shipped TRIBE_Combat_Object class in t_c_obj.cpp.
// The grouped t_c_obj context supplies the complete inherited ABI surface.

#include "../../include/t_c_obj_context.h"

float TRIBE_Combat_Object::calc_attack_modifier(RGE_Static_Object* param_1)
{
    RGE_Master_Static_Object* master =
        ((RGE_Static_Object*)this)->master_obj;
    // Binary note: t_c_obj reads this master field at +0x124.
    if (*(short*)((char*)master + 0x124) >= 0) {
        if (this->higher_than_target(param_1) != 0)
            return 1.5f;
    }
    else {
        if (this->world_z < param_1->world_z)
            return 0.6666f;
    }

    return 1.0f;
}
