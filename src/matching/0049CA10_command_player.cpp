// first pass: cheat-code gate, unselect current player object, view-panel callback, then game dispatch
// if this is sticky, the remaining lead is likely just the exact virtual-slot declarations on the two game callbacks
#if !defined(SCR_GAME_TU_CONTEXT)
 #include "../../include/scr_game_context.h"

#endif

void TRIBE_Screen_Game::command_player(int param_1) {
    if (!rge_base_game->allowCheatCodes()) {
        return;
    }

    rge_base_game->get_player()->unselect_object();
    this->main_view->set_redraw(1);

    if (rge_base_game->game_mode == 6 && rge_base_game->sub_game_mode == 1) {
        rge_base_game->set_game_mode(0, 0);
    }

    rge_base_game->set_player((short)param_1);
}
