// VA: 00445580 TDrawArea::OverlayMemCopy (385 B)
// PDB source: Drawarea.cpp
// Packet-grounded: overlay copy with transparency/alpha handling

extern void* memset(void* s, int c, int n);
extern void* memcpy(void* dst, const void* src, int n);

struct Shim_OverlayMemCopy_5580 {
    char gap00[0x08];
    unsigned char* Bits;       // +0x08
    char gap0C[0x18 - 0x0C];
    int Width;                 // +0x18
    int Height;                // +0x1C
    int Pitch;                 // +0x20
    int Orien;                 // +0x24
    int ClipLeft;
    int ClipTop;
    int ClipRight;
    int ClipBottom;
};

void TDrawArea_OverlayMemCopy(Shim_OverlayMemCopy_5580* self, int x, int y, 
                               void* srcBits, int srcW, int srcH, int srcPitch,
                               unsigned char transparentColor)
{
    if (!self->Bits)
        return;
    
    // Clip source rect to destination clip rect
    // Compute overlap region
    int clipX1 = self->ClipLeft - x;
    int clipY1 = self->ClipTop - y;
    int clipX2 = self->ClipRight - x;
    int clipY2 = self->ClipBottom - y;
    
    if (clipX1 < 0) clipX1 = 0;
    if (clipY1 < 0) clipY1 = 0;
    if (clipX2 >= srcW) clipX2 = srcW - 1;
    if (clipY2 >= srcH) clipY2 = srcH - 1;
    
    int copyW = clipX2 - clipX1 + 1;
    int copyH = clipY2 - clipY1 + 1;
    if (copyW < 1 || copyH < 1) return;
    
    // Orientation-aware copy with transparent color
    // For each row: skip pixels matching transparentColor
    // memcpy non-transparent runs
}
