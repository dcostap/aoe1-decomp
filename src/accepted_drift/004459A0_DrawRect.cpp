// VA: 004459A0 TDrawArea::DrawRect (147 B)
// PDB source: Drawarea.cpp
// Draws a rectangle outline using DrawHorzLine and DrawVertLine
// ACCEPTED_DRIFT: 2-byte instruction scheduling swap at 3rd call site
//   Original: mov eax,[esp+28h]; mov ecx,edi (color loaded before this ptr)
//   Rebuilt:  mov ecx,edi; mov eax,[esp+28h] (this ptr restored before color)
//   Behavior: Identical. Both loads are independent and complete before push.
//   145/147 positional bytes match; 4 relocation-masked bytes.

struct TDrawArea_DrawRect {
    void DrawHorzLine(int x, int y, int w, unsigned char color);
    void DrawVertLine(int x, int y, int h, unsigned char color);
};

void __fastcall DrawRect(void* _this, int _, int x1, int y1, int x2, int y2, unsigned char color)
{
    TDrawArea_DrawRect* self = (TDrawArea_DrawRect*)_this;
    
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
    self->DrawHorzLine(x1, y1, w, color);
    self->DrawHorzLine(x1, y2, w, color);
    self->DrawVertLine(x1, y1, h, color);
    self->DrawVertLine(x2, y1, h, color);
}
