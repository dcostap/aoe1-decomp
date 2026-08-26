#if !defined(SCR_GAME_TU_CONTEXT)
 #include "../../include/scr_game_context.h"

#endif

void TRIBE_Screen_Game::command_build(void) {
    if (rge_base_game->get_paused() == 0) {
        rge_base_game->set_game_mode(6, 1);
        // BINARY NOTE: The original clears the inherited start item.
        this->start_item = 0;
        this->setup_buttons();
    }
}
