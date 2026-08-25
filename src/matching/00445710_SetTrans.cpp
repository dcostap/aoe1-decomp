// VA: 00445710 TDrawArea::SetTrans (99 B)
// PDB source: Drawarea.cpp
// Sets source transparency color key

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

    void SetTrans(int useTrans, unsigned char transColor);
};
#endif

void TDrawArea::SetTrans(int useTrans, unsigned char transColor)
{
    this->UseTrans = useTrans;

    if (useTrans != 0)
        this->TransColor = transColor;
    else
        this->TransColor = 0xFF;

    if (useTrans == 0)
        return;

    if (this->DrawSurface == 0)
        return;

    if (this->DrawSystem == 0)
        return;

    if (this->DrawSystem->DrawType != 2)
        return;

    int ddck[2];
    ddck[0] = this->TransColor;
    ddck[1] = this->TransColor;
    this->DrawSurface->SetColorKey(8, (DDCOLORKEY*)ddck);
}
