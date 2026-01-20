#pragma once
#include "common.h"

struct BuildingLot {
    int typeID;
    uchar status;
    uchar x;
    uchar y;
};
static_assert(sizeof(BuildingLot) == 0x8, "Size mismatch");
