#ifndef TAITACMD_SHARED_CONTEXT
// 00500260 TribeTacticalAIModule::createGroup(int)
// Source: taitacmd.cpp lines 11261-11280
// FLAGS: /GX required for VC5 C++ new/constructor EH registration.
// Attempt log:
// - Replaced stub with real C++ `new TacticalAIGroup`, list insertion, optional
//   ID assignment, and group count increment.
// - Exact match: visible TacticalAIGroup size must be 0x330 so `new` emits the
//   original allocation size, and /GX supplies the constructor EH frame.

void* __cdecl operator new(unsigned int size);

#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    virtual void destroy(int flags);
    TacticalAIGroup* next;
    TacticalAIGroup* prev;
    char gap_0C[0x330 - 0x0C];

    TacticalAIGroup();
    void setID(int id);
};

class TribeTacticalAIModule {
public:
    char gap_000[0x9D4];
    char groups[0x330];
    int groupIDValue;
    int numberGroupsValue;

    TacticalAIGroup* createGroup(int assignID);
};

#endif
TacticalAIGroup* TribeTacticalAIModule::createGroup(int assignID)
{
    TacticalAIGroup* group;
    int id;

    group = new TacticalAIGroup;
    if (group == 0) {
        return 0;
    }
    group->next = (TacticalAIGroup*)this->groups;
    group->prev = ((TacticalAIGroup*)this->groups)->prev;
    group->prev->next = group;
    ((TacticalAIGroup*)this->groups)->prev = group;
    if (assignID == 1) {
        id = this->groupIDValue;
        this->groupIDValue = id + 1;
        group->setID(id);
        this->numberGroupsValue = this->numberGroupsValue + 1;
    }
    return group;
}
#else
TacticalAIGroup* TribeTacticalAIModule::createGroup(int assignID) {
    return 0;
}
#endif
