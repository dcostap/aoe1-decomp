// ACCEPTED_DRIFT: 7 bytes (11%) block ordering diff - VC5 inverts JNE/JE for
// field24 check and flips set_state(1)/set_state(3) block order. Behavior identical.
//
// 00404D10 RGE_Action_Missile::first_in_stack (62B)
// ACT_misl.cpp

class RGE_Action {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void set_state(unsigned char param_1);
};

class RGE_Action_Missile : public RGE_Action {
public:
    char gap_04[0xC];
    int stateValue;        // +0x10
    char gap_14[0xC];
    int field20;           // +0x20
    int field24;           // +0x24

    void first_in_stack(unsigned char value);
    void set_state(unsigned char value);
};

void RGE_Action_Missile::first_in_stack(unsigned char value) {
    if (value != 0) {
        if (stateValue == 0) {
            if (field20 == 0xBF800000 || field24 == 0xBF800000) {
                set_state(1);
            } else {
                set_state(3);
            }
        } else {
            set_state(3);
        }
    } else {
        set_state(4);
    }
}
