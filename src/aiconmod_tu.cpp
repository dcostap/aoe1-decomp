// Canonical authentic aiconmod.cpp owner context.
//
// PDB source: C:\\msdev\\work\\age1_x1\\aiconmod.cpp
// The owners below follow the original source-line and linked-address order.
// The generated scalar deleting destructor at 0040AB90 has no PDB source line
// and is intentionally omitted, as are no-line compiler artifacts in other
// canonical module wrappers.
//
// Exact anchors:
//   0040AA90  ConstructionAIModule(void*, int)       lines 36-43
//   0040ABB0  ConstructionAIModule(int, int)         lines 57-182
//   0040B690  loadConstructionPlan                  lines 308-380
//   0040BBB0  setBuilt                              lines 477-486
//
// The two reviewed behavior owners remain in their assigned banks:
//   0040B1A0  save                accepted drift, same ordered serialization
//   0040B980  setReferencePoint  accepted drift, same behavior and boundaries
// All other PDB owners in this range are matching sources. This file is an
// owner wrapper only. It does not register a translation-unit config entry.
#define AICONMOD_CANONICAL_TU 1
#include "../include/aiconmod_context.h"

#include "matching/0040AA90_ConstructionAIModule.cpp"
#include "matching/0040ABB0_ConstructionAIModule.cpp"
#include "matching/0040B120_ConstructionAIModule.cpp"
#include "accepted_drift/0040B1A0_save.cpp"
#include "matching/0040B690_loadConstructionPlan.cpp"
#include "matching/0040B970_constructionPlanName.cpp"
#include "accepted_drift/0040B980_setReferencePoint.cpp"
#include "matching/0040BB70_xReferencePoint.cpp"
#include "matching/0040BB80_yReferencePoint.cpp"
#include "matching/0040BB90_placeStructure.cpp"
#include "matching/0040BBA0_lastPlacementReturnCode.cpp"
#include "matching/0040BBB0_setBuilt.cpp"
#include "matching/0040BC00_unplaceStructure.cpp"
#include "matching/0040BC80_unplaceStructure.cpp"
#include "matching/0040BD10_decrementBuildAttempts.cpp"
#include "matching/0040BD40_incrementBuildAttempts.cpp"
#include "matching/0040BD70_lot.cpp"
#include "matching/0040BE10_randomLot.cpp"
#include "matching/0040BE70_removeOldLots.cpp"

#undef AICONMOD_CANONICAL_TU
