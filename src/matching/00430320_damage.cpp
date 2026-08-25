// VA: 00430320 RGE_Combat_Object::damage
// Source: com_obj.cpp lines 398-425

#ifndef RGE_COM_OBJ_SHARED_CONTEXT
#include "../com_obj_fallback_damage.h"
#endif

void RGE_Combat_Object::damage(int param_1, RGE_Armor_Weapon_Info* armor, float value, RGE_Player* player, RGE_Static_Object* target) {
    hp -= calculateDamage(param_1, armor, value, player, target);
    if (target != 0) {
        notify(target->id, id, 0x1F4, target->id, (int)hp, master_obj->hp);
    }
    if (hp < 1.0) {
        hp = 0.0f;
    }
}
