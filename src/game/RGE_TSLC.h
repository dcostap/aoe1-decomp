#pragma once
#include "../common.h"

class RGE_TimeSinceLastCall {
public:
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
    virtual ~RGE_TimeSinceLastCall();
    virtual ulong GetAvg(int param_1);
    virtual ulong Get();
    virtual ulong Set();
    virtual void Skip();
    virtual char* GetAvgInfo(int param_1);
    virtual char* GetHiLoMaxInfo(int param_1);
    virtual char* GetHiLoInfo(int param_1);
    virtual ulong CPS();
    virtual ulong GetFirstCall();
    virtual char* GetElapsedFirstCall();
    virtual void Test();
};

static_assert(sizeof(RGE_TimeSinceLastCall) == 0x2B4, "RGE_TimeSinceLastCall Size Mismatch");
static_assert(offsetof(RGE_TimeSinceLastCall, cps) == 0x2B0, "RGE_TimeSinceLastCall Offset Mismatch");

