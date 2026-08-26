// Authentic PDB-ordered owner wrapper for C:\msdev\work\age1_x1\victory.cpp.
//
// The PDB source module contains 58 normal owners from lines 28-1552. The
// wrapper keeps those owners in source-line and address order. Matching owners
// are exact owners. Scratch and accepted-drift owners remain observed in the
// candidate proposal; this wrapper does not promote or retune them.
//
// 00531F71 is a compiler-generated padding-only fragment. It has no source
// include. The module has no nearby compiler-generated owner in its packet.
//
// The current shared declaration surface is include/victory_context.h. The
// first prefix and later point-handler wrappers proved parts of this context.
// Older owner files retain standalone declarations behind declaration-only
// guards. Standalone builds keep their donor declarations; this wrapper uses
// one canonical context without grouped-only body forks.

#include "../include/victory_context.h"

#include "scratch/00531750_RGE_Victory_Conditions.cpp"
#include "matching/00531AF0_RGE_Victory_Conditions.cpp"
#include "matching/00531B20_RGE_Victory_Conditions.cpp"
#include "matching/00531B70_save.cpp"
#include "accepted_drift/00531DB0_check_for_victory.cpp"
#include "matching/00531E90_update.cpp"
#include "matching/00531EF0_update_for_object.cpp"
#include "matching/00531F30_handle_point_condition.cpp"
#include "matching/00531F90_handle_condition.cpp"
#include "matching/00532050_handle_capture.cpp"
#include "matching/00532110_handle_create.cpp"
#include "matching/00532220_handle_create_in_area.cpp"
#include "matching/005323B0_handle_destroy.cpp"
#include "matching/005323D0_handle_destroy_multiple.cpp"
#include "accepted_drift/005324A0_handle_destroy_all.cpp"
#include "matching/00532570_handle_destroy_player.cpp"
#include "matching/005325A0_handle_bring_area.cpp"
#include "matching/00532610_handle_bring_object.cpp"
#include "accepted_drift/005326F0_handle_attribute.cpp"
#include "matching/005327A0_handle_explore.cpp"
#include "matching/00532880_handle_victory_points.cpp"
#include "matching/00532930_add.cpp"
#include "matching/00532970_add_capture.cpp"
#include "matching/005329A0_add_create.cpp"
#include "matching/005329D0_add_create.cpp"
#include "matching/00532A20_add_destroy.cpp"
#include "matching/00532A50_add_destroy.cpp"
#include "matching/00532A90_add_destroy.cpp"
#include "matching/00532AC0_add_destroy.cpp"
#include "matching/00532AF0_add_bring.cpp"
#include "matching/00532B30_add_bring.cpp"
#include "matching/00532B70_add_attributes.cpp"
#include "matching/00532BA0_add_explore.cpp"
#include "matching/00532BE0_add_victory_points.cpp"
#include "accepted_drift/00532C10_sub.cpp"
#include "matching/00532C50_destroy_all.cpp"
#include "matching/00532C70_condition_info.cpp"
#include "matching/00532CC0_condition_description.cpp"
#include "accepted_drift/00532ED0_condition_raw_info.cpp"
#include "matching/00532EF0_condition_number.cpp"
#include "matching/00532F00_victory_achieved.cpp"
#include "matching/00532F10_remove_condition.cpp"
#include "matching/00532F50_add_point.cpp"
#include "accepted_drift/00532FA0_sub_point.cpp"
#include "matching/00532FE0_add_points_attribute_amount.cpp"
#include "matching/00533020_add_points_attribute_first.cpp"
#include "matching/00533060_add_points_highest_attribute.cpp"
#include "matching/005330A0_add_points_high_attribute_once.cpp"
#include "matching/005330E0_add_points_high_attribute_amount.cpp"
#include "matching/00533120_handle_points_attribute_amount.cpp"
#include "matching/00533180_handle_points_attribute_first.cpp"
#include "scratch/00533240_handle_points_highest_attribute.cpp"
#include "matching/00533330_handle_points_high_attribute_once.cpp"
#include "matching/00533410_handle_points_high_attribute_amount.cpp"
#include "matching/00533480_get_victory_points.cpp"
#include "matching/00533490_get_victory_points_group.cpp"
#include "matching/005334C0_get_victory_points_id.cpp"
#include "matching/005334E0_get_attribute_id.cpp"
