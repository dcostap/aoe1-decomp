#ifndef TACT_REP_CONTEXT_H
class TRIBE_Action_Repair {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void first_in_stack(unsigned char value);
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

    char gap_04[0xC];
    void* target_obj;
};
#endif

void TRIBE_Action_Repair::first_in_stack(unsigned char value) {
    if (value != 0 && this->target_obj != 0) {
        this->set_state(4);
        return;
    }
    this->set_state(3);
}
