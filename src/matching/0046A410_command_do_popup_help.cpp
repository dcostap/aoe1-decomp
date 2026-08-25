// attempt 2: natural popup-help command: exit help mode, restore cursor, resolve help text, show help dialog

long TEasy_Panel::command_do_popup_help(unsigned char clicked, long x, long y) {
    long help_page;
    char* temp;
    char help_string2[1000];

    temp = help_string2;
    if (this->help_mode == 1) {
        this->help_mode = 0;
        rge_base_game->set_mouse_cursor(LoadCursorA(0, (const char*)0x7F00));
        rge_base_game->set_mouse_facet(0);
        rge_base_game->mouse_pointer->set_game_enable(this->saved_mouse_mode);
        if (clicked == 1) {
            if (this->get_popup_help(&temp, &help_page, x, y)) {
                this->command_help(this->help_title, help_string2, help_page, x, y);
            }
        }
        return 1;
    }
    return 0;
}
