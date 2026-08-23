// ~TDrawSystem — real pass
// VA: 00442710
// Attempt log:
// - Previous raw __fastcall used a 32-int local buffer and fake DeleteSurfaces wrapper, producing an 0x80 frame and indirect mov/call.
// - 2026-05-10 StarryZephyr pass: switched to natural thiscall destructor/member DeleteSurfaces and 0x64-byte DDBLTFX-shaped local.

#include "../../include/drawarea_context.h"

TDrawSystem::~TDrawSystem()
{
    char ddbltfx[0x64];
    if (this->ScreenMode == 2 && this->PrimarySurface != 0) {
        IDirectDrawSurface* s = this->PrimarySurface;
        void** vt = *(void***)s;
        *(int*)(ddbltfx + 0) = 0x64;
        *(int*)(ddbltfx + 0x50) = 0;
        ((void (__stdcall *)(IDirectDrawSurface*, int, int, int, int, void*))vt[5])(s, 0, 0, 0, 0x1000400, ddbltfx);
    }

    this->DeleteSurfaces();

    if (this->DirDraw != 0) {
        if (this->DirDrawPal != 0) {
            IDirectDrawPalette* p = this->DirDrawPal;
            (*(void (__stdcall ***)(IDirectDrawPalette*))p)[2](p);
            this->DirDrawPal = 0;
        }
        if (this->Clipper != 0) {
            IDirectDrawClipper* c = this->Clipper;
            (*(void (__stdcall ***)(IDirectDrawClipper*))c)[2](c);
            this->Clipper = 0;
        }
        if (this->ChangedMode != 0) {
            IDirectDraw* d = this->DirDraw;
            (*(void (__stdcall ***)(IDirectDraw*))d)[19](d);
            this->ChangedMode = 0;
        }
        IDirectDraw* d = this->DirDraw;
        (*(void (__stdcall ***)(IDirectDraw*))d)[2](d);
        this->DirDraw = 0;
    }
}
