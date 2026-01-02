#pragma once
#include "../common.h"

class ResourceAIModule : public AIModule {
public:
    MainDecisionAIModule* md;                // 0xF0
    int numberResourcesValue;                // 0xF4
    int* resourceValue;                      // 0xF8
    int* minValue;                           // 0xFC
    int* maxValue;                           // 0x100
    int** resourceTypesValue;                // 0x104
    int* numberResourceTypesValue;           // 0x108

    ResourceAIModule(void* param_1, int param_2, int param_3, int param_4, int param_5, int param_6);
    virtual ~ResourceAIModule();
    virtual int processMessage(AIModuleMessage* param_1);
    virtual int update(int param_1);
    virtual void setCallbackMessage(AIModuleMessage* param_1);
    virtual void setMainDecisionAI(MainDecisionAIModule* param_1);
    virtual int numberResources();
    virtual int resource(int param_1);
    virtual int resourcesAvailable(ResourceItem* param_1);
    virtual int unavailableResource(ResourceItem* param_1);
    virtual int minValueOfResource(int param_1);
    virtual int maxValueOfResource(int param_1);
    virtual void setResource(int param_1, int param_2);
    virtual void setResources(ResourceItem* param_1);
    virtual void incrementResource(int param_1, int param_2);
    virtual void incrementResources(ResourceItem* param_1);
    virtual void decrementResource(int param_1, int param_2);
    virtual void decrementResources(ResourceItem* param_1);
    virtual void setResourceMin(int param_1, int param_2);
    virtual void setResourceMax(int param_1, int param_2);
    virtual int filterOutMessage(AIModuleMessage* param_1);
    virtual void addResourceType(int param_1, int param_2);
    virtual int isResourceType(int param_1, int param_2);
    virtual int numberResourceTypes(int param_1);
    virtual int lowestResourceType();
};

static_assert(sizeof(ResourceAIModule) == 0x10C, "ResourceAIModule Size Mismatch");
static_assert(offsetof(ResourceAIModule, numberResourceTypesValue) == 0x108, "ResourceAIModule Offset Mismatch");

