// 00503580 TribeTacticalAIModule::numberWaterExplorers()
// Source: taitacmd.cpp lines 13317-13336
// Attempt log:
// - Replaced stub with Ghidra list walk and real direct member-call surface.

#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    TacticalAIGroup* next;
    TacticalAIGroup* prev;

    int type();
    int action();
};

class TribeTacticalAIModule {
public:
    char gap_000[0x9D4];
    TacticalAIGroup groups;

    int numberWaterExplorers();
};

#endif
int TribeTacticalAIModule::numberWaterExplorers()
{
    TacticalAIGroup* group;
    TacticalAIGroup* sentinel;
    int count;

    count = 0;
    group = this->groups.next;
    sentinel = &this->groups;
    while (group != sentinel && group != 0) {
        if ((group->type() == 0x67 || group->type() == 0x68 ||
             group->type() == 0x69 || group->type() == 0x6a ||
             group->type() == 0x6b || group->type() == 0x6c) &&
            group->action() == 8) {
            count = count + 1;
        }
        group = group->next;
    }
    return count;
}
