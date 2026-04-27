// VA: 00444680 TDrawArea::Clear (458 B)
// PDB source: Drawarea.cpp
// Packet-grounded: fill entire surface with color, respecting clip rect

extern void* memset(void* s, int c, int n);
extern int TDrawArea_FillRect(void* self, int x1, int y1, int x2, int y2, unsigned char color);

struct Shim_Clear_4680 {
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
};

void TDrawArea_Clear(Shim_Clear_4680* self, unsigned char color)
{
    if (!self->Bits)
        return;
    
    // Check if we can do a fast full-surface memset
    int w = self->ClipRight - self->ClipLeft + 1;
    int h = self->ClipBottom - self->ClipTop + 1;
    
    if (w < 1 || h < 1)
        return;
    
    if (self->Orien == 1) {
        // Top-down: simplest fill, row by row
        unsigned char* ptr = self->Bits + self->ClipTop * self->Pitch + self->ClipLeft;
        
        // If clip covers full width, use single memset for each row
        if (self->ClipLeft == 0 && w == self->Width) {
            // Full-width rows can be done quickly
            int y;
            for (y = 0; y < h; y++) {
                memset(ptr, color, w);
                ptr += self->Pitch;
            }
        } else {
            // Partial width, still row by row
            int y;
            for (y = 0; y < h; y++) {
                memset(ptr, color, w);
                ptr += self->Pitch;
            }
        }
    } else {
        // Bottom-up orientation
        unsigned char* ptr = self->Bits + (self->Height - self->ClipTop - 1) * self->Pitch + self->ClipLeft;
        int y;
        for (y = 0; y < h; y++) {
            memset(ptr, color, w);
            ptr -= self->Pitch;
        }
    }
}
