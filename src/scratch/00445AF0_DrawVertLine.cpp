// VA: 00445AF0 TDrawArea::DrawVertLine (143 B)
// PDB source: Drawarea.cpp
// Draws a vertical line clipped to the clip rect
// Attempt log:
// Retry 2026-05-19 target-only:
// try 1: revalidated inherited source: exact size 143B, MISMATCH 86 positional bytes / 60.14%, edit diff 85B; behavior close but register allocation differs (rebuilt uses EBP=Bits, EBX=x, EDI=h; original uses EBX=Bits, EDI=x, EBP=h).
// try 2: introduced explicit `bits` local and used it in address expressions; no codegen change.
// try 3: added register locals for x/h to force x/h into desired registers; this did put Bits in EBX but introduced early param preload and worse layout (92.31% positional), rolled back.
// GIVEUP: remaining mismatch is broad register-allocation/scheduling for the same clipped vertical-line behavior. Original wants EBX=Bits loaded before saving EBP, EDI=x, EDX=y, EBP=h, ESI=pitch/clip temp; rebuilt persists in a different register basin. Not proposing accepted_drift because positional drift is broad.
// Retry 2026-05-19/20 assigned pass:
// - Revalidated default baseline: exact size 143B, 60.1399% positional / 59.4406% edit, first mismatch +1; behavior still close but EBX/EBP/EDI allocation differs.
// - Explicit `bits` local in retained source did not alter codegen versus inherited baseline.
// - `register` bits/pitch produced no codegen change.
// - /Ob0 and /G5 flag probes produced no codegen change; flags removed.
// - Reversing compare spellings for top/bottom clipping worsened slightly (60.8392% positional) and was rolled back.
// - Introducing a separate `len` local for h forced early parameter preload and worse 92.3077% positional; rolled back.
// - /O1 with the len-style basin was size-short/wrong prologue; rejected and flag removed.
// Boss retry 2026-05-19: revalidated baseline (86/143 positional, first mismatch +1).
// - Removing the explicit bits local optimized to identical baseline.
// - register rx/rh locals forced Bits into EBX, but introduced early h preload, worse 132/143
//   positional and wrong scheduling; rolled back.
// Retry 2026-05-20 assigned pass:
// - Revalidated baseline: exact size 143B, 86 positional / 85 edit, first mismatch +1.
// - Tried no bits local and register bits local; no change from baseline.
// - Tried parameter-mutation source with explicit bottom/top locals; no improvement.
// - Tried function-scope xx/yy/hh locals and register variants; yy/hh forms worsened badly, x forms no change.
// - Tried duplicated per-orientation loops and do-loop/for-loop variants; duplicated loops destroyed layout, do/for did not improve.
// - Tried raw-offset field accesses; no change from baseline.
// - Breakthrough: removed the shared pitch local and used direct this->Pitch in each orientation arm with a separate step variable; this matched the prologue/Bits/x clipping exactly and reduced diff to 32 positional / 35 edit, first mismatch +31.
// - Tried register-y signature, yy locals, top/bottom locals, inverted top compare, end local, parameter-slot/color no-op, and h+y term order; none improved the remaining +31 register-coloring hunk.
// Left in scratch: best source is exact size and behavior-equivalent but still mismatches in y/top/step register allocation and equivalent address/add ordering. Not promoting; possible accepted_drift only if reviewer accepts moderate register-coloring drift.

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea {
public:
    char gap_00[0x08];
    unsigned char* Bits;       // +0x08
    char gap_0C[0x10];
    int Height;                // +0x1C
    int Pitch;                 // +0x20
    int Orien;                 // +0x24
    tagRECT ClipRect;          // +0x28

    void DrawVertLine(long x, long y, long h, unsigned char color);
};

void TDrawArea::DrawVertLine(long x, long y, long h, unsigned char color)
{
    unsigned char* bits = this->Bits;
    if (bits == 0) return;
    if (x < this->ClipRect.left || x > this->ClipRect.right) return;
    if (y > this->ClipRect.bottom) return;
    if (y < this->ClipRect.top) { h += y - this->ClipRect.top; y = this->ClipRect.top; }
    if (y + h - 1 > this->ClipRect.bottom) h = this->ClipRect.bottom - y + 1;
    if (h < 1) return;
    unsigned char* dest; int step;
    if (this->Orien == 1) { dest = bits + y * this->Pitch + x; step = this->Pitch; }
    else { dest = bits + (this->Height - y - 1) * this->Pitch + x; step = -this->Pitch; }
    while (h > 0) { *dest = color; dest += step; h--; }
}
