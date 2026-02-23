#pragma once
#include "common.h"

struct RGE_TimeSinceLastCall {
    RGE_TimeSinceLastCall();
    ~RGE_TimeSinceLastCall();

    ulong GetAvg(int sample_count);
    ulong Get();
    ulong Set();
    void Skip();
    char* GetAvgInfo(int sample_count);
    char* GetHiLoMaxInfo(int sample_count);
    char* GetHiLoInfo(int sample_count);
    ulong CPS();
    ulong GetFirstCall();
    char* GetElapsedFirstCall();
    void Test();

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
