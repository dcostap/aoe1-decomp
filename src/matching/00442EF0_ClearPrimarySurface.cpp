// VA: 00442EF0 TDrawSystem::ClearPrimarySurface (62 B)
// PDB source: Drawarea.cpp
// Clears the primary surface using Blt

struct IDirectDrawSurface {
    virtual void __stdcall QueryInterface();
    virtual void __stdcall AddRef();
    virtual void __stdcall Release();
    virtual void __stdcall AddAttachedSurface();
    virtual void __stdcall AddOverlayDirtyRect();
    virtual int __stdcall Blt(void* destRect, void* srcRect, void* param3, unsigned long flags, void* ddbltfx);
};

class TDrawSystem {
public:
    char gap_00[0x1C];
    IDirectDrawSurface* PrimarySurface;  // +0x1C
    char gap_20[0x459];
    unsigned char ScreenMode;            // +0x479

    void ClearPrimarySurface();
};

void TDrawSystem::ClearPrimarySurface()
{
    if (this->ScreenMode != 2)
        return;

    IDirectDrawSurface* surface = this->PrimarySurface;
    if (surface == 0)
        return;

    int ddbltfx[25];
    ddbltfx[0] = 0x64;
    ddbltfx[0x50 / 4] = 0;
    surface->Blt(0, 0, 0, 0x1000400, ddbltfx);
}
