#pragma once
#include "common.h"

struct RESENDER {
    ulong TimeSent;
    uint Serial;
    char* ResendMsg;
    uint Length;
    uint DestMap[10];
};
static_assert(sizeof(RESENDER) == 0x38, "Size mismatch");
