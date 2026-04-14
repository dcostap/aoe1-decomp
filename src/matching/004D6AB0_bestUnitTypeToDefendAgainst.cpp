class CombatRuleSystem {
public:
    virtual ~CombatRuleSystem();
    int bestUnitTypeToDefendAgainst(int p0);
};

int CombatRuleSystem::bestUnitTypeToDefendAgainst(int p0) { return -1; }
