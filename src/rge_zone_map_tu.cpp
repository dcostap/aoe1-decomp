// Canonical zone_map.cpp reconstruction TU.
// Each included file remains the sole VA-named owner of its member body.
// Keep the complete module context before the owner bodies. The common zone
// map header is suppressed so the module-local declaration surface is shared
// by every owner without changing any owner source.
#define ZONE_MAP_TU_BUILD 1
#include "zone_map_tu_context.h"

#include "matching/00546720_zone_pop.cpp"
#include "matching/00546770_zone_push.cpp"
#include "accepted_drift/005467B0_RGE_Zone_Map.cpp"
#include "matching/005468C0_RGE_Zone_Map.cpp"
#include "matching/005469C0_RGE_Zone_Map.cpp"
#include "matching/00546A00_save.cpp"
#include "accepted_drift/00546A90_do_zone_map.cpp"
#include "accepted_drift/00546BB0_do_zone_map_area.cpp"
#include "matching/00546E50_check_info.cpp"
#include "matching/00546EB0_get_zone_info.cpp"
#include "matching/00546ED0_withinRange.cpp"
#include "matching/00546F00_withinRange.cpp"
#include "matching/00547000_numberTilesInZone.cpp"
#include "matching/00547080_findClosestPointInTerrainType.cpp"
#include "matching/00547180_RGE_Zone_Map_List.cpp"
#include "matching/00547240_RGE_Zone_Map_List.cpp"
#include "matching/00547260_RGE_Zone_Map_List.cpp"
#include "matching/00547270_save.cpp"
#include "matching/005472B0_create_zone_map.cpp"
#include "matching/005473B0_get_zone_map.cpp"
#include "matching/005474B0_get_zone_map.cpp"
#include "matching/005474D0_delete_zone_maps.cpp"

#undef ZONE_MAP_TU_BUILD
