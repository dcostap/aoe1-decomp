// Authentic tact_bld.cpp reconstruction wrapper.
//
// Source module: C:\\msdev\\work\\age1_x1\\tact_bld.cpp
//
// PDB and address order:
//  004CD1B0  TRIBE_Action_Build(int, RGE_Action_Object*)
//  004CD210  TRIBE_Action_Build(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*)
//  004CD2A0  TRIBE_Action_Build(RGE_Action_Object*, RGE_Task*, float, float, float)
//  004CD2E0  first_in_stack
//  004CD310  set_state
//  004CD5E0  update
//  004CD910  stop
//  004CD920  move_to
//  004CD960  work
//
// Exact anchors are 004CD1B0, 004CD210, 004CD2A0, 004CD2E0, 004CD310,
// 004CD910, and 004CD920.  The two constructors and set_state retain their
// EH-aware period surfaces.  update and work keep their reviewed accepted-drift
// owners.  004CD1E0 is the compiler-generated deleting destructor selected in
// the candidate proposal.  Its no-PDB 004CD200 destructor body also emits and
// independently matches.  004CD1FE and 004CD5A5 are no-PDB padding or boundary
// entries, not source body owners, so they are not included in this wrapper.
//
// The wrapper uses one canonical RGE_Action/TRIBE_Action_Build surface.  This
// preserves target IDs, target coordinates, task ownership, sub-action list
// ownership, action state, and the proven virtual slots.  The source bodies
// keep their PDB line order and their observed call and failure behavior.
//
// The original constructors and set_state contain C++ EH registration and
// unwind-state stores.  Use /nologo /c /O2 /Oy /GX with the pinned VC5 toolchain.
// This wrapper adds no translation_units.json or flag configuration entry.

#include "../include/tact_bld_context.h"

#include "matching/004CD1B0_TRIBE_Action_Build.cpp"
#include "matching/004CD210_TRIBE_Action_Build.cpp"
#include "matching/004CD2A0_TRIBE_Action_Build.cpp"
#include "matching/004CD2E0_first_in_stack.cpp"
#include "matching/004CD310_set_state.cpp"
#include "accepted_drift/004CD5E0_update.cpp"
#include "matching/004CD910_stop.cpp"
#include "matching/004CD920_move_to.cpp"
#include "accepted_drift/004CD960_work.cpp"
