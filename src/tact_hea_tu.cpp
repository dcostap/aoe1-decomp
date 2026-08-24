// Authentic tact_hea.cpp translation unit in PDB source order.
//
// Source module: C:\\msdev\\work\\age1_x1\\tact_hea.cpp
// PDB owner lines: 41, 51, 67, 80, 98, 175, and 371.
//
// The module context supplies the reviewed tactical-action hierarchy and keeps
// the source bodies in one compiler context.  The nearby scalar deleting
// destructor at 004CE960 is compiler-generated and is selected in the proposal.
//
// Baseline validation: 004CE930, 004CE990, 004CEA90, 004CECF0, and 004CF030
// match.  004CEA10 matches bytes but keeps its source-compatible int ABI view;
// 004CEA50 differs by one byte in the shared context.  Both remain observed.
// Candidate validation reports 5 exact owners, 2 observed owners, and 1 exact
// compiler-generated scalar deleting destructor for this complete wrapper.
// No exact-codegen tuning was done in this pass.
// The module context now uses the reviewed tactical hierarchy and named virtual
// surfaces.  Candidate validation and dry-run registration pass.

#include "../include/tact_hea_context.h"

#include "matching/004CE930_TRIBE_Action_Heal.cpp"
#include "matching/004CE990_TRIBE_Action_Heal.cpp"
#include "matching/004CEA10_TRIBE_Action_Heal.cpp"
#include "matching/004CEA50_first_in_stack.cpp"
#include "matching/004CEA90_set_state.cpp"
#include "matching/004CECF0_update.cpp"
#include "matching/004CF030_work.cpp"
