struct TacticalAIGroup {
    int addUnit(int groupId, int pMainAI);
};

struct TribeTacticalAIModule {
    char gap_0[0xF0];
    int mainDecisionAI;
    TacticalAIGroup* group(int unitId, int a, int b, int c);
    int addToGroup(int groupId, int unitId);
};

int TribeTacticalAIModule::addToGroup(int groupId, int unitId) {
    TacticalAIGroup* grp = group(unitId, -1, -1, -1);
    if (!grp)
        return 0;
    return grp->addUnit(groupId, mainDecisionAI);
}
