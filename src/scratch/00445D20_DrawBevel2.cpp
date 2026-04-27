// VA: 00445D20 TDrawArea::DrawBevel2 (284 B)
// PDB source: Drawarea.cpp
// Packet-grounded: draw 2-line bevel (light on top/left, dark on bottom/right)

extern int TDrawArea_FillRect(void* self, int x1, int y1, int x2, int y2, unsigned char color);

struct Shim_DrawBevel2_5D20 {
    char gap00[0x28];
    int ClipLeft;
    int ClipTop;
    int ClipRight;
    int ClipBottom;
};

void TDrawArea_DrawBevel2(Shim_DrawBevel2_5D20* self, int x1, int y1, int x2, int y2,
                           unsigned char lightColor, unsigned char darkColor)
{
    // Normalize coordinates: ensure x1 <= y1, x2 <= y2
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
    if (x1 > self->ClipRight || y1 < self->ClipLeft ||
        x2 > self->ClipBottom || y2 < self->ClipTop)
        return;
    
    if (x1 < self->ClipLeft) x1 = self->ClipLeft;
    if (y1 > self->ClipRight) y1 = self->ClipRight;
    if (x2 < self->ClipTop) x2 = self->ClipTop;
    if (y2 > self->ClipBottom) y2 = self->ClipBottom;
    
    // Clip and compute dimensions
    int width = y1 - x1 + 1;
    int height = y2 - x2 + 1;
    
    if (width < 2 || height < 2)
        return;
    
    // Draw light top line
    TDrawArea_FillRect(self, x1, x1, y1 - 1, x1, lightColor);
    
    // Draw light left line
    TDrawArea_FillRect(self, x1, x2, x1, y2 - 1, lightColor);
    
    // Draw dark bottom line
    TDrawArea_FillRect(self, x1, y1 - 1, y1, y1, darkColor);
    
    // Draw dark right line
    TDrawArea_FillRect(self, y1 - 1, x2, y1 - 1, y2, darkColor);
}
