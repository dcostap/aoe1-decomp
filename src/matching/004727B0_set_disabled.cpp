#ifndef PNL_BTN_SHARED_CONTEXT
#include "../../include/pnl_btn_context.h"

#endif /* PNL_BTN_SHARED_CONTEXT */

void TButtonPanel::set_disabled(int is_disabled) {
    disabled = is_disabled;
        set_redraw(1);
    if (disabled != 0) {
        active = 0;
        return;
    }
    active = 1;
}
