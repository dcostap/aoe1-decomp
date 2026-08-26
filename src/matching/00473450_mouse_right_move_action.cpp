// VA: 00473450 mouse_right_move_action (194B)
// Pnl_btn.cpp
//
// Attempt log:
// - Restored the period-plausible TPanel/TButtonPanel ownership from the
//   neighboring exact Pnl_btn.cpp actions: is_inside, set_redraw, parent_panel,
//   id/id2, cur_state, is_down, and button_down_time.
// - Baseline matched all bytes except the final notification branch polarity;
//   keeping the positive is_down arm first recovered the original hot (code 5)
//   block layout and exact bytes.

extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);

long TButtonPanel::mouse_right_move_action(long x, long y, int ctrl, int shift) {
    int new_is_down = (this->is_inside(x, y) != 0);

    if (this->is_down != new_is_down) {
        this->is_down = new_is_down;
        if (new_is_down != 0) {
            this->button_down_time = debug_timeGetTime(
                "C:\\msdev\\work\\age1_x1\\Pnl_btn.cpp", 0x3E3);
        }
        this->set_redraw(1);
        if (this->is_down != 0) {
            if (this->parent_panel != 0) {
                this->parent_panel->action(
                    this, 5, this->id[this->cur_state], this->id2[this->cur_state]);
            }
            return 1;
        } else if (this->parent_panel != 0) {
            this->parent_panel->action(
                this, 6, this->id[this->cur_state], this->id2[this->cur_state]);
        }
    }

    return 1;
}
