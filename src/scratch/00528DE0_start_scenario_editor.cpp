// VA: 00528DE0 TRIBE_Game::start_scenario_editor (374 B)
// PDB source: tribegam.cpp
// Packet-grounded: start scenario editor with setup calls

extern void* operator_new(unsigned int size);
extern int TPanelSystem_setCurrentPanel(void* panelSys, const char* name);
extern void TRIBE_Game_shutdown_video_system(void* self);

extern void* panel_system;

int TRIBE_Game_start_scenario_editor(void* self)
{
    // EH frame via FS:[0] expected
    
    if (*(int*)((char*)self + 0xC00))
        TRIBE_Game_shutdown_video_system(self);
    
    void* editor = operator_new(0x4B0);
    if (!editor)
        return 0;
    
    // Call TRIBE_Screen_Scenario_Editor constructor
    // ...
    
    if (*(int*)((char*)editor + 0xD8)) {
        // vtable[0](1)
        (*(void(**)(void*, int))(*(int**)editor))(editor, 1);
        return 0;
    }
    
    TPanelSystem_setCurrentPanel(panel_system, "Scenario Editor");
    return 1;
}
