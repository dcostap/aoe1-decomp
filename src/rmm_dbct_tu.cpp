// Canonical rmm_dbct.cpp owner sequence in complete PDB order.
//
// PDB order is preserved across the included owners.  The unresolved
// 00482B70 constructor, 00483600 calc_land_start, and 00483A20
// add_land_module remain scratch reconstructions.  00484470 is an
// accepted-drift owner.  These owners are included as observed sources so the
// wrapper is complete; exact tuning stops at wrapper compilation.
//
// The local context supplies one complete declaration surface for the owner
// sources.  It preserves the full aggregate layouts while avoiding duplicate
// per-function class declarations in this authentic single translation unit.
#include "rmm_dbct_tu_context.h"

#include "scratch/00482B70_RGE_RMM_Database_Controller.cpp"
#include "matching/00483020_RGE_RMM_Database_Controller.cpp"
#include "matching/00483200_RGE_RMM_Database_Controller.cpp"
#include "matching/004832E0_save.cpp"
#include "matching/00483430_generate.cpp"
#include "matching/00483540_init.cpp"
#include "matching/004835A0_de_init.cpp"
#include "scratch/00483600_calc_land_start.cpp"
#include "scratch/00483A20_add_land_module.cpp"
#include "matching/00484160_add_terrain_module.cpp"
#include "matching/00484320_add_object_module.cpp"
#include "accepted_drift/00484470_add_elevation_module.cpp"
