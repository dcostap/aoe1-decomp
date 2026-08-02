// VA: 00480570 RGE_TimeSinceLastCall::GetHiLoMaxInfo
// PDB: RGE_TSLC.cpp lines 139-148
// Default flags: /nologo /c /O2 /Oy
// Size: 146 bytes original, 144 bytes rebuilt
//
// Attempt log (20 attempts):
//
// Attempt 17/18/19 was best: 144 bytes (98.6% of original), 2 bytes short.
// Match quality breakdown vs original:
//   ✓ Register allocation: eax=sum, ebx=sum(alt), ebp=count, edi=lo, edx=idx
//   ✓ idx wrap check: test edx,edx; jg (matches original encoding)
//   ✓ Vtable/field offsets: Offset (+0x2A0=672), aTSLC (+0x10C=268), 
//     lowTSLC (+0x100=256), highTSLC (+0x104=260)
//   ✓ sprintf arg order matches (highTSLC, hi, count, avg, lo, lowTSLC, fmt, this)
//   ✓ Bounds checks: cmp 1, jl exit; cmp 100, jg exit
//   ✓ if(param_1>0) guard with test/jle before loop
//   ✓ do-while(param_1!=0) with dec; jne at loop bottom
//   ✓ div ebp for unsigned division (sum/count)
//
// Remaining 2-byte difference (stable across all attempts):
//
// Issue 1 — hi on stack vs. ebx register:
//   Original: xor ebx,ebx (hi in ebx)
//   Rebuilt:  xor ecx,ecx; mov [esp+N],ecx (hi on stack)
//   Root cause: int count = param_1; at function scope allocates ebp for
//   count, pushing hi to the stack. Removing count causes param_1 to use 
//   ebx instead of ebp, breaking the div ebp / ebp preservation pattern.
//   
// Issue 2 — Counter not stored to param_1 stack slot:
//   Original: mov [esp+14h],ebp (store counter); mov ecx,[esp+14h]; dec ecx;
//             mov [esp+14h],ecx; jne (load/dec/store in loop)
//   Rebuilt:  dec eax; jne (register-only counter)
//   Root cause: VC5 optimizes the counter into register (eax) instead of
//   storing to the param_1 stack slot. This saves 8 bytes.
//   
// Net: hi-on-stack adds ~6 bytes, counter-in-register saves ~8 bytes →
// 2 bytes shorter overall.
//
// These are stable VC5 codegen decisions — the compiler chooses register-only
// counter tracking and allocates hi to stack when count needs ebp. No source
// rearrangement tested (20 variants) changed this allocation.
//
// Not suitable for accepted_drift — 2 bytes shorter means different binary
// structure, not localized drift.
//
// Left in scratch with best attempt (count=param_1 first, separate inits).
// Boss retry 2026-05-19: revalidated best attempt still 144B text for 146B target.
// Tried volatile counter pointer plus register hi to force stack-slot dec/store and EBX hi; it
// produced exact size but with push-ecx stack home, sum in EBX, hi on stack, and 93.15% positional
// drift. Rolled back to known best 144B source.
// Retry 2026-05-20: 11 additional probes: explicit param_1=count before loop, volatile param dec,
// pointer-to-param counter, temp assignment, while/for loop forms, hi-before-count and count-after-inits
// declaration orders, volatile formal, register formal. The only exact-size variants were broad
// regressions (82.9-90.4% positional), while all close variants stayed 144B/2 bytes short.
// GIVEUP: remaining blocker is still the stable VC5 choice between stack-slot parameter countdown
// and register-only loop/count/hi allocation. Not accepted_drift: exact-size variants reorder the
// whole function badly, and the best close form is structurally 2 bytes short.
// Retry 2026-05-21 Boss pass: tried condition on `count` vs `param_1`, delayed count assignment,
// `register count`, separate `avg` local, inline avg expression, named `hiArg`, volatile write back
// to `param_1`, unsigned count, `while` loop form, and separate `n` countdown local. Close families
// remain 144B/2 bytes short; exact-size variants spill/push ecx or move count to EBX/EBP differently
// and drift broadly. Rolled back to prior 144B close source; no accepted_drift proposal.
// Retry 2026-05-24 Boss pass: 10 more probes. Revalidated current close source still 144B for 146B target. Tried `register count`, declaration order hi/count changes, const count, volatile formal (exact-size but 82.8767% positional and broad prologue/tail drift), `int& count = param_1` (128B), decompiler-natural body, removing avg local, condition on count, explicit `param_1=count`, and volatile/nonvolatile return locals. Best close families remain 144B/2 bytes short; exact-size variants are broad regressions. Leaving prior close source. Not accepted_drift: structural size/codegen-family mismatch, not localized benign drift.
// Retry 2026-05-26 Boss pass: 18 probes on VA 00480570 only. Revalidated close source: still 144B for 146B target. Tried condition on `count`, `hiArg`/`hi2` before div, avg local, delayed count declaration, separate countdown `n` (exact-size but 90.4110% positional), volatile count copy, `<101`/nested bounds, `(char*)this` sprintf/return, dummy after div, else hi/lo order, init-order changes, and flag probes /G5 /Og /Oa /Ow /Ob0 /Oy- /O1 /Zp1. All close variants stayed 144B/2 bytes short; exact-size variants were broad prologue/register regressions. GIVEUP: not accepted_drift quality; remaining mismatch is structural size/codegen-family (stack-slot countdown vs register allocation), not a localized benign hunk.

// Retry 2026-08-02 Luna-480570: current checker baseline is 140 effective bytes
// versus 146 original (the padded extraction is 144 bytes). Ten bounded probes
// were recorded: signed local widths, declaration/initialization order, parameter
// home pointer, delayed count assignment, count-vs-parameter guards, direct
// parameter countdown, register-qualified accumulators, and natural initializers.
// All retained/nearby variants emitted the same 140-byte family; no probe restored
// the original EBP parameter-home countdown or EAX/EBX sum/high coloring. Final
// state remains the best 140-byte source; structural mismatch is not accepted drift.
//
// Retry 2026-08-03 Luna480570: canonical-layout reset. Ground-truth type evidence
// proves TBuff[255] plus one padding byte, lowTSLC/highTSLC/TSLC at +100/+104/+108,
// aTSLC[101] at +10C through +29F, and Offset at +2A0. The indexed loop can read
// element 100, so the old aTSLC[100] plus gap model was discarded before new probes.
// Probe 2026-08-03: best clean source so far uses the formal count as the
// preserved divisor/format value and a separate natural remaining-count local
// for the scan; it reaches the original prologue and loop register basin.
// The branch-local store placement variant was rolled back: it changed the
// prologue to an EBX-count/stack-home family and widened the structural drift.
// The direct-formal-countdown variant returned to the old 140-byte family.
// A focused three-case source lab confirmed this formal-remaining form as the
// best plausible basin: 144 extracted bytes versus 146 original, 78 strict
// diff bytes, exact call-set parity; scoped-count forms regressed broadly.
// Remaining mismatch is structural: the natural remaining local is homed at
// [esp+14h] before the bounds branches and is written as the average after div,
// whereas the oracle homes the countdown after the positive guard and keeps the
// quotient in EAX. No exact or accepted-drift result was found.

#include <stdio.h>

class RGE_TimeSinceLastCall {
public:
    char TBuff[255];
    unsigned char TBuff_pad;
    unsigned long lowTSLC;      // +0x100
    unsigned long highTSLC;     // +0x104
    unsigned long TSLC;         // +0x108
    unsigned long aTSLC[101];   // +0x10C (101*4 = 0x194, ends at 0x2A0)
    int Offset;                 // +0x2A0
    unsigned long LastCall;     // +0x2A4
    unsigned long FirstCall;    // +0x2A8
    unsigned long Now;          // +0x2AC
    unsigned long cps;          // +0x2B0

    char* GetHiLoMaxInfo(int param_1);
};

char* RGE_TimeSinceLastCall::GetHiLoMaxInfo(int param_1)
{
    int remaining;
    unsigned long sum;
    unsigned long hi;
    unsigned long lo;
    sum = 0;
    hi = 0;
    lo = 0xF423F;

    remaining = param_1;

    if (param_1 >= 1 && param_1 <= 100) {
        int idx = this->Offset;
        if (remaining > 0) {
            do {
                idx--;
                if (idx <= 0)
                    idx = 100;
                unsigned long val = this->aTSLC[idx];
                sum += val;
                if (val < lo)
                    lo = val;
                if (val > hi)
                    hi = val;
                remaining--;
            } while (remaining != 0);
        }
        remaining = sum / (unsigned long)param_1;
    } else {
        lo = remaining;
        hi = remaining;
    }

    sprintf(this->TBuff,
        "(LoLo %d) Lo=%d < Avg=%d / %d > Hi=%d  (HiHi %d)",
        this->lowTSLC, lo, (unsigned long)remaining, param_1, hi, this->highTSLC);

    return this->TBuff;
}
