#ifndef AOE1_AICONMOD_H
#define AOE1_AICONMOD_H

// Reviewed compiler-facing declarations for the aiconmod.cpp source module.
// BaseItem and AIModule are owned by their canonical headers.  This header
// owns only ConstructionItem and ConstructionAIModule.

#include "aibitm.h"
#include "aimodule.h"

class BuildItem;

class ConstructionItem : public BaseItem {
public:
    ConstructionItem* next;       // +0x6C
    ConstructionItem* prev;       // +0x70
    int inProgressValue;          // +0x74
    int builtValue;               // +0x78
    int buildAttemptsValue;       // +0x7C

    ConstructionItem();
    ConstructionItem(float x, float y, float z,
                     float xSize, float ySize, float zSize,
                     int typeID, char* name);
    virtual ~ConstructionItem();

    int inProgress();
    int built();
    int buildAttempts();
    void setInProgress(int value);
    void setBuilt(int value);
    void setBuildAttempts(int value);
    void decrementBuildAttempts();
    void incrementBuildAttempts();
};

class ConstructionAIModule : public AIModule {
public:
    enum PlacementResult {
        PlacementOk = 0
    };

    virtual ~ConstructionAIModule();
    virtual int save(int file);
    virtual int loadConstructionPlan(char* name, int mapX, int mapY,
                                     float xReference, float yReference,
                                     float zReference);
    virtual ConstructionItem* placeStructure(BuildItem* item);
    virtual void setBuilt(ConstructionItem* item, int built);
    virtual int unplaceStructure(ConstructionItem* item, int decrement);
    virtual int unplaceStructure(float x, float y, int decrement);
    virtual void decrementBuildAttempts(float x, float y, int count);
    virtual void incrementBuildAttempts(float x, float y, int count);

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

    ConstructionAIModule(void* parameter, int player);
    ConstructionAIModule(int player, int file);

    char* constructionPlanName();
    void setReferencePoint(int mapX, int mapY, float xReference,
                           float yReference, float zReference);
    float xReferencePoint();
    float yReferencePoint();
    PlacementResult lastPlacementReturnCode();
    ConstructionItem* lot(float x, float y);
    ConstructionItem* randomLot(float x, float y);

protected:
    void removeOldLots();
};

int __cdecl operator==(const ConstructionItem& left,
                       const ConstructionItem& right);

typedef char aiconmod_aimodule_size[(sizeof(AIModule) == 0xF0) ? 1 : -1];
typedef char aiconmod_base_item_size[(sizeof(BaseItem) == 0x6C) ? 1 : -1];
typedef char aiconmod_construction_item_size[(sizeof(ConstructionItem) == 0x80) ? 1 : -1];
typedef char aiconmod_module_size[(sizeof(ConstructionAIModule) == 0x314) ? 1 : -1];

#endif
