// 0051F0D0 Time_Line_Panel::set_body_font (tpnl_tml.cpp:407-412)
// BINARY NOTE: the shared timeline surface preserves the redraw slot at +20.

#include "../../include/tpnl_tml_context.h"

void Time_Line_Panel::set_body_font(void* font, long width, long height) {
    this->body_font = font;
    this->body_font_wid = width;
    this->body_font_hgt = height;
    this->redraw(1);
}
