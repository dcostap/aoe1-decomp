// VA: 00444300 TDrawArea::Unlock (53 B)
// PDB source: Drawarea.cpp
// Unlocks the DirectDraw surface and sets Bits to NULL

#include <ddraw.h>

#ifndef DRAWAREA_CANONICAL_TU
class TDrawSystem {
public:
    char gap_00[0x478];
    unsigned char DrawType;
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;   // +0x00
    char gap_04[0x04];
    unsigned char* Bits;       // +0x08
    char gap_0C[0x2C];
    void* DrawDc;              // +0x38
    IDirectDrawSurface* DrawSurface; // +0x3C

    void Unlock(char* name);
};
#endif

void TDrawArea::Unlock(char* name)
{
    if (this->DrawSystem != 0 && this->DrawSystem->DrawType == 1)
        return;

    if (this->DrawSurface == 0)
        return;

    if (this->Bits == 0)
        return;

    this->DrawSurface->Unlock(this->Bits);
    this->Bits = 0;
}
