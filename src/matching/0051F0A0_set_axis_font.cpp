// 0051F0A0 Time_Line_Panel::set_axis_font (tpnl_tml.cpp:394-399)
// BINARY NOTE: the shared timeline surface preserves the redraw slot at +20.

#include "../../include/tpnl_tml_context.h"

void Time_Line_Panel::set_axis_font(void* font, long width, long height) {
    this->axis_font = font;
    this->axis_font_wid = width;
    this->axis_font_hgt = height;
    this->redraw(1);
}
