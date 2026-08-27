// PDB source module: C:\\msdev\\work\\age1_x1\\aitacmod.cpp.
// The definitions below follow the original PDB source-line order.
// The vector-deleting destructor at 00412B80 is compiler generated.

#include "../include/aitacmod.h"

// PDB lines 24-26; VA 00412B50.
TacticalAIModule::TacticalAIModule(void* param1, int param2)
    : AIModule("TacAI", 0x3F1, param2, param1)
{
}

// PDB line 31; VA 00412BA0.
// BINARY NOTE: The derived destructor restores its vptr, then tail-jumps to
// AIModule::~AIModule through the real base-class ownership surface.
TacticalAIModule::~TacticalAIModule()
{
}
