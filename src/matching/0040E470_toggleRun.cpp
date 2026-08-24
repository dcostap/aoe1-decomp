// toggleRun (0040E470, 20 bytes, aimodule.cpp)
// toggles runningValue: if (runningValue) runningValue = 0; else runningValue = 1;


#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModule {
public:
    virtual ~AIModule();
    unsigned char _pad[0x8C];
    int runningValue;  // +0x90
    void toggleRun();
};
#endif

void AIModule::toggleRun() {
    if (runningValue)
        runningValue = 0;
    else
        runningValue = 1;
}
