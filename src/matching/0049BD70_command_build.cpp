#if !defined(SCR_GAME_TU_CONTEXT)
 #include "../../include/scr_game_context.h"

#endif

void TRIBE_Screen_Game::command_build(void) {
    if (rge_base_game->get_paused() == 0) {
        rge_base_game->build_mode(6, 1);
        this->last_item = 0;
        this->setup_buttons();
    }
}
