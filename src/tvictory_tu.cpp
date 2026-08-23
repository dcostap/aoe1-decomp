// Authentic tvictory.cpp owner wrapper.
//
// The PDB source module is C:\\msdev\\work\\age1_x1\\tvictory.cpp. The
// owner order below follows its PDB line and address order. These six owners
// form the reviewed source span from 0052C8F0 through 0052C9D3.
//
// Exact anchors retained by the owners:
// - 0052C8F0 calls RGE_Victory_Conditions::RGE_Victory_Conditions at 00531750
//   and publishes the TRIBE vtable at 00531F30.
// - 0052C920 calls the one-argument base constructor at 00531AF0 and publishes
//   the same TRIBE vtable.
// - 0052C940 publishes the TRIBE vtable, then tail-jumps to 00531B20.
// - 0052C950 preserves both calls: base handle_condition at 00531F90 and the
//   local handle_tech owner at 0052C970.
// - 0052C970 preserves the TRIBE_Player_Tech::get_tech_state call at 0050C58C.
// - 0052C9B0 preserves the base add call at 00532930 and command 'd'.
// 0052C970 remains scratch. The current context loads +0x2D4 instead of the
// original +0x220 player technology owner offset.
//
// Do not add this module to config here. Its owners remain individually
// published through the existing function map until the main agent registers
// the module.

#include "../include/tvictory_context.h"

// tvictory.cpp:30-31
#include "matching/0052C8F0_TRIBE_Victory_Conditions.cpp"

// tvictory.cpp:37-38
#include "matching/0052C920_TRIBE_Victory_Conditions.cpp"

// tvictory.cpp:43
#include "matching/0052C940_TRIBE_Victory_Conditions.cpp"

// tvictory.cpp:49-59
#include "matching/0052C950_handle_condition.cpp"

// tvictory.cpp:63-67
#include "scratch/0052C970_handle_tech.cpp"

// tvictory.cpp:71-83
#include "matching/0052C9B0_add_tech.cpp"
