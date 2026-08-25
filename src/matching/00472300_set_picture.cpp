class TShape;

#ifndef PNL_BTN_SHARED_CONTEXT
#include "../../include/pnl_btn_context.h"

#endif /* PNL_BTN_SHARED_CONTEXT */

void TButtonPanel::set_picture(short param_1, TShape* param_2, short param_3) {
    this->pic[param_1] = param_2;
    this->pic_index[param_1] = param_3;
    this->set_redraw(1);
}
