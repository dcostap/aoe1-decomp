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

    char gap_04[0x20];
    tagRECT clip_rect;

    virtual void draw_rect(tagRECT* rect);
};

void TPanel::draw_rect(tagRECT* rect) {
    tagRECT save_rect;

    save_rect = clip_rect;
    clip_rect = *rect;
    draw();
    clip_rect = save_rect;
}
