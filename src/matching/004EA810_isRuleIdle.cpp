// probe 2: mirror the matched executingRules pattern with the idleRules offsets

#ifndef TAISTRMD_TU_CONTEXT
class TribeStrategyAIModule {
public:
    char gap_000[0x258];
    int* idleRules_value;   // +0x258
    int idleRules_count;    // +0x25C
    char gap_260[0x4];
    int idleRules_max;      // +0x264

    int isRuleIdle(int rule_id);
};
#endif

int TribeStrategyAIModule::isRuleIdle(int rule_id) {
    int i;

    for (i = 0; i < this->idleRules.numberValue; i = i + 1) {
        if (i >= this->idleRules.maximumSizeValue) {
            return 0;
        }
        if (this->idleRules.value[i] == rule_id) {
            return 1;
        }
    }
    return 0;
}
