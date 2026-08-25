extern TPanelSystem panel_system;


void RGE_Base_Game::disable_input() {
    if (this->is_mouse_on != 0) {
        void* cursor = LoadCursorA(0, (const char*)0x7F02);
        set_mouse_cursor(cursor);
    }
    panel_system.DisableInput();
    this->input_enabled = 0;
    if (this->input_disabled_window != 0) {
        if (GetCapture()) {
            ReleaseCapture();
        }
        SetCapture(this->input_disabled_window);
    }
}
