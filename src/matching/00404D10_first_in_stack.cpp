// PDB owner: RGE_Action_Missile::first_in_stack, ACT_misl.cpp lines 58-68.
// BINARY NOTE: The target-null and sentinel tests are one compound guard.
// This keeps one set_state(3) call site and the original fault order.
//
// 00404D10 RGE_Action_Missile::first_in_stack (62B)
// ACT_misl.cpp

#ifndef ACT_MISL_SHARED_CONTEXT
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
#endif

void RGE_Action_Missile::first_in_stack(unsigned char value) {
    if (value != 0) {
#ifdef ACT_MISL_SHARED_CONTEXT
        if (this->target_obj == 0 &&
            (*(int*)&this->target_x == 0xBF800000 ||
             *(int*)&this->target_y == 0xBF800000)) {
            set_state(1);
        } else {
            set_state(3);
        }
#else
        if (stateValue == 0 &&
            (field20 == 0xBF800000 || field24 == 0xBF800000)) {
            set_state(1);
        } else {
            set_state(3);
        }
#endif
    } else {
        set_state(4);
    }
}
