#pragma once
#include "../common.h"

class TacticalAIModule : public AIModule       {
public:
    char _pad_0x4[0xEC];

    TacticalAIModule(void* param_1, int param_2);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TacticalAIModule() noexcept(false); // Ghidra: `vector_deleting_destructor'

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

    // [Slot 15] Offset 0x3C WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

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
    // virtual void `scalar_deleting_destructor'();

    // [Slot 33] Offset 0x84 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 34] Offset 0x88 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 35] Offset 0x8C WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 36] Offset 0x90 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 37] Offset 0x94 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 38] Offset 0x98 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 39] Offset 0x9C WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 40] Offset 0xA0 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 41] Offset 0xA4 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 42] Offset 0xA8 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 43] Offset 0xAC WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 44] Offset 0xB0 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 45] Offset 0xB4 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 46] Offset 0xB8 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 47] Offset 0xBC WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 48] Offset 0xC0 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 49] Offset 0xC4 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 50] Offset 0xC8 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 51] Offset 0xCC WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 52] Offset 0xD0 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 53] Offset 0xD4 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 54] Offset 0xD8 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 55] Offset 0xDC WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 56] Offset 0xE0 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 57] Offset 0xE4 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 58] Offset 0xE8 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 59] Offset 0xEC WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 60] Offset 0xF0 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 61] Offset 0xF4 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 62] Offset 0xF8 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 63] Offset 0xFC WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 64] Offset 0x100 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 65] Offset 0x104 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 66] Offset 0x108 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 67] Offset 0x10C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 68] Offset 0x110 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 69] Offset 0x114 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 70] Offset 0x118 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 71] Offset 0x11C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 72] Offset 0x120 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 73] Offset 0x124 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 74] Offset 0x128 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 75] Offset 0x12C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 76] Offset 0x130 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 77] Offset 0x134 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 78] Offset 0x138 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 79] Offset 0x13C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 80] Offset 0x140 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 81] Offset 0x144 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 82] Offset 0x148 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 83] Offset 0x14C WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 84] Offset 0x150 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 85] Offset 0x154 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 86] Offset 0x158 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 87] Offset 0x15C WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

};

static_assert(sizeof(TacticalAIModule) == 0xF0, "TacticalAIModule Size Mismatch");

