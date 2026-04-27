// VA: 005213A0 TRIBE_Game::~TRIBE_Game (625 B)
// PDB source: tribegam.cpp
// Packet-grounded: EH-framed, cleanup panels, comm, shutdown systems

extern void operator_delete(void* p);
extern void TPanelSystem_destroyPanel(void* panelSys, const char* name);
extern void TRIBE_Game_close_game_screens(void* self, int flag);

extern void* panel_system;

void TRIBE_Game_dtor(void* self, int flags)
{
    // EH frame via FS:[0]
    
    // Restore vtable
    *(int**)self = (int*)0x5771A8;
    
    // Close game screens
    TRIBE_Game_close_game_screens(self, 1);
    
    // Destroy many panels
    TPanelSystem_destroyPanel(panel_system, "Scenario Editor");
    TPanelSystem_destroyPanel(panel_system, "Scenario Selection Screen");
    TPanelSystem_destroyPanel(panel_system, "Campaign Selection Screen");
    TPanelSystem_destroyPanel(panel_system, "Main Menu");
    TPanelSystem_destroyPanel(panel_system, "Status Screen");
    TPanelSystem_destroyPanel(panel_system, "Game Screen");
    TPanelSystem_destroyPanel(panel_system, "Load Saved Game Screen");
    TPanelSystem_destroyPanel(panel_system, "Save Game Screen");
    TPanelSystem_destroyPanel(panel_system, "Map Editor");
    TPanelSystem_destroyPanel(panel_system, "Player Select Screen");
    TPanelSystem_destroyPanel(panel_system, "Achievements Screen");
    TPanelSystem_destroyPanel(panel_system, "Multiplayer Wait Screen");
    TPanelSystem_destroyPanel(panel_system, "Multiplayer Disconnect Screen");
    TPanelSystem_destroyPanel(panel_system, "Multiplayer User List");
    TPanelSystem_destroyPanel(panel_system, "Multiplayer Name Screen");
    TPanelSystem_destroyPanel(panel_system, "Multiplayer Game Select");
    TPanelSystem_destroyPanel(panel_system, "Multiplayer Setup Screen");
    
    // Shutdown video system if active
    // ...
    
    // Delete comm handler
    // ...
    
    // operator_delete on self if flag&1
    if (flags & 1)
        operator_delete(self);
}
