#if !defined(SCR_GAME_TU_CONTEXT)
 #include "../../include/scr_game_context.h"

#endif

void TRIBE_Screen_Game::set_map_buttons_redraw(int mode) {
    if (this->field_14 < 0x320) {
        this->button_panel[5]->set_redraw(mode);
        this->button_panel[11]->set_redraw(mode);
    }
    this->button_panel[15]->set_redraw(mode);
    this->button_panel[16]->set_redraw(mode);
}
