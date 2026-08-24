// Authentic tact_hnt.cpp owner wrapper.
//
// Source module: C:\\msdev\\work\\age1_x1\\tact_hnt.cpp
// PDB order is 004CF090, 004CF130, 004CF1C0, 004CF210, 004CF240,
// 004CF300, 004CF860, 004CFF20, 004CFF50, 004CFF90, 004CFFD0, and
// 004D0080.  The source-line bands are 70-73, 81-105, 113-124, 130-133,
// 139-171, 177-378, 384-794, 800-807, 813-820, 826-833, 840-883, and
// 890-948.  The wrapper keeps that owner sequence and does not add a dummy
// function or an unrelated declaration.
//
// The canonical TRIBE_Action_Hunt surface is the 0x44-byte RGE_Action-derived
// action.  Its target object is +0x10, dropsite target is +0x14, coordinates
// are +0x20..+0x28, timer is +0x2C, task is +0x30, sub-action list is +0x34,
// and targetType is +0x40.  RGE_Action slots +0x54, +0x58, and +0x5C are the
// target setters and state transition.  The action-object set_attribute slot
// is +0x80, notify is +0x148, and turn_towards is +0x1F0.  The wrapper keeps
// these calls virtual.  It does not replace them with hand-written vtables.
//
// The state and update owners keep the shipped x87 behavior.  Float globals
// DAT_00575150 and DAT_00575168 remain memory operands.  The gather transfer
// keeps its signed __ftol conversion and the original divisor and clamp order.
// The constructors retain the original /GX EH surface around base setup,
// rge_read, allocation, and action-list cleanup.  Build this module with one
// period-plausible flag set: /nologo /c /O2 /Oy /GX.
//
// Exact anchors: 004CF090, 004CF130, 004CF1C0, 004CF240, 004CF300,
// 004CFF20, 004CFF90, and 004D0080.  004CF210 and 004CFF50 use their
// canonical RGE_Action/TRIBE_Action_Hunt owners here.  004CF860 remains a
// scratch structural reconstruction.  004CFFD0 remains accepted drift for
// the localized false-path parameter scheduling difference.
// The compiler-generated scalar deleting destructor at 004CF100 is emitted
// by this virtual class surface and has no standalone source owner.  The
// candidate proposal records its exact decorated symbol.
//
// tact_hnt_context.h imports only the reviewed declaration surface from the
// set_state owner.  It does not import the body.  Each VA below remains owned
// by its existing source file.  No translation_units.json entry is added here.

#define TACT_HNT_SHARED_CONTEXT 1
#include "../include/tact_hnt_context.h"

#include "matching/004CF090_TRIBE_Action_Hunt.cpp"
#include "matching/004CF130_TRIBE_Action_Hunt.cpp"
#include "matching/004CF1C0_TRIBE_Action_Hunt.cpp"
#include "matching/004CF210_save.cpp"
#include "matching/004CF240_first_in_stack.cpp"
#include "matching/004CF300_set_state.cpp"
#include "scratch/004CF860_update.cpp"
#include "matching/004CFF20_get_move_sprite.cpp"
#include "matching/004CFF50_get_wait_sprite.cpp"
#include "matching/004CFF90_stop.cpp"
#include "accepted_drift/004CFFD0_move_to.cpp"
#include "matching/004D0080_work.cpp"

#undef TACT_HNT_SHARED_CONTEXT
