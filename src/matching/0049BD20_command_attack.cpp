#if !defined(SCR_GAME_TU_CONTEXT)
 #include "../../include/scr_game_context.h"

#endif

void TRIBE_Screen_Game::command_attack(void) {
    if (rge_base_game->get_paused() != 0) {
        return;
    }
    this->message_panel->show_message(1, this->get_string(0xBE2), 0x32, 0, 0, 0, 0);
    // BINARY NOTE: This command uses the set_game_mode virtual slot.
    rge_base_game->set_game_mode(0x67, 0);
}
