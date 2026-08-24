#ifndef ACT_ENTR_CONTEXT_H
class RGE_Action_Enter {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0c(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1c(void);
    virtual void vf20(void);
    virtual void vf24(void);
    virtual void vf28(void);
    virtual void vf2c(void);
    virtual void vf30(void);
    virtual void vf34(void);
    virtual void vf38(void);
    virtual void vf3c(void);
    virtual void vf40(void);
    virtual void vf44(void);
    virtual void vf48(void);
    virtual void vf4c(void);
    virtual void vf50(void);
    virtual void vf54(void);
    virtual void vf58(void);
    virtual void set_state(unsigned char value);
    virtual void first_in_stack(unsigned char param_1);
};
#endif

void RGE_Action_Enter::first_in_stack(unsigned char param_1) {
    this->set_state(4);
}
