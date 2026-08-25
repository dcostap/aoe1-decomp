#ifndef PNL_BTN_SHARED_CONTEXT
#include "../../include/pnl_btn_context.h"

#endif /* PNL_BTN_SHARED_CONTEXT */

void TButtonPanel::set_state(short param_1) {
    this->cur_state = param_1;
    this->set_redraw(1);
}
