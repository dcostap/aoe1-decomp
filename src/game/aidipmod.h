#pragma once
#include "../common.h"
#include "aimdmod.h"
#include "aimodule.h"

class DiplomacyAIModule : public AIModule       {
public:
    char _pad_0x4[0xEC];
    MainDecisionAIModule* md;                // 0xF0
    int dislikeTable[10];                    // 0xF4
    int likeTable[10];                       // 0x11C
    uchar changeableTable[10];               // 0x144

    DiplomacyAIModule(void* param_1, int param_2);
    DiplomacyAIModule(int param_1, int param_2);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~DiplomacyAIModule() noexcept(false); // Ghidra: `scalar_deleting_destructor'

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

    // [Slot 12] Offset 0x30 (Override)
    virtual int update(int param_1); // Ghidra: update

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

    // [Slot 31] Offset 0x7C WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 32] Offset 0x80 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 33] Offset 0x84 WARNING: Function body missing in analysis
    // virtual void loggingHistory();

    // [Slot 34] Offset 0x88 WARNING: Function body missing in analysis
    // virtual void setLogHistory();

    // [Slot 35] Offset 0x8C WARNING: Function body missing in analysis
    // virtual void toggleLogHistory();

    // [Slot 36] Offset 0x90 WARNING: Function body missing in analysis
    // virtual void setHistoryFilename();

    // [Slot 37] Offset 0x94 WARNING: Function body missing in analysis
    // virtual void loggingCommonHistory();

    // [Slot 38] Offset 0x98 WARNING: Function body missing in analysis
    // virtual void setLogCommonHistory();

    // [Slot 39] Offset 0x9C WARNING: Function body missing in analysis
    // virtual void toggleLogCommonHistory();

    // [Slot 40] Offset 0xA0 WARNING: Function body missing in analysis
    // virtual void loadState();

    // [Slot 41] Offset 0xA4 WARNING: Function body missing in analysis
    // virtual void saveState();

    // [Slot 42] Offset 0xA8 WARNING: Function body missing in analysis
    // virtual void gleanState();

    // [Slot 43] Offset 0xAC WARNING: Function body missing in analysis
    // virtual void processMessage();

    // [Slot 44] Offset 0xB0 WARNING: Function body missing in analysis
    // virtual void update();

    // [Slot 45] Offset 0xB4 WARNING: Function body missing in analysis
    // virtual void setCallbackMessage();

    // [Slot 46] Offset 0xB8 WARNING: Function body missing in analysis
    // virtual void filterOutMessage();

    // --- Non-Virtual Members ---
    void setMainDecisionAI(MainDecisionAIModule* param_1);
    int stance(int param_1, int param_2);
    void changeStance(int param_1, int param_2, int param_3);
    void setStance(int param_1, int param_2, int param_3);
    int isDisliked(int param_1);
    int isAmbivalent(int param_1);
    int isLiked(int param_1);
    int isChangeable(int param_1);
    void setChangeable(int param_1, uchar param_2);
    int mostHated(int param_1, int param_2, int param_3, int param_4);
    int mostLiked(int param_1, int param_2);
    int isEnemy(int param_1);
    int isNeutral(int param_1);
    int isAlly(int param_1);
    int isAlliedWithMe(int param_1);
    void setRelation(int param_1, int param_2);
};

static_assert(sizeof(DiplomacyAIModule) == 0x150, "DiplomacyAIModule Size Mismatch");
static_assert(offsetof(DiplomacyAIModule, changeableTable) == 0x144, "DiplomacyAIModule Offset Mismatch");

