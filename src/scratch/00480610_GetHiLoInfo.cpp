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
// Retry 2026-05-20 assigned pass:
// try 17: simple param-count source with no avg/out_hi locals; still 128B too small.
// try 18: count local plus explicit param_1=count before do-loop to model incoming stack slot as countdown; still 128B.
// try 19: register param_1/count variant with --param_1 loop; still 128B.
// try 20: decompiler-shaped source with explicit invalid-path lo/avg/out_hi reset; still 128B.
// try 21: reduced to only count/sum/hi/lo locals and reused sum as avg; still 128B.
// try 22: declaration order sum/hi/count/lo; still 128B.
// try 23: declaration order hi/count/sum/lo; still 128B.
// try 24: declaration order count/hi/sum/lo; still 128B.
// try 25: /O1 /Oy flag probe produced wrong 123B family; removed flag.
// try 26: /Od /Oy produced 132B but completely wrong unoptimized EBP-frame family (128 positional diff); removed flag.
// try 27: /O2 /Oy /Gf and /Og flag probes did not change the 128B family; removed flags.
// GIVEUP: exact validation still cannot compare because rebuilt .text is 128B vs configured 132B. Remaining structural mismatch is register/stack allocation: rebuilt saves extra ECX/local slot, uses EBX=this and EBP=sum/stack hi, original uses EDI=this, EBP=original count, EAX=sum, EBX=hi and reuses incoming param slot as loop counter. Not accepted_drift.
// Retry 2026-05-21 Boss pass: 18 more probes. Tried simpler invalid-path source, explicit param-slot countdown, for-local countdown, register locals, raw this+offset array access (only 132B variant, but broad 88.6364% mismatch from byte 0), explicit stack-lvalue invalid reads, self local, exact decompiler-shaped variables, no-inner-if do loop, unsigned range test, plus flags /G5 /Gr /Gz /Ob0 /Og /Gf /Os /O1. All source/flag variants either stayed the 128B too-small family or regressed badly; none reached the original EDI=this/EBP=count/EAX=sum/EBX=hi/param-slot-countdown register topology. Leaving in scratch; no accepted_drift because size/register/stack topology mismatch is structural.
// Retry 2026-05-24 Boss pass: 20 more probes. Revalidated current source still emits only 128B, so checker cannot byte-compare against 132B original. Tried decompiler-exact variable topology, separate invalid-path assignments, register-qualified params/locals, self alias first, volatile param-slot countdown (only 132B compareable source, but 92.42% positional from byte 0), while/predec and for-countdown loops, split/nested range compares, raw this+offset array accesses, extern sprintf, hardcoded format address, unsigned index, mutating param_1 as idx, late avg/out_hi assignments, lo/hi/sum declaration reorders, equivalent compare operand swaps, removed inner guard, and flags /G3 /G4 /GB /Ox /Ow /Ot /Oi /GX. Every non-volatile source/flag stayed in the same 128B too-small family; volatile stack-slot source regressed badly. No accepted_drift: still a structural size/register/stack-topology mismatch, not localized benign drift.
// Retry 2026-05-26 Boss pass: 16 more probes. Revalidated current source still emits 128B vs original 132B (checker stops before byte compare). Tried register parameter/original, direct param-as-count, count-local without param mutation, avg-as-accumulator, minimal/no avg-out_hi locals, while/predec loop, no-original-local form, declaration orders hi/sum/lo/original, const/split/orig-last original, register all locals, and equivalent range nesting. All stayed in the same stable 128B basin: push ecx scratch, EDI=this, EBX=sum, EBP=hi, original count homed at [esp+10h], div [esp+10h]. Original remains push ebx/push ebp first, EBP=original count, EAX=sum, EBX=hi, incoming param stack slot reused as countdown, div ebp. GIVEUP: no accepted_drift because the mismatch is still function-size plus register/stack-topology structural drift, not a localized benign difference.

// Retry 2026-08-02 Luna-480610 (10 probes): exact class surface and unsigned-int
// locals were codegen-duplicate. Distinguishing invalid-path low output from the
// valid minimum reached the original 132-byte boundary; >=1/<=100 and explicit
// idx>0 spellings recovered most loop CFG shape. Reusing param_1 as countdown and
// average, with one min/output local plus invalid fallback, gave the best stable
// basin: 124 meaningful bytes (128 extracted), 73.21% shape, 51.85% exact-block
// coverage, 126 strict diff bytes; call target/site parity is exact. Remaining
// structural mismatch is register allocation: rebuilt loads param before saves,
// keeps sum in EBX and max in the incoming home; original loads count into EBP
// after initial saves, keeps sum in EAX/max in EBX, and uses the incoming home as
// countdown. Declaration/register-order and max-compare probes did not alter it.
// PAUSED: no accepted_drift; remaining register/stack topology is broad.

// Retry 2026-08-03 Luna480610: sibling-derived local ABI hypothesis; use
// unsigned long accumulators matching the validated RGE_TSLC sibling source,
// while retaining the natural formal-count source shape.

// probe 4 behavior/control-flow: do not initialize the valid-loop value from
// the parameter before the prologue; assign invalid-path min/max explicitly so
// the executable's three fallback pushes remain direct parameter reads.

// Probe 5 (rolled back): delaying original-count assignment widened the
// prologue; retain original-first declaration order.
// Probe 6: swap sum/max declaration order under the sibling's unsigned-long
// local surface to test the EAX=sum/EBX=max coloring directly.

// Probe 7: sibling-shaped countdown/average lifetime; keep formal param
// unchanged for divisor/final format and reuse remaining for both countdown
// and valid average, with value scoped to the loop body.
// Probe 8: focused value-surface lab found the direct hi output form preserves
// the 132-byte basin; a separate value local regressed to the 126-byte family.
// Probe 9: corrected/repeated lab (2 natural forms, size/call-set gated) found
// no exact variant; direct form remains best, first mismatch is countdown-home
// placement at +22. The failed first lab expansion was only a template repair.
// Final bounded state: exact call target/site parity and canonical element-100
// layout are retained; remaining drift is parameter-home scheduling plus the
// quotient/output tail. Not accepted_drift because the block drift is structural.

// Retry 2026-08-03 Luna480610b (10 probes): a 48-case home/tail lab found no
// exact variant; its metric-best diagnostic family moved the countdown initialization into
// the positive inner guard and forced invalid-arm stack rereads with narrow
// volatile casts: 132 bytes, 11 strict diff bytes, 87.04% exact blocks, and
// exact call/relocation parity. That fake-volatility form was not retained. A volatile invalid assignment,
// duplicated sprintf arms, and a register-qualified output-high temporary were
// rolled back (the last emitted 138-byte family did expose the missing
// pre-divisor ECX copy but added stack-tail loads). The natural canonical source
// below was restored for validation; the diagnostic proves the remaining axis is
// pre-divisor/invalid-arm scheduling, not a missing semantic operation. Main-agent
// validation after restoration: 132/132 bytes, 65 strict diff, 87.50% shape,
// exact call parity.
// Main-agent normalization before semantic review: removed the redundant
// param_1>0 guard already proved by the 1..100 range and replaced the empty
// positive idx branch with the natural `if (idx <= 0) idx = 100` wrap.

#include <stdio.h>

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

    char* GetHiLoInfo(int param_1);
};

char* RGE_TimeSinceLastCall::GetHiLoInfo(int param_1)
{
    int remaining;
    unsigned long sum = 0;
    unsigned long hi = 0;
    unsigned long min = 999999;
    remaining = param_1;
    if (param_1 >= 1 && param_1 <= 100) {
        int idx = Offset;
        do {
            idx = idx - 1;
            if (idx <= 0)
                idx = 100;
            unsigned long value = aTSLC[idx];
            sum = sum + value;
            if (value < min)
                min = value;
            if (value > hi)
                hi = value;
            remaining = remaining - 1;
        } while (remaining != 0);
        remaining = sum / (unsigned long)param_1;
    } else {
        min = remaining;
        hi = remaining;
    }
    sprintf(TBuff, "Lo=%d < Avg=%d > Hi=%d of %d",
            min, remaining, hi, param_1);
    return TBuff;
}
