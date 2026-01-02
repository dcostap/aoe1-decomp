#pragma once
#include "../common.h"

class StrategyAIModule : public AIModule {
public:

    StrategyAIModule(void* param_1, int param_2);
    virtual ~StrategyAIModule();
};

static_assert(sizeof(StrategyAIModule) == 0xF0, "StrategyAIModule Size Mismatch");

