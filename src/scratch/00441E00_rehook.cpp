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
// Retry 2026-05-24 assigned pass: 15 more probes. A separate vtable-helper interface for the final
// destroy call removed the spurious `xor edx,edx` but shortened the tail and worsened positional
// drift. Volatile/raw/register/member-pointer/assignment-condition doppled reads, dummy locals,
// pointer-typed doppled_object, separate `-1 - doppled` index spellings, and void* owner surfaces
// all kept the same first mismatch at +9 (ECX-vs-EAX load/test/push) or worsened. No exact match;
// not accepted_drift: remaining differences span the first branch, negative owner lookup, branch
// targets, and final vtable-call shape rather than a localized benign hunk.
// Retry 2026-05-26 Boss pass: revalidated baseline (168B, 100 positional / 28 edit, first mismatch +9). Tried 15 more variants. Best improvement was direct member use in the first branch (no saved `doppled` local), which matched through +46 and reduced to 34 positional / 20 edit, but still drifted in positive owner register (`mov eax,[eax+0C]` vs original `mov edx,[eax+0C]`), negative-path scheduling (`this+0C` load and `sub` placement), and final fastcall tail (`xor edx,edx`). Other probes: volatile/assignment/register doppled reads, alternate `-1-doppled` spellings, owner/int locals, virtual destroy helper, second-part locals/direct member, delayed positive store, cdecl tail. No exact. Kept older baseline because it preserves the previously reviewed source shape; best direct-member variant is noted but not promoted since remaining drift remains structural. GIVEUP; not accepted_drift without review because drift spans multiple control-flow regions and call-tail convention.

// Luna441E00 pass: completed the ten-hypothesis budget. Restored the true
// polymorphic RGE_Static_Object/RGE_Animated_Object ownership surface and the
// RGE_Player world/player-table and master-object layouts; corrected
// get_object_pointer to return RGE_Static_Object* and used the inherited
// destroy_obj virtual at vtable +0x68. The final source is the cleanest
// period-plausible reconstruction, although the pinned baseline remains the
// emitted-code frontier.
// Probe results: the true virtual surface removed the spurious final xor edx
// and preserved the 3-call set, but source variants still selected EAX for the
// initial dopple load and positive owner load where the original uses ECX/EDX.
// Natural typed source ends at 171 bytes (original 168), 109 positional diff,
// 34 edit diff, 91.67% shape, and 83.33% exact-block coverage; first mismatch
// remains +9. The raw virtual/integer-field variant reached 168 bytes/102
// positional diff but is less canonical and was not kept as living source.
// Unresolved: recover the original local/register lifetime that yields
// `mov ecx,[this+8c]`, `or eax,-1; sub eax,ecx`, and the target EDX owner
// register without replacing the typed ownership model with opaque casts.

struct RGE_Game_World;
struct RGE_Color_Table;
struct RGE_Master_Static_Object;

struct RGE_Player {
    char gap_00[0x22];
    short master_object_num;              // +0x22
    RGE_Master_Static_Object** master_objects; // +0x24
    char gap_28[0x14];
    RGE_Game_World* world;                // +0x3C
    char gap_40[0xC8];
    RGE_Color_Table* color_table;         // +0x108
};

struct RGE_Game_World {
    char gap_00[0x40];
    RGE_Player** players;                 // +0x40
};

struct RGE_Static_Object {
    virtual ~RGE_Static_Object();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void rehook();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void destroy_obj();

    long id;                // +0x04
    RGE_Static_Object* master_obj; // +0x08
    RGE_Player* owner;      // +0x0C
    char gap_10[0x78];      // +0x10 through +0x87
    RGE_Static_Object* get_object_pointer(long id);
};

struct RGE_Animated_Object : RGE_Static_Object {
    float speed;            // +0x88
};

struct RGE_Doppleganger_Object : RGE_Animated_Object {
    // Starting at +0x8C:
    RGE_Static_Object* doppled_object; // +0x8C
    RGE_Color_Table* draw_color;      // +0x90
    RGE_Master_Static_Object* doppled_master_obj; // +0x94
    int doppled_player;          // +0x98
    unsigned long* MapAddress;   // +0x9C
    unsigned long LastMapValue;  // +0xA0
    unsigned long CantSeeBits;   // +0xA4
    unsigned char map_draw_level;// +0xA8
    unsigned char map_color;     // +0xA9
    unsigned char pad_AA[2];     // +0xAA
    int doppledObjectID;         // +0xAC

    virtual void rehook();
};

void RGE_Doppleganger_Object::rehook() {
    RGE_Static_Object* doppled;
    RGE_Player* player;

    RGE_Static_Object::rehook();

    doppled = this->doppled_object;
    if ((long)doppled >= 0) {
        this->doppled_object = this->get_object_pointer((long)doppled);
        if (this->doppled_object == 0) {
            goto second_part;
        }
        this->doppledObjectID = this->doppled_object->id;
        player = this->doppled_object->owner;
        goto color_lookup;
    }

    // neg path - falls through to color_lookup
    this->doppled_object = 0;
    this->doppledObjectID = -1;
    player = this->owner->world->players[-1 - (long)doppled];

color_lookup:
    this->draw_color = player->color_table;

second_part:
    if ((long)this->doppled_master_obj >= 0) {
        player = this->owner->world->players[this->doppled_player];
        if ((long)this->doppled_master_obj < player->master_object_num) {
            this->doppled_master_obj = player->master_objects[(long)this->doppled_master_obj];
            return;
        }
    }

    this->doppled_master_obj = 0;
    this->destroy_obj();
}
