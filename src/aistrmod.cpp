
#include "../include/aistrmod.h"

StrategyAIModule::StrategyAIModule(void* pW, int playerID) : AIModule("Strategy AI", 0x3F0, playerID, pW) {
}

// The derived destructor restores its vptr, then tail-jumps to
// AIModule::~AIModule through the real base-class ownership surface.
StrategyAIModule::~StrategyAIModule() {
}
