// attempt log:
// first pass: direct sum-of-positive-table-values spelling with a final 1.0 floor and ftol-style return
// second pass: switch to double accumulation and short/int locals to chase the x87 fild/faddp basin
// third pass: restore float zero-init and move the entry pointer setup after the count gate to mirror the asm ordering
// fourth pass: force a named float addend so VC5 may choose fild + faddp instead of fiadd
// fifth pass: move the table base load before the count gate to match the original register order
// target shape: iterate param->weapon_num entries at param->weapon, add positive word[+2] values, clamp minimum to 1.0, return long
// paused here: remaining mismatch is a small but stubborn loop-register / compare-order basin around the positive-only add and final floor

class RGE_Master_Combat_Object {
public:
    char gap_00[0x108];
    short weapon_num;
    short _pad_10A;
    char* weapon;
};

class RGE_Master_Static_Object {
public:
    long calc_base_damage_ability(RGE_Master_Combat_Object* param);
};

long RGE_Master_Static_Object::calc_base_damage_ability(RGE_Master_Combat_Object* param) {
    float total = 0.0f;
    int count = param->weapon_num;
    char* entry = param->weapon + 2;
    if (count > 0) {
        do {
            short value = *(short*)entry;
            if (value > 0) {
                float addend = (float)value;
                total = total + addend;
            }
            entry += 4;
            count--;
        } while (count != 0);
    }

    if (total < 1.0f) {
        total = 1.0f;
    }
    return (long)total;
}
