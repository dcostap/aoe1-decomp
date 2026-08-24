// Authentic ACT_GATH.cpp owner wrapper.
//
// PDB source module: C:\\msdev\\work\\age1_x1\\ACT_GATH.cpp.
// Normal owners stay in PDB line and address order.  00402F10 is the
// compiler-generated scalar deleting destructor for RGE_Action_Gather; it is
// emitted by the class declaration and has no standalone source owner.
//
// The context header is module-local.  It preserves the period RGE_Action,
// action-object, static-object, task, player, and gather ABI surfaces.  The
// owner files keep their narrow standalone declarations outside this wrapper.
// The small aliases below join proven same-slot names from independent owner
// recoveries without adding a synthetic function or altering a call target.

#include "../include/act_gath_context.h"

#define target_relation keepGatheringWhenObjectIsOut
#define check_attribute keepGatheringWhenObjectIsOut
#define has_drop_site useSameZoneDropsite

#include "matching/00402EA0_RGE_Action_Gather.cpp"
#include "matching/00402F40_RGE_Action_Gather.cpp"
#include "matching/00402FD0_RGE_Action_Gather.cpp"
#include "matching/00403020_save.cpp"
#include "matching/00403050_first_in_stack.cpp"
#include "scratch/00403110_set_state.cpp"
#include "scratch/00403590_update.cpp"
#include "matching/00403C60_get_move_sprite.cpp"
#include "matching/00403C90_get_wait_sprite.cpp"

#define vf5C set_state
#include "matching/00403CD0_stop.cpp"
#undef vf5C

#include "accepted_drift/00403CE0_move_to.cpp"
#include "accepted_drift/00403D90_work.cpp"

#undef has_drop_site
#undef check_attribute
#undef target_relation
