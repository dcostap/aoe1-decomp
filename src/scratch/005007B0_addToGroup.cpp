struct TacticalAIGroup {
    char data[4];
};

struct TribeTacticalAIModule {
    char gap_0[4];
};

TacticalAIGroup* __fastcall findGroup(TribeTacticalAIModule*, int, int);
int __fastcall addUnit(TacticalAIGroup*, int, int);

int __fastcall addToGroup(TribeTacticalAIModule* self, int, int groupId, int unitId) {
    TacticalAIGroup* grp = findGroup(self, 0, groupId);
    if (!grp)
        return 0;
    return addUnit(grp, 0, unitId);
}
