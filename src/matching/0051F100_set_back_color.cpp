// 0051F100 Time_Line_Panel::set_back_color (tpnl_tml.cpp:419-422)
// BINARY NOTE: this owner uses the shared tpnl_tml.cpp timeline surface.

#include "../../include/tpnl_tml_context.h"

void Time_Line_Panel::set_back_color(int a, unsigned char b) {
    this->fill_back = a;
    this->back_color = b;
}
