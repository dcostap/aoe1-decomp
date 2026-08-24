// Authentic PDB-ordered owner wrapper for m_ac_obj.cpp.
//
// Module: C:\\msdev\\work\\age1_x1\\m_ac_obj.cpp
// Owner order follows build/tu_plans/m_ac_obj_cpp/packet.json lines 29-341.
// The vector deleting destructor at 0044F0D0 is compiler generated and is
// listed in the proposal, not included as a source owner.
//
// Matching owners are 0044F070, 0044F0F0, 0044F160, 0044F290, 0044F3C0,
// 0044F540, 0044F5A0, 0044F670, 0044F6E0, 0044F710, and 0044F880.
// Accepted-drift owners are 0044F4D0, 0044F820, and 0044F850.
// Scratch owners are included as observed owners: 0044F1E0, 0044F760,
// 0044F7F0, 0044F980, and 0044F9A0.
//
// The module-local context keeps the isolated owner declarations behind a TU
// guard. It models the shipped master-object hierarchy and task/sound fields.
// It does not add a synthetic owner or alter the accepted-drift bodies.

#define RGE_MAC_OBJ_SHARED_CONTEXT 1
#include "../include/m_ac_obj_context.h"

#include "matching/0044F070_RGE_Master_Action_Object.cpp"
#include "matching/0044F0F0_RGE_Master_Action_Object.cpp"
#include "matching/0044F160_RGE_Master_Action_Object.cpp"
#include "scratch/0044F1E0_setup.cpp"
#include "matching/0044F290_setup.cpp"
#include "matching/0044F3C0_setup.cpp"
#include "accepted_drift/0044F4D0_RGE_Master_Action_Object.cpp"
#include "matching/0044F540_create_task_list.cpp"
#include "matching/0044F5A0_make_new_obj.cpp"
#include "matching/0044F670_make_new_master.cpp"
#include "matching/0044F6E0_get_task.cpp"
#include "matching/0044F710_getTaskByTaskID.cpp"
#include "scratch/0044F760_copy_obj.cpp"
#include "scratch/0044F7F0_modify.cpp"
#include "accepted_drift/0044F820_modify_delta.cpp"
#include "accepted_drift/0044F850_modify_percent.cpp"
#include "matching/0044F880_save.cpp"
#include "scratch/0044F980_play_command_sound.cpp"
#include "scratch/0044F9A0_play_move_sound.cpp"

#undef RGE_MAC_OBJ_SHARED_CONTEXT
