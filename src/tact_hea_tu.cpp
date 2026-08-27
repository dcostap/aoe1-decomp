// Authentic tact_hea.cpp translation unit in PDB source order.
//
// Source module: C:\\msdev\\work\\age1_x1\\tact_hea.cpp
// PDB owner lines: 41, 51, 67, 80, 98, 175, and 371.
//
// The source-only context supplies the reviewed tactical-action hierarchy from
// canonical owner headers.  The legacy context remains for the old fragments,
// but this owner no longer consumes it.  The nearby scalar deleting destructor
// at 004CE960 is compiler-generated and is selected in the proposal.
//
// Candidate validation rows after this cleanup:
// 004CE930 MATCH, 004CE990 MATCH, 004CEA10 MATCH, 004CEA50 MATCH,
// 004CEA90 MISMATCH (456 bytes), 004CECF0 MISMATCH (568 bytes),
// 004CF030 MATCH, and generated 004CE960 MATCH.
// The two mismatches are structural regressions from replacing the copied
// context with canonical owners.  No exact-codegen tuning was done here.

#include "../include/tact_hea.h"
#include "../include/action.h"
#include "../include/act_list.h"
#include "../include/act_move.h"
#include "../include/act_obj.h"
#include "../include/stat_obj.h"
#include "../include/move_obj.h"
#include "../include/m_s_obj.h"
#include "../include/m_ac_obj.h"
#include "../include/com_obj.h"
#include "../include/t_c_obj.h"
#include "../include/t_b_obj.h"
#include "../include/basegame.h"
#include "../include/game_globals.h"
#include "../include/player.h"
#include "../include/rge_base_game_global.h"
#include "../include/sound.h"
#include "../include/task.h"
#include "../include/world.h"

#include "matching/004CE930_TRIBE_Action_Heal.cpp"
#include "matching/004CE990_TRIBE_Action_Heal.cpp"
#include "matching/004CEA10_TRIBE_Action_Heal.cpp"
#include "matching/004CEA50_first_in_stack.cpp"
#include "matching/004CEA90_set_state.cpp"
#include "matching/004CECF0_update.cpp"
#include "matching/004CF030_work.cpp"
