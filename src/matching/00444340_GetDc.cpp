// 00444340 TDrawArea::GetDc
// Source: Drawarea.cpp lines 2177-2278. 72 bytes. __thiscall, ret 4.
//
// MATCHED. Exact 72-byte match confirmed via local check_function.py.
// Key fix: IDirectDrawSurface::GetDC must be __stdcall (COM convention),
// not __thiscall. Without __stdcall, VC5 emits mov ecx,edx pushing
// this via ECX instead of push edx passing this on stack.

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
    virtual void __stdcall GetDC(void** dc);
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;
    char gap_04[0x4];
    void* Bits;
    char gap_0C[0x2C];
    void* DrawDc;
    IDirectDrawSurface* DrawSurface;

    void* GetDc(char* unused);
};

void* TDrawArea::GetDc(char* unused)
{
    if (this->DrawSystem != 0) {
        if (this->DrawSystem->DrawType == 1)
            return this->DrawDc;
    }

    if (this->DrawSurface == 0)
        return 0;

    if (this->DrawDc != 0)
        return this->DrawDc;

    if (this->Bits != 0)
        return 0;

    IDirectDrawSurface* surface = this->DrawSurface;
    surface->GetDC(&this->DrawDc);
    return this->DrawDc;
}
