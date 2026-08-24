#ifndef PNL_TXT_TU_CONTEXT
class TTextPanel {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void redraw(int value);

    char gap_04[0x150];
    int outline;
    unsigned char outline_color;
    char gap_159[0x17];
    int bevel_type;

    void set_outline(int outline, unsigned char color);
};
#endif

void TTextPanel::set_outline(int outline, unsigned char color) {
    this->outline = outline;
    if (outline != 0) {
        this->bevel_type = 1;
    } else {
        this->bevel_type = 0;
    }
    this->outline_color = color;
    this->redraw(1);
}
