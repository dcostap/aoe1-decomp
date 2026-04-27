// VA: 00526E60 TRIBE_Game::create_game (2512 B)
// PDB source: tribegam.cpp
// Bounded heavy-pass: create new game scenario with options

extern void* operator_new(unsigned int size);
extern int RGE_Base_Game_disable_input(void* self);
extern int RGE_Base_Game_enable_input(void* self);
extern void TRIBE_Game_show_status_message(void* self, int msgId, void* a, int b);
extern int TPanelSystem_setCurrentPanel(void* panelSys, const char* name);
extern int TPanelSystem_destroyPanel(void* panelSys, const char* name);
extern void* panel_system;

int TRIBE_Game_create_game(void* self, int playerCount, int mapSize, int mapType,
                            int resources, int era, int difficulty)
{
    RGE_Base_Game_disable_input(self);
    
    // Create scenario
    // ...
    
    // Set up players
    // ...
    
    // Generate map
    // ...
    
    // Place resources and units
    // ...
    
    TPanelSystem_setCurrentPanel(panel_system, "Game Screen");
    
    RGE_Base_Game_enable_input(self);
    return 1;
}
