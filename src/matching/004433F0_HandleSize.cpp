// VA: 004433F0
// TDrawSystem::HandleSize(void*, unsigned int, unsigned int, long)
// Source: Drawarea.cpp lines 1155-1172

// attempt 1: natural if-else chain with GetClientRect + two SetSize calls -> EXACT MATCH (109/109, 0.0000%)
// default flags; period import declaration for IAT-resolved GetClientRect

#include "../drawarea_phase2_context.h"

// IAT-resolved GetClientRect via the period Win32 import declaration.
#ifndef DRAWAREA_CANONICAL_TU
extern "C" __declspec(dllimport) int __stdcall GetClientRect(void* hWnd, RECT* rect);
#endif

// BINARY NOTE: the canonical Drawarea context preserves this exact owner.

void TDrawSystem::HandleSize(void* hwnd, unsigned int msg, unsigned int wparam, long lparam) {
    if (this->DrawArea == 0) return;

    if (this->DrawType == 1 || this->ScreenMode == 1) {
        RECT rect;
        GetClientRect(this->Wnd, &rect);
        this->ScreenWidth = rect.right;
        this->ScreenHeight = rect.bottom;
    }

    if (this->PrimaryArea != 0) {
        this->PrimaryArea->SetSize(this->ScreenWidth, this->ScreenHeight, 0);
    }

    this->DrawArea->SetSize(this->ScreenWidth, this->ScreenHeight, 0);
}
