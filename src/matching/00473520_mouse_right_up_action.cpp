extern "C" __declspec(dllimport) long __stdcall SendMessageA(void* hwnd, unsigned int msg, unsigned int wparam, long lparam);

#ifndef PNL_BTN_SHARED_CONTEXT
#include "../../include/pnl_btn_context.h"

#endif

long TButtonPanel::mouse_right_up_action(long x, long y, int ctrl, int shift) {
    release_mouse();
    if (is_down != 0) {
        if (buttonTypeValue != 2) {
            is_down = 0;
        }
        set_redraw(1);
        SendMessageA(render_area->Wnd, 0x0F, 0, 0);
        do_right_action(shift);
        return 1;
    }
    if (buttonTypeValue == 2 && cur_state == 1) {
        is_down = 1;
        set_redraw(1);
    }
    return 1;
}
