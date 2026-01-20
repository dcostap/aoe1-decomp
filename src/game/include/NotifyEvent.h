#pragma once
#include "common.h"

struct NotifyEvent {
    int caller;
    int recipient;
    int mType;
    long p1;
    long p2;
    long p3;
};
static_assert(sizeof(NotifyEvent) == 0x18, "Size mismatch");
