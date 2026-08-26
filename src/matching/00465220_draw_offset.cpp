#ifndef AOE1_PANEL_CONTEXT_H
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TPanel {
public:
    virtual void draw(void);

    int previousPanel_;
    int previousModalPanel_;
    int pnl_x_;
    int pnl_y_;
    int pnl_wid_;
    int pnl_hgt_;
    int panelName_;
    int render_area_;
    tagRECT clip_rect;

    virtual void draw_offset(long x, long y, tagRECT* rect);
};

#endif
void TPanel::draw_offset(long x, long y, tagRECT* rect) {
    tagRECT save_rect;

    pnl_x_ = pnl_x_ + x;
    pnl_y_ = pnl_y_ + y;
    save_rect = clip_rect;
    clip_rect = *rect;
    draw();
    clip_rect = save_rect;
    pnl_x_ = pnl_x_ - x;
    pnl_y_ = pnl_y_ - y;
}
