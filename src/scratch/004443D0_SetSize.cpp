// VA: 004443D0 TDrawArea::SetSize (675 B)
// PDB source: Drawarea.cpp
// Packet-grounded: EH-framed resize surface, re-allocate Bits, update SpanLists

extern void* operator_new(unsigned int size);
extern void operator_delete(void* p);
extern void* memset(void* s, int c, int n);
extern void* memcpy(void* dst, const void* src, int n);
extern int CreateSurface(void* self, int w, int h, int flags);
extern int Release(void* surface);

struct Shim_SetSize_43D0 {
    char gap00[0x08];
    unsigned char* Bits;       // +0x08
    char gap0C[0x0C];
    int Width;                 // +0x18
    int Height;                // +0x1C
    int Pitch;                 // +0x20
    int Orien;                 // +0x24
    int field_28;
    char gap2C[0x34 - 0x2C];
    int BitsPerPixel;          // +0x34
    char gap38[0x3C - 0x38];
    void* Surface;             // +0x3C
    char gap40[0x478 - 0x40];
    unsigned char surf_type;   // +0x478
};

int TDrawArea_SetSize(Shim_SetSize_43D0* self, int newW, int newH, int keepContent, int field_FC)
{
    // EH frame via FS:[0] expected
    
    // Guard: need a DD raw surface to work with
    // ...
    
    // Clamp dimensions to >= 1
    if (newW < 1) newW = 1;
    if (newH < 1) newH = 1;
    
    // Check if size actually changed
    if (newW == self->Width && newH == self->Height) {
        if (self->Surface)
            return 1;
    }
    
    // Store keepContent flag
    *(int*)((char*)self + 0xF8) = keepContent;
    
    // Update Bits+4 with new width
    *(int*)((char*)self->Bits + 4) = newW;
    
    // Check orientation for pitch calculation
    int pitch;
    if (self->Orien == 1) {
        pitch = newW;
    } else {
        pitch = -newW;
    }
    
    // Update pitch in Bits+8
    *(int*)((char*)self->Bits + 8) = pitch * self->BitsPerPixel / 8;
    
    // Store new dimensions
    self->Width = newW;
    self->Height = newH;
    self->Pitch = pitch * self->BitsPerPixel / 8;
    
    // Build DDSURFACEDESC and call CreateSurface
    // ...
    
    // If surf_type != 2 and we have a surface, release it
    if (self->surf_type != 2 && self->Surface) {
        Release(self->Surface);
        self->Surface = 0;
    }
    
    // If surf_type == 2 (video memory), re-create the surface
    // ...
    
    return 1;
}
