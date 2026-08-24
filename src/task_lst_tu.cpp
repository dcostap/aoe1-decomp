// Authentic task_lst.cpp owner wrapper.
//
// Source module: C:\\msdev\\work\\age1_x1\\task_lst.cpp.
// PDB source order and exact anchors:
//   00508E00  RGE_Task_List::RGE_Task_List       task_lst.cpp:27-30
//   00508E20  RGE_Task_List::~RGE_Task_List      task_lst.cpp:35-36
//   00508E30  RGE_Task_List::copy                task_lst.cpp:42-58
//   00508EC0  RGE_Task_List::load(int, ...)      task_lst.cpp:63-81
//   00508F60  RGE_Task_List::load(FILE*, ...)    task_lst.cpp:86-107
//   00509010  RGE_Task_List::save               task_lst.cpp:112-119
//   00509050  RGE_Task_List::delete_list        task_lst.cpp:124-142
//   005090B0  RGE_Task_List::create_task        task_lst.cpp:148-154
//   00509120  RGE_Task_List::get_target_task    task_lst.cpp:159-237
//   005092D0  RGE_Task_List::is_attack_task     task_lst.cpp:242-247
//   005092F0  RGE_Task_List::check_task         task_lst.cpp:252-297
//
// The context header is the one compiler-facing declaration surface for this
// source module.  Owners contain bodies only.
#include "../include/task_lst_context.h"

#include "matching/00508E00_RGE_Task_List.cpp"
#include "matching/00508E20_RGE_Task_List.cpp"
#include "matching/00508E30_copy.cpp"
#include "matching/00508EC0_load.cpp"
#include "matching/00508F60_load.cpp"
#include "matching/00509010_save.cpp"
#include "matching/00509050_delete_list.cpp"
#include "matching/005090B0_create_task.cpp"
#include "matching/00509120_get_target_task.cpp"
#include "matching/005092D0_is_attack_task.cpp"
#include "matching/005092F0_check_task.cpp"
