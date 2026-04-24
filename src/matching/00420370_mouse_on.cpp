class TMousePointer {
public:
    void on();
};

extern "C" __declspec(dllimport) void* __stdcall SetCursor(void*);
extern "C" __declspec(dllimport) long __stdcall SetClassLongA(void*, long, long);

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

    void mouse_on();
};

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
