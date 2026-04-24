class IDirectDrawSurface {
public:
    void** vftable;
};

struct _DDCOLORKEY {
    unsigned long dwColorSpaceLowValue;
    unsigned long dwColorSpaceHighValue;
};

class TDrawSystem {
public:
    char gap_000[0x478];
    unsigned char DrawType;
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;
    char gap_004[0x3C - 0x4];
    IDirectDrawSurface* DrawSurface;
    char gap_040[0xEC - 0x40];
    int UseTrans;
    char gap_0F0[0xFC - 0xF0];
    unsigned char TransColor;

    void SetOverlayTrans(int param_1, unsigned char param_2);
};

void TDrawArea::SetOverlayTrans(int param_1, unsigned char param_2) {
    _DDCOLORKEY ddck;
    this->UseTrans = param_1;
    this->TransColor = param_2;
    if (param_1 != 0 && this->DrawSurface != 0 && this->DrawSystem != 0 && this->DrawSystem->DrawType == 2) {
        ddck.dwColorSpaceLowValue = param_2;
        ddck.dwColorSpaceHighValue = param_2;
        ((void (__stdcall *)(IDirectDrawSurface*, int, _DDCOLORKEY*))(*(void***)this->DrawSurface)[29])(this->DrawSurface, 0x10, &ddck);
    }
}
