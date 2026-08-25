// RGE_Base_Game::set_mouse_cursor at 00420500 (basegame.cpp lines 3448-3457)
// Inventory: 00420500_set_mouse_cursor
// Status: first pass â€” building to compare

// Forward declarations for class types used in layout (only sizes matter)
class RGE_Game_Info;
class RGE_Scenario_File_Info;
class RGE_Prog_Info;



// Global last_mouse_cursor (declared in some compilation unit)
extern "C" void* last_mouse_cursor;

// Windows API functions (via USER32.DLL imported IAT)
extern "C" __declspec(dllimport) void* __stdcall SetCursor(void* hCursor);

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
