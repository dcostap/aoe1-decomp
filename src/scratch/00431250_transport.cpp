// 00431250 RGE_Combat_Object::transport(float, float, float, int)
// PDB: com_obj.cpp:1146-1172, 230 bytes
// __thiscall, returns int, ret 10h (4 params: float x 3, int)
// FLAGS: /GX (original TU used /GX, generating SEH frame)
//
// Attempt log:
// probe 1-4: class layout wrong (+0x180/0x188 vs +0x184), no EH
// probe 5-7: thunk class approach for virtual calls (placement new)
// probe 8-10: regular new with /GX, EH frame generated but TU-dependent handler
//
// Parked: 79% diff.
// Core logic IS correct — the function body (after EH prologue) follows the
// same flow as original: have_action→get_type→type==0xC path vs alloc path
//
// Issues:
// 1. EH handler address is TU-dependent (0x55CE9B in com_obj.cpp, can't match standalone)
// 2. Register allocation: EDI for this instead of ESI
// 3. Extra locals from /GX+new (sub esp,8 vs push ecx for try_level)
// 4. Virtual calls using thunk classes work but vtable slots may differ from real classes
//
// These are TU-context and EH-table issues that require compiling within the
// full com_obj.cpp translation unit to resolve fully.

#include <stdlib.h>
#include <new.h>

typedef unsigned char uchar;

// External game functions (cdecl wrappers called from game EXE)
extern uchar __cdecl have_action(void* list);
extern void* __cdecl get_action(void* list);
extern void __cdecl delete_list(void* list);

// Thunk for RGE_Action virtuals:
// slot 6 (vtable+0x18): get_type() -> returns short, compared with 0xC
// slot 13 (vtable+0x34): init(int, float, float, float)
struct RGE_ActionThunk {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual short get_type();               // slot 6
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void init(int a, float x, float y, float z); // slot 13
};

// RGE_Action_Transport size: 0x40
struct RGE_Action_Transport : RGE_ActionThunk {
    char pad_04[0x3C];
    RGE_Action_Transport(void* owner, void* task, float x, float y, float z);
};

// Thunk for RGE_Combat_Object virtual at slot 130 (vtable+0x208):
// add_action(RGE_Action*)
struct RGE_CombatThunk {
    virtual void d0();
    virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4();
    virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8();
    virtual void d9(); virtual void d10(); virtual void d11(); virtual void d12();
    virtual void d13(); virtual void d14(); virtual void d15(); virtual void d16();
    virtual void d17(); virtual void d18(); virtual void d19();
    virtual void d20(); virtual void d21(); virtual void d22(); virtual void d23();
    virtual void d24(); virtual void d25(); virtual void d26(); virtual void d27();
    virtual void d28(); virtual void d29();
    virtual void d30(); virtual void d31(); virtual void d32(); virtual void d33();
    virtual void d34(); virtual void d35(); virtual void d36(); virtual void d37();
    virtual void d38(); virtual void d39();
    virtual void d40(); virtual void d41(); virtual void d42(); virtual void d43();
    virtual void d44(); virtual void d45(); virtual void d46(); virtual void d47();
    virtual void d48(); virtual void d49();
    virtual void d50(); virtual void d51(); virtual void d52(); virtual void d53();
    virtual void d54(); virtual void d55(); virtual void d56(); virtual void d57();
    virtual void d58(); virtual void d59();
    virtual void d60(); virtual void d61(); virtual void d62(); virtual void d63();
    virtual void d64(); virtual void d65(); virtual void d66(); virtual void d67();
    virtual void d68(); virtual void d69();
    virtual void d70(); virtual void d71(); virtual void d72(); virtual void d73();
    virtual void d74(); virtual void d75(); virtual void d76(); virtual void d77();
    virtual void d78(); virtual void d79();
    virtual void d80(); virtual void d81(); virtual void d82(); virtual void d83();
    virtual void d84(); virtual void d85(); virtual void d86(); virtual void d87();
    virtual void d88(); virtual void d89();
    virtual void d90(); virtual void d91(); virtual void d92(); virtual void d93();
    virtual void d94(); virtual void d95(); virtual void d96(); virtual void d97();
    virtual void d98(); virtual void d99();
    virtual void d100(); virtual void d101(); virtual void d102(); virtual void d103();
    virtual void d104(); virtual void d105(); virtual void d106(); virtual void d107();
    virtual void d108(); virtual void d109();
    virtual void d110(); virtual void d111(); virtual void d112(); virtual void d113();
    virtual void d114(); virtual void d115(); virtual void d116(); virtual void d117();
    virtual void d118(); virtual void d119();
    virtual void d120(); virtual void d121(); virtual void d122(); virtual void d123();
    virtual void d124(); virtual void d125(); virtual void d126(); virtual void d127();
    virtual void d128(); virtual void d129();
    virtual void add_action(void* a);      // slot 130 (vtable+0x208)
};

void* __cdecl operator new(unsigned int s) { return malloc(s); }

// RGE_Combat_Object: flat layout (size 0x1C4)
// Base RGE_Action_Object: actions at +0x184
struct RGE_Combat_Object {
    char gap_00[0x184];
    void* actions;                         // +0x184: RGE_Action_List*
    char gap_188[0x1C4 - 0x188];

    int transport(float x, float y, float z, int w);
};

int RGE_Combat_Object::transport(float x, float y, float z, int w) {
    void* lst = this->actions;
    RGE_ActionThunk* a;

    if (have_action(lst)) {
        a = (RGE_ActionThunk*)get_action(lst);
        if (a->get_type() == 0xC) {
            a = (RGE_ActionThunk*)get_action(lst);
            a->init(0, x, y, z);
            return 1;
        }
    }

    RGE_Action_Transport* t = new RGE_Action_Transport(this, 0, x, y, z);
    if (!t) return 0;

    delete_list(lst);
    ((RGE_CombatThunk*)this)->add_action(t);
    t->init((int)this, x, y, z);
    return 1;
}
