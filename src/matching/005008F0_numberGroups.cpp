#ifndef TAITACMD_SHARED_CONTEXT
// attempt 1: sibling-style sentinel/null list walk with the two optional filters and a local count
// exact match landed with the natural filter order and the sentinel/list-node surface using the +4 next field

#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    int gap_00;
    TacticalAIGroup* next;

    int type() const;
    int action() const;
};

class TribeTacticalAIModule {
public:
    char gap_00[0x9D4];
    TacticalAIGroup groups;

    int numberGroups(int param_1, int param_2);
};

#endif
int TribeTacticalAIModule::numberGroups(int param_1, int param_2) {
    TacticalAIGroup* group = this->groups.next;
    TacticalAIGroup* sentinel = &this->groups;
    int count = 0;

    while (group != sentinel && group != 0) {
        if ((param_1 == -1 || group->type() == param_1) && (param_2 == -1 || group->action() == param_2)) {
            ++count;
        }
        group = group->next;
    }

    return count;
}
#else
int TribeTacticalAIModule::numberGroups(int param_1, int param_2) {
    return 0;
}
#endif
