// TRIBE_Panel_Button::set_garrison_number
// PDB: tpnl_btn.cpp:326-329

#ifndef TPNL_BTN_SHARED_CONTEXT
class TRIBE_Panel_Button {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20(int);
    char gap_04[0x2B8];
    int garrsion_number;

    void set_garrison_number(int);
};
#else
#include "../../include/tpnl_btn_context.h"
#endif

void TRIBE_Panel_Button::set_garrison_number(int value) {
    this->garrsion_number = value;
#ifdef TPNL_BTN_SHARED_CONTEXT
    this->set_redraw(1);
#else
    vf20(1);
#endif
}
