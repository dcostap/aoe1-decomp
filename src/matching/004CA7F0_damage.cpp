// VA: 004CA7F0 TRIBE_Combat_Object::damage
// Canonical ownership is the shipped t_c_obj class surface.

#include "../../include/t_c_obj_context.h"

extern double DAT_00574c88;
extern float DAT_00574c78;

void TRIBE_Combat_Object::damage(int param_1, RGE_Armor_Weapon_Info* armor,
                                 float value, RGE_Player* player,
                                 RGE_Static_Object* target)
{
    float temp_hp = this->hp;

    if (this->hp >= DAT_00574c88) {
        RGE_Combat_Object::damage(param_1, armor, value, player, target);

        if (this->hp < DAT_00574c88) {
            if (this->produceWhenKilledBy(
                    (int)target->master_obj->object_group) == 0) {
                this->set_attribute_amount(0.0f, 0, 1);
            }
        }

        if (temp_hp - this->hp < DAT_00574c88) {
            this->hp = temp_hp - DAT_00574c78;
        }

        if (this->owner->id > 0 && this->hp < DAT_00574c78) {
            player->add_attribute_num(0x14, 1.0f, 0);
        }
    }
}
