#pragma once
#include "common.h"

struct AttackState {
    int bestTargetID;
    float bestTargetValue;
    int bestTargetMemoryIndex;
    int iterationIndex;
    int attackGroupID;
    int playID;
    uchar phase;
    int bestNonWallTargetID;
    float bestNonWallTargetValue;
    int bestNonWallTargetMemoryIndex;
    int active;
};
static_assert(sizeof(AttackState) == 0x2C, "Size mismatch");
