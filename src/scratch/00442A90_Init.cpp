// VA: 00442A90 TDrawSystem::Init (802 B)
// PDB source: Drawarea.cpp
// Packet-grounded: initialize TDrawArea with surface, dimensions, orientation, bpp

extern void* operator_new(unsigned int size);
extern void operator_delete(void* p);
extern int RGE_get_description(char* buf, int size);
extern int CreateSurface(void* self, int w, int h, int flags);
extern int LockSurface(void* self, void* rect, int flags);

struct Shim_Init_2A90 {
    char gap00[4];
    void* field_04;            // +0x04
    void* field_08;            // +0x08
    char gap0C[0x0C];
    int Width;                 // +0x18
    int Height;                // +0x1C
    int Pitch;                 // +0x20
    int Orien;                 // +0x24
    int field_28;
    int field_2C;
    int field_30;
    char gap34[0x3C - 0x34];
    void* Surface;             // +0x3C
    char gap40[0x478 - 0x40];
    unsigned char surf_type;   // +0x478
    unsigned char surf_type2;  // +0x479
};

int TDrawSystem_Init(Shim_Init_2A90* self, void* hwnd, int width, int height, 
                     int bpp, void* palette, int mode, int surf_type,
                     int surf_type2, int a9, int a10)
{
    // Store parameters
    self->field_08 = hwnd;
    self->field_04 = palette;
    self->Width = width;
    self->Height = height;
    self->Pitch = 0;
    self->surf_type = (unsigned char)surf_type;
    self->surf_type2 = (unsigned char)surf_type2;
    self->field_2C = a9;
    self->field_30 = a10;
    
    // If surf_type == 1 (system memory), return 0 immediately
    if (surf_type == 1)
        return 0;
    
    // Call RGE_get_description for device info
    // ...
    
    // Determine orientation based on bpp
    if (bpp <= 8) {
        self->Orien = 1;  // Top-down for palette modes
    } else {
        // Calculate pitch from width
    }
    
    // Create the surface through the initial DDraw wrapper
    // ...
    
    if (self->Height) {
        // If height already set, lock the surface to get bits/pitch
        // ...
    }
    
    // Lock surface to initialize
    // ...
    
    // Set orien based on pitch sign (positive = top-down, negative = bottom-up)
    // ...
    
    return 0;
}
