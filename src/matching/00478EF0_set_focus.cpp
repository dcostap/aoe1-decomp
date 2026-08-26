// TListPanel::set_focus — matching pattern from mouse_left_dbl_click_action

void TListPanel::set_focus(int focus) {
    TPanel::set_focus(focus);
    if (this->field_78 != 0 && this->parent_panel != 0 &&
        this->cur_line > -1 && this->cur_line < this->num_lines) {
        this->parent_panel->action(this, 1, this->cur_line, 0);
    }
}
