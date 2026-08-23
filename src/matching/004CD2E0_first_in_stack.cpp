#ifndef TACT_BLD_CONTEXT_H
class RGE_Static_Object;
class TRIBE_Action_Build {
public:
    virtual int vf00(void);
    virtual int vf04(void);
    virtual int vf08(void);
    virtual int vf0C(void);
    virtual int vf10(void);
    virtual int vf14(void);
    virtual int vf18(void);
    virtual int vf1C(void);
    virtual int vf20(void);
    virtual int vf24(void);
    virtual int vf28(void);
    virtual int vf2C(void);
    virtual int vf30(void);
    virtual int vf34(void);
    virtual int vf38(void);
    virtual int vf3C(void);
    virtual int vf40(void);
    virtual int vf44(void);
    virtual int vf48(void);
    virtual int vf4C(void);
    virtual int vf50(void);
    virtual int vf54(void);
    virtual int vf58(void);
    virtual void set_state(int state);
    char gap_04[0x0C];
    RGE_Static_Object* target_obj;

    virtual void first_in_stack(unsigned char value);
};
#endif

void TRIBE_Action_Build::first_in_stack(unsigned char value) {
    if (value != 0) {
        if (this->target_obj != 0) {
            this->set_state(4);
            return;
        }
        this->set_state(3);
        return;
    }
    this->set_state(3);
}
