// 004CC4C0 TRIBE_Combat_Object::heal
// t_c_obj.cpp lines 1637-1657, 173 bytes
// Retry 2026-05-21 Boss pass: replaced stub with natural member source and tried
// max/denominator locals as int/long, direct denominator expression, separate
// heal_amount local, split *= and /=, operand order swaps, cast/no-cast denominator,
// and both `max < amount+hp` and `amount+hp > max` comparison spellings. Best kept
// is exact-size but mismatching: first 56 bytes match through type dispatch/base-heal
// fallback, then FPU codegen diverges because VC5 emits an fild/fxch family instead
// of original fild max; fld param; store denom; fmul st1; fidiv stack-slot sequence.
// Not accepted_drift-worthy: remaining drift is broad FPU scheduling/stack topology.

struct RGE_Static_Object {
    char gap_00[8];
    void* master_obj;       // +0x08
    void* player;           // +0x0C
    char gap_10[0x20];
    float hit_points;       // +0x30

    unsigned char heal(float amount);
};

struct TRIBE_Player {
    unsigned char pay_obj_cost(short type, float amount, int flag);
};

struct TRIBE_Combat_Object : RGE_Static_Object {
    unsigned char heal(float amount);
};

unsigned char TRIBE_Combat_Object::heal(float amount)
{
    void* master = this->master_obj;
    short type = *(short*)((char*)master + 0x14);
    if (type != 2 && type != 0x14 && type != 0x15 && type != 0x16) {
        return RGE_Static_Object::heal(amount);
    }

    long max_hp = *(short*)((char*)master + 0x26);
    long heal_rate = *(short*)((char*)master + 0x15A);
    amount = amount * (float)max_hp / heal_rate;
    if (amount + this->hit_points > (float)max_hp) {
        amount = (float)max_hp - this->hit_points;
    }

    if (((TRIBE_Player*)this->player)->pay_obj_cost(*(short*)((char*)master + 0x10), amount / (float)(max_hp * 2), 1)) {
        return RGE_Static_Object::heal(amount);
    }
    return 2;
}
