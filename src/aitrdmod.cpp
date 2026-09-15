
#include "../include/aitrdmod.h"

TradeAIModule::TradeAIModule(void* pW, int playerID)
    : AIModule("Trade AI", 0x3F2, playerID, pW),
      md(0) {
}

TradeAIModule::TradeAIModule(int playerID, int infile)
    : AIModule("Trade AI", 0x3F2, playerID, 0),
      md(0) {
}

TradeAIModule::~TradeAIModule() {
}

void TradeAIModule::setMainDecisionAI(MainDecisionAIModule* m) {
    this->md = m;
}

int TradeAIModule::save(int outfile) {
    return 1;
}
