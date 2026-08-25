#ifndef PNL_BTN_SHARED_CONTEXT
#include "../../include/pnl_btn_context.h"

#endif /* PNL_BTN_SHARED_CONTEXT */

void TButtonPanel::set_font(void* param_1, long param_2, long param_3) {
    this->font = param_1;
    this->font_wid = param_2;
    this->font_hgt = param_3;
    this->set_redraw(1);
}
