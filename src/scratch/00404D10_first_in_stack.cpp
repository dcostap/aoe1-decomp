// tried direct if/else and nested if/else shapes; VC5 kept the zero-branch as a different jump basin
// tried the same field offsets with a 23-slot virtual table stub so set_state lands at +0x5c
// remaining mismatch is the very first branch target / layout around the param_1 zero case
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
    int stateValue;
    char gap_14[0xC];
    long field20;
    long field24;

    void first_in_stack(unsigned char value);
    void set_state(unsigned char value);
};

void RGE_Action_Missile::first_in_stack(unsigned char value) {
    if (value == 0) {
        this->set_state(4);
    } else if (this->stateValue != 0) {
        this->set_state(3);
    } else if ((this->field20 == 0xBF800000) || (this->field24 == 0xBF800000)) {
        this->set_state(1);
    } else {
        this->set_state(3);
    }
}
