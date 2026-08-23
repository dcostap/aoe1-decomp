// Canonical obj_list.cpp translation unit.
// Each normal owner is included once in PDB address order.
#define OBJLIST_SHARED_CONTEXT 1
#include "../include/obj_list_context.h"

#include "matching/00462E80_RGE_Object_List.cpp"
#include "matching/00462EA0_RGE_Object_List.cpp"
#include "matching/00462EF0_removeAllObjects.cpp"
#include "accepted_drift/00462F30_add_node.cpp"
#include "matching/00462F70_remove_node.cpp"
#include "matching/00462FD0_invert.cpp"
#include "matching/00463000_draw.cpp"
// 004630DD is reviewed padding-only and is not an obj_list.cpp owner.
#include "matching/00463100_shadow_draw.cpp"
#include "matching/00463180_normal_draw.cpp"
#include "matching/00463210_update.cpp"
#include "matching/00463260_sort.cpp"
#include "matching/004632E0_find_by_group.cpp"
#include "matching/00463310_find_by_group.cpp"
#include "matching/00463490_find_by_id.cpp"
#include "matching/004634C0_find_by_master_id.cpp"
#include "matching/00463640_find_by_master_ids.cpp"
#include "matching/004637C0_find_by_type.cpp"
#include "matching/00463890_save.cpp"
#include "matching/004638D0_load_list.cpp"
#include "matching/00463910_rehook_list.cpp"
#include "matching/00463930_load.cpp"

#undef OBJLIST_SHARED_CONTEXT
