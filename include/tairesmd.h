#ifndef AOE1_TAIRESMD_H
#define AOE1_TAIRESMD_H

#include "aimodule.h"
#include "airesitm.h"

class TribeMainDecisionAIModule;

class TribeResourceAIModule : public AIModule {
  public:
    virtual ~TribeResourceAIModule();
    virtual int save(int outfile);

    TribeResourceAIModule(void* pW, int playerID, int n, int iV, int minV, int maxV);
    TribeResourceAIModule(int playerID, int infile);

    int numberResources() const;
    int resource(int n) const;
    char* resourceName(int i);
    int resourcesAvailable(ResourceItem* ri);
    void setMainDecisionAI(TribeMainDecisionAIModule* m);
    int unavailableResource(ResourceItem* ri);

    TribeMainDecisionAIModule* md;
    int numberResourcesValue;
};

typedef char verify_tairesmd_TribeResourceAIModule_size[sizeof(TribeResourceAIModule) == 0xF8 ? 1 : -1];

#endif
