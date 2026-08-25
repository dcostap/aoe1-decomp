// VA: 00422AB0 RGE_Base_Game::enable_input
// basegame.cpp lines 5645-5658
// MATCHED: mirror the nearby disable_input surface exactly.
// The working details were: extern "C" dllimport USER32 declarations, full mouse-related field layout through +0x1DC,
// and a named local for the LoadCursorA result before set_mouse_cursor.

extern TPanelSystem panel_system;


void RGE_Base_Game::enable_input() {
    if (this->input_disabled_window != 0) {
        if (GetCapture()) {
            ReleaseCapture();
        }
    }
    panel_system.EnableInput();
    this->input_enabled = 1;
    if (this->is_mouse_on != 0) {
        void* cursor = LoadCursorA(0, (const char*)0x7F00);
        set_mouse_cursor(cursor);
    }
}
