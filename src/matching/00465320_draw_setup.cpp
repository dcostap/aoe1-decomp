extern "C" __declspec(dllimport) int __stdcall SelectClipRgn(void* hdc, void* hrgn);

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea {
public:
    char gap_00[0x38];
    void* DrawDc;

    void SetClipRect(tagRECT* rect);
    void Clear(tagRECT* rect, unsigned int color);
};

class TPanel {
public:
    char gap_04[0x1C];
    TDrawArea* render_area;
    tagRECT clip_rect;
    char gap_34[0x54];
    void* clip_rgn;
    char gap_8C[0x63];
    unsigned char color;

    virtual void draw_setup(int clear);
};

void TPanel::draw_setup(int clear) {
    void* dc;
    tagRECT* rect;

    dc = render_area->DrawDc;
    if (dc != 0) {
        SelectClipRgn(dc, clip_rgn);
    }
    rect = &clip_rect;
    render_area->SetClipRect(rect);
    if (clear != 0) {
        render_area->Clear(rect, color);
    }
}
