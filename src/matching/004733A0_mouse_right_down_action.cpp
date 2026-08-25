extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);

class TButtonPanel;
#ifndef PNL_BTN_SHARED_CONTEXT
#include "../../include/pnl_btn_context.h"

#endif

long TButtonPanel::mouse_right_down_action(long x, long y, int ctrl, int shift) {
    if (disabled != 0) {
        return 0;
    }
    if (sound != 0) {
        if (sound->is_playing() != 0) {
            sound->stop();
        }
        sound->play();
    }
    capture_mouse();
    is_down = 1;
    button_down_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_btn.cpp", 0x3CC);
    set_redraw(1);
    if (parent_panel != 0) {
        parent_panel->action(this, 5, id[cur_state], id2[cur_state]);
    }
    return 1;
}
