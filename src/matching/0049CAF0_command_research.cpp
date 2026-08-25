// VA: 0049CAF0 command_research (160B)
// scr_game.cpp
// Retry 2026-05-19: replace placeholder with natural member-call surface.

#if !defined(SCR_GAME_TU_CONTEXT)
 #include "../../include/scr_game_context.h"

#endif

void TRIBE_Screen_Game::command_research(int player_id) {
    register TRIBE_Screen_Game* self = this;
    short attr;
    char msg[512];

    if (rge_base_game->get_paused() == 0) {
        TRIBE_Player* player = rge_base_game->get_player(player_id, &attr);
        if (player->check_tech_cost()) {
            rge_base_game->get_player(player_id)->command_building_make_tech();
            return;
        }
        rge_base_game->language(0x67, 1, (int)attr, msg, 0x200);
        self->message_panel->show_message(1, msg, 0x56, 0, 0, 0, 0);
    }
}
