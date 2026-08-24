extern "C" __declspec(dllimport) int __stdcall ReleaseCapture(void);

#ifndef AOE1_PANEL_CONTEXT_H
class TPanel;
class TPanelSystem {
public:
    TPanel* mouseOwner(void);
    void setMouseOwner(TPanel* owner);
};

extern TPanelSystem panel_system;

class TPanel {
public:
    char gap_00[0x68];
    int mouse_captured;

    void release_mouse(void);
};

#endif
void TPanel::release_mouse(void) {
    if (mouse_captured != 0) {
        if (panel_system.mouseOwner() == this) {
            panel_system.setMouseOwner(0);
            ReleaseCapture();
        }
        mouse_captured = 0;
    }
}
