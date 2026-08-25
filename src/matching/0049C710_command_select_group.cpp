// first pass: direct paused guard, optional unselect, default-to-10 group, then the main-view callback
// if this is sticky, the only likely drift is the exact member-call/vtable shape on the final 0x4B8 dispatch
#if !defined(SCR_GAME_TU_CONTEXT)
 #include "../../include/scr_game_context.h"

#endif

void TRIBE_Screen_Game::command_select_group(int group, int unselect) {
    if (rge_base_game->get_paused()) {
        return;
    }
    if (unselect != 0) {
        rge_base_game->get_player()->unselect_object();
    }
    if (group == 0) {
        group = 10;
    }
    rge_base_game->get_player()->select_group(group);
    this->main_view->set_redraw(1);
}
