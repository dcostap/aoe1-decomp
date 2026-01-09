#pragma once
#include "common.h"

class TradeAIModule : public AIModule {
public:
    MainDecisionAIModule* md;                // 0xF0

    virtual int save(int param_1);                          // vt0[15]+0x3C=0x412EF0
    TradeAIModule(void* param_1, int param_2);
    TradeAIModule(int param_1, int param_2);
    ~TradeAIModule();
    void setMainDecisionAI(MainDecisionAIModule* param_1);
};

static_assert(sizeof(TradeAIModule) == 0xF4, "TradeAIModule Size Mismatch");

