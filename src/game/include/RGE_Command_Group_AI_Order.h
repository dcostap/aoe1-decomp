#pragma once
#include "common.h"

struct RGE_Command_Group_AI_Order {
    uchar command;
    uchar player_id;
    uchar issuer;
    uchar recipient_count;
    short orderType;
    uchar orderPriority;
    int target;
    uchar targetOwner;
    float targetX;
    float targetY;
    float targetZ;
    float range;
    uchar immediate;
    uchar inFront;
};
static_assert(sizeof(RGE_Command_Group_AI_Order) == 0x24, "Size mismatch");
