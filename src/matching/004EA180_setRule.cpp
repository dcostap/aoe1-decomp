#include "../../include/taistrmd_context.h"

void logCommonHistory(AIModule* ai, const char* fmt, int value1, int value2);

#ifndef TAISTRMD_TU_CONTEXT
class AIModule {};

class VictoryConditionRuleSystem {
public:
    void setRule(int rule, int value);
};

class TribeStrategyAIModule : public AIModule {
public:
    char gap_00[0x268];
    VictoryConditionRuleSystem vcRules;

    void setRule(int rule, int value);
};
#endif

void TribeStrategyAIModule::setRule(int rule, int value) {
    logCommonHistory((AIModule*)this, "Setting SN[%d] to %d.", rule, value);
    this->vcRules.setRule(rule, value);
}
