// tried the ScreenMode gate plus a stack block for ddbltfx; first mismatch moved to the stack-call ordering around the blit setup
// tried a COM-style surface temp/call spelling next; remaining mismatch is still the early push/store ordering before the vtable call

class TDrawArea;
class DrawAreaNode;
class IDirectDraw;
class IDirectDrawClipper;
class IDirectDrawPalette;
class IDirectDrawSurface {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void Blt(void*, void*, void*, unsigned long, void*);
};

class TDrawSystem {
public:
    void* Inst;
    void* Wnd;
    void* Pal;
    TDrawArea* DrawArea;
    TDrawArea* PrimaryArea;
    DrawAreaNode* DrawAreaList;
    IDirectDraw* DirDraw;
    IDirectDrawSurface* PrimarySurface;
    IDirectDrawClipper* Clipper;
    IDirectDrawPalette* DirDrawPal;
    char gap_28[0x479 - 0x28];
    unsigned char ScreenMode;

    void ClearPrimarySurface();
};

void TDrawSystem::ClearPrimarySurface() {
    char ddbltfx[0x64];
    IDirectDrawSurface* surface;
    typedef void (__stdcall *BltFn)(IDirectDrawSurface*, void*, void*, void*, unsigned long, void*);
    BltFn blt;

    if (ScreenMode == 2 && (surface = PrimarySurface) != 0) {
        *(int*)(ddbltfx + 0x00) = 0x64;
        *(int*)(ddbltfx + 0x50) = 0;
        blt = (BltFn)((*(void***)surface)[5]);
        blt(surface, 0, 0, 0, 0x1000400, ddbltfx);
    }
}
