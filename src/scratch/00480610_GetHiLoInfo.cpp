// VA: 00480610 RGE_TimeSinceLastCall::GetHiLoInfo
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

    char* GetHiLoInfo(int param_1);
};

char* RGE_TimeSinceLastCall::GetHiLoInfo(int param_1)
{
    unsigned long sum = 0;
    unsigned long hi = 0;
    unsigned long lo = 0xF423F;
    int idx;
    int c;
    int orig = param_1;

    if (param_1 > 0 && param_1 <= 100) {
        idx = Offset;
        c = param_1;
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
            c--;
        } while (c != 0);
        param_1 = sum / param_1;
    } else {
        lo = param_1;
        hi = param_1;
    }

    sprintf(TBuff, "Lo=%d < Avg=%d > Hi=%d of %d",
            lo, (int)(unsigned int)param_1, hi, orig);

    return TBuff;
}
