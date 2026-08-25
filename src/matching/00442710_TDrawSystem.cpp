// ~TDrawSystem — real pass
// VA: 00442710
// Attempt log:
// - Previous raw __fastcall used a 32-int local buffer and fake DeleteSurfaces wrapper, producing an 0x80 frame and indirect mov/call.
// - 2026-05-10 StarryZephyr pass: switched to natural thiscall destructor/member DeleteSurfaces and 0x64-byte DDBLTFX-shaped local.

#include "../drawarea_phase2_context.h"

TDrawSystem::~TDrawSystem()
{
    DDBLTFX ddbltfx;
    if (this->ScreenMode == 2 && this->PrimarySurface != 0) {
        IDirectDrawSurface* s = this->PrimarySurface;
        ddbltfx.dwSize = 0x64;
        ddbltfx.dwFillColor = 0;
        s->Blt(0, 0, 0, 0x1000400, &ddbltfx);
    }

    this->DeleteSurfaces();

    if (this->DirDraw != 0) {
        if (this->DirDrawPal != 0) {
            IDirectDrawPalette* p = this->DirDrawPal;
            p->Release();
            this->DirDrawPal = 0;
        }
        if (this->Clipper != 0) {
            IDirectDrawClipper* c = this->Clipper;
            c->Release();
            this->Clipper = 0;
        }
        if (this->ChangedMode != 0) {
            IDirectDraw* d = this->DirDraw;
            d->RestoreDisplayMode();
            this->ChangedMode = 0;
        }
        IDirectDraw* d = this->DirDraw;
        d->Release();
        this->DirDraw = 0;
    }
}
