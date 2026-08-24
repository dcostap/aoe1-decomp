#ifndef AOE1_RGE_TSLC_CONTEXT_H
#define AOE1_RGE_TSLC_CONTEXT_H

#include <stdio.h>

extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);

class RGE_TimeSinceLastCall {
public:
    char TBuff[255];
    unsigned char _pad_0[1];
    unsigned long lowTSLC;
    unsigned long highTSLC;
    unsigned long TSLC;
    unsigned long aTSLC[101];
    int Offset;
    unsigned long LastCall;
    unsigned long FirstCall;
    unsigned long Now;
    unsigned long cps;

    RGE_TimeSinceLastCall();
    ~RGE_TimeSinceLastCall();
    unsigned long GetAvg(int count);
    unsigned long Get();
    unsigned long Set();
    void Skip();
    char* GetAvgInfo(int count);
    char* GetHiLoMaxInfo(int count);
    char* GetHiLoInfo(int count);
    unsigned long CPS();
    unsigned long GetFirstCall();
    char* GetElapsedFirstCall();
    void Test();
};

typedef char rge_tslc_context_size_check[
    (sizeof(RGE_TimeSinceLastCall) == 0x2B4) ? 1 : -1];

#endif
