// VA: 00445E40 TDrawArea::DrawBevel3 (404 B)
// PDB source: Drawarea.cpp:4191-4240
// Attempt log:
// - Replaced the placeholder FillRect reconstruction with the binary-proven
//   six-color DrawHorzLine/DrawVertLine bevel sequence and exact __thiscall ABI.
// - Block-local x/y swap temporaries restored the Drawarea sibling prologue and
//   normalization blocks; the difference fell from 386 to 341 bytes.
// - Inclusive width/height locals with the observed -1..-6 line spans produced
//   the exact 404-byte function; source remains ordinary typed Drawarea code.

class TDrawArea {
public:
    void DrawHorzLine(long x, long y, long width, unsigned char color);
    void DrawVertLine(long x, long y, long height, unsigned char color);
    void DrawBevel3(long x1, long y1, long x2, long y2,
                    unsigned char c1, unsigned char c2,
                    unsigned char c3, unsigned char c4,
                    unsigned char c5, unsigned char c6);
};

void TDrawArea::DrawBevel3(long x1, long y1, long x2, long y2,
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

    int x1_plus_one = x1 + 1;
    DrawHorzLine(x1_plus_one, y1, width - 1, c1);
    int y1_plus_one = y1 + 1;
    DrawVertLine(x2, y1_plus_one, height - 2, c1);
    int x1_plus_two = x1 + 2;
    DrawHorzLine(x1_plus_two, y1_plus_one, width - 3, c2);
    int y1_plus_two = y1 + 2;
    DrawVertLine(x2 - 1, y1_plus_two, height - 4, c2);
    DrawHorzLine(x1 + 3, y1_plus_two, width - 5, c3);
    DrawVertLine(x2 - 2, y1 + 3, height - 6, c3);
    DrawHorzLine(x1, y2, width, c6);
    DrawVertLine(x1, y1, height - 1, c6);
    DrawHorzLine(x1_plus_one, y2 - 1, width - 2, c5);
    DrawVertLine(x1_plus_one, y1_plus_one, height - 3, c5);
    DrawHorzLine(x1_plus_two, y2 - 2, width - 4, c4);
    DrawVertLine(x1_plus_two, y1_plus_two, height - 5, c4);
}
