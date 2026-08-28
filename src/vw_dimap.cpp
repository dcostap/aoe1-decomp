#include "../include/vw_dimap.h"
#include "../include/game_globals.h"
#include "../include/main.h"

RGE_Diamond_Map_View::RGE_Diamond_Map_View() : RGE_Diamond_Map() {
    this->mouse_move_tolerance = 0;
}

long RGE_Diamond_Map_View::handle_mouse_down(unsigned char button, long x, long y, int ctrl, int shift) {
    short tile_x;
    short tile_y;
    RGE_Tile* tile;
    if (this->pick_tile(x, y, &tile_x, &tile_y, &tile) == 0) {
        return 0;
    }
    return TPanel::handle_mouse_down(button, x, y, ctrl, shift);
}

long RGE_Diamond_Map_View::mouse_left_down_action(long x, long y, int key, int flags) {
    if (rge_base_game->get_paused() == 0) {
        int mode = rge_base_game->prog_mode;
        if (mode == 4 || mode == 6 || mode == 7 || mode == 5) {
        if (rge_base_game->prog_info->interface_style == 2) {
            this->start_scroll_view(x, y);
            return 1;
        }
        if (mode == 4 || mode == 6 || mode == 7) {
            this->capture_mouse();
        }
            return 1;
        }
    }
    return 0;
}

long RGE_Diamond_Map_View::mouse_left_move_action(long x, long y, int key, int flags) {
    int prog_mode = rge_base_game->prog_mode;
    if (prog_mode == 4 || prog_mode == 6 || prog_mode == 7 || prog_mode == 5) {
        if (rge_base_game->get_paused()) {
            if (this->scrolling) {
                this->end_scroll_view();
            } else {
                this->release_mouse();
            }
            return 0;
        }
        if (this->scrolling) {
            this->handle_scroll_view(x, y);
            return 1;
        }
    }
    return 0;
}

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

long RGE_Diamond_Map_View::mouse_right_down_action(long x, long y, int key, int flags) {
    if (rge_base_game->get_paused() == 0) {
        int mode = rge_base_game->prog_mode;
        if (mode == 4 || mode == 6 || mode == 7 || mode == 5) {
            if (rge_base_game->prog_info->interface_style == 2) {
                if (mode == 4 || mode == 6 || mode == 7) {
                    this->capture_mouse();
                    return 1;
                }
            } else {
                this->start_scroll_view(x, y);
            }
            return 1;
        }
    }
    return 0;
}

long RGE_Diamond_Map_View::mouse_right_move_action(long x, long y, int key, int flags) {
    int mode = rge_base_game->prog_mode;
    if (mode == 4 || mode == 6 || mode == 7 || mode == 5) {
        if (rge_base_game->get_paused()) {
            if (this->scrolling) {
                this->end_scroll_view();
            } else {
                this->release_mouse();
            }
            return 0;
        }
        if (this->scrolling) {
            this->handle_scroll_view(x, y);
            return 1;
        }
    }
    return 0;
}

long RGE_Diamond_Map_View::mouse_right_up_action(long x, long y, int param_3, int param_4)
{
    RGE_Tile* tile;
    int mode = rge_base_game->prog_mode;
    if (mode != 4 && mode != 6 && mode != 7 && mode != 5) {
        return 0;
    }

    if (this->scrolling != 0) {
        this->end_scroll_view();
        return 1;
    }

    this->release_mouse();
    if (rge_base_game->get_paused() != 0) {
        return 0;
    }

    if (this->mouse_action != 1 && this->mouse_action != 2) {
        return 0;
    }

    if (rge_base_game->prog_info->interface_style == 2) {
        if (rge_base_game->game_mode != 0 || rge_base_game->prog_mode == 5) {
            return 0;
        }
        if (param_4 == 0) {
            if (this->command_make_do(x, y) == 0) {
                goto fail;
            }
            return 1;
        }
        short tile_x;
        short tile_y;
        if (this->pick_tile(x, y, &tile_x, &tile_y, &tile) != 0) {
            this->player->command_add_waypoint(
                (float)tile_x + 0.5f, (float)tile_y + 0.5f, 1.0f);
        }
        return 1;
    }

    if (rge_base_game->prog_mode == 7) {
        return 0;
    }
    if (rge_base_game->game_mode != 0) {
        rge_base_game->set_game_mode(0, 0);
        return 0;
    }
    this->player->unselect_object();
fail:
    return 0;
}

void RGE_Diamond_Map_View::draw()
{
    unsigned long start;

    start = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\vw_dimap.cpp", 0x10E);
    RGE_Diamond_Map::draw();
    rge_base_game->add_to_timing(7, debug_timeGetTime("C:\\msdev\\work\\age1_x1\\vw_dimap.cpp", 0x112) - start);
}

// BINARY NOTE: The binary calls the player command slot at +0xA8.
int RGE_Diamond_Map_View::command_make_do(long a1, long a2) {
    int result;
    short col;
    short row;
    RGE_Tile* tile;
    if (allow_user_commands == 0) return 0;
    result = 0;
    if (this->pick_tile(a1, a2, &col, &row, &tile) != 0) {
        float x = (float)row + 0.5f;
        float y = (float)col + 0.5f;
        result = this->player->command_make_do(0, y, x) & 0xff;
    }
    return result;
}

// BINARY NOTE: The binary calls the player command slot at +0xA0.
// BINARY NOTE: The cleanup call uses the base-game slot at +0x10.
int RGE_Diamond_Map_View::command_make_move(long a1, long a2) {
    int result;
    short col;
    short row;
    RGE_Tile* tile;
    if (allow_user_commands == 0) return 0;
    result = 0;
    if (this->pick_tile(a1, a2, &col, &row, &tile) != 0) {
        float x = (float)row + 0.5f;
        float y = (float)col + 0.5f;
        result = this->player->command_make_move(0, y, x) & 0xff;
    }
    rge_base_game->set_game_mode(0, 0);
    return result;
}

// BINARY NOTE: The binary calls the player command slot at +0xA4.
// BINARY NOTE: The cleanup call uses the base-game slot at +0x10.
int RGE_Diamond_Map_View::command_make_work(long a1, long a2) {
    int result;
    short col;
    short row;
    RGE_Tile* tile;
    if (allow_user_commands == 0) return 0;
    result = 0;
    if (this->pick_tile(a1, a2, &col, &row, &tile) != 0) {
        float x = (float)row + 0.5f;
        float y = (float)col + 0.5f;
        result = this->player->command_make_work(0, y, x) & 0xff;
    }
    rge_base_game->set_game_mode(0, 0);
    return result;
}
