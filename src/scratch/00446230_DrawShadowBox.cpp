// VA: 00446230 TDrawArea::DrawShadowBox (271 B)
// PDB source: Drawarea.cpp
// Packet-grounded: draw 3D shadow box with bevel + shadow offset

extern int TDrawArea_FillRect(void* self, int x1, int y1, int x2, int y2, unsigned char color);
extern int TDrawArea_DrawBevel2(void* self, int x1, int y1, int x2, int y2, 
                                 unsigned char light, unsigned char dark);

struct Shim_DrawShadowBox_6230 {
    char gap00[0x08];
    unsigned char* Bits;       // +0x08
    char gap0C[0xC8 - 0x0C];
    int field_C8;              // +0xC8
};

void TDrawArea_DrawShadowBox(Shim_DrawShadowBox_6230* self, int x1, int y1, int x2, int y2,
                              unsigned char lightColor, unsigned char darkColor, unsigned char shadowColor)
{
    // Guard: need both Bits and field_C8 set
    if (!self->field_C8 || !self->Bits)
        return;
    
    // Draw the main bevel box
    TDrawArea_DrawBevel2(self, x1, y1, x2 - 2, y2 - 2, lightColor, darkColor);
    
    // Fill the shadow area (right side + bottom offset)
    // Shadow on right: 2 pixels wide
    TDrawArea_FillRect(self, x2 - 2, y1 + 2, x2, y2, shadowColor);
    
    // Shadow on bottom: 2 pixels tall
    TDrawArea_FillRect(self, x1 + 2, y2 - 2, x2 - 2, y2, shadowColor);
    
    // Corner shadow pixel
    // ...
}
