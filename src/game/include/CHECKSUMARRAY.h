#pragma once
#include "common.h"

struct CHECKSUMARRAY {
    uint PlayerNo;
    ulong WTime;
    ulong WTurn;
    long cs1;
    long cs2;
    long cs3;
    long cs4;
    long cs5;
    uint Random;
};
static_assert(sizeof(CHECKSUMARRAY) == 0x24, "Size mismatch");
