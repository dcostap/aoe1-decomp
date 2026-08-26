// compact list double-click handler first
// expected basin: call goto_item on the click target, then if the parent panel exists and the current line is in range, fire the slot 0xB4 action

long TListPanel::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) {
    this->goto_item(param_1, param_2);
    if (this->parent_panel != 0 && this->cur_line > -1 && this->cur_line < this->num_lines) {
        this->parent_panel->action(this, 3, this->cur_line, 0);
    }
    return 1;
}
