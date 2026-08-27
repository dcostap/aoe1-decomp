// PDB source module: C:\\msdev\\work\\age1_x1\\aitrdmod.cpp.
// Definitions follow the original PDB source order.

#include "../include/aitrdmod.h"

// PDB lines 23-24; VA 00412E40.
TradeAIModule::TradeAIModule(void* ptr, int player)
    : AIModule("Trade AI", 0x3F2, player, ptr),
      md(0)
{
}

// PDB lines 31-32; VA 00412EA0.
TradeAIModule::TradeAIModule(int player, int unused)
    : AIModule("Trade AI", 0x3F2, player, 0),
      md(0)
{
}

// PDB line 37; VA 00412ED0.
TradeAIModule::~TradeAIModule()
{
}

// PDB lines 43-45; VA 00412EE0.
void TradeAIModule::setMainDecisionAI(MainDecisionAIModule* module)
{
    this->md = module;
}

// PDB lines 50-52; VA 00412EF0.
int TradeAIModule::save(int unused)
{
    return 1;
}
