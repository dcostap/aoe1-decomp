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

    char gap_04[0x1E4];
    void* font;
    long font_wid;
    long font_hgt;

    void set_redraw(int);
    void set_font(void* param_1, long param_2, long param_3);
};
#endif /* PNL_BTN_SHARED_CONTEXT */

void TButtonPanel::set_font(void* param_1, long param_2, long param_3) {
    this->font = param_1;
    this->font_wid = param_2;
    this->font_hgt = param_3;
    this->set_redraw(1);
}
