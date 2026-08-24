// Authentic PDB-ordered owner wrapper for map.cpp.
//
// Module: C:\\msdev\\work\\age1_x1\\map.cpp.
// The owner order follows the PDB line bands in
// build/tu_plans/map_cpp/packet.json.  The vector-deleting destructor at
// 00455080 is compiler generated and is listed in the proposal manifest.
//
// The normal path uses the pinned default response file (/O2 /Oy).  Exact
// owners remain in src/matching; accepted-drift and scratch owners are
// reported as observed functions in the candidate proposal.
// No map.cpp owner is blocked; the generated vector-deleting destructor is
// recorded separately in the proposal.
// Packet accounting: 49 exact owners, 15 observed owners, and one generated
// entry. The candidate compiles under config/flags/default.rsp. Mismatches
// remain recorded as observed results; this captain pass does not tune them.

#define MAP_CONTEXT_TU 1
#include "../include/map_context.h"

#include "accepted_drift/00455000_RGE_Map.cpp"
#include "matching/004550A0_RGE_Map.cpp"
#include "matching/00455430_RGE_Map.cpp"
#include "matching/00455570_init_tile_sizes.cpp"
#include "matching/004557C0_data_load_random_map.cpp"
#include "matching/00455820_load_random_map.cpp"
#include "matching/00455890_set_map_visible.cpp"
#include "matching/004558A0_set_map_fog.cpp"
#include "matching/004558B0_clear_map.cpp"
#include "matching/00455910_new_map.cpp"
#include "accepted_drift/00455C20_clear_map.cpp"
#include "matching/00455CB0_request_redraw.cpp"
#include "matching/00455D60_clear_map_view_info.cpp"
#include "matching/00455DB0_coordinate_map.cpp"
#include "matching/00455DD0_set_map_screen_pos.cpp"
#include "matching/00455F10_scenario_save.cpp"
#include "matching/00455FF0_scenario_load.cpp"
#include "matching/00456140_give_up_map_offsets.cpp"
#include "matching/00456150_get_map_width.cpp"
#include "matching/00456160_get_map_height.cpp"
#include "scratch/00456170_postclean_elevation.cpp"
#include "matching/004564E0_preclean_elevation.cpp"
#include "matching/004568C0_clean_elevation.cpp"
#include "matching/00456E90_clean_terrain.cpp"
#include "matching/00457300_clean_borders.cpp"
#include "matching/00457310_clean_border_tile.cpp"
#include "matching/00457320_do_terrain_brush.cpp"
#include "matching/004573C0_do_terrain_brush_stroke.cpp"
#include "matching/00457510_do_elevation_brush.cpp"
#include "matching/004575C0_do_elevation_brush_stroke.cpp"
#include "matching/00457750_do_cliff_brush.cpp"
#include "matching/00457760_do_cliff_brush_stroke.cpp"
#include "matching/004578A0_map_generate.cpp"
#include "matching/004578B0_map_generate2.cpp"
#include "matching/004579C0_load_map.cpp"
#include "accepted_drift/00457C50_save_map.cpp"
#include "accepted_drift/00457DF0_save.cpp"
#include "matching/00457EB0_load_terrain_types.cpp"
#include "scratch/00457F80_load_terrain_types.cpp"
#include "matching/00458280_load_border_types.cpp"
#include "scratch/00458350_load_border_types.cpp"
#include "matching/00458600_load_terrain_obj_types.cpp"
#include "matching/00458760_delete_objects_on_tile.cpp"
#include "matching/004587D0_delete_all_objects_on_tile.cpp"
#include "scratch/00458820_create_terrain_object.cpp"
#include "scratch/00458B40_clear_terrain_object.cpp"
#include "scratch/00458C90_place_terrain_object.cpp"
#include "matching/00458FD0_create_terrain_objects.cpp"
#include "matching/00459020_set_tile_size.cpp"
#include "scratch/00459060_tile_map_coords.cpp"
#include "matching/004593A0_check_map_coords.cpp"
#include "matching/004593D0_get_elev.cpp"
#include "matching/00459400_get_terrain.cpp"
#include "matching/00459460_get_border.cpp"
#include "accepted_drift/004594B0_set_terrain_passablity.cpp"
#include "accepted_drift/004595E0_set_elev.cpp"
#include "matching/00459900_set_terrain.cpp"
#include "matching/00459A00_set_terrain_absolute.cpp"
#include "accepted_drift/00459A90_set_terrain.cpp"
#include "matching/00459D20_get_tile_type.cpp"
#include "scratch/0045A030_get_border_type.cpp"
#include "matching/0045A490_check_for_border.cpp"
#include "matching/0045A500_update.cpp"
#include "matching/0045A6D0_get_point.cpp"
