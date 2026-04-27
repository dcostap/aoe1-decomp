// VA: 005237B0 TRIBE_Game::start_video (804 B)
// PDB source: tribegam.cpp
// Packet-grounded: set up video system with full init chain

extern void* operator_new(unsigned int size);
extern int TPanelSystem_setCurrentPanel(void* panelSys, const char* name);
extern void TRIBE_Game_shutdown_video_system(void* self);
extern void TRIBE_Game_setup_video_system(void* self);

extern void* panel_system;

int TRIBE_Game_start_video(void* self, int width, int height, int bpp)
{
    // Shutdown existing video if any
    if (*(int*)((char*)self + 0xC00))
        TRIBE_Game_shutdown_video_system(self);
    
    // Create draw system
    TRIBE_Game_setup_video_system(self);
    
    // Init draw system with requested video mode
    // ...
    
    // Load palette
    // ...
    
    // Create surfaces
    // ...
    
    return 1;
}
