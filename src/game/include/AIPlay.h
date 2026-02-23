#pragma once
#include "common.h"

#include "AIPlayGroup.h"
#include "AIPlayPhase.h"

struct AIPlay {
    char nameValue[65];
    uchar minimumNumberUnitsValue;
    uchar maximumNumberUnitsValue;
    uchar typeValue;
    uchar targetTypeValue[5];
    uchar targetCharacteristicValue[5];
    uchar powerValue;
    uchar overflowValue;
    uchar intelligenceValue;
    uchar deathPercentageValue;
    uchar numberGroupsValue;
    AIPlayGroup groups[5];
    AIPlayPhase phases[10];
};
static_assert(sizeof(AIPlay) == 0x608, "Size mismatch");
