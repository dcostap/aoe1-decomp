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
    virtual void vf28(void);
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
    virtual void vf28(void);
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
