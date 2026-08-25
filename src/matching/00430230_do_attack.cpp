// VA: 00430230 RGE_Combat_Object::do_attack
// PDB: com_obj.cpp:361-390, 234 bytes
// FLAGS: default

#ifndef RGE_COM_OBJ_SHARED_CONTEXT
extern "C" int __cdecl debug_rand(const char* file, int line);
#include "../com_obj_fallback_do_attack.h"
#endif

unsigned char RGE_Combat_Object::do_attack(RGE_Static_Object* target, RGE_Combat_Object* attacker, float p3, float p4, float p5)
{
    if (target == 0) {
        return 0;
    }

    if (*(float*)((char*)this->object_info + 0x118) > 0.0f) {
        this->area_attack(p3, p4, p5, attacker, 0);
        return 1;
    }

    this->notify(this->field_04, this->field_04, 0x200, 0x258, target->id, 0);
    int r = debug_rand("C:\\msdev\\work\\age1_x1\\com_obj.cpp", 0x17b);
    int chance = (r * 100) / 0x7fff;
    if (chance <= (int)*(short*)((char*)this->object_info + 0x126)) {
        float mod = this->calc_attack_modifier(target);
        target->damage((int)*(short*)((char*)this->object_info + 0x108),
                      *(RGE_Armor_Weapon_Info**)((char*)this->object_info + 0x10c),
                      mod,
                      (RGE_Player*)this->field_0C,
                      (RGE_Static_Object*)attacker);
    }
    return 1;
}
