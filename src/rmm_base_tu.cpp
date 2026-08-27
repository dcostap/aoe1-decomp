// Authentic PDB-order owner wrapper for C:\\msdev\\work\\age1_x1\\rmm_base.cpp.
//
// The context header owns the complete RGE_Random_Map_Module and Map_Stack
// surfaces.  The included bodies retain their reviewed source owners while
// this translation unit restores the original address order.
// No synthetic function or manual vtable write is used by this wrapper.

#define RMM_BASE_SHARED_CONTEXT 1
#include "../include/rmm_base_context.h"

#include "matching/00480790_RGE_Random_Map_Module.cpp"
#include "matching/00480840_RGE_Random_Map_Module.cpp"
#include "matching/004808C0_get_schedule.cpp"
#include "matching/004808D0_generate.cpp"
#include "matching/004809E0_add_module.cpp"
#include "accepted_drift/00480A20_remove_module.cpp"
#include "matching/00480A80_create_shared_resources.cpp"
#include "matching/00480B60_destroy_shared_resources.cpp"
#include "matching/00480BC0_update_child_resources.cpp"
#include "matching/00480BE0_update_resources.cpp"
#include "matching/00480C10_update_child_map_info.cpp"
#include "matching/00480C30_update_map_info.cpp"
#include "matching/00480C80_share_resources.cpp"
#include "matching/00480CC0_init_stack.cpp"
#include "matching/00480CF0_deinit_stack.cpp"
#include "matching/00480D10_push_stack.cpp"
#include "matching/00480DA0_pop_stack.cpp"
#include "matching/00480DE0_add_stack_node.cpp"
#include "matching/00480E20_remove_stack_node.cpp"
#include "matching/00480E50_clear_stack.cpp"
#include "matching/00480EA0_check_stack.cpp"
#include "accepted_drift/00480EC0_randomize_stack.cpp"
#include "matching/00480FB0_find_path.cpp"
#include "scratch/00481000_find_path.cpp"

#undef RMM_BASE_SHARED_CONTEXT
