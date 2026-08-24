// Authentic taibldmd.cpp translation-unit candidate.
//
// Source module: C:\\msdev\\work\\age1_x1\\taibldmd.cpp
// PDB owner order is preserved from lines 62 through 1773.  004D3AB0 is the
// compiler-generated vector deleting destructor between the destructor and
// second constructor; it is emitted by the canonical virtual surface and is
// listed in the candidate proposal, not included as a source owner.
//
// The original initialize, nextBuildableItem, and blockingResource bodies have
// EH-aware frames.  The candidate therefore uses the reviewed /GX flag set.
// This wrapper is a proposal only.  It does not register global configuration.
//
// Candidate categories are recorded in build/candidate_tus/proposals/
// taibldmd_cpp.json.  Sixteen normal owners and the generated deleting
// destructor match in this grouped compile.  The remaining twelve normal
// owners are observed mismatches, not exact claims.  Their source banks and
// status remain unchanged for main-agent review.
//
// The candidate uses no synthetic function, inline assembly, absolute-address
// stub, or duplicate compiler owner.  The prior readyToResearch padding helper
// was removed because it was not a PDB-owned body and used forbidden assembly.

#include "../include/taibldmd_context.h"
#define TAIBLDMD_SHARED_CONTEXT 1

#include "matching/004D3A80_TribeBuildAIModule.cpp"
#include "matching/004D3AD0_TribeBuildAIModule.cpp"
#include "matching/004D3B00_TribeBuildAIModule.cpp"
#include "matching/004D3B10_setMainDecisionAI.cpp"
#include "matching/004D3B20_loadBuildList.cpp"
#include "scratch/004D3D60_initialize.cpp"
#include "matching/004D4460_skipNextBuildListItem.cpp"
#include "scratch/004D4540_nextBuildableItem.cpp"
#include "matching/004D4DB0_nextBuildListItemCategory.cpp"
#include "accepted_drift/004D4E10_blockingResource.cpp"
#include "matching/004D4F80_mostNeededResource.cpp"
#include "matching/004D5090_addItem.cpp"
#include "matching/004D5170_addBuiltItem.cpp"
#include "matching/004D5270_removeBuiltItem.cpp"
#include "matching/004D5310_cancelBuildItem.cpp"
#include "matching/004D5590_addTrainedUnit.cpp"
#include "accepted_drift/004D5600_cancelTrainUnit.cpp"
#include "matching/004D5690_addResearch.cpp"
#include "matching/004D56F0_cancelResearch.cpp"
#include "matching/004D5780_isAgeResearch.cpp"
#include "matching/004D57A0_insert.cpp"
#include "matching/004D5AD0_insertResearch.cpp"
#include "matching/004D5B80_insertGathererPercentage.cpp"
#include "matching/004D5BB0_numberBuiltOrInProgressItemsOfType.cpp"
#include "matching/004D5C20_allBuilt.cpp"
#include "accepted_drift/004D5CA0_readyToResearch.cpp"
#include "accepted_drift/004D5D40_unskipBuildList.cpp"
#include "accepted_drift/004D5DE0_buildItem.cpp"
