// VA: 00473240 TButtonPanel::mouse_left_move_action(long,long,int,int)
// Pnl_btn.cpp lines 893-920
// Attempt log:
// - Canonical typed fields and virtual is_inside/set-redraw/notify surfaces matched size, calls, and body shape;
//   the first natural branch order left only the notification-arm polarity different.
// - Putting the positive is_down notification arm first preserves the original je-to-code-3 layout. Exact.

extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);

class TButtonPanel;
#ifndef PNL_BTN_SHARED_CONTEXT
#include "../../include/pnl_btn_context.h"

#endif

long TButtonPanel::mouse_left_move_action(long x, long y, int ctrl, int shift) {
    int new_state = (this->is_inside(x, y) != 0);
    if (this->is_down != new_state) {
        this->is_down = new_state;
        if (new_state != 0) {
            this->button_down_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_btn.cpp", 0x389);
        }
        this->set_redraw(1);
        TPanel* target = this->parent_panel;
        if (this->is_down != 0) {
            if (target != 0) {
                target->action(this, 2, this->id[this->cur_state], this->id2[this->cur_state]);
                return 1;
            }
        } else if (target != 0) {
            target->action(this, 3, this->id[this->cur_state], this->id2[this->cur_state]);
        }
    }
    return 1;
}
