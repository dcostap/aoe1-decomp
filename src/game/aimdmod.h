#pragma once
#include "../common.h"
#include "aimodule.h"
#include "player.h"
#include "utmarray.h"

class MainDecisionAIModule : public AIModule       {
public:
    char _pad_0x4[0xEC];
    RGE_Player* player;                      // 0xF0
    ManagedArray<int> objects;               // 0xF4

    MainDecisionAIModule(void* param_1, int param_2, RGE_Player* param_3);
    MainDecisionAIModule(int param_1, RGE_Player* param_2, int param_3);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~MainDecisionAIModule() noexcept(false); // Ghidra: `vector_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void loggingHistory();

    // [Slot 02] Offset 0x08 (Override)
    virtual void setLogHistory(int param_1); // Ghidra: setLogHistory

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
    virtual int addObject(RGE_Static_Object* param_1); // Ghidra: addObject

    // [Slot 17] Offset 0x44 (Override)
    virtual int removeObject(int param_1); // Ghidra: removeObject

    // [Slot 18] Offset 0x48 (Override)
    virtual int objectGroupThatCanPerformAction(int param_1); // Ghidra: objectGroupThatCanPerformAction

    // [Slot 19] Offset 0x4C (Override)
    virtual int canPerformAction(int param_1, int param_2); // Ghidra: canPerformAction

    // [Slot 20] Offset 0x50 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 21] Offset 0x54 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 22] Offset 0x58 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 23] Offset 0x5C WARNING: Function body missing in analysis
    // virtual void loggingHistory();

    // [Slot 24] Offset 0x60 WARNING: Function body missing in analysis
    // virtual void setLogHistory();

    // [Slot 25] Offset 0x64 WARNING: Function body missing in analysis
    // virtual void toggleLogHistory();

    // [Slot 26] Offset 0x68 WARNING: Function body missing in analysis
    // virtual void setHistoryFilename();

    // [Slot 27] Offset 0x6C WARNING: Function body missing in analysis
    // virtual void loggingCommonHistory();

    // [Slot 28] Offset 0x70 WARNING: Function body missing in analysis
    // virtual void setLogCommonHistory();

    // [Slot 29] Offset 0x74 WARNING: Function body missing in analysis
    // virtual void toggleLogCommonHistory();

    // [Slot 30] Offset 0x78 WARNING: Function body missing in analysis
    // virtual void loadState();

    // [Slot 31] Offset 0x7C WARNING: Function body missing in analysis
    // virtual void saveState();

    // [Slot 32] Offset 0x80 WARNING: Function body missing in analysis
    // virtual void gleanState();

    // [Slot 33] Offset 0x84 WARNING: Function body missing in analysis
    // virtual void processMessage();

    // [Slot 34] Offset 0x88 WARNING: Function body missing in analysis
    // virtual void update();

    // [Slot 35] Offset 0x8C WARNING: Function body missing in analysis
    // virtual void setCallbackMessage();

    // [Slot 36] Offset 0x90 WARNING: Function body missing in analysis
    // virtual void filterOutMessage();

    // --- Non-Virtual Members ---
    int numberObjects();
    int numberObjectsWithAction(int param_1);
    int numberObjectsWithGroup(int param_1);
    int numberObjectsWithActionAndTarget(int param_1, int param_2);
    int numberObjectsWithTargetType(int param_1);
    int numberObjectsWithActionAndTargetType(int param_1, int param_2);
    RGE_Static_Object* object(int param_1);
    RGE_Static_Object* object(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7, int param_8, int param_9, int param_10);
    RGE_Static_Object* object(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6);
    int numberBusyObjects();
    RGE_Static_Object* mostDamaged(int param_1, int param_2);
};

static_assert(sizeof(MainDecisionAIModule) == 0x104, "MainDecisionAIModule Size Mismatch");
static_assert(offsetof(MainDecisionAIModule, objects) == 0xF4, "MainDecisionAIModule Offset Mismatch");

