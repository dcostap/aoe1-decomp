

extern "C" __declspec(dllimport) void* __stdcall SetCursor(void*);


void RGE_Base_Game::mouse_on() {
    if (this->is_mouse_on == 0) {
        if ((this->custom_mouse != 0) && (this->windows_mouse == 0)) {
            this->mouse_pointer->on();
            this->is_mouse_on = 1;
            return;
        }
        SetCursor(this->mouse_cursor);
        SetClassLongA(this->prog_window, -12, (long)this->mouse_cursor);
        this->is_mouse_on = 1;
    }
}
