// tried swapping compare/source order; still in the load-order basin at 0x0D24/0x254
class TribeTacticalAIModule {
public:
    char gap_00[0x254];
    unsigned long randomizedAttackSeparationTime;
    char gap_258[0x58];
    unsigned long attack_state;
    char gap_2B4[0xA70];
    unsigned long attack_mode;

    unsigned long attackLimiterTime(int param);
};

unsigned long TribeTacticalAIModule::attackLimiterTime(int param) {
    if (this->attack_state == 1) {
        if (this->randomizedAttackSeparationTime < this->attack_mode) {
            return this->attack_mode;
        }
        return this->randomizedAttackSeparationTime;
    }
    if (param == 0x2E) {
        return this->randomizedAttackSeparationTime;
    }
    return this->attack_mode;
}
