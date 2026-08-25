#ifndef PNL_BTN_SHARED_CONTEXT
#include "../../include/pnl_btn_context.h"

#endif /* PNL_BTN_SHARED_CONTEXT */

void TButtonPanel::set_text_color(int state, unsigned long color1, unsigned long color2) {
    if (state >= 0 && state <= 8) {
        text_color1[state] = color1;
        text_color2[state] = color2;
        set_redraw(1);
    }
}
