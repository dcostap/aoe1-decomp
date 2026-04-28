// TPanel::set_rect (00464C50)
// Panel.cpp:1051-1112, 284 bytes
// __thiscall: ecx=this, 4 stack params, ret 10h

extern "C" __declspec(dllimport) int __stdcall DeleteObject(void* hObject);
extern "C" __declspec(dllimport) void* __stdcall CreateRectRgn(int x1, int y1, int x2, int y2);

class TDrawArea {
public:
    char gap_00[0x18];
    int Width;      // +0x18
    int Height;     // +0x1C
};

class TPanel {
public:
    char gap_04[0x08];
    int pnl_x;                     // +0x0C
    int pnl_y;                     // +0x10
    int pnl_wid;                   // +0x14
    int pnl_hgt;                   // +0x18
    char gap_1C[0x04];
    TDrawArea* render_area;        // +0x20
    int clip_left;                 // +0x24
    int clip_top;                  // +0x28
    int clip_right;                // +0x2C
    int clip_bottom;               // +0x30
    char gap_34[0x0C];
    TPanel* parent_panel;          // +0x40
    char gap_44[0x28];
    int active;                    // +0x6C
    int visible;                   // +0x70
    char gap_74[0x14];
    void* clip_rgn;                // +0x88
    int render_left;               // +0x8C
    int render_top;                // +0x90
    int render_right;              // +0x94
    int render_bottom;             // +0x98
    char gap_9C[0x55];
    char clip_to_parent;           // +0xF1

    virtual void pad00() = 0;
    virtual void pad01() = 0;
    virtual void pad02() = 0;
    virtual void pad03() = 0;
    virtual void pad04() = 0;
    virtual void pad05() = 0;
    virtual void pad06() = 0;
    virtual void pad07() = 0;
    virtual void redraw(int flags) = 0;  // vt[8] = +0x20
    void set_rect(int left, int top, int width, int height);
};

void TPanel::set_rect(int left, int top, int width, int height)
{
    pnl_wid = width;
    pnl_hgt = height;
    int right = left + width - 1;
    int bottom = top + height - 1;

    pnl_x = left;
    pnl_y = top;

    render_left = left;
    render_top = top;
    render_right = right;
    render_bottom = bottom;

    clip_left = left;
    clip_top = top;
    clip_right = right;
    clip_bottom = bottom;

    if (parent_panel != 0 && clip_to_parent != 0) {
        if (left < parent_panel->clip_left) {
            clip_left = parent_panel->clip_left;
        }
        if (top < parent_panel->clip_top) {
            clip_top = parent_panel->clip_top;
        }
        if (right > parent_panel->clip_right) {
            clip_right = parent_panel->clip_right;
        }
        if (bottom > parent_panel->clip_bottom) {
            clip_bottom = parent_panel->clip_bottom;
        }
    }

    if (clip_left < 0) {
        clip_left = 0;
    }
    if (clip_top < 0) {
        clip_top = 0;
    }

    if (render_area != 0) {
        if (clip_right >= render_area->Width) {
            clip_right = render_area->Width - 1;
        }
    }
    if (render_area != 0) {
        if (clip_bottom >= render_area->Height) {
            clip_bottom = render_area->Height - 1;
        }
    }

    if (clip_rgn != 0) {
        DeleteObject(clip_rgn);
        clip_rgn = 0;
    }

    if (clip_right >= clip_left && clip_bottom >= clip_top) {
        visible = 1;
        clip_rgn = CreateRectRgn(clip_left, clip_top, clip_right, clip_bottom);
    } else {
        visible = 0;
    }

    if (active != 0) {
        redraw(2);
    }
}
