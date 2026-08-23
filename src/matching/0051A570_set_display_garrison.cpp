// TRIBE_Panel_Button::set_display_garrison
// PDB: tpnl_btn.cpp:320-323

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
    char gap_04[0x2B4];
    int display_garrison;

    void set_display_garrison(int);
};
#else
#include "../../include/tpnl_btn_context.h"
#endif

void TRIBE_Panel_Button::set_display_garrison(int value) {
    this->display_garrison = value;
#ifdef TPNL_BTN_SHARED_CONTEXT
    this->set_redraw(1);
#else
    vf20(1);
#endif
}
