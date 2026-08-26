// VA: 00480610 RGE_TimeSinceLastCall::GetHiLoInfo (132 B)
// PDB source: RGE_TSLC.cpp lines 152-161.
// BINARY NOTE: The inner positive-count test gives the shipped branch layout.
// ORIGINAL BUG: Invalid counts read uninitialized output locals.
// The executable reads the input home for these output values.
// Initializing them changes both this behavior and the emitted code.

#include "../../include/rge_tslc_context.h"

char* RGE_TimeSinceLastCall::GetHiLoInfo(int param_1)
{
    int remaining;
    unsigned long sum = 0;
    unsigned long hi = 0;
    unsigned long min = 999999;
    unsigned long average;
    unsigned long out_hi;
    unsigned long out_lo;

    if (param_1 >= 1 && param_1 <= 100) {
        int idx = Offset;
        if (param_1 > 0) {
            remaining = param_1;
            do {
                idx--;
                if (idx <= 0)
                    idx = 100;
                unsigned long value = aTSLC[idx];
                sum += value;
                if (value < min)
                    min = value;
                if (value > hi)
                    hi = value;
                remaining--;
            } while (remaining != 0);
        }
        average = sum / (unsigned long)param_1;
        out_lo = min;
        out_hi = hi;
    }

    sprintf(TBuff, "Lo=%d < Avg=%d > Hi=%d of %d",
            out_lo, average, out_hi, param_1);
    return TBuff;
}
