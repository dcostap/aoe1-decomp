// first pass: if the flag is zero, force state 2; otherwise require both timing floats to be non-negative for state 11
// tried direct returns, nested ifs, and split fail labels; the remaining mismatch is now just block-layout drift in the zero-vs-compare fail path order

extern float DAT_0056E6B8;

class RGE_Action {
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
    virtual void vf34(void);
    virtual void vf38(void);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void vf44(void);
    virtual void vf48(void);
    virtual void vf4C(void);
    virtual void vf50(void);
    virtual void vf54(void);
    virtual void vf58(void);
    virtual void set_state(unsigned char value);
};

class RGE_Action_Transport : public RGE_Action {
public:
    char gap_04[0x1C];
    float field_20;
    float field_24;

    virtual void first_in_stack(unsigned char value);
};

void RGE_Action_Transport::first_in_stack(unsigned char value) {
    if (value == 0) {
        goto fail_zero;
    }
    if (this->field_20 < DAT_0056E6B8) {
        goto fail_cmp;
    }
    if (this->field_24 < DAT_0056E6B8) {
        goto fail_cmp;
    }

    this->set_state(11);
    return;

fail_cmp:
    {
        RGE_Action* action = this;
        action->set_state(2);
    }
    return;

fail_zero:
    this->set_state(2);
}
