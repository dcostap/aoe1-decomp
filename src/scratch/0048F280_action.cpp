// VA: 0048F280 TribeAchievementsScreen::action (638 B)
// PDB source: scr_ach.cpp
// Packet-grounded: dispatch by action ID to buttons

extern int TPanel_wnd_proc(void* self, void* h1, unsigned int msg, unsigned int w, long l);
extern int PostMessageA(void* hwnd, unsigned int msg, unsigned int w, long l);
extern void* rge_base_game;

struct Shim_action_F280 {
    char gap00[0x1B0];
    int game_mode;             // +0x1B0
};

long TribeAchievementsScreen_action(Shim_action_F280* self, void* h1, unsigned int msg, unsigned int w, long l)
{
    // Switch on action ID (lParam)
    int actionId = (int)l;
    
    if (actionId == 0x1BF) {
        // Button 0 - scroll left or similar
        // ...
        return 0;
    }
    
    if (actionId == 0x1C0) {
        // Button 1
        // ...
        return 0;
    }
    
    if (actionId == 0x1C1) {
        // Button 2
        // ...
        return 0;
    }
    
    if (actionId == 0x406 || actionId == 0x407) {
        // Back/done button
        if (self->game_mode == 4 || self->game_mode == 5 || 
            self->game_mode == 6 || self->game_mode == 7) {
            PostMessageA(*(void**)((char*)rge_base_game + 0x10), 0x111, 0x1C2, 0);
        } else {
            PostMessageA(*(void**)((char*)rge_base_game + 0x10), 0x111, 0x1C4, 0);
        }
        return 1;
    }
    
    return TPanel_wnd_proc(self, h1, msg, w, l);
}
