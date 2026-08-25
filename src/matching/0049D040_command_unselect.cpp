#if !defined(SCR_GAME_TU_CONTEXT)
 #include "../../include/scr_game_context.h"

#endif

void TRIBE_Screen_Game::command_unselect(void) {
    if (rge_base_game->get_paused() == 0) {
        rge_base_game->get_player()->unselect_object();
        rge_base_game->get_player()->unselect_area();
        this->main_view->set_redraw(1);
    }
}
