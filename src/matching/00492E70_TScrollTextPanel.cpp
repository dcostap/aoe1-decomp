// TScrollTextPanel::TScrollTextPanel
// VA: 00492E70
//
// Clean baseline: the constructor is a normal derived TTextPanel constructor.
// The base size and the four derived fields are binary-proven; the optional
// setup arguments are the period API's zero/default surface.
//
// Attempt log:
// - natural base-constructor/member-init reconstruction: MATCH (211/211).
// FLAGS: config/flags/00492E70_TScrollTextPanel.rsp retains /GX for the
// original EH registration frame.

#include "../../include/scr_cred_context.h"

TScrollTextPanel::TScrollTextPanel(TPanel* parent, TDrawArea* draw_area,
                                   long x, long y, long width, long height,
                                   int speed_value, void* font, long font_wid,
                                   long font_hgt, char* text)
    : TTextPanel()
{
    this->speed = speed_value;
    this->scroll = 0;
    this->last_time = 0;
    this->done = 0;

    if (this->setup(draw_area, parent, x, y, width, height, font, font_wid,
                    font_hgt, 0, 0, 0, 0, 0, 0, 0) != 0) {
        this->set_alignment(3, 0);
        this->set_word_wrap(1);
        this->set_text(text);
        this->set_text_color(this->text_color1, this->text_color2);
    }
}
