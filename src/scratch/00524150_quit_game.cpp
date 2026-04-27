// VA: 00524150 TRIBE_Game::quit_game (582 B)
// PDB source: tribegam.cpp
// Packet-grounded: quit game with cleanup, panel navigation

extern void TRIBE_Game_close_game_screens(void* self, int flag);
extern void TRIBE_Game_disconnect_multiplayer_game(void* self);
extern int TRIBE_Game_start_menu(void* self);
extern int TRIBE_Game_start_campaign_menu(void* self);
extern int RGE_Base_Game_multiplayerGame(void* self);
extern int RGE_Base_Game_set_paused(void* self, int a, int b);
extern int TPanelSystem_destroyPanel(void* panelSys, const char* name);
extern void* panel_system;

int TRIBE_Game_quit_game(void* self)
{
    // Check game mode
    int mode = *(int*)((char*)self + 0x1B0);
    
    // Close game screens (but keep game screen)
    TRIBE_Game_close_game_screens(self, 1);
    
    // Set paused
    RGE_Base_Game_set_paused(self, 1, 0);
    
    // Determine cleanup based on mode
    if (mode == 4 || mode == 5 || mode == 6 || mode == 7) {
        // In-game: disconnect MP if needed, then go to menu
        if (RGE_Base_Game_multiplayerGame(self))
            TRIBE_Game_disconnect_multiplayer_game(self);
        
        // Destroy game screen
        TPanelSystem_destroyPanel(panel_system, "Game Screen");
        
        // Go to campaign menu or main menu
        // ...
        
        return 1;
    }
    
    // Other modes: destroy panels and start menu
    // ...
    
    return 0;
}
