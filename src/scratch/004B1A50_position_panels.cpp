// VA: 004B1A50 TRIBE_Screen_Sed_Open::position_panels (3969 B)
// PDB source: scr_sed2.cpp
// Packet-grounded: position scenario editor panels based on display size

extern int TPanelSystem_findPanel(void* panelSys, const char* name);
extern void TPanel_set_rect(void* panel, int x, int y, int w, int h);
extern int TDrawSystem_getWidth(void* drawSys);
extern int TDrawSystem_getHeight(void* drawSys);
extern void* draw_system;
extern int TPanelSystem_findPanel(void* sys, const char* name);

void TRIBE_Screen_Sed_Open_position_panels(void* self)
{
    // Get draw system dimensions
    int screenW = TDrawSystem_getWidth(draw_system);
    int screenH = TDrawSystem_getHeight(draw_system);
    
    // Find panels
    void* panel;
    
    // Position toolbar/button panels
    panel = (void*)TPanelSystem_findPanel(0, "Scenario Editor");
    if (panel) {
        TPanel_set_rect(panel, 0, 0, screenW, 20);
    }
    
    // Position file list panel
    panel = (void*)TPanelSystem_findPanel(0, "File List");
    if (panel) {
        TPanel_set_rect(panel, 0, 20, 200, screenH - 40);
    }
    
    // Position preview panel
    panel = (void*)TPanelSystem_findPanel(0, "Preview");
    if (panel) {
        TPanel_set_rect(panel, 200, 20, screenW - 200, screenH - 40);
    }
    
    // Position status bar
    panel = (void*)TPanelSystem_findPanel(0, "Status Bar");
    if (panel) {
        TPanel_set_rect(panel, 0, screenH - 20, screenW, 20);
    }
    
    // Many more panel positioning calls based on screen size
    // ...
}
