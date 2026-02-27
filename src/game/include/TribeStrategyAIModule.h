#pragma once
#include "common.h"
#include "StrategyAIModule.h"
#include "VictoryConditionRuleSystem.h"
#include "Waypoint.h"

class TribeStrategyAIModule : public StrategyAIModule {
public:
    TribeStrategyAIModule(void* param_1, int param_2);
    TribeStrategyAIModule(int param_1, int param_2);

    // Virtuals (best-effort)
    virtual ~TribeStrategyAIModule(); // vt[0] (0x0)
    virtual int loggingHistory(); // vt[1] (0x4)
    virtual void setLogHistory(int param_1); // vt[2] (0x8)
    virtual void toggleLogHistory(); // vt[3] (0xC)
    virtual void setHistoryFilename(char* param_1); // vt[4] (0x10)
    virtual int loggingCommonHistory(); // vt[5] (0x14)
    virtual void setLogCommonHistory(int param_1); // vt[6] (0x18)
    virtual void toggleLogCommonHistory(); // vt[7] (0x1C)
    virtual int loadState(char* param_1); // vt[8] (0x20)
    virtual int saveState(char* param_1); // vt[9] (0x24)
    virtual int gleanState(int param_1); // vt[10] (0x28)
    virtual int processMessage(AIModuleMessage* param_1); // vt[11] (0x2C)
    virtual int update(int param_1); // vt[12] (0x30)
    virtual void setCallbackMessage(AIModuleMessage* param_1); // vt[13] (0x34)
    virtual int filterOutMessage(AIModuleMessage* param_1); // vt[14] (0x38)
    virtual int save(int param_1); // vt[15] (0x3C)

    void setMainDecisionAI(TribeMainDecisionAIModule* param_1);
    char* ruleSetName();
    int loadRules(char* param_1);
    void setRule(int param_1, int param_2);
    int rule(int param_1);
    void setDifficultyLevel(int param_1);
    int currentVictoryCondition() const;
    int targetID() const;
    int targetType() const;
    int secondTargetID() const;
    int secondTargetType() const;
    const Waypoint& targetPoint1() const;
    const Waypoint& targetPoint2() const;
    int targetAttribute() const;
    int targetNumber() const;
    void setVictoryCondition(int param_1);
    int isRuleExecuting(int param_1);
    int isRuleIdle(int param_1);

    TribeMainDecisionAIModule* md;
    int currentVictoryConditionValue;
    char ruleSetNameValue[257];
    int targetIDValue;
    int targetTypeValue;
    int secondTargetIDValue;
    int secondTargetTypeValue;
    Waypoint targetPoint1Value;
    Waypoint targetPoint2Value;
    int targetAttributeValue;
    int targetNumberValue;
    int victoryConditionChangeTimeout;
    ManagedArray<int> vcRuleSet;
    ManagedArray<int> executingRules;
    ManagedArray<int> idleRules;
    VictoryConditionRuleSystem vcRules;
    int difficultyLevel;
};
static_assert(sizeof(TribeStrategyAIModule) == 0x5F8, "Size mismatch");
