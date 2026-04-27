// 004D2CB0 TRIBE_Action_Trade::update
// Source: tact_trd.cpp lines 281-626
// Size: 1428 bytes, no EH (sub esp,8 prologue)
// Complex state machine with nested switches and FPU math
// Calls vt[+0x148] (slot 82), vt[+0x138] (slot 78), vt[+0x1F0] (slot 124)
//
// Attempt log:
// Probe 1: structural classification — HIGH-SLOT BLOCKER (slots 78, 82, 124)
//   Requires 124+ dummy virtual methods on RGE_Action class.
//   Also uses FPU math chains, nested state switches, RGE_Sound, find_by_master_ids.
//   Not practical without donor headers.

// Not implementing — classified as high-slot blocker.
// The function structure:
// 1. Guard checks on field_18 and field_1C (early bail if -1 or owner's objects exist)
// 2. Guard checks on field_10 and field_14 (bail if state >= 7)
// 3. Main switch on state (13 cases, values 1-13):
//    - State 1: FPU coord delta, action list state switch, sends to state 4/7
//    - State 2: same FPU pattern
//    - State 3: action list state check → state 6, or copy coords + state 7
//    - State 4: FPU check → if field_14 exists → send to state 8
//    - State 5: check action_list[0]->master->id → sound play + FPU + state 8
//    - State 6: FPU coord delta → state 8 with set_state(8)
//    - State 7: inner switch on action_list state 0-3
//    - State 8: action_list allocation/timer check → state 3
//    - State 9: FPU add → send to state 8
//    - State 10: action_list check → state 6
//    - State 11: field_14 check + FPU math chain
//       (dot product, fmul constants, boundary check, sound/anim calls)
//    - State 12: check obj owner/id → send to state 7
//    - State 13: action_list check → state 3/timer
// 4. All paths return 0 (char), except some early-return paths return 0
