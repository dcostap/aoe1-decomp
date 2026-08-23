// 0045BF90 TMousePointer::center (Mouseptr.cpp:1029-1047, 113B)
// Exact-match note: naming shared x/y locals across both branches makes VC5 keep
// the draw_system/RECT-left value in ESI and emit the original push/pop ESI shape.

#include "../../include/mouseptr_context.h"

struct RECT_S {
    long left;
    long top;
    long right;
    long bottom;
};

__declspec(dllimport) int __stdcall GetWindowRect(void* hwnd, RECT_S* rect);
__declspec(dllimport) int __stdcall SetCursorPos(int x, int y);

void TMousePointer::center()
{
    TDrawSystem* draw_system = this->render_area->DrawSystem;
    int x;
    int y;

    if (draw_system->ScreenMode == 1) {
        RECT_S win_rect;
        GetWindowRect(draw_system->Wnd, &win_rect);
        x = (win_rect.right - win_rect.left) / 2 + win_rect.left;
        y = (win_rect.bottom - win_rect.top) / 2 + win_rect.top;
    } else {
        x = draw_system->ScreenWidth / 2;
        y = draw_system->ScreenHeight / 2;
    }
    SetCursorPos(x, y);
}
