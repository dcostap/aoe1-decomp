
#include "../include/basegame.h"
#include "../include/program_mode.h"
#include "../include/game_globals.h"
#include "../include/main.h"
#include "../include/view.h"
#include "../include/map.h"
#include "../include/player.h"
#include "../include/world.h"
#include "../include/stat_obj.h"
#include "../include/asp_list.h"
#include "../include/visible.h"
#include "../include/m_s_obj.h"
#include "../include/tm_b_obj.h"
#include "../include/tplayer.h"
#include "../include/vw_main.h"
#include "../include/rge_base_game_global.h"

#include <stdlib.h>
#include <string.h>

void TRIBE_Main_View::draw_multi_object_outline() {
    long start_col;
    long start_row;
    long end_col;
    long end_row;
    tagPOINT point;
    RGE_Pick_Info pick_info;

    short master_id = rge_base_game->master_obj_id;
    if (master_id == -1)
        return;

    TRIBE_Master_Building_Object* master_bldg =
        static_cast<TRIBE_Master_Building_Object*>(this->player->master_objects[master_id]);
    if (master_bldg == 0)
        return;

    this->render_area->SetClipRect(&this->clip_rect);

    if (this->get_selection_area(start_col, start_row, end_col, end_row, 0) == 0) {
        rge_base_game->get_mouse_pos(point);
        if (this->is_inside(point.x, point.y) == 0)
            return;

        if (this->pick1(0x28, 0, point.x - this->render_rect.left, point.y - this->render_rect.top, &pick_info, 0, 1)
            != 0x33)
            return;

        this->fixup_pick_info(&pick_info);
        start_col = static_cast<long>(pick_info.x);
        start_row = static_cast<long>(pick_info.y);
        end_col = start_col;
        end_row = start_row;
    }

    int row_distance = abs(end_row - start_row);
    int col_distance = abs(end_col - start_col);

    if (row_distance == col_distance) {
        long col;
        long row;

        if (end_col < start_col) {
            if (end_row < start_row) {
                col = end_col;
                row = end_row;
                do {
                    this->draw_wall_outline(col, row, master_bldg, 2);
                    col++;
                    row++;
                } while (col <= start_col);
            } else if (start_col >= end_col) {
                col = start_col;
                row = start_row;
                do {
                    this->draw_wall_outline(col, row, master_bldg, 2);
                    col--;
                    row++;
                } while (col >= end_col);
            }
        } else if (end_row < start_row) {
            col = end_col;
            row = end_row;
            do {
                this->draw_wall_outline(col, row, master_bldg, 2);
                col--;
                row++;
            } while (col >= start_col);
        } else if (start_col <= end_col) {
            col = start_col;
            row = start_row;
            do {
                this->draw_wall_outline(col, row, master_bldg, 2);
                col++;
                row++;
            } while (col <= end_col);
        }
    } else if (row_distance > col_distance) {
        long first_row;
        long last_row;
        long main_row = -1;
        long first_col;
        long last_col;

        if (end_row > start_row) {
            first_row = start_row;
            last_row = end_row;
        } else {
            first_row = end_row;
            last_row = start_row;
        }

        if (start_col < end_col) {
            main_row = end_row;
            first_col = start_col + 1;
            last_col = end_col;
        } else if (start_col > end_col) {
            main_row = end_row;
            first_col = end_col;
            last_col = start_col - 1;
        }

        if (main_row != -1 && last_col >= start_col) {
            long col = last_col;
            do {
                long mode = (col == start_col || col == end_col) ? 2 : 0;
                this->draw_wall_outline(col, main_row, master_bldg, mode);
                col--;
            } while (col >= first_col);
        }

        if (first_row <= last_row) {
            long row = first_row;
            do {
                long mode = (row == start_row || row == end_row) ? 2 : 1;
                this->draw_wall_outline(start_col, row, master_bldg, mode);
                row++;
            } while (row <= last_row);
        }

        if (main_row != -1 && last_col >= first_col && last_col < start_col) {
            long col = last_col;
            do {
                long mode = (col == start_col || col == end_col) ? 2 : 0;
                this->draw_wall_outline(col, main_row, master_bldg, mode);
                col--;
            } while (col >= first_col);
        }
    } else {
        long first_col;
        long last_col;
        long main_col = -1;
        long first_row;
        long last_row;

        if (end_col > start_col) {
            first_col = start_col;
            last_col = end_col;
        } else {
            first_col = end_col;
            last_col = start_col;
        }

        if (start_row < end_row) {
            main_col = end_col;
            first_row = start_row + 1;
            last_row = end_row;
        } else if (start_row > end_row) {
            main_col = end_col;
            first_row = end_row;
            last_row = start_row - 1;
        }

        if (main_col != -1 && first_row <= start_row) {
            long row = first_row;
            do {
                long mode = (row == start_row || row == end_row) ? 2 : 1;
                this->draw_wall_outline(main_col, row, master_bldg, mode);
                row++;
            } while (row <= last_row);
        }

        if (last_col >= first_col) {
            long col = last_col;
            do {
                long mode = (col == start_col || col == end_col) ? 2 : 0;
                this->draw_wall_outline(col, start_row, master_bldg, mode);
                col--;
            } while (col >= first_col);
        }

        if (main_col != -1 && first_row <= last_row && first_row > start_row) {
            long row = first_row;
            do {
                long mode = (row == start_row || row == end_row) ? 2 : 1;
                this->draw_wall_outline(main_col, row, master_bldg, mode);
                row++;
            } while (row <= last_row);
        }
    }

    this->render_area->SetClipRect(0);
}

int TRIBE_Main_View::draw_wall_outline(long col, long row, TRIBE_Master_Building_Object* master_bldg, long facet) {
    short x4;
    short y3;
    short x2;
    short y1;
    short scr_y;
    short y2;
    short scr_x;
    short x3;
    short y4;
    short alignment_y4[2];

    if (this->get_tile_screen_coords(static_cast<short>(col), static_cast<short>(row), &x3, &scr_x, 0) != 0) {
        float world_x = static_cast<float>(col) + 0.5f;
        master_bldg->alignment_box(
            this->world, world_x, static_cast<float>(row) + 0.5f, x4, y2, scr_y, y3, y4, y1, x2, alignment_y4[0]
        );

        if (master_bldg->check_placement(
                this->player, world_x, static_cast<float>(row) + 0.5f, 0, 1, master_bldg->elevation_flag, 0, 1, 1, 1
            )
            == 0) {
            fog_next_shape = 5;
        } else {
            unsigned int time = (static_cast<unsigned int>(this->world->world_time) >> 7) & 7;
            if (time < 4)
                time += 0x24;
            else
                time = 0x2C - time;
            fog_next_shape = (time << 4) | 9;
        }

        if (master_bldg->sprite != 0) {
            x3 = static_cast<short>(x3 + (x4 - y4) / 2 + y4);
            scr_x = static_cast<short>(scr_x + (y3 - alignment_y4[0]) / 2 + alignment_y4[0]);
            SDI_Draw_Line = scr_x;
            master_bldg->draw(
                this->render_area, x3, scr_x, rge_base_game->get_player()->color_table, facet + 1, 0, 0, 0
            );
        }
    }

    fog_next_shape = 0;
    return 1;
}

int TRIBE_Main_View::command_place_object(long x, long y, int reset_mode) {
    int object_id;
    RGE_Master_Static_Object* master_obj;
    RGE_Pick_Info pick_info;

    if (allow_user_commands != 0) {
        if (rge_base_game->game_mode != TRIBE_GAME_MODE_PLACE_BUILDING) {
            return RGE_Main_View::command_place_object(x, y, 1);
        }

        if (this->pick1(0x28, 0, x, y, &pick_info, 0, 1) == 0x33) {
            this->fixup_pick_info(&pick_info);
            object_id = rge_base_game->master_obj_id;
            if (object_id != -1 && (master_obj = this->player->master_objects[object_id]) != 0) {
                master_obj->alignment(pick_info.x, pick_info.y, this->world, 0);
                if (master_obj->check_placement(
                        this->player, pick_info.x, pick_info.y, 0, 1, master_obj->elevation_flag, 0, 1, 1, 1
                    )
                    == 0) {
                    if (reset_mode != 0 || object_id == MASTER_OBJECT_TOWN_CENTER1) {
                        rge_base_game->set_game_mode(RGE_GAME_MODE_NORMAL, 0);
                    }
                    if (static_cast<TRIBE_Player*>(this->player)
                            ->command_make_building(object_id, pick_info.x, pick_info.y)
                        != 0) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int TRIBE_Main_View::command_place_multi_object(long x1, long y1, long x2, long y2, int reset_mode) {
    int result = 0;

    if (allow_user_commands == 0)
        return 0;

    short master_id = rge_base_game->master_obj_id;

    if (rge_base_game->prog_mode == ProgModeScenarioEditor) {
        if (master_id != -1) {
            TRIBE_Master_Building_Object* master = static_cast<TRIBE_Master_Building_Object*>(
                static_cast<TRIBE_Player*>(this->player)->master_objects[master_id]
            );

            if (master != 0) {
                int end_y = static_cast<int>(y2);
                int start_y = static_cast<int>(y1);
                int end_x = static_cast<int>(x2);
                int start_x = static_cast<int>(x1);

                int row_distance = abs(end_y - start_y);
                int col_distance = abs(end_x - start_x);

                if (row_distance == col_distance) {
                    this->place_line_of_walls(
                        static_cast<TRIBE_Player*>(this->player), master, start_x, start_y, end_x, end_y
                    );
                } else if (row_distance >= col_distance) {
                    this->place_line_of_walls(
                        static_cast<TRIBE_Player*>(this->player), master, start_x, start_y, start_x, end_y
                    );

                    if (end_x > start_x) {
                        this->place_line_of_walls(
                            static_cast<TRIBE_Player*>(this->player), master, start_x + 1, end_y, end_x, end_y
                        );
                        result = 1;
                    } else if (start_x > end_x) {
                        this->place_line_of_walls(
                            static_cast<TRIBE_Player*>(this->player), master, start_x - 1, end_y, end_x, end_y
                        );
                    }
                } else {
                    this->place_line_of_walls(
                        static_cast<TRIBE_Player*>(this->player), master, start_x, start_y, end_x, start_y
                    );

                    if (end_y > start_y) {
                        this->place_line_of_walls(
                            static_cast<TRIBE_Player*>(this->player), master, end_x, start_y + 1, end_x, end_y
                        );
                        result = 1;
                    } else if (start_y > end_y) {
                        this->place_line_of_walls(
                            static_cast<TRIBE_Player*>(this->player), master, end_x, start_y - 1, end_x, end_y
                        );
                    }
                }

                result = 1;
            }
        }
    } else {
        if (master_id != -1 && static_cast<TRIBE_Player*>(this->player)->master_objects[master_id] != 0) {
            if (static_cast<TRIBE_Player*>(this->player)->command_make_wall(master_id, x1, y1, x2, y2) != 0)
                result = 1;
        }

        if (reset_mode != 0)
            rge_base_game->set_game_mode(RGE_GAME_MODE_NORMAL, 0);
    }

    this->set_selection_area(-1, -1, -1, -1);
    this->set_redraw(TPanel::RedrawNormal);
    return result;
}

void TRIBE_Main_View::place_line_of_walls(
    TRIBE_Player* player, TRIBE_Master_Building_Object* master_obj, int x1, int y1, int x2, int y2
) {
    int x;
    int y;
    int y_skip;
    int x_skip;

    if (x1 == x2) {
        y_skip = 0;
    } else {
        y_skip = ((static_cast<int>(x2 <= x1) - 1) & 2) - 1;
    }

    if (y1 == y2) {
        x_skip = 0;
    } else {
        x_skip = ((static_cast<int>(y2 <= y1) - 1) & 2) - 1;
    }

    x = x1;
    y = y1;

    for (;;) {
        float world_x = static_cast<float>(x) + 0.5f;
        float world_y = static_cast<float>(y) + 0.5f;
        if (master_obj->check_placement(player, world_x, world_y, 0, 1, master_obj->elevation_flag, 0, 1, 1, 1) == 0) {
            player->make_new_object(static_cast<int>(static_cast<short>(master_obj->id)), world_x, world_y, 0, 1);
        }

        if ((x == x2) && (y == y2)) {
            break;
        }

        x += y_skip;
        y += x_skip;
    }
}

long TRIBE_Main_View::mouse_left_up_action(long x, long y, int ctrl_key, int shift_key) {
    int mode = rge_base_game->prog_mode;
    RGE_Pick_Info pick_info;

    if (mode != ProgModeGame && mode != ProgModeGameTempPaused && mode != ProgModeScenarioEditor
        && mode != ProgModeGameOver) {
        return 0;
    }

    if (rge_base_game->get_paused() != 0)
        goto default_action;

    switch (rge_base_game->game_mode) {
        case TRIBE_GAME_MODE_COMMAND_ATTACK_GROUND:
            this->release_mouse();
            if (this->mouse_action != 1 && this->mouse_action != 2)
                goto invalid_action;
            if (this->pick1(0x28, 0, x, y, &pick_info, 0, 1) == 0x33) {
                this->fixup_pick_info(&pick_info);
                if (static_cast<TRIBE_Player*>(this->player)->command_attack_ground(pick_info.x, pick_info.y) != 0) {
                    this->reset_display_object_selection(2);
                    this->add_overlay_sprite(
                        rge_base_game->shapes[2], 0, this->map_scr_x_offset + x, this->map_scr_y_offset + y, 0, 0x0F, 0,
                        2, 0x7D
                    );
                    this->set_redraw(TPanel::RedrawNormal);
                    goto done_b;
                }
            }
            goto error_b;

        case TRIBE_GAME_MODE_COMMAND_HEAL:
            this->release_mouse();
            if (this->mouse_action != 1 && this->mouse_action != 2)
                goto invalid_action;
            if (this->command_make_do(x, y, 0, 0x69) != 0)
                goto done_a;
            rge_base_game->play_sound(3);
            goto done_a;

        done_a:
            rge_base_game->set_game_mode(RGE_GAME_MODE_NORMAL, 0);
        return_one:
            return 1;

        error_a:
            rge_base_game->play_sound(3);
            goto done_a;

        default_action:
            return RGE_Main_View::mouse_left_up_action(x, y, ctrl_key, shift_key);

        case TRIBE_GAME_MODE_COMMAND_CONVERT:
            this->release_mouse();
            if (this->mouse_action != 1 && this->mouse_action != 2)
                goto invalid_action;
            if (this->command_make_do(x, y, 0, 0x68) == 0)
                goto error_b;
            goto done_b;

        error_b:
            rge_base_game->play_sound(3);
        done_b:
            rge_base_game->set_game_mode(RGE_GAME_MODE_NORMAL, 0);
            return 1;

        case TRIBE_GAME_MODE_COMMAND_ATTACK:
            this->release_mouse();
            if (this->mouse_action != 1 && this->mouse_action != 2)
                goto invalid_action;
            if (this->command_make_do(x, y, 0, 7) != 0)
                goto done_a;
            goto error_a;

        case TRIBE_GAME_MODE_COMMAND_REPAIR: {
            this->release_mouse();
            if (this->mouse_action != 1 && this->mouse_action != 2)
                goto invalid_action;
            RGE_Static_Object* object = this->pick_best_target(x, y, 0, -1);
            if (object != 0 && static_cast<TRIBE_Player*>(this->player)->command_make_repair(object) != 0) {
                this->display_object_selection(object->id, 0x5DC, 2, 2);
                this->reset_overlay_sprites();
                this->set_redraw(TPanel::RedrawNormal);
                goto done_a;
            }
            goto error_a;
        }

        case TRIBE_GAME_MODE_COMMAND_UNLOAD:
            this->release_mouse();
            if (this->mouse_action != 1 && this->mouse_action != 2)
                goto invalid_action;
            if (this->pick1(0x28, 0, x, y, &pick_info, 0, 1) == 0x33) {
                this->fixup_pick_info(&pick_info);
                if (static_cast<TRIBE_Player*>(this->player)->command_make_unload(pick_info.x, pick_info.y) != 0) {
                    this->reset_display_object_selection(2);
                    this->add_overlay_sprite(
                        rge_base_game->shapes[2], 0, this->map_scr_x_offset + x, this->map_scr_y_offset + y, 0, 0x0F, 0,
                        2, 0x7D
                    );
                    this->set_redraw(TPanel::RedrawNormal);
                    goto done_a;
                }
            }
            goto error_a;

        default:
            goto default_action;
    }

invalid_action:
    goto return_one;
}

long TRIBE_Main_View::mouse_right_up_action(long x, long y, int ctrl_key, int shift_key) {
    int mode = rge_base_game->prog_mode;
    RGE_Pick_Info pick_info;

    if (mode != ProgModeGame && mode != ProgModeGameTempPaused && mode != ProgModeScenarioEditor
        && mode != ProgModeGameOver) {
        return 0;
    }

    if (rge_base_game->get_paused() != 0)
        goto default_action;

    switch (rge_base_game->game_mode) {
        case TRIBE_GAME_MODE_COMMAND_ATTACK_GROUND:
            this->release_mouse();
            if (this->mouse_action != 1 && this->mouse_action != 2)
                goto invalid_action;
            if (this->pick1(0x28, 0, x, y, &pick_info, 0, 1) == 0x33) {
                this->fixup_pick_info(&pick_info);
                if (static_cast<TRIBE_Player*>(this->player)->command_attack_ground(pick_info.x, pick_info.y) != 0) {
                    this->reset_display_object_selection(2);
                    this->add_overlay_sprite(
                        rge_base_game->shapes[2], 0, this->map_scr_x_offset + x, this->map_scr_y_offset + y, 0, 0x0F, 0,
                        2, 0x7D
                    );
                    this->set_redraw(TPanel::RedrawNormal);
                    goto done_b;
                }
            }
            goto error_b;

        case TRIBE_GAME_MODE_COMMAND_HEAL:
            this->release_mouse();
            if (this->mouse_action != 1 && this->mouse_action != 2)
                goto invalid_action;
            if (this->command_make_do(x, y, 0, 0x69) != 0)
                goto done_a;
            goto error_a;

        error_a:
            rge_base_game->play_sound(3);
        done_a:
            rge_base_game->set_game_mode(RGE_GAME_MODE_NORMAL, 0);
        invalid_action:
            return 1;

        default:
        default_action:
            return RGE_Main_View::mouse_right_up_action(x, y, ctrl_key, shift_key);

        case TRIBE_GAME_MODE_COMMAND_CONVERT:
            this->release_mouse();
            if (this->mouse_action != 1 && this->mouse_action != 2)
                goto invalid_action;
            if (this->command_make_do(x, y, 0, 0x68) != 0)
                goto done_b;
            goto error_b;

        error_b:
            rge_base_game->play_sound(3);
        done_b:
            rge_base_game->set_game_mode(RGE_GAME_MODE_NORMAL, 0);
            return 1;

        case TRIBE_GAME_MODE_COMMAND_ATTACK:
            this->release_mouse();
            if (this->mouse_action != 1 && this->mouse_action != 2)
                goto invalid_action;
            if (this->command_make_do(x, y, 0, 7) != 0)
                goto done_a;
            goto error_a;

        case TRIBE_GAME_MODE_COMMAND_REPAIR:
            this->release_mouse();
            if (this->mouse_action != 1 && this->mouse_action != 2)
                goto invalid_action;
            {
                RGE_Static_Object* object = this->pick_best_target(x, y, 0, -1);
                if (object != 0 && static_cast<TRIBE_Player*>(this->player)->command_make_repair(object) != 0) {
                    this->display_object_selection(object->id, 0x5DC, 2, 2);
                    this->reset_overlay_sprites();
                    this->set_redraw(TPanel::RedrawNormal);
                    goto done_a;
                }
            }
            goto error_a;

        case TRIBE_GAME_MODE_COMMAND_UNLOAD:
            this->release_mouse();
            if (this->mouse_action != 1) {
                if (this->mouse_action != 2)
                    goto invalid_action;
            }
            if (this->pick1(0x28, 0, x, y, &pick_info, 0, 1) == 0x33) {
                this->fixup_pick_info(&pick_info);
                if (static_cast<TRIBE_Player*>(this->player)->command_make_unload(pick_info.x, pick_info.y) != 0) {
                    this->reset_display_object_selection(2);
                    this->add_overlay_sprite(
                        rge_base_game->shapes[2], 0, this->map_scr_x_offset + x, this->map_scr_y_offset + y, 0, 0x0F, 0,
                        2, 0x7D
                    );
                    this->set_redraw(TPanel::RedrawNormal);
                    goto done_a;
                }
            }
            goto error_a;
    }
}

int TRIBE_Main_View::pick_through_fog(RGE_Static_Object* obj) {
    if ((obj != 0) && (obj->master_obj->id == MASTER_OBJECT_DOCK_1)) {
        return 1;
    }
    return RGE_View::pick_through_fog(obj);
}

int TRIBE_Main_View::pick_weight(RGE_Static_Object* obj, int confidence) {
    unsigned char select_level = obj->master_obj->select_level;

    if (obj->master_obj->id == MASTER_OBJECT_WATCH_TOWER || obj->master_obj->id == MASTER_OBJECT_SENTRY_TOWER
        || obj->master_obj->id == MASTER_OBJECT_GUARD_TOWER || obj->master_obj->id == MASTER_OBJECT_GUARD_TOWER2) {
        select_level = 3;
    }

    int touched;
    if (this->UC_ObjectTouched != 0 && this->UC_TouchedObj == obj->id)
        touched = 1;
    else
        touched = 0;

    int result = 0;
    switch (select_level) {
        case 4:
            if (touched)
                return 5;
            if (confidence == 1 || confidence == 2)
                return 4;
            if (confidence == 3)
                return 3;
            return 2;

        case 3:
            if (touched)
                return 5;
            if (confidence == 1 || confidence == 2)
                result = 3;
            else if (confidence == 3 && obj->object_state < RGE_OBJECT_STATE_ACTIVE)
                result = 2;
            break;

        case 2:
            if (touched)
                return 5;
            if (confidence == 1 || confidence == 2)
                result = 3;
            else if (confidence == 3)
                result = 2;
            break;

        default:
            return 1;
    }

    return result;
}

int TRIBE_Main_View::command_make_do(long x, long y, int work_on_tile, short action_type) {
    return RGE_Main_View::command_make_do(x, y, work_on_tile, action_type);
}

long TRIBE_Main_View::mouse_left_dbl_click_action(long x, long y, int ctrl_key, int shift_key) {
    RGE_Pick_Info pick_info;

    if (this->pick1(0x29, 1, x, y, &pick_info, 0, 1) == 0x34) {
        if ((pick_info.object->master_obj->select_level == 4) && (pick_info.object->owner == this->player)) {
            if ((ctrl_key == 0) && (shift_key == 0)) {
                this->player->unselect_object();
            }

            this->player->select_one_object(pick_info.object, 0);

            short object_id = pick_info.object->master_obj->id;
            unsigned char unit_level = pick_info.object->master_obj->unit_level;
            if (unit_level != 3) {
                unit_level = static_cast<unsigned char>(-1);
            }

            RGE_Object_Node* node = this->player->objects->list;
            while (node != 0) {
                RGE_Static_Object* object = node->node;
                if ((object->master_obj->id == object_id) || (object->master_obj->unit_level == unit_level)) {
                    if (this->Object_Was_Displayed(object->id, false)) {
                        this->player->select_one_object(object, 0);
                    }
                }
                node = node->next;
            }

            this->player->select_one_object(pick_info.object, 0);
            return 1;
        }
    }

    return 0;
}
