#include "../com_obj_phase2_context.h"

void RGE_Combat_Object::get_armor(short& armor, short& original_armor) {
    int i;

    armor = master_obj->base_armor;
    for (i = 0; i < master_obj->armor_num; ++i) {
        if (master_obj->armor[i].value > armor) {
            armor = master_obj->armor[i].value;
        }
    }
    original_armor = master_obj->orig_armor;
}
