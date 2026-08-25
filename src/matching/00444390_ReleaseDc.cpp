// VA: 00444390 TDrawArea::ReleaseDc (50 B)
// PDB source: Drawarea.cpp
// Releases the DC obtained from GetDc

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

    void ReleaseDc(char* name);
};
#endif

void TDrawArea::ReleaseDc(char* name)
{
    if (this->DrawSystem != 0 && this->DrawSystem->DrawType == 1)
        return;

    if (this->DrawSurface == 0)
        return;

    if (this->DrawDc == 0)
        return;

    this->DrawSurface->ReleaseDC(this->DrawDc);
    this->DrawDc = 0;
}
