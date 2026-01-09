#pragma once
#include "common.h"

class TacticalAIModule : public AIModule {
public:

    TacticalAIModule(void* param_1, int param_2);
    ~TacticalAIModule();
};

static_assert(sizeof(TacticalAIModule) == 0xF0, "TacticalAIModule Size Mismatch");

