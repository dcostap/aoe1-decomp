class TacticalAIGroup {
public:
    int removeUnit(int unit, int* md);
    int numberUnits() const;
    int id() const;
};

class TribeMainDecisionAIModule;

class TribeTacticalAIModule {
public:
    char gap_00[0xF0];
    TribeMainDecisionAIModule* md;

    TacticalAIGroup* groupUnitIsIn(int unit);
    void removeGroup(int id);
    int removeFromGroup(int unit);
};

int TribeTacticalAIModule::removeFromGroup(int unit) {
    TacticalAIGroup* group;
    int result;

    group = this->groupUnitIsIn(unit);
    if (group == 0) {
        return 0;
    }
    result = group->removeUnit(unit, (int*)this->md);
    if (group->numberUnits() == 0) {
        this->removeGroup(group->id());
    }
    return result;
}
