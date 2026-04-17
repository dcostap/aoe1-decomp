extern "C" __declspec(dllimport) void* __stdcall SetCapture(void* hwnd);

class TPanel;
class TPanelSystem {
public:
    TPanel* mouseOwner(void);
    void setMouseOwner(TPanel* owner);
};

extern TPanelSystem panel_system;

class TDrawArea {
public:
    char gap_00[0x04];
    void* Wnd;
};

class TPanel {
public:
    char gap_00[0x20];
    TDrawArea* render_area;
    char gap_24[0x44];
    int mouse_captured;

    int capture_mouse(void);
};

int TPanel::capture_mouse(void) {
    TPanel* owner;

    owner = panel_system.mouseOwner();
    if (owner != 0) {
        owner = panel_system.mouseOwner();
        if (owner != this) {
            return 0;
        }
    }
    if (panel_system.mouseOwner() == this) {
        return 1;
    }
    SetCapture(render_area->Wnd);
    panel_system.setMouseOwner(this);
    mouse_captured = 1;
    return 1;
}
