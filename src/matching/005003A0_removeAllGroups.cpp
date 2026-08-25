#ifndef TAITACMD_SHARED_CONTEXT
// 005003A0 TribeTacticalAIModule::removeAllGroups(int)
// Source: taitacmd.cpp lines 11309-11325
// Attempt log:
// - Replaced stub with Ghidra list-removal logic and vtable-slot-0
//   deleting-destructor dispatch via a normal virtual member (`destroy(1)`).
// - Exact match: source must be `while (1)` with explicit top null break and
//   explicit bottom sentinel break. A `while (group != 0)`/do-while condition
//   makes VC5 add a bottom null test and shifts the epilogue.

#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    virtual void destroy(int flags);
    TacticalAIGroup* next;
    TacticalAIGroup* prev;

    int type();
};

class TribeTacticalAIModule {
public:
    char gap_000[0x9D4];
    char groups[0x330];
    int groupIDValue;
    int numberGroupsValue;

    int removeAllGroups(int type);
};

#endif
int TribeTacticalAIModule::removeAllGroups(int type)
{
    int wanted;
    int groupType;
    TacticalAIGroup* group;
    TacticalAIGroup* sentinel;
    TacticalAIGroup* prev;

    group = ((TacticalAIGroup*)this->groups)->next;
    sentinel = (TacticalAIGroup*)this->groups;
    if (group != sentinel) {
        wanted = type;
        while (1) {
            if (group == 0) {
                break;
            }
            groupType = group->type();
            if (groupType == wanted || wanted == -1) {
                group->prev->next = group->next;
                group->next->prev = group->prev;
                prev = group->prev;
                group->destroy(1);
                group = prev;
                this->numberGroupsValue = this->numberGroupsValue - 1;
            }
            group = group->next;
            sentinel = (TacticalAIGroup*)this->groups;
            if (group == sentinel) {
                break;
            }
        }
    }
    return 1;
}
#else
int TribeTacticalAIModule::removeAllGroups(int type) {
    return 0;
}
#endif
