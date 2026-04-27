// 004D2880 TRIBE_Action_Trade::set_state
// Source: tact_trd.cpp lines 134-275
// Size: 1020 bytes, EH-framed, switch on param with jump table
// Calls vt[+0x148] (slot 82) and vt[+0x138] (slot 78) — high-slot dispatch blocker
//
// Attempt log:
// Probe 1: structural switch decomp — classified as HIGH-SLOT BLOCKER
//   Calls virtual methods at vtable slots 78 (+0x138) and 82 (+0x148).
//   Requires 82+ dummy virtual methods on RGE_Action class to match.
//   Also uses RGE_Action_Move_To ctor, RGE_Action_List, RGE_Sound.
//   Not practical without donor headers.
//   Left in scratch: high-slot vtable dispatch blocKed.

#include "..\..\include\game_globals.h"

// RGE_Action_List stub
class RGE_Action_List {
public:
    char _gap_00[0x04];
    // methods: delete_list, add_action
    void delete_list();
    void add_action(void* action);
};

// RGE_Sound stub
class RGE_Sound {
public:
    void play(int param);
};

// TRIBE_Action_Trade class with dummy vtable (needs 82+ for slot 78/82)
// This is a stub — the high-slot dispatch makes exact matching impractical
class TRIBE_Action_Trade {
public:
    // vptr at +0x00 (implicit)
    // action_type at +0x04
    char _gap_04[0x04];
    void* action_obj;           // +0x08
    unsigned char state;        // +0x0C
    char _gap_0D[0x03];         // +0x0D-0x0F
    void* field_10;             // +0x10
    void* field_14;             // +0x14
    char _gap_18[0x0C];         // +0x18-0x23
    float coord_x;              // +0x20
    float coord_y;              // +0x24
    float coord_z;              // +0x28
    char _gap_2C[0x04];         // +0x2C-0x2F
    void* task;                 // +0x30
    RGE_Action_List* action_list; // +0x34
    char _gap_38[0x08];         // +0x38-0x3F
    float pick_up_x;            // +0x40
    float pick_up_y;            // +0x44

    // Without 82+ dummy virtual methods, this cannot match
};

// Not implementing the full switch — classified as high-slot blocker.
// The function deletes action_list, stores state, then dispatches 10 cases (2-11):
// Cases 2,3,6: get_wait_sprite or get_move_sprite + vt[+0x38](sprite)
// Cases 4,5,11: new RGE_Action_Move_To(0x44) + get_move_sprite + add_action
// Case 7: set sprite from task, play sound, copy pick_up_x/y from field_10
// Case 8: FPU math, find_by_master_ids, possibly new Action_Move_To
// Cases 9,10: vt[+0x148](gfx_params), set_state(0xD) or set_state(3)
// Case default: just return
