#pragma once
#include "common.h"

struct OrderEvent {
    int issuer;
    int orderType;
    int priority;
    int target;
    int targetOwner;
    float targetX;
    float targetY;
    float targetZ;
    float range;
};
static_assert(sizeof(OrderEvent) == 0x24, "Size mismatch");
