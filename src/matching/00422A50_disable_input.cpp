extern "C" __declspec(dllimport) void* __stdcall LoadCursorA(void*, unsigned int);
extern "C" __declspec(dllimport) void* __stdcall GetCapture(void);
extern "C" __declspec(dllimport) void __stdcall ReleaseCapture(void);
extern "C" __declspec(dllimport) void* __stdcall SetCapture(void*);

class TPanelSystem {
public:
    void DisableInput();
};

extern TPanelSystem panel_system;

class RGE_Base_Game {
public:
    char gap_00[0x1CC];
    int is_mouse_on;
    int windows_mouse;
    void* mouse_cursor;
    int input_enabled;
    void* input_disabled_window;

    void set_mouse_cursor(void*);
    void disable_input();
};

void RGE_Base_Game::disable_input() {
    if (this->is_mouse_on != 0) {
        void* cursor = LoadCursorA(0, 0x7F02);
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
