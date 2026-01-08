#pragma once
#include "../common.h"
#include "aibitm.h"

// ----------------------------------------------------------------
// PlacementState
// Sizeñ: 0x130
struct PlacementState {
    int buildingTypeID; // 0x0
    float buildingSize; // 0x4
    char buildingName[256]; // 0x8
    int builderID; // 0x108
    int minimumDistance; // 0x10C
    int maximumDistance; // 0x110
    int active; // 0x114
    XYPoint bestPoint; // 0x118
    int bestPointValue; // 0x120
    int iterationX; // 0x124
    int randomInfluence; // 0x128
    BuildItem * buildItem; // 0x12C
};

class BuildItem : public BaseItem       {
public:
    char _pad_0x4[0x68];
    BuildItem* next;                         // 0x6C
    BuildItem* prev;                         // 0x70
    int buildCategoryValue;                  // 0x74
    int numberValue;                         // 0x78
    int priorityValue;                       // 0x7C
    int progressValue;                       // 0x80
    int builtValue;                          // 0x84
    int buildAttemptsValue;                  // 0x88
    int buildFromValue;                      // 0x8C
    int terrainSetValue;                     // 0x90
    int terrainAdjacencyValue[2];            // 0x94
    int placeOnElevationValue;               // 0x9C
    int numberBuildsValue;                   // 0xA0
    int buildCapValue;                       // 0xA4
    int skipCyclesValue;                     // 0xA8
    uchar permanentSkipValue;                // 0xAC

    BuildItem();
    BuildItem(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, char* param_7, float param_8, float param_9, float param_10, int param_11, int param_12, int param_13, int param_14);
    BuildItem(BuildItem* param_1);
    BuildItem(BuildItem* param_1);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~BuildItem() noexcept(false); // Ghidra: `vector_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void loggingHistory();

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void setLogHistory();

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void toggleLogHistory();

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void setHistoryFilename();

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void loggingCommonHistory();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void setLogCommonHistory();

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void toggleLogCommonHistory();

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void loadState();

    // [Slot 10] Offset 0x28 WARNING: Function body missing in analysis
    // virtual void saveState();

    // [Slot 11] Offset 0x2C WARNING: Function body missing in analysis
    // virtual void gleanState();

    // [Slot 12] Offset 0x30 WARNING: Function body missing in analysis
    // virtual void processMessage();

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void update();

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void setCallbackMessage();

    // [Slot 15] Offset 0x3C WARNING: Function body missing in analysis
    // virtual void filterOutMessage();

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 17] Offset 0x44 WARNING: Function body missing in analysis
    // virtual void displayBuildList();

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void loadBuildList();

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void numberBuiltOrInProgressItemsOfType();

    // --- Non-Virtual Members ---
    int buildCategory();
    int number();
    int priority();
    int inProgress();
    int built();
    int buildAttempts();
    int buildFrom();
    int terrainSet();
    int terrainAdjacency(int param_1);
    int placeOnElevation();
    void setInProgress(int param_1);
    void setBuilt(int param_1);
    void setBuildAttempts(int param_1);
    void incrementBuildAttempts();
    void decrementBuildAttempts();
    int numberBuilds();
    void incrementNumberBuilds();
    void setNumberBuilds(int param_1);
    int buildCap();
    void setBuildCap(int param_1);
    int skipCycles();
    void incrementSkipCycles();
    void setSkipCycles(int param_1);
    uchar permanentSkip();
    void setPermanentSkip(uchar param_1);
};

static_assert(sizeof(BuildItem) == 0xB0, "BuildItem Size Mismatch");
static_assert(offsetof(BuildItem, permanentSkipValue) == 0xAC, "BuildItem Offset Mismatch");

