#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModuleID {
public:
    virtual ~AIModuleID();
    char data[0x44];
};

class AIModule {
public:
    int purgeCallbacksWithID(AIModuleID p, int id);
};
#endif

int AIModule::purgeCallbacksWithID(AIModuleID p, int id) { return 0; }
