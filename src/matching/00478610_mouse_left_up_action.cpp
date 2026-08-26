// TListPanel::mouse_left_up_action — release mouse, clear scroll, then conditionally dispatch callback with action=2

long TListPanel::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) {
    release_mouse();
    this->mouse_scroll_up = 0;
    this->mouse_scroll_down = 0;
    if (this->parent_panel != 0 && this->cur_line > -1 && this->cur_line < this->num_lines) {
        this->parent_panel->action(this, 2, this->cur_line, 0);
    }
    return 1;
}
