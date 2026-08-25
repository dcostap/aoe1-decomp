// VA: 00445780 TDrawArea::SetOverlayTrans (81 B)
// PDB source: Drawarea.cpp
// Sets overlay transparency color key

#include <ddraw.h>

#ifndef DRAWAREA_CANONICAL_TU
class TDrawSystem {
public:
    char gap_00[0x478];
    unsigned char DrawType;
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;         // +0x00
    char gap_04[0x38];
    IDirectDrawSurface* DrawSurface; // +0x3C
    char gap_40[0xAC];
    int UseTrans;                    // +0xEC
    char gap_F0[0x0C];
    unsigned char TransColor;        // +0xFC

    void SetOverlayTrans(int useTrans, unsigned char transColor);
};
#endif

void TDrawArea::SetOverlayTrans(int useTrans, unsigned char transColor)
{
    this->UseTrans = useTrans;
    this->TransColor = transColor;

    if (useTrans == 0)
        return;

    if (this->DrawSurface == 0)
        return;

    if (this->DrawSystem == 0)
        return;

    if (this->DrawSystem->DrawType != 2)
        return;

    int ddck[2];
    ddck[0] = transColor;
    ddck[1] = transColor;
    this->DrawSurface->SetColorKey(0x10, (DDCOLORKEY*)ddck);
}
