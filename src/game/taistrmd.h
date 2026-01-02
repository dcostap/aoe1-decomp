#pragma once
#include "../common.h"

class VictoryConditionRuleSystem {
public:
    int sn[226];                             // 0x4

    VictoryConditionRuleSystem();
    virtual ~VictoryConditionRuleSystem();
    virtual int loadRules(char* param_1);
    virtual void setRule(int param_1, int param_2);
    virtual int rule(int param_1);
    virtual int evaluateAsInProgress(TRIBE_Player* param_1, int param_2);
    virtual int evaluateAsNonInProgress(TRIBE_Player* param_1, int param_2);
    virtual int execute(TRIBE_Player* param_1, int param_2, int param_3);
    virtual int stopExecution(TRIBE_Player* param_1, int param_2);
    virtual void modifyForDifficultyLevel(int param_1);
};

static_assert(sizeof(VictoryConditionRuleSystem) == 0x38C, "VictoryConditionRuleSystem Size Mismatch");
static_assert(offsetof(VictoryConditionRuleSystem, sn) == 0x4, "VictoryConditionRuleSystem Offset Mismatch");

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

    TribeStrategyAIModule(void* param_1, int param_2);
    TribeStrategyAIModule(int param_1, int param_2);
    virtual ~TribeStrategyAIModule();
    virtual int update(int param_1);
    virtual void setMainDecisionAI(TribeMainDecisionAIModule* param_1);
    virtual int save(int param_1);
    virtual char* ruleSetName();
    virtual int loadRules(char* param_1);
    virtual void setRule(int param_1, int param_2);
    virtual int rule(int param_1);
    virtual void setDifficultyLevel(int param_1);
    virtual int currentVictoryCondition();
    virtual int targetID();
    virtual int targetType();
    virtual int secondTargetID();
    virtual int secondTargetType();
    virtual Waypoint* targetPoint1();
    virtual Waypoint* targetPoint2();
    virtual int targetAttribute();
    virtual int targetNumber();
    virtual void setVictoryCondition(int param_1);
    virtual int isRuleExecuting(int param_1);
    virtual int isRuleIdle(int param_1);
};

static_assert(sizeof(TribeStrategyAIModule) == 0x5F8, "TribeStrategyAIModule Size Mismatch");
static_assert(offsetof(TribeStrategyAIModule, difficultyLevel) == 0x5F4, "TribeStrategyAIModule Offset Mismatch");

