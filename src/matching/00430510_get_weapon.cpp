#include "../com_obj_phase2_context.h"

void RGE_Combat_Object::get_weapon(short& weapon, short& original_weapon) {
    int i;

    weapon = 0;
    for (i = 0; i < master_obj->weapon_num; ++i) {
        if (master_obj->weapon[i].value > weapon) {
            weapon = master_obj->weapon[i].value;
        }
    }
    original_weapon = master_obj->orig_weapon;
}
