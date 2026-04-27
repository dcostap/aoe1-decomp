// VA: 004460C0 TDrawArea::DrawBevel32 (341 B)
// PDB source: Drawarea.cpp
// Packet-grounded: 3-2 bevel (different dimensions than DrawBevel21)

extern int TDrawArea_FillRect(void* self, int x1, int y1, int x2, int y2, unsigned char color);
extern int TDrawArea_DrawLine(void* self, int x1, int y1, int x2, int y2, unsigned char color);

void TDrawArea_DrawBevel32(void* self, int x1, int y1, int x2, int y2, 
                            unsigned char lightColor, unsigned char darkColor)
{
    // Normalize coordinates
    if (x1 > y1) { int t = x1; x1 = y1; y1 = t; }
    if (x2 > y2) { int t = x2; x2 = y2; y2 = t; }
    
    int w = y1 - x1 + 1;
    int h = y2 - x2 + 1;
    if (w < 1 || h < 1) return;
    
    // Outer light frame (top + left, offset from edges)
    TDrawArea_FillRect(self, x1+1, x1, y1-1, x1, lightColor);       // top
    TDrawArea_FillRect(self, x1, x2, x1, y2-1, lightColor);         // left
    
    // Outer dark frame (bottom + right, offset from edges)
    TDrawArea_FillRect(self, x1, y1-1, y1-2, y1-1, darkColor);      // bottom
    TDrawArea_FillRect(self, y1-1, x2+2, y1-1, y2-2, darkColor);    // right
    TDrawArea_FillRect(self, y1-2, x2+1, y1-2, y2-1, darkColor);    // right-inner
    
    // Inner light accent
    TDrawArea_FillRect(self, x1+2, x1+2, y1-3, x1+2, lightColor);   // top-inner
    TDrawArea_FillRect(self, x1+2, x2+2, x1+2, y2-3, lightColor);   // left-inner
    
    // Inner dark accent
    TDrawArea_FillRect(self, x1+2, y1-3, y1-3, y1-3, darkColor);    // bottom-inner
    TDrawArea_FillRect(self, y1-3, x2+2, y1-3, y2-3, darkColor);    // right-inner
}
