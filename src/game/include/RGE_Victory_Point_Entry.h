#pragma once
#include "common.h"

struct RGE_Victory_Point_Entry {
    uchar command;
    uchar state;
    uchar id;
    uchar group;
    long attribute;
    long amount;
    long points;
    long curr_points;
    float curr_attribute_amount;
    RGE_Victory_Point_Entry* next;
};
static_assert(sizeof(RGE_Victory_Point_Entry) == 0x1C, "Size mismatch");
