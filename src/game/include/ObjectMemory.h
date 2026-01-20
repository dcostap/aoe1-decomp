#pragma once
#include "common.h"

struct ObjectMemory {
    int id;
    short type;
    short group;
    uchar x;
    uchar y;
    uchar z;
    uchar owner;
    short hitPoints;
    int attackAttempts;
    uchar kills;
    float damageCapability;
    float rateOfFire;
    float range;
};
static_assert(sizeof(ObjectMemory) == 0x24, "Size mismatch");
