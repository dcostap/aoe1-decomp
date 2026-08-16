class AIModuleID {
public:
    virtual ~AIModuleID();
    char data[0x44];
};

class AIModule {
public:
    int purgeCallbacks(AIModuleID p);
};

int AIModule::purgeCallbacks(AIModuleID p) {
    return 0;
}
