#pragma once
#include "../common.h"

class TechnologyItem       {
public:
    TechnologyItem* next;                    // 0x4
    TechnologyItem* prev;                    // 0x8
    int idValue;                             // 0xC
    char nameValue[64];                      // 0x10
    ResourceItem* resourceCostValue;         // 0x50

    TechnologyItem();
    TechnologyItem(int param_1, char* param_2, ResourceItem param_3);
    TechnologyItem(TechnologyItem* param_1);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TechnologyItem() noexcept(false); // Ghidra: `scalar_deleting_destructor'

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
    // virtual void `scalar_deleting_destructor'();

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 20] Offset 0x50 WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 21] Offset 0x54 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 22] Offset 0x58 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 23] Offset 0x5C WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 24] Offset 0x60 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 25] Offset 0x64 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 26] Offset 0x68 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 27] Offset 0x6C WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 28] Offset 0x70 WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 29] Offset 0x74 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 30] Offset 0x78 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 31] Offset 0x7C WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 32] Offset 0x80 WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 33] Offset 0x84 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 34] Offset 0x88 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 35] Offset 0x8C WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 36] Offset 0x90 WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 37] Offset 0x94 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 38] Offset 0x98 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 39] Offset 0x9C WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 40] Offset 0xA0 WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 41] Offset 0xA4 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 42] Offset 0xA8 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 43] Offset 0xAC WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 44] Offset 0xB0 WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 45] Offset 0xB4 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 46] Offset 0xB8 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 47] Offset 0xBC WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 48] Offset 0xC0 WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 49] Offset 0xC4 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 50] Offset 0xC8 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 51] Offset 0xCC WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 52] Offset 0xD0 WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 53] Offset 0xD4 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 54] Offset 0xD8 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 55] Offset 0xDC WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 56] Offset 0xE0 WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 57] Offset 0xE4 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 58] Offset 0xE8 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 59] Offset 0xEC WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 60] Offset 0xF0 WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 61] Offset 0xF4 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 62] Offset 0xF8 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 63] Offset 0xFC WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 64] Offset 0x100 WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 65] Offset 0x104 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 66] Offset 0x108 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 67] Offset 0x10C WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 68] Offset 0x110 WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 69] Offset 0x114 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 70] Offset 0x118 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 71] Offset 0x11C WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 72] Offset 0x120 WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // --- Non-Virtual Members ---
    int id();
    char* name();
    ResourceItem* resourceCost();
};

static_assert(sizeof(TechnologyItem) == 0x54, "TechnologyItem Size Mismatch");
static_assert(offsetof(TechnologyItem, resourceCostValue) == 0x50, "TechnologyItem Offset Mismatch");

