#pragma once
#include "common.h"

struct UnitData {
    int id;
    int data1;
    int data2;
    int data3;
    int target;
    ulong lastTaskTime;
};
static_assert(sizeof(UnitData) == 0x18, "Size mismatch");
