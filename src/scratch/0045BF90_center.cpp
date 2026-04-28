// 0045BF90 TMousePointer::center (113 bytes)
// PDB: Mouseptr.cpp
// STATUS: parked - 7 bytes short of original size (112 vs 113)
//
// Remaining diff: VC5 uses ECX (caller-save) instead of ESI (callee-save)
// for the draw_system pointer. Without ESI save/restore, function is 106 bytes
// (+6 from __declspec dllimport making calls indirect at 6 bytes each).
// Need 7 more bytes: push esi (1) + 2x pop esi (2) + RECT at [esp+4] vs [esp]
// encoding differences (~4 bytes).
//
// Tried: local pointer variable, dllimport for indirect calls, integer
// arithmetic casts, void* variable, separate sx/sy params, saved_this
// hack. VC5 consistently uses ECX — pointer is not live across function calls,
// so no ESI save needed.

#include <stddef.h>

struct RECT_S {
    long left;
    long top;
    long right;
    long bottom;
};

struct TMousePointer {
    char gap[4];
    void* render_area;
    void center();
};

__declspec(dllimport) int __stdcall GetWindowRect(void* hwnd, RECT_S* rect);
__declspec(dllimport) int __stdcall SetCursorPos(int x, int y);

void TMousePointer::center()
{
    void* draw_system = *(void**)this->render_area;

    if (*(unsigned char*)((int)draw_system + 0x479) == 1) {
        RECT_S win_rect;
        GetWindowRect(*(void**)((int)draw_system + 4), &win_rect);
        SetCursorPos((win_rect.right - win_rect.left) / 2 + win_rect.left,
                     (win_rect.bottom - win_rect.top) / 2 + win_rect.top);
    } else {
        SetCursorPos(*(int*)((int)draw_system + 0x2C) / 2,
                     *(int*)((int)draw_system + 0x30) / 2);
    }
}
