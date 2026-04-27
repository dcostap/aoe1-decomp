// VA: 00444850 TDrawArea::PtrClear (308 B)
// PDB source: Drawarea.cpp
// Packet-grounded: span-based clear using CurSpanList, fill rows with memset

extern void* memset(void* s, int c, int n);

struct Shim_PtrClear_4850 {
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
    char gap38[0xD0 - 0x38];
    void* CurSpanList;         // +0xD0
};

void TDrawArea_PtrClear(Shim_PtrClear_4850* self, unsigned char color)
{
    if (!self->CurSpanList || !self->Bits)
        return;
    
    // Get span list data
    // CurSpanList->SpanData[...]
    // For each span in the list:
    //   left, right, y
    //   compute pixel address, memset
    
    // Orientation-aware addressing (top-down vs bottom-up)
    if (self->Orien == 1) {
        // Top-down: ptr = Bits + y * Pitch + left
        // For each row/span, memset with color
    } else {
        // Bottom-up: ptr = Bits + (Height - y - 1) * Pitch + left
    }
}
