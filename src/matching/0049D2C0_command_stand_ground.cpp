#if !defined(SCR_GAME_TU_CONTEXT)
 #include "../../include/scr_game_context.h"

#endif

void TRIBE_Screen_Game::command_stand_ground(void) {
    if (rge_base_game->get_paused() == 0) {
        ((RGE_Player*)rge_base_game->get_player())->command_stand_ground();
    }
}
