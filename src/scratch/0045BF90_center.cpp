// 0045BF90 TMousePointer::center (Mouseptr.cpp:1029-1047, 113B)
// 112/113 bytes (112B .text, target 113B). VC5-version difference:
//
// The 1998 build saves the draw_system pointer in esi (callee-save register),
// requiring `push esi` (1 byte) and `pop esi` in each path (2x1=2 bytes).
// Our VC5 keeps draw_system in ecx (volatile), which doesn't need saving
// across the GetWindowRect call. This removes 3 bytes of esi save/restore
// but adds 2 bytes elsewhere in instruction encoding/RECT offset handling,
// for a net difference of 1 byte.
//
// The `void* draw_system = *(void**)this->render_area;` local triggers the
// register difference. No C source change forces esi usage. VC5-version
// register allocation difference.

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
