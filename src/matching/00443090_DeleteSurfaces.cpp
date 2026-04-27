// tried the natural delete/member-call shape first; the exact match landed after moving PrimaryArea zeroing outside the inner delete check
#include "..\..\include\game_types.h"

class TDrawArea {
public:
    ~TDrawArea();
};

class IDirectDrawSurface {
public:
    virtual long __stdcall QueryInterface();
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};

class TDrawSystem {
public:
    void* Inst;
    void* Wnd;
    void* Pal;
    TDrawArea* DrawArea;
    TDrawArea* PrimaryArea;
    char _pad_14[0x8];
    IDirectDrawSurface* PrimarySurface;

    void DeleteSurfaces();
};

void TDrawSystem::DeleteSurfaces() {
    if (DrawArea != 0) {
        delete DrawArea;
        DrawArea = 0;
    }

    if (PrimarySurface != 0) {
        if (PrimaryArea != 0) {
            delete PrimaryArea;
        }

        PrimaryArea = 0;
        PrimarySurface->Release();
        PrimarySurface = 0;
    }
}
