#if !defined(SCR_GAME_TU_CONTEXT)
 #include "../../include/scr_game_context.h"

#endif

// BINARY NOTE: the width test is TPanel::pnl_wid at +0x14.
void TRIBE_Screen_Game::set_map_buttons_redraw(TPanel::RedrawMode mode) {
    if (this->pnl_wid < 0x320) {
        this->button_panel[5]->set_redraw(mode);
        this->button_panel[11]->set_redraw(mode);
    }
    this->button_panel[15]->set_redraw(mode);
    this->button_panel[16]->set_redraw(mode);
}
