// VA: 00521620 TRIBE_Game::close_game_screens (355 B)
// PDB source: tribegam.cpp
// Packet-grounded: destroy all dialog/overlay panels

extern int TPanelSystem_destroyPanel(void* panelSys, const char* name);
extern void* panel_system;  // 0x62E870

void TRIBE_Game_close_game_screens(void* self, int destroyGameScreen)
{
    TPanelSystem_destroyPanel(panel_system, "Object List Dialog");
    TPanelSystem_destroyPanel(panel_system, "OKDialog");
    TPanelSystem_destroyPanel(panel_system, "YesNoDialog");
    TPanelSystem_destroyPanel(panel_system, "RestartDialog");
    TPanelSystem_destroyPanel(panel_system, "QuitGameDialog");
    TPanelSystem_destroyPanel(panel_system, "CloseProgramDialog");
    TPanelSystem_destroyPanel(panel_system, "QuitAndLoadDialog");
    TPanelSystem_destroyPanel(panel_system, "ResignDialog");
    TPanelSystem_destroyPanel(panel_system, "Help Dialog");
    TPanelSystem_destroyPanel(panel_system, "About Dialog");
    TPanelSystem_destroyPanel(panel_system, "Send Quick Message Dialog");
    TPanelSystem_destroyPanel(panel_system, "Mission Dialog");
    TPanelSystem_destroyPanel(panel_system, "Send Message Dialog");
    TPanelSystem_destroyPanel(panel_system, "Diplomacy Dialog");
    TPanelSystem_destroyPanel(panel_system, "Menu Dialog");
    TPanelSystem_destroyPanel(panel_system, "Save Game Screen");
    TPanelSystem_destroyPanel(panel_system, "Load Saved Game Screen");
    TPanelSystem_destroyPanel(panel_system, "End Screen");
    TPanelSystem_destroyPanel(panel_system, "Achievements Screen");
    TPanelSystem_destroyPanel(panel_system, "Multiplayer Wait Screen");
    TPanelSystem_destroyPanel(panel_system, "Multiplayer Disconnect Screen");
    
    if (destroyGameScreen) {
        *(int*)((char*)self + 0xC24) = 0;
        TPanelSystem_destroyPanel(panel_system, "Game Screen");
    }
}
