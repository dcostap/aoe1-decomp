// VA: 00445E40 TDrawArea::DrawBevel3 (404 B)
// PDB source: Drawarea.cpp
// Packet-grounded: 3-line bevel with outer/mid/inner light/dark lines

extern int TDrawArea_FillRect(void* self, int x1, int y1, int x2, int y2, unsigned char color);

void TDrawArea_DrawBevel3(void* self, int x1, int y1, int x2, int y2,
                           unsigned char lightColor, unsigned char darkColor)
{
    // Normalize coordinates
    if (x1 > y1) { int t = x1; x1 = y1; y1 = t; }
    if (x2 > y2) { int t = x2; x2 = y2; y2 = t; }
    
    int w = y1 - x1 + 1;
    int h = y2 - x2 + 1;
    if (w < 3 || h < 3) return;
    
    // Outer bevel lines
    // Light outer top
    TDrawArea_FillRect(self, x1, x1, y1, x1, lightColor);
    // Light outer left
    TDrawArea_FillRect(self, x1, x2, x1, y2, lightColor);
    
    // Dark outer bottom
    TDrawArea_FillRect(self, x1, y1, y1, y1, darkColor);
    // Dark outer right
    TDrawArea_FillRect(self, y1, x2, y1, y2, darkColor);
    
    // Middle bevel lines (offset by 1)
    TDrawArea_FillRect(self, x1+1, x1+1, y1-1, x1+1, lightColor);
    TDrawArea_FillRect(self, x1+1, x2+1, x1+1, y2-1, lightColor);
    TDrawArea_FillRect(self, x1+1, y1-1, y1-1, y1-1, darkColor);
    TDrawArea_FillRect(self, y1-1, x2+1, y1-1, y2-1, darkColor);
    
    // Inner bevel lines (offset by 2)
    TDrawArea_FillRect(self, x1+2, x1+2, y1-2, x1+2, lightColor);
    TDrawArea_FillRect(self, x1+2, x2+2, x1+2, y2-2, lightColor);
    TDrawArea_FillRect(self, x1+2, y1-2, y1-2, y1-2, darkColor);
    TDrawArea_FillRect(self, y1-2, x2+2, y1-2, y2-2, darkColor);
}
