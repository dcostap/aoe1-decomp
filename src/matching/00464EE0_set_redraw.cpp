extern "C" __declspec(dllimport) int __stdcall InvalidateRect(void* hwnd, const void* rect, int erase);

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea {
public:
    char gap_00[0x04];
    void* Wnd;
};

class TPanel {
public:
    char gap_04[0x1C];
    TDrawArea* render_area;
    tagRECT clip_rect;
    char gap_34[0x04];
    int need_redraw;
    char gap_3C[0x30];
    int active;
    int visible;

    virtual void set_redraw(int mode);
};

void TPanel::set_redraw(int mode) {
    if (mode == 1 && need_redraw == 2) {
        return;
    }
    need_redraw = mode;
    if (mode != 0 && render_area != 0 && visible != 0 && active != 0) {
        InvalidateRect(render_area->Wnd, &clip_rect, 0);
    }
}
