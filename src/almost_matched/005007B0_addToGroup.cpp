// STATUS: almost_matched
// CLASS: return-tail-merge
// RISK: low
// WHY: /Og merges two identical pop esi;ret 8 sequences into one shared return.
//      Original has jne body + early_ret + body + normal_ret (50B).
//      Compiled generates je end + body + shared_ret (48B, 46 code + 2 nop).
//      All calling convention, stack cleanup, and behavior are correct.
// NEXT: TU context compilation or /Og tail-merge workaround discovery.
// FLAGS: config\flags\005007B0_addToGroup.rsp

struct TacticalAIGroup {
    void addUnit(int groupId, int pMainAI);
};

struct TribeTacticalAIModule {
    char gap_0[0xF0];
    int mainDecisionAI;
    TacticalAIGroup* findOrCreateGroup(int unitId, int a, int b, int c);
    void addToGroup(int groupId, int unitId);
};

void TribeTacticalAIModule::addToGroup(int groupId, int unitId) {
    TacticalAIGroup* grp = findOrCreateGroup(unitId, -1, -1, -1);
    if (!grp)
        return;
    grp->addUnit(groupId, mainDecisionAI);
}
