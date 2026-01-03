#pragma once
#include "../common.h"

class RGE_TimeSinceLastCall {
public:
    char TBuff[255];
    ulong lowTSLC;                           // 0x100
    ulong highTSLC;                          // 0x104
    ulong TSLC;                              // 0x108
    ulong aTSLC[101];                        // 0x10C
    int Offset;                              // 0x2A0
    ulong LastCall;                          // 0x2A4
    ulong FirstCall;                         // 0x2A8
    ulong Now;                               // 0x2AC
    ulong cps;                               // 0x2B0

    RGE_TimeSinceLastCall();
    ~RGE_TimeSinceLastCall();
    ulong GetAvg(int param_1);
    ulong Get();
    ulong Set();
    void Skip();
    char* GetAvgInfo(int param_1);
    char* GetHiLoMaxInfo(int param_1);
    char* GetHiLoInfo(int param_1);
    ulong CPS();
    ulong GetFirstCall();
    char* GetElapsedFirstCall();
    void Test();
};

static_assert(sizeof(RGE_TimeSinceLastCall) == 0x2B4, "RGE_TimeSinceLastCall Size Mismatch");
static_assert(offsetof(RGE_TimeSinceLastCall, cps) == 0x2B0, "RGE_TimeSinceLastCall Offset Mismatch");

