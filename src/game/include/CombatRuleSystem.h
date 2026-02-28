#pragma once
#include "common.h"

class CombatRuleSystem {
public:
    CombatRuleSystem();
    // Virtuals (best-effort)
    virtual ~CombatRuleSystem(); // vt[0] (0x0)
    int loadRules(char* param_1);
    int bestUnitTypeToAttack(int param_1);
    int bestUnitTypeToDefendAgainst(int param_1);

    uchar ratingValue[2500];
};
static_assert(sizeof(CombatRuleSystem) == 0x9C8, "Size mismatch");
