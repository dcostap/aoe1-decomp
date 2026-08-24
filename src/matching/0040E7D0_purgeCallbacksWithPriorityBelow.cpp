// VA: 0040E7D0 AIModule::purgeCallbacksWithPriorityBelow (14 bytes)
// The by-value AIModuleID is 0x48 bytes and has a direct virtual destructor.
// The priority argument is unused. Scope exit preserves AIModuleID cleanup.
// Exact check: 14/14 bytes with the original direct destructor target.

#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModuleID {
public:
    int id;
    char name[64];
    virtual ~AIModuleID();
};

class AIModule {
public:
    int purgeCallbacksWithPriorityBelow(AIModuleID p, int priority);
};
#endif

int AIModule::purgeCallbacksWithPriorityBelow(AIModuleID p, int priority) {
    return 0;
}
