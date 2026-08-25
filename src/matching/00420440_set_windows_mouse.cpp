// VA: 00420440 RGE_Base_Game::set_windows_mouse
// PDB source: basegame.cpp
// Attempt log:
// v0: natural decompiler-shaped source using sibling mouse_on/off declarations.

extern "C" __declspec(dllimport) void* __stdcall SetCursor(void* hcur);



void RGE_Base_Game::set_windows_mouse(int value) {
    if (this->custom_mouse != 0) {
        this->windows_mouse = value;
    } else {
        this->windows_mouse = 1;
    }

    if ((this->custom_mouse != 0) && (this->windows_mouse == 0)) {
        SetCursor(0);
        SetClassLongA(this->prog_window, -12, 0);
        if (this->is_mouse_on != 0) {
            this->mouse_pointer->on();
            return;
        }
        this->mouse_pointer->off();
        return;
    }

    this->mouse_pointer->off();
    if (this->is_mouse_on != 0) {
        SetCursor(this->mouse_cursor);
        SetClassLongA(this->prog_window, -12, (long)this->mouse_cursor);
    } else {
        SetCursor(0);
        SetClassLongA(this->prog_window, -12, 0);
    }
}
