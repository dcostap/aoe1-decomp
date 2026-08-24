// VA: 00445FE0 TDrawArea::DrawBevel21 (223 B)
// PDB source: Drawarea.cpp
// Packet-grounded: 3-color bevel frame; normalizes (x1,x2) and (y1,y2),
// guards on width/height, then draws 6 lines via DrawHorzLine/DrawVertLine.
// Color args: c1=param5, c2=param6, c3=param7 (unused in binary), c4=param8.
// Source family mirrors matched sibling 00445C70 DrawBevel.

#ifndef DRAWAREA_CANONICAL_TU
class TDrawArea {
public:
    void DrawHorzLine(long x, long y, long width, unsigned char color);
    void DrawVertLine(long x, long y, long height, unsigned char color);
    void DrawBevel21(long x1, long y1, long x2, long y2,
                     unsigned char c1, unsigned char c2,
                     unsigned char c3, unsigned char c4);
};
#endif

void TDrawArea::DrawBevel21(long x1, long y1, long x2, long y2,
                            unsigned char c1, unsigned char c2,
                            unsigned char c3, unsigned char c4)
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

    long width = x2 - x1 + 1;
    if (width < 1)
        return;
    long height = y2 - y1 + 1;
    if (height < 1)
        return;

    DrawHorzLine(x1 + 1, y1, width - 1, c1);
    DrawVertLine(x2, y1 + 1, height - 2, c1);
    DrawHorzLine(x1 + 1, y1 + 1, width - 2, c2);
    DrawVertLine(x2 - 1, y1 + 2, height - 3, c2);
    DrawHorzLine(x1, y2, width, c4);
    DrawVertLine(x1, y1, height - 1, c4);
}
