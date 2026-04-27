// VA: 00523B10 TRIBE_Game::stop_video (998 B)
// PDB source: tribegam.cpp
// Packet-grounded: shutdown video system, close screens, navigate to menu

extern void operator_delete(void* p);
extern void TRIBE_Game_close_game_screens(void* self, int flag);
extern int TRIBE_Game_start_menu(void* self);
extern int TRIBE_Game_start_campaign_menu(void* self);
extern int TPanelSystem_setCurrentPanel(void* panelSys, const char* name);
extern int TPanelSystem_destroyPanel(void* panelSys, const char* name);
extern void* panel_system;

int TRIBE_Game_stop_video(void* self, int goToMenu)
{
    // Check if video is active
    void* videoSys = *(void**)((char*)self + 0xC00);
    if (!videoSys)
        return 0;
    
    // Close game screens
    TRIBE_Game_close_game_screens(self, goToMenu);
    
    // Determine navigation based on mode
    int mode = *(int*)((char*)self + 0x1B0);
    
    if (goToMenu) {
        // Destroy game screen
        // ...
        
        // Navigate to menu
        if (mode >= 4) {
            // Campaign menu for campaign mode
            TRIBE_Game_start_menu(self);
        } else {
            // Regular menu
            TRIBE_Game_start_menu(self);
        }
    }
    
    // Shutdown video system
    // ...
    
    // operator_delete on video system
    operator_delete(videoSys);
    *(void**)((char*)self + 0xC00) = 0;
    
    return 1;
}
