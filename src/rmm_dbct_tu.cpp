// Canonical rmm_dbct.cpp owner sequence for the reviewed database prefix.
//
// PDB order is preserved across the included owners.  The unresolved
// The 00482B70 constructor remains a scratch reconstruction with an open
// register/CFG frontier.  It is included here to test the complete prefix, but
// its mismatch does not support an exactness claim for the module.
//
// The module uses one response-file flag set.  The /GX set is required by the
// exact constructor and generator anchors; it is not a per-function mixture.
// Boundary status: 00482B70 remains unresolved through 00483010. The complete
// wrapper preserves the later exact anchors 00483020, 00483200, 00483430,
// 00483540, and 004835A0.
#include "scratch/00482B70_RGE_RMM_Database_Controller.cpp"
#include "matching/00483020_RGE_RMM_Database_Controller.cpp"
#include "matching/00483200_RGE_RMM_Database_Controller.cpp"
#include "matching/004832E0_save.cpp"
#include "matching/00483430_generate.cpp"
#include "matching/00483540_init.cpp"
#include "matching/004835A0_de_init.cpp"
#include "scratch/00483600_calc_land_start.cpp"
