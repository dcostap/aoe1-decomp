// VA: 00445D20 TDrawArea::DrawBevel2 (284 B)
// PDB source: Drawarea.cpp:4144-4185
// Attempt log:
// - baseline candidate: natural four-color, two-inner-line bevel reconstructed
//   from the DrawBevel/DrawBevel21 same-TU family and original call sequence.
// - named inner-coordinate locals improved instruction-shape similarity but not
//   the frame/prologue; hoisting their declarations was codegen-identical.
// - reversed compare operands changed branch shape and was rolled back.
// - separate original-coordinate swap temporaries reached the best emitted
//   candidate (284-byte size, 274 positional bytes different); the y swap uses
//   the packet's observed y2=y1 / y1=old-y2 assignment order.
// - reverse temporary/assignment order and staged width/height arithmetic were
//   codegen regressions or duplicates; final source restored to the natural
//   typed form and left in scratch.
// - Session retested the DrawBevel21 direct-swap family, width/height widths,
//   parameter-home boundary locals, repeated arithmetic, and point-of-use
//   inner coordinates; none removed the frame or improved the canonical
//   validated source. Original call targets and color roles remain aligned.
// Main-agent audit confirmed the natural draw-area line ownership and retained
// the ordinary clipped bevel construction.

class TDrawArea {
public:
    void DrawHorzLine(long x, long y, long width, unsigned char color);
    void DrawVertLine(long x, long y, long height, unsigned char color);
    void DrawBevel2(long x1, long y1, long x2, long y2,
                    unsigned char c1, unsigned char c2,
                    unsigned char c3, unsigned char c4);
};

void TDrawArea::DrawBevel2(long x1, long y1, long x2, long y2,
                           unsigned char c1, unsigned char c2,
                           unsigned char c3, unsigned char c4)
{
    long original_x1;
    long original_y2;
    int width;
    int height;
    int x1_plus_one;
    int y1_plus_one;

    original_y2 = y2;
    original_x1 = x1;
    if (x1 > x2) {
        x1 = x2;
        x2 = original_x1;
    }
    if (y1 > y2) {
        y2 = y1;
        y1 = original_y2;
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
    DrawHorzLine(x1 + 2, y1_plus_one, width - 2, c2);
    DrawVertLine(x2 - 1, y1 + 2, height - 3, c2);
    DrawHorzLine(x1, y2, width, c4);
    DrawVertLine(x1, y1, height, c4);
    DrawHorzLine(x1_plus_one, y2 - 1, width - 1, c3);
    DrawVertLine(x1_plus_one, y1_plus_one, height - 2, c3);
}
