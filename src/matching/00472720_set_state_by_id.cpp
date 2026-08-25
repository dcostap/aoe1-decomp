#ifndef PNL_BTN_SHARED_CONTEXT
#include "../../include/pnl_btn_context.h"

#endif /* PNL_BTN_SHARED_CONTEXT */

void TButtonPanel::set_state_by_id(long target_id) {
    int i;

    for (i = 0; i < num_states; i++) {
        if (id[i] == target_id) {
            cur_state = (short)i;
            set_redraw(1);
            return;
        }
    }
}
