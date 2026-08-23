// TMousePointer::erase (0045BD60)
// PDB source: Mouseptr.cpp:882-912
// Size: 192 bytes (0xC0)
// Calling convention: __thiscall

#include "../../include/mouseptr_context.h"
extern "C" __declspec(dllimport) int __stdcall InvalidateRect(void* hwnd, const RECT4* rect, int erase);

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
