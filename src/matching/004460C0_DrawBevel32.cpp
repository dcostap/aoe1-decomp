// VA: 004460C0 TDrawArea::DrawBevel32 (341 B)
// PDB source: Drawarea.cpp, lines 4293-4342
//
// Attempt log:
// - Replaced the generated FillRect/DrawLine shim with the same-TU
//   DrawHorzLine/DrawVertLine bevel source family used by DrawBevel21.
//   The sixth color is used for the outer bottom/right pair; c4 is unused by
//   the original binary.
// - Natural swap-local, inner-coordinate, direct-arithmetic, and combined
//   guard probes preserved all ten ordered calls but did not recover the
//   original VC5 liveness basin. The worker exhausted its context after seven
//   hypotheses; the main agent retained this canonical direct-arithmetic form
//   and closed the lease at 293 differing bytes and exact 341-byte size.
// - Fresh pass: corrected the inner line extents to the executable's
//   decompiler-supported raw differences (the prior retained candidate was
//   one pixel too wide/tall on the inner c1/c2/c3/c5 paths).  The natural
//   typed source now emits 341 bytes/138 instructions and 286 differing bytes.
// - Repeated x1+1 source expressions emit the observed -4 spill just like an
//   explicit inner_x local, so the living source keeps the clearer direct form.
// - Reversed normalization predicates, decompiler-style y swapping, and a
//   0 < (difference + 1) guard were tested and rolled back.  Two focused
//   expression labs found a plus-one spelling with a deeper first mismatch,
//   but it remained nonexact and compiler-steering rather than plausible source;
//   it was not promoted into the function.
// - Natural DrawBevel3-family int width/height locals preserved the executable
//   raw extents and recovered the exact first prologue hunk and full 341-byte
//   function.  This source remains ordinary typed Drawarea code.

#ifndef DRAWAREA_CANONICAL_TU
class TDrawArea {
public:
    void DrawHorzLine(long x, long y, long width, unsigned char color);
    void DrawVertLine(long x, long y, long height, unsigned char color);
    void DrawBevel32(long x1, long y1, long x2, long y2,
                     unsigned char c1, unsigned char c2,
                     unsigned char c3, unsigned char c4,
                     unsigned char c5, unsigned char c6);
};
#endif

void TDrawArea::DrawBevel32(long x1, long y1, long x2, long y2,
                            unsigned char c1, unsigned char c2,
                            unsigned char c3, unsigned char c4,
                            unsigned char c5, unsigned char c6)
{
    if (x1 > x2) {
        long temp = x1;
        x1 = x2;
        x2 = temp;
    }
    if (y1 > y2) {
        long temp = y1;
        y1 = y2;
        y2 = temp;
    }

    int width = x2 - x1 + 1;
    if (width < 1)
        return;
    int height = y2 - y1 + 1;
    if (height < 1)
        return;

    DrawHorzLine(x1 + 1, y1, width - 1, c1);
    DrawVertLine(x2, y1 + 1, height - 2, c1);
    DrawHorzLine(x1 + 2, y1 + 1, width - 3, c2);
    DrawVertLine(x2 - 1, y1 + 2, height - 4, c2);
    DrawHorzLine(x1 + 2, y1 + 2, width - 4, c3);
    DrawVertLine(x2 - 2, y1 + 3, height - 5, c3);
    DrawHorzLine(x1, y2, width, c6);
    DrawVertLine(x1, y1, height - 1, c6);
    DrawHorzLine(x1 + 1, y2 - 1, width - 2, c5);
    DrawVertLine(x1 + 1, y1 + 1, height - 3, c5);
}
