#include "../../include/taistrmd_context.h"

// PDB ownership is VictoryConditionRuleSystem, not TribeStrategyAIModule.
// The corrected qualified symbol and the five body bytes both match exactly.

int VictoryConditionRuleSystem::stopExecution(TRIBE_Player*, int) {
    return 0;
}
