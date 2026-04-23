// tried the direct idleRules layout and the decompiler-style scan; the body is right but VC5 keeps dropping the ebx save
// tried adding a local values pointer and max temp to coax the original register basin; mismatch stayed at the entry prolog
// leaving in scratch: remaining delta is prolog/register allocation, not the loop predicate or return behavior

class TribeStrategyAIModule {
public:
    char gap_000[0x258];
    int* idleRules_value;   // 0x258
    int idleRules_count;    // 0x25C
    char gap_260[0x4];
    int idleRules_max;      // 0x264

    int isRuleIdle(int rule_id);
};

int TribeStrategyAIModule::isRuleIdle(int rule_id) {
    int count = this->idleRules_count;
    int index = 0;
    if (0 < count) {
        int* values = this->idleRules_value;
        int max = this->idleRules_max;
        while (index < max) {
            if (values[index] == rule_id) {
                return 1;
            }
            index = index + 1;
            if (count <= index) {
                return 0;
            }
        }
    }
    return 0;
}
