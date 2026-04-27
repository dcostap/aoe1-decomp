// VA: 00444110 TDrawArea::CheckSurface (338 B)
// PDB source: Drawarea.cpp
// Packet-grounded: check surface's surface, re-create on mismatch/size change/lost

extern int CreateSurface(void* self, int w, int h, int flags);
extern int Release(void* surface);
extern int IsLost(void* surface);

struct Shim_CheckSurface_4110 {
    char gap00[0x18];
    int Width;                 // +0x18
    int Height;                // +0x1C
    char gap20[0x3C - 0x20];
    void* Surface;             // +0x3C
    char gap40[0x478 - 0x40];
    unsigned char surf_type;   // +0x478 (0=none, 1=system, 2=video/overlay)
};

int TDrawArea_CheckSurface(Shim_CheckSurface_4110* self)
{
    void* drawSys = *(void**)self;
    if (!drawSys)
        return 3;
    
    if (*(unsigned char*)((char*)drawSys + 0x478) != 2)
        return 3;
    
    if (!self->Surface) {
        // No surface — create one
        // Create a 0x6C-byte temp struct and call vtable function
        return 3;
    }
    
    // Call check on the surface
    int result = ((int(*)(void*))(*(int**)((char*)self->Surface + 0x60))[0x60/4])(self->Surface);
    if (!result)
        return 3;
    
    // Now check dimensions via vtable call
    // ...
    
    return 0;
}
