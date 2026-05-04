// probe 5: loop bounded by numberValue, inner guard on maximumSizeValue

class ManagedRuleArray {
public:
    int* value;
    int numberValue;
    char gap_04[0x4];
    int maximumSizeValue;
};

class TribeStrategyAIModule {
public:
    char gap_00[0x248];
    ManagedRuleArray executingRules;

    int isRuleExecuting(int ruleId);
};

int TribeStrategyAIModule::isRuleExecuting(int ruleId) {
    int i;

    for (i = 0; i < this->executingRules.numberValue; i = i + 1) {
        if (i >= this->executingRules.maximumSizeValue) {
            return 0;
        }
        if (this->executingRules.value[i] == ruleId) {
            return 1;
        }
    }
    return 0;
}
