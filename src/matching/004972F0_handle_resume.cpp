#if !defined(SCR_GAME_TU_CONTEXT)
 #include "../../include/scr_game_context.h"

#endif

void TRIBE_Screen_Game::handle_resume(void) {
    if (this->pause_text->field_6C != 0) {
        this->pause_text->set_active(0);
        this->pause_text->set_redraw(1);
        this->main_view->set_redraw(1);
    }
}
