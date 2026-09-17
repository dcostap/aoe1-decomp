
#include "../include/basegame.h"
#include "../include/main.h"
#include "../include/view.h"
#include "../include/map.h"
#include "../include/player.h"
#include "../include/world.h"
#include "../include/stat_obj.h"
#include "../include/asp_list.h"
#include "../include/visible.h"
#include "../include/m_ac_obj.h"
#include "../include/act_obj.h"
#include "../include/sprite.h"
#include "../include/task_lst.h"
#include "../include/vw_main.h"

#include <stdlib.h>
#include <string.h>

extern void __cdecl color_log(unsigned char, unsigned char, int);
extern unsigned long __cdecl debug_timeGetTime(char*, int);
extern void __cdecl write_draw_log2(char*);

RGE_Main_View::RGE_Main_View() : RGE_View() {
    this->map_view = 0;
    this->last_mouse_scroll_time = 0;
    this->mouse_scrolling = 0;
    this->last_key_scroll_time = 0;
    this->mouse_move_tolerance = 10;
    this->mouse_last_x = -1;
    this->mouse_last_y = -1;
    this->key_scrolling = 0;
    this->save_player = 0;
}

long RGE_Main_View::handle_idle() {
    long result;

    color_log('E', 'E', 5);
    do_auto_scroll();
    color_log('E', 0x16, 5);
    handle_keys();
    color_log('E', '$', 5);
    result = TPanel::handle_idle();
    color_log('E', '_', 5);
    return result;
}

int RGE_Main_View::do_auto_scroll() {
    tagRECT rect;
    tagPOINT point;
    float scroll_dist2;
    short vert_scroll;
    short horz_scroll;
    RGE_Prog_Info* info;
    unsigned long now;
    unsigned long elapsed;

    if ((rge_base_game->prog_mode == 4 || rge_base_game->prog_mode == 6 ||
         rge_base_game->prog_mode == 7 || rge_base_game->prog_mode == 5) &&
        rge_base_game->get_paused() == 0 &&
        rge_base_game->prog_info->auto_scroll != 0 &&
        GetForegroundWindow() == this->TPanel::render_area->Wnd &&
        panel_system.modalPanel() == 0 &&
        (panel_system.mouseOwner() == 0 || panel_system.mouseOwner() == this) &&
        this->key_scrolling == 0) {
        GetWindowRect(this->TPanel::render_area->Wnd, &rect);
        GetCursorPos(&point);

        horz_scroll = 0;
        vert_scroll = 0;
        info = rge_base_game->prog_info;

        if (GetAsyncKeyState(1) >= 0 && GetAsyncKeyState(2) >= 0) {
            if (point.x < rect.left + info->mouse_scroll_edge)
                vert_scroll = -1;
            else if (point.x > rect.right - info->mouse_scroll_edge)
                vert_scroll = 1;

            if (point.y < rect.top + info->mouse_scroll_edge)
                horz_scroll = -1;
            else if (point.y > rect.bottom - info->mouse_scroll_edge)
                horz_scroll = 1;

            if (vert_scroll != 0 || horz_scroll != 0) {
                now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\vw_main.cpp", 170);
                elapsed = now - this->last_mouse_scroll_time;
                if (this->mouse_scrolling == 0) {
                    scroll_dist2 = DAT_00577900;
                    this->mouse_scrolling = 1;
                } else {
                    scroll_dist2 = (float)elapsed / info->key_scroll_interval;
                    long whole = (long)scroll_dist2;
                    scroll_dist2 -= (float)whole;
                    if (scroll_dist2 < DAT_00577904)
                        scroll_dist2 = DAT_00577908;
                    else
                        scroll_dist2 = DAT_00577904;
                    scroll_dist2 += (float)whole;
                }

                if (scroll_dist2 > info->mouse_scroll_max_dist)
                    scroll_dist2 = info->mouse_scroll_max_dist;

                if (scroll_dist2 > DAT_00577908) {
                    float scroll_dist = scroll_dist2 + scroll_dist2;
                    if (vert_scroll == -1)
                        this->player->set_view_loc(this->player->view_x - scroll_dist2,
                                                   this->player->view_y - scroll_dist2);
                    else if (vert_scroll == 1)
                        this->player->set_view_loc(this->player->view_x + scroll_dist2,
                                                   this->player->view_y + scroll_dist2);

                    if (horz_scroll == -1)
                        this->player->set_view_loc(this->player->view_x + scroll_dist, this->player->view_y - scroll_dist);
                    else if (horz_scroll == 1)
                        this->player->set_view_loc(this->player->view_x - scroll_dist, this->player->view_y + scroll_dist);

                    this->set_redraw(TPanel::RedrawNormal);
                    if (this->map_view != 0)
                        this->map_view->set_redraw(TPanel::RedrawNormal);
                    this->last_mouse_scroll_time = now;
                }
            }
        }

        if (vert_scroll == 0 && horz_scroll == 0)
            this->mouse_scrolling = 0;
        return this->mouse_scrolling;
    }

    this->mouse_scrolling = 0;
    return 0;
}

int RGE_Main_View::handle_keys() {
    unsigned char pbKeyState[256];
    short horz_scroll;
    short vert_scroll;
    float scroll_dist2;
    int changed;
    RGE_Prog_Info* info;
    unsigned long now;
    unsigned long elapsed;

    if (rge_base_game->get_paused() == 0 &&
        (rge_base_game->prog_mode == 4 || rge_base_game->prog_mode == 6 ||
         rge_base_game->prog_mode == 7 || rge_base_game->prog_mode == 5) &&
        GetForegroundWindow() == this->TPanel::render_area->Wnd &&
        this->have_focus != 0) {
        changed = 0;
        GetKeyboardState(pbKeyState);
        horz_scroll = 0;
        vert_scroll = 0;
        info = rge_base_game->prog_info;

        if (rge_base_game->game_mode == 0x12 &&
            this->player != 0 && this->player->selected_obj != 0) {
            RGE_Static_Object* obj = this->player->selected_obj;
            if (pbKeyState[0x26] > 1) {
                obj->teleport(obj->world_x + info->key_scroll_object_move, obj->world_y - info->key_scroll_object_move, 0);
                changed = 1;
            }
            if (pbKeyState[0x28] > 1) {
                RGE_Static_Object* obj2 = this->player->selected_obj;
                obj2->teleport(obj->world_x - info->key_scroll_object_move, obj->world_y + info->key_scroll_object_move, 0);
                changed = 1;
            }
            if (pbKeyState[0x25] > 1) {
                RGE_Static_Object* obj2 = this->player->selected_obj;
                obj2->teleport(obj->world_x - info->key_scroll_object_move, obj->world_y - info->key_scroll_object_move, 0);
                changed = 1;
            }
            if (pbKeyState[0x27] > 1) {
                RGE_Static_Object* obj2 = this->player->selected_obj;
                obj2->teleport(obj->world_x + info->key_scroll_object_move, obj->world_y + info->key_scroll_object_move, 0);
                changed = 1;
            }
        } else if (this->player != 0) {
            if (pbKeyState[0x25] > 1)
                horz_scroll = -1;
            else if (pbKeyState[0x27] > 1)
                horz_scroll = 1;

            if (pbKeyState[0x26] > 1)
                vert_scroll = -1;
            else if (pbKeyState[0x28] > 1)
                vert_scroll = 1;

            if (horz_scroll != 0 || vert_scroll != 0) {
                now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\vw_main.cpp", 339);
                elapsed = now - this->last_key_scroll_time;
                if (this->key_scrolling == 0) {
                    scroll_dist2 = DAT_00577900;
                    this->key_scrolling = 1;
                } else {
                    scroll_dist2 = (float)elapsed / info->key_scroll_interval;
                    long whole = (long)scroll_dist2;
                    scroll_dist2 -= (float)whole;
                    if (scroll_dist2 < DAT_00577904) {
                        scroll_dist2 = 0.0f;
                    } else {
                        scroll_dist2 = DAT_00577904;
                    }
                    scroll_dist2 += (float)whole;
                }
                if (scroll_dist2 > info->key_scroll_max_dist)
                    scroll_dist2 = info->key_scroll_max_dist;
                if (scroll_dist2 > DAT_00577908) {
                    float scroll_dist = scroll_dist2 + scroll_dist2;
                    if (horz_scroll == -1) {
                        this->player->set_view_loc(this->player->view_x - scroll_dist2,
                                                   this->player->view_y - scroll_dist2);
                    } else if (horz_scroll == 1) {
                        this->player->set_view_loc(this->player->view_x + scroll_dist2,
                                                   this->player->view_y + scroll_dist2);
                    }
                    if (vert_scroll == -1) {
                        this->player->set_view_loc(this->player->view_x + scroll_dist, this->player->view_y - scroll_dist);
                    } else if (vert_scroll == 1) {
                        this->player->set_view_loc(this->player->view_x - scroll_dist, this->player->view_y + scroll_dist);
                    }
                    this->last_key_scroll_time = now;
                    changed = 1;
                }
            }
        }

        if (horz_scroll == 0 && vert_scroll == 0)
            this->key_scrolling = 0;
        if (changed) {
            this->set_redraw(TPanel::RedrawNormal);
            if (this->map_view != 0)
                this->map_view->set_redraw(TPanel::RedrawNormal);
        }
        return changed;
    }

    this->key_scrolling = 0;
    return 0;
}

long RGE_Main_View::handle_mouse_up(unsigned char mouse_button_in, long x, long y, int ctrl_key, int shift_key) {
    unsigned long start;
    long result;
    unsigned long stop;

    start = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\vw_main.cpp", 430);
    result = RGE_View::handle_mouse_up(mouse_button_in, x, y, ctrl_key, shift_key);
    stop = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\vw_main.cpp", 432);
    rge_base_game->add_to_timing(0x0D, stop - start);
    return result;
}

long RGE_Main_View::mouse_move_action(long x, long y, int ctrl_key, int shift_key) {
    RGE_Base_Game* game = rge_base_game;
    int mode = game->prog_mode;
    if (mode == 4 || mode == 6 || mode == 7 || mode == 5) {
        mode = game->game_mode;
        if (mode == 1)
            goto call_redraw;
        if (mode <= 6)
            goto ret_one;
        if (mode > 8)
            goto ret_one;
    call_redraw:
        this->set_redraw(TPanel::RedrawNormal);
    ret_one:
        return 1;
    }
    return 0;
}

long RGE_Main_View::mouse_left_down_action(long x, long y, int ctrl_key, int shift_key) {
    short min_x;
    short min_y;
    short max_y;
    short max_x;
    tagPOINT point;
    RGE_Pick_Info pick_info;

    if (rge_base_game->get_paused() == 0) {
        int mode = rge_base_game->prog_mode;
        if (mode == 4 || mode == 6 || mode == 7 || mode == 5) {
            mode = rge_base_game->game_mode;
            color_log(0x4C, 0xBA, 1);

            switch (mode) {
            case 18:
                if (this->pick1(0x29, 0, x, y, &pick_info, this->player->selected_obj, 1) == 0x34) {
                    this->player->unselect_object();
                    this->player->select_one_object(pick_info.object, 1);
                    this->set_redraw(TPanel::RedrawNormal);
                    if (pick_info.object->sprite != 0) {
                        pick_info.object->get_frame(min_x, min_y, max_x, max_y);
                        point.x = pick_info.scr_x - min_x;
                        point.y = pick_info.scr_y - min_y;
                        if (this->TPanel::render_area->DrawSystem->ScreenMode == 1)
                            ClientToScreen(this->TPanel::render_area->Wnd, &point);
                        if (this->TPanel::render_area->DrawSystem->ScreenMode == 1)
                            ScreenToClient(this->TPanel::render_area->Wnd, &point);
                        this->start_scroll_view(4, point.x, point.y, ctrl_key, shift_key);
                    }
                }
                break;

            case 1:
                if (this->pick1(0x28, 0, x, y, &pick_info, 0, 1) == 0x33) {
                    this->fixup_pick_info(&pick_info);
                    int object_id = rge_base_game->master_obj_id;
                    if (object_id != -1 &&
                        this->player->master_objects[object_id] != 0) {
                        RGE_Master_Static_Object* master =
                            this->player->master_objects[object_id];
                        master->alignment(pick_info.x, pick_info.y, this->world, 0);
                        this->player->command_place_object((short)object_id, pick_info.x, pick_info.y, 0.0f);
                    } else if (object_id != -1 && this->world->players[0]
                               ->master_objects[object_id] != 0) {
                        RGE_Master_Static_Object* master =
                            this->world->players[0]->master_objects[object_id];
                        master->alignment(pick_info.x, pick_info.y, this->world, 0);
                        this->world->players[0]->command_place_object((short)object_id, pick_info.x, pick_info.y, 0.0f);
                    }
                }
                break;

            case 9:
            case 10:
            case 19:
                if (this->player->selected_obj != 0) {
                    this->player->unselect_object();
                    this->set_redraw(TPanel::RedrawNormal);
                }
                if (mode == 19)
                    rge_base_game->set_game_mode(19, 0);
                this->start_scroll_view(9, x, y, ctrl_key, shift_key);
                break;

            case 2:
            case 3:
            case 17:
                if (this->player->selected_obj != 0) {
                    this->player->unselect_object();
                    this->set_redraw(TPanel::RedrawNormal);
                }
                // These modes share the scroll command used by mode 21.
            case 21:
                this->start_scroll_view(3, x, y, ctrl_key, shift_key);
                break;

            case 15:
                if (this->pick1(0x29, 0, x, y, &pick_info, this->player->selected_obj, 1) == 0x34) {
                    if (pick_info.object->master_obj->object_group != 0x22) {
                        unsigned char draw_level;
                        if (pick_info.object->sprite_list != 0) {
                            draw_level = pick_info.object->sprite_list
                                             ->get_lowest_draw_level();
                        } else if (pick_info.object->sprite != 0) {
                            draw_level = pick_info.object->sprite
                                             ->get_lowest_draw_level();
                        } else {
                            draw_level = 0x14;
                        }

                        this->save_player = rge_base_game->get_player();
                        rge_base_game->set_player(pick_info.object->owner->id);
                        RGE_Base_Game* base_game = rge_base_game;
                        base_game->master_obj_id =
                            pick_info.object->master_obj->id;
                        this->movable_object = pick_info.object;
                        pick_info.object->object_state = 7;
                        if (draw_level == 0)
                            this->set_redraw(TPanel::RedrawImmediate);
                        rge_base_game->set_game_mode(8, 1);
                        if (this->movable_object->sprite != 0) {
                            this->movable_object->get_frame(min_x, min_y, max_x, max_y);
                            point.x = pick_info.scr_x - min_x;
                            point.y = pick_info.scr_y - min_y;
                            if (this->TPanel::render_area->DrawSystem
                                    ->ScreenMode == 1)
                                ClientToScreen(this->TPanel::render_area->Wnd, &point);
                        }
                        this->start_scroll_view(9, x, y, ctrl_key, shift_key);
                    }
                }
                break;

            default:
                this->capture_mouse();
                break;
            }

            color_log(0x4C, 0x5F, 1);
            return 1;
        }
    }
    return 0;
}

long RGE_Main_View::mouse_left_move_action(long x, long y, int ctrl_key, int shift_key) {
    int mode = rge_base_game->prog_mode;
    if (mode == 4 || mode == 6 || mode == 7 || mode == 5) {
        if (rge_base_game->get_paused()) {
            if (this->scroll_action)
                this->end_scroll_view();
            else
                this->release_mouse();
            return 0;
        }

        if (this->scroll_action) {
            this->handle_scroll_view(x, y);
            return 1;
        }

        switch (rge_base_game->game_mode) {
        case 0:
            this->release_mouse();
            this->start_scroll_view(2, this->mouse_down_x, this->mouse_down_y, ctrl_key, shift_key);
            this->handle_scroll_view(x, y);
            return 1;
        case 1:
        case 7:
        case 8:
            this->set_redraw(TPanel::RedrawNormal);
            break;
        }
        return 1;
    }
    return 0;
}

long RGE_Main_View::mouse_left_up_action(long x, long y, int ctrl_key, int shift_key) {
    RGE_Pick_Info pick_info;
    int mode = rge_base_game->prog_mode;

    if (mode != 4 && mode != 6 && mode != 7 && mode != 5)
        return 0;

    color_log(0x4C, 0x16, 1);

    if (this->scroll_action != 0) {
        this->end_scroll_view();

        if (rge_base_game->game_mode == 0x15) {
            int placement_mode = (ctrl_key == 0 && shift_key == 0) ? 1 : 0;
            this->command_place_multi_object(this->sel_col1, this->sel_row1, this->sel_col2, this->sel_row2, placement_mode);
        }

        if (rge_base_game->game_mode == 8) {
            this->command_place_object(x, y, 1);
            if (rge_base_game->sub_game_mode == 1) {
                this->movable_object->object_state = 2;
                this->movable_object = 0;
                rge_base_game->set_game_mode(0x0F, 0);
                if (this->save_player != 0) {
                    rge_base_game->set_player(this->save_player->id);
                    this->save_player = 0;
                }
            }
        }

        color_log(0x4C, 0x5F, 1);
        return 1;
    }

    this->release_mouse();
    if (rge_base_game->get_paused() != 0) {
        color_log(0x4C, 0x5F, 1);
        return 0;
    }

    mode = rge_base_game->game_mode;

    if ((ctrl_key != 0 || shift_key != 0) && mode != 7 && mode != 0x15) {
        if (this->pick1(0x29, 2, x, y, &pick_info, 0, 0) == 0x34) {
            RGE_Static_Object* object = pick_info.object;
            if ((object->selected & 1) != 0) {
                this->player->unselect_one_object(object);
            } else {
                RGE_Static_Object* selected = this->player->selected_obj;
                if (selected != 0 &&
                    (selected->owner != this->player ||
                     this->player->get_select_level() !=
                         object->master_obj->select_level)) {
                    this->player->unselect_object();
                }
                if (ctrl_key != 0)
                    this->player->select_one_object(object, 1);
                else
                    this->player->select_object(object);
            }
            this->set_redraw(TPanel::RedrawNormal);
        }

        if (ctrl_key != 0 || rge_base_game->prog_info->interface_style == 2) {
            color_log(0x4C, 0x5F, 1);
            return 1;
        }
    }

    switch (mode) {
    case 0:
    case 6: {
        if (mode == 6)
            rge_base_game->set_game_mode(0, 0);

        if (rge_base_game->prog_info->interface_style == 2) {
            RGE_Static_Object* exclude = 0;
            if (x == this->mouse_last_x && y == this->mouse_last_y)
                exclude = this->player->selected_obj;

            unsigned char status =
                this->pick1(0x29, 2, x, y, &pick_info, exclude, 0);
            this->mouse_last_x = -1;
            this->mouse_last_y = -1;

            if (status == 0x34) {
                RGE_Static_Object* object = pick_info.object;
                if ((object->selected & 1) != 0) {
                    if (this->player->sel_count < 2)
                        break;
                    this->player->unselect_object();
                    this->player->select_one_object(object, 1);
                } else {
                    this->player->unselect_object();
                    this->player->select_object(object);
                }
                this->set_redraw(TPanel::RedrawNormal);
                this->mouse_last_x = x;
                this->mouse_last_y = y;
            } else {
                this->player->unselect_object();
                this->set_redraw(TPanel::RedrawNormal);
            }
        } else {
            RGE_Static_Object* exclude = 0;
            if (x == this->mouse_last_x && y == this->mouse_last_y)
                exclude = this->player->selected_obj;

            unsigned char status =
                this->pick1(0x2A, 1, x, y, &pick_info, exclude, 1);
            if (status == 0x34) {
                if (x == this->mouse_last_x && y == this->mouse_last_y &&
                    pick_info.object != this->player->selected_obj) {
                    this->player->unselect_object();
                    this->set_redraw(TPanel::RedrawNormal);
                }
            }
            this->mouse_last_x = -1;
            this->mouse_last_y = -1;

            if (status == 0x34) {
                int prog_mode = rge_base_game->prog_mode;
                if (prog_mode != 5 && this->player->sel_count > 0 &&
                    prog_mode != 7 &&
                    this->command_make_do(x, y, 0, -1) != 0) {
                    return 1;
                }

                RGE_Static_Object* object = pick_info.object;
                if ((object->selected & 1) != 0) {
                    if (this->player->sel_count < 2)
                        return 1;
                    this->player->unselect_object();
                    this->player->select_one_object(object, 1);
                    this->set_redraw(TPanel::RedrawNormal);
                    this->mouse_last_x = x;
                    this->mouse_last_y = y;
                    return 1;
                }

                if (object->owner == this->player ||
                    this->player->sel_count == 0) {
                    if (object->master_obj->select_level >= 2 &&
                        (this->map->map_visible_flag != 0 ||
                         this->player->visible->get_visible((int)object->world_x, (int)object->world_y) == 0x0F)) {
                        this->player->unselect_object();
                        this->player->select_object(object);
                        this->set_redraw(TPanel::RedrawNormal);
                        this->mouse_last_x = x;
                        this->mouse_last_y = y;
                    }
                } else {
                    prog_mode = rge_base_game->prog_mode;
                    if (prog_mode != 5 && prog_mode != 7 &&
                        this->command_make_do(x, y, 1, -1) != 0) {
                        break;
                    }

                    if (object->master_obj->select_level >= 2 &&
                        (this->map->map_visible_flag != 0 ||
                         this->player->visible->get_visible((int)object->world_x, (int)object->world_y) == 0x0F)) {
                        this->player->unselect_object();
                        this->player->select_object(object);
                        this->set_redraw(TPanel::RedrawNormal);
                        this->mouse_last_x = x;
                        this->mouse_last_y = y;
                    }
                }
            }

            if (status == 0x33) {
                int prog_mode = rge_base_game->prog_mode;
                if (prog_mode != 5 && prog_mode != 7) {
                    if (shift_key == 0) {
                        this->command_make_do(x, y, 1, -1);
                    } else {
                        RGE_Static_Object** list;
                        short list_num;
                        if (this->player->get_selected_objects_to_command(&list, &list_num, -1, -1, -1, -1)) {
                            free(list);
                            if (allow_user_commands != 0) {
                                this->fixup_pick_info(&pick_info);
                                this->player->command_add_waypoint(pick_info.x, pick_info.y, 1.0f);
                                this->reset_display_object_selection(2);
                                this->add_overlay_sprite(rge_base_game->shapes[1], 0, this->map_scr_x_offset + x,
                                                         this->map_scr_y_offset + y, 0, 0x0F, 0, 1, 0xFA);
                                this->set_redraw(TPanel::RedrawNormal);
                            }
                        }
                    }
                }
            }
        }
        break;
    }

    case 4:
        this->command_make_move(x, y);
        break;

    case 5:
        this->command_make_work(x, y);
        break;

    case 7:
        this->command_place_object(x, y, (ctrl_key == 0 && shift_key == 0) ? 1 : 0);
        break;

    case 8:
        this->command_place_object(x, y, 1);
        if (rge_base_game->sub_game_mode == 1) {
            this->movable_object->object_state = 2;
            this->movable_object = 0;
            rge_base_game->set_game_mode(0x0F, 0);
            if (this->save_player != 0) {
                rge_base_game->set_player(this->save_player->id);
                this->save_player = 0;
            }
        }
        break;

    case 0x0E: {
        RGE_Static_Object* exclude = this->player->selected_obj;
        if (this->pick1(0x29, 0, x, y, &pick_info, exclude, 1) == 0x34) {
            RGE_Static_Object* object = pick_info.object;
            unsigned char draw_level;
            if (object->sprite_list != 0)
                draw_level = object->sprite_list->get_lowest_draw_level();
            else if (object->sprite != 0)
                draw_level = object->sprite->get_lowest_draw_level();
            else
                draw_level = 0x14;

            if (rge_base_game->prog_mode == 7) {
                if (object != 0)
                    delete object;
            } else {
                object->destroy_obj();
            }
            if (draw_level == 0)
                this->set_redraw(TPanel::RedrawImmediate);
        }
        break;
    }

    case 0x10:
        if (this->pick1(0x29, 1, x, y, &pick_info, this->player->selected_obj, 1) == 0x34) {
            if (this->curr_child != 0) {
                this->curr_child->action(this, 0x10, reinterpret_cast<unsigned long>(pick_info.object), 0);
                this->player->select_one_object(pick_info.object, 1);
                this->set_redraw(TPanel::RedrawNormal);
            }
            rge_base_game->set_game_mode(0, 0);
        }
        break;

    case 0x14:
        if (this->pick1(0x29, 2, x, y, &pick_info, this->player->selected_obj, 1) == 0x34)
            pick_info.object->rotate(1);
        break;
    }

    color_log(0x4C, 0x5F, 1);
    return 1;
}

long RGE_Main_View::mouse_right_down_action(long x, long y, int ctrl_key, int shift_key) {
    if (!rge_base_game->get_paused()) {
        int mode = rge_base_game->prog_mode;
        if (mode == 4 || mode == 6 || mode == 7 || mode == 5) {
            color_log(0x4C, 0x24, 1);
            if (rge_base_game->game_mode != 0x13) {
                this->capture_mouse();
            } else {
                if (this->player->selected_obj) {
                    this->player->unselect_object();
                    this->set_redraw(TPanel::RedrawNormal);
                }
                rge_base_game->set_game_mode(0x13, 1);
                this->start_scroll_view(9, x, y, ctrl_key, shift_key);
            }
            color_log(0x4C, 0x5F, 1);
            return 1;
        }
    }
    return 0;
}

long RGE_Main_View::mouse_right_move_action(long x, long y, int ctrl_key, int shift_key) {
    int mode = rge_base_game->prog_mode;
    if (mode != 4 && mode != 6 && mode != 7 && mode != 5)
        return 0;

    int paused = rge_base_game->get_paused();
    if (paused) {
        if (this->scroll_action) {
            this->end_scroll_view();
            return 0;
        }
        this->release_mouse();
        return 0;
    }

    if (this->scroll_action) {
        this->handle_scroll_view(x, y);
        return 1;
    }

    if (this->player->sel_count == 0) {
        this->release_mouse();
        this->start_scroll_view(1, this->mouse_down_x, this->mouse_down_y, ctrl_key, shift_key);
        this->handle_scroll_view(x, y);
        return 1;
    }
    return 0;
}

long RGE_Main_View::mouse_right_up_action(long x, long y, int ctrl_key, int shift_key) {
    RGE_Pick_Info pick_info;
    int mode = rge_base_game->prog_mode;

    if (mode == 4 || mode == 6 || mode == 7 || mode == 5) {
        color_log(0x4C, 0x32, 1);

        if (this->scroll_action != 0) {
            this->end_scroll_view();
        } else {
            this->release_mouse();

            if (rge_base_game->game_mode == 0x14) {
                if (this->pick1(0x29, 2, x, y, &pick_info, this->player->selected_obj, 1) == 0x34)
                    pick_info.object->rotate(-1);
            } else {
                if (rge_base_game->get_paused() != 0) {
                    color_log(0x4C, 0x5F, 1);
                    return 0;
                }
                if (this->mouse_action != 1 && this->mouse_action != 2) {
                    color_log(0x4C, 0x5F, 1);
                    return 0;
                }

                if (rge_base_game->prog_info->interface_style == 2) {
                    if (rge_base_game->prog_mode != 5 &&
                        rge_base_game->prog_mode != 7) {
                        if (rge_base_game->game_mode == 0) {
                            if (shift_key == 0) {
                                this->command_make_do(x, y, 1, -1);
                            } else {
                                RGE_Static_Object** list;
                                short list_num;
                                if (this->player->get_selected_objects_to_command(&list, &list_num, -1, -1, -1, -1)) {
                                    free(list);
                                    if (allow_user_commands != 0) {
                                        if (this->pick1(0x28, 0, x, y, &pick_info, 0, 1) == 0x33) {
                                            this->fixup_pick_info(&pick_info);
                                            this->player->command_add_waypoint(pick_info.x, pick_info.y, 1.0f);
                                            this->reset_display_object_selection(2);
                                            this->add_overlay_sprite(rge_base_game->shapes[1], 0,
                                                                     this->map_scr_x_offset + x, this->map_scr_y_offset + y,
                                                                     0, 0x0F, 0, 1, 0xFA);
                                            this->set_redraw(TPanel::RedrawNormal);
                                        }
                                    }
                                }
                            }
                        } else {
                            if (rge_base_game->game_mode == 0x15) {
                                this->set_selection_area(-1, -1, -1, -1);
                                this->set_redraw(TPanel::RedrawNormal);
                            }
                            rge_base_game->set_game_mode(0, 0);
                        }
                    }
                } else if (rge_base_game->prog_mode != 7) {
                    if (rge_base_game->game_mode != 0) {
                        rge_base_game->set_game_mode(0, 0);
                    } else {
                        this->player->unselect_object();
                        this->set_redraw(TPanel::RedrawNormal);
                    }
                }
            }
        }

        color_log(0x4C, 0x5F, 1);
        return 1;
    }
    return 0;
}

int RGE_Main_View::start_scroll_view(unsigned char scroll_action_in, long x, long y, int ctrl_key, int shift_key) {
    if (this->RGE_View::start_scroll_view(scroll_action_in, x, y, ctrl_key, shift_key) != 0) {
        if (this->map_view != 0)
            this->map_view->set_redraw(TPanel::RedrawNormal);
        return 1;
    }
    return 0;
}

int RGE_Main_View::handle_scroll_view(long x, long y) {
    int result = this->RGE_View::handle_scroll_view(x, y);
    if (result != 0) {
        if (this->map_view != 0)
            this->map_view->set_redraw(TPanel::RedrawNormal);
        return 1;
    }
    return 0;
}

void RGE_Main_View::draw() {
    unsigned long start;
    unsigned long at;
    unsigned long et;
    unsigned long ac2;

    start = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\vw_main.cpp", 1314);
    at = rge_base_game->get_accum_time(0xB);

    if (world != 0 && player != 0) {
        if (do_draw_log != 0)
            write_draw_log2("<vs>");
        color_log(0x4C, 0x4C, 1);
        RGE_View::draw();
        color_log(0x4C, 0x5F, 1);
        if (do_draw_log != 0)
            write_draw_log2("<vf>\n");
    } else {
        draw_setup(0);
        this->TPanel::render_area->Clear(&this->TPanel::clip_rect, this->TPanel::color);
        draw_finish();
    }

    ac2 = rge_base_game->get_accum_time(0xB);
    ac2 -= at;
    et = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\vw_main.cpp", 1346);
    rge_base_game->add_to_timing(6, (et - start) - ac2);
    rge_base_game->increment_view_update_count();
    rge_base_game->add_to_timing(0xC, ac2);
}

void RGE_Main_View::draw_multi_object_outline() {}

int RGE_Main_View::command_place_object(long x, long y, int reset_mode) {
    int object_id;
    RGE_Master_Static_Object* master_obj;
    RGE_Pick_Info pick_info;
    RGE_Static_Object* object;
    int check;
    int alignment_flag;

    if (allow_user_commands != 0) {
        if (this->pick1(0x28, 0, x, y, &pick_info, 0, 1) == 0x33) {
            this->fixup_pick_info(&pick_info);
            object_id = rge_base_game->master_obj_id;
            if (object_id != -1 &&
                rge_base_game->get_player()->master_objects[object_id] != 0) {
                master_obj =
                    rge_base_game->get_player()->master_objects[object_id];
                alignment_flag = 1;
                if (rge_base_game->sub_game_mode == 3)
                    alignment_flag = 0;
                master_obj->alignment(pick_info.x, pick_info.y, this->world, alignment_flag);
                check = master_obj->check_placement(rge_base_game->get_player(), pick_info.x, pick_info.y, 0,
                                                    1, master_obj->elevation_flag, 0, 1, 1, 1);
                if (check == 0) {
                    if (rge_base_game->game_mode == 1) {
                        if (rge_base_game->get_player()->command_place_object((short)object_id, pick_info.x, pick_info.y,
                                                                              0.0f) != 0) {
                            if (reset_mode != 0)
                                rge_base_game->set_game_mode(0, 0);
                            return 1;
                        }
                    } else if (rge_base_game->game_mode == 8) {
                        if (rge_base_game->sub_game_mode == 1) {
                            object = this->movable_object;
                            object->teleport(pick_info.x, pick_info.y, 0.0f);
                        } else {
                            object = rge_base_game->get_player()->make_new_object(object_id, pick_info.x, pick_info.y, 0.0f, 1);
                        }
                        if (object != 0) {
                            unsigned char draw_level;
                            if (object->sprite_list != 0)
                                draw_level = object->sprite_list
                                                 ->get_lowest_draw_level();
                            else if (object->sprite != 0)
                                draw_level = object->sprite
                                                 ->get_lowest_draw_level();
                            else
                                draw_level = 0x14;
                            if (draw_level == 0)
                                this->set_redraw(TPanel::RedrawImmediate);
                            else
                                this->set_redraw(TPanel::RedrawNormal);
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int RGE_Main_View::command_make_do(long x, long y, int work_on_tile, short action_type) {
    RGE_Static_Object** list;
    short list_num;
    int attacking;
    RGE_Pick_Info pick_info;
    int result;

    if (allow_user_commands != 0) {
        if (this->player->get_selected_objects_to_command(&list, &list_num, -1, -1, -1, -1)) {
            free(list);
            color_log(0x4C, 0xBA, 2);

            RGE_Static_Object* target =
                this->pick_best_target(x, y, &attacking, action_type);
            if (target != 0) {
                result = this->player->command_make_do(target, target->world_x, target->world_y);
                if (result != 0)
                    this->display_object_selection(target->id, 0x5DC, 2, 2);
                this->reset_overlay_sprites();
                this->set_redraw(TPanel::RedrawNormal);
                color_log(0x4C, 0x5F, 2);
                return result;
            }

            if (work_on_tile != 0) {
                if (this->pick1(0x28, 0, x, y, &pick_info, 0, 1) == 0x33) {
                    this->fixup_pick_info(&pick_info);
                    result = this->player->command_make_move(0, pick_info.x, pick_info.y);
                    if (result != 0) {
                        this->reset_display_object_selection(2);
                        this->add_overlay_sprite(rge_base_game->shapes[2], 0, this->map_scr_x_offset + x,
                                                 this->map_scr_y_offset + y, 0, 0x0F, 0, 2, 0x5A);
                        this->set_redraw(TPanel::RedrawNormal);
                    }
                    color_log(0x4C, 0x5F, 2);
                    return result;
                }
            }

            this->reset_overlay_sprites();
            this->set_redraw(TPanel::RedrawNormal);
            color_log(0x4C, 0x5F, 2);
        }
    }
    return 0;
}

unsigned char RGE_Main_View::pick1(unsigned char pick_mode_in,
                                   unsigned char select_level, long x, long y,
                                   RGE_Pick_Info* pick_info,
                                   RGE_Static_Object* last_picked_object,
                                   int pick_dopples) {
    if (pick_mode_in != 0x29) {
        if (pick_mode_in == 0x2A &&
            this->pick1(0x29, select_level, x, y, pick_info, last_picked_object, 1) ==
                0x34)
            return 0x34;
        return this->RGE_View::pick(0x28, select_level, x, y, pick_info, last_picked_object);
    }

    pick_info->x = 0.0f;
    pick_info->y = 0.0f;
    pick_info->scr_x = 0;
    pick_info->scr_y = 0;
    pick_info->object = 0;
    pick_info->tile = 0;

    int target_count;
    if (select_level == 0)
        target_count = this->pick_objects(x, y, 0, 40, 15, 4, 1);
    else
        target_count = this->pick_objects(x, y, 10, 20, 15, 4, 1);

    if (target_count == 0)
        return 0x32;

    RGE_Static_Object* picked_obj = 0;
    short scr_x = 0;
    short scr_y = 0;

    if (last_picked_object == 0) {
        int best_weight = 0;
        RGE_Pick_Obj_Info* info = Picked_Objects;

        for (int i = 0; i < target_count; i++, info++) {
            if (info->object_id < 0)
                continue;

            RGE_Static_Object* object =
                this->world->objectsValue[info->object_id];
            if (object == 0 || object->object_state >= 7 ||
                object->master_obj->select_level < select_level)
                continue;

            if (pick_dopples == 0 && this->map->map_visible_flag == 0 &&
                this->pick_through_fog(object) == 0 &&
                this->player->visible->get_visible((int)object->world_x, (int)object->world_y) != 0x0F)
                continue;

            int weight = this->pick_weight(object, info->confidence);
            if (weight > best_weight) {
                picked_obj = object;
                scr_x = (short)this->render_rect.left + info->draw_x;
                scr_y = (short)this->render_rect.top + info->draw_y;
                best_weight = weight;
            }
        }
    } else {
        int found_last = 0;
        int i = 0;
        RGE_Pick_Obj_Info* info = Picked_Objects;

        for (; i < target_count; i++, info++) {
            if (info->object_id < 0)
                continue;

            RGE_Static_Object* object =
                this->world->objectsValue[info->object_id];
            if (object == 0 || object->object_state >= 7 ||
                object->master_obj->select_level < select_level ||
                this->pick_weight(object, info->confidence) <= 0)
                continue;

            if (pick_dopples == 0 && this->map->map_visible_flag == 0 &&
                this->pick_through_fog(object) == 0 &&
                this->player->visible->get_visible((int)object->world_x, (int)object->world_y) != 0x0F)
                continue;

            if (object == last_picked_object) {
                found_last = 1;
                continue;
            }

            if (found_last != 0) {
                picked_obj = object;
                scr_x = (short)this->render_rect.left + info->draw_x;
                scr_y = (short)this->render_rect.top + info->draw_y;
                break;
            }

            if (picked_obj == 0) {
                picked_obj = object;
                scr_x = (short)this->render_rect.left + info->draw_x;
                scr_y = (short)this->render_rect.top + info->draw_y;
            }
        }

        if (found_last != 0 && picked_obj == 0) {
            picked_obj = last_picked_object;
            scr_x = (short)this->render_rect.left + Picked_Objects[i].draw_x;
            scr_y = (short)this->render_rect.top + Picked_Objects[i].draw_y;
        }
    }

    if (picked_obj == 0)
        return 0x32;

    pick_info->object = picked_obj;
    pick_info->scr_x = scr_x;
    pick_info->scr_y = scr_y;
    pick_info->x = picked_obj->world_x;
    pick_info->y = picked_obj->world_y;
    return 0x34;
}

int RGE_Main_View::pick_objects1(long x, long y, RGE_Static_Object** object_list, int max_objects) {
    RGE_Static_Object* previous;
    int count;
    RGE_Static_Object** output;
    RGE_Pick_Info pick_info;

    output = object_list;
    previous = 0;
    count = 0;
    while (true) {
        if (count == max_objects)
            return count;
        if (this->pick(0x29, 0, x, y, &pick_info, previous) != 0x34)
            break;
        if (count > 0 && pick_info.object == *object_list)
            return count;
        *output = pick_info.object;
        count = count + 1;
        output = output + 1;
        previous = pick_info.object;
    }
    return count;
}

RGE_Static_Object* RGE_Main_View::pick_best_target(long x, long y, int* attacking_in, short action_type) {
    // task ownership is RGE_Master_Action_Object, not its static
    // base. Its named tasks and task_by_group fields are used below.
    short selected_count;
    RGE_Static_Object** selected_objects;
    int j;
    int target_count;
    int picked_count;
    RGE_Master_Action_Object* master_obj;
    RGE_Pick_Obj_Info* info;
    RGE_Pick_Obj_Info* info2;
    int valid_target_count[64];
    int attacking[64];

    if (attacking_in != 0)
        *attacking_in = 0;

    picked_count = this->pick_objects(x, y, 10, 20, 15, 4, 1);
    if (picked_count == 0)
        return 0;

    if (!this->player->get_selected_objects_to_command(&selected_objects, &selected_count, -1, -1, -1, -1))
        return 0;

    if (picked_count > 0) {
        for (target_count = 0; target_count != picked_count; target_count++)
            attacking[target_count] = 0;
        for (target_count = 0; target_count != picked_count; target_count++)
            valid_target_count[target_count] = 0;
    }

    j = 0;
    if (selected_count > 0) {
        do {
            target_count = 0;
            master_obj = static_cast<RGE_Master_Action_Object*>(selected_objects[j]->master_obj);
            if (picked_count > 0) {
                info = Picked_Objects;
                do {
                    int picked = info->object_id;
                    if (picked >= 0) {
                        RGE_Static_Object* object =
                            this->world->objectsValue[picked];
                        if (object != 0 && object->object_state < 7) {
                            RGE_Task* action = master_obj->tasks->get_target_task(
                                static_cast<RGE_Action_Object*>(selected_objects[j]), object, 0, 0, 0);
                            if (action != 0) {
                                if (action_type != -1 &&
                                    action->action_type != action_type)
                                    action = 0;
                                if (action != 0) {
                                    valid_target_count[target_count] +=
                                        this->pick_weight(object, info->confidence);
                                    if (master_obj->tasks->is_attack_task(action))
                                        attacking[target_count] = 1;
                                    goto next_target;
                                }
                            }
                            if (master_obj->task_by_group != 0) {
                                int k = 0;
                                while (k < this->player->master_object_num) {
                                    RGE_Master_Action_Object* object2 =
                                        static_cast<RGE_Master_Action_Object*>(this->player->master_objects[k]);
                                    if (object2 != 0 &&
                                        object2->object_group ==
                                            master_obj->object_group &&
                                        object2->master_type == master_obj->master_type &&
                                        object2->task_by_group == master_obj->task_by_group) {
                                        RGE_Task* action2 =
                                            object2->tasks->get_target_task(static_cast<RGE_Action_Object*>(
                                                    selected_objects[j]), object, 0, 0, 0);
                                        if (action2 != 0) {
                                            if (action_type != -1 &&
                                                action2->action_type !=
                                                    action_type)
                                                action2 = 0;
                                            if (action2 != 0) {
                                                valid_target_count[target_count] +=
                                                    this->pick_weight(object, info->confidence);
                                                if (object2->tasks->is_attack_task(action2))
                                                    attacking[target_count] = 1;
                                                goto next_target;
                                            }
                                        }
                                    }
                                    k++;
                                }
                            }
                        }
                    }
                next_target:
                    target_count++;
                    info++;
                } while (target_count < picked_count);
            }
            j++;
        } while (j < selected_count);
    }

    free(selected_objects);

    int best = 0;
    RGE_Static_Object* best_object = 0;
    int i = 0;
    if (picked_count > 0) {
        info2 = Picked_Objects;
        do {
            int score = valid_target_count[i];
            if (score > best) {
                int picked = info2->object_id;
                best_object = this->world->objectsValue[picked];
                if (attacking_in != 0)
                    *attacking_in = attacking[i];
                best = score;
            }
            i++;
            info2++;
        } while (i < picked_count);
    }
    return best_object;
}

int RGE_Main_View::command_make_move(long x, long y) {
    RGE_Static_Object** list;
    short list_num;
    RGE_Pick_Info pick_info;
    int result;

    if (allow_user_commands != 0) {
        if (this->player->get_selected_objects_to_command(&list, &list_num, -1, -1, -1, -1)) {
            free(list);
            result = 0;
            if (this->pick1(0x2A, 1, x, y, &pick_info, 0, 1) != 0x32) {
                this->fixup_pick_info(&pick_info);
                result = this->player->command_make_move(pick_info.object, pick_info.x, pick_info.y);
                this->set_redraw(TPanel::RedrawNormal);
            }
            rge_base_game->set_game_mode(0, 0);
            return result;
        }
    }
    return 0;
}

int RGE_Main_View::command_make_work(long x, long y) {
    RGE_Static_Object** list;
    short list_num;
    int attacking;
    RGE_Pick_Info pick_info;
    RGE_Static_Object* target;
    int result;

    if (allow_user_commands != 0) {
        if (this->player->get_selected_objects_to_command(&list, &list_num, -1, -1, -1, -1)) {
            free(list);
            target = this->pick_best_target(x, y, &attacking, -1);
            if (target != 0) {
                result = this->player->command_make_work(target, target->world_x, target->world_y);
                if (result != 0)
                    this->display_object_selection(target->id, 0x5DC, 2, 2);
                this->reset_overlay_sprites();
                this->set_redraw(TPanel::RedrawNormal);
                rge_base_game->set_game_mode(0, 0);
                return result;
            }

            if (this->pick1(0x28, 0, x, y, &pick_info, 0, 1) == 0x33) {
                this->fixup_pick_info(&pick_info);
                result = this->player->command_make_work(0, pick_info.x, pick_info.y);
                if (result != 0) {
                    this->reset_display_object_selection(2);
                    this->add_overlay_sprite(rge_base_game->shapes[2], 0, this->map_scr_x_offset + x,
                                             this->map_scr_y_offset + y, 0, 0x0F, 0, 2, 0x5A);
                }
                this->set_redraw(TPanel::RedrawNormal);
                rge_base_game->set_game_mode(0, 0);
                return result;
            }

            this->reset_overlay_sprites();
            this->set_redraw(TPanel::RedrawNormal);
            rge_base_game->set_game_mode(0, 0);
        }
    }
    return 0;
}

int RGE_Main_View::command_place_multi_object(long x1, long y1, long x2, long y2, int reset_mode) {
    this->set_selection_area(-1, -1, -1, -1);
    this->set_redraw(TPanel::RedrawNormal);
    return 0;
}

unsigned char RGE_Main_View::get_help_info(char*& string, long& page, long x, long y) {
    RGE_Pick_Info pick_info;
    unsigned char result = this->pick1(0x29, 2, x, y, &pick_info, 0, 1);

    if (result == 0x34) {
        int message = pick_info.object->master_obj->get_help_message();
        char* text = this->TPanel::get_string(message);
        strcpy(string, text);
        page = pick_info.object->master_obj->get_help_page();
        return 1;
    }
    return TPanel::get_help_info(string, page, x, y);
}

void RGE_Main_View::fixup_pick_info(RGE_Pick_Info* pick_info) {
    if (pick_info->x < 0.0f) {
        pick_info->x = 0.0f;
    } else {
        float max_x = (float)this->map->map_width;
        if (pick_info->x >= max_x)
            pick_info->x = max_x - 1.0f;
    }
    if (pick_info->y < 0.0f) {
        pick_info->y = 0.0f;
        return;
    } else {
        float max_y = (float)this->map->map_height;
        if (pick_info->y >= max_y)
            pick_info->y = max_y - 1.0f;
    }
}

void RGE_Main_View::reset_display_object_selection(int reset_type) {
    // the list is a typed 20-byte record array at the view tail.
    int count = 0;
    if (this->DispSel_List_Max > 0) {
        do {
            DisplaySelectedObjRec* fields = &this->DispSel_List[count];
            if (fields->active == 1 && fields->select_type == reset_type)
                fields->start_time = fields->start_time - fields->duration;
            count = count + 1;
        } while (count < this->DispSel_List_Max);
    }
}
