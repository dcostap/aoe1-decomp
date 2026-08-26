// 0053A9C0 RGE_View::end_scroll_view (view.cpp:6161-6220)
// Using proper virtual method declarations for correct thiscall vtable dispatch.
// vtable: set_redraw at slot 8 (0x20), end_scroll_view at slot 60 (0xF0), do_paint at slot 61 (0xF4)

#include <windows.h>
#include "../../include/view_tu_context.h"

extern "C" __declspec(dllimport) int __stdcall ClientToScreen(void* hWnd, tagPOINT* point);
extern "C" __declspec(dllimport) int __stdcall SetCursorPos(int x, int y);

void RGE_View::end_scroll_view() {
    long min_x, max_x, min_y, max_y;

    switch (this->scroll_action) {
    case 2:
        if (this->mouse_down_x > this->mouse_last_x) {
            min_x = this->mouse_last_x;
            max_x = this->mouse_down_x;
        } else {
            min_x = this->mouse_down_x;
            max_x = this->mouse_last_x;
        }
        if (this->mouse_down_y > this->mouse_last_y) {
            min_y = this->mouse_last_y;
            max_y = this->mouse_down_y;
        } else {
            min_y = this->mouse_down_y;
            max_y = this->mouse_last_y;
        }
        this->pick_multi(4, min_x, min_y, max_x, max_y);
        this->set_redraw((TPanel::RedrawMode)1);
        break;

    case 1:
    case 6:
    case 7:
    case 8: {
        tagPOINT pt;
        pt.x = this->mouse_down_x;
        pt.y = this->mouse_down_y;
        // render_area->Wnd at offset +4 is the HWND
        ClientToScreen(((void**)this->render_area)[1], &pt);
        SetCursorPos(pt.x, pt.y);
        break;
    }

    case 9:
        this->do_paint(this->mouse_down_x, this->mouse_down_y, this->mouse_down_x, this->mouse_down_y, 0);
        this->set_redraw((TPanel::RedrawMode)1);
        break;

    case 3:
    case 4:
    case 5:
        break;
    }

    if (this->scroll_action == 1 || this->scroll_action == 2
        || this->scroll_action == 6 || this->scroll_action == 7
        || this->scroll_action == 8)
    {
        rge_base_game->mouse_on();
    }

    this->release_mouse();
    this->scroll_action = 0;
}
