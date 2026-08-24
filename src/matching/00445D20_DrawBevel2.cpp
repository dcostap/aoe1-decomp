// VA: 00445D20 TDrawArea::DrawBevel2 (284 B)
// PDB source: Drawarea.cpp:4144-4185
// Attempt log:
// - baseline candidate: natural four-color, two-inner-line bevel reconstructed
//   from the DrawBevel/DrawBevel21 same-TU family and original call sequence.
// - named inner-coordinate locals improved instruction-shape similarity but not
//   the frame/prologue; hoisting their declarations was codegen-identical.
// - reversed compare operands changed branch shape and was rolled back.
// - separate original-coordinate swap temporaries reached the best emitted
//   candidate (284-byte size, 274 positional bytes different); that old
//   candidate had an incorrect y swap and was not retained.
// - reverse temporary/assignment order and staged width/height arithmetic were
//   codegen regressions or duplicates; final source restored to the natural
//   typed form and left in scratch.
// - Session retested the DrawBevel21 direct-swap family, width/height widths,
//   parameter-home boundary locals, repeated arithmetic, and point-of-use
//   inner coordinates; none removed the frame or improved the canonical
//   validated source. Original call targets and color roles remain aligned.
// - This session retested the decompiler-supported difference arithmetic,
//   nested positive guards, and reduced local sets; these shortened bytes but
//   worsened prologue/CFG shape. The audited source below is restored.
// - This session retested direct DrawBevel21-style swaps, a single persistent
//   x1+1 local, behavior-correct block-local swaps, and register width/height;
//   all worsened or duplicated the 293-byte/274-difference clean result.
// - Final plausibility audit removed the unconditional original-coordinate
//   copies; each normalization now uses the ordinary block-local swap form.
// - Blind semantic review corrected the y swap and the five inner-line spans:
//   call3 width-3, call4 height-4, call6 height-1, call7 width-2, and
//   call8 height-3. The eight asm-verified pairs are H(x1+1,y1,w-1,c1),
//   V(x2,y1+1,h-2,c1), H(x1+2,y1+1,w-3,c2), V(x2-1,y1+2,h-4,c2),
//   H(x1,y2,w,c4), V(x1,y1,h-1,c4), H(x1+1,y2-1,w-2,c3), and
//   V(x1+1,y1+1,h-3,c3).
// Main-agent audit confirmed the natural draw-area line ownership and retained
// the ordinary clipped bevel construction.

#ifndef DRAWAREA_CANONICAL_TU
class TDrawArea {
public:
    void DrawHorzLine(long x, long y, long width, unsigned char color);
    void DrawVertLine(long x, long y, long height, unsigned char color);
    void DrawBevel2(long x1, long y1, long x2, long y2,
                    unsigned char c1, unsigned char c2,
                    unsigned char c3, unsigned char c4);
};
#endif

void TDrawArea::DrawBevel2(long x1, long y1, long x2, long y2,
                           unsigned char c1, unsigned char c2,
                           unsigned char c3, unsigned char c4)
{
    int width;
    int height;
    int x1_plus_one;
    int y1_plus_one;

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

    width = x2 - x1 + 1;
    if (width < 1)
        return;
    height = y2 - y1 + 1;
    if (height < 1)
        return;

    x1_plus_one = x1 + 1;
    DrawHorzLine(x1_plus_one, y1, width - 1, c1);
    y1_plus_one = y1 + 1;
    DrawVertLine(x2, y1_plus_one, height - 2, c1);
    DrawHorzLine(x1 + 2, y1_plus_one, width - 3, c2);
    DrawVertLine(x2 - 1, y1 + 2, height - 4, c2);
    DrawHorzLine(x1, y2, width, c4);
    DrawVertLine(x1, y1, height - 1, c4);
    DrawHorzLine(x1_plus_one, y2 - 1, width - 2, c3);
    DrawVertLine(x1_plus_one, y1_plus_one, height - 3, c3);
}
