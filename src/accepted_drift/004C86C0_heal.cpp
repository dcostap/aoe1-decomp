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
// Retry 2026-05-19:
// - split computation through `float maxHpF; amount *= maxHpF; amount /= healRate;` moved first mismatch from +4 to +26 and improved edit diff to 20.31%, but VC5 emits `mov [esp+4],eax; fld st0; fmul [amount]; fild [esp+4]; fdivp` instead of original `fld [amount]; mov [esp+0Ch],eax; fmul st1; fidiv [esp+0Ch]`.
// - explicit `amount = amount * maxHpF` produced same improved basin as compound multiply.
// - trying to write healRate through `*(int*)&amount` before the divide regressed to early-FLD and extra fxch family (45.31% edit).
// - volatile healRate forced a larger stack frame (`sub esp,8`) and broad drift (39.84% edit), rejected.
// Left in scratch: improved split-computation basin below; remaining drift is the FPU setup/divide instruction family and shifted tail, not accepted-drift quality.
// Retry 2026-05-19/20 assigned pass:
// - `float amt=amount; *(int*)&amount=healRate; amount=(amt*maxHpF)/(float)*(int*)&amount` regressed to early FLD/fxch family (78.125% positional), rolled back.
// - `amount *= maxHpF / (float)healRate` improved to 5.4688% positional but computes ratio first (`fdivr st1; fmul [amount]`) rather than original multiply-then-fidiv.
// - `amount = maxHpF * amount / healRate` is best: exact size 128B, 7.0312% positional / 3.9062% edit, first mismatch +27 only. Tail fully resyncs.
// - `amount = (amount * maxHpF) / (float)healRate` regressed to shifted fild/fdivp family (71.0938% positional), rolled back.
// - `amount = (float)maxHp * amount / healRate` regressed to early FLD/fxch family (81.25% positional), rolled back.
// - explicit `float healRateF` forced `sub esp,8` stack-frame basin (91.4062%), rolled back.
// - /Op flag probe was much worse (`sub esp,8`, 93.75%), flag removed.
// ACCEPTED_DRIFT 2026-05-19: approved localized behavior-equivalent FPU setup drift.
// Original uses `fld [amount]; mov [amount],healRate; fmul st1`; rebuilt uses
// `fld st0; fmul [amount]; mov [amount],healRate`. In both sequences ST0 becomes
// maxHp*amount and ST1 remains maxHp before the same `fidiv [amount]`; all later
// calls, branches, stores, stack cleanup, and returns resync exactly.

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
    float maxHpF = (float)maxHp;
    amount = maxHpF * amount / healRate;
    if (amount + this->hp > maxHpF) {
        amount = maxHpF - this->hp;
    }
    if (this->owner->pay_obj_cost(*(short*)((char*)master + 0x10), amount / (float)(maxHp * 2), 0)) {
        return TRIBE_Combat_Object::heal(amount);
    }
    return 2;
}
