// 0051EAB0 Time_Line_Panel::set_bevel_info (tpnl_tml.cpp:234-242)
// BINARY NOTE: this owner uses the shared tpnl_tml.cpp timeline surface.

#include "../../include/tpnl_tml_context.h"

void Time_Line_Panel::set_bevel_info(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7) {
    this->bevel_type = param_1;
    this->bevel_color1 = (unsigned char)param_2;
    this->bevel_color2 = (unsigned char)param_3;
    this->bevel_color3 = (unsigned char)param_4;
    this->bevel_color4 = (unsigned char)param_5;
    this->bevel_color5 = (unsigned char)param_6;
    this->bevel_color6 = (unsigned char)param_7;
}
