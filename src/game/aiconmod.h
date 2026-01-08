#pragma once
#include "../common.h"
#include "aimodule.h"
#include "aiconitm.h"
#include "aiblditm.h"

enum PlacementResult : unsigned int {
    PlacementOk = 0,
    PlacementOnImpassableTile = 1,
    PlacementObstructed = 2,
    PlacementUnknownObject = 3,
    PlacementFailed = 4,
    PlacementFailedNoLot = 5,
};

class ConstructionAIModule : public AIModule       {
public:
    char _pad_0x4[0xEC];
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

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~ConstructionAIModule() noexcept(false); // Ghidra: `scalar_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void loggingHistory();

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void setLogHistory();

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void toggleLogHistory();

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void setHistoryFilename();

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void loggingCommonHistory();

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void setLogCommonHistory();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void toggleLogCommonHistory();

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void loadState();

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void saveState();

    // [Slot 10] Offset 0x28 WARNING: Function body missing in analysis
    // virtual void gleanState();

    // [Slot 11] Offset 0x2C WARNING: Function body missing in analysis
    // virtual void processMessage();

    // [Slot 12] Offset 0x30 WARNING: Function body missing in analysis
    // virtual void update();

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void setCallbackMessage();

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void filterOutMessage();

    // [Slot 15] Offset 0x3C (Override)
    virtual int save(int param_1); // Ghidra: save

    // [Slot 16] Offset 0x40 (Override)
    virtual int loadConstructionPlan(char* param_1, int param_2, int param_3, float param_4, float param_5, float param_6); // Ghidra: loadConstructionPlan

    // [Slot 17] Offset 0x44 (Override)
    virtual ConstructionItem* placeStructure(BuildItem* param_1); // Ghidra: placeStructure

    // [Slot 18] Offset 0x48 (Override)
    virtual void setBuilt(ConstructionItem* param_1, int param_2); // Ghidra: setBuilt

    // [Slot 19] Offset 0x4C (Override)
    virtual int unplaceStructure(float param_1, float param_2, int param_3); // Ghidra: unplaceStructure

    // [Slot 20] Offset 0x50 (Override)
    virtual int unplaceStructure(ConstructionItem* param_1, int param_2); // Ghidra: unplaceStructure

    // [Slot 21] Offset 0x54 (Override)
    virtual void decrementBuildAttempts(float param_1, float param_2, int param_3); // Ghidra: decrementBuildAttempts

    // [Slot 22] Offset 0x58 (Override)
    virtual void incrementBuildAttempts(float param_1, float param_2, int param_3); // Ghidra: incrementBuildAttempts

    // --- Non-Virtual Members ---
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
static_assert(offsetof(ConstructionAIModule, lastPlacementReturnCodeValue) == 0x310, "ConstructionAIModule Offset Mismatch");

