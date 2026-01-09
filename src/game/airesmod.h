#pragma once
#include "common.h"

class ResourceAIModule : public AIModule {
public:
    MainDecisionAIModule* md;                // 0xF0
    int numberResourcesValue;                // 0xF4
    int* resourceValue;                      // 0xF8
    int* minValue;                           // 0xFC
    int* maxValue;                           // 0x100
    int** resourceTypesValue;                // 0x104
    int* numberResourceTypesValue;           // 0x108

    virtual int processMessage(AIModuleMessage* param_1);   // vt0[11]+0x2C=0x412540
    virtual int update(int param_1);                        // vt0[12]+0x30=0x412550
    virtual void setCallbackMessage(AIModuleMessage* param_1); // vt0[13]+0x34=0x412560
    virtual int filterOutMessage(AIModuleMessage* param_1); // vt0[14]+0x38=0x412960
    ResourceAIModule(void* param_1, int param_2, int param_3, int param_4, int param_5, int param_6);
    ~ResourceAIModule();
    void setMainDecisionAI(MainDecisionAIModule* param_1);
    int numberResources();
    int resource(int param_1);
    int resourcesAvailable(ResourceItem* param_1);
    int unavailableResource(ResourceItem* param_1);
    int minValueOfResource(int param_1);
    int maxValueOfResource(int param_1);
    void setResource(int param_1, int param_2);
    void setResources(ResourceItem* param_1);
    void incrementResource(int param_1, int param_2);
    void incrementResources(ResourceItem* param_1);
    void decrementResource(int param_1, int param_2);
    void decrementResources(ResourceItem* param_1);
    void setResourceMin(int param_1, int param_2);
    void setResourceMax(int param_1, int param_2);
    void addResourceType(int param_1, int param_2);
    int isResourceType(int param_1, int param_2);
    int numberResourceTypes(int param_1);
    int lowestResourceType();
};

static_assert(sizeof(ResourceAIModule) == 0x10C, "ResourceAIModule Size Mismatch");

