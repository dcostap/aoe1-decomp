// The vector-deleting destructor at 00412B80 is compiler generated.

#include "../include/aitacmod.h"

TacticalAIModule::TacticalAIModule(void* param1, int param2)
    : AIModule("TacAI", 0x3F1, param2, param1)
{
}

// The derived destructor restores its vptr, then tail-jumps to
// AIModule::~AIModule through the real base-class ownership surface.
TacticalAIModule::~TacticalAIModule()
{
}
