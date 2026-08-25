// attempt 1: direct Time_Line_Panel draw path using the panel dump offsets and the known helper sequence
// target shape: base draw, clear +0x38, gate on +0x20/+0x70/+0x6C, then vcall +0x28, helpers, and vcall +0x2C
// BINARY NOTE: the panel setup and finish calls use the inherited draw_setup and draw_finish slots.

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

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(tagRECT*);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                 long, long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void redraw(int);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw(void);
    virtual void draw_rect(tagRECT*);
    virtual void draw_offset(long, long, tagRECT*);
    virtual void draw_rect2(tagRECT*);

    char gap_04[0x1C];
    TDrawArea* render_area;
    tagRECT clip_rect;
    char gap_34[0x04];
    int need_redraw;
    char gap_3C[0x04];
    TPanel* parent_panel;
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
        this->draw_setup(0);
        this->draw_background();
        this->draw_border();
        this->draw_axis();
        this->draw_timeline();
        this->draw_special_events();
        this->draw_civilization_names();
        this->draw_finish();
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
