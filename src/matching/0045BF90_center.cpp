// 0045BF90 TMousePointer::center (Mouseptr.cpp:1029-1047, 113B)
// Exact-match note: naming shared x/y locals across both branches makes VC5 keep
// the draw_system/RECT-left value in ESI and emit the original push/pop ESI shape.

struct RECT_S {
    long left;
    long top;
    long right;
    long bottom;
};

struct TDrawSystem {
    char gap0[4];
    void* hwnd;
    char gap8[0x24];
    int width;
    int height;
    char gap34[0x445];
    unsigned char screen_mode;
};

struct TRenderArea {
    TDrawSystem* DrawSystem;
};

struct TMousePointer {
    char gap[4];
    TRenderArea* render_area;
    void center();
};

__declspec(dllimport) int __stdcall GetWindowRect(void* hwnd, RECT_S* rect);
__declspec(dllimport) int __stdcall SetCursorPos(int x, int y);

void TMousePointer::center()
{
    TDrawSystem* draw_system = this->render_area->DrawSystem;
    int x;
    int y;

    if (draw_system->screen_mode == 1) {
        RECT_S win_rect;
        GetWindowRect(draw_system->hwnd, &win_rect);
        x = (win_rect.right - win_rect.left) / 2 + win_rect.left;
        y = (win_rect.bottom - win_rect.top) / 2 + win_rect.top;
    } else {
        x = draw_system->width / 2;
        y = draw_system->height / 2;
    }
    SetCursorPos(x, y);
}
