#pragma once
#include "common.h"

struct AIPlayPhaseTrigger {
    uchar typeValue;
    int value1Value;
    int value2Value;
    uchar phaseValue;
    uchar nextPhaseValue;
    int randomnessValue;
};
static_assert(sizeof(AIPlayPhaseTrigger) == 0x14, "Size mismatch");
