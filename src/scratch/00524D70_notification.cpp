// VA: 00524D70 TRIBE_Game::notification (3760 B)
// PDB source: tribegam.cpp
// Bounded heavy-pass: show notification messages with sound/image

extern void* operator_new(unsigned int size);
extern int sprintf(char* buf, const char* fmt, ...);
extern int TPanelSystem_setCurrentPanel(void* panelSys, const char* name);
extern int TPanelSystem_destroyPanel(void* panelSys, const char* name);
extern void* panel_system;

int TRIBE_Game_notification(void* self, int type, const char* text, int player)
{
    // Check notification type
    switch (type) {
        case 0: // Achievement
            break;
        case 1: // Tech research complete
            break;
        case 2: // Resource depleted
            break;
        case 3: // Enemy sighted
            break;
        case 4: // Building complete
            break;
        case 5: // Unit killed
            break;
        case 6: // Diplomacy change
            break;
    }
    
    // Show notification panel
    TPanelSystem_setCurrentPanel(panel_system, "Status Screen");
    
    return 1;
}
