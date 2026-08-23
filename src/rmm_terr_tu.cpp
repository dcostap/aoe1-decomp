// Canonical owner wrapper for C:\\msdev\\work\\age1_x1\\rmm_terr.cpp.
//
// PDB order and exact anchors:
//   004888E0 ctor                  rmm_terr.cpp:24-28   59 bytes
//   00488920 generate              rmm_terr.cpp:32-54  173 bytes
//   004889D0 water                 rmm_terr.cpp:62-70   28 bytes
//   004889F0 check_borders         rmm_terr.cpp:76-116 409 bytes
//   00488B90 check_terrain         rmm_terr.cpp:121-173 437 bytes
//   00488D50 generate_modifiers    rmm_terr.cpp:179-213 240 bytes
//   00488E40 fig_chance            rmm_terr.cpp:218-225  27 bytes
//   00488E60 count_map_tiles       rmm_terr.cpp:231-241  54 bytes
//   00488EA0 link_stack_randomly   rmm_terr.cpp:245-275 239 bytes
//   00488F90 remove_area_from_lists rmm_terr.cpp:279-300 154 bytes
//   00489030 base_terrain_generate rmm_terr.cpp:305-504 2204 bytes
//
// Exact anchors are the reviewed neighboring owners. 00488B90 and 00489030
// remain behavior-reviewed accepted-drift owners. Their typed surfaces retain
// the clipped inclusive scans, direct tile-byte ownership, x87 conversions,
// debug_rand call order, stack mutation, and fault order. Do not compile these
// owners as unrelated standalone translation units when testing rmm_terr.cpp.

#include "matching/004888E0_RGE_RMM_Terrain_Generator.cpp"
#include "matching/00488920_generate.cpp"
#include "matching/004889D0_water.cpp"
#include "matching/004889F0_check_borders.cpp"
#include "accepted_drift/00488B90_check_terrain.cpp"
#include "matching/00488D50_generate_modifiers.cpp"
#include "matching/00488E40_fig_chance.cpp"
#include "matching/00488E60_count_map_tiles.cpp"
#include "matching/00488EA0_link_stack_randomly.cpp"
#include "matching/00488F90_remove_area_from_lists.cpp"
#include "matching/00489030_base_terrain_generate.cpp"
