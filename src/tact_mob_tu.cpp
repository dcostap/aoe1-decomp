// Authentic tact_mob.cpp owner wrapper.
//
// Source module: C:\\msdev\\work\\age1_x1\\tact_mob.cpp
// PDB owner order and source bands:
//   004D0DD0  TRIBE_Action_Make_Obj(int, RGE_Action_Object*)       31-41
//   004D0EB0  TRIBE_Action_Make_Obj(RGE_Action_Object*,...)       48-54
//   004D0EF0  ~TRIBE_Action_Make_Obj                          60-65
//   004D0F70  save                                           69-76
//   004D0FC0  first_in_stack                                79-116
//   004D10E0  set_state                                    120-123
//   004D10F0  update                                       126-167
//   004D12B0  place_obj                                    171-233
//   004D1550  stop                                         237-251
//   004D15F0  get_info                                     255-268
//
// The compiler-generated vector-deleting destructor at 004D0E90 is emitted by
// the canonical TRIBE_Action_Make_Obj virtual destructor. It has no source
// owner. The wrapper includes each normal owner once and keeps PDB order.
// The shared context preserves the shipped action offsets, virtual slots,
// mixed calling conventions, x87 work calculation, and placement formulas.
//
// Exact anchors: 004D0DD0, 004D0EF0, 004D0F70, 004D10E0, 004D10F0, and
// 004D1550. The second constructor, first_in_stack, place_obj, and get_info
// remain observed nonexact owners in their reviewed source banks.

#define TACT_MOB_SHARED_CONTEXT 1
#include "../include/tact_mob_context.h"

#include "matching/004D0DD0_TRIBE_Action_Make_Obj.cpp"
#include "accepted_drift/004D0EB0_TRIBE_Action_Make_Obj.cpp"
#include "matching/004D0EF0_TRIBE_Action_Make_Obj.cpp"
#include "matching/004D0F70_save.cpp"
#include "accepted_drift/004D0FC0_first_in_stack.cpp"
#include "matching/004D10E0_set_state.cpp"
#include "matching/004D10F0_update.cpp"
#include "matching/004D12B0_place_obj.cpp"
#include "matching/004D1550_stop.cpp"
#include "matching/004D15F0_get_info.cpp"

#undef TACT_MOB_SHARED_CONTEXT
