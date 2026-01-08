#pragma once
#include "../common.h"
#include "taimdmd.h"
#include "tplayer.h"

class VictoryConditionRuleSystem       {
public:
    int sn[226];                             // 0x4

    VictoryConditionRuleSystem();

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~VictoryConditionRuleSystem() noexcept(false); // Ghidra: `scalar_deleting_destructor'

    // --- Non-Virtual Members ---
    int loadRules(char* param_1);
    void setRule(int param_1, int param_2);
    int rule(int param_1);
    int evaluateAsInProgress(TRIBE_Player* param_1, int param_2);
    int evaluateAsNonInProgress(TRIBE_Player* param_1, int param_2);
    int execute(TRIBE_Player* param_1, int param_2, int param_3);
    int stopExecution(TRIBE_Player* param_1, int param_2);
    void modifyForDifficultyLevel(int param_1);
};

static_assert(sizeof(VictoryConditionRuleSystem) == 0x38C, "VictoryConditionRuleSystem Size Mismatch");
static_assert(offsetof(VictoryConditionRuleSystem, sn) == 0x4, "VictoryConditionRuleSystem Offset Mismatch");

class TribeStrategyAIModule : public StrategyAIModule       {
public:
    char _pad_0x4[0xEC];
    TribeMainDecisionAIModule* md;           // 0xF0
    int currentVictoryConditionValue;        // 0xF4
    char ruleSetNameValue[257];              // 0xF8
    int targetIDValue;                       // 0x1FC
    int targetTypeValue;                     // 0x200
    int secondTargetIDValue;                 // 0x204
    int secondTargetTypeValue;               // 0x208
    Waypoint targetPoint1Value;              // 0x20C
    Waypoint targetPoint2Value;              // 0x21C
    int targetAttributeValue;                // 0x22C
    int targetNumberValue;                   // 0x230
    int victoryConditionChangeTimeout;       // 0x234
    ManagedArray<int> vcRuleSet;             // 0x238
    ManagedArray<int> executingRules;        // 0x248
    ManagedArray<int> idleRules;             // 0x258
    VictoryConditionRuleSystem vcRules;      // 0x268
    int difficultyLevel;                     // 0x5F4

    TribeStrategyAIModule(void* param_1, int param_2);
    TribeStrategyAIModule(int param_1, int param_2);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TribeStrategyAIModule() noexcept(false); // Ghidra: `vector_deleting_destructor'

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
    // virtual void `scalar_deleting_destructor'();

    // --- Non-Virtual Members ---
    void setMainDecisionAI(TribeMainDecisionAIModule* param_1);
    char* ruleSetName();
    int loadRules(char* param_1);
    void setRule(int param_1, int param_2);
    int rule(int param_1);
    void setDifficultyLevel(int param_1);
    int currentVictoryCondition();
    int targetID();
    int targetType();
    int secondTargetID();
    int secondTargetType();
    Waypoint* targetPoint1();
    Waypoint* targetPoint2();
    int targetAttribute();
    int targetNumber();
    void setVictoryCondition(int param_1);
    int isRuleExecuting(int param_1);
    int isRuleIdle(int param_1);
};

static_assert(sizeof(TribeStrategyAIModule) == 0x5F8, "TribeStrategyAIModule Size Mismatch");
static_assert(offsetof(TribeStrategyAIModule, difficultyLevel) == 0x5F4, "TribeStrategyAIModule Offset Mismatch");

