// Authentic owner wrapper for the PDB source module
// C:\\msdev\\work\\age1_x1\\tact_art.cpp.
//
// The include order follows the PDB line and address sequence.  The complete
// class surface is in tact_art_context.h.  It also supplies the generated
// vector-deleting destructor at 004CCBD0.

#define AOE1_TACT_ART_TU_CONTEXT 1
#include "../include/tact_art_context.h"

#include <stdlib.h>
#include <string.h>

extern double DAT_00574f08;
extern float DAT_00574f10;
extern float DAT_00574f14;

#include "matching/004CCBA0_TRIBE_Action_Artifact.cpp"
#include "matching/004CCC00_TRIBE_Action_Artifact.cpp"
#include "matching/004CCC30_TRIBE_Action_Artifact.cpp"
#include "matching/004CCC70_first_in_stack.cpp"
#include "matching/004CCCB0_set_state.cpp"
#include "matching/004CCDF0_update.cpp"
#include "matching/004CCF30_check_ownership.cpp"
#include "matching/004CD120_stop.cpp"
#include "matching/004CD130_move_to.cpp"
#include "matching/004CD160_work.cpp"
#include "matching/004CD1A0_reset_owner.cpp"

#undef AOE1_TACT_ART_TU_CONTEXT
