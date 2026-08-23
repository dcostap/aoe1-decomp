// Authentic ttsk_lst.cpp owner wrapper.
//
// Source module: C:\\msdev\\work\\age1_x1\\ttsk_lst.cpp.
// The PDB order is the source order.  The target body starts at line 41 and
// ends at line 294.  is_attack_task starts at line 299 and ends at line 304.
//
// Canonical owners and address anchors:
//   0052C3F0  TRIBE_Task_List::get_target_task  ttsk_lst.cpp:41-294
//             eight calls: 0052C580, 0052C598, 0052C60A, 0052C6B2,
//             0052C6CE, 0052C78F, 0052C7F1, and base call 0052C894
//   0052C8A1  reviewed padding-only switch-table boundary; not an owner
//   0052C8D0  TRIBE_Task_List::is_attack_task ttsk_lst.cpp:299-304
//             exact anchor and end at 0052C8F0
//
// The target packet proves the seven indirect calls use RGE_Player::isAlly at
// virtual slot +0x1C.  The last call is the direct RGE_Task_List base method.
// Keep those owners and call surfaces.  Do not replace them with free helpers.
//
// RGE_Task_List::list and list_num are the one shared list pointer and count at
// +0x04 and +0x08.  The bodies keep this alias.  Do not add a second list or a
// cached list owner.  The executable also dereferences task entries directly.
// Do not add null checks that are not in the shipped code.
//
// This source module has no panel or other UI call site.  The wrapper does not
// add a UI shim.  It preserves the canonical game relation calls above.
// The context header keeps the reviewed game-object field owners and the
// period virtual order.  It does not change config/translation_units.json.
#include "../include/ttsk_lst_context.h"

#include "scratch/0052C3F0_get_target_task.cpp"
#include "matching/0052C8D0_is_attack_task.cpp"
