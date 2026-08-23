// attempt log:
// first pass: direct natural branch spelling for the base-hit / state / nested-vcall gate
// second pass: model the +0xBC call with a helper class whose target method is the 49th vfunc
// third pass: remove the fake inherited surface; the main object wants raw +0x40 / +0x2C0 offsets
// fourth pass: use an outer object at +0x40 with the nested pointer at +0x4BC to match the branch length
// keep the base call first, then reject state 2/3 with the nested +0x4BC virtual +0xBC hit

#ifndef TPNL_BTN_SHARED_CONTEXT
class TPanel {
public:
    int is_inside(long x, long y);
};

class TRIBE_Panel_Button_Nested {
public:
    virtual int vf00();
    virtual int vf01();
    virtual int vf02();
    virtual int vf03();
    virtual int vf04();
    virtual int vf05();
    virtual int vf06();
    virtual int vf07();
    virtual int vf08();
    virtual int vf09();
    virtual int vf0A();
    virtual int vf0B();
    virtual int vf0C();
    virtual int vf0D();
    virtual int vf0E();
    virtual int vf0F();
    virtual int vf10();
    virtual int vf11();
    virtual int vf12();
    virtual int vf13();
    virtual int vf14();
    virtual int vf15();
    virtual int vf16();
    virtual int vf17();
    virtual int vf18();
    virtual int vf19();
    virtual int vf1A();
    virtual int vf1B();
    virtual int vf1C();
    virtual int vf1D();
    virtual int vf1E();
    virtual int vf1F();
    virtual int vf20();
    virtual int vf21();
    virtual int vf22();
    virtual int vf23();
    virtual int vf24();
    virtual int vf25();
    virtual int vf26();
    virtual int vf27();
    virtual int vf28();
    virtual int vf29();
    virtual int vf2A();
    virtual int vf2B();
    virtual int vf2C();
    virtual int vf2D();
    virtual int vf2E();
    virtual int hit_test(long x, long y);
};

class TRIBE_Panel_Button_Outer {
public:
    char gap_00[0x4BC];
    TRIBE_Panel_Button_Nested* nested_4bc;
};

class TRIBE_Panel_Button {
public:
    char gap_00[0x40];
    TRIBE_Panel_Button_Outer* panel_40;
    char gap_44[0x27C];
    unsigned char state_2c0;

    int is_inside(long x, long y);
};
#else
#include "../../include/tpnl_btn_context.h"
#endif

int TRIBE_Panel_Button::is_inside(long x, long y) {
    if (!((TPanel*)this)->TPanel::is_inside(x, y)) {
        return 0;
    }

    unsigned char state = this->state_2c0;
    if (state == 2 || state == 3) {
        TRIBE_Panel_Button_Outer* outer = this->panel_40;
        TRIBE_Panel_Button_Nested* nested = outer->nested_4bc;
        if (nested != 0 && nested->hit_test(x, y)) {
            return 0;
        }
    }

    return 1;
}
