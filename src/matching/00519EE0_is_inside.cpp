// attempt log:
// first pass: direct natural branch spelling for the base-hit / state / nested-vcall gate
// second pass: model the +0xBC call with a helper class whose target method is the 49th vfunc
// third pass: remove the fake inherited surface; the main object wants raw +0x40 / +0x2C0 offsets
// fourth pass: use an outer object at +0x40 with the nested pointer at +0x4BC to match the branch length
// keep the base call first, then reject state 2/3 with the nested +0x4BC virtual +0xBC hit

#ifndef TPNL_BTN_SHARED_CONTEXT
#include "../../include/tpnl_btn_context.h"
#endif

int TRIBE_Panel_Button::is_inside(long x, long y) {
    if (!((TPanel*)this)->TPanel::is_inside(x, y)) {
        return 0;
    }

    unsigned char state = this->state_2c0;
    if (state == 2 || state == 3) {
        TRIBE_Panel_Button_Outer* outer = this->panel_40;
        TPanel* nested = outer->nested_4bc;
        if (nested != 0 && nested->is_inside(x, y)) {
            return 0;
        }
    }

    return 1;
}
