class TRIBE_Action_Artifact {
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
    virtual void vf5C(int value);

    char gap_04[0x0C];
    void* field_10;
    char gap_14[0x0C];
    int field_20;
    int field_24;

    void first_in_stack(unsigned char value);
};

void TRIBE_Action_Artifact::first_in_stack(unsigned char value) {
    if (value == 0) {
        return;
    }
    if (this->field_10 != 0) {
        this->vf5C(5);
        return;
    }
    if ((this->field_20 != (int)0xBF800000) && (this->field_24 != (int)0xBF800000)) {
        this->vf5C(4);
        return;
    }
    this->vf5C(6);
}
