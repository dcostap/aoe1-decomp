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

class TDrawArea {
public:
    void DrawHorzLine(long x, long y, long width, unsigned char color);
    void DrawVertLine(long x, long y, long height, unsigned char color);
    void DrawBevel32(long x1, long y1, long x2, long y2,
                     unsigned char c1, unsigned char c2,
                     unsigned char c3, unsigned char c4,
                     unsigned char c5, unsigned char c6);
};

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

    if (x2 - x1 + 1 >= 1 && y2 - y1 + 1 >= 1) {
        long inner_x;
        inner_x = x1 + 1;
        DrawHorzLine(inner_x, y1, x2 - x1, c1);
        DrawVertLine(x2, y1 + 1, y2 - y1, c1);
        DrawHorzLine(x1 + 2, y1 + 1, x2 - x1 - 1, c2);
        DrawVertLine(x2 - 1, y1 + 2, y2 - y1 - 2, c2);
        DrawHorzLine(x1 + 2, y1 + 2, x2 - x1 - 2, c3);
        DrawVertLine(x2 - 2, y1 + 3, y2 - y1 - 3, c3);
        DrawHorzLine(x1, y2, x2 - x1 + 1, c6);
        DrawVertLine(x1, y1, y2 - y1 + 1, c6);
        DrawHorzLine(inner_x, y2 - 1, x2 - x1, c5);
        DrawVertLine(inner_x, y1 + 1, y2 - y1 - 1, c5);
    }
}
