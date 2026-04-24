extern "C" __declspec(dllimport) void* __stdcall SetCursor(void* hcur);
extern "C" __declspec(dllimport) long __stdcall SetClassLongA(void* hwnd, long index, long value);

class TMousePointer {
public:
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
    char gap_1C4[8];
    int is_mouse_on;
    int windows_mouse;

    void mouse_off();
};

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
