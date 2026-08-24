// 0047BEC0 THorizontalSliderPanel::set_rect
// Source: pnl_sld.cpp lines 162-176.
// The field order and interleaving follow the exact owner reconstruction.

#include "../../include/pnl_sld_context.h"

void THorizontalSliderPanel::set_rect(long param_1, long param_2, long param_3, long param_4) {
    TScrollBarPanel::set_rect(param_1, param_2, param_3, param_4);
    long left = field_0C;
    long right = left + width - 1;
    left1 = left;
    left2 = left;
    right1 = right;
    right2 = right;
    min_right = left + 1;
    span = right - height + 2;
    min_left = left + 1;
    TScrollBarPanel::calc_item_rects();
}
