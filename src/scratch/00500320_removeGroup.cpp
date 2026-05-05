// VA: 00500320 TribeTacticalAIModule::removeGroup
// left in scratch: behavior and unlink/delete/count decrement modeled.
// Close edit diff (11 bytes) but VC5 places the post-next null test inline (`cmp sentinel; je fail; test; jne id`)
// instead of original `cmp sentinel; jne loop_top` where loop_top begins with the null test. Tried while/do/goto and
// volatile id load to recover EBX timing; branch layout remains shifted.

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
    TacticalAIGroup* group = this->groups.next;
    TacticalAIGroup* sentinel = &this->groups;
    if (group != sentinel) {
        int targetId = *(volatile int*)&id;
        while (group != 0) {
            if (group->id() == targetId) {
                group->prev->next = group->next;
                group->next->prev = group->prev;
                if (group != 0) {
                    delete group;
                }
                this->numberGroups--;
                return 1;
            }
            group = group->next;
            if (group == sentinel) {
                return 0;
            }
        }
    }
    return 0;
}
