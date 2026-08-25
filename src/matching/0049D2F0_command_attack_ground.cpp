#if !defined(SCR_GAME_TU_CONTEXT)
 #include "../../include/scr_game_context.h"

#endif

void TRIBE_Screen_Game::command_attack_ground(void) {
    if (rge_base_game->get_paused() != 0) {
        return;
    }
    this->message_panel->show_message(1, this->get_string(0xBE5), 0x32, 0, 0, 0, 0);
    rge_base_game->set_font(0x64, 0);
}
