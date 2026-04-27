// toggleRun (0040E470, 20 bytes, aimodule.cpp)
// toggles runningValue: if (runningValue) runningValue = 0; else runningValue = 1;
#include "game_globals.h"
#include "game_types.h"

class AIModule {
public:
    void* vtable;
    unsigned char _pad[0x8C];
    int runningValue;  // +0x90
};

void AIModule::toggleRun() {
    if (runningValue)
        runningValue = 0;
    else
        runningValue = 1;
}
