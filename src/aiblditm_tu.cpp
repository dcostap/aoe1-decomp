// Authentic aiblditm.cpp translation-unit candidate.
// PDB owner order is preserved from lines 36 through 335.
// The class surface uses the reviewed BaseItem layout and a natural virtual
// destructor. It does not write a vtable, add a fake slot, or add a stub.
// Binary evidence fixes next/prev at +0x6C/+0x70, buildFrom at +0x8C, and
// terrainSet plus two adjacency values at +0x90 through +0x98.
// Candidate result: 29 exact owners match at 0 bytes, and the generated
// deleting destructor at 00408200 matches with ??_GBuildItem@@UAEPAXI@Z.
// Five operator/destructor entries remain observed: 00408470 matches; the
// four comparison operators have 0-byte code diffs but unverified owner kind.
// Blocked generated entries: none. Exact decorated symbols are in the packet.
#include "../include/aiblditm_context.h"

#include "matching/00408190_BuildItem.cpp"
#include "matching/00408220_BuildItem.cpp"
#include "matching/004082F0_BuildItem.cpp"
#include "matching/004083B0_BuildItem.cpp"
#include "matching/00408470_BuildItem.cpp"
#include "matching/00408480_operator.cpp"
#include "matching/004084A0_operator.cpp"
#include "scratch/004084C0_operator.cpp"
#include "scratch/004084E0_operator.cpp"
#include "matching/00408500_buildCategory.cpp"
#include "matching/00408510_number.cpp"
#include "matching/00408520_priority.cpp"
#include "matching/00408530_inProgress.cpp"
#include "matching/00408540_built.cpp"
#include "matching/00408550_buildAttempts.cpp"
#include "matching/00408560_buildFrom.cpp"
#include "matching/00408570_terrainSet.cpp"
#include "matching/00408580_terrainAdjacency.cpp"
#include "matching/004085A0_placeOnElevation.cpp"
#include "matching/004085B0_setInProgress.cpp"
#include "matching/004085C0_setBuilt.cpp"
#include "matching/004085D0_setBuildAttempts.cpp"
#include "matching/004085E0_incrementBuildAttempts.cpp"
#include "matching/004085F0_decrementBuildAttempts.cpp"
#include "matching/00408610_numberBuilds.cpp"
#include "matching/00408620_incrementNumberBuilds.cpp"
#include "matching/00408630_setNumberBuilds.cpp"
#include "matching/00408640_buildCap.cpp"
#include "matching/00408650_setBuildCap.cpp"
#include "matching/00408660_skipCycles.cpp"
#include "matching/00408670_incrementSkipCycles.cpp"
#include "matching/00408680_setSkipCycles.cpp"
#include "matching/00408690_permanentSkip.cpp"
#include "matching/004086A0_setPermanentSkip.cpp"
