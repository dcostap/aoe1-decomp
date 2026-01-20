#pragma once
#include "common.h"

struct Attribute_Cost {
    short type;
    short amount;
    uchar flag;
};
static_assert(sizeof(Attribute_Cost) == 0x6, "Size mismatch");
