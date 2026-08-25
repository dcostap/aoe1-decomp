#ifndef PNL_BTN_SHARED_CONTEXT
#include "../../include/pnl_btn_context.h"

#endif /* PNL_BTN_SHARED_CONTEXT */

void TButtonPanel::set_id(short param_1, long param_2, long param_3) {
    this->id[param_1] = param_2;
    this->id2[param_1] = param_3;
}
