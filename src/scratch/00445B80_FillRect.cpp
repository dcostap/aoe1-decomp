// VA: 00445B80 TDrawArea::FillRect (240 B)
// PDB source: Drawarea.cpp
// Packet-grounded: clip rect constrained fill with memset, supports bottom-up orientation

extern void* memset(void* s, int c, int n);

struct Shim_FillRect_5B80 {
    char gap00[0x08];
    unsigned char* Bits;       // +0x08
    char gap0C[0x18 - 0x0C];
    int Width;                 // +0x18
    int Height;                // +0x1C
    int Pitch;                 // +0x20
    int Orien;                 // +0x24 (1 = top-down, other = bottom-up)
    int ClipLeft;              // +0x28
    int ClipTop;               // +0x2C
    int ClipRight;             // +0x30
    int ClipBottom;            // +0x34
};

void TDrawArea_FillRect(Shim_FillRect_5B80* self, int x1, int y1, int x2, int y2, unsigned char color)
{
    if (!self->Bits)
        return;
    
    // Normalize x coordinates
    int left = x1;
    int right = x2;
    if (left > right) {
        int temp = left;
        left = right;
        right = temp;
    }
    
    // Normalize y coordinates
    int top = y1;
    int bottom = y2;
    if (top > bottom) {
        int temp = top;
        top = bottom;
        bottom = temp;
    }
    
    // Check against clip rect: reject if entirely outside
    if (left > self->ClipRight || right < self->ClipLeft ||
        top > self->ClipBottom || bottom < self->ClipTop)
        return;
    
    // Clip to clip rect
    if (left < self->ClipLeft) left = self->ClipLeft;
    if (right > self->ClipRight) right = self->ClipRight;
    if (top < self->ClipTop) top = self->ClipTop;
    if (bottom > self->ClipBottom) bottom = self->ClipBottom;
    
    int width = right - left + 1;
    int height = bottom - top + 1;
    
    if (width < 1 || height < 1)
        return;
    
    // Calculate starting pixel address based on orientation
    unsigned char* ptr;
    int pitch;
    
    if (self->Orien == 1) {
        // Top-down orientation
        pitch = self->Pitch;
        ptr = self->Bits + top * pitch + left;
    } else {
        // Bottom-up orientation
        pitch = -self->Pitch;
        ptr = self->Bits + ((self->Height - top - 1) * self->Pitch) + left;
    }
    
    // Fill each row
    int y;
    for (y = 0; y < height; y++) {
        memset(ptr, color, width);
        ptr += pitch;
    }
}
