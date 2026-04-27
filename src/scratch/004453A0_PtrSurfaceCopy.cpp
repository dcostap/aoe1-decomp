// VA: 004453A0 TDrawArea::PtrSurfaceCopy (470 B)
// PDB source: Drawarea.cpp
// Packet-grounded: span-based surface copy with surface lock/unlock

extern void* Lock(void* surface, void* rect, int flags);
extern void Unlock(void* surface);
extern void* memcpy(void* dst, const void* src, int n);

struct Shim_PtrSurfaceCopy_53A0 {
    char gap00[0x08];
    unsigned char* Bits;       // +0x08
    char gap0C[0x18 - 0x0C];
    int Width;                 // +0x18
    int Height;                // +0x1C
    int Pitch;                 // +0x20
    int Orien;                 // +0x24
    char gap28[0xD0 - 0x28];
    void* CurSpanList;         // +0xD0
};

void TDrawArea_PtrSurfaceCopy(Shim_PtrSurfaceCopy_53A0* self, void* srcSurface, int srcW, int srcH, int srcPitch)
{
    if (!self->CurSpanList || !self->Bits || !srcSurface)
        return;
    
    // Lock source surface to get source bits
    // Lock(target_surface, 0, 1)
    
    // For each span in CurSpanList:
    //   left, right, y
    //   width = right - left + 1
    //   dst = Bits + y * Pitch + left
    //   src = srcBits + y * srcPitch + left
    //   memcpy(dst, src, width)
    
    // Orientation-aware addressing
    
    // Unlock source surface
}
