extern "C" __declspec(dllimport) int __stdcall SelectClipRgn(void* hdc, void* hrgn);

class TDrawArea {
public:
    char gap_00[0x38];
    void* DrawDc;

    void SetClipRect(void* rect);
};

class TPanel {
public:
    char gap_00[0x1C];
    TDrawArea* render_area;
    char gap_24[0x14];
    int need_redraw;
    char gap_3C[0xB7];
    unsigned char need_restore;

    virtual void draw_finish(void);
};

void TPanel::draw_finish(void) {
    void* dc;

    need_redraw = 0;
    dc = render_area->DrawDc;
    if (dc != 0) {
        SelectClipRgn(dc, 0);
    }
    render_area->SetClipRect(0);
    need_restore = 0;
}
