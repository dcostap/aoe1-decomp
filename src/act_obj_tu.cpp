// Authentic PDB-ordered owner wrapper for act_obj.cpp.
//
// Source module: C:\\msdev\\work\\age1_x1\\act_obj.cpp
// The owner sequence follows the source-line bands and address order in the
// original PDB.  This wrapper uses the reviewed act_obj context and keeps the
// unresolved get_command_master source as observed codegen evidence.
// The compiler emits the deleting destructor at 00405F70 from the virtual
// RGE_Action_Object destructor.

#include "../include/act_obj_context.h"

#include "matching/00405C60_RGE_Action_Object.cpp"
#include "matching/00405F90_RGE_Action_Object.cpp"
#include "matching/00406010_RGE_Action_Object.cpp"
#include "matching/00406080_recycle_out_of_game.cpp"
#include "matching/004060A0_recycle_in_to_game.cpp"
#include "matching/004060D0_setup.cpp"
#include "matching/00406120_setup.cpp"
#include "matching/004061A0_create_action_list.cpp"
#include "matching/00406200_rehook.cpp"
#include "matching/00406220_save.cpp"
#include "matching/00406270_transform.cpp"
#include "matching/00406290_destroy_obj.cpp"
#include "matching/004062B0_notify_of_relation.cpp"
#include "matching/004062C0_do_command.cpp"
#include "matching/00406300_move_to.cpp"
#include "matching/00406430_work.cpp"
#include "matching/00406470_work2.cpp"
#include "matching/00406830_set_attack.cpp"
#include "matching/00406840_play_command_sound.cpp"
#include "matching/00406850_play_move_sound.cpp"
#include "scratch/00406860_get_command_master.cpp"
#include "matching/00406940_set_task.cpp"
#include "matching/00406990_setTaskByTaskID.cpp"
#include "matching/004069E0_set_action.cpp"
#include "matching/00406A00_set_only_action.cpp"
#include "matching/00406A30_set_end_action.cpp"
#include "matching/00406A50_stop.cpp"
#include "matching/00406A70_update.cpp"
#include "matching/00406B90_change_ownership.cpp"
#include "matching/00406BC0_copy_obj.cpp"
#include "matching/00406BF0_have_action.cpp"
#include "matching/00406C10_get_target_obj.cpp"
#include "matching/00406C30_getTask.cpp"
#include "matching/00406D00_actionState.cpp"
#include "matching/00406D30_get_action_checksum.cpp"
