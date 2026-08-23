#ifndef TACT_TRD_SHARED_CONTEXT
class TRIBE_Action_Trade {
public:
    char gap_00[4];
    class TRIBE_Action_Trade_Child* child;
    char gap_0C[4];
    int field_10;

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
    virtual void vf5C(int value);

    void first_in_stack(unsigned char param_1);
};

class TRIBE_Action_Trade_Child {
public:
    char gap_00[0x4C];
    short field_4C;
};
#endif

void TRIBE_Action_Trade::first_in_stack(unsigned char param_1) {
    if (this->child->field_4C != 0 && this->child->field_4C != 2 && this->child->field_4C != 1) {
        this->child->field_4C = 1;
    }
    if (param_1 != 0) {
        if (this->field_10 != 0) {
            this->vf5C(4);
            return;
        }
        this->vf5C(2);
        return;
    }
    this->vf5C(3);
}
