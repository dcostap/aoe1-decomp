// Authentic pathsys.cpp owner wrapper.
//
// PDB source: C:\\msdev\\work\\age1_x1\\pathsys.cpp
// Includes follow the shipped source-line and address order. The module uses
// the constructor's reviewed /GX flags because the PathingSystem constructor
// and destructor own EH state in this source group.
//
// Exact owners: 12 matching sources.
// Observed owners: 8 scratch sources and 2 accepted-drift sources.
// Generated owner: the scalar deleting destructor at 0046B250.
// No exact tuning is performed in this wrapper pass.

#define PATHSYS_TU_CONTEXT 1
#include "../include/pathsys_context.h"

#include "scratch/0046B060_E9.cpp"
#include "scratch/0046B0B0_E14.cpp"
#include "matching/0046B0F0_PathingSystem.cpp"
#include "matching/0046B270_PathingSystem.cpp"
#include "matching/0046B310_initialize.cpp"
#include "matching/0046B360_printToFile.cpp"
#include "matching/0046B550_lookupMisc.cpp"
#include "matching/0046B570_setMisc.cpp"
#include "scratch/0046B590_initMisc.cpp"
#include "matching/0046B5C0_zeroObstructionMap.cpp"
#define obstructionValue obstructionValueFlat
#include "matching/0046B5E0_obstruction.cpp"
#include "matching/0046B620_incrementObstruction.cpp"
#include "accepted_drift/0046B680_decrementObstruction.cpp"
#undef obstructionValue
#include "scratch/0046B6E0_findTilePath.cpp"

#undef FADDR
#undef DADDR
#undef MapPathsDisplay
#undef rge_base_game
#undef numberPathingIterations
#undef DiagionalDistance
#undef FacetSkipMask
#undef ObstructionValueShift
#undef ObstructionMasks
#undef VPAD1
#undef VPAD2
#undef VPAD4
#undef VPAD8
#undef VPAD16
#undef VPAD32

#include "matching/0046D250_incrementInitialPaths.cpp"
#include "matching/0046D260_incrementContinuePaths.cpp"
#include "matching/0046D270_incrementCanPaths.cpp"
#include "scratch/0046D280_passable.cpp"
#include "matching/0046D740_checksum.cpp"
#include "matching/0046D770_printState.cpp"
#include "accepted_drift/0046D830_copyPath.cpp"
#include "matching/0046DCB0_copyUnobstructibles.cpp"

#undef PATHSYS_TU_CONTEXT
