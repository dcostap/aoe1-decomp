// VA: 0049D200 TRIBE_Screen_Game::command_work

#if !defined(SCR_GAME_TU_CONTEXT)
#include "../../include/scr_game_context.h"
#endif

void TRIBE_Screen_Game::command_work() {
    void** list;
    short list_num;

    if (rge_base_game->get_paused() == 0) {
        RGE_Player* player = rge_base_game->get_player(&list, &list_num, -1, -1, -1, -1);
        if (player->get_selected_objects_to_command()) {
            free(list);
            char* msg = this->get_string(0xBE1, 0x32, 0, 0, 0, 0);
            this->message_panel->show_message(1, msg);
            rge_base_game->set_game_mode(5, 0);
        }
    }
}
