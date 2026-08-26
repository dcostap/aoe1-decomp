#include "../com_obj_phase2_context.h"

float RGE_Combat_Object::damageCapability(RGE_Static_Object* target) {
    float base_damage;

    base_damage = target->calc_attack_modifier((RGE_Static_Object*)this);
    return calculateDamage(target->master_obj->weapon_num, target->master_obj->weapon, base_damage, target->owner, target);
}
