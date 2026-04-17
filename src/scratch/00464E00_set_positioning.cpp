// STATUS: blocked
// BLOCKER: body size and tail match, but VC5 still hoists the max-width load ahead of the mode/left/top setup, so the prologue/store order diverges from the original
// NOTE: field offsets, virtual call offsets, and later min/max/panel store sequence are understood; remaining drift is early parameter scheduling only

struct TDrawArea {
    char gap_00[0x18];
    long width;
    long height;
};

class TPanel {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(int mode);
    virtual void vf24(void);
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void vf34(void);
    virtual void vf38(void);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void vf44(void);
    virtual void vf48(void);
    virtual void vf4C(void);
    virtual void vf50(long width, long height);

    char gap_04[0x1C];
    TDrawArea* render_area;
    char gap_24[0x10];
    int position_mode;
    char gap_38[0x0C];
    TPanel* left_panel;
    TPanel* top_panel;
    TPanel* right_panel;
    TPanel* bottom_panel;
    char gap_54[0x18];
    int redraw_mode;
    char gap_70[0x2C];
    int left_border;
    int top_border;
    int right_border;
    int bottom_border;
    int min_wid;
    int max_wid;
    int min_hgt;
    int max_hgt;

    void set_positioning(
        int mode,
        long left,
        long top,
        long right,
        long bottom,
        long min_width,
        long max_width,
        long min_height,
        long max_height,
        TPanel* leftPanel,
        TPanel* topPanel,
        TPanel* rightPanel,
        TPanel* bottomPanel
    );
};

void TPanel::set_positioning(
    int mode,
    long left,
    long top,
    long right,
    long bottom,
    long min_width,
    long max_width,
    long min_height,
    long max_height,
    TPanel* leftPanel,
    TPanel* topPanel,
    TPanel* rightPanel,
    TPanel* bottomPanel
) {
    TDrawArea* area;
    int local_mode;
    long local_left;
    long local_top;

    local_mode = mode;
    local_left = left;
    local_top = top;
    position_mode = local_mode;
    right_border = right;
    max_wid = max_width;
    left_border = local_left;
    top_border = local_top;
    left_panel = leftPanel;
    bottom_border = bottom;
    min_wid = min_width;
    bottom_panel = bottomPanel;
    area = render_area;
    min_hgt = min_height;
    max_hgt = max_height;
    top_panel = topPanel;
    right_panel = rightPanel;
    if (area != 0) {
        vf50(area->width, area->height);
    } else {
        vf50(0, 0);
    }
    if (redraw_mode != 0) {
        vf20(2);
    }
}
