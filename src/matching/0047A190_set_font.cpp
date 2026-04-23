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
    virtual void redraw(int mode);

    char gap_04[0xEF];
    unsigned char need_restore;
};

class TMessagePanel : public TPanel {
public:
    char gap_0[0x210];
    void* font;
    long font_wid;
    long font_hgt;
    unsigned char font_color;
    unsigned char back_color;
    char gap_312[2];
    int index_color;

    void set_font(void* param_1, long param_2, long param_3);
};

void TMessagePanel::set_font(void* param_1, long param_2, long param_3) {
    if (this->font != param_1) {
        this->font = param_1;
        this->font_wid = param_2;
        this->font_hgt = param_3;
        this->need_restore = 1;
        this->redraw(1);
    }
}
