// VA: 00443490 TDrawSystem::HandleQueryNewPalette (134 B)
// PDB source: Drawarea.cpp
// Handles WM_QUERYNEWPALETTE message

// BINARY NOTE: the canonical Drawarea context preserves the palette owner and
// the exact six-call Win32/Drawarea sequence.
#include "../../include/drawarea_context.h"

__declspec(dllimport) void* __stdcall GetDC(void* hwnd);
__declspec(dllimport) void* __stdcall SelectPalette(void* hdc, void* hpal, int bForceBackground);
__declspec(dllimport) int __stdcall RealizePalette(void* hdc);
__declspec(dllimport) int __stdcall ReleaseDC(void* hwnd, void* hdc);
__declspec(dllimport) int __stdcall InvalidateRect(void* hwnd, void* rect, int bErase);

int TDrawSystem::HandleQueryNewPalette(void* param1, unsigned int param2, unsigned int param3, long param4)
{
    if (this->Pal != 0 && (this->DrawType == 1 || this->ScreenMode == 1)) {
        void* hdc = GetDC(this->Wnd);
        if (this->Pal != 0)
            SelectPalette(hdc, this->Pal, 0);
        unsigned char result = (unsigned char)RealizePalette(hdc);
        ReleaseDC(this->Wnd, hdc);
        if (result != 0) {
            InvalidateRect(this->Wnd, 0, 0);
            return 1;
        }
    }
    this->ModifyPalette(0, 256, (tagPALETTEENTRY*)((char*)this + 0x78));
    return 0;
}
