// VA: 00443520 TDrawArea::Paint (342 B)
// PDB source: Drawarea.cpp
// Packet-grounded: blit/flip surface to primary (screen or backbuffer)

extern int Blt(void* dst, void* src, ...);
extern int GetDC(void* surface);
extern int ReleaseDC(void* surface, int dc);

struct Shim_Paint_3520 {
    char gap00[4];
    void* Surface2;            // +0x04 (primary/backbuffer?)
    char gap08[0x0C - 0x08];
    void* Bits;                // +0x0C
    char gap10[0x1C - 0x10];
    int Height;                // +0x1C
    char gap20[0x478 - 0x20];
    unsigned char surf_type;   // +0x478
    unsigned char surf_type2;  // +0x479
};

void TDrawArea_Paint(Shim_Paint_3520* self, void* srcRect, void* dstRect)
{
    if (self->surf_type == 1)
        return;
    if (!self->Height || !self->Bits)
        return;
    void* surfaces = *(void**)((char*)self->Bits + 0x3C);
    if (!surfaces)
        return;
    
    if (self->surf_type2 == 1) {
        // Use GDI: GetDC on source, Blt, ReleaseDC
        // ...
    } else {
        // Direct draw: Blt with stretch or copy
        // ...
    }
}
