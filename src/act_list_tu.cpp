// Authentic act_list.cpp owner wrapper in PDB source order.
//
// PDB source: C:\\msdev\\work\\age1_x1\\act_list.cpp
// The owner order is the line order in the original module.  004041C2 is an
// internal dispatch block inside create_action, not a separate source owner.
// No compiler-generated owner is listed in the module packet.
//
// The module has EH constructors at 00403FC0 and 00404200.  Use the pinned
// module flags in config/flags/00404200_create_task_action.rsp:
// /nologo /c /O2 /Oy /GX.

#define ACT_LIST_SHARED_CONTEXT 1
#include "../include/act_list_context.h"

#include "matching/00403EA0_RGE_Action_List.cpp"
#include "matching/00403EC0_RGE_Action_List.cpp"
#include "matching/00403ED0_load.cpp"
#include "matching/00403F40_rehook.cpp"
#include "matching/00403F60_save.cpp"
#include "matching/00403FA0_delete_list.cpp"
#include "matching/00403FC0_create_action.cpp"
#include "accepted_drift/00404200_create_task_action.cpp"
#include "matching/004044A0_inside_obj_update.cpp"
#include "matching/004044F0_update.cpp"
#include "matching/00404540_add_action.cpp"
#include "accepted_drift/00404590_add_action_at_end.cpp"
#include "scratch/00404610_add_action_at_end_of_action_queue.cpp"
#include "matching/00404710_remove_action.cpp"
#include "matching/00404760_have_action.cpp"
#include "matching/00404770_action_stop.cpp"
#include "matching/00404790_action_move_to.cpp"
#include "matching/004047C0_action_work.cpp"
#include "matching/004047F0_attack_response.cpp"
#include "matching/00404810_relation_response.cpp"
#include "scratch/00404840_get_action.cpp"
#include "matching/00404850_get_task.cpp"
#include "matching/00404860_copy_obj.cpp"
#include "matching/00404890_copy_obj_sprites.cpp"
#include "matching/004048C0_get_action_name.cpp"

#undef ACT_LIST_SHARED_CONTEXT
