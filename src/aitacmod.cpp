#include "../include/aitacmod.h"

TacticalAIModule::TacticalAIModule(void* pW, int playerID)
    : AIModule("TacAI", 0x3F1, playerID, pW) {
}

// The derived destructor restores its vptr, then tail-jumps to
// AIModule::~AIModule through the real base-class ownership surface.
TacticalAIModule::~TacticalAIModule() {
}
