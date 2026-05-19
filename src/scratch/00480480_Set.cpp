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
// GIVEUP: current best below is behaviorally straightforward and exact-size, but original keeps previous LastCall in ECX, copies now to EDX for delta, preserves a longer load/store schedule, and has no NOP padding; rebuilt keeps previous LastCall in EDX/uses ECX for delta or offset depending source. Not proposing accepted_drift because drift spans register allocation, index update schedule, aTSLC store source, and final length/padding.

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
    register unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\RGE_TSLC.cpp", 0x5D);
    unsigned long prev = this->LastCall;
    if (prev == now) return 0;
    this->LastCall = now;
    this->TSLC = now - prev;
    int idx = this->Offset + 1;
    this->Offset = idx;
    if (idx > 100) this->Offset = 0;
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
