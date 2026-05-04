// probe 2: mirror the matched executingRules pattern with the idleRules offsets

class TribeStrategyAIModule {
public:
    char gap_000[0x258];
    int* idleRules_value;   // +0x258
    int idleRules_count;    // +0x25C
    char gap_260[0x4];
    int idleRules_max;      // +0x264

    int isRuleIdle(int rule_id);
};

int TribeStrategyAIModule::isRuleIdle(int rule_id) {
    int i;

    for (i = 0; i < this->idleRules_count; i = i + 1) {
        if (i >= this->idleRules_max) {
            return 0;
        }
        if (this->idleRules_value[i] == rule_id) {
            return 1;
        }
    }
    return 0;
}
