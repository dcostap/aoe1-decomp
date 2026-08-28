#ifndef AOE1_TAICONMD_H
#define AOE1_TAICONMD_H

#include "aiconmod.h"

class TribeMainDecisionAIModule;
struct PlacementState;

class TribeConstructionAIModule : public ConstructionAIModule {
public:
    TribeConstructionAIModule(void*, int);
    TribeConstructionAIModule(int, int);
    virtual ~TribeConstructionAIModule();

    void setMainDecisionAI(TribeMainDecisionAIModule* value);
    int canPlace(BuildItem* item);
    ConstructionItem* placeStructure(BuildItem* item, int builder_id,
                                     PlacementState& state,
                                     unsigned long time);
    ConstructionItem* placeDock(BuildItem* item);
    void setBuilt(RGE_Static_Object* object, int built);

protected:
    ConstructionItem* compare(ConstructionItem* left,
                              ConstructionItem* right);

public:
    TribeMainDecisionAIModule* md;
};

typedef char taiconmd_tribe_construction_size[
    (sizeof(TribeConstructionAIModule) == 0x318) ? 1 : -1];

#endif
