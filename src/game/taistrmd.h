#pragma once
#include "common.h"

class TribeStrategyAIModule : public StrategyAIModule {
public:
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

    virtual int update(int param_1);                        // vt0[12]+0x30=0x4E9820
    virtual int save(int param_1);                          // vt0[15]+0x3C=0x4E9DA0
    TribeStrategyAIModule(void* param_1, int param_2);
    TribeStrategyAIModule(int param_1, int param_2);
    ~TribeStrategyAIModule();
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

class VictoryConditionRuleSystem {
public:
    // [omitted] vfptr @ 0x0 ('_padding_')
    int sn[226];                             // 0x4

    VictoryConditionRuleSystem();
    ~VictoryConditionRuleSystem();
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

