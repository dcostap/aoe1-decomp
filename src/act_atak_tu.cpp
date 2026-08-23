// Authentic Act_atak.cpp owner wrapper.
//
// Source module: C:\\msdev\\work\\age1_x1\\Act_atak.cpp
//
// PDB line bands and address order agree for all normal body owners below.
// The two in-line accessors at 00401130 and 00401140 come from action.h.  Their
// shared class definitions emit the exact four-byte bodies.  The compiler emits
// the vector-deleting destructor at 00401150 from the virtual destructor.  The
// entries at 00401746 and 00401A8E are padding or dispatch data.  They are not
// body owners here.
// A VC5 /GX build emits this same linked symbol order.  Exact-anchor section
// spans also reach each next original address.  The two dispatch tails stay
// compiler-owned inside set_state and update.
//
// Compile this module with the pinned VC5 compiler and /O2 /Oy /GX.  The
// constructors at 00401000 and 00401170 have EH frames.  The state transition
// owner at 00401550 also has an EH frame around RGE_Action_Move_To allocation.
// /GX is therefore module context, not a target-local source-shape device.
// This wrapper does not add or change a translation_units.json entry.
//
// The shared declarations keep the original ownership chain:
// RGE_Action_Attack -> RGE_Action, RGE_Action_Object -> RGE_Moving_Object ->
// RGE_Animated_Object -> RGE_Static_Object, and the static, animated, moving,
// action, and combat master-object sequence.  RGE_Action is 0x40 bytes.
// RGE_Action_Attack is 0x5C bytes.  The attack fields stay at +0x40 through
// +0x5A.  Object coordinates stay at +0x38 through +0x40.
//
// Keep the proven virtual slots.  Static-object can_attack is +0x7C,
// maximumSpeed is +0xFC, and notify is +0x148.  Action-object turn_towards is
// +0x1F0.  Combat-object attack dispatches are +0x220 and +0x224.
// Sprite-list frame_passed and looped are +0x20 and +0x24.  Do not replace
// these calls with direct helpers.
//
// The constructor bodies keep stack-parameter and x87 order.  ready_to_attack
// keeps distance and radius values on the x87 stack across the shipped tests.
// update keeps its sparse state routing and shared notification tails.  Do not
// add target guards or reorder owner, visibility, sprite, or target reads.
// These reads define the executable's fault order.
//
// Exact anchors before the unresolved lane are 00401000, 00401130, 00401140,
// 00401150, 004013A0, 004013B0, 004014B0, 00401540, and 00401550.  Exact
// anchors after it are 00401AD0, 00401EC0, and 00401F00.  The two constructors
// at 00401170 and 004012B0 are accepted drift.  update at 00401780 and
// ready_to_attack at 00401B30 remain scratch.  Keep accepted and scratch owners
// in their PDB positions.

#include "../include/act_atak_context.h"

#include "matching/00401000_RGE_Action_Attack.cpp"
#include "accepted_drift/00401170_RGE_Action_Attack.cpp"
#include "accepted_drift/004012B0_RGE_Action_Attack.cpp"
#include "matching/004013A0_RGE_Action_Attack.cpp"
#include "matching/004013B0_save.cpp"
#include "matching/004014B0_first_in_stack.cpp"
#include "matching/00401540_stop.cpp"
#include "matching/00401550_set_state.cpp"
#include "scratch/00401780_update.cpp"
#include "matching/00401AD0_work.cpp"
#include "scratch/00401B30_ready_to_attack.cpp"
#include "matching/00401EC0_do_attack.cpp"
#include "matching/00401F00_copy_obj_sprites.cpp"
