#pragma once
#include "../common.h"
#include "aimodule.h"
#include "aiconitm.h"
#include "aiblditm.h"

class ConstructionAIModule : public AIModule {
public:
    int numberConstructionLotsValue;         // 0xF0
    ConstructionItem constructionLots;       // 0xF4
    int numberRandomConstructionLotsValue;   // 0x174
    ConstructionItem randomConstructionLots; // 0x178
    char constructionPlanNameValue[257];     // 0x1F8
    float xReferencePointValue;              // 0x2FC
    float yReferencePointValue;              // 0x300
    float zReferencePointValue;              // 0x304
    int mapXSizeValue;                       // 0x308
    int mapYSizeValue;                       // 0x30C
    PlacementResult lastPlacementReturnCodeValue; // 0x310

    ConstructionAIModule(void* param_1, int param_2);
    ConstructionAIModule(int param_1, int param_2);
    virtual ~ConstructionAIModule();
    virtual int save(int param_1);
    virtual int loadConstructionPlan(char* param_1, int param_2, int param_3, float param_4, float param_5, float param_6);
    virtual char* constructionPlanName();
    virtual void setReferencePoint(int param_1, int param_2, float param_3, float param_4, float param_5);
    virtual float xReferencePoint();
    virtual float yReferencePoint();
    virtual ConstructionItem* placeStructure(BuildItem* param_1);
    virtual PlacementResult lastPlacementReturnCode();
    virtual void setBuilt(ConstructionItem* param_1, int param_2);
    virtual int unplaceStructure(ConstructionItem* param_1, int param_2);
    virtual int unplaceStructure(float param_1, float param_2, int param_3);
    virtual void decrementBuildAttempts(float param_1, float param_2, int param_3);
    virtual void incrementBuildAttempts(float param_1, float param_2, int param_3);
    virtual ConstructionItem* lot(float param_1, float param_2);
    virtual ConstructionItem* randomLot(float param_1, float param_2);
    virtual void removeOldLots();
};

static_assert(sizeof(ConstructionAIModule) == 0x314, "ConstructionAIModule Size Mismatch");
static_assert(offsetof(ConstructionAIModule, lastPlacementReturnCodeValue) == 0x310, "ConstructionAIModule Offset Mismatch");

