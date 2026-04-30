// VA: 00454980 calc_base_damage_ability (95B)
// m_s_obj.cpp

class RGE_Master_Combat_Object {
public:
    char gap_00[0x108];
    short weapon_num;
    char pad_10A[0x2];
    char* weapon;
};

class RGE_Master_Static_Object {
public:
    long calc_base_damage_ability(RGE_Master_Combat_Object* param);
};

long RGE_Master_Static_Object::calc_base_damage_ability(RGE_Master_Combat_Object* param) {
    float total = 0.0f;
    int count = param->weapon_num;
    char* weapon_start = param->weapon;
    if (count > 0) {
        char* entry = weapon_start + 2;
        do {
            short val = *(short*)entry;
            float fval = (float)val;
            if (fval > 0.0) {
                total = total + fval;
            }
            entry += 4;
            count--;
        } while (count != 0);
    }
    if (total < 1.0) {
        total = 1.0f;
    }
    return (long)total;
}
