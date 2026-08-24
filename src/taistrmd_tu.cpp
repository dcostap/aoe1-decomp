// Authentic PDB-ordered owner wrapper for C:\\msdev\\work\\age1_x1\\taistrmd.cpp.
//
// The packet contains 33 normal owners in lines 34 through 1650.  This wrapper
// keeps the owners in PDB line and shipped-address order.  The two nearby
// deleting destructors are compiler-generated and are listed in the proposal.
//
// The shared context header is the canonical module declaration surface.  The
// owner files keep standalone declarations behind a declaration-only guard.
//
// No synthetic function, inline assembly, absolute-address stub, or duplicate
// compiler owner is included.  Existing accepted-drift owners are preserved;
// this packet has no accepted-drift normal owner.
//
// Candidate result: 28 exact owners, 5 observed owners, and 2 generated
// deleting destructors.  The complete wrapper compiles in PDB order.  The two
// grouped mismatches remain observed and receive no grouped-only body fork.

#define TAISTRMD_TU_CONTEXT 1
#include "../include/taistrmd_context.h"

#include "matching/004E6E10_VictoryConditionRuleSystem.cpp"
#include "matching/004E7430_VictoryConditionRuleSystem.cpp"
#include "matching/004E7440_loadRules.cpp"
#include "matching/004E75D0_setRule.cpp"
#include "matching/004E75F0_rule.cpp"
#include "matching/004E7610_evaluateAsInProgress.cpp"
#include "matching/004E7620_evaluateAsNonInProgress.cpp"
#include "matching/004E7690_execute.cpp"
#include "matching/004E8D10_stopExecution.cpp"
#include "matching/004E8D20_modifyForDifficultyLevel.cpp"
#include "matching/004E9100_TribeStrategyAIModule.cpp"
#include "matching/004E9260_TribeStrategyAIModule.cpp"
#include "matching/004E9730_TribeStrategyAIModule.cpp"
#include "scratch/004E9820_update.cpp"
#include "matching/004e9d90_setMainDecisionAI.cpp"
#include "matching/004E9DA0_save.cpp"
#include "matching/004ea130_ruleSetName.cpp"
#include "matching/004EA140_loadRules.cpp"
#include "matching/004EA180_setRule.cpp"
#include "scratch/004EA1B0_rule.cpp"
#include "scratch/004EA1D0_setDifficultyLevel.cpp"
#include "matching/004ea1f0_currentVictoryCondition.cpp"
#include "matching/004ea200_targetID.cpp"
#include "matching/004ea210_targetType.cpp"
#include "matching/004ea220_secondTargetID.cpp"
#include "matching/004ea230_secondTargetType.cpp"
#include "matching/004ea240_targetPoint1.cpp"
#include "matching/004ea250_targetPoint2.cpp"
#include "matching/004ea260_targetAttribute.cpp"
#include "matching/004ea270_targetNumber.cpp"
#include "matching/004EA280_setVictoryCondition.cpp"
#include "matching/004EA7C0_isRuleExecuting.cpp"
#include "matching/004EA810_isRuleIdle.cpp"

#undef TAISTRMD_TU_CONTEXT
