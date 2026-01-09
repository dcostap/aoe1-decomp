#pragma once
#include "common.h"

class TribeResourceAIModule : public AIModule {
public:
    TribeMainDecisionAIModule* md;           // 0xF0
    int numberResourcesValue;                // 0xF4

    virtual int save(int param_1);                          // vt0[15]+0x3C=0x4E6C40
    TribeResourceAIModule(void* param_1, int param_2, int param_3, int param_4, int param_5, int param_6);
    TribeResourceAIModule(int param_1, int param_2);
    ~TribeResourceAIModule();
    void setMainDecisionAI(TribeMainDecisionAIModule* param_1);
    int numberResources();
    int resource(int param_1);
    int resourcesAvailable(ResourceItem* param_1);
    int unavailableResource(ResourceItem* param_1);
    char* resourceName(int param_1);
};

static_assert(sizeof(TribeResourceAIModule) == 0xF8, "TribeResourceAIModule Size Mismatch");

