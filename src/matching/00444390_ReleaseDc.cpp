// VA: 00444390 TDrawArea::ReleaseDc (50 B)
// PDB source: Drawarea.cpp
// Releases the DC obtained from GetDc

class TDrawSystem {
public:
    char gap_00[0x478];
    unsigned char DrawType;
};

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
    virtual void __stdcall GetDC(void** dc);       // +0x44 (index 17)
    virtual void __stdcall GetDeviceSurface();
    virtual void __stdcall GetDDInterface();
    virtual void __stdcall GetPalette();
    virtual void __stdcall GetPixelFormat();
    virtual void __stdcall GetSurfaceDesc(void* desc);
    virtual void __stdcall Initialize();
    virtual void __stdcall IsLost();
    virtual int __stdcall Lock(void* rect, void* desc, int flags, void* hdc);  // +0x64 (index 25)
    virtual void __stdcall ReleaseDC(void* dc);     // +0x68 (index 26)
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
