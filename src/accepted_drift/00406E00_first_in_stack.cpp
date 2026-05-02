// ACCEPTED_DRIFT: VC5 inserts add esp,4 after virtual calls (cdecl-style)
// even with __thiscall-declared virtual member functions. The original has
// callee cleanup via ret 4. The FPU comparisons use relocated zero constant
// vs original's hardcoded 56E6B8h address (masked in comparison).
// VA: 00406E00 first_in_stack (70B, act_tran.cpp)

class RGE_Action_Transport {
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
    virtual void method_5C(int param_1);
    char gap_04[0x1C];
    float field_20;
    float field_24;

    void first_in_stack(unsigned char param_1);
};

void RGE_Action_Transport::first_in_stack(unsigned char param_1)
{
    if (param_1 != 0 && this->field_20 >= 0.0f && this->field_24 >= 0.0f) {
        this->method_5C(0xB);
        return;
    }
    this->method_5C(2);
}
