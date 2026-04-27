// VA: 00444D50 TDrawArea::Copy (865 B)
// PDB source: Drawarea.cpp
// Packet-grounded: copy surface with optional clip rect and transparent color

extern void* memcpy(void* dst, const void* src, int n);
extern int TDrawArea_PtrCopy(void* self, void* srcBits, int srcPitch);
extern int TDrawArea_OverlayMemCopy(void* self, int x, int y, void* srcBits, int srcW, int srcH, int srcPitch, unsigned char transparentColor);

struct Shim_Copy_4D50 {
    char gap00[0x08];
    unsigned char* Bits;       // +0x08
    char gap0C[0x0C];
    int Width;                 // +0x18
    int Height;                // +0x1C
    int Pitch;                 // +0x20
    int Orien;                 // +0x24
    char gap28[0xD0 - 0x28];
    void* CurSpanList;         // +0xD0
    char gapD4[0xEC - 0xD4];
    void* field_EC;            // +0xEC
    char gapF0[0xFC - 0xF0];
    unsigned char field_FC;    // +0xFC (transparent color or flag)
};

void TDrawArea_Copy(Shim_Copy_4D50* self, void* src, int x, int y, 
                    void* clipRect, unsigned char transparentColor)
{
    if (!self->Bits || !src)
        return;
    
    // Get source dimensions
    int srcW = *(int*)((char*)src + 0x18);   // src->Width
    int srcH = *(int*)((char*)src + 0x1C);   // src->Height
    void* srcBits = *(void**)((char*)src + 0x08);  // src->Bits
    int srcPitch = *(int*)((char*)src + 0x20);     // src->Pitch
    
    // Check source validity
    // ...
    
    // If no clipRect provided, use full destination surface
    int clipX, clipY, clipW, clipH;
    if (!clipRect) {
        clipW = self->Width;
        clipH = self->Height;
        clipX = 0;
        clipY = 0;
    } else {
        clipX = *(int*)((char*)clipRect + 0);
        clipY = *(int*)((char*)clipRect + 4);
        clipW = *(int*)((char*)clipRect + 8);
        clipH = *(int*)((char*)clipRect + 0x0C);
    }
    
    // Clip rect checking: compute source region to draw
    // x,y = position of source rect on destination
    // ...
    
    // Check if EC field is set (span-based copy)
    if (self->field_EC) {
        // Use overlay method with transparency
        // ...
    } else {
        // Use direct span copy via PtrCopy
        // ...
    }
}
