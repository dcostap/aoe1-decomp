#pragma once
#include "common.h"

struct ResourceMemory {
    int id;
    uchar x;
    uchar y;
    uchar gatherAttempts;
    int gatherValue;
    uchar valid;
    uchar gone;
    uchar dropDistance;
    uchar resourceType;
    int dropsiteID;
};
static_assert(sizeof(ResourceMemory) == 0x14, "Size mismatch");
