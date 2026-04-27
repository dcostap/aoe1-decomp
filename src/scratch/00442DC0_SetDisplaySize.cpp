// VA: 00442DC0 TDrawArea::SetDisplaySize (300 B)
// PDB source: Drawarea.cpp
// Packet-grounded: check surface type 2, create new surface at requested size

extern int CreateSurface(void* self, int w, int h, int flags);
extern int Release(void* surface);

struct Shim_SetDisplaySize_2DC0 {
    char gap00[0x18];
    int Width;                 // +0x18
    int Height;                // +0x1C
    char gap20[0x3C - 0x20];
    void* Surface;             // +0x3C
    char gap40[0x478 - 0x40];
    unsigned char surf_type;   // +0x478 (0=none, 1=system, 2=video/overlay)
    char gap479[1];
};

void TDrawArea_SetDisplaySize(Shim_SetDisplaySize_2DC0* self, int w, int h)
{
    if (self->surf_type != 2)
        return;
    
    *(int*)0x62E63C = 1;  // Global flag
    
    // Create a new DD surface with the requested size
    // 0x1000400 = DDSCAPS flags for this type
    CreateSurface(self, w, h, 0x1000400);
    
    // Store width/height
    self->Width = w;
    self->Height = h;
    
    // Additional setup for video mode surfaces
    // ...
}
