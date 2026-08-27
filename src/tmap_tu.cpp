// Authentic PDB-ordered owner wrapper for tmap.cpp.
//
// Module: C:\\msdev\\work\\age1_x1\\tmap.cpp.
// Every normal owner from build/tu_plans/tmap_cpp/packet.json appears once,
// in PDB line order.  The scalar-deleting destructor at 0050F740 is generated
// by the canonical polymorphic TRIBE_Map declaration and is listed in the
// proposal manifest.
//
// TMAP_GROUP_CONTEXT selects the shared module declaration surface.  Individual
// owner files retain their standalone declarations for focused checks.  Their
// bodies, statuses, and accepted-drift notes are unchanged in this wrapper.

#define TMAP_GROUP_CONTEXT 1
#include "tmap_context_local.h"

#include "matching/0050F410_TRIBE_Map.cpp"
#include "matching/0050F760_TRIBE_Map.cpp"
#include "scratch/0050F7A0_TRIBE_Map.cpp"
#include "matching/0050F7B0_save.cpp"
#include "accepted_drift/0050F7C0_map_generate.cpp"
#include "matching/0050F7F0_map_generate.cpp"
#include "matching/0050F800_data_load_random_map.cpp"
#include "matching/0050F860_load_random_map.cpp"
#include "scratch/0050F8D0_check_tile_for_forest_change.cpp"
#include "scratch/0050FA90_change_terrain.cpp"
#include "scratch/0050FC40_do_terrain_brush.cpp"
#include "matching/0050FD40_do_terrain_brush_stroke.cpp"
#include "matching/0050FDD0_do_elevation_brush_stroke.cpp"
#include "matching/0050FE90_setup_cliff_type.cpp"
#include "matching/0050FF20_find_cliff.cpp"
#include "matching/00510020_get_cliff_info.cpp"
#include "matching/005100D0_check_cliff_valid.cpp"
#include "matching/00510110_make_new_cliff.cpp"
#include "scratch/005102A0_remove_cliff_edge.cpp"
#include "matching/00510410_reverse_cliff_direction.cpp"
#include "scratch/00510430_add_cliff_edge.cpp"
#include "matching/00510960_delete_cliff.cpp"
#include "matching/00510A50_do_cliff_brush.cpp"
#include "matching/00510C10_do_cliff_brush_stroke.cpp"
#include "matching/00510C90_water.cpp"
#include "matching/00510CB0_clean_borders.cpp"
#include "matching/00511000_do_terrain_brush_check.cpp"
#include "accepted_drift/005110E0_tribe_clean_elevation.cpp"
#include "scratch/005111A0_tribe_clean_terrain.cpp"

#undef TMAP_GROUP_CONTEXT
