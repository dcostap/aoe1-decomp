#pragma once
#include "common.h"

class TribeConstructionAIModule : public ConstructionAIModule {
public:
    TribeMainDecisionAIModule* md;           // 0x314

    TribeConstructionAIModule(void* param_1, int param_2);
    TribeConstructionAIModule(int param_1, int param_2);
    ~TribeConstructionAIModule();
    void setMainDecisionAI(TribeMainDecisionAIModule* param_1);
    int canPlace(BuildItem* param_1);
    ConstructionItem* placeStructure(BuildItem* param_1, int param_2, PlacementState* param_3, ulong param_4);
    ConstructionItem* placeDock(BuildItem* param_1);
    void setBuilt(RGE_Static_Object* param_1, int param_2);
    ConstructionItem* compare(ConstructionItem* param_1, ConstructionItem* param_2);
};

static_assert(sizeof(TribeConstructionAIModule) == 0x318, "TribeConstructionAIModule Size Mismatch");

