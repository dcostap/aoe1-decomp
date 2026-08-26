// TRIBE_Panel_Button::set_garrison_number
// PDB: tpnl_btn.cpp:326-329

#ifndef TPNL_BTN_SHARED_CONTEXT
#include "../../include/tpnl_btn_context.h"
#endif

void TRIBE_Panel_Button::set_garrison_number(int value) {
    this->garrsion_number = value;
#ifdef TPNL_BTN_SHARED_CONTEXT
    this->set_redraw(1);
#else
    this->set_redraw(1);
#endif
}
