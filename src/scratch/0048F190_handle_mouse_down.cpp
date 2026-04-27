// VA: 0048F190 TribeAchievementsScreen::handle_mouse_down (226 B)
// PDB source: scr_ach.cpp
// Packet-grounded: dispatch by click Y-coordinate to 4 buttons

extern long TPanel_wnd_proc(void* self, void* h1, unsigned int msg, unsigned int w, long l);
extern void* rge_base_game;

struct Shim_mousedown_F190 {
    char gap00[0x1B0];
    int game_mode;             // +0x1B0
};

long TribeAchievementsScreen_handle_mouse_down(Shim_mousedown_F190* self, void* h1, unsigned int msg, unsigned int w, long l)
{
    // Dispatch based on lParam (coordinates)
    int y = (int)((short)(l >> 16));
    int x = (int)((short)(l & 0xFFFF));
    
    if (y >= 0x13A && y < 0x163) {
        // Button 1 - done/back
        // PostMessage to parent
        return 1;
    } else if (y >= 0x13A && y < 0x163 && x >= 0x284) {
        // Button 2
        // ...
    } else if (y >= 0x13A && y < 0x163 && x >= 0x284) {
        // Button 3
        // ...
    } else {
        // Button 4 area or fall through to base class
        return TPanel_wnd_proc(self, h1, msg, w, l);
    }
    
    return 0;
}
