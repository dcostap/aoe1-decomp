// VA: 00445780 TDrawArea::SetOverlayTrans (81 B)
// PDB source: Drawarea.cpp
// Sets overlay transparency color key

#ifndef DRAWAREA_CANONICAL_TU
struct IDirectDrawSurface {
    virtual void __stdcall QueryInterface();
    virtual void __stdcall AddRef();
    virtual void __stdcall Release();
    virtual void __stdcall AddAttachedSurface();
    virtual void __stdcall AddOverlayDirtyRect();
    virtual void __stdcall Blt();
    virtual void __stdcall ColorFill();
    virtual void __stdcall CreateAttachedSurface();
    virtual void __stdcall DeleteAttachedSurface();
    virtual void __stdcall EnumAttachedSurfaces();
    virtual void __stdcall EnumOverlayZOrders();
    virtual void __stdcall Flip();
    virtual void __stdcall GetAttachedSurface();
    virtual void __stdcall GetBltStatus();
    virtual void __stdcall GetCaps();
    virtual void __stdcall GetClipper();
    virtual void __stdcall GetColorKey();
    virtual void __stdcall GetDC(void** dc);
    virtual void __stdcall GetDeviceSurface();
    virtual void __stdcall GetDDInterface();
    virtual void __stdcall GetPalette();
    virtual void __stdcall GetPixelFormat();
    virtual void __stdcall GetSurfaceDesc(void* desc);
    virtual void __stdcall Initialize();
    virtual void __stdcall IsLost();
    virtual int __stdcall Lock(void* rect, void* desc, int flags, void* hdc);
    virtual void __stdcall ReleaseDC(void* dc);
    virtual void __stdcall Method27();
    virtual void __stdcall Method28();
    virtual int __stdcall SetColorKey(unsigned long flags, void* colorKey);  // +0x74 (index 29)
};

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
    this->DrawSurface->SetColorKey(0x10, ddck);
}
