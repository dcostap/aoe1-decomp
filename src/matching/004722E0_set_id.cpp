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

    char gap_04[0xF0];
    long id[9];
    long id2[9];

    void set_id(short param_1, long param_2, long param_3);
};
#endif /* PNL_BTN_SHARED_CONTEXT */

void TButtonPanel::set_id(short param_1, long param_2, long param_3) {
    this->id[param_1] = param_2;
    this->id2[param_1] = param_3;
}
