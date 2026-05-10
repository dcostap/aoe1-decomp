// ~TDrawSystem — real pass
// VA: 00442710
// Attempt log:
// - Previous raw __fastcall used a 32-int local buffer and fake DeleteSurfaces wrapper, producing an 0x80 frame and indirect mov/call.
// - 2026-05-10 StarryZephyr pass: switched to natural thiscall destructor/member DeleteSurfaces and 0x64-byte DDBLTFX-shaped local.

class IDirectDrawSurfaceLike;
class IDirectDrawLike;
class IDirectDrawPaletteLike;
class IDirectDrawClipperLike;

class TDrawSystem {
public:
    char gap_000[0x18];
    IDirectDrawLike* DirDraw;
    IDirectDrawSurfaceLike* PrimarySurface;
    IDirectDrawClipperLike* Clipper;
    IDirectDrawPaletteLike* DirDrawPal;
    char gap_028[0x3C - 0x28];
    int ChangedMode;
    char gap_040[0x479 - 0x40];
    unsigned char ScreenMode;

    void destructor();
    void DeleteSurfaces();
};

void TDrawSystem::destructor()
{
    char ddbltfx[0x64];
    if (this->ScreenMode == 2 && this->PrimarySurface != 0) {
        IDirectDrawSurfaceLike* s = this->PrimarySurface;
        void** vt = *(void***)s;
        *(int*)(ddbltfx + 0) = 0x64;
        *(int*)(ddbltfx + 0x50) = 0;
        ((void (__stdcall *)(IDirectDrawSurfaceLike*, int, int, int, int, void*))vt[5])(s, 0, 0, 0, 0x1000400, ddbltfx);
    }

    this->DeleteSurfaces();

    if (this->DirDraw != 0) {
        if (this->DirDrawPal != 0) {
            IDirectDrawPaletteLike* p = this->DirDrawPal;
            (*(void (__stdcall ***)(IDirectDrawPaletteLike*))p)[2](p);
            this->DirDrawPal = 0;
        }
        if (this->Clipper != 0) {
            IDirectDrawClipperLike* c = this->Clipper;
            (*(void (__stdcall ***)(IDirectDrawClipperLike*))c)[2](c);
            this->Clipper = 0;
        }
        if (this->ChangedMode != 0) {
            IDirectDrawLike* d = this->DirDraw;
            (*(void (__stdcall ***)(IDirectDrawLike*))d)[19](d);
            this->ChangedMode = 0;
        }
        IDirectDrawLike* d = this->DirDraw;
        (*(void (__stdcall ***)(IDirectDrawLike*))d)[2](d);
        this->DirDraw = 0;
    }
}
