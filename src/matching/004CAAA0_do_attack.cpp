// VA: 004CAAA0 TRIBE_Combat_Object::do_attack
// Source: t_c_obj.cpp lines 500-542
// The canonical t_c_obj header owns the inherited combat and static classes.

#include "../../include/t_c_obj_context.h"

#ifndef rge_base_game
#define rge_base_game (*(RGE_Base_Game**)0x0062C574)
#endif

extern "C" int __cdecl debug_rand(const char* file, int line);

unsigned char TRIBE_Combat_Object::do_attack(RGE_Static_Object* target,
                                             RGE_Combat_Object* attacker,
                                             float p3, float p4, float p5)
{
    if (target == 0) {
        return 0;
    }

    if (rge_base_game->quick_build != 0) {
        short type = *(short*)((char*)this->object_info + 0x10);
        if (type == 0x7a || type == 0x7b) {
            this->notify(this->field_04, this->field_04, 0x200, 0x258,
                         target->id, 0);
            target->die_die_die();
            return 1;
        }
    }

    if (*(float*)((char*)this->object_info + 0x118) > 0.0f &&
        *(float*)((char*)this->object_info + 0x114) < 0.99f) {
        this->area_attack(p3, p4, p5, attacker, target);
        this->notify(this->field_04, this->field_04, 0x200, 0x258,
                     target->id, 0);
        int r = debug_rand("C:\\msdev\\work\\age1_x1\\t_c_obj.cpp", 0x211);
        int chance = (r * 100) / 0x7fff;
        if (chance <= (int)*(short*)((char*)this->object_info + 0x126)) {
            float mod = this->calc_attack_modifier(target);
            target->damage((int)*(short*)((char*)this->object_info + 0x108),
                           (RGE_Armor_Weapon_Info*)*(int*)((char*)this->object_info + 0x10c),
                           mod,
                           (RGE_Player*)this->field_0C,
                           (RGE_Static_Object*)attacker);
        }
        return 1;
    }

    return RGE_Combat_Object::do_attack(target, attacker, p3, p4, p5);
}
