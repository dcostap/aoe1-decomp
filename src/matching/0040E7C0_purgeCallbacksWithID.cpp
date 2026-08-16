class AIModuleID {
public:
    virtual ~AIModuleID();
    char data[0x44];
};

class AIModule {
public:
    int purgeCallbacksWithID(AIModuleID p, int id);
};

int AIModule::purgeCallbacksWithID(AIModuleID p, int id) { return 0; }
