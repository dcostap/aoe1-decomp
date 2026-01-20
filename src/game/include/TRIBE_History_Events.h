#pragma once
#include "common.h"

struct TRIBE_History_Events {
    uchar event;
    long time;
    long world_time;
    TRIBE_History_Events* next;
};
static_assert(sizeof(TRIBE_History_Events) == 0x10, "Size mismatch");
