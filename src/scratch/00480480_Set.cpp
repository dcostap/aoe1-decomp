// VA: 00480480 RGE_TimeSinceLastCall::Set
// PDB source: RGE_TSLC.cpp lines 90-113. Default flags, no inline asm.
// Attempt log:
// inherited baseline: exact size 141B but MISMATCH 98 positional / 41 edit bytes; VC5 chooses EDX for LastCall and shorter tail with NOP padding.
// try 1: reordered source to LastCall store, diff temp, Offset, then TSLC to match original scheduling; worsened slightly (102 positional / 42 edit).
// try 2: register-qualified prev/diff/idx locals; no useful register change.
// try 3: compare directly against this->LastCall before naming prev; no change.
// try 4: volatile LastCall field; no useful change.
// try 5: register-qualified now with natural decompiler order; returned to best baseline-ish family (98 positional / 41 edit).
// try 6: swapped equality expression to now == prev; changed cmp operand order but still EDX prev and worse family.
// try 7: /O1 probe: 133B too short, removed.
// try 8: /O2 /Os probe: 133B too short, removed.
// 2026-05-19 later pass:
// try 9: non-register now + register prev/diff and explicit diff-=prev before TSLC; no improvement, 102 positional / 42 edit.
// try 10: idx++ split from Offset load; same worse family.
// try 11: direct field compare before prev local; same worse family.
// Boss retry 2026-05-19:
// try 12: direct field compare then late prev/diff local; still EDX prev, 102 positional.
// try 13: register prev/idx; no allocation change from try 12.
// try 14: ++this->Offset form got desired ECX prev and first mismatch moved to +33, but used
//         EAX for diff, EDX for offset, shorter 128B tail; not kept.
// try 15: register diff / separate Offset store probes fell into same 128B/short-tail family.
// Rolled back to exact-size baseline as best scratch state.
// GIVEUP: current best below is behaviorally straightforward and exact-size, but original keeps previous LastCall in ECX, copies now to EDX for delta, preserves a longer load/store schedule, and has no NOP padding; rebuilt keeps previous LastCall in EDX/uses ECX for delta or offset depending source. Not proposing accepted_drift because drift spans register allocation, index update schedule, aTSLC store source, and final length/padding.
// Retry 2026-05-20 Boss pass: revalidated baseline (141B, 69.50% positional, 29.08% edit, first mismatch 16). Tried decompiler order without register now, diff-before-store, explicit delta copy, LastCall reference local, unsigned idx/direct minmax, result local, member ++Offset, volatile now/prev combinations, raw byte-offset field access, and direct min/max assignments. Best edit-only variant was LastCall reference (26.95% edit) but positional worsened and still used wrong register/schedule; many variants compiled to shorter .text or worsened with stack spills. No improvement over exact-size baseline.
// Retry 2026-05-21 Boss pass: re-tested schedule-focused variants: `t=now` before/after LastCall
// store, reference `LastCall` plus saved old value, member `++Offset`, volatile Offset, `return TSLC`,
// direct min/max assignments, and unsigned index. The member `++Offset` family still gets the original
// ECX previous-LastCall and first mismatch +33, but collapses to a 128-byte body with NOP padding and
// wrong offset/delta register schedule. Other variants return to the exact-size baseline family with
// previous LastCall in EDX. Leaving in scratch; diff is broad, not accepted_drift-worthy.

extern "C" unsigned long __cdecl debug_timeGetTime(char* file, int line);

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

    unsigned long Set();
};

unsigned long RGE_TimeSinceLastCall::Set()
{
    unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\RGE_TSLC.cpp", 0x5D);
    unsigned long& prev = this->LastCall;
    if (prev == now) return 0;
    unsigned long old = prev;
    unsigned long t = now;
    prev = now;
    t -= old;
    this->TSLC = t;
    int idx = this->Offset + 1;
    this->Offset = idx;
    if (idx > 100) this->Offset = 0;
    this->aTSLC[this->Offset] = this->TSLC;
    t = this->TSLC;
    unsigned long v = this->lowTSLC;
    if (t < v) v = t;
    this->lowTSLC = v;
    v = this->highTSLC;
    if (t > v) v = t;
    this->highTSLC = v;
    return t;
}
