#pragma once
#include "common.h"

class VictoryConditionRuleSystem {
public:
    VictoryConditionRuleSystem();

    // Virtuals (best-effort)
    virtual ~VictoryConditionRuleSystem(); // vt[0] (0x0)

    int loadRules(char* param_1);
    void setRule(int param_1, int param_2);
    int rule(int param_1);
    int evaluateAsInProgress(TRIBE_Player* param_1, int param_2);
    int evaluateAsNonInProgress(TRIBE_Player* param_1, int param_2);
    int execute(TRIBE_Player* param_1, int param_2, int param_3);
    int stopExecution(TRIBE_Player* param_1, int param_2);
    void modifyForDifficultyLevel(int param_1);

    int sn[226];
};
static_assert(sizeof(VictoryConditionRuleSystem) == 0x38C, "Size mismatch");
