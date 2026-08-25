#ifndef PNL_BTN_SHARED_CONTEXT
#include "../../include/pnl_btn_context.h"

#endif /* PNL_BTN_SHARED_CONTEXT */

#ifndef PNL_BTN_SHARED_CONTEXT
#include "../../include/pnl_btn_context.h"
#endif /* PNL_BTN_SHARED_CONTEXT */

long TButtonPanel::handle_mouse_down(unsigned char button, long x, long y, int ctrl, int shift) {
    if (visible == 0) {
        return 0;
    }
    if (active != 0) {
        return 0;
    }
    if (is_inside(x, y) == 0) {
        return 0;
    }
    return ((TPanel*)this)->handle_mouse_down(button, x, y, ctrl, shift);
}
