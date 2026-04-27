// VA: 00442F30 TDrawArea::CheckSurfaces (318 B)
// PDB source: Drawarea.cpp
// Packet-grounded: check DD surface status, re-create if lost

extern int CreateSurface(void* self, int w, int h, int flags);
extern int Release(void* surface);
extern int IsLost(void* surface);
extern int Restore(void* surface);
extern int TDrawArea_CheckSurface(void* self);

struct Shim_CheckSurfaces_2F30 {
    char gap00[0x18];
    int Width;                 // +0x18
    int Height;                // +0x1C
    char gap20[0x3C - 0x20];
    void* Surface;             // +0x3C
    char gap40[0x478 - 0x40];
    unsigned char surf_type;   // +0x478 (0=none, 1=system, 2=video/overlay)
    unsigned char surf_type2;  // +0x479
};

int TDrawArea_CheckSurfaces(Shim_CheckSurfaces_2F30* self)
{
    // Check surface type
    if (self->surf_type != 2 && self->surf_type2 != 2)
        return 0;
    
    if (!self->Surface)
        return 0;
    
    // Check if surface is lost
    int result = IsLost(self->Surface);
    if (result == 0) {
        // Surface is fine, restore if possible
        result = Restore(self->Surface);
        
        if (result == 0) {
            // Surface restored, now re-create
            // Release old surface
            Release(self->Surface);
            self->Surface = 0;
            
            // Create new surface at current size
            CreateSurface(self, self->Width, self->Height, 0);
            
            // Check surfaces recursively
            TDrawArea_CheckSurface(self);
            return 1;
        }
    }
    
    return 0;
}
