// attempt 1: wrong member offsets, dllimport missing
// attempt 2: fix offsets, dllimport all -> 80 bytes (too small)
// attempt 3: no dllimport -> direct calls, wrong layout
// attempt 4: inline LoadCursorA call, still direct calls
// attempt 5: dllimport+stdcall all -> 80 bytes
// attempt 6: dllimport+stdcall no-arg only -> GetCapture still direct, LoadCursorA has add esp,8
// left in scratch: GetCapture compiles as e8 not ff 15 even with dllimport+stdcall
// LoadCursorA needs __stdcall to avoid add esp,8 but then size changes
// push eax / mov ecx order also different from original

void* __declspec(dllimport) __stdcall GetCapture();
void __declspec(dllimport) __stdcall ReleaseCapture();
void* LoadCursorA(void* instance, unsigned long cursorId);

class TPanelSystem {
public:
    void EnableInput();
};

extern TPanelSystem panel_system;

class RGE_Base_Game {
public:
    char gap_00[0x1CC];
    int is_mouse_on;
    char gap_1D0[0x8];
    int input_enabled;
    void* input_disabled_window;

    void enable_input();
    void set_mouse_cursor(void* cursor);
};

void RGE_Base_Game::enable_input() {
    if (input_disabled_window != 0) {
        if (GetCapture() != 0) {
            ReleaseCapture();
        }
    }
    panel_system.EnableInput();
    input_enabled = 1;
    if (is_mouse_on != 0) {
        set_mouse_cursor(LoadCursorA(0, 0x7F00));
    }
}
