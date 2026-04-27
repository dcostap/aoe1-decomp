// VA: 00527830 TRIBE_Game::create_game_screen (576 B)
// PDB source: tribegam.cpp
// Packet-grounded: create TRIBE_Screen_Game and set as current panel

extern void* operator_new(unsigned int size);
extern int TPanelSystem_setCurrentPanel(void* panelSys, const char* name);
extern void* panel_system;

int TRIBE_Game_create_game_screen(void* self)
{
    void* gameScreen = operator_new(0xDE8);
    if (!gameScreen)
        return 0;
    
    // Call TRIBE_Screen_Game::TRIBE_Screen_Game constructor
    // (**(void(**)(void*, void*))(*(int**)gameScreen + ...))(gameScreen, this);
    // ...
    
    // Store game screen in self
    *(void**)((char*)self + 0xC24) = gameScreen;
    
    // Set current panel
    TPanelSystem_setCurrentPanel(panel_system, "Game Screen");
    
    return 1;
}
