// VA: 00480570 RGE_TimeSinceLastCall::GetHiLoMaxInfo
// PDB source: RGE_TSLC.cpp

#include <stdio.h>

class RGE_TimeSinceLastCall {
public:
    char TBuff[0x100];
    unsigned long lowTSLC;
    unsigned long highTSLC;
    unsigned long TSLC;
    unsigned long aTSLC[100];
    char gap_29C_29F[4];
    int Offset;
    unsigned long LastCall;
    unsigned long FirstCall;
    unsigned long Now;

    char* GetHiLoMaxInfo(int param_1);
};

char* RGE_TimeSinceLastCall::GetHiLoMaxInfo(int param_1)
{
    unsigned long sum = 0;
    unsigned long hi = 0;
    unsigned long lo = 0xF423F;
    int idx;
    int count = param_1;

    if (param_1 >= 1 && param_1 <= 100) {
        idx = Offset;
        do {
            idx--;
            if (idx < 1)
                idx = 100;
            unsigned long val = aTSLC[idx];
            sum += val;
            if (val < lo)
                lo = val;
            if (val > hi)
                hi = val;
            param_1--;
        } while (param_1 != 0);
        param_1 = sum / count;
    } else {
        lo = param_1;
        hi = param_1;
    }

    sprintf(TBuff, "(LoLo %d) Lo=%d < Avg=%d / %d > Hi=%d  (HiHi %d)",
            lowTSLC, lo, (int)(unsigned int)param_1, count, hi, highTSLC);

    return TBuff;
}
