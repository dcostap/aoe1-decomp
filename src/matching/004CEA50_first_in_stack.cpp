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
    virtual void set_state(unsigned char param_1);
};

class TRIBE_Action_Heal : public RGE_Action {
public:
    char gap_04[0x0C];
    void* actionObject;
    char gap_14[0x18];

    void first_in_stack(unsigned char param_1);
};

void TRIBE_Action_Heal::first_in_stack(unsigned char) {
    if (this->actionObject != 0) {
        short kind = *(short*)(*(char**)((char*)this->actionObject + 8) + 0x14);
        if (kind == 0x15 || kind == 2 || kind == 0x14 || kind == 0x16) {
            return;
        }
        this->set_state(4);
        return;
    }
    this->set_state(3);
}
