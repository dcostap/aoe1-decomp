#ifndef AOE1_AIRESMOD_H
#define AOE1_AIRESMOD_H

#include "aimodule.h"
#include "airesitm.h"

class MainDecisionAIModule;

class ResourceAIModule : public AIModule {
public:
    ResourceAIModule(void* pW, int playerID, int n, int iV, int minV, int maxV);
    virtual ~ResourceAIModule();
    virtual int processMessage(AIModuleMessage* m);
    virtual int update(int timeLimit);
    virtual void setCallbackMessage(AIModuleMessage* m);
protected:
    virtual int filterOutMessage(AIModuleMessage* m);

public:
    MainDecisionAIModule* md;
    int numberResourcesValue;
    int* resourceValue;
    int* minValue;
    int* maxValue;
    int** resourceTypesValue;
    int* numberResourceTypesValue;

    void setMainDecisionAI(MainDecisionAIModule* m);
    int numberResources() const;
    int resource(int n) const;
    int resourcesAvailable(ResourceItem* ri);
    int unavailableResource(ResourceItem* ri);
    int minValueOfResource(int n) const;
    int maxValueOfResource(int n) const;
    void setResource(int n, int v);
    void setResources(ResourceItem* ri);
    void incrementResource(int n, int v);
    void incrementResources(ResourceItem* ri);
    void decrementResource(int n, int v);
    void decrementResources(ResourceItem* ri);
    void setResourceMin(int n, int v);
    void setResourceMax(int n, int v);
    void addResourceType(int r, int t);
    int isResourceType(int r, int t);
    int numberResourceTypes(int r);
    int lowestResourceType() const;
};

typedef char verify_airesmod_ResourceAIModule_size[
    sizeof(ResourceAIModule) == 0x10C ? 1 : -1];

#endif
