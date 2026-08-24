// Authentic t_c_obj.cpp translation-unit wrapper.
//
// PDB source module: C:\\msdev\\work\\age1_x1\\t_c_obj.cpp
// Owner order follows the packet's PDB line and address order.  The nearby
// compiler-generated deleting destructor is intentionally not an owner.
// Build context for this compile proposal: /nologo /c /O2 /Oy /GX.
//
// Packet accounting:
// - exact owners: 004CA510 and 004CBD30, both grouped matches;
// - observed owners: the other 37 bodies, including 26 former grouped exact
//   candidates and the 11 original scratch or accepted-drift bodies;
// - generated: 004CA180 vector-deleting destructor, registration-policy-blocked;
// - exact decorated overrides select the ambiguous constructors, setup,
//   attack, repair, build, and heal symbols.
//
// Compilation validation: the complete include set compiles under the pinned
// VC5 host and /GX.  The validation report is
// build/tu_plans/t_c_obj_cpp/validation_reclassified/report.json.  It records
// 2 exact comparison matches, 37 observed comparisons, and no selection
// errors.  The generated companion is recorded in the blocked proposal entry.
// This pass stops at compilation.  It does not claim grouped exactness.

#include "../include/t_c_obj_context.h"

#define rge_base_game (*(RGE_Base_Game**)0x0062C574)

#include "matching/004CA0F0_TRIBE_Combat_Object.cpp"
#include "matching/004CA1A0_TRIBE_Combat_Object.cpp"
#include "matching/004CA210_TRIBE_Combat_Object.cpp"
#include "matching/004CA300_setup.cpp"
#include "matching/004CA3E0_setup.cpp"
#include "matching/004CA510_create_action_list.cpp"
#include "matching/004CA570_save.cpp"
#include "matching/004CA5F0_update.cpp"
#include "matching/004CA640_modify.cpp"
#include "matching/004CA700_transform.cpp"
#include "matching/004CA740_set_object_state.cpp"
#include "scratch/004CA780_cancel_object.cpp"
#include "matching/004CA790_die_die_die.cpp"
#include "matching/004CA7F0_damage.cpp"
#include "matching/004CA8C0_change_ownership.cpp"
#include "scratch/004CAA00_calc_attack_modifier.cpp"
#include "matching/004CAA50_attack.cpp"
#include "matching/004CAAA0_do_attack.cpp"
#include "accepted_drift/004CAC10_get_armor.cpp"
#include "matching/004CAC80_get_pierce_armor.cpp"
#include "matching/004CACE0_reposition_artifact.cpp"
#include "matching/004CB040_can_debark.cpp"
#include "matching/004CB060_hunt.cpp"
#include "matching/004CB1B0_convert.cpp"
#include "matching/004CB300_heal.cpp"
#include "accepted_drift/004CB450_repair.cpp"
#include "accepted_drift/004CB5C0_build.cpp"
#include "accepted_drift/004CB710_trade.cpp"
#include "scratch/004CB860_keepGatheringWhenObjectIsOut.cpp"
#include "matching/004CB880_produceWhenKilledBy.cpp"
#include "scratch/004CB8B0_useSameZoneDropsite.cpp"
#include "matching/004CB8D0_initUnitAI.cpp"
#include "matching/004CBD30_lines_intersect.cpp"
#include "scratch/004CBD40_higher_check_for_cliff.cpp"
#include "accepted_drift/004CBEF0_higher_than_target.cpp"
#include "matching/004CC1B0_area_attack.cpp"
#include "accepted_drift/004CC4C0_heal.cpp"
#include "matching/004CC570_canRepair.cpp"
#include "matching/004CC5B0_do_repair.cpp"

#undef rge_base_game
