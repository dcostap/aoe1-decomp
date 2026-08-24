// togglePause (0040E490, 20 bytes, aimodule.cpp)
// toggles pausedValue: if (pausedValue) pausedValue = 0; else pausedValue = 1;
// Exact source recovery: pausedValue is a 32-bit member at +0x94.
#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModule {
public:
    virtual ~AIModule();
    unsigned char _pad[0x8C];
    int runningValue;  // +0x90
    int pausedValue;   // +0x94
    void togglePause();
};
#endif

void AIModule::togglePause() {
    if (pausedValue)
        pausedValue = 0;
    else
        pausedValue = 1;
}
