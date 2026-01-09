#pragma once
#include "common.h"

class CombatRuleSystem : public AIModule {
public:

    CombatRuleSystem();
    ~CombatRuleSystem();
    int loadRules(char* param_1);
    int bestUnitTypeToAttack(int param_1);
    int bestUnitTypeToDefendAgainst(int param_1);
};

static_assert(sizeof(CombatRuleSystem) == 0x9C8, "CombatRuleSystem Size Mismatch");

