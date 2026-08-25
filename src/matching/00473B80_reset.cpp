#ifndef PNL_BTN_SHARED_CONTEXT
#include "../../include/pnl_btn_context.h"

#endif

void TButtonPanel::reset(void) {
    release_mouse();
    if (is_down != 0) {
        if (buttonTypeValue != 2) {
            is_down = 0;
        }
        set_redraw(1);
    }
}
