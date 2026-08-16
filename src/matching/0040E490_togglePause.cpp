// togglePause (0040E490, 20 bytes, aimodule.cpp)
// toggles pausedValue: if (pausedValue) pausedValue = 0; else pausedValue = 1;
// Exact source recovery: pausedValue is a 32-bit member at +0x94.
class AIModule {
public:
    void* vtable;
    unsigned char _pad[0x8C];
    int runningValue;  // +0x90
    int pausedValue;   // +0x94
    void togglePause();
};

void AIModule::togglePause() {
    if (pausedValue)
        pausedValue = 0;
    else
        pausedValue = 1;
}
