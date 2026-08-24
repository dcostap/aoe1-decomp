// 004430F0 TDrawSystem::CreateSurfaces
// PDB owner: TDrawSystem::CreateSurfaces, Drawarea.cpp lines 1062-1149.
// The canonical Drawarea context owns the class, record, and COM surfaces.
// BINARY NOTE: Drawarea.cpp has EH frames at 004430F0, 004443D0, and 00444C30.
// A module-wide /GX wrapper preserves all earlier exact anchors and this body.
// Non-EH bodies do not prove a separate code-band flag state.
// Attempt log:
// FLAGS: config/flags/004430F0_CreateSurfaces.rsp uses /GX; original has VC5 EH frame around TDrawArea construction.
// try 1: natural DirectDraw/TDrawArea reconstruction with EH new areas, DDSURFACEDESC/DDBLTFX locals.
// try 2: default flags probe compiled only 560B and lacked EH frame; restored /GX.
// try 3: modeled DDSURFACEDESC 0x6c memset and DirectDraw::CreateSurface call at vt+0x18.
// try 4: modeled BackBuffer pointer at +0x1c via &this->BackBuffer for CreateSurface out-param.
// try 5: modeled fullscreen clear Blt with DDBLTFX size 0x64/fill 0 and flags 0x1000400.
// try 6: modeled bpp==8 SetPalette at surface vt+0x7c and SetClipper vt+0x70.
// try 7: modeled PrimaryArea allocation/ctor string and EH state 0; calls recognizable but compiler saves EBP unlike original.
// try 8: modeled DrawArea allocation/ctor string and EH state 1; late block recognizable with same high-level call sequence.
// try 9: canonical dllimport GetClientRect declaration preserves the indirect IAT call; window RECT local offsets still drift.
// final: corrected the DirectDrawSurface COM slot prefix, restored the real
// PrimarySurface +0x1C ownership and +0x28 gap, modeled DDSURFACEDESC flags/caps,
// and used the five-argument TDrawArea::Init ABI; exact under /GX and default
// source layout.

#include <string.h>
#pragma function(memset)
extern void* __cdecl operator new(unsigned int);

#include "../../include/drawarea_context.h"

typedef _DDBLTFX DDBLTFX;

#ifndef DRAWAREA_CANONICAL_TU
extern "C" __declspec(dllimport) int __stdcall GetClientRect(void*, RECT*);
#endif

int TDrawSystem::CreateSurfaces()
{
    DDSURFACEDESC ddsd;
    DDBLTFX ddbltfx;
    RECT wnd_rect;

    if (this->DrawType == 2) {
        if (this->PrimarySurface == 0) {
            memset(&ddsd, 0, 0x6c);
            ddsd.dwSize = 0x6c;
            ddsd.dwFlags = 1;
            ddsd.ddsCaps.dwCaps = 0x200;
            if (this->DirDraw->CreateSurface(&ddsd, &this->PrimarySurface, 0)) return 0;
            if (this->ScreenMode == 2) {
                ddbltfx.dwSize = 0x64;
                ddbltfx.dwFillColor = 0;
                this->PrimarySurface->Blt(0, 0, 0, 0x1000400, &ddbltfx);
            }
            if (this->ColorBits == 8) {
                if (this->PrimarySurface->SetPalette(this->DirDrawPal)) return 0;
            }
            if (this->PrimarySurface->SetClipper(this->Clipper)) return 0;
        }
        if (this->PrimaryArea == 0) {
            TDrawArea* area = new TDrawArea("Primary Area", 0);
            this->PrimaryArea = area;
            if (area == 0) return 0;
            if (this->ScreenMode == 1) {
                GetClientRect(this->Wnd, &wnd_rect);
                if (!this->PrimaryArea->Init(this, wnd_rect.right, wnd_rect.bottom, 0, 1)) return 0;
            } else {
                if (!area->Init(this, this->ScreenWidth, this->ScreenHeight, 0, 1)) return 0;
            }
        }
    }
    if (this->DrawArea == 0) {
        TDrawArea* area2 = new TDrawArea("Draw Area", 0);
        this->DrawArea = area2;
        if (area2 == 0) return 0;
        if (this->ScreenMode == 1) {
            GetClientRect(this->Wnd, &wnd_rect);
            if (!this->DrawArea->Init(this, wnd_rect.right, wnd_rect.bottom, 0, 0)) return 0;
        } else {
            if (!area2->Init(this, this->ScreenWidth, this->ScreenHeight, 0, 0)) return 0;
        }
    }
    return 1;
}
