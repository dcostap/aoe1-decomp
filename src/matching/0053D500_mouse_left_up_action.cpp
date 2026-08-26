// 0053D500 mouse_left_up_action (284 bytes)
// PDB: vw_dimap.cpp (RGE_Diamond_Map_View::mouse_left_up_action)
// The shared vw_dimap context supplies the reviewed class and ABI surface.

#ifndef VW_DIMAP_SHARED_CONTEXT
#include "../../include/vw_dimap_tu_context.h"
#endif

long RGE_Diamond_Map_View::mouse_left_up_action(long x, long y, int key, int flags)
{
    int mode = rge_base_game->prog_mode;

    if (mode == 4 || mode == 6 || mode == 7 || mode == 5) {
        if (this->scrolling) {
            this->end_scroll_view();
            return 1;
        }

        this->release_mouse();

        if (rge_base_game->get_paused()) {
            return 0;
        }

        if (rge_base_game->prog_mode == 5) {
            return 0;
        }

        short col, row;
        RGE_Tile* tile;

        if (this->pick_tile(x, y, &col, &row, &tile)) {
            switch (rge_base_game->game_mode) {
                case 0:
                    if (rge_base_game->prog_info->interface_style != 2) {
                        if (this->command_make_do(x, y)) {
                            return 1;
                        }
                    }
                    break;
                case 4:
                    this->command_make_move(x, y);
                    return 1;
                case 5:
                    this->command_make_work(x, y);
                    return 1;
            }
        }
    }

    return 0;
}
