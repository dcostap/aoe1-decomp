#ifndef PNL_BTN_SHARED_CONTEXT
class TButtonPanel {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(int param_1);

    char gap_04[0x204];
    unsigned long text_color1[9];
    unsigned long text_color2[9];

    void set_redraw(int);
    void set_text_color(int state, unsigned long color1, unsigned long color2);
};
#endif /* PNL_BTN_SHARED_CONTEXT */

void TButtonPanel::set_text_color(int state, unsigned long color1, unsigned long color2) {
    if (state >= 0 && state <= 8) {
        text_color1[state] = color1;
        text_color2[state] = color2;
        set_redraw(1);
    }
}
