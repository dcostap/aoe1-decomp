// Sparse canonical stat_obj.cpp translation unit in PDB source order.
// Each included file remains the sole source owner of its VA.
#define RGE_STAT_OBJ_SHARED_CONTEXT 1
#include "../include/stat_obj_context.h"

#include "matching/004C1CF0_change_unique_id.cpp"
#include "matching/004C1D60_create_object_list.cpp"
#include "matching/004C1DC0_create_sprite_list.cpp"
#include "matching/004C1E20_get_starting_attribute.cpp"
#include "accepted_drift/004C1E70_give_attribute_to_owner.cpp"
#include "accepted_drift/004C1ED0_take_attribute_from_owner.cpp"
#include "matching/004C1F30_draw.cpp"
#include "matching/004C2030_shadow_draw.cpp"
#include "matching/004C2080_normal_draw.cpp"
#include "accepted_drift/004C2110_draw_front_frame.cpp"
#include "matching/004C2220_capture_frame.cpp"
#include "matching/004C23F0_capture_frame_3d_cube.cpp"
#include "matching/004C2970_draw_frame_3d_square_back.cpp"
// 004C2B50 keeps its reviewed accepted-drift status in this context.
#include "accepted_drift/004C2B50_draw_frame_3d_square_front.cpp"
#include "matching/004C2DF0_draw_frame_3d_cube_back.cpp"
#include "matching/004C31E0_draw_frame_3d_cube_front.cpp"
// 004C3B30 is exact alone. The proven trailing virtual surfaces select a
// different coordinate schedule in this shared context, so stop this prefix.

#include "scratch/004C5610_check_object_bounds.cpp"
#include "matching/004C5B90_damage.cpp"
#include "matching/004C5BE0_calculateDamage.cpp"
#include "matching/004C5C10_rotate.cpp"
#include "matching/004C5C40_set_attribute.cpp"
#include "matching/004C5C60_set_attribute_amount.cpp"
#include "matching/004C5CB0_heal.cpp"
#include "matching/004C5D10_notify_of_relation.cpp"
#include "matching/004C5D20_set_being_worked_on.cpp"
#include "matching/004C5D40_release_being_worked_on.cpp"
#include "scratch/004C5D80_inRange.cpp"
#include "matching/004C5E50_distance_to_object.cpp"

#include "matching/004C66C0_RGE_Check_List.cpp"
#include "matching/004C66D0_RGE_Check_List.cpp"
#include "matching/004C6700_add_node.cpp"
#include "scratch/004C6740_make_object_bounds_list.cpp"

#undef RGE_STAT_OBJ_SHARED_CONTEXT
