// VA: 00526170 TRIBE_Game::load_game (3152 B)
// PDB source: tribegam.cpp
// Bounded heavy-pass: load saved game from file

extern void* operator_new(unsigned int size);
extern void* fopen(const char* path, const char* mode);
extern int fclose(void* file);
extern int fread(void* buf, int sz, int n, void* file);
extern int fwrite(const void* buf, int sz, int n, void* file);
extern int RGE_Base_Game_disable_input(void* self);
extern int RGE_Base_Game_enable_input(void* self);
extern void TRIBE_Game_show_status_message(void* self, int msgId, void* a, int b);
extern int TPanelSystem_setCurrentPanel(void* panelSys, const char* name);
extern void* panel_system;

int TRIBE_Game_load_game(void* self, const char* filename)
{
    RGE_Base_Game_disable_input(self);
    
    // Open save file
    void* file = fopen(filename, "rb");
    if (!file) {
        RGE_Base_Game_enable_input(self);
        return 0;
    }
    
    // Read header/version
    // ...
    
    // Read game state
    // ...
    
    // Set up scenario
    // ...
    
    fclose(file);
    
    TPanelSystem_setCurrentPanel(panel_system, "Game Screen");
    RGE_Base_Game_enable_input(self);
    return 1;
}
