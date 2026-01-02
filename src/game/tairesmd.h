#pragma once
#include "../common.h"

class TribeResourceAIModule : public AIModule {
public:
    TribeMainDecisionAIModule* md;           // 0xF0
    int numberResourcesValue;                // 0xF4

    TribeResourceAIModule(void* param_1, int param_2, int param_3, int param_4, int param_5, int param_6);
    TribeResourceAIModule(int param_1, int param_2);
    virtual ~TribeResourceAIModule();
    virtual void setMainDecisionAI(TribeMainDecisionAIModule* param_1);
    virtual int save(int param_1);
    virtual int numberResources();
    virtual int resource(int param_1);
    virtual int resourcesAvailable(ResourceItem* param_1);
    virtual int unavailableResource(ResourceItem* param_1);
    virtual char* resourceName(int param_1);
};

static_assert(sizeof(TribeResourceAIModule) == 0xF8, "TribeResourceAIModule Size Mismatch");
static_assert(offsetof(TribeResourceAIModule, numberResourcesValue) == 0xF4, "TribeResourceAIModule Offset Mismatch");

