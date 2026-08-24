// tried both `value * work_rate`, `work_rate *= value`, an explicit result local, a rewrite-through-value-parameter form, and a volatile RHS load; VC5 stayed in the fld-work_rate / fmul-value basin
// the remaining gap is now isolated to that FPU operand-load order in the special attribute==0x0D path
#ifndef RGE_MAC_OBJ_SHARED_CONTEXT
class RGE_Master_Moving_Object {
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
    virtual void vf5C(void);
    virtual void vf60(void);
    virtual void vf64(void);
    virtual void vf68(void);
    virtual void vf6C(void);
    virtual void modify_percent(float value, unsigned char attribute);
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    char gap_04[0xE0];
    float work_rate;

    void modify_percent(float value, unsigned char attribute);
};
#endif

void RGE_Master_Action_Object::modify_percent(float value, unsigned char attribute) {
    if (attribute != 0x0D) {
        RGE_Master_Moving_Object::modify_percent(value, attribute);
        return;
    }
    value = value * this->work_rate;
    this->work_rate = value;
}
