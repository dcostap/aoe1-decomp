// TListPanel::key_down_action

long TListPanel::key_down_action(long vk, short param_2, int param_3, int param_4, int param_5) {
    switch (vk) {
    case 0x28:
        this->scroll_cur_line(2, 0, 1);
        return 1;
    case 0x26:
        this->scroll_cur_line(3, 0, 1);
        return 1;
    case 0x23:
        this->scroll_cur_line(4, 0, 1);
        return 1;
    case 0x24:
        this->scroll_cur_line(5, 0, 1);
        return 1;
    case 0x21:
        this->scroll_cur_line(6, 0, 1);
        return 1;
    case 0x22:
        this->scroll_cur_line(7, 0, 1);
        return 1;
    case 0x0D:
        if (this->parent_panel != 0 && this->cur_line > -1 && this->cur_line < this->num_lines) {
        this->parent_panel->action(this, 3, this->cur_line, 0);
        }
        return 1;
    }
    return 0;
}
