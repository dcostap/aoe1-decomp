// 00500420 TribeTacticalAIModule::group(int,int,int,int)
// Source: taitacmd.cpp lines 11331-11342
// Attempt log:
// - Replaced stub with full group-list filter logic and direct member calls.
// - Exact match: keep target/action/type as locals loaded in that order and use
//   explicit top null/bottom sentinel breaks for the list walk.

class TacticalAIGroup {
public:
    virtual void destroy(int flags);
    TacticalAIGroup* next;
    TacticalAIGroup* prev;

    int id();
    int type();
    int action();
    int target();
};

class TribeTacticalAIModule {
public:
    char gap_000[0x9D4];
    char groups[0x330];

    TacticalAIGroup* group(int id, int type, int action, int target);
};

TacticalAIGroup* TribeTacticalAIModule::group(int id, int type, int action, int target)
{
    TacticalAIGroup* group;
    TacticalAIGroup* sentinel;
    int wantType;
    int wantAction;
    int wantTarget;

    group = ((TacticalAIGroup*)this->groups)->next;
    sentinel = (TacticalAIGroup*)this->groups;
    if (group != sentinel) {
        wantTarget = target;
        wantAction = action;
        wantType = type;
        while (1) {
            if (group == 0) {
                break;
            }
            if (id == -1 || group->id() == id) {
                if (wantType == -1 || group->type() == wantType) {
                    if (wantAction == -1 || group->action() == wantAction) {
                        if (wantTarget == -1 || group->target() == wantTarget) {
                            return group;
                        }
                    }
                }
            }
            group = group->next;
            if (group == sentinel) {
                return 0;
            }
        }
    }
    return 0;
}
