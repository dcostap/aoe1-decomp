// VA: 004992E0 object_changed (199B)
// scr_game.cpp
// PDB owner: protected TRIBE_Screen_Game::object_changed, scr_game.cpp:3261-3298.
// Body: 004992E0-004993A6. 00498950 is data, not a function.
// Exact finish: natural player-state publication, mode guards, and reset cleanup
// produce 60 instructions, 7 ordered calls, and the protected IAEXXZ symbol.

#if !defined(SCR_GAME_TU_CONTEXT)
 #include "../../include/scr_game_context.h"

#endif

void TRIBE_Screen_Game::object_changed(void) {
    int changed = this->game_obj != rge_base_game->get_player()->selected_obj;
    this->game_obj = rge_base_game->get_player()->selected_obj;
    this->sel_count = rge_base_game->get_player()->sel_count;

    if (changed != 0) {
        if (rge_base_game->game_mode == 0x15) {
            this->main_view->end_scroll_view();
            this->main_view->set_selection_area(-1, -1, -1, -1);
        }

        int mode = rge_base_game->game_mode;
        if ((char)mode != 1 &&
            (char)mode != 0x12 &&
            (char)mode != 0x0E &&
            (char)mode != 2 &&
            (char)mode != 3 &&
            (char)mode != 8 &&
            (char)mode != 9 &&
            (char)mode != 0x0A) {
            rge_base_game->set_game_mode(0, 0);
        }
    }

    this->reset_buttons();
}
