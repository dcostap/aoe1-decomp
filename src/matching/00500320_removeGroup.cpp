// VA: 00500320 TribeTacticalAIModule::removeGroup
// MATCHED: use a natural `for (group = next; group != sentinel; group = group->next)` loop
// with an inner `if (group == 0) break;` before the id check. This makes VC5 place
// the sentinel compare at the bottom and jump back to a loop top that begins with
// the null test, matching the original layout.

class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    TacticalAIGroup* next;
    TacticalAIGroup* prev;

    int id();
};

class TribeTacticalAIModule {
public:
    char gap_000[0x9D4];
    TacticalAIGroup groups;
    char gap_9E0[0x328];
    int numberGroups;

    int removeGroup(int id);
};

int TribeTacticalAIModule::removeGroup(int id) {
    TacticalAIGroup* sentinel = &this->groups;
    int targetId = id;
    for (TacticalAIGroup* group = this->groups.next; group != sentinel; group = group->next) {
        if (group == 0) {
            break;
        }
        if (group->id() == targetId) {
            group->prev->next = group->next;
            group->next->prev = group->prev;
            if (group != 0) {
                delete group;
            }
            this->numberGroups--;
            return 1;
        }
    }
    return 0;
}
