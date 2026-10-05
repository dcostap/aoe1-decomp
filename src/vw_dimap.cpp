#include "../include/vw_dimap.h"
#include "../include/program_mode.h"
#include "../include/game_globals.h"
#include "../include/main.h"

RGE_Diamond_Map_View::RGE_Diamond_Map_View() : RGE_Diamond_Map() {
    this->mouse_move_tolerance = 0;
}

long RGE_Diamond_Map_View::handle_mouse_down(
    unsigned char mouse_button_in, long x, long y, int ctrl_key, int shift_key
) {
    short col;
    short row;
    RGE_Tile* tile;
    if (this->pick_tile(x, y, &col, &row, &tile) == 0) {
        return 0;
    }
    return TPanel::handle_mouse_down(mouse_button_in, x, y, ctrl_key, shift_key);
}

long RGE_Diamond_Map_View::mouse_left_down_action(long x, long y, int ctrl_key, int shift_key) {
    if (rge_base_game->get_paused() == 0) {
        int mode = rge_base_game->prog_mode;
        if (mode == ProgModeGame || mode == ProgModeGameTempPaused || mode == ProgModeScenarioEditor
            || mode == ProgModeGameOver) {
            if (rge_base_game->prog_info->interface_style == 2) {
                this->start_scroll_view(x, y);
                return 1;
            }
            if (mode == ProgModeGame || mode == ProgModeGameTempPaused || mode == ProgModeScenarioEditor) {
                this->capture_mouse();
            }
            return 1;
        }
    }
    return 0;
}

long RGE_Diamond_Map_View::mouse_left_move_action(long x, long y, int ctrl_key, int shift_key) {
    int prog_mode = rge_base_game->prog_mode;
    if (prog_mode == ProgModeGame || prog_mode == ProgModeGameTempPaused || prog_mode == ProgModeScenarioEditor
        || prog_mode == ProgModeGameOver) {
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

long RGE_Diamond_Map_View::mouse_left_up_action(long x, long y, int ctrl_key, int shift_key) {
    int mode = rge_base_game->prog_mode;

    if (mode == ProgModeGame || mode == ProgModeGameTempPaused || mode == ProgModeScenarioEditor
        || mode == ProgModeGameOver) {
        if (this->scrolling) {
            this->end_scroll_view();
            return 1;
        }

        this->release_mouse();

        if (rge_base_game->get_paused()) {
            return 0;
        }

        if (rge_base_game->prog_mode == ProgModeGameOver) {
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

long RGE_Diamond_Map_View::mouse_right_down_action(long x, long y, int ctrl_key, int shift_key) {
    if (rge_base_game->get_paused() == 0) {
        int mode = rge_base_game->prog_mode;
        if (mode == ProgModeGame || mode == ProgModeGameTempPaused || mode == ProgModeScenarioEditor
            || mode == ProgModeGameOver) {
            if (rge_base_game->prog_info->interface_style == 2) {
                if (mode == ProgModeGame || mode == ProgModeGameTempPaused || mode == ProgModeScenarioEditor) {
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

long RGE_Diamond_Map_View::mouse_right_move_action(long x, long y, int ctrl_key, int shift_key) {
    int mode = rge_base_game->prog_mode;
    if (mode == ProgModeGame || mode == ProgModeGameTempPaused || mode == ProgModeScenarioEditor
        || mode == ProgModeGameOver) {
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

long RGE_Diamond_Map_View::mouse_right_up_action(long x, long y, int ctrl_key, int shift_key) {
    RGE_Tile* tile;
    int mode = rge_base_game->prog_mode;
    if (mode != ProgModeGame && mode != ProgModeGameTempPaused && mode != ProgModeScenarioEditor
        && mode != ProgModeGameOver) {
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
        if (rge_base_game->game_mode != 0 || rge_base_game->prog_mode == ProgModeGameOver) {
            return 0;
        }
        if (shift_key == 0) {
            if (this->command_make_do(x, y) == 0) {
                goto fail;
            }
            return 1;
        }
        short col;
        short row;
        if (this->pick_tile(x, y, &col, &row, &tile) != 0) {
            this->player->command_add_waypoint((float) col + 0.5f, (float) row + 0.5f, 1.0f);
        }
        return 1;
    }

    if (rge_base_game->prog_mode == ProgModeScenarioEditor) {
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

void RGE_Diamond_Map_View::draw() {
    unsigned long start;

    start = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\vw_dimap.cpp", 270);
    RGE_Diamond_Map::draw();
    rge_base_game->add_to_timing(7, debug_timeGetTime("C:\\msdev\\work\\age1_x1\\vw_dimap.cpp", 274) - start);
}

// The binary calls the player command slot at +0xA8.
int RGE_Diamond_Map_View::command_make_do(long x, long y) {
    int result;
    short col;
    short row;
    RGE_Tile* tile;
    if (allow_user_commands == 0)
        return 0;
    result = 0;
    if (this->pick_tile(x, y, &col, &row, &tile) != 0) {
        float world_y = (float) row + 0.5f;
        float world_x = (float) col + 0.5f;
        result = this->player->command_make_do(0, world_x, world_y) & 0xff;
    }
    return result;
}

// The binary calls the player command slot at +0xA0.
// The cleanup call uses the base-game slot at +0x10.
int RGE_Diamond_Map_View::command_make_move(long x, long y) {
    int result;
    short col;
    short row;
    RGE_Tile* tile;
    if (allow_user_commands == 0)
        return 0;
    result = 0;
    if (this->pick_tile(x, y, &col, &row, &tile) != 0) {
        float world_y = (float) row + 0.5f;
        float world_x = (float) col + 0.5f;
        result = this->player->command_make_move(0, world_x, world_y) & 0xff;
    }
    rge_base_game->set_game_mode(0, 0);
    return result;
}

// The binary calls the player command slot at +0xA4.
// The cleanup call uses the base-game slot at +0x10.
int RGE_Diamond_Map_View::command_make_work(long x, long y) {
    int result;
    short col;
    short row;
    RGE_Tile* tile;
    if (allow_user_commands == 0)
        return 0;
    result = 0;
    if (this->pick_tile(x, y, &col, &row, &tile) != 0) {
        float world_y = (float) row + 0.5f;
        float world_x = (float) col + 0.5f;
        result = this->player->command_make_work(0, world_x, world_y) & 0xff;
    }
    rge_base_game->set_game_mode(0, 0);
    return result;
}
