// attempt 1: direct Time_Line_Panel draw path using the panel dump offsets and the known helper sequence
// target shape: base draw, clear +0x38, gate on +0x20/+0x70/+0x6C, then vcall +0x28, helpers, and vcall +0x2C

#ifndef TPNL_TML_WRAPPER
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea {
public:
    void Clear(tagRECT* rect, unsigned int color);
};

class TPanelParent {
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
    virtual void vf28(int param_1);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void draw_rect(tagRECT* rect);
    virtual void draw_offset(long x, long y, tagRECT* rect);
    virtual void draw_rect2(tagRECT* rect);
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
    virtual void vf28(int param_1);
    virtual void vf2C(void);
    virtual void draw(void);
    virtual void draw_rect(tagRECT* rect);

    char gap_04[0x1C];
    TDrawArea* render_area;
    tagRECT clip_rect;
    char gap_34[0x04];
    int need_redraw;
    char gap_3C[0x04];
    TPanelParent* parent_panel;
    char gap_44[0x28];
    int active;
    int visible;
    char gap_74[0x7B];
    unsigned char color;
    unsigned char fill_in_background;
    char gap_F1[0x01];
    unsigned char draw_rect2_flag;
};

class Time_Line_Panel : public TPanel {
public:
    virtual void draw(void);
    void draw_background(void);
    void draw_border(void);
    void draw_axis(void);
    void draw_timeline(void);
    void draw_special_events(void);
    void draw_civilization_names(void);
};
#endif

void Time_Line_Panel::draw(void) {
    TPanel::draw();
    this->need_redraw = 0;
    if (this->render_area != 0 && this->visible != 0 && this->active != 0) {
        this->vf28(0);
        this->draw_background();
        this->draw_border();
        this->draw_axis();
        this->draw_timeline();
        this->draw_special_events();
        this->draw_civilization_names();
        this->vf2C();
    }
}

void TPanel::draw(void) {
    TDrawArea* area;

    need_redraw = 0;
    area = render_area;
    if (area != 0 && visible != 0 && active != 0) {
        if (fill_in_background == 0 && parent_panel != 0) {
            if (draw_rect2_flag != 0) {
                parent_panel->draw_rect2(&clip_rect);
                return;
            }
            parent_panel->draw_rect(&clip_rect);
            return;
        }
        area->Clear(&clip_rect, color);
    }
}
