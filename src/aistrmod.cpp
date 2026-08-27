// Authentic PDB-ordered source module for C:\\msdev\\work\\age1_x1\\aistrmod.cpp.
// The two normal owners follow the source-line and shipped-address order.
// The vector-deleting destructor at 00412B20 is compiler generated.

#include "../include/aistrmod.h"

// PDB lines 22-24; VA 00412AF0.
StrategyAIModule::StrategyAIModule(void* param1, int param2)
    : AIModule("Strategy AI", 0x3F0, param2, param1)
{
}

// PDB line 29; VA 00412B40.
// BINARY NOTE: The derived destructor restores its vptr, then tail-jumps to
// AIModule::~AIModule through the real base-class ownership surface.
StrategyAIModule::~StrategyAIModule()
{
}
