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

    char gap_04[0x1F2];
    short cur_state;

    void set_redraw(int);
    void set_state(short param_1);
};
#endif /* PNL_BTN_SHARED_CONTEXT */

void TButtonPanel::set_state(short param_1) {
    this->cur_state = param_1;
    this->set_redraw(1);
}
