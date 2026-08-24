#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModuleID {
public:
    int id;
    char name[64];
    virtual ~AIModuleID();
};

class AIModule {
public:
    int purgeMessagesWithPriorityBelow(AIModuleID p, int priority);
};
#endif

int AIModule::purgeMessagesWithPriorityBelow(AIModuleID p, int priority) {
    return 0;
}
