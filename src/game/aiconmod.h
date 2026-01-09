#pragma once
#include "common.h"


enum PlacementResult : unsigned int {
    PlacementOk = 0,
    PlacementOnImpassableTile = 1,
    PlacementObstructed = 2,
    PlacementUnknownObject = 3,
    PlacementFailed = 4,
    PlacementFailedNoLot = 5,
};


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

    virtual int save(int param_1);                          // vt0[15]+0x3C=0x40B1A0
    virtual int loadConstructionPlan(char* param_1, int param_2, int param_3, float param_4, float param_5, float param_6); // vt0[16]+0x40=0x40B690
    virtual ConstructionItem* placeStructure(BuildItem* param_1); // vt0[17]+0x44=0x40BB90
    virtual void setBuilt(ConstructionItem* param_1, int param_2); // vt0[18]+0x48=0x40BBB0
    virtual int unplaceStructure(float param_1, float param_2, int param_3); // vt0[19]+0x4C=0x40BC80
    virtual int unplaceStructure(ConstructionItem* param_1, int param_2); // vt0[20]+0x50=0x40BC00
    virtual void decrementBuildAttempts(float param_1, float param_2, int param_3); // vt0[21]+0x54=0x40BD10
    virtual void incrementBuildAttempts(float param_1, float param_2, int param_3); // vt0[22]+0x58=0x40BD40
    ConstructionAIModule(void* param_1, int param_2);
    ConstructionAIModule(int param_1, int param_2);
    ~ConstructionAIModule();
    char* constructionPlanName();
    void setReferencePoint(int param_1, int param_2, float param_3, float param_4, float param_5);
    float xReferencePoint();
    float yReferencePoint();
    PlacementResult lastPlacementReturnCode();
    ConstructionItem* lot(float param_1, float param_2);
    ConstructionItem* randomLot(float param_1, float param_2);
    void removeOldLots();
};

static_assert(sizeof(ConstructionAIModule) == 0x314, "ConstructionAIModule Size Mismatch");

