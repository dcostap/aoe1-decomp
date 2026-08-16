// VA: 0040E7E0 AIModule::purgeCallbacksWithData (14 bytes)
// The by-value AIModuleID is 0x48 bytes and has a direct virtual destructor.
// The remaining arguments are unused. Scope exit preserves AIModuleID cleanup.
// Exact check: 14/14 bytes with the original direct destructor target.

class AIModuleID {
public:
    int id;
    char name[64];
    virtual ~AIModuleID();
};

class AIModule {
public:
    int purgeCallbacksWithData(AIModuleID id, int type, int priority, long data);
};

int AIModule::purgeCallbacksWithData(AIModuleID id, int type, int priority, long data) {
    return 0;
}
