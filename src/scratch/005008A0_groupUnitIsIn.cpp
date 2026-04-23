// tried the direct sentinel-walk shape with a single group temp; VC5 still re-ordered the early test/load pair and the mismatch stayed at the first branch window
// tried removing the separate end temp and comparing against &this->groups inline; same result
// leaving in scratch because the remaining gap is source-shape/codegen ordering, not a behavior mismatch
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
    TacticalAIGroup* group;

    group = this->groups.next;
    if (group != &this->groups) {
        while (group != 0) {
            if (group->containsUnit(unit) == 1) {
                return group;
            }
            group = group->next;
            if (group == &this->groups) {
                return 0;
            }
        }
    }
    return 0;
}
