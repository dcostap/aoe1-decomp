// VA: 00529A70 TRIBE_Game::action_user_command (1135 B)
// PDB source: tribegam.cpp
// Bounded heavy-pass: structurally accurate first-pass dispatch

extern int RGE_Base_Game_action_user_command(void* self, int cmd);
extern int TPanelSystem_handle_command(void* panelSys, int cmd);
extern void* panel_system;

int TRIBE_Game_action_user_command(void* self, int cmd)
{
    // Dispatch user commands
    // ...
    
    // Call base class
    RGE_Base_Game_action_user_command(self, cmd);
    
    // Panel system handles commands too
    TPanelSystem_handle_command(panel_system, cmd);
    
    // Mode-specific handling
    // ...
    
    return 0;
}
