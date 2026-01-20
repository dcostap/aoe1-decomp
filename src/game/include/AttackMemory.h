#pragma once
#include "common.h"

struct AttackMemory {
    int id;
    uchar type;
    uchar minX;
    uchar minY;
    uchar maxX;
    uchar maxY;
    uchar attackingOwner;
    uchar targetOwner;
    short kills;
    uchar success;
    ulong timeStamp;
    int play;
};
static_assert(sizeof(AttackMemory) == 0x18, "Size mismatch");
