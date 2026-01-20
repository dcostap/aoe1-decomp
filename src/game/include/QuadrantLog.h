#pragma once
#include "common.h"

struct QuadrantLog {
    int numberExploredTiles;
    int numberAttacksOnUs;
    int numberAttacksByUs;
};
static_assert(sizeof(QuadrantLog) == 0xC, "Size mismatch");
