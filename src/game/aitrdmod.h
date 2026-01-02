#pragma once
#include "../common.h"

class TradeAIModule : public AIModule {
public:
    MainDecisionAIModule* md;                // 0xF0

    TradeAIModule(void* param_1, int param_2);
    TradeAIModule(int param_1, int param_2);
    virtual ~TradeAIModule();
    virtual void setMainDecisionAI(MainDecisionAIModule* param_1);
    virtual int save(int param_1);
};

static_assert(sizeof(TradeAIModule) == 0xF4, "TradeAIModule Size Mismatch");
static_assert(offsetof(TradeAIModule, md) == 0xF0, "TradeAIModule Offset Mismatch");

