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

int AIModule::purgeMessagesWithPriorityBelow(AIModuleID p, int priority) {
    return 0;
}
