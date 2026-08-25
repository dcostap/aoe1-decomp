// VA: 00444110 TDrawArea::CheckSurface (338 B)
// PDB source: Drawarea.cpp, lines 1880-1949
//
// Attempt log:
// - Replaced the generated surface shim with the period DirectDraw status,
//   restore/recreate, and clear flow.  The first reconstruction uses typed
//   0x6C DDSURFACEDESC/0x64 DDBLTFX records and SDK-shaped COM slots.
// - The restore-error branch must be positive (`if (hr != 0)`) so the clear/
//   Blt path remains the late fallthrough.  Typed dwRGBBitCount and the two
//   HRESULT-specific release/recreate cases then match exactly under default
//   flags.

#include <string.h>
#include <ddraw.h>
#pragma function(memset)

#ifndef DRAWAREA_CANONICAL_TU
class TDrawArea;

class TDrawSystem {
public:
    void* Inst;                         // +0x00
    void* Wnd;                          // +0x04
    void* Pal;                          // +0x08
    TDrawArea* DrawArea;                // +0x0C
    TDrawArea* PrimaryArea;             // +0x10
    void* DrawAreaList;                 // +0x14
    IDirectDraw* DirDraw;               // +0x18
    IDirectDrawSurface* PrimarySurface; // +0x1C
    void* Clipper;                      // +0x20
    void* DirDrawPal;                   // +0x24
    unsigned long Flags;                // +0x28
    int ScreenWidth;                    // +0x2C
    int ScreenHeight;                   // +0x30
    int ColorBits;                      // +0x34
    int ErrorCode;                      // +0x38
    char gap_3C[0x43C];                 // +0x3C .. +0x477
    unsigned char DrawType;             // +0x478

    int GetIsLostErrorNum(long hr);
    int GetRestoreErrorNum(long hr);
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;    // +0x00
    char gap_04[0x14];          // +0x04 .. +0x17
    int Width;                  // +0x18
    int Height;                 // +0x1C
    char gap_20[0x1C];          // +0x20 .. +0x3B
    IDirectDrawSurface* DrawSurface; // +0x3C
    char gap_40[0xB4];           // +0x40 .. +0xF3
    int Restored;                // +0xF4

    void SetSize(long width, long height, int flags);
    unsigned char CheckSurface();
};
#endif

unsigned char TDrawArea::CheckSurface()
{
    if (this->DrawSystem != 0 && this->DrawSystem->DrawType == 2) {
        if (this->DrawSurface == 0)
            return 3;

        long hr = this->DrawSurface->IsLost();
        if (hr != 0) {
            this->DrawSystem->GetIsLostErrorNum(hr);

            _DDSURFACEDESC ddsd;
            _DDBLTFX ddbltfx;
            memset(&ddsd, 0, sizeof(ddsd));
            ddsd.dwSize = sizeof(ddsd);

            hr = this->DrawSystem->DirDraw->GetDisplayMode(&ddsd);
            if (hr == 0 &&
                (ddsd.dwWidth != (unsigned long)this->DrawSystem->ScreenWidth ||
                 ddsd.dwHeight != (unsigned long)this->DrawSystem->ScreenHeight ||
                 ddsd.ddpfPixelFormat.dwRGBBitCount != 8))
                return 1;

            hr = this->DrawSurface->Restore();
            if (hr != 0) {
                if (hr == (long)0x8876024B || hr == (long)0x8007000E) {
                    this->DrawSurface->Release();
                    this->DrawSurface = 0;
                    this->SetSize(this->Width, this->Height, 0);
                    if (this->DrawSurface != 0)
                        return 2;
                }

                this->DrawSystem->GetRestoreErrorNum(hr);
                return 3;
            }

            ddbltfx.dwSize = sizeof(ddbltfx);
            ddbltfx.dwFillColor = 0;
            this->DrawSurface->Blt(0, 0, 0, 0x1000400, &ddbltfx);
            this->Restored = 1;
            return 2;
        }
    }
    return 0;
}
