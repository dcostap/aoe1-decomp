#pragma once
#include "../common.h"
#include "aibitm.h"

class ConstructionItem : public BaseItem       {
public:
    char _pad_0x4[0x68];
    ConstructionItem* next;                  // 0x6C
    ConstructionItem* prev;                  // 0x70
    int inProgressValue;                     // 0x74
    int builtValue;                          // 0x78
    int buildAttemptsValue;                  // 0x7C

    ConstructionItem();
    ConstructionItem(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6, int param_7, char* param_8);
    ConstructionItem(ConstructionItem* param_1);
    ConstructionItem(ConstructionItem* param_1);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~ConstructionItem() noexcept(false); // Ghidra: `scalar_deleting_destructor'

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
    // virtual void loadConstructionPlan();

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void placeStructure();

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void setBuilt();

    // [Slot 20] Offset 0x50 WARNING: Function body missing in analysis
    // virtual void unplaceStructure();

    // [Slot 21] Offset 0x54 WARNING: Function body missing in analysis
    // virtual void unplaceStructure();

    // [Slot 22] Offset 0x58 WARNING: Function body missing in analysis
    // virtual void decrementBuildAttempts();

    // [Slot 23] Offset 0x5C WARNING: Function body missing in analysis
    // virtual void incrementBuildAttempts();

    // --- Non-Virtual Members ---
    int inProgress();
    int built();
    int buildAttempts();
    void setInProgress(int param_1);
    void setBuilt(int param_1);
    void incrementBuildAttempts();
    void decrementBuildAttempts();
    void setBuildAttempts(int param_1);
};

static_assert(sizeof(ConstructionItem) == 0x80, "ConstructionItem Size Mismatch");
static_assert(offsetof(ConstructionItem, buildAttemptsValue) == 0x7C, "ConstructionItem Offset Mismatch");

