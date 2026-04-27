// VA: 00445FE0 TDrawArea::DrawBevel21 (223 B)
// PDB source: Drawarea.cpp
// Packet-grounded: 2-tier bevel rectangle draw with light/dark shadow colors

extern int TDrawArea_FillRect(void* self, int x1, int y1, int x2, int y2, unsigned char color);

struct Shim_DrawBevel21_5FE0 {
    char gap00[0x28];
    int ClipLeft;
    int ClipTop;
    int ClipRight;
    int ClipBottom;
};

void TDrawArea_DrawBevel21(Shim_DrawBevel21_5FE0* self, int x1, int y1, int x2, int y2, 
                            unsigned char lightColor, unsigned char darkColor)
{
    // Normalize coordinates
    if (x1 > y1) {
        int temp = x1;
        x1 = y1;
        y1 = temp;
    }
    
    if (x2 > y2) {
        int temp = x2;
        x2 = y2;
        y2 = temp;
    }
    
    // Clip to clip rect
    // ...
    
    // Draw outer bevel (light on top/left, dark on bottom/right)
    // Draw inner bevel (reversed or different colors)
    
    // Outer top-left light lines
    TDrawArea_FillRect(self, x1, x1, y1, x1, lightColor);     // top
    TDrawArea_FillRect(self, x1, x1, x1, y2, lightColor);     // left
    
    // Outer bottom-right dark lines
    TDrawArea_FillRect(self, x1, y1, y1, y1, darkColor);      // bottom
    TDrawArea_FillRect(self, y1, x1, y1, y2, darkColor);      // right
    
    // Inner bevel
    // ...
}
