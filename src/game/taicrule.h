#pragma once
#include "../common.h"

class CombatRuleSystem {
public:
    uchar ratingValue[2500];                 // 0x4

    CombatRuleSystem();
    virtual ~CombatRuleSystem();
    virtual int loadRules(char* param_1);
    virtual int bestUnitTypeToAttack(int param_1);
    virtual int bestUnitTypeToDefendAgainst(int param_1);
};

static_assert(sizeof(CombatRuleSystem) == 0x9C8, "CombatRuleSystem Size Mismatch");
static_assert(offsetof(CombatRuleSystem, ratingValue) == 0x4, "CombatRuleSystem Offset Mismatch");

