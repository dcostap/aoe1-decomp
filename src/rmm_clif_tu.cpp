// Authentic PDB-ordered owner wrapper for rmm_clif.cpp.
//
// Owner order follows the shipped source-line bands:
//   00481980 constructor       lines 33-37
//   004819C0 generate          lines 41-56
//   00481A00 setup_cliff_maps  lines 60-173
//   00481CD0 generate_cliff    lines 177-294
//   00481FC0 check_for_valid_cliff_site lines 298-344
//   004820A0 invalidate_cliff_area    lines 348-375
//
// Exact anchors are the five matching owners. The final owner remains an
// observed scratch reconstruction until its complete body is validated.

#define RMM_CLIF_SHARED_CONTEXT 1

#include "matching/00481980_RGE_RMM_Cliffs_Generator.cpp"
#include "matching/004819C0_generate.cpp"
#include "matching/00481A00_setup_cliff_maps.cpp"
#include "matching/00481CD0_generate_cliff.cpp"
#include "matching/00481FC0_check_for_valid_cliff_site.cpp"
#include "scratch/004820A0_invalidate_cliff_area.cpp"

#undef RMM_CLIF_SHARED_CONTEXT
