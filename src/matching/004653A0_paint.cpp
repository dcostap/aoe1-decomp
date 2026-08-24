#ifndef AOE1_PANEL_CONTEXT_H
extern "C" __declspec(dllimport) int __stdcall ValidateRect(void* hwnd, const void* rect);
#endif

#ifndef AOE1_PANEL_CONTEXT_H
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawSystem {
public:
    void Paint(tagRECT* rect);
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;
    void* Wnd;
};

class TPanel {
public:
    virtual void paint(void);

    char gap_04[0x1C];
    TDrawArea* render_area;
    tagRECT clip_rect;
    char gap_34[0x38];
    int active;
    int visible;
};

#endif
void TPanel::paint(void) {
    if (render_area != 0 && visible != 0 && active != 0) {
        render_area->DrawSystem->Paint(&clip_rect);
        ValidateRect(render_area->Wnd, &clip_rect);
    }
}
