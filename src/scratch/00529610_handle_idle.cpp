// VA: 00529610 TRIBE_Game::handle_idle (867 B)
// PDB source: tribegam.cpp
// Packet-grounded: idle dispatcher based on game mode

extern int RGE_Base_Game_handle_idle(void* self);
extern void TRIBE_Game_show_ai(void* self);
extern int TCommunications_Handler_ReceiveMessages(void* comm);
extern int TPanelSystem_handle_idle(void* panelSys);

extern void* panel_system;

int TRIBE_Game_handle_idle(void* self, int frameCount)
{
    // Call base class handle_idle
    RGE_Base_Game_handle_idle(self);
    
    // Check game mode
    int mode = *(int*)((char*)self + 0x1B0);
    
    switch (mode) {
        case 0: case 1: case 2: case 3:
            // Menu/briefing modes
            break;
            
        case 4: case 5: case 6: case 7:
            // In-game modes
            if (*(int*)((char*)self + 0x18C)) {
                // Receive network messages
                TCommunications_Handler_ReceiveMessages(*(void**)((char*)self + 0x18C));
            }
            
            // Handle panel idle
            TPanelSystem_handle_idle(panel_system);
            
            // Show AI debug if enabled
            // ...
            break;
    }
    
    return 1;
}
