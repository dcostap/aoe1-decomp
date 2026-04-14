class CombatRuleSystem {
public:
    virtual ~CombatRuleSystem();
    int bestUnitTypeToAttack(int p0);
};

int CombatRuleSystem::bestUnitTypeToAttack(int p0) { return -1; }
