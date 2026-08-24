#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModuleID {
public:
    int id;
    char name[64];

    virtual ~AIModuleID();
};

class AIModule {
public:
    int purgeMessagesWithData(AIModuleID id, int type, int priority, long data);
};
#endif

int AIModule::purgeMessagesWithData(AIModuleID id, int type, int priority, long data) {
    return 0;
}
