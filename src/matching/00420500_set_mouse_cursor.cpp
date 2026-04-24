// RGE_Base_Game::set_mouse_cursor at 00420500 (basegame.cpp lines 3448-3457)
// Inventory: 00420500_set_mouse_cursor
// Status: first pass — building to compare

// Forward declarations for class types used in layout (only sizes matter)
class RGE_Game_Info;
class RGE_Scenario_File_Info;
class RGE_Prog_Info;

class RGE_Base_Game {
public:
    void*                     vtable_ptr;        // +0x00
    RGE_Game_Info*            player_game_info;  // +0x04
    RGE_Scenario_File_Info*   scenario_info;     // +0x08
    RGE_Prog_Info*            prog_info;         // +0x0C
    void*                     prog_window;       // +0x10
    char                      gap_14[0x40]; // +0x14..0x53 filler (0x54 - 0x14 = 0x40)
    int                       custom_mouse;      // +0x54
    char                      gap_58[0x174]; // +0x58..0xCA filler (0x1CC - 0x58 = 0x174)
    int                       is_mouse_on;       // +0x1CC
    int                       windows_mouse;     // +0x1D0
    void*                     mouse_cursor;      // +0x1D4

    void set_mouse_cursor(void* new_cursor);
};


// Global last_mouse_cursor (declared in some compilation unit)
extern "C" void* last_mouse_cursor;

// Windows API functions (via USER32.DLL imported IAT)
extern "C" __declspec(dllimport) void* __stdcall SetCursor(void* hCursor);
extern "C" __declspec(dllimport) unsigned long __stdcall SetClassLongA(void* hWnd, int nIndex, unsigned long dwNewLong);

void RGE_Base_Game::set_mouse_cursor(void* new_cursor) {
    this->mouse_cursor = new_cursor;

    if (new_cursor != 0) {
        last_mouse_cursor = new_cursor;
    }

    if (this->is_mouse_on == 0) {
        return;
    }

    if (this->custom_mouse != 0) {
        if (this->windows_mouse == 0) {
            return;
        }
    }

    SetCursor(this->mouse_cursor);
    SetClassLongA(this->prog_window, 0xFFFFFFF4, (unsigned long)this->mouse_cursor);
}
