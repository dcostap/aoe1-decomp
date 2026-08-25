#if !defined(SCR_GAME_TU_CONTEXT)
 #include "../../include/scr_game_context.h"

#endif

void TRIBE_Screen_Game::command_unload(void) {
    if (!rge_base_game->get_paused()) {
        this->message_panel->show_message(1, this->get_string(0xBED, 0x32, 0, 0, 0, 0));
        rge_base_game->set_game_mode(0x69, 0);
    }
}
