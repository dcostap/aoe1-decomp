// SOURCE NOTE: One canonical base call replaces the old context-only fork.
// The reduced grouped source remains exact.
#include "../../include/m_mi_obj_context.h"

void RGE_Master_Missile_Object::modify_delta(float param_1, unsigned char param_2) {
    if (param_2 == 0x13) {
        this->field_149 = (unsigned char)(int)param_1;
    }
    RGE_Master_Combat_Object::modify_delta(param_1, param_2);
}
