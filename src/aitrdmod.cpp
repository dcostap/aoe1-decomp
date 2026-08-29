
#include "../include/aitrdmod.h"

TradeAIModule::TradeAIModule(void* ptr, int player)
    : AIModule("Trade AI", 0x3F2, player, ptr),
      md(0)
{
}

TradeAIModule::TradeAIModule(int player, int unused)
    : AIModule("Trade AI", 0x3F2, player, 0),
      md(0)
{
}

TradeAIModule::~TradeAIModule()
{
}

void TradeAIModule::setMainDecisionAI(MainDecisionAIModule* module)
{
    this->md = module;
}

int TradeAIModule::save(int unused)
{
    return 1;
}
