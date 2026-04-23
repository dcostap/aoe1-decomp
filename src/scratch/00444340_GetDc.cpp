// tried direct if/else member access; got the right branch structure but VC5 inserts mov ecx,edx in the GetDC call path
// tried a local surface temp; no codegen change in the call basin
// remaining mismatch is a single register-move before the IDirectDrawSurface::GetDC vcall
class TDrawSystem {
public:
    char gap_00[0x478];
    unsigned char DrawType;
};

class IDirectDrawSurface {
public:
    virtual void QueryInterface();
    virtual void AddRef();
    virtual void Release();
    virtual void AddAttachedSurface();
    virtual void AddOverlayDirtyRect();
    virtual void Blt();
    virtual void ColorFill();
    virtual void CreateAttachedSurface();
    virtual void DeleteAttachedSurface();
    virtual void EnumAttachedSurfaces();
    virtual void EnumOverlayZOrders();
    virtual void Flip();
    virtual void GetAttachedSurface();
    virtual void GetBltStatus();
    virtual void GetCaps();
    virtual void GetClipper();
    virtual void GetColorKey();
    virtual void GetDC(void** dc);
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
