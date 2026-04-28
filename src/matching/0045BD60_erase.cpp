// TMousePointer::erase (0045BD60)
// PDB source: Mouseptr.cpp:882-912
// Size: 192 bytes (0xC0)
// Calling convention: __thiscall

extern "C" __declspec(dllimport) int __stdcall InvalidateRect(void* hwnd, const void* rect, int erase);

class IDirectDrawSurface;

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea {
public:
    char gap_00[0x04];
    void* Wnd;                      // +0x04
    char gap_08[0x34];
    IDirectDrawSurface* DrawSurface; // +0x3C
};

class TMousePointer {
public:
    int custom_draw;                // +0x00
    TDrawArea* render_area;         // +0x04
    TDrawArea* save_area;           // +0x08
    char gap_0C[0xAC];              // +0x0C to +0xB7
    int save_area_valid;            // +0xB8
    tagRECT save_rect;              // +0xBC
    char gap_CC[0x30];              // +0xCC to +0xFB
    tagRECT restore_rect;           // +0xFC
    char gap_10C[0x10];             // +0x10C to +0x11B
    IDirectDrawSurface* restoreSurface;  // +0x11C
    char gap_120[0x04];             // +0x120
    IDirectDrawSurface* PrimarySurface; // +0x124
    int active;                     // +0x128
    int drawn;                      // +0x12C
    char gap_130[0x08];             // +0x130 to +0x137
    int GameMode;                   // +0x138
    int GameEnabled;                // +0x13C
    char gap_140[0x08];             // +0x140 to +0x147
    long LastddError;               // +0x148

    void erase();
};

void TMousePointer::erase() {
    if (!active) return;
    if (!custom_draw) return;
    if (!drawn) return;
    if (!save_area_valid) return;
    if (restoreSurface == PrimarySurface) return;

    // Blt from save_area->DrawSurface to restoreSurface
    // IDirectDrawSurface::Blt(LPRECT lpDestRect, LPDIRECTDRAWSURFACE lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwFlags, LPDDBLTFX lpDDBltFx)
    void** vtable = *(void***)restoreSurface;
    typedef long (__stdcall* BltFunc)(IDirectDrawSurface*, tagRECT*, IDirectDrawSurface*, tagRECT*, unsigned long, void*);
    long result = ((BltFunc)vtable[5])(restoreSurface, &restore_rect, save_area->DrawSurface, &save_rect, 0x1000000, 0);

    if (result != 0) {
        LastddError = result;
        return;
    }

    if (GameMode && GameEnabled) {
        save_area_valid = 1;
        restoreSurface = PrimarySurface;
        return;
    }

    InvalidateRect(render_area->Wnd, &restore_rect, 0);
    save_area_valid = 0;
}
