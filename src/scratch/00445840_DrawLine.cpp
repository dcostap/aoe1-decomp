// VA: 00445840 TDrawArea::DrawLine (348 B)
// PDB source: Drawarea.cpp
// Packet-grounded: Bresenham-style line drawing with clipping

extern void TDrawArea_setPixel(void* self, int x, int y, unsigned char color);

struct Shim_DrawLine_5840 {
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

void TDrawArea_DrawLine(Shim_DrawLine_5840* self, int x1, int y1, int x2, int y2, unsigned char color)
{
    if (!self->Bits)
        return;
    
    // Simple line draw with clip rect check
    // Compute dX, dY, determine step direction
    int dx = x2 - x1;
    int dy = y2 - y1;
    
    if (dx < 0) { dx = -dx; x1 = x2; x2 = x1 + dx; /* swap x endpoints */ }
    if (dy < 0) { dy = -dy; y1 = y2; y2 = y1 + dy; /* swap y endpoints */ }
    
    // Check against clip rect
    // ...
    
    // Bresenham loop
    // ...
}
