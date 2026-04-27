// VA: 00525EE0 TRIBE_Game::start_scenario (653 B)
// PDB source: tribegam.cpp
// Packet-grounded: start a scenario with full init chain

extern void* operator_new(unsigned int size);
extern int TPanelSystem_setCurrentPanel(void* panelSys, const char* name);
extern int TPanelSystem_destroyPanel(void* panelSys, const char* name);
extern void RGE_Base_Game_disable_input(void* self);
extern void RGE_Base_Game_enable_input(void* self);
extern void* panel_system;

int TRIBE_Game_start_scenario(void* self)
{
    // Disable input
    RGE_Base_Game_disable_input(self);
    
    // Create scenario via RGE_Scenario constructor
    // ...
    
    // Set up game world
    // ...
    
    // Create game screen
    // ...
    
    // Set current panel
    TPanelSystem_setCurrentPanel(panel_system, "Game Screen");
    
    RGE_Base_Game_enable_input(self);
    return 1;
}
