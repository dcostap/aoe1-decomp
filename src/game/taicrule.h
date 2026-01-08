#pragma once
#include "../common.h"

class CombatRuleSystem       {
public:
    uchar ratingValue[2500];                 // 0x4

    CombatRuleSystem();

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~CombatRuleSystem() noexcept(false); // Ghidra: `scalar_deleting_destructor'

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

    // --- Non-Virtual Members ---
    int loadRules(char* param_1);
    int bestUnitTypeToAttack(int param_1);
    int bestUnitTypeToDefendAgainst(int param_1);
};

static_assert(sizeof(CombatRuleSystem) == 0x9C8, "CombatRuleSystem Size Mismatch");
static_assert(offsetof(CombatRuleSystem, ratingValue) == 0x4, "CombatRuleSystem Offset Mismatch");

