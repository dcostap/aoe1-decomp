// Authentic task.cpp owner wrapper.
//
// Source module: C:\\msdev\\work\\age1_x1\\task.cpp.
// PDB source order and exact anchors:
//   00508670  RGE_Task::RGE_Task  task.cpp:26-57
//   005086F0  RGE_Task::~RGE_Task task.cpp:62
//   00508700  RGE_Task::copy     task.cpp:68-98
//   005087C0  RGE_Task::load(int, RGE_Sprite**, RGE_Sound**) task.cpp:103-149
//   00508A20  RGE_Task::load(FILE*, RGE_Sprite**, RGE_Sound**) task.cpp:154-218
//   00508BB0  RGE_Task::save    task.cpp:223-267
//
// The shared context declares one canonical RGE_Task layout and its complete
// overload surface.  Each owner source contains only its authentic body.
#include "../include/task_context.h"

#include "matching/00508670_RGE_Task.cpp"
#include "matching/005086F0_RGE_Task.cpp"
#include "matching/00508700_copy.cpp"
#include "matching/005087C0_load.cpp"
#include "matching/00508A20_load.cpp"
#include "matching/00508BB0_save.cpp"
