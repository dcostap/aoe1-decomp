// VA: 005008A0 TribeTacticalAIModule::groupUnitIsIn (71B)
// PDB source: taitacmd.cpp lines 11465-11473
// Probe 5: direct `while (group != end)` with an inner null guard.

class TacticalAIGroup {
public:
    void* vtable_ptr;
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
