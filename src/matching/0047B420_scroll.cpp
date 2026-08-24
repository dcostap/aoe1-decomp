// TScrollBarPanel::scroll
// VA: 0047B420
// Pnl_scbr.cpp:596-643
// 159 bytes
// BINARY NOTE: List notifications use the inherited TPanel::action surface.

#include "../../include/game_globals.h"

#ifndef PNL_SCBR_CANONICAL_TU
#include "../../include/pnl_scbr_context.h"
#endif

void TScrollBarPanel::scroll(TScrollBarPanel::ActionType action, long param) {
    if (this->list_panel != 0) {
        this->list_panel->action(this, action, param, 0);
        return;
    }

    long val = this->list_num;

    switch (action) {
    case 0:
        val -= this->one_step;
        break;
    case 1:
        val += this->one_step;
        break;
    case 2:
        val -= this->page_step;
        break;
    case 3:
        val += this->page_step;
        break;
    case 4:
        val = param;
        break;
    default:
        return;
    }

    if (val < 0) {
        val = 0;
    } else {
        int max = this->list_len - 1;
        if (val > max)
            val = max;
    }

    if (val != this->list_num) {
        set_tab_pos(val);
        if (this->panel != 0) {
            this->panel->action(this, 4, val, 0);
        }
    }
}
