// VA: 00480480 Set
// VA: 00480570 GetHiLoMaxInfo
// VA: 00480610 GetHiLoInfo
// VA: 004806D0 GetElapsedFirstCall
// PDB source: RGE_TSLC.cpp

#include <stdio.h>

extern "C" unsigned long __cdecl debug_timeGetTime(char* file, int line);
extern "C" int __cdecl timeGetTime();

class RGE_TimeSinceLastCall {
public:
    char TBuff[0x100];       // +0x000: sprintf output buffer
    unsigned long lowTSLC;   // +0x100
    unsigned long highTSLC;  // +0x104
    unsigned long TSLC;      // +0x108: current delta
    unsigned long aTSLC[100];// +0x10C: rolling buffer of last 100 values
    int Offset;              // +0x2A0: buffer index (0-99)
    unsigned long LastCall;  // +0x2A4: previous timeGetTime value

    unsigned long Set();
    char* GetHiLoMaxInfo(int param_1);
    char* GetHiLoInfo(int param_1);
    unsigned long GetElapsedFirstCall();
};

unsigned long RGE_TimeSinceLastCall::Set()
{
    unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\RGE_TSLC.cpp", 0x5D);
    unsigned long prev = LastCall;

    if (prev == now)
        return 0;

    LastCall = now;
    TSLC = now - prev;

    int idx = Offset + 1;
    Offset = idx;
    if (idx > 100)
        Offset = 0;

    aTSLC[Offset] = TSLC;

    unsigned long t = TSLC;
    if (t < lowTSLC)
        lowTSLC = t;
    if (t > highTSLC)
        highTSLC = t;

    return t;
}

char* RGE_TimeSinceLastCall::GetHiLoMaxInfo(int param_1)
{
    unsigned long sum = 0;
    unsigned long hi = 0;
    unsigned long lo = 0xF423F; // 999999
    int idx;

    if (param_1 >= 1 && param_1 <= 100) {
        idx = Offset;
        for (int i = 0; i < param_1; i++) {
            idx--;
            if (idx < 1)
                idx = 100;
            unsigned long val = aTSLC[idx];
            sum += val;
            if (val < lo)
                lo = val;
            if (val > hi)
                hi = val;
        }
        param_1 = sum / param_1;
    }

    sprintf(TBuff, "(LoLo %d) Lo=%d < Avg=%d / %d > Hi=%d  (HiHi %d)",
            lowTSLC, lo, param_1, (int)(unsigned int)???, hi, highTSLC);

    return TBuff;
}

char* RGE_TimeSinceLastCall::GetHiLoInfo(int param_1)
{
    // Same structure but different format string
    unsigned long sum = 0;
    unsigned long hi = 0;
    unsigned long lo = 0xF423F;
    int idx;

    if (param_1 >= 1 && param_1 <= 100) {
        idx = Offset;
        for (int i = 0; i < param_1; i++) {
            idx--;
            if (idx < 1)
                idx = 100;
            unsigned long val = aTSLC[idx];
            sum += val;
            if (val < lo)
                lo = val;
            if (val > hi)
                hi = val;
        }
        param_1 = sum / param_1;
    }

    sprintf(TBuff, "(Lo %d) Lo=%d < Avg=%d / %d > Hi=%d  (Hi %d)",
            lowTSLC, lo, param_1, ???, hi, highTSLC);

    return TBuff;
}

unsigned long RGE_TimeSinceLastCall::GetElapsedFirstCall()
{
    unsigned long now = timeGetTime();
    unsigned long prev = LastCall;

    if (prev == 0) {
        LastCall = now;
        return 0;
    }

    TSLC = now - prev;
    LastCall = now;
    return TSLC;
}
