// first pass: scan the executingRules array for a matching rule id and return 1 on the first hit
// tried caching max and the rules pointer, then a nested ManagedRuleArray layout; the mismatch stayed in the prolog/register basin (push ebx / load order)

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
    int i = 0;
    int count = this->executingRules.numberValue;

    if (count > 0) {
        while (i < this->executingRules.maximumSizeValue) {
            if (this->executingRules.value[i] == ruleId) {
                return 1;
            }
            i = i + 1;
            if (count <= i) {
                return 0;
            }
        }
    }
    return 0;
}
