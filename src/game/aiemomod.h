#pragma once
#include "../common.h"
#include "aimdmod.h"
#include "aimodule.h"

class EmotionalAIModule : public AIModule       {
public:
    char _pad_0x4[0xEC];
    MainDecisionAIModule* md;                // 0xF0
    int stateValue[6];                       // 0xF4
    char stateNameValue[6][30];              // 0x10C

    EmotionalAIModule(void* param_1, int param_2);
    EmotionalAIModule(int param_1, int param_2);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~EmotionalAIModule() noexcept(false); // Ghidra: `vector_deleting_destructor'

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

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 17] Offset 0x44 WARNING: Function body missing in analysis
    // virtual void loggingHistory();

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void setLogHistory();

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void toggleLogHistory();

    // [Slot 20] Offset 0x50 WARNING: Function body missing in analysis
    // virtual void setHistoryFilename();

    // [Slot 21] Offset 0x54 WARNING: Function body missing in analysis
    // virtual void loggingCommonHistory();

    // [Slot 22] Offset 0x58 WARNING: Function body missing in analysis
    // virtual void setLogCommonHistory();

    // [Slot 23] Offset 0x5C WARNING: Function body missing in analysis
    // virtual void toggleLogCommonHistory();

    // [Slot 24] Offset 0x60 WARNING: Function body missing in analysis
    // virtual void loadState();

    // [Slot 25] Offset 0x64 WARNING: Function body missing in analysis
    // virtual void saveState();

    // [Slot 26] Offset 0x68 WARNING: Function body missing in analysis
    // virtual void gleanState();

    // [Slot 27] Offset 0x6C WARNING: Function body missing in analysis
    // virtual void processMessage();

    // [Slot 28] Offset 0x70 WARNING: Function body missing in analysis
    // virtual void update();

    // [Slot 29] Offset 0x74 WARNING: Function body missing in analysis
    // virtual void setCallbackMessage();

    // [Slot 30] Offset 0x78 WARNING: Function body missing in analysis
    // virtual void filterOutMessage();

    // --- Non-Virtual Members ---
    void setMainDecisionAI(MainDecisionAIModule* param_1);
    char* stateName(int param_1);
    int state(int param_1);
    void setState(int param_1, int param_2);
    void incrementState(int param_1, int param_2);
    void decrementState(int param_1, int param_2);
    int overallState();
    void setOverallState(int param_1);
    int defaultState();
};

static_assert(sizeof(EmotionalAIModule) == 0x1C0, "EmotionalAIModule Size Mismatch");
static_assert(offsetof(EmotionalAIModule, stateNameValue) == 0x10C, "EmotionalAIModule Offset Mismatch");

