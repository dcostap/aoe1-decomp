// VA: 004459A0 TDrawArea::DrawRect (147 B)
// PDB source: Drawarea.cpp
// Draws a rectangle outline using DrawHorzLine and DrawVertLine

typedef void (__fastcall* HorzLineFn)(void* self, int _, int x, int y, int w, unsigned char color);
typedef void (__fastcall* VertLineFn)(void* self, int _, int x, int y, int h, unsigned char color);

void __fastcall DrawRect(void* _this, int _, int x1, int y1, int x2, int y2, unsigned char color)
{
    // Ensure x1 <= x2
    if (x1 > x2) {
        int tmp = x1;
        x1 = x2;
        x2 = tmp;
    }
    
    // Ensure y1 <= y2
    if (y1 > y2) {
        int tmp = y1;
        y1 = y2;
        y2 = tmp;
    }
    
    int w = x2 - x1 + 1;
    if (w < 1)
        return;
    
    int h = y2 - y1 + 1;
    if (h < 1)
        return;
    
    // Draw rectangle outline
    ((HorzLineFn)0x00445A60)(_this, 0, x1, y1, w, color);
    ((HorzLineFn)0x00445A60)(_this, 0, x1, y2, w, color);
    ((VertLineFn)0x00445AF0)(_this, 0, x1, y1, h, color);
    ((VertLineFn)0x00445AF0)(_this, 0, x2, y1, h, color);
}
