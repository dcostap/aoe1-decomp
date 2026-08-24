// 004D1F60 TRIBE_Action_Repair::move_to
// Source: tact_rep.cpp lines 457-464. 51 bytes. __thiscall, ret 10h.
//
// MATCHED. Exact 51-byte match confirmed via local check_function.py.
// Lesson from ZephyrStone (sibling 004CD920): assign move_x = x BEFORE move_y = y.
// The original source code at tact_rep.cpp:461 writes x first, then y, then z.
// This naturally reads x and z before push esi (at [esp+8]/[esp+10h]) and
// reads y after push esi (at [esp+10h]), matching the original EXE.

#include "../../include/tact_rep_context.h"

int TRIBE_Action_Repair::move_to(RGE_Static_Object* obj, float x, float y, float z) {
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
    this->set_target_obj(0);
    this->set_state(0x0B);
    return 1;
}
