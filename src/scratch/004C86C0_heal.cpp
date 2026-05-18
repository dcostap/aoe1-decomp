// VA: 004C86C0 TRIBE_Building_Object::heal (128 B)
// PDB source: t_b_obj.cpp lines 272-285
// Attempt log:
// try 1: baseline with memcpy(&amt,&amount,4): exact size 128B but 110 positional diff bytes / 85.94%; extra param reload/store before master load shifts most body.
// try 2: removed memcpy and used direct `amount * maxHp / healRate`; worsened FPU ordering, compiler loads `amount` before master/int loads.
// try 3: `float amt; amt = amount; amt = ...`; no improvement, same early FLD basin.
// try 4: assigned back to source parameter `amount = ...`; no improvement, same early FLD basin.
// try 5: swapped multiplication operand order `maxHp * amount`; no codegen change.
// tries 6-7: reviewed original FPU topology: master load and movsx max/rate first, fild max, then fld amount, store healRate into param slot, fmul st1, fidiv param slot. Current source cannot keep that without either early FLD or extra memcpy copy.
// try 8: tail/pay_obj_cost and base heal call sequence is aligned after resync; main remaining issue is early FPU scheduling/stack-slot setup causing broad shift.
// try 9: accepted_drift review rejected: although behavior/calls look aligned, diff spans most function due shifted FPU setup and tail addresses; not localized.
// try 10: final validation remains exact size 128B but broad mismatch. GIVEUP.

#include <string.h>

class TRIBE_Player {
public:
    unsigned char pay_obj_cost(short type, float amount, int flag);
};

class TRIBE_Combat_Object {
public:
    unsigned char heal(float amount);
};

class TRIBE_Building_Object : public TRIBE_Combat_Object {
public:
    void* vtable;
    int id;
    void* master_obj;
    TRIBE_Player* owner;
    void* sprite;
    void* old_sprite;
    void* sprite_list;
    void* tile;
    void* inside_obj;
    void* objects;
    short screen_x_offset;
    short screen_y_offset;
    short shadow_x_offset;
    short shadow_y_offset;
    float hp;

    unsigned char heal(float amount);
};

unsigned char TRIBE_Building_Object::heal(float amount)
{
    void* master = this->master_obj;
    int maxHp = *(short*)((char*)master + 0x26);
    int healRate = *(short*)((char*)master + 0x15A);
    amount = ((float)maxHp * amount) / (float)healRate;
    if (amount + this->hp > (float)maxHp) {
        amount = (float)maxHp - this->hp;
    }
    if (this->owner->pay_obj_cost(*(short*)((char*)master + 0x10), amount / (float)(maxHp * 2), 0)) {
        return TRIBE_Combat_Object::heal(amount);
    }
    return 2;
}
