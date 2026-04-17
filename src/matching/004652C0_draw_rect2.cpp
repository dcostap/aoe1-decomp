struct tagRECT;

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
    virtual void vf30(void);
    virtual void draw_rect(tagRECT* rect);

    char gap_04[0xEE];
    unsigned char draw_rect2_flag;

    virtual void draw_rect2(tagRECT* rect);
};

void TPanel::draw_rect2(tagRECT* rect) {
    draw_rect2_flag = 1;
    draw_rect(rect);
    draw_rect2_flag = 0;
}
