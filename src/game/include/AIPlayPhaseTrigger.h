#pragma once
#include "common.h"

struct AIPlayPhaseTrigger {
    uchar typeValue;
    int value1Value;
    int value2Value;
    uchar phaseValue;
    uchar nextPhaseValue;
    int randomnessValue;

    AIPlayPhaseTrigger();
    AIPlayPhaseTrigger(uchar type, int value1, int value2, uchar phase, uchar nextPhase, int randomness);
    AIPlayPhaseTrigger(char* typeName, int value1, int value2, uchar phase, uchar nextPhase, int randomness);
    char* nameType() const;

protected:
    uchar convertToIntType(char* typeName) const;
    char* convertToNameType(uchar type) const;
};
static_assert(sizeof(AIPlayPhaseTrigger) == 0x14, "Size mismatch");
