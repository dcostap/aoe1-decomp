// TRIBE_Panel_Button::set_display_garrison
// PDB: tpnl_btn.cpp:320-323

#ifndef TPNL_BTN_SHARED_CONTEXT
#include "../../include/tpnl_btn_context.h"
#endif

void TRIBE_Panel_Button::set_display_garrison(int value) {
    this->display_garrison = value;
#ifdef TPNL_BTN_SHARED_CONTEXT
    this->set_redraw(1);
#else
    this->set_redraw(1);
#endif
}
