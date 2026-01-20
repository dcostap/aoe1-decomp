#pragma once
#include "common.h"

struct RGE_TimeSinceLastCall {
    char TBuff[255];
    ulong lowTSLC;
    ulong highTSLC;
    ulong TSLC;
    ulong aTSLC[101];
    int Offset;
    ulong LastCall;
    ulong FirstCall;
    ulong Now;
    ulong cps;
};
static_assert(sizeof(RGE_TimeSinceLastCall) == 0x2B4, "Size mismatch");
