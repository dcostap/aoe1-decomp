// VA: 005243A0 TRIBE_Game::restart_game (389 B)
// PDB source: tribegam.cpp
// Packet-grounded: restart game with confirmation and cleanup

extern void RGE_Base_Game_disable_input(void* self);
extern void RGE_Base_Game_enable_input(void* self);
extern int TPanelSystem_setCurrentPanel(void* panelSys, const char* name);
extern int TPanelSystem_destroyPanel(void* panelSys, const char* name);

extern void* panel_system;

int TRIBE_Game_restart_game(void* self)
{
    // Close game screens
    // destroy "Game Screen" panel
    
    // Disable input
    RGE_Base_Game_disable_input(self);
    
    // Cleanup and restart
    // ...
    
    // Set panel back
    TPanelSystem_setCurrentPanel(panel_system, "Game Screen");
    TPanelSystem_destroyPanel(panel_system, "RestartDialog");
    
    RGE_Base_Game_enable_input(self);
    return 1;
}
