#ifndef AOE1_AIVCRULE_H
#define AOE1_AIVCRULE_H

class TRIBE_Player;

class VictoryConditionRuleSystem {
public:
    virtual ~VictoryConditionRuleSystem();

    VictoryConditionRuleSystem();
    int loadRules(char* filename);
    void setRule(int index, int value);
    int rule(int index);
    int evaluateAsInProgress(TRIBE_Player* player, int rule);
    int evaluateAsNonInProgress(TRIBE_Player* player, int rule);
    int stopExecution(TRIBE_Player* player, int rule);
    int execute(TRIBE_Player* player, int state, int command);
    void modifyForDifficultyLevel(int level);

    int sn[226];
};

typedef char aivcrule_victory_condition_rule_system_size[
    (sizeof(VictoryConditionRuleSystem) == 0x38C) ? 1 : -1];

#endif
