// VA: 004450C0 TDrawArea::PtrCopy (395 B)
// PDB source: Drawarea.cpp
// Packet-grounded: span-based row copy using CurSpanList

extern void* memcpy(void* dst, const void* src, int n);

struct Shim_PtrCopy_50C0 {
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

void TDrawArea_PtrCopy(Shim_PtrCopy_50C0* self, void* srcBits, int srcPitch)
{
    if (!self->CurSpanList || !self->Bits || !srcBits)
        return;
    
    // For each span in CurSpanList:
    //   left, right, y
    //   width = right - left + 1
    //   dst = Bits + y * Pitch + left  (or bottom-up adjusted)
    //   src = srcBits + y * srcPitch + left
    //   memcpy(dst, src, width)
    
    // Orientation check: if both are same orientation, direct copy
    // If different, adjust y for source
}
