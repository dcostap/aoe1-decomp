#ifndef AOE1_TAIRESMD_H
#define AOE1_TAIRESMD_H

#include "aimodule.h"
#include "airesitm.h"

// Authentic declaration surface for C:\\msdev\\work\\age1_x1\\tairesmd.cpp.
// The module contains two TribeResourceAIModule constructors and its virtual
// destructor before the remaining helpers.

class ResourceTable {
public:
    char gap_00[0x50];
    float* values;
};

class TribeMainDecisionAIModule {
public:
    char gap_00[0xF0];
    ResourceTable* player;
};

class TribeResourceAIModule : public AIModule {
public:
    virtual ~TribeResourceAIModule();
    virtual int save(int);

    TribeResourceAIModule(void*, int, int, int, int, int);
    TribeResourceAIModule(int, int);

    int numberResources() const;
    int resource(int) const;
    char* resourceName(int);
    int resourcesAvailable(ResourceItem*);
    void setMainDecisionAI(TribeMainDecisionAIModule*);
    int unavailableResource(ResourceItem*);

    TribeMainDecisionAIModule* md;
    int numberResourcesValue;
};

typedef char verify_tairesmd_TribeResourceAIModule_size[
    sizeof(TribeResourceAIModule) == 0xF8 ? 1 : -1];

#endif
