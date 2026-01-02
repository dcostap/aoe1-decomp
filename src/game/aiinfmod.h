#pragma once
#include "../common.h"

class InformationAIModule : public AIModule {
public:

    InformationAIModule(void* param_1, int param_2);
    virtual ~InformationAIModule();
};

static_assert(sizeof(InformationAIModule) == 0xF0, "InformationAIModule Size Mismatch");

