#ifndef AOE1_TAICRULE_CONTEXT_H
class CombatRuleSystem {
public:
    virtual ~CombatRuleSystem();
    int bestUnitTypeToDefendAgainst(int p0);
};
#endif

int CombatRuleSystem::bestUnitTypeToDefendAgainst(int p0) { return -1; }
