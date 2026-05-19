// VA: 00480610 RGE_TimeSinceLastCall::GetHiLoInfo (132 B)
// PDB source: RGE_TSLC.cpp lines 152-161
// Attempt log:
// retry 2026-05-19 target-only:
// try 1: inherited baseline failed before compare because rebuilt .text is 128B vs original configured 132B.
// try 2: rewrote loop to use param_1 as the countdown and keep original count separately; still 128B.
// try 3: changed avg initialization/invalid path to mirror original fallback pushes; still 128B.
// try 4: added register hints to sum/hi/lo; no size/codegen improvement.
// try 5: /Ob0 flag probe; no change, removed flag.
// try 6: tried while(param_1--) loop form; no improvement, rolled back to do/countdown shape.
// try 7: split original declaration/assignment; no improvement.
// 2026-05-19 later pass:
// try 8: register original / non-register sum-hi-lo declaration order; no improvement from best 128B basin.
// try 9: decompiler-shaped uVar source using param_1 as loop variable and explicit avg/hi/lo outputs; reached 132B but broad regression with extra stack home, wrong saved registers, and wrong accumulator register.
// try 10: declaration order with register hi/sum/lo before original; same broad 132B regression.
// try 11: explicit extern sprintf instead of <stdio.h>; no codegen change.
// GIVEUP: current object remains 128B, blocking byte compare. Dumpbin shows behaviorally close loop/sprintf shape but VC5 keeps sum in EBX and hi in a stack slot, with pre-push parameter load, while original uses EAX=sum, EBX=hi, EBP=original count, and the incoming param stack slot as loop counter. Not accepted_drift: register/stack topology and function-size mismatch are structural.

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
    int original;
    original = param_1;
    register unsigned long sum = 0;
    register unsigned long hi = 0;
    register unsigned long lo = 0xF423F;
    int idx;
    int avg;

    if (original >= 1 && original <= 100) {
        idx = Offset;
        if (original > 0) {
            param_1 = original;
            do {
                idx--;
                if (idx <= 0)
                    idx = 100;
                unsigned long val = aTSLC[idx];
                sum += val;
                if (val < lo)
                    lo = val;
                if (val > hi)
                    hi = val;
                param_1--;
            } while (param_1 != 0);
        }
        avg = sum / original;
    } else {
        avg = param_1;
        lo = param_1;
        hi = param_1;
    }

    sprintf(TBuff, "Lo=%d < Avg=%d > Hi=%d of %d",
            lo, avg, hi, original);

    return TBuff;
}
