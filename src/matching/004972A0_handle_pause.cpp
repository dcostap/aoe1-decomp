#if !defined(SCR_GAME_TU_CONTEXT)
 #include "../../include/scr_game_context.h"

#endif

// BINARY NOTE: this guard reads the inherited TPanel field at +0x6C.
void TRIBE_Screen_Game::handle_pause(void) {
    this->pause_text->set_text(0x2329);
    if (this->pause_text->field_6C == 0) {
        this->pause_text->set_active(1);
        this->pause_text->set_redraw(1);
    }
    this->main_view->set_redraw(1);
}
