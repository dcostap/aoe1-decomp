// tried the direct pause check, then the message text / panel call, then the trailing base-game virtual
// remaining mismatch would be in the exact wrapper-vs-virtual call basin, not the visible control flow

#if !defined(SCR_GAME_TU_CONTEXT)
 #include "../../include/scr_game_context.h"

#endif

void TRIBE_Screen_Game::command_heal(void) {
    if (rge_base_game->get_paused() != 0) {
        return;
    }

    this->message_panel->show_message(1, this->get_string(0xBE3), 0x32, 0, 0, 0, 0);
        rge_base_game->set_game_mode(0x66, 0);
}
