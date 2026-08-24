#include "../../include/pnl_msg_context.h"

void TMessagePanel::set_font(void* param_1, long param_2, long param_3) {
    if (this->font != param_1) {
        this->font = param_1;
        this->font_wid = param_2;
        this->font_hgt = param_3;
        this->need_restore = 1;
        this->set_redraw(1);
    }
}
