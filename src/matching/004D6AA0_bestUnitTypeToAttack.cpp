#ifndef AOE1_TAICRULE_CONTEXT_H
class CombatRuleSystem {
public:
    virtual ~CombatRuleSystem();
    int bestUnitTypeToAttack(int p0);
};
#endif

int CombatRuleSystem::bestUnitTypeToAttack(int p0) { return -1; }
