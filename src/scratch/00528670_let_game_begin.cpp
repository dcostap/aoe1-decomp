// VA: 00528670 TRIBE_Game::let_game_begin (1779 B)
// PDB source: tribegam.cpp
// Bounded heavy-pass: start game after player setup

extern void RGE_Base_Game_disable_input(void* self);
extern void RGE_Base_Game_enable_input(void* self);
extern int TPanelSystem_setCurrentPanel(void* panelSys, const char* name);
extern int TPanelSystem_destroyPanel(void* panelSys, const char* name);
extern int TRIBE_Game_create_game_screen(void* self);
extern void TRIBE_Game_show_status_message(void* self, int msgId, void* a, int b);
extern void* panel_system;

int TRIBE_Game_let_game_begin(void* self)
{
    RGE_Base_Game_disable_input(self);
    
    // Show loading status
    TRIBE_Game_show_status_message(self, 0x453, 0, -1);
    
    // Create game screen
    TRIBE_Game_create_game_screen(self);
    
    // Destroy selection screen
    TPanelSystem_destroyPanel(panel_system, "Scenario Selection Screen");
    
    // Set current panel
    TPanelSystem_setCurrentPanel(panel_system, "Game Screen");
    
    RGE_Base_Game_enable_input(self);
    return 1;
}
