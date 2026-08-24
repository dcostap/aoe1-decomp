// VA: 0047B4E0 TScrollBarPanel::draw
// Source: Pnl_scbr.cpp lines 649-689
// Attempt log:
// 1: natural reconstruction from packet; use real helper calls and direct field offsets: first mismatch at rect check order/boolean temp shape.
// 2: check top/bottom before left/right and pass pressed predicate directly to avoid byte temp.
// BINARY NOTE: The executable dispatches the panel setup, finish, and rect
// calls through TPanel slots draw_setup, draw_finish, and draw_rect2.

#ifndef PNL_SCBR_CANONICAL_TU
#include "../../include/pnl_scbr_context.h"
#endif

void TScrollBarPanel::draw()
{
    if (this->panel != 0) {
        this->panel->draw_rect2(&this->rect_24);
    }

    this->draw_setup(0);

    if (this->draw_area->Lock("pnl_scbr::draw", 1)) {
        this->draw_back_pic();
        this->draw_border(0, 1, &this->rect_8C);

        if (this->up_rect.top != this->up_rect.bottom && this->up_rect.left != this->up_rect.right) {
            this->draw_button_pic(this->up_frame, this->pressed_part == 1 && this->active, &this->up_rect);
            this->draw_border(1, this->pressed_part == 1 && this->active, &this->up_rect);
        }

        if (this->down_rect.top != this->down_rect.bottom && this->down_rect.left != this->down_rect.right) {
            this->draw_button_pic(this->down_frame, this->pressed_part == 2 && this->active, &this->down_rect);
            this->draw_border(1, this->pressed_part == 2 && this->active, &this->down_rect);
        }

        this->draw_button_pic(this->tab_frame, 0, &this->tab_rect);
        this->draw_border(1, 0, &this->tab_rect);

        this->draw_area->Unlock("pnl_scbr::draw");
    }

    this->draw_finish();
}
