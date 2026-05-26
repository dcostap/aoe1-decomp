// VA: 00420440 RGE_Base_Game::set_windows_mouse
// PDB source: basegame.cpp
// Attempt log:
// v0: natural decompiler-shaped source using sibling mouse_on/off declarations.

extern "C" __declspec(dllimport) void* __stdcall SetCursor(void* hcur);
extern "C" __declspec(dllimport) long __stdcall SetClassLongA(void* hwnd, long index, long value);

class TMousePointer {
public:
    void on();
    void off();
};

class RGE_Base_Game {
public:
    char gap_00[0x10];
    void* prog_window;
    char gap_14[0x40];
    void* custom_mouse;
    char gap_58[0x168];
    TMousePointer* mouse_pointer;
    char gap_1C4[0x08];
    int is_mouse_on;
    int windows_mouse;
    void* mouse_cursor;

    void set_windows_mouse(int value);
};

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
