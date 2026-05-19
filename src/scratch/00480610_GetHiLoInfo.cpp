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
// Retry 2026-05-19 assigned pass:
// try 12: register original/sum/hi/lo with val split; no change from 128B stack-home basin.
// try 13: explicit self local for this to encourage EDI=this; no change, compiler kept EBX=this.
// try 14: declaration-order swaps for original/sum/hi/self; no change.
// try 15: /O2 without /Oy; no change, flag removed.
// try 16: decompiler-shaped avg/out_hi initialized to param; no change from 128B basin.
// GIVEUP: exact validation still cannot compare because rebuilt .text is 128B vs configured 132B. Remaining structural mismatch is register/stack allocation: rebuilt saves extra ECX/local slot, uses EBX=this and EBP=sum/stack hi, original uses EDI=this, EBP=original count, EAX=sum, EBX=hi and reuses incoming param slot as loop counter. Not accepted_drift.

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
    int original = param_1;
    unsigned long sum = 0;
    unsigned long hi = 0;
    unsigned long lo = 0xF423F;
    unsigned long avg = param_1;
    unsigned long out_hi = param_1;

    if (0 < param_1 && param_1 < 0x65) {
        int idx = Offset;
        if (0 < param_1) {
            do {
                idx--;
                if (idx < 1)
                    idx = 100;
                out_hi = aTSLC[idx];
                sum = sum + out_hi;
                if (out_hi < lo)
                    lo = out_hi;
                if (hi < out_hi)
                    hi = out_hi;
                param_1 = param_1 - 1;
            } while (param_1 != 0);
        }
        avg = sum / (unsigned int)original;
        out_hi = hi;
    }

    sprintf(TBuff, "Lo=%d < Avg=%d > Hi=%d of %d",
            lo, avg, out_hi, original);
    return TBuff;
}
