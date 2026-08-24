// Authentic tact_rep.cpp translation-unit wrapper.
//
// Source module: C:\\msdev\\work\\age1_x1\\tact_rep.cpp
//
// PDB source order and line bands:
//  004D1680  TRIBE_Action_Repair(int, RGE_Action_Object*, int)  (41-46)
//  004D1720  TRIBE_Action_Repair(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*) (54-66)
//  004D17B0  TRIBE_Action_Repair(int, RGE_Task*, float, float, float) (74-81)
//  004D1800  setup (85-96)
//  004D1850  save (100-104)
//  004D1880  first_in_stack (110-115)
//  004D18B0  set_state (121-221)
//  004D1BB0  update (229-441)
//  004D1F50  stop (447-450)
//  004D1F60  move_to (457-464)
//  004D1FA0  work (471-495)
//  004D2020  meet_target (501-557)
//
// The wrapper keeps each VA with its existing source owner.  The nearby
// 004D16F0 vector deleting destructor is compiler-generated and is produced
// by the force-delete use below.  It is not a standalone source owner.
//
// Canonical field ownership comes from the RGE_Action and tactical action
// hierarchy.  tact_rep_context.h supplies the inherited ABI declarations.
// Build with the module's period VC5 flags: /nologo /c /O2 /Oy /GX.
// Candidate validation records 10 exact owners, 2 observed scratch owners,
// and 1 compiler-generated owner.  first_in_stack is observed exact.  update
// is observed with a 2-byte state-4 vtable-register mismatch and remains the
// only blocked entry; stop wrapper tuning after this authentic compile.

#include "../include/tact_rep_context.h"

#include "matching/004D1680_TRIBE_Action_Repair.cpp"
#include "matching/004D1720_TRIBE_Action_Repair.cpp"
#include "matching/004D17B0_TRIBE_Action_Repair.cpp"
#include "matching/004D1800_setup.cpp"
#include "matching/004D1850_save.cpp"
#include "matching/004D1880_first_in_stack.cpp"
#include "matching/004D18B0_set_state.cpp"
#include "scratch/004D1BB0_update.cpp"
#include "matching/004D1F50_stop.cpp"
#include "matching/004D1F60_move_to.cpp"
#include "matching/004D1FA0_work.cpp"
#include "matching/004D2020_meet_target.cpp"

static void tact_rep_force_vector_delete(TRIBE_Action_Repair* value)
{
    delete [] value;
}
