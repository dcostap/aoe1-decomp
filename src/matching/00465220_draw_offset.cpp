struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
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
    virtual void vf20(void);
    virtual void vf24(void);
    virtual void vf28(void);
    virtual void vf2C(void);
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
