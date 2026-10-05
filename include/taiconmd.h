#ifndef AOE1_TAICONMD_H
#define AOE1_TAICONMD_H

#include "aiconmod.h"

class TribeMainDecisionAIModule;
class RGE_Static_Object;
struct PlacementState;

class TribeConstructionAIModule : public ConstructionAIModule {
  public:
    TribeConstructionAIModule(void* pW, int pID);
    TribeConstructionAIModule(int pID, int infile);
    virtual ~TribeConstructionAIModule();

    void setMainDecisionAI(TribeMainDecisionAIModule* m);
    int canPlace(BuildItem* bi);
    ConstructionItem* placeStructure(
        BuildItem* bi, int builder, PlacementState& placementState, unsigned long startTime
    );
    ConstructionItem* placeDock(BuildItem* bi);
    void setBuilt(RGE_Static_Object* bo, int v);

  protected:
    ConstructionItem* compare(ConstructionItem* one, ConstructionItem* two);

  public:
    TribeMainDecisionAIModule* md;
};

typedef char taiconmd_tribe_construction_size[(sizeof(TribeConstructionAIModule) == 0x318) ? 1 : -1];

#endif
