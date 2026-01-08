#pragma once
#include "../common.h"
#include "aimodule.h"
#include "aiblditm.h"
#include "utmarray.h"
#include "player.h"

class BuildAIModule : public AIModule       {
public:
    char _pad_0x4[0xEC];
    BuildItem buildList;                     // 0xF0
    int buildListLengthValue;                // 0x1A0
    char buildListNameValue[257];            // 0x1A4
    char lastBuildItemRequestedValue[257];   // 0x2A5
    char currentBuildItemRequestedValue[257]; // 0x3A6
    char nextBuildItemRequestedValue[257];   // 0x4A7
    int numberItemsIntoBuildListValue;       // 0x5A8
    ManagedArray<int> typesToIgnore;         // 0x5AC

    BuildAIModule(void* param_1, int param_2);
    BuildAIModule(int param_1, int param_2);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~BuildAIModule() noexcept(false); // Ghidra: `scalar_deleting_destructor'

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
    virtual void displayBuildList(); // Ghidra: displayBuildList

    // [Slot 17] Offset 0x44 (Override)
    virtual int loadBuildList(char* param_1, RGE_Player* param_2); // Ghidra: loadBuildList

    // [Slot 18] Offset 0x48 (Override)
    virtual int numberBuiltOrInProgressItemsOfType(int param_1, int param_2); // Ghidra: numberBuiltOrInProgressItemsOfType

    // --- Non-Virtual Members ---
    int buildListLength();
    char* buildListName();
    int haveBuildList();
    int insertItem(RGE_Player* param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7);
    int numberItemsBuilt();
    int numberItemsInProgress();
    int numberItemsBuiltOrInProgress();
    int numberItemsIntoBuildList();
    char* lastBuildItemRequested();
    char* currentBuildItemRequested();
    char* nextBuildItemRequested();
    int numberItemsOfType(int param_1, int param_2);
    int numberBuiltItemsOfType(int param_1, int param_2);
    int numberUnbuiltItemsOfType(int param_1, int param_2);
    int numberInProgressItemsOfType(int param_1, int param_2);
    void removeOldList();
    BuildItem* anyBuildListItem(int param_1, int param_2, int param_3);
    BuildItem* specificBuildListItem(int param_1);
};

static_assert(sizeof(BuildAIModule) == 0x5BC, "BuildAIModule Size Mismatch");
static_assert(offsetof(BuildAIModule, typesToIgnore) == 0x5AC, "BuildAIModule Offset Mismatch");

