#ifndef PNL_BTN_SHARED_CONTEXT
#include "../../include/pnl_btn_context.h"

#endif /* PNL_BTN_SHARED_CONTEXT */

void TButtonPanel::set_radio_button(void) {
    int i;

    for (i = 0; i < num_radio_buttons; i++) {
        radio_buttons[i]->is_down = 0;
        radio_buttons[i]->set_redraw(0);
    }
    if (drawTypeValue == 3 || drawTypeValue == 5) {
        is_down = 1;
    }
    set_redraw(1);
}
