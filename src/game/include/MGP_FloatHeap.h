#pragma once
#include "common.h"

struct MGP_FloatHeap {
    uchar x;
    uchar y;
    ushort next;
    int total;
};
static_assert(sizeof(MGP_FloatHeap) == 0x8, "Size mismatch");
