// PDB source module: C:/msdev/work/age1_x1/tpnl_obj.cpp.
// Definitions follow the original PDB source order.

#include "../include/tpnl_obj.h"
#include <new.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The executable uses three unnamed format strings from the original data segment.
static const char* const format_id_name = (const char*)0x0058B690;
static const char* const format_name = (const char*)0x0057F324;
static const char* const format_hp = (const char*)0x005870AC;

// 0051ADF0 TRIBE_Panel_Object (tpnl_obj.cpp:49-116)
TRIBE_Panel_Object::TRIBE_Panel_Object(
    TDrawArea* draw_area, TPanel* parent, void* font_, long font_wid_,
    long font_hgt_, TShape* unit_pics_, TShape** bldg_pics_,
    TRIBE_Player* player_)
    : TPanel()
{
    this->font = font_;
    this->font_wid = font_wid_;
    this->font_hgt = font_hgt_;
    this->health_pic = 0;
    this->item_pic = 0;
    this->unit_pics = unit_pics_;
    this->bldg_pics = bldg_pics_;
    this->player = 0;
    this->game_obj = 0;
    this->idle_time = 0;
    this->idle_interval = 500;
    this->mode = 1;
    this->save_obj_type = 0;
    this->save_attr_type = -1;
    this->save_attr_amount = 0.0f;
    this->save_object_state = 0;
    this->save_build_pts = 0.0f;
    this->save_list = 0;
    this->save_hp = 0.0f;
    this->save_armor = 0;
    this->save_pierce_armor = 0;
    this->save_weapon = 0;
    this->save_weapon_range = 0.0f;
    this->save_speed_of_attack = 0.0f;
    this->save_work_type = 0;
    this->save_work_target = 0;
    this->save_progress = 0;
    this->save_name[0] = 0;
    this->save_facet = 0;
    this->save_angle = 0.0f;
    this->save_los = 0.0f;
    this->save_pop = 0;
    this->save_max_pop = 0;
    this->save_selected_group = 0;
    this->save_owner = 0;
    this->save_have_action = 0;
    this->save_farm_amt = 0;

    for (int i = 0; i < 9; ++i)
        this->save_score[i] = 0;

    if (this->setup(draw_area, parent, 0, 0, 0, 0, 0) == 0) {
        this->error_code = 1;
        return;
    }

    this->set_player(player_);

    this->health_pic = new TShape((char*)s_health_shp, 0xC639);
    if (this->health_pic != 0 && this->health_pic->is_loaded() == 0) {
        if (this->health_pic != 0)
            delete this->health_pic;
        this->health_pic = 0;
    }

    this->item_pic = new TShape((char*)s_itemicon_shp, 0xC62B);
    if (this->item_pic != 0 && this->item_pic->is_loaded() == 0) {
        if (this->item_pic != 0)
            delete this->item_pic;
        this->item_pic = 0;
    }
}

// 0051B070 ~TRIBE_Panel_Object (tpnl_obj.cpp:122-134)
TRIBE_Panel_Object::~TRIBE_Panel_Object()
{
    if (this->health_pic != 0) {
        delete this->health_pic;
        this->health_pic = 0;
    }

    if (this->item_pic != 0) {
        delete this->item_pic;
        this->item_pic = 0;
    }
}

// 0051B110 set_player (tpnl_obj.cpp:140-146)
void TRIBE_Panel_Object::set_player(TRIBE_Player* player) {
    this->player = player;
    if (player != 0) {
        set_object(player->object_130);
        return;
    }
    set_object(0);
}

// 0051B140 set_object (tpnl_obj.cpp:152-167)
void TRIBE_Panel_Object::set_object(RGE_Static_Object* object) {
    this->game_obj = (TRIBE_Building_Object*)object;
    save_object_info();
    this->set_redraw(1);
}

// 0051B160 set_mode (tpnl_obj.cpp:175-179)
void TRIBE_Panel_Object::set_mode(unsigned char mode) {
    this->mode = mode;
    save_object_info();
    this->set_redraw(1);
}

// 0051B180 get_mode (tpnl_obj.cpp:185-187)
unsigned char TRIBE_Panel_Object::get_mode() {
    return this->mode;
}

// 0051B190 draw (tpnl_obj.cpp:193-735)
void TRIBE_Panel_Object::draw()
{
    short cur_val;
    short orig_val;
    float dx;
    short work_type;
    TRIBE_Building_Object* bldg_obj;
    float cur_fval;
    short progress;
    short work_target;
    float orig_fval;
    short temp;
    char name[100];
    char str[100];
    char work_name[100];

    if (this->render_area == 0 || this->visible == 0 || this->active == 0) {
        this->need_redraw = 0;
        return;
    }

    if (this->mode == 2) {
        this->draw_score();
        return;
    }

    if (this->game_obj == 0) {
        if (this->parent_panel != 0)
            this->parent_panel->draw_rect(&this->clip_rect);
        this->need_redraw = 0;
        return;
    }

    this->draw_setup(0);
    this->render_area->Clear(&this->clip_rect, 0);

    if (this->render_area->Lock((char*)s_tpnl_obj_draw, 1) != 0) {
        short shape = this->game_obj->master_obj->button_pict;
        if (shape != -1) {
            TShape* picture;
            if (this->game_obj->master_obj->unit_level == 2) {
                unsigned char culture = this->game_obj->culture;
                shape += this->game_obj->master_obj->building_facet;
                picture = this->bldg_pics[culture];
            } else {
                picture = this->unit_pics;
            }

            if (this->game_obj->owner->color_table != 0) {
                _ASMSet_Color_Xform(
                    (this->game_obj->owner->color_table->id + 1) * 0x10);

                picture->shape_draw(
                    this->render_area,
                    this->pnl_x + 3,
                    this->pnl_y + 0x1e,
                    shape,
                    1,
                    this->game_obj->owner->color_table->table);
            } else {
                picture->shape_draw(
                    this->render_area,
                    this->pnl_x + 3,
                    this->pnl_y + 0x1e,
                    shape,
                    0,
                    0);
            }
        }

        if (this->game_obj->hp > DAT_00576d80 && this->health_pic != 0) {
            float count = (float)this->health_pic->shape_count();
            short frame = (short)(
                count - (float)this->health_pic->shape_count() * this->game_obj->hp /
                              (float)this->game_obj->master_obj->hp);
            if (frame < 0) {
                frame = 0;
            } else if (this->health_pic->shape_count() - 1 < frame) {
                frame = (short)this->health_pic->shape_count() - 1;
            }

            this->health_pic->shape_draw(
                this->render_area,
                this->pnl_x + 3,
                this->pnl_y + 0x54,
                frame,
                0,
                0);
        }

        this->render_area->Unlock((char*)s_tpnl_obj_draw);
    }

    if (this->render_area->GetDc((char*)s_tpnl_obj_draw) != 0) {
        HDC dc = this->render_area->DrawDc;
        SetBkMode(dc, 1);
        SetTextColor(dc, 0x00ffffff);
        SelectClipRgn(dc, (HRGN)this->clip_rgn);
        HGDIOBJ old_font = SelectObject(dc, (HGDIOBJ)this->font);

        if (this->game_obj->owner->id != 0) {
            if (rge_base_game->campaignGame() == 0) {
                name[0] = 0;
            } else {
                strcpy(name, this->game_obj->owner->world->scenario->GetPlayerName(
                    this->game_obj->owner->id - 1));
            }

            if (name[0] == 0) {
                rge_base_game->get_string2(
                    0x69,
                    this->game_obj->owner->master_player_id,
                    0,
                    name,
                    100);
            }

            TextOutA(dc, this->pnl_x + 3, this->pnl_y - 2,
                     name, (int)strlen(name));
        }

        if (this->game_obj->master_obj->string_id < 1) {
            str[0] = 0;
        } else {
            rge_base_game->get_string(
                this->game_obj->master_obj->string_id, str, 100);
        }

        if (str[0] == 0)
            strcpy(str, this->game_obj->master_obj->name);

        if (rge_base_game->object_name_mode != 0)
            sprintf(name, format_id_name, this->game_obj->id, str);
        else
            sprintf(name, format_name, str);

        TextOutA(dc, this->pnl_x + 3, this->pnl_y + 0x0d,
                 name, (int)strlen(name));

        if (this->game_obj->hp > DAT_00576d80) {
            sprintf(str, format_hp,
                    (int)this->game_obj->hp,
                    (int)this->game_obj->master_obj->hp);
            TextOutA(dc, this->pnl_x + 3, this->pnl_y + 0x5c,
                     str, (int)strlen(str));
        }

        SelectObject(dc, old_font);
        SelectClipRgn(dc, 0);
        this->render_area->ReleaseDc((char*)s_tpnl_obj_draw);
    }

    int row = 0;
    unsigned char level = this->game_obj->master_obj->unit_level;

    if (level == 3 || level == 4 || level == 5 || level == 6 ||
        level == 7 || level == 9) {
        if (level == 3 || level == 4) {
            this->game_obj->get_weapon(cur_val, orig_val);
            this->draw_item(0, 7, ValueTypeBonus, orig_val, cur_val);
            row = 1;
        }

        this->game_obj->get_armor(cur_val, orig_val);
        if (cur_val > 0) {
            this->draw_item(row, 8, ValueTypeBonus, orig_val, cur_val);
            ++row;
        }

        this->game_obj->get_pierce_armor(cur_val, orig_val);
        if (cur_val > 0) {
            this->draw_item(row, 10, ValueTypeBonus, orig_val, cur_val);
            ++row;
        }

        if (level == 4 || level == 6) {
            this->game_obj->get_weapon_range(cur_fval, orig_fval);
            if (cur_fval > DAT_00576dac) {
                this->draw_item(row, 6, ValueTypeBonus,
                                (int)orig_fval, (int)cur_fval);
                ++row;
            }
        }

        if (level == 6) {
            this->draw_item(row, 9, ValueTypePercent,
                            (int)(this->game_obj->attribute_amount_held -
                                  DAT_00576d84), 0);
            ++row;
        }

        if (this->game_obj->owner != this->player) {
            goto finish;
        }

        if (level == 7) {
            this->draw_item(
                row, 4, ValueTypeCompare,
                this->game_obj->objects->number_of_objects,
                this->game_obj->master_obj->obj_max);
            this->draw_finish();
            return;
        }

        if (level == 9) {
            if (this->game_obj->attribute_type_held == 0x11 ||
                this->game_obj->attribute_type_held == 0)
                cur_val = (short)(int)(this->game_obj->attribute_amount_held -
                                       DAT_00576d84);
            else
                cur_val = 0;
            this->draw_item(row, 2, ValueTypeNumber, cur_val, 0);
            this->draw_finish();
            return;
        }

        if (level == 5) {
            int item_type;
            switch (this->game_obj->attribute_type_held) {
            case 0:
            case 0x0f:
            case 0x10:
            case 0x11:
                item_type = 2;
                break;
            case 1:
                item_type = 0;
                break;
            case 2:
                item_type = 1;
                break;
            case 3:
                item_type = 3;
                break;
            case 9:
                item_type = 5;
                break;
            default:
                goto invalid_item;
            }

            if ((int)(this->game_obj->attribute_amount_held - DAT_00576d84) > 0) {
                this->draw_item(row, 3, ValueTypeNumber,
                                (int)(this->game_obj->attribute_amount_held -
                                      DAT_00576d84), 0);
            } else {
                this->draw_item(row, item_type, ValueTypeNone, -1, 0);
            }
            this->draw_finish();
            return;
        }

        if ((int)this->game_obj->attribute_amount_held < 1) {
            goto finish;
        }

        int item_type;
        switch (this->game_obj->attribute_type_held) {
        case 0:
        case 0x0f:
        case 0x10:
        case 0x11:
            item_type = 2;
            break;
        case 1:
            item_type = 0;
            break;
        case 2:
            item_type = 1;
            break;
        case 3:
            item_type = 3;
            break;
        case 9:
            item_type = 5;
            break;
        default:
            goto invalid_item;
        }
        this->draw_item(row, item_type, ValueTypeNumber,
                        (int)(this->game_obj->attribute_amount_held -
                              DAT_00576d84), 0);
        goto finish;
    }

    if (level == 1) {
        int item_type;
        switch (this->game_obj->attribute_type_held) {
        case 0:
        case 0x0f:
        case 0x10:
        case 0x11:
            item_type = 2;
            break;
        case 1:
            item_type = 0;
            break;
        case 2:
            item_type = 1;
            break;
        case 3:
            item_type = 3;
            break;
        case 9:
            item_type = 5;
            break;
        default:
            goto invalid_item;
        }
        this->draw_item(
            0, item_type, ValueTypeNumber,
            (int)(this->game_obj->attribute_amount_held - DAT_00576d84),
            0);
        this->draw_finish();
        return;
    }

    if (level == 2 || level == 8) {
        bldg_obj = this->game_obj;
        if (this->game_obj->master_obj->master_type == 'P') {
            bldg_obj->work_status(
                work_type, work_target, progress, work_name, 100);

            if (work_type != 0x67 && work_type != 0x66 &&
                bldg_obj->production_queue_status(work_target, temp) != 0) {
                work_type = 0x66;
                progress = temp;
            }

            if (this->game_obj->object_state != 0 &&
                (this->game_obj->owner != this->player ||
                 (work_type != 0x67 && work_type != 0x66))) {
                bldg_obj->get_weapon(cur_val, orig_val);
                if (cur_val > 0) {
                    this->draw_item(0, 7, ValueTypeBonus, orig_val, cur_val);
                    row = 1;
                }
                bldg_obj->get_weapon_range(cur_fval, orig_fval);
                if ((int)cur_fval > 0) {
                    this->draw_item(row, 6, ValueTypeBonus,
                                    (int)orig_fval, (int)cur_fval);
                    ++row;
                }
            }

            if (this->game_obj->owner == this->player) {
                if (this->game_obj->object_state == 0) {
                    progress = bldg_obj->get_construction_progress();
                }

                if (this->game_obj->object_state == 0 ||
                    work_type == 0x67 || work_type == 0x66) {
                    this->draw_item(row, 9, ValueTypePercent, progress, 0);
                    ++row;
                } else {
                    if (this->game_obj->master_obj->id == 0x46) {
                        int value = (int)(this->player->attributes[4] +
                                          this->player->attributes[11]);
                        int max_value = (int)this->player->attributes[32];
                        if (max_value < value)
                            value = max_value;
                        int current_value = (int)this->player->attributes[11];
                        this->draw_item(row, 4, ValueTypeCompare, current_value, value);
                        ++row;
                    }

                    if (this->game_obj->master_obj->id == 0x32) {
                        RGE_Action* action = bldg_obj->actions->get_action();
                        if (action != 0)
                            this->draw_item(
                                row, 2, ValueTypeNumber,
                                (int)(action->field_2c +
                                      this->game_obj->attribute_amount_held -
                                      DAT_00576d84),
                                0);
                    }
                }
            }
        }

        if (this->game_obj->object_state != 0 &&
            this->game_obj->object_state == 2) {
            int show_resource = 0;
            if (this->game_obj->owner == this->player) {
                if (work_type != 0x67 && work_type != 0x66) {
                    if (this->game_obj->master_obj->id == 0x2d) {
                        show_resource = 1;
                    } else if (this->game_obj->master_obj->id != 0x32 &&
                               this->game_obj->attribute_type_held != -1 &&
                               (int)this->game_obj->attribute_amount_held > 0) {
                        show_resource = 1;
                    }
                }
            } else if (this->game_obj->master_obj->id == 0x2d) {
                show_resource = 1;
            }

            if (show_resource) {
                short resource_type = this->game_obj->attribute_type_held;
                if (this->game_obj->master_obj->id == 0x2d) {
                    resource_type = 9;
                }

                int item_type;
                switch (resource_type) {
                case 0:
                case 0x0f:
                case 0x10:
                case 0x11:
                    item_type = 2;
                    break;
                case 1:
                    item_type = 0;
                    break;
                case 2:
                    item_type = 1;
                    break;
                case 3:
                    item_type = 3;
                    break;
                case 9:
                    item_type = 5;
                    break;
                default:
                    // BINARY NOTE: an invalid resource type skips this draw.
                    goto resource_done;
                }

                if (this->game_obj->master_obj->id == 0x2d) {
                    this->draw_item(
                        row, item_type, ValueTypeNumber,
                        (int)(this->game_obj->owner->attributes[9] -
                              DAT_00576d84), 0);
                } else {
                    this->draw_item(
                        row, item_type, ValueTypeNumber,
                        (int)(this->game_obj->attribute_amount_held -
                              DAT_00576d84), 0);
                }
                ++row;
            }
        }

resource_done:
        if (this->game_obj->master_obj->id == 0x2d &&
            this->game_obj->owner != this->player) {
            RGE_Player* current_player = rge_base_game->get_player();
            RGE_Static_Object* nearby = current_player->objects->find_by_master_id(
                0x2d,
                this->game_obj->world_x,
                this->game_obj->world_y,
                1,
                2,
                this->game_obj);

            if (nearby != 0) {
                dx = nearby->world_x - this->game_obj->world_x;
                float dy = nearby->world_y - this->game_obj->world_y;
                float distance = dx * dx + dy * dy;
                distance *= DAT_00576d88;
                distance *= DAT_00576d8c;
                if (this->player->master_player_id == 0x0f)
                    distance += 1.0f;
                if (distance < DAT_00576d98)
                    distance = DAT_00576da0;
                distance *= DAT_00576da4;
                if (distance > DAT_00576da8)
                    distance = DAT_00576da8;
                this->draw_item(
                    row, 3, ValueTypeCompare,
                    (int)(distance - DAT_00576d84), 0x14);
            }
        }
    }
invalid_item:
    this->draw_finish();
    return;

finish:
    this->draw_finish();
}

// 0051BF90 draw_score (tpnl_obj.cpp:741-814)
void TRIBE_Panel_Object::draw_score()
{
    int i;
    short x_val;
    HGDIOBJ old_font;
    RGE_Player* temp_player;
    int y_offset = 0;
    short x;
    short y;
    RECT rect;
    char str[100];

    if (this->render_area == 0 || this->visible == 0 || this->active == 0) {
        this->need_redraw = 0;
        return;
    }

    this->draw_setup(0);
    this->render_area->Clear(&this->clip_rect, 0);

    if (this->render_area->GetDc(s_tpnl_obj_draw_score) != 0) {
        SetBkMode(this->render_area->DrawDc, 1);
        SetTextColor(this->render_area->DrawDc, 0xFFFFFF);
        old_font = SelectObject(this->render_area->DrawDc,
                                (HGDIOBJ)this->font);

        x = (short)this->pnl_x + 3;
        x_val = (short)this->pnl_x + 0x5A;
        y = (short)this->pnl_y - 1;

        i = 1;
        do {
            int player_id = rge_base_game->playerID(i);
            if (player_id != 0 &&
                player_id < rge_base_game->world->player_num) {
                temp_player = rge_base_game->world->players[player_id];
                int color;

                switch (temp_player->color_table->id) {
                case 0:
                    color = 0xFF0000;
                    break;
                case 1:
                    color = 0x2139C6;
                    break;
                case 2:
                    color = 0xFFFF;
                    break;
                case 3:
                    color = 0x4F73A3;
                    break;
                case 4:
                    color = 0x0F77F3;
                    break;
                case 5:
                    color = 0xC700;
                    break;
                case 6:
                    color = 0x7B90A2;
                    break;
                case 7:
                    color = 0xADAD00;
                    break;
                default:
                    color = 0xFFFFFF;
                    break;
                }

                SetTextColor(this->render_area->DrawDc, color);
                strcpy(str, comm->GetPlayerName(i));
                TextOutA(this->render_area->DrawDc, x, y + y_offset,
                         str, strlen(str));
                sprintf(str, s_fmt_d,
                        temp_player->victory_conditions->get_victory_points());
                SetRect(&rect, x_val, y + y_offset,
                        this->pnl_x + this->pnl_wid - 3,
                        y + y_offset + 0x0E);
                DrawTextA(this->render_area->DrawDc, str, -1, &rect, 0x22);
                y_offset += 0x0E;
            }
            ++i;
        } while (i < 9);

        SelectObject(this->render_area->DrawDc, old_font);
        this->render_area->ReleaseDc(s_tpnl_obj_draw_score);
    }

    this->draw_finish();
}

// 0051C220 draw_item (tpnl_obj.cpp:820-867)
void TRIBE_Panel_Object::draw_item(int index, int frame, ValueType type,
                                   int value, int value2)
{
    char val_str[20];

    if (this->item_pic != 0 && frame != -1) {
        if (this->render_area->Lock((char*)s_tpnl_obj_draw_item, 1) != 0) {
            this->item_pic->shape_draw(
                this->render_area,
                this->pnl_x + 0x36,
                this->pnl_y + index * 0x14 + 0x1E,
                frame, 0, 0);
            this->render_area->Unlock((char*)s_tpnl_obj_draw_item);
        }
    }

    switch (type) {
    case ValueTypeNumber:
        sprintf(val_str, s_fmt_d, value);
        break;
    case ValueTypeBonus:
        if (value2 > value)
            sprintf(val_str, s_fmt_d_plus_d, value, value2 - value);
        else
            sprintf(val_str, s_fmt_d, value);
        break;
    case ValueTypeCompare:
        sprintf(val_str, s_fmt_d_slash_d, value, value2);
        break;
    case ValueTypePercent:
        sprintf(val_str, s_fmt_d_percent, value);
        break;
    default:
        val_str[0] = 0;
        break;
    }

    if (val_str[0] != 0) {
        void* dc = this->render_area->GetDc((char*)s_tpnl_obj_draw_item);
        if (dc != 0) {
            SetBkMode(this->render_area->DrawDc, 1);
            SetTextColor(this->render_area->DrawDc, 0xFFFFFF);
            HGDIOBJ old_font = SelectObject(this->render_area->DrawDc,
                                             (HGDIOBJ)this->font);

            TextOutA(this->render_area->DrawDc,
                     this->pnl_x + 0x58,
                     this->pnl_y + index * 0x14 + 0x21,
                     val_str, strlen(val_str));

            SelectObject(this->render_area->DrawDc, old_font);
            this->render_area->ReleaseDc((char*)s_tpnl_obj_draw_item);
        }
    }
}

// 0051C3F0 handle_idle (tpnl_obj.cpp:873-1133)
long TRIBE_Panel_Object::handle_idle()
{
    TPanel::handle_idle();
    if (this->active == 0) return 0;

    unsigned long now = debug_timeGetTime(
        "C:\\msdev\\work\\age1_x1\\tpnl_obj.cpp", 0x37C);
    if (now - this->idle_time < this->idle_interval) return 0;
    now = debug_timeGetTime(
        "C:\\msdev\\work\\age1_x1\\tpnl_obj.cpp", 0x37F);
    this->idle_time = now;

    if (this->mode == 2) {
        for (int i = 1; i < 9; ++i) {
            int p = rge_base_game->playerID(i);
            if (p != 0) {
                long score = rge_base_game->world->players[p]->victory_conditions->get_victory_points();
                if (this->save_score[p] != score) {
                    if (this->need_redraw == 0) this->set_redraw(1);
                    this->save_object_info();
                    return 0;
                }
            }
        }
        return 0;
    }

    if ((this->player == 0 && this->game_obj != 0) ||
        (this->player != 0 &&
         this->player->object_130 != this->game_obj)) {
        if (this->player != 0) {
            this->set_object(this->player->object_130);
        } else {
            this->set_object(0);
        }
        return 0;
    }

    int changed = 0;
    int do_buttons = 0;
    TRIBE_Building_Object* bldg;
    short cur_val;
    short work_target;
    short orig_val;
    float cur_fval;
    short temp;
    short work_type;
    short progress_value;
    float orig_fval;
    char name[100];

    {
    RGE_Action_Object* object = (RGE_Action_Object*)this->game_obj;
    if (object == 0) goto finish;

    if (object->owner != this->save_owner) {
        changed = 1;
        do_buttons = 1;
    } else if (object->selected_group != this->save_selected_group) {
        changed = 1;
        do_buttons = 1;
    } else if (object->master_obj != this->save_obj_type) {
        changed = 1;
        do_buttons = 1;
    } else {
        short n = object->objects->number_of_objects;
        if (n == this->save_number_of_objects) {
            if (object->attribute_type_held != this->save_attr_type ||
                object->attribute_amount_held != this->save_attr_amount ||
                object->hp != this->save_hp ||
                object->objects->list != this->save_list ||
                object->master_obj->los != this->save_los ||
                object->master_obj->id == 0x2d) {
                changed = 1;
            }
        } else {
            changed = 1;
            if (n == 0 || this->save_number_of_objects == 0) do_buttons = 1;
        }
    }

    if (!changed) {
        unsigned char type = ((RGE_Action_Object*)this->game_obj)->master_obj->master_type;
        if (type >= 0x46 && type != 0x5A) {
            if (((RGE_Action_Object*)this->game_obj)->have_action() != this->save_have_action) {
                changed = 1; do_buttons = 1;
            }
            if (!changed) {
                ((RGE_Combat_Object*)this->game_obj)->get_armor(orig_val, cur_val);
                if (orig_val != this->save_armor) { changed = 1; }
                if (!changed) {
                    ((RGE_Combat_Object*)this->game_obj)->get_pierce_armor(orig_val, cur_val);
                    if (orig_val != this->save_pierce_armor) { changed = 1; }
                }
                if (!changed) {
                    ((RGE_Combat_Object*)this->game_obj)->get_weapon(orig_val, cur_val);
                    if (orig_val != this->save_weapon) { changed = 1; }
                }
                if (!changed) {
                    ((RGE_Combat_Object*)this->game_obj)->get_weapon_range(cur_fval, orig_fval);
                    if (cur_fval != this->save_weapon_range) { changed = 1; }
                }
                if (!changed) {
                    ((RGE_Combat_Object*)this->game_obj)->get_speed_of_attack(cur_fval, orig_fval);
                    if (cur_fval != this->save_speed_of_attack) { changed = 1; }
                }
            }
        }
    }

    if (changed && do_buttons) goto finish;
    bldg = (TRIBE_Building_Object*)this->game_obj;
    if (bldg->master_obj->master_type != 'P') goto finish;
    if (bldg->object_state != this->save_object_state) {
        changed = 1; do_buttons = 1;
    }
    if (!changed || !do_buttons) {
        short progress = bldg->get_construction_progress();
        if ((float)progress != this->save_build_pts) {
            changed = 1;
            if ((float)progress > 99.0f) do_buttons = 1;
        }
    }
    if (!changed || !do_buttons) {
        bldg->work_status(work_type, work_target, progress_value, name, 100);
        if (work_type != 0x67 && work_type != 0x66 && bldg->production_queue_status(work_target, temp) != 0) {
            work_type = 0x66;
            orig_fval = (float)temp;
        }
        if (work_type == this->save_work_type &&
            work_target == this->save_work_target &&
            progress_value == this->save_progress) {
            if (strcmp(name, this->save_name) == 0) {
                goto name_same;
            }
        }
        changed = 1;
        if (work_type == this->save_work_type &&
            work_target == this->save_work_target) {
            if (strcmp(name, this->save_name) == 0) {
                goto name_same;
            }
        }
        do_buttons = 1;
    }
name_same:
    ;
    }
finish:
    if ((!changed || !do_buttons) && this->game_obj->master_obj->id == 0x46) {
        if ((int)this->player->attributes[11] != this->save_pop ||
            (int)this->player->attributes[4] != this->save_max_pop) {
            changed = 1;
        }
    }
    if ((!changed || !do_buttons) &&
        bldg->owner == this->player && bldg->master_obj->id == 0x32) {
        RGE_Action* action = bldg->actions->get_action();
        if (action != 0 &&
            (int)(action->attribute_amount + bldg->attribute_amount_held -
                  DAT_00576d84) != this->save_farm_amt) {
            changed = 1;
        }
    }
    if (changed) {
        if (this->need_redraw == 0) this->set_redraw(1);
        this->save_object_info();
        if (do_buttons) this->child->notify(this, 1, 0, 0);
    }
    return 0;
}

// 0051CA10 save_object_info (tpnl_obj.cpp:1139-1228)
void TRIBE_Panel_Object::save_object_info()
{
    if (this->mode == 2) {
        int i = 1;
        do {
            int player_id = rge_base_game->playerID(i);
            if (player_id != 0 &&
                player_id < rge_base_game->world->player_num) {
                this->save_score[player_id] =
                    rge_base_game->world->players[player_id]
                        ->victory_conditions->get_victory_points();
            }
            ++i;
        } while (i < 9);
        return;
    }

    RGE_Action_Object* object = (RGE_Action_Object*)this->game_obj;
    if (object == 0)
        return;

    short orig_val;
    short temp;
    float orig_fval;

    this->save_selected_group = object->selected_group;
    this->save_obj_type = object->master_obj;
    this->save_attr_type = object->attribute_type_held;
    this->save_attr_amount = object->attribute_amount_held;
    this->save_hp = object->hp;
    this->save_list = object->objects->list;
    this->save_number_of_objects = object->objects->number_of_objects;
    this->save_los = object->master_obj->los;
    this->save_owner = object->owner;

    if (object->master_obj->master_type >= 0x46 &&
        object->master_obj->master_type != 0x5A) {
        this->save_have_action = object->have_action();
        ((RGE_Combat_Object*)this->game_obj)->get_armor(
            this->save_armor, orig_val);
        ((RGE_Combat_Object*)this->game_obj)->get_armor(
            this->save_pierce_armor, orig_val);
        ((RGE_Combat_Object*)this->game_obj)->get_weapon(
            this->save_weapon, orig_val);
        ((RGE_Combat_Object*)this->game_obj)->get_weapon_range(
            this->save_weapon_range, orig_fval);
        ((RGE_Combat_Object*)this->game_obj)->get_speed_of_attack(
            this->save_speed_of_attack, orig_fval);
    }

    TRIBE_Building_Object* building =
        (TRIBE_Building_Object*)this->game_obj;
    if (building->master_obj->master_type == 'P') {
        this->save_object_state = building->object_state;
        int construction_progress = building->get_construction_progress();
        this->save_build_pts = (float)construction_progress;
        building->work_status(this->save_work_type,
                              this->save_work_target,
                              this->save_progress,
                              this->save_name, 100);

        if (this->save_work_type != 0x67 &&
            this->save_work_type != 0x66 &&
            building->production_queue_status(this->save_work_target,
                                               temp) != 0) {
            this->save_work_type = 0x66;
            this->save_progress = temp;
        }

        TRIBE_Player* player = this->player;
        this->save_pop = (int)player->attributes[11];
        this->save_max_pop = (int)player->attributes[4];

        if (this->game_obj->owner == player &&
            this->game_obj->master_obj->id == 0x32) {
            RGE_Action* action = building->actions->get_action();
            if (action != 0) {
                float action_amount = action->attribute_amount;
                this->save_farm_amt =
                    (int)(action_amount +
                          this->game_obj->attribute_amount_held -
                          DAT_00576d84);
            }
        }
    }
}

// 0051CC80 mouse_left_down_action (tpnl_obj.cpp:1234-1244)
long TRIBE_Panel_Object::mouse_left_down_action(long p0, long p1, int p2, int p3) { return 0; }

// 0051CC90 mouse_left_up_action (tpnl_obj.cpp:1250-1265)
long TRIBE_Panel_Object::mouse_left_up_action(long p0, long p1, int p2, int p3) { return 0; }
