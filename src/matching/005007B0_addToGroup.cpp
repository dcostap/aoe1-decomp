#ifndef TAITACMD_SHARED_CONTEXT
#ifndef TAITACMD_SHARED_CONTEXT
struct TacticalAIGroup {
    int addUnit(int groupId, int pMainAI);
};

struct TribeTacticalAIModule {
    char gap_0[0xF0];
    int mainDecisionAI;
    TacticalAIGroup* group(int unitId, int a, int b, int c);
    int addToGroup(int groupId, int unitId);
};

#endif
int TribeTacticalAIModule::addToGroup(int groupId, int unitId) {
    TacticalAIGroup* grp = group(unitId, -1, -1, -1);
    if (!grp)
        return 0;
    return grp->addUnit(groupId, mainDecisionAI);
}
#else
int TribeTacticalAIModule::addToGroup(int, int) { return 0; }
#endif
