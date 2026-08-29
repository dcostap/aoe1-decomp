
#include "../include/aistrmod.h"

StrategyAIModule::StrategyAIModule(void* param1, int param2)
    : AIModule("Strategy AI", 0x3F0, param2, param1)
{
}

// The derived destructor restores its vptr, then tail-jumps to
// AIModule::~AIModule through the real base-class ownership surface.
StrategyAIModule::~StrategyAIModule()
{
}
