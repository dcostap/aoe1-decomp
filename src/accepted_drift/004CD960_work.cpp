// VA: 004CD960 TRIBE_Action_Build::work
// left in scratch: behavior/core matched, but remaining 9-byte drift is load/register order.
// Original owner check loads actor into EDX first, then target owner into ECX; VC5 uses ECX first.
// Fallback coordinate stores also reload stack params in a different order despite source z,x,y and int punning.
// SpruceGlow tries 1-10: actor local/owner locals, reversed compare, direct float stores, z/x/y int-pun forms,
//   explicit param local order, goto fallback, nested positive form, direct action condition. No improvement;
//   actor local first was worse (edit 29), goto much worse, most stayed at same 9-byte register/load-order diff.
// SpruceGlow tries 11-20: raw owner offset loads, delayed actor owner, alternate fallback load/store order,
//   vtable local, inverted condition, char* int-puns, direct float lvalue forms. Same 9-byte diff.
// SpruceGlow tries 21-30: owner-id helper, short/int owner-id locals, volatile actor, union/pointer/volatile
//   fallback parameter loads, extra vtable local, action switch, and else-nesting. Same 9-byte diff or worse
//   (helper/action-switch/volatile/union variants drifted substantially).
// === ACCEPTED_DRIFT ===
// Diff is register/load-order only in owner-id comparison and fallback coordinate reload/store ordering;
// branches, calls, stack cleanup, stores to same fields, and return values are otherwise identical.
// No inline asm/hacks.

#ifndef TACT_BLD_CONTEXT_H
class RGE_Static_Object;

class TRIBE_Action_Build {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void set_target_obj(RGE_Static_Object* target);
    virtual void vf58();
    virtual int set_state(int type);

    void* vptr2;                    // 0x04
    RGE_Static_Object* obj;         // 0x08
    unsigned char state;            // 0x0c
    char gap_0d[3];
    RGE_Static_Object* target_obj;  // 0x10
    char gap_14[0x0c];
    float target_x;                 // 0x20
    float target_y;                 // 0x24
    float target_z;                 // 0x28

    int work(RGE_Static_Object* target, float param_2, float param_3, float param_4);
};

struct OwnerInfo {
    char gap_00[0x4a];
    short id;
};

class RGE_Static_Object {
public:
    char gap_00[0x0c];
    OwnerInfo* owner;
};

#endif

int TRIBE_Action_Build::work(RGE_Static_Object* target, float param_2, float param_3, float param_4) {
    if (target != 0 && target->owner->id == this->obj->owner->id) {
        if (target == this->target_obj) {
            unsigned char action = this->state;
            if (action == 4 || action == 6) {
                return 1;
            }
        }
        this->set_target_obj(target);
        this->set_state(4);
        return 1;
    }

    int iz = *(int*)&param_4;
    int ix = *(int*)&param_2;
    int iy = *(int*)&param_3;
    *(int*)&this->target_z = iz;
    *(int*)&this->target_x = ix;
    *(int*)&this->target_y = iy;
    this->set_target_obj(0);
    this->set_state(11);
    return 1;
}
