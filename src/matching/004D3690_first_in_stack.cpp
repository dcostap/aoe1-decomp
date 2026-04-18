class FirstInStackHost {
public:
    virtual void vf00(void);
    virtual void vf01(void);
    virtual void vf02(void);
    virtual void vf03(void);
    virtual void vf04(void);
    virtual void vf05(void);
    virtual void vf06(void);
    virtual void vf07(void);
    virtual void vf08(void);
    virtual void vf09(void);
    virtual void vf10(void);
    virtual void vf11(void);
    virtual void vf12(void);
    virtual void vf13(void);
    virtual void vf14(void);
    virtual void vf15(void);
    virtual void vf16(void);
    virtual void vf17(void);
    virtual void vf18(void);
    virtual void vf19(void);
    virtual void vf20(void);
    virtual void vf21(void);
    virtual void vf22(void);
    virtual void vf23(int arg);
    void first_in_stack(unsigned char v);
};

void FirstInStackHost::first_in_stack(unsigned char v) {
    if (v) {
        this->vf23(2);
    }
}
