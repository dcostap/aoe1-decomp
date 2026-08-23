// PDB owner: RGE_Static_Object, not the former derived-class surrogate.
#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
struct RGE_Armor_Weapon_Info {
    char gap_00[2];
    short value;
};

class RGE_Player;
class RGE_Static_Object;

float __cdecl zero_float_574720();

class RGE_Static_Object {
public:
    virtual float calculateDamage(int count, RGE_Armor_Weapon_Info* info, float scale, RGE_Player* player, RGE_Static_Object* object);
};

#endif

float RGE_Static_Object::calculateDamage(int count, RGE_Armor_Weapon_Info* info, float scale, RGE_Player*, RGE_Static_Object*) {
    float damage = 0.0f;

    if (count > 0) {
        short* value = &info->value;
        do {
            damage = (float)(int)(*value) * scale + damage;
            value = value + 2;
            count = count - 1;
        } while (count != 0);
    }
    return damage;
}
