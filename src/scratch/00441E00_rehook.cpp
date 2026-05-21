// RGE_Doppleganger_Object::rehook
// VA: 00441E00, dpl_obj.cpp:280-327
// Status: PARKED in scratch - VC5 register allocation/codegen drift
//
// Attempt log:
// v0: __fastcall free function with dummy param → extra push edi from dummy
// v1: member function (__thiscall), class methods for base calls → first 9 bytes match!
// v2: restructured control flow to match original block layout (pos path jumps, neg path falls through) → same structure
// v3: added destroy_obj() member call for vtable dispatch → eliminated xor edx
// v4: virtual destroy_obj → vtable layout shifted ALL field offsets (regression)
// v5: goto-based control flow (neg path as label after pos path) → same as v1
//
// Remaining drift summary:
// 1. REGISTER ALLOCATION: doppled_object loaded into EAX instead of ECX.
//    This single difference cascades throughout the function:
//    - push eax vs push ecx for get_object_pointer call param
//    - lea edx,[eax*4+4] vs or eax,-1 for neg path index
//    - Neg path uses different register for player pointer
//    - Second part register differences
// 2. VID: xor edx,edx before vtable call (from __fastcall function pointer convention)
//    Original uses __thiscall which doesn't need edx.
// 3. All differences are stable VC5 codegen-family drift (register scheduler choice).
//    Behavior is equivalent in all paths.
// Retry 2026-05-21 Boss pass: tried register/volatile doppled, assignment-in-condition and
// inverted/goto positive branch, passing member vs local to get_object_pointer, id local,
// removing count temp, virtual destroy_obj surface with adjusted vptr layout, __thiscall
// function-pointer probe (VC5 rejects), integer obj/owner surfaces, `~doppled` negative-index
// spelling, and /G5 /Op flags. Best kept improves edit diff to 16.6667% but still has broad
// ECX-vs-EAX first load, owner register, branch target, and final vtable-call convention drift.
// Not accepted_drift-worthy.

struct RGE_Static_Object {
    char gap_00[4];         // vtable at +0x00
    char gap_04[0x84];      // dummy space up to +0x88
    float speed;            // +0x88 (inherited from RGE_Animated_Object)

    void rehook();
    void* get_object_pointer(long id);
};

struct RGE_Doppleganger_Object : RGE_Static_Object {
    // Starting at +0x8C:
    int doppled_object;          // +0x8C
    int draw_color;              // +0x90
    int doppled_master_obj;      // +0x94
    int doppled_player;          // +0x98
    unsigned long* MapAddress;   // +0x9C
    unsigned long LastMapValue;  // +0xA0
    unsigned long CantSeeBits;   // +0xA4
    unsigned char map_draw_level;// +0xA8
    unsigned char map_color;     // +0xA9
    unsigned char pad_AA[2];     // +0xAA
    int doppledObjectID;         // +0xAC

    void rehook();
};

void RGE_Doppleganger_Object::rehook() {
    int doppled;
    int index;
    void* player;
    int owner;
    int entry;

    RGE_Static_Object::rehook();

    doppled = this->doppled_object;
    if (doppled >= 0) {
        int id = doppled;
        int obj = (int)this->get_object_pointer(id);
        this->doppled_object = obj;
        if (obj == 0) {
            goto second_part;
        }
        this->doppledObjectID = *(int*)(obj + 4);
        owner = *(int*)(obj + 0x0C);
        goto color_lookup;
    }

    // neg path - falls through to color_lookup
    index = ~doppled;
    this->doppled_object = 0;
    this->doppledObjectID = -1;
    player = *(void**)((char*)this + 0x0C);
    owner = *(int*)(*(int*)(*(int*)((char*)player + 0x3C) + 0x40) + index * 4);

color_lookup:
    this->draw_color = *(int*)(owner + 0x108);

second_part:
    if (this->doppled_master_obj >= 0) {
        player = *(void**)((char*)this + 0x0C);
        entry = *(int*)(*(int*)(*(int*)((char*)player + 0x3C) + 0x40) + this->doppled_player * 4);
        if (this->doppled_master_obj < *(short*)(entry + 0x22)) {
            this->doppled_master_obj = *(int*)(*(int*)(entry + 0x24) + this->doppled_master_obj * 4);
            return;
        }
    }

    this->doppled_master_obj = 0;
    {
        typedef void (__fastcall *DestroyFn)(RGE_Doppleganger_Object*, int);
        DestroyFn destroy = *(DestroyFn*)(*(int*)this + 0x68);
        destroy(this, 0);
    }
}
