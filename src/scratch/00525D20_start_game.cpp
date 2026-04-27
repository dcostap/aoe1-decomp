// VA: 00525D20 TRIBE_Game::start_game (299 B)
// PDB source: tribegam.cpp
// Packet-grounded: start new game with scenario

extern void RGE_Base_Game_disable_input(void* self);
extern void RGE_Base_Game_enable_input(void* self);
extern int TPanelSystem_setCurrentPanel(void* panelSys, const char* name);

extern void* panel_system;

int TRIBE_Game_start_game(void* self)
{
    // Check game mode
    int mode = *(int*)((char*)self + 0x1B0);
    // ...
    
    RGE_Base_Game_disable_input(self);
    
    // Create scenario
    // ...
    
    // Set current panel to game screen
    TPanelSystem_setCurrentPanel(panel_system, "Game Screen");
    
    RGE_Base_Game_enable_input(self);
    return 1;
}
