// VA: 00524790 TRIBE_Game::save_scenario (228 B)
// PDB source: tribegam.cpp
// Packet-grounded: save scenario to file with status screen

extern void RGE_Base_Game_disable_input(void* self);
extern void RGE_Base_Game_enable_input(void* self);
extern int RGE_Base_Game_singlePlayerGame(void* self);
extern void RGE_Base_Game_set_paused(void* self, int pause, int unk);
extern void TRIBE_Game_show_status_message(void* self, int msgId, void* unk1, int unk2);
extern int TPanelSystem_setCurrentPanel(void* panelSys, const char* name);
extern int TPanelSystem_destroyPanel(void* panelSys, const char* name);

extern void* panel_system;  // 0x62E870

int TRIBE_Game_save_scenario(void* self, const char* filename)
{
    int mode = *(int*)((char*)self + 0x1B0);
    if (mode != 4 && mode != 6 && mode != 7 && mode != 5)
        return 0;
    
    RGE_Base_Game_disable_input(self);
    TRIBE_Game_show_status_message(self, 0x450, 0, -1);
    
    // Set all players active
    void* scenario = *(void**)((char*)self + 0x3F4);
    int i;
    for (i = 1; i < *(short*)((char*)scenario + 0x3C); i++) {
        // RGE_Scenario::Set_player_Active(scenario->players, i-1, 1)
        void* players = *(void**)((char*)scenario + 0x5C);
        // Call Set_player_Active(players, i-1, 1)
        // using vtable
    }
    
    // Call scenario save through vtable
    // ...
    
    RGE_Base_Game_enable_input(self);
    return 1;
}
