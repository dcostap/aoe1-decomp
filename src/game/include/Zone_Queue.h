#pragma once
#include "common.h"

struct Zone_Queue {
    long x;
    long y;
    Zone_Queue* next;
};
static_assert(sizeof(Zone_Queue) == 0xC, "Size mismatch");
