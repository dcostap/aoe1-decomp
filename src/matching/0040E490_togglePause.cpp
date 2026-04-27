// togglePause (0040E490, 20 bytes, aimodule.cpp)
// toggles pausedValue: if (pausedValue) pausedValue = 0; else pausedValue = 1;
#include "game_globals.h"
#include "game_types.h"

class AIModule {
public:
    void* vtable;
    unsigned char _pad[0x8C];
    int runningValue;  // +0x90
    int pausedValue;   // +0x94
};

void AIModule::togglePause() {
    if (pausedValue)
        pausedValue = 0;
    else
        pausedValue = 1;
}
