extern "C" __declspec(dllimport) void* __stdcall SetCursor(void* hcur);



void RGE_Base_Game::mouse_off() {
    if (is_mouse_on) {
        if (custom_mouse && !windows_mouse) {
            mouse_pointer->off();
            is_mouse_on = 0;
            return;
        }
        SetCursor(0);
        SetClassLongA(prog_window, -12, 0);
        is_mouse_on = 0;
    }
}
