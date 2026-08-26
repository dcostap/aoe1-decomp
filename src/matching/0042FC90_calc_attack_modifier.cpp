extern "C" float g_attack_modifier;

#include "../com_obj_phase2_context.h"

float RGE_Combat_Object::calc_attack_modifier(RGE_Static_Object* unused) {
    return g_attack_modifier;
}
