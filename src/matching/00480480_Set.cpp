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
// Retry 2026-05-24 Boss pass: 10 more probes. Revalidated baseline (141B, 69.5035% positional / 29.0780% edit). Tried ++Offset family again (first mismatch +32, edit 25.5319% but short real body/NOP tail and wrong delta/index registers), explicit `t=now; t=t-old`, direct field compare/no reference, register now, volatile LastCall (first mismatch +33, best edit 21.9858% but reloads LastCall after branch and shifts store/compare order), register old, and /Ob0 flag (no change, removed). No retained exact improvement: either baseline EDX-prev family or the ECX-prev/short-tail family. Not accepted_drift because drift spans LastCall register allocation, delta/index update scheduling, aTSLC store source, and function length/tail padding.
// Retry 2026-05-26 Boss pass: 18 more probes. Revalidated exact-size baseline first
// (141B, 69.5035% positional / 29.0780% edit, first mismatch +16). Tried old-before-if,
// register/const/signed old types, diff-before-store, explicit delta/copy locals, comma
// store, raw byte-offset LastCall/Offset access, old reference, idx declared early, postinc
// member Offset family, local idx array store, ternary/direct minmax, volatile now/delta/old,
// and store-order variants. The only deeper first-mismatch family is still member Offset++:
// it matches through +33 and gets ECX=old, but uses EAX for delta, EDX for Offset, emits a
// short real body with NOP tail, and worsens edit diff. Restored baseline; no accepted_drift
// because drift is still broad register/schedule/length mismatch rather than localized drift.

// 2026-08-02 Luna-480480: rebuilt baseline and claimed the target with the full
// generated class surface. A 36-variant source lab held size/frame/call-set constant;
// its best group used a named diff before the LastCall store and a fresh TSLC reload
// local (91 positional / 38 edit bytes), retained below. A pre-guard copied-time
// liveness variant collapsed to a 125-byte direct-update family (103 positional / 31
// edit), so it was rolled back. Remaining drift is broad: VC5 loads old LastCall into
// EDX rather than original ECX, computes delta in ECX rather than original EDX, and
// shifts the Offset/TSLC schedule while leaving a NOP tail.

// 2026-08-03 Luna480480: canonical-layout retry used the required full
// TBuff[255]+pad / TSLC / aTSLC[101] / Offset(+2A0) surface throughout. Direct
// TSLC-before-LastCall, preincrement Offset, old-before-guard, saved-now, and
// mutable-delta source-shape probes did not improve the emitted family. A
// 180-variant focused lab (all size/call-set valid) found no exact result; its
// closest edit group was a diagnostic direct-delta family (88 positional / 15
// edit, first mismatch +40) with a broad register/schedule mismatch, so it was
// not retained. Restored the clean best source below: 141B, 91 positional / 38
// edit, original call-set/frame/size parity; remaining drift is old LastCall
// register color, delta/index scheduling, and the padded tail. No accepted drift.
// 2026-08-03 Luna480480b: a focused 135-variant core lab found exact bytes with
// TSLC assigned before LastCall and a post-increment member Offset++ (the named
// idx form was not exact). Exact candidate retained below; validate before move.

#include "../../include/rge_tslc_context.h"

unsigned long RGE_TimeSinceLastCall::Set()
{
    unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\RGE_TSLC.cpp", 0x5D);
    if (this->LastCall == now) return 0;
    unsigned long old = this->LastCall;
    this->TSLC = now - old;
    this->LastCall = now;
    this->Offset++;
    if (this->Offset > 100) this->Offset = 0;
    this->aTSLC[this->Offset] = this->TSLC;
    unsigned long t = this->TSLC;
    unsigned long v = this->lowTSLC;
    if (t < v) v = t;
    this->lowTSLC = v;
    v = this->highTSLC;
    if (t > v) v = t;
    this->highTSLC = v;
    return t;
}
