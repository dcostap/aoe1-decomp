// target: VA 0049BEA0 TRIBE_Screen_Game::command_cancel()
// attempt: flattened local layout to binary-proven offsets (+0x45C popup_help, +0x4B8 main_view)
// attempt: pure virtual padding for TRIBE_Main_View vt[60] avoids fake cdecl cast push/add cleanup
// attempt: nested game_mode branch keeps command_unselect as shared tail block like original

#if !defined(SCR_GAME_TU_CONTEXT)
 #include "../../include/scr_game_context.h"

#endif

void TRIBE_Screen_Game::command_cancel() {
    if (this->popup_help_flag) {
        this->clear_popup_help();
        return;
    }

    if (rge_base_game->get_paused()) {
        return;
    }

    if (rge_base_game->game_mode != 0) {
        if (rge_base_game->game_mode == 0x15) {
            this->main_view->end_scroll_view();
            this->main_view->set_selection_area(-1, -1, -1, -1);
        }
        rge_base_game->set_game_mode(0, 0);
    } else {
        this->command_unselect();
    }
}
