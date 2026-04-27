// VA: 00524640 TRIBE_Game::save_game (332 B)
// PDB source: tribegam.cpp
// Packet-grounded: save game state to file

extern void RGE_Base_Game_disable_input(void* self);
extern void RGE_Base_Game_enable_input(void* self);
extern int RGE_Base_Game_singlePlayerGame(void* self);
extern void RGE_Base_Game_set_paused(void* self, int pause, int unk);
extern void TRIBE_Game_show_status_message(void* self, int msgId, void* unk1, int unk2);
extern int TPanelSystem_setCurrentPanel(void* panelSys, const char* name);
extern int TPanelSystem_destroyPanel(void* panelSys, const char* name);

extern void* panel_system;

int TRIBE_Game_save_game(void* self, const char* filename)
{
    int mode = *(int*)((char*)self + 0x1B0);
    if (mode != 4 && mode != 6 && mode != 7 && mode != 5)
        return 0;
    
    RGE_Base_Game_disable_input(self);
    TRIBE_Game_show_status_message(self, 0x451, 0, -1);
    
    // Save game logic
    // ...
    
    if (RGE_Base_Game_singlePlayerGame(self))
        RGE_Base_Game_set_paused(self, 0, 0);
    
    TPanelSystem_setCurrentPanel(panel_system, "Game Screen");
    RGE_Base_Game_enable_input(self);
    return 1;
}
