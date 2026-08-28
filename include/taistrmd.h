#ifndef TAISTRMD_H
#define TAISTRMD_H

// Declarations for the original taistrmd.cpp source module.
// PDB order starts with VictoryConditionRuleSystem and then the strategy
// module constructors and methods.

#include "aivcrule.h"
#include "aistrmod.h"
#include "utmarray.h"
#include "waypoint.h"

class RGE_Base_Game;
class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Static_Object;
class RGE_Victory_Conditions;
class TribeMainDecisionAIModule;
class TRIBE_Player;
struct RGE_Victory_Entry;

void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* pointer);

class TribeStrategyAIModule : public StrategyAIModule {
public:
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

    virtual ~TribeStrategyAIModule();
    virtual int update(int parameter);
    virtual int save(int fileHandle);
    TribeStrategyAIModule(void* object, int parameter);
    TribeStrategyAIModule(int playerID, int infile);
    void setMainDecisionAI(TribeMainDecisionAIModule* value);
    int loadRules(char* name);
    void setDifficultyLevel(int level);
    void setRule(int rule, int value);
    int rule(int index);
    char* ruleSetName();
    int currentVictoryCondition() const;
    int targetID() const;
    int targetType() const;
    int secondTargetID() const;
    int secondTargetType() const;
    const Waypoint& targetPoint1() const;
    const Waypoint& targetPoint2() const;
    int targetAttribute() const;
    int targetNumber() const;
    void setVictoryCondition(int value);
    int isRuleExecuting(int ruleID);
    int isRuleIdle(int ruleID);
};

typedef char taistrmd_strategy_size[
    (sizeof(TribeStrategyAIModule) == 0x5F8) ? 1 : -1];

typedef char taistrmd_rule_set_name_size[
    (sizeof(((TribeStrategyAIModule*)0)->ruleSetNameValue) == 257) ? 1 : -1];

#endif
