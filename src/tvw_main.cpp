// Authentic source module for C:\\msdev\\work\\age1_x1\\tvw_main.cpp.
// Definitions follow the PDB source order.  The normal owners are kept in
// this one compiler-facing source file.  The original executable is the
// behavior oracle; nonexact bodies remain documented below.
//
// PDB boundary audit:
//   0052CAF0  39-210  draw_multi_object_outline
//   0052D060 216-275  draw_wall_outline
//   0052D1F0 281-313  command_place_object
//   0052D320 319-376  command_place_multi_object
//   0052D4F0 382-418  place_line_of_walls
//   0052D600 424-534  mouse_left_up_action
//   0052D970 540-650  mouse_right_up_action
//   0052DCE0 656-661  pick_through_fog
//   0052DD10 667-723  pick_weight
//   0052DE20 731-769  command_make_do
//   0052DE40 776-817  mouse_left_dbl_click_action
//
// The nearby 00495470/00495490 destructor entries are compiler-generated.
//
// 0052CAF0 remains scratch. Its natural body preserves all 28 wall calls and
// has a 1203-byte strict difference. 0052D600 and 0052D970 remain accepted
// drift with 14 caller-saved register-color bytes each.  The other eight
// normal bodies are exact in the grouped module check.

#include "../include/basegame.h"
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

extern int allow_user_commands;
extern int SDI_Draw_Line;

void TRIBE_Main_View::draw_multi_object_outline() {
    short master_id;
    long calc_row2;
    TRIBE_Master_Building_Object* master;
    long end_col;
    long end_row;
    long calc_col1;
    long start_col;
    long calc_col2;
    long main_row;
    long main_col;
    long calc_row1;
    long start_row;
    long col;
    long row;
    long endpoint;
    int row_distance;
    int col_distance;
    tagPOINT point;
    RGE_Pick_Info pick_info;

    master_id = rge_base_game->master_obj_id;
    if (master_id == -1)
        return;

    master = (TRIBE_Master_Building_Object*)
        this->player->master_objects[(int)master_id];
    if (master == 0)
        return;

    this->render_area->SetClipRect(&this->clip_rect);

    if (this->get_selection_area(
            start_col, start_row, main_row, end_row, 0) == 0) {
        rge_base_game->get_mouse_pos(point);
        if (this->is_inside(point.x, point.y) == 0)
            return;

        if (this->pick1(
                0x28, 0, point.x - this->pnl_x, point.y - this->pnl_y,
                &pick_info, 0, 1) != 0x33)
            return;

        this->fixup_pick_info(&pick_info);
        start_col = (int)pick_info.x;
        main_row = start_col;
        start_row = (int)pick_info.y;
        end_row = start_row;
    }

    calc_row1 = -1;
    main_col = -1;
    end_col = main_row;
    col_distance = end_col - start_col;
    if (col_distance < 0)
        col_distance = -col_distance;
    row_distance = end_row - start_row;
    if (row_distance < 0)
        row_distance = -row_distance;

    if (col_distance == row_distance) {
        if (end_col < start_col) {
            col = end_col;
            row = end_row;
            if (end_row < start_row) {
                while (col <= start_col) {
                    this->draw_wall_outline(col, row, master, 2);
                    ++col;
                    ++row;
                }
                this->render_area->SetClipRect(0);
                return;
            }
            col = start_col;
            row = start_row;
            if (start_col > end_col) {
                if (col >= end_col) {
                    while (col >= end_col) {
                        this->draw_wall_outline(col, row, master, 2);
                        --col;
                        ++row;
                    }
                    this->render_area->SetClipRect(0);
                    return;
                }
            }
        }

        col = end_col;
        row = end_row;
        if (end_row < start_row) {
            while (col >= start_col) {
                this->draw_wall_outline(col, row, master, 2);
                --col;
                ++row;
            }
            this->render_area->SetClipRect(0);
            return;
        }

        col = start_col;
        row = start_row;
        if (start_col <= end_col) {
            while (col <= end_col) {
                this->draw_wall_outline(col, row, master, 2);
                ++col;
                ++row;
            }
            this->render_area->SetClipRect(0);
            return;
        }
    }

    if (col_distance > row_distance) {
        calc_row2 = end_row;
        end_row = end_col;
        calc_col2 = start_col;
        if (start_col < end_col) {
            end_row = start_col;
            calc_col2 = end_col;
        }

        if (start_row < calc_row2) {
            point.x = start_row + 1;
            calc_row1 = end_col;
            calc_col1 = calc_row2;
            main_col = start_row;
        } else if (calc_row2 < start_row) {
            point.x = calc_row2;
            calc_row1 = end_col;
            calc_col1 = start_row;
            main_col = start_row;
        }

        if (calc_row1 == -1 || start_row < point.x) {
            if (end_row <= calc_col2) {
                for (col = calc_col2; col >= end_row; --col) {
                    endpoint = (col == start_col || col == end_col) ? 2 : 0;
                    this->draw_wall_outline(col, start_row, master, endpoint);
                }
            }
            if (calc_row1 != -1 && point.x <= calc_col1) {
                for (row = point.x; row <= calc_col1; ++row) {
                    endpoint = (row == start_row || row == calc_row2) ? 2 : 1;
                    this->draw_wall_outline(calc_row1, row, master, endpoint);
                }
            }
        } else {
            if (calc_row1 != -1 && point.x <= calc_col1) {
                for (row = point.x; row <= calc_col1; ++row) {
                    endpoint = (row == start_row || row == calc_row2) ? 2 : 1;
                    this->draw_wall_outline(calc_row1, row, master, endpoint);
                }
            }
            if (end_row <= calc_col2) {
                for (col = calc_col2; col >= end_row; --col) {
                    endpoint = (col == start_col || col == end_col) ? 2 : 0;
                    this->draw_wall_outline(col, start_row, master, endpoint);
                }
            }
        }
        this->render_area->SetClipRect(0);
        return;
    }

    calc_row1 = start_row;
    calc_row2 = end_row;
    if (calc_row2 < calc_row1) {
        calc_row1 = end_row;
        calc_row2 = start_row;
    }

    main_col = -1;
    if (start_col < end_col) {
        main_col = end_row;
        calc_col1 = start_col + 1;
        calc_col2 = end_col;
    } else if (end_col < start_col) {
        main_col = end_row;
        calc_col1 = end_col;
        calc_col2 = start_col - 1;
    }

    if (main_col == -1 || calc_col2 < start_col) {
        if (calc_row1 <= calc_row2) {
            for (row = calc_row1; row <= calc_row2; ++row) {
                endpoint = (row == start_row || row == end_row) ? 2 : 0;
                this->draw_wall_outline(start_col, row, master, endpoint);
            }
        }
        if (main_col != -1 && calc_col1 <= calc_col2) {
            for (col = calc_col1; col <= calc_col2; ++col) {
                endpoint = (col == start_col || col == end_col) ? 2 : 1;
                this->draw_wall_outline(col, main_col, master, endpoint);
            }
        }
    } else {
        if (main_col != -1 && calc_col1 <= calc_col2) {
            for (col = calc_col1; col <= calc_col2; ++col) {
                endpoint = (col == start_col || col == end_col) ? 2 : 1;
                this->draw_wall_outline(col, main_col, master, endpoint);
            }
        }
        if (calc_row1 <= calc_row2) {
            for (row = calc_row1; row <= calc_row2; ++row) {
                endpoint = (row == start_row || row == end_row) ? 2 : 0;
                this->draw_wall_outline(start_col, row, master, endpoint);
            }
        }
    }
    this->render_area->SetClipRect(0);
}

int TRIBE_Main_View::draw_wall_outline(
    long x, long y, TRIBE_Master_Building_Object* master, long mode) {
    short x4;
    short y3;
    short x2;
    short y1;
    short scr_y;
    short local_12;
    short scr_x;
    short x3;
    short y4;
    short local_4[2];

    if (this->get_tile_screen_coords(
            (short)x, (short)y, &x3, &scr_x, 0) != 0) {
        float coordinate_x = (float)x + 0.5f;
        master->alignment_box(
            this->world, coordinate_x, (float)y + 0.5f,
            x4, local_12, scr_y, y3, y4, y1, x2, local_4[0]);

        if (master->check_placement(
                this->player, coordinate_x, (float)y + 0.5f,
                0, 1, master->elevation_flag, 0, 1, 1, 1) == 0) {
            fog_next_shape = 5;
        } else {
            unsigned int time = ((unsigned int)this->world->world_time >> 7) & 7;
            if (time < 4)
                time += 0x24;
            else
                time = 0x2C - time;
            fog_next_shape = (time << 4) | 9;
        }

        if (master->sprite != 0) {
            x3 = (short)((int)x3 +
                ((int)x4 - (int)y4) / 2 + y4);
            scr_x = (short)((int)scr_x +
                ((int)y3 - (int)local_4[0]) / 2 + local_4[0]);
            SDI_Draw_Line = (int)scr_x;
            master->draw(
                this->render_area,
                x3, scr_x,
                rge_base_game->get_player()->color_table,
                mode + 1, 0, 0, 0);
        }
    }

    fog_next_shape = 0;
    return 1;
}

int TRIBE_Main_View::command_place_object(long x, long y, int param_3) {
    int object_id;
    RGE_Master_Static_Object* master_obj;
    RGE_Pick_Info pick_info;

    if (allow_user_commands != 0) {
        if (rge_base_game->game_mode != 7) {
            return RGE_Main_View::command_place_object(x, y, 1);
        }

        if (this->pick1(0x28, 0, x, y, &pick_info, 0, 1) == 0x33) {
            this->fixup_pick_info(&pick_info);
            object_id = rge_base_game->master_obj_id;
            if (object_id != -1 &&
                (master_obj = this->player->master_objects[object_id]) != 0) {
                master_obj->alignment(pick_info.x, pick_info.y,
                                      this->world, 0);
                if (master_obj->check_placement(
                        this->player, pick_info.x, pick_info.y, 0,
                        1, master_obj->elevation_flag, 0, 1, 1, 1) == 0) {
                    if (param_3 != 0 || object_id == 0x6D) {
                        rge_base_game->set_game_mode(0, 0);
                    }
                    if (static_cast<TRIBE_Player*>(this->player)->command_make_building(
                            object_id, pick_info.x, pick_info.y) != 0) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int TRIBE_Main_View::command_place_multi_object(
    long param_1, long param_2, long param_3, long param_4, int mode) {
    int result = 0;

    if (allow_user_commands == 0)
        return 0;

    short master_id = rge_base_game->master_obj_id;

    if (rge_base_game->prog_mode == 7) {
        if (master_id != -1) {
        TRIBE_Master_Building_Object* master =
            (TRIBE_Master_Building_Object*)
                ((TRIBE_Player*)this->player)->master_objects[master_id];

        if (master != 0) {
            int end_y = (int)param_4;
            int start_y = (int)param_2;
            int end_x = (int)param_3;
            int start_x = (int)param_1;

            int row_distance = abs(end_y - start_y);
            int col_distance = abs(end_x - start_x);

            if (row_distance == col_distance) {
                this->place_line_of_walls(
                    (TRIBE_Player*)this->player, master,
                    start_x, start_y, end_x, end_y);
            } else if (row_distance >= col_distance) {
                this->place_line_of_walls(
                    (TRIBE_Player*)this->player, master,
                    start_x, start_y, start_x, end_y);

                if (end_x > start_x) {
                    this->place_line_of_walls(
                        (TRIBE_Player*)this->player, master,
                        start_x + 1, end_y, end_x, end_y);
                    result = 1;
                } else if (start_x > end_x) {
                    this->place_line_of_walls(
                        (TRIBE_Player*)this->player, master,
                        start_x - 1, end_y, end_x, end_y);
                }
            } else {
                this->place_line_of_walls(
                    (TRIBE_Player*)this->player, master,
                    start_x, start_y, end_x, start_y);

                if (end_y > start_y) {
                    this->place_line_of_walls(
                        (TRIBE_Player*)this->player, master,
                        end_x, start_y + 1, end_x, end_y);
                    result = 1;
                } else if (start_y > end_y) {
                    this->place_line_of_walls(
                        (TRIBE_Player*)this->player, master,
                        end_x, start_y - 1, end_x, end_y);
                }
            }

            result = 1;
        }
        }
    } else {
        if (master_id != -1 &&
            ((TRIBE_Player*)this->player)->master_objects[master_id] != 0) {
            if (((TRIBE_Player*)this->player)->command_make_wall(
                    master_id, param_1, param_2, param_3, param_4) != 0)
                result = 1;
        }

        if (mode != 0)
            rge_base_game->set_game_mode(0, 0);
    }

    this->set_selection_area(-1, -1, -1, -1);
    this->set_redraw(TPanel::RedrawNormal);
    return result;
}

void TRIBE_Main_View::place_line_of_walls(
    TRIBE_Player* player,
    TRIBE_Master_Building_Object* master,
    int x1,
    int y1,
    int x2,
    int y2) {
    int x;
    int y;
    int y_skip;
    int x_skip;

    if (x1 == x2) {
        y_skip = 0;
    } else {
        y_skip = (((int)(x2 <= x1) - 1) & 2) - 1;
    }

    if (y1 == y2) {
        x_skip = 0;
    } else {
        x_skip = (((int)(y2 <= y1) - 1) & 2) - 1;
    }

    x = x1;
    y = y1;

    for (;;) {
        float coordinate_x = (float)x + 0.5f;
        float coordinate_y = (float)y + 0.5f;
        if (master->check_placement(
                player,
                coordinate_x,
                coordinate_y,
                0,
                1,
                master->elevation_flag,
                0,
                1,
                1,
                1) == 0) {
            player->make_new_object(
                (int)(short)master->id,
                coordinate_x,
                coordinate_y,
                0,
                1);
        }

        if ((x == x2) && (y == y2)) {
            break;
        }

        x += y_skip;
        y += x_skip;
    }
}

long TRIBE_Main_View::mouse_left_up_action(long param_1, long param_2,
                                           int param_3, int param_4) {
    int mode = rge_base_game->prog_mode;
    RGE_Pick_Info pick_info;
    RGE_Static_Object* object;

    if (mode != 4 && mode != 6 && mode != 7 && mode != 5) {
        return 0;
    }

    if (rge_base_game->get_paused() != 0)
        goto default_action;

    switch (rge_base_game->game_mode) {
    case 100:
        this->release_mouse();
        if (this->mouse_action != 1 && this->mouse_action != 2)
            goto invalid_action;
        if (this->pick1(0x28, 0, param_1, param_2, &pick_info, 0, 1) == 0x33) {
            this->fixup_pick_info(&pick_info);
            if (static_cast<TRIBE_Player*>(this->player)->command_attack_ground(pick_info.x, pick_info.y) != 0) {
                this->reset_display_object_selection(2);
                this->add_overlay_sprite(
                    rge_base_game->shapes[2], 0,
                    this->map_scr_x_offset + param_1,
                    this->map_scr_y_offset + param_2,
                    0, 0x0F, 0, 2, 0x7D);
                this->set_redraw(TPanel::RedrawNormal);
                goto done_b;
            }
        }
        goto error_b;

    case 102:
        this->release_mouse();
        if (this->mouse_action != 1 && this->mouse_action != 2)
            goto invalid_action;
        if (this->command_make_do(param_1, param_2, 0, 0x69) != 0)
            goto done_a;
        rge_base_game->play_sound(3);
        goto done_a;

done_a:
        rge_base_game->set_game_mode(0, 0);
return_one:
        return 1;

error_a:
        rge_base_game->play_sound(3);
        goto done_a;

default_action:
        return RGE_Main_View::mouse_left_up_action(
            param_1, param_2, param_3, param_4);

    case 101:
        this->release_mouse();
        if (this->mouse_action != 1 && this->mouse_action != 2)
            goto invalid_action;
        if (this->command_make_do(param_1, param_2, 0, 0x68) == 0)
            goto error_b;
        goto done_b;

error_b:
        rge_base_game->play_sound(3);
done_b:
        rge_base_game->set_game_mode(0, 0);
        return 1;

    case 103:
        this->release_mouse();
        if (this->mouse_action != 1 && this->mouse_action != 2)
            goto invalid_action;
        if (this->command_make_do(param_1, param_2, 0, 7) != 0)
            goto done_a;
        goto error_a;

    case 104:
        this->release_mouse();
        if (this->mouse_action != 1 && this->mouse_action != 2)
            goto invalid_action;
        object = this->pick_best_target(param_1, param_2, 0, -1);
        if (object != 0 && static_cast<TRIBE_Player*>(this->player)->command_make_repair(object) != 0) {
            this->display_object_selection(object->id, 0x5DC, 2, 2);
            this->reset_overlay_sprites();
            this->set_redraw(TPanel::RedrawNormal);
            goto done_a;
        }
        goto error_a;

    case 105:
        this->release_mouse();
        if (this->mouse_action != 1 && this->mouse_action != 2)
            goto invalid_action;
        if (this->pick1(0x28, 0, param_1, param_2, &pick_info, 0, 1) == 0x33) {
            this->fixup_pick_info(&pick_info);
            if (static_cast<TRIBE_Player*>(this->player)->command_make_unload(pick_info.x, pick_info.y) != 0) {
                this->reset_display_object_selection(2);
                this->add_overlay_sprite(
                    rge_base_game->shapes[2], 0,
                    this->map_scr_x_offset + param_1,
                    this->map_scr_y_offset + param_2,
                    0, 0x0F, 0, 2, 0x7D);
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

long TRIBE_Main_View::mouse_right_up_action(long param_1, long param_2,
                                            int param_3, int param_4) {
    int mode = rge_base_game->prog_mode;
    RGE_Pick_Info pick_info;

    if (mode != 4 && mode != 6 && mode != 7 && mode != 5) {
        return 0;
    }

    if (rge_base_game->get_paused() != 0)
        goto default_action;

    switch (rge_base_game->game_mode) {
    case 100:
        this->release_mouse();
        if (this->mouse_action != 1 && this->mouse_action != 2)
            goto invalid_action;
        if (this->pick1(0x28, 0, param_1, param_2, &pick_info, 0, 1) == 0x33) {
            this->fixup_pick_info(&pick_info);
            if (static_cast<TRIBE_Player*>(this->player)->command_attack_ground(pick_info.x, pick_info.y) != 0) {
                this->reset_display_object_selection(2);
                this->add_overlay_sprite(
                    rge_base_game->shapes[2], 0,
                    this->map_scr_x_offset + param_1,
                    this->map_scr_y_offset + param_2,
                    0, 0x0F, 0, 2, 0x7D);
                this->set_redraw(TPanel::RedrawNormal);
                goto done_b;
            }
        }
        goto error_b;

    case 102:
        this->release_mouse();
        if (this->mouse_action != 1 && this->mouse_action != 2)
            goto invalid_action;
        if (this->command_make_do(param_1, param_2, 0, 0x69) != 0)
            goto done_a;
        goto error_a;

error_a:
        rge_base_game->play_sound(3);
done_a:
    rge_base_game->set_game_mode(0, 0);
invalid_action:
    return 1;

    default:
default_action:
        return RGE_Main_View::mouse_right_up_action(
            param_1, param_2, param_3, param_4);

    case 101:
        this->release_mouse();
        if (this->mouse_action != 1 && this->mouse_action != 2)
            goto invalid_action;
        if (this->command_make_do(param_1, param_2, 0, 0x68) != 0)
            goto done_b;
        goto error_b;

error_b:
        rge_base_game->play_sound(3);
done_b:
        rge_base_game->set_game_mode(0, 0);
        return 1;

    case 103:
        this->release_mouse();
        if (this->mouse_action != 1 && this->mouse_action != 2)
            goto invalid_action;
        if (this->command_make_do(param_1, param_2, 0, 7) != 0)
            goto done_a;
        goto error_a;

    case 104:
        this->release_mouse();
        if (this->mouse_action != 1 && this->mouse_action != 2)
            goto invalid_action;
        {
            RGE_Static_Object* object = this->pick_best_target(
                param_1, param_2, 0, -1);
            if (object != 0 && static_cast<TRIBE_Player*>(this->player)->command_make_repair(object) != 0) {
                this->display_object_selection(object->id, 0x5DC, 2, 2);
                this->reset_overlay_sprites();
                this->set_redraw(TPanel::RedrawNormal);
                goto done_a;
            }
        }
        goto error_a;

    case 105:
        this->release_mouse();
        if (this->mouse_action != 1) {
            if (this->mouse_action != 2)
                goto invalid_action;
        }
        if (this->pick1(0x28, 0, param_1, param_2, &pick_info, 0, 1) == 0x33) {
            this->fixup_pick_info(&pick_info);
            if (static_cast<TRIBE_Player*>(this->player)->command_make_unload(pick_info.x, pick_info.y) != 0) {
                this->reset_display_object_selection(2);
                this->add_overlay_sprite(
                    rge_base_game->shapes[2], 0,
                    this->map_scr_x_offset + param_1,
                    this->map_scr_y_offset + param_2,
                    0, 0x0F, 0, 2, 0x7D);
                this->set_redraw(TPanel::RedrawNormal);
                goto done_a;
            }
        }
        goto error_a;

    }
}

int TRIBE_Main_View::pick_through_fog(RGE_Static_Object* obj) {
    if ((obj != 0) && (obj->master_obj->id == 0x2D)) {
        return 1;
    }
    return RGE_View::pick_through_fog(obj);
}

int TRIBE_Main_View::pick_weight(RGE_Static_Object* param_1, int param_2) {
    unsigned char select_level = param_1->master_obj->select_level;

    if (param_1->master_obj->id == 0x4F ||
        param_1->master_obj->id == 0xC7 ||
        param_1->master_obj->id == 0x45 ||
        param_1->master_obj->id == 0x116) {
        select_level = 3;
    }

    int touched;
    if (this->UC_ObjectTouched != 0 && this->UC_TouchedObj == param_1->id)
        touched = 1;
    else
        touched = 0;

    int result = 0;
    switch (select_level) {
        case 4:
            if (touched)
                return 5;
            if (param_2 == 1 || param_2 == 2)
                return 4;
            if (param_2 == 3)
                return 3;
            return 2;

        case 3:
            if (touched)
                return 5;
            if (param_2 == 1 || param_2 == 2)
                result = 3;
            else if (param_2 == 3 && param_1->object_state < 2)
                result = 2;
            break;

        case 2:
            if (touched)
                return 5;
            if (param_2 == 1 || param_2 == 2)
                result = 3;
            else if (param_2 == 3)
                result = 2;
            break;

        default:
            return 1;
    }

    return result;
}

int TRIBE_Main_View::command_make_do(
    long x, long y, int mode, short flag) {
    return RGE_Main_View::command_make_do(x, y, mode, flag);
}

long TRIBE_Main_View::mouse_left_dbl_click_action(long x, long y,
                                                   int key, int flags) {
    RGE_Pick_Info pick_info;

    if (this->pick1(0x29, 1, x, y, &pick_info, 0, 1) == 0x34) {
        if ((pick_info.object->master_obj->select_level == 4) &&
            (pick_info.object->owner == this->player)) {
            if ((key == 0) && (flags == 0)) {
                this->player->unselect_object();
            }

            this->player->select_one_object(pick_info.object, 0);

            short object_id = pick_info.object->master_obj->id;
            unsigned char unit_level = pick_info.object->master_obj->unit_level;
            if (unit_level != 3) {
                unit_level = (unsigned char)-1;
            }

            RGE_Object_Node* node = this->player->objects->list;
            while (node != 0) {
                RGE_Static_Object* object = node->node;
                if ((object->master_obj->id == object_id) ||
                    (object->master_obj->unit_level == unit_level)) {
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
