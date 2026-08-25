#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    unsigned long storage_00;
    TacticalAIGroup* next;
    TacticalAIGroup* prev;
    int type() const;
    int numberUnits() const;
};

class TacticalAIModule {
public:
    char gap_00[0x9D4];
    TacticalAIGroup groups;
};

class TribeTacticalAIModule : public TacticalAIModule {
public:
    int numberUnitsInGroups(int type);
};

#endif
int TribeTacticalAIModule::numberUnitsInGroups(int type) {
    int total = 0;
    TacticalAIGroup* end = &this->groups;

    for (TacticalAIGroup* group = this->groups.next; group != end && group != 0; group = group->next) {
        if (type == -1 || group->type() == type) {
            total += group->numberUnits();
        }
    }
    return total;
}
