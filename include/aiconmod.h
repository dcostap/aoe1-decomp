#ifndef AOE1_AICONMOD_H
#define AOE1_AICONMOD_H

#include "aiconitm.h"
#include "aimodule.h"

class BuildItem;

class ConstructionAIModule : public AIModule {
public:
    enum PlacementResult {
        PlacementOk = 0,
        PlacementFailed = 5
    };

    virtual ~ConstructionAIModule();
    virtual int save(int outfile);
    virtual int loadConstructionPlan(char* pName, int mXSize, int mYSize, float xRef, float yRef, float zRef);
    virtual ConstructionItem* placeStructure(BuildItem* bi);
    virtual void setBuilt(ConstructionItem* ci, int v);
    virtual int unplaceStructure(ConstructionItem* ci, int decBA);
    virtual int unplaceStructure(float x, float y, int decBA);
    virtual void decrementBuildAttempts(float x, float y, int n);
    virtual void incrementBuildAttempts(float x, float y, int n);

    int numberConstructionLotsValue;             // +0xF0
    ConstructionItem constructionLots;           // +0xF4
    int numberRandomConstructionLotsValue;       // +0x174
    ConstructionItem randomConstructionLots;     // +0x178
    char constructionPlanNameValue[257];        // +0x1F8
    float xReferencePointValue;                  // +0x2FC (natural alignment)
    float yReferencePointValue;                  // +0x300
    float zReferencePointValue;                  // +0x304
    int mapXSizeValue;                            // +0x308
    int mapYSizeValue;                            // +0x30C
    PlacementResult lastPlacementReturnCodeValue; // +0x310

    ConstructionAIModule(void* pW, int playerID);
    ConstructionAIModule(int playerID, int infile);

    char* constructionPlanName();
    void setReferencePoint(int mXSize, int mYSize, float x, float y, float z);
    float xReferencePoint();
    float yReferencePoint();
    PlacementResult lastPlacementReturnCode();
    ConstructionItem* lot(float x, float y);
    ConstructionItem* randomLot(float x, float y);

protected:
    void removeOldLots();
};

int __cdecl operator==(const ConstructionItem& one, const ConstructionItem& two);

typedef char aiconmod_aimodule_size[(sizeof(AIModule) == 0xF0) ? 1 : -1];
typedef char aiconmod_base_item_size[(sizeof(BaseItem) == 0x6C) ? 1 : -1];
typedef char aiconmod_construction_item_size[(sizeof(ConstructionItem) == 0x80) ? 1 : -1];
typedef char aiconmod_module_size[(sizeof(ConstructionAIModule) == 0x314) ? 1 : -1];

#endif
