class AIModuleID {
public:
    virtual ~AIModuleID();
    char data[0x44];
};

class AIModule {
public:
    int purgeMessages(AIModuleID p);
};

int AIModule::purgeMessages(AIModuleID p) { return 0; }
