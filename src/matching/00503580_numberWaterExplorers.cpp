// 00503580 TribeTacticalAIModule::numberWaterExplorers()
// Source: taitacmd.cpp lines 13317-13336
// Attempt log:
// - Replaced stub with Ghidra list walk and real direct member-call surface.

class TacticalAIGroup {
public:
    virtual void destroy(int flags);
    TacticalAIGroup* next;
    TacticalAIGroup* prev;

    int type();
    int action();
};

class TribeTacticalAIModule {
public:
    char gap_000[0x9D4];
    char groups[0x330];

    int numberWaterExplorers();
};

int TribeTacticalAIModule::numberWaterExplorers()
{
    TacticalAIGroup* group;
    TacticalAIGroup* sentinel;
    int count;

    count = 0;
    group = ((TacticalAIGroup*)this->groups)->next;
    sentinel = (TacticalAIGroup*)this->groups;
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
