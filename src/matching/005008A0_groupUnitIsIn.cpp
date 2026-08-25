#ifndef TAITACMD_SHARED_CONTEXT
// VA: 005008A0 TribeTacticalAIModule::groupUnitIsIn (71B)
// PDB source: taitacmd.cpp lines 11465-11473
// Probe 5: direct `while (group != end)` with an inner null guard.

#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    unsigned long storage_00;
    TacticalAIGroup* next;
    TacticalAIGroup* prev;
    int idValue;
    int inUseValue;
    int typeValue;
    int subTypeValue;

    int containsUnit(int unit);
};

class TacticalAIModule {
public:
    char gap_00[0x9D4];
};

class TribeTacticalAIModule : public TacticalAIModule {
public:
    TacticalAIGroup groups;

    TacticalAIGroup* groupUnitIsIn(int unit);
};

#endif
TacticalAIGroup* TribeTacticalAIModule::groupUnitIsIn(int unit) {
    TacticalAIGroup* group = this->groups.next;
    TacticalAIGroup* end = &this->groups;

    while (group != end) {
        if (group == 0) {
            return 0;
        }
        if (group->containsUnit(unit) == 1) {
            return group;
        }
        group = group->next;
    }

    return 0;
}
#else
TacticalAIGroup* TribeTacticalAIModule::groupUnitIsIn(int unit) {
    return 0;
}
#endif
