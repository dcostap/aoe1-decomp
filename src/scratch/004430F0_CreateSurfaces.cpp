// VA: 004430F0 TDrawArea::CreateSurfaces (768 B)
// PDB source: Drawarea.cpp
// Packet-grounded: EH-framed, creates DD surfaces based on surf_type

extern void* memset(void* s, int c, int n);

struct Shim_CreateSurfaces_30F0 {
    char gap00[0x0C];
    void* Bits;                // +0x0C (DDraw surface wrapper)
    char gap10[0x18 - 0x10];
    int Width;                 // +0x18
    int Height;                // +0x1C
    int Pitch;                 // +0x20
    int Orien;                 // +0x24
    char gap28[0x34 - 0x28];
    int BitsPerPixel;          // +0x34
    char gap38[0x3C - 0x38];
    void* Surface;             // +0x3C (DDraw surface)
    char gap40[0x478 - 0x40];
    unsigned char surf_type;   // +0x478
    unsigned char surf_type2;  // +0x479
};

int TDrawArea_CreateSurfaces(Shim_CreateSurfaces_30F0* self)
{
    // EH frame with FS:[0] prolog
    // Returns: 0 on success, 1 on failure
    
    // Only create surfaces for surf_type == 2 (video/overlay)
    if (self->surf_type != 2)
        return 1;
    
    // Check if height is already set
    if (self->Height)
        return 1;
    
    // Allocate and initialize a 0x6C byte DDSURFACEDESC structure
    // calloc(1, 0x6C) it first
    // Set dwSize = 0x6C, dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH
    
    // Get Bits pointer, call vtable method to create primary surface
    // if fails, return 1
    
    // If surf_type2 == 2 (secondary/backbuffer):
    //   Build overlay surface: push surface desc, flags 0x1000400, 
    //     call vtable[0x14/4]
    // Check width%8==0? Check bpp==8:
    //   Call vtable[0x7C/4] on surface for palette
    //   if fails, return 1
    
    // Get palette data from surface
    // Check width, call vtable[0x70/4] on surface 
    //   if fails, return 1
    
    // Release old surface (if any), create new
    // Lock the surface to get pitch
    // if fails, return 1
    
    // Set pitch = surface pitch
    // Set Bits = locked surface bits
    
    return 0;
}
