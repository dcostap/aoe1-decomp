#pragma once
#include "common.h"

struct AIPlayStatus {
    GroupingStruct groupings[50];
    int playNumberValue;
    int targetValue;
    XYZ originalPointValue;
    int originalHitPointsValue[5];
    uchar currentPhaseValue;
    int savedAttackerValue;
    ulong lastPhaseChangeTimeValue;
    uchar deviationValue;
};
static_assert(sizeof(AIPlayStatus) == 0x1C8, "Size mismatch");
