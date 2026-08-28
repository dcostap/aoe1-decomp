#ifndef AOE1_AIRESMOD_H
#define AOE1_AIRESMOD_H

#include "aimodule.h"
#include "airesitm.h"

class MainDecisionAIModule;

class ResourceAIModule : public AIModule {
public:
    ResourceAIModule(void* owner, int player, int resourceCount,
                     int initialValue, int minimumValue, int maximumValue);
    virtual ~ResourceAIModule();
    virtual int processMessage(AIModuleMessage*);
    virtual int update(int);
    virtual void setCallbackMessage(AIModuleMessage*);
protected:
    virtual int filterOutMessage(AIModuleMessage*);

public:
    MainDecisionAIModule* md;
    int numberResourcesValue;
    int* resourceValue;
    int* minValue;
    int* maxValue;
    int** resourceTypesValue;
    int* numberResourceTypesValue;

    void setMainDecisionAI(MainDecisionAIModule* decisionAI);
    int numberResources() const;
    int resource(int) const;
    int resourcesAvailable(ResourceItem*);
    int unavailableResource(ResourceItem*);
    int minValueOfResource(int) const;
    int maxValueOfResource(int) const;
    void setResource(int, int);
    void setResources(ResourceItem*);
    void incrementResource(int, int);
    void incrementResources(ResourceItem*);
    void decrementResource(int, int);
    void decrementResources(ResourceItem*);
    void setResourceMin(int, int);
    void setResourceMax(int, int);
    void addResourceType(int resourceIndex, int type);
    int isResourceType(int resourceIndex, int type);
    int numberResourceTypes(int resourceIndex);
    int lowestResourceType() const;
};

typedef char verify_airesmod_ResourceAIModule_size[
    sizeof(ResourceAIModule) == 0x10C ? 1 : -1];

#endif
