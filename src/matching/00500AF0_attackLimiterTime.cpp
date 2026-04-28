// TribeTacticalAIModule::attackLimiterTime
// VA: 00500AF0
// taitacmd.cpp:11549-11562
// MATCH: 0.0000% diff, 0 relocations masked

#include "../../include/game_globals.h"

class TribeTacticalAIModule {
public:
    char gap_00[0x254];
    int attackSeparationTime;          // +0x254
    char gap_258[0x2B0 - 0x258];
    int attackLimiterMode;             // +0x2B0
    char gap_2B4[0xD24 - 0x2B4];
    int randomizedAttackSeparationTime; // +0xD24

    unsigned long attackLimiterTime(int param_1);
};

unsigned long TribeTacticalAIModule::attackLimiterTime(int param_1) {
    if (this->attackLimiterMode == 1) {
        int val = this->randomizedAttackSeparationTime;
        int limit = this->attackSeparationTime;
        if (val < limit) {
            return val;
        }
        return limit;
    } else {
        if (param_1 == 0x2E) {
            return this->randomizedAttackSeparationTime;
        }
        return this->attackSeparationTime;
    }
}
