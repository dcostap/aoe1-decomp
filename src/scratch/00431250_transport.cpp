// VA: 00431250, RGE_Combat_Object::transport, 230 bytes
// Source: com_obj.cpp lines 1146-1172
// __thiscall virtual, returns int, ret 10h (float x, float y, float z, int w)
//
// Attempt log:
// probe 1-10 (prior workers): thunk classes + extern wrappers + flat layout,
//   79% diff, wrong layout (+0x180/0x188 vs +0x184), wrong EH basin.
// This session (sa-e16e6199): mirror the exact matched sibling 00431340 unload
//   (same TU com_obj.cpp, same class surface, same /GX EH frame). Baseline 82 diff.
// Probes (source-shape, all same emitted tail except noted):
//   - if/else, goto-exit result, result+if/else: VC5 canonicalizes -> inline ret0 epilogue (82 diff, 249B)
//   - comma-return func34,1: worse (175 diff, 276B)
//   - goto fail at end: 82 diff (249B)
//   - result=0; if (transport!=0) {body; result=1;} return result;  => BEST 67 diff,
//     230/230 bytes, shape 93.9%, exact-blocks 93.8%, edit-diff 14.
// Left in scratch: single-return shape shares the epilogue exactly like the original
//   (tail [call;mov eax,1] + [epilogue] blocks match byte-for-byte; mov eax,1 not hoisted
//   into epilogue; original fs-restore interleave reproduced), but the ret0 head differs:
//   rebuilt emits [xor eax,eax; try=-1; test edi,edi; je epilogue] (xor hoisted before
//   the test), original emits [test; try=-1; jne body; xor eax,eax; jmp epilogue]
//   (xor inside inline ret0 block, body as jne target).
// Next lead: plain two-return shape has right head but VC5 duplicates the epilogue and
//   hoists mov eax,1 into it (preventing the cross-jump); the single-return shape shares
//   the epilogue but hoists xor eax,eax before the test. A shape that yields BOTH
//   (xor after the test AND shared epilogue) should be exact. Candidates not yet tried:
//   a mixed form with an explicit shared exit label reached by the ret0 via a conditional
//   edge rather than an unconditional goto, or controlling the try-level reset scheduling
//   (reset is emitted between test and branch in the original; VC5's scheduling of the
//   /GX end-of-try store relative to the source if-test is the lever).
// Session sa-10e3eb44-r1:
//   - ABI evidence identifies action slot +34 as int work(...); changing the local
//     declaration from void to int was emitted-code neutral.
//   - Reusing top-level action/transport temporaries and explicit result/goto labels
//     were codegen duplicates or regressed to 82 diff / 249B; a shared action/owner
//     work label regressed structurally (210 diff), and a do/while-break wrapper
//     added an extra vslot call (175 diff / 276B). All were restored.
//   - Best clean reconstruction remains the result=0; positive transport guard form
//     at 67 positional diff, exact size/calls, with the tail epilogue aligned.
// Main-agent normalization replaced the cast-to-helper virtual call with a real
// inherited virtual surface and direct member call; emitted code is unchanged.
// Fresh worker: explicit null/success result arms reproduced the prior 249-byte
// two-return basin, while a switch diagnostic grew to 276 bytes; both were rolled
// back to the natural single-result guard.
// Fresh session probes: returning the allocation pointer as the final boolean
// duplicated the shared func34 call; positive guard with an explicit else did
// the same and expanded the EH exits.  A base-typed transport pointer was
// codegen-neutral.  Preserve the derived action ownership and clean guard.
// Main-agent audit retained direct inherited virtual calls and canonical action
// ownership; no manual dispatch or EH-tail steering survives.
// FLAGS: /nologo /c /O2 /Oy /GX

#include <stddef.h>

typedef unsigned char uchar;

// RGE_Action_List (direct calls)
class RGE_Action_List {
public:
    uchar have_action();
    void* get_action();
    void delete_list();
};

// RGE_Action with virtual functions for correct vtable dispatch
class RGE_Action {
public:
    // vtable pointer at +0x00 from compiler
    short action_type;     // +0x04
    uchar gap_06[2];       // +0x06
    void* obj;             // +0x08
    uchar state;           // +0x0C
    uchar gap_0D[3];       // +0x0D
    void* target_obj;      // +0x10
    void* target_obj2;     // +0x14
    int targetID;          // +0x18
    int target2ID;         // +0x1C
    float target_x;        // +0x20
    float target_y;        // +0x24
    float target_z;        // +0x28
    float timer;           // +0x2C
    void* task;            // +0x30
    void* sub_actions;     // +0x34
    void* sprite;          // +0x38
    uchar subActionValue;  // +0x3C
    uchar gap_3D[3];       // +0x3D

    virtual ~RGE_Action();
    virtual void slot_04();
    virtual void slot_08();
    virtual void slot_0C();
    virtual void slot_10();
    virtual void slot_14();
    virtual short func18();
    virtual void slot_1C();
    virtual void slot_20();
    virtual void slot_24();
    virtual void slot_28();
    virtual void slot_2C();
    virtual void slot_30();
    virtual int func34(void*, float, float, float);
};

class RGE_Action_Transport : public RGE_Action {
public:
    RGE_Action_Transport(void* obj, void* task, float x, float y, float z);
};

// Narrow canonical inherited virtual surface through slot 0x208. Keeping it as
// a real base avoids raw/manual vtable dispatch while preserving the proven ABI.
struct RGE_Combat_Object_Virtual_Base {
    virtual ~RGE_Combat_Object_Virtual_Base();
    virtual void s04();
    virtual void s08();
    virtual void s0C();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1C();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2C();
    virtual void s30();
    virtual void s34();
    virtual void s38();
    virtual void s3C();
    virtual void s40();
    virtual void s44();
    virtual void s48();
    virtual void s4C();
    virtual void s50();
    virtual void s54();
    virtual void s58();
    virtual void s5C();
    virtual void s60();
    virtual void s64();
    virtual void s68();
    virtual void s6C();
    virtual void s70();
    virtual void s74();
    virtual void s78();
    virtual void s7C();
    virtual void s80();
    virtual void s84();
    virtual void s88();
    virtual void s8C();
    virtual void s90();
    virtual void s94();
    virtual void s98();
    virtual void s9C();
    virtual void sA0();
    virtual void sA4();
    virtual void sA8();
    virtual void sAC();
    virtual void sB0();
    virtual void sB4();
    virtual void sB8();
    virtual void sBC();
    virtual void sC0();
    virtual void sC4();
    virtual void sC8();
    virtual void sCC();
    virtual void sD0();
    virtual void sD4();
    virtual void sD8();
    virtual void sDC();
    virtual void sE0();
    virtual void sE4();
    virtual void sE8();
    virtual void sEC();
    virtual void sF0();
    virtual void sF4();
    virtual void sF8();
    virtual void sFC();
    virtual void s100();
    virtual void s104();
    virtual void s108();
    virtual void s10C();
    virtual void s110();
    virtual void s114();
    virtual void s118();
    virtual void s11C();
    virtual void s120();
    virtual void s124();
    virtual void s128();
    virtual void s12C();
    virtual void s130();
    virtual void s134();
    virtual void s138();
    virtual void s13C();
    virtual void s140();
    virtual void s144();
    virtual void s148();
    virtual void s14C();
    virtual void s150();
    virtual void s154();
    virtual void s158();
    virtual void s15C();
    virtual void s160();
    virtual void s164();
    virtual void s168();
    virtual void s16C();
    virtual void s170();
    virtual void s174();
    virtual void s178();
    virtual void s17C();
    virtual void s180();
    virtual void s184();
    virtual void s188();
    virtual void s18C();
    virtual void s190();
    virtual void s194();
    virtual void s198();
    virtual void s19C();
    virtual void s1A0();
    virtual void s1A4();
    virtual void s1A8();
    virtual void s1AC();
    virtual void s1B0();
    virtual void s1B4();
    virtual void s1B8();
    virtual void s1BC();
    virtual void s1C0();
    virtual void s1C4();
    virtual void s1C8();
    virtual void s1CC();
    virtual void s1D0();
    virtual void s1D4();
    virtual void s1D8();
    virtual void s1DC();
    virtual void s1E0();
    virtual void s1E4();
    virtual void s1E8();
    virtual void s1EC();
    virtual void s1F0();
    virtual void s1F4();
    virtual void s1F8();
    virtual void s1FC();
    virtual void s200();
    virtual void s204();
    virtual void call208(void* arg);  // slot 0x82 (130), offset 0x208
};

class RGE_Combat_Object : public RGE_Combat_Object_Virtual_Base {
public:
    uchar gap_04[0x34];
    float world_x;
    float world_y;
    float world_z;
    uchar gap_44[0x140];
    RGE_Action_List* actions;

    int transport(float x, float y, float z, int w);
};

int RGE_Combat_Object::transport(float x, float y, float z, int w)
{
    int result;

    if (actions->have_action() == 1) {
        RGE_Action* action = (RGE_Action*)actions->get_action();
        if (action->func18() == 0x0C) {
            // Call get_action() AGAIN (original does this)
            RGE_Action* action2 = (RGE_Action*)actions->get_action();
            action2->func34(0, x, y, z);
            return 1;
        }
    }

    RGE_Action_Transport* transport = new RGE_Action_Transport(this, 0, x, y, z);
    result = 0;
    if (transport != 0) {
        actions->delete_list();
        this->call208(transport);
        transport->func34(this, x, y, z);
        result = 1;
    }
    return result;
}
