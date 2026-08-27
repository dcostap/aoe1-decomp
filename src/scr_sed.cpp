
#include "../include/scr_sed.h"

TRIBE_Screen_Sed::TRIBE_Screen_Sed(char* file, int mode) : TScreenPanel("Scenario Editor Screen")
{
    char name[260];
    char temp_name[260];
    this->is_multi_player = 0;
    this->scenario_mode = 0;
    this->map_type = 0;
    this->mp_victory_type = 2;
    this->brush_size = BrushSizeNone;
    this->paint_type = 0;
    this->player_num = 1;
    this->message_type = MessageTypeNone;
    this->SelectedObject = 0;
    this->DestinationObject = 0;
    this->CurrentPlayer = 0;
    this->need_to_save_flag = 0;
    this->valid_save_spot_flag = 0;
    this->init_module_variables();
    this->update_interval = 200;
    this->last_update_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_sed.cpp", 0x117);
    this->map_redraw_interval = 1000;
    this->last_map_redraw_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_sed.cpp", 0x11A);
    this->save_text_color = 0;
    this->save_window_color = 0;
    this->changed_system_colors = 0;
    this->CurrentVictory = 0;
    rge_base_game->set_prog_mode(7);
    if (!this->command_new_map(file, mode, 0, 0x90, 0x90, 1)) {
        this->setup_error = 1;
        return;
    }
    int game_file_number = rge_base_game->registry->RegGetInt(0, "Game File Number");
    sprintf(temp_name, "default%d.scx", game_file_number);
    if (file && strcmp(file, temp_name) == 0)
        this->need_to_save_flag = 1;
    if (!this->TScreenPanel::setup(rge_base_game->draw_area,
                                   "scr5", 0xC387, 1)) {
        this->setup_error = 1;
        return;
    }
    this->TEasy_Panel::setup_shadow_area(0);
    this->main_view = new TRIBE_Main_View;
    if (this->main_view == 0 || this->main_view->setup_error != 0) {
        this->setup_error = 1;
        return;
    }
    if (!this->main_view->RGE_View::setup(this->render_area, this,
                                          0, 0, 0, 0, 0xA1, 0,
                                          "bordline")) {
        this->setup_error = 1;
        return;
    }
    this->map_view = new RGE_Diamond_Map_View;
    if (this->map_view == 0 || this->map_view->setup_error != 0) {
        this->setup_error = 1;
        return;
    }
    if (!this->map_view->RGE_Diamond_Map::setup(
            this->render_area, this, 0, 0, 0, 0, 0xA1, 0,
            rge_base_game->map_save_area)) {
        this->setup_error = 1;
        return;
    }
    this->map_view->set_bitmap("map640.bmp", 0xC4E1);
    {
        TRIBE_Main_View* main_view = this->main_view;
        RGE_Diamond_Map_View* map_view = this->map_view;
        map_view->main_view = main_view;
    }
    {
        RGE_Diamond_Map_View* map_view = this->map_view;
        TRIBE_Main_View* main_view = this->main_view;
        main_view->map_view = map_view;
    }
    this->main_view->set_help_info(-1, -1);
    RGE_Font* font = rge_base_game->get_font(0x0B);
    this->message_panel = new TMessagePanel(font->font, font->font_wid,
                                             font->font_hgt);
    if (this->message_panel == 0 || this->message_panel->setup_error != 0) {
        this->setup_error = 1;
        return;
    }
    if (!this->message_panel->setup(this->render_area, this->main_view,
                                    0, 0, 0, 0, 0)) {
        this->setup_error = 1;
        return;
    }
    this->bottom_panel = new TPanel;
    if (this->bottom_panel == 0 || this->bottom_panel->setup_error != 0) {
        this->setup_error = 1;
        return;
    }
    if (!this->bottom_panel->setup(this->render_area, this,
                                   0, 0, 0, 0, 0)) {
        this->setup_error = 1;
        return;
    }
    this->create_all_buttons_etc();
    int idx;
    if (file && *file) {
        if (strstr(file, ".scn") != 0 ||
            strstr(file, ".SCN") != 0) {
            char* source = file;
            int i = 0;
            do {
                name[i++] = source[0];
                source++;
            } while (source[0] != '.');
            name[i] = 0;
            sprintf(file, "%s.scx", name);
            this->world->scenario->Set_scenario_name(file);
        }
        for (idx = 0; idx < 8; ++idx) {
            if (this->world->scenario->Get_player_Active(idx) == 0)
                break;
        }
        --idx;
        this->player_number_list->set_line(idx);
    } else {
        this->set_player_active(0, 1);
        this->set_player_active(1, 1);
        this->player_number_list->set_line(1);
    }
    this->SavePlayerActiveStatus();
    this->set_curr_child(this->bottom_panel);
    this->position_panels();
    this->set_panel_info();
    this->set_map_type((MapType)1, 0);
    this->set_mp_victory_type((VictoryType)1, 0);
    this->set_brush_size(BrushSizeVerySmall);
    this->set_paint_type((PaintType)1, 0);
    this->set_player(1, 0, 0);
    this->set_unit_player(1);
    this->set_message_type(MessageTypeNormal, 0);
    this->set_scenario_mode(1);
    this->set_unit(-1);
    this->world->map->set_map_visible(1);
    this->world->map->set_map_fog(0);
}

void TRIBE_Screen_Sed::set_panel_info(void) {
    this->main_view->set_world(this->world);
    this->main_view->set_player(rge_base_game->get_player());
    this->map_view->set_world(this->world);
    this->map_view->set_player(rge_base_game->get_player());
}

void TRIBE_Screen_Sed::set_string(char* buffer, long panel_id, int limit) {
    this->get_string(panel_id, buffer, limit);
}

int TRIBE_Screen_Sed::create_button(TPanel* panel, TButtonPanel** button, long string_id, int param_4) {
    char buffer[0x78];
    ((TPanel*)this)->get_string(string_id, buffer, 0x78);
    return ((TEasy_Panel*)this)->create_button(panel, button, buffer, 0, 0, 0);
}

int TRIBE_Screen_Sed::create_button(TPanel* parent, TButtonPanel** out,
                                    char* text1, char* text2,
                                    char* text3, char* text4)
{
    if (this->TEasy_Panel::create_button(parent, out, text1, text2,
                                         0, 0, 0, 0, 10, 1, 0) == 0)
        return 0;

    if (text3 != 0)
        (*out)->set_text(2, text3);
    if (text4 != 0)
        (*out)->set_text(3, text4);

    (*out)->set_z_order(1, 0);
    (*out)->set_active(0);

    if (this->use_bevels != 0) {
        (*out)->set_bevel_info(3,
                               this->bevel_color1,
                               this->bevel_color2,
                               this->bevel_color3,
                               this->bevel_color4,
                               this->bevel_color5,
                               this->bevel_color6);
    }

    return 1;
}

int TRIBE_Screen_Sed::create_text(TPanel* panel, TTextPanel** text_panel, long value) {
    int ok = ((TEasy_Panel*)this)->create_text(panel, text_panel, value, 0, 0, 0, 0, 10, 0, 0, 0);
    if (!ok) return 0;
    ((TPanel*)(*text_panel))->set_z_order(1, 0);
    (*text_panel)->set_active(0);
    return 1;
}

int TRIBE_Screen_Sed::create_text(TPanel* panel, TTextPanel** text_panel, char* text) {
    int ok = ((TEasy_Panel*)this)->create_text(panel, text_panel, text, 0, 0, 0, 0, 10, 0, 0, 0);
    if (!ok) return 0;
    ((TPanel*)(*text_panel))->set_z_order(1, 0);
    (*text_panel)->set_active(0);
    return 1;
}

int TRIBE_Screen_Sed::create_input(TPanel* param_1, TInputPanel** param_2,
                                   char* param_3, short param_4,
                                   TInputPanel::FormatType param_5) {
    if (TEasy_Panel::create_input(param_1, param_2, param_3, param_4, param_5, 0, 0, 0, 0, 10) == 0) {
        return 0;
    }
    ((TPanel*)*param_2)->set_z_order(1, 0);
    ((TInputPanel*)*param_2)->set_active(0);
    return 1;
}

int TRIBE_Screen_Sed::create_edit(TPanel* panel, TEditPanel** out_edit,
                                  char* text, short width,
                                  TEditPanel::FormatType format, int a6,
                                  int a7) {
    int result = ((TEasy_Panel*)this)->create_edit(panel, out_edit, text, width, format, 0, 0, 0, 0, 10, a6, a7);
    if (result == 0) return 0;
    ((TPanel*)(*out_edit))->set_z_order(1, 0);
    (*out_edit)->set_active(0);
    return 1;
}

int TRIBE_Screen_Sed::create_drop_down(TPanel* parent, TDropDownPanel** out)
{
    long height;

    if (out == &this->victory_object_list ||
        out == &this->victory_attribute_list ||
        out == &this->victory_ages_list ||
        out == &this->victory_tech_list ||
        out == &this->BuildList ||
        out == &this->CityLayout ||
        out == &this->AiRules ||
        out == &this->victory_time) {
        height = 0xDC;
        goto create;
    }
    if (out != &this->victory_drop_down) {
        if (out == this->cinematic_input ||
            out == this->cinematic_input + 1 ||
            out == this->cinematic_input + 2 ||
            out == this->cinematic_input + 3 ||
            out == &this->default_terrain_drop ||
            out == &this->map_size_drop ||
            out == &this->map_style_drop) {
            height = 0xAA;
            goto create;
        }
        if (out == &this->player_advance_civilization_drop ||
            out == &this->player_list ||
            out == &this->player_number_list ||
            out == &this->unit_player_list ||
            out == &this->victory_player_list ||
            out == &this->options_player_list ||
            out == &this->Diplomacy_player_list ||
            out == &this->victory_enemy_player_list) {
            height = 0x96;
            goto create;
        }
        height = 0x82;
    } else {
        height = 0xB4;
    }

create:

    if (this->TEasy_Panel::create_drop_down(parent, out, height, 100, 0, 0,
                                             height, 0x16, 10) == 0) {
        return 0;
    }

    (*out)->set_z_order(1, 0);
    (*out)->set_active(0);
    (*out)->empty_list();

    TDropDownPanel** list;

    list = &this->map_size_drop;
    if (out == list) {
        (*list)->append_line(0x2973, 0);
        (*list)->append_line(0x2974, 0);
        (*list)->append_line(0x2975, 0);
        (*list)->append_line(0x2976, 0);
        (*list)->append_line(0x2977, 0);
        (*list)->append_line(0x2978, 0);
        (*list)->set_line(3);
        goto done;
    } else {
        list = &this->map_style_drop;
        if (out == list) {
            (*list)->append_line(0x296A, 0);
            (*list)->append_line(0x296B, 0);
            (*list)->append_line(0x296C, 0);
            (*list)->append_line(0x296D, 0);
            (*list)->append_line(0x296E, 0);
            (*list)->append_line(0x296F, 0);
            (*list)->append_line(0x2970, 0);
            (*list)->append_line(0x2971, 0);
            (*list)->append_line(0x2972, 0);
            (*list)->set_line(3);
            goto done;
        } else {
            list = &this->player_number_list;
            if (out == list) {
                int i = 0;
                do {
                    (*list)->append_line(i + 0x2877, 0);
                    i++;
                } while (i < 8);
                (*list)->set_line(0);
                goto done;
            } else {
                list = &this->victory_enemy_player_list;
                if (out == list) {
                    int i = 0;
                    do {
                        (*list)->append_line(i + 0x2877, 0);
                        i++;
                    } while (i < 8);
                    (*list)->set_line(0);
                    goto done;
                } else {
                    list = &this->victory_attribute_list;
                    if (out == list) {
                        (*list)->append_line(0x2882, 0x2B);
                        (*list)->append_line(0x2883, 0x29);
                        (*list)->append_line(0x2884, 0x2C);
                        (*list)->append_line(0x2886, 0x28);
                        (*list)->append_line(0x2887, 0x15);
                        (*list)->append_line(0x2888, 0x14);
                        (*list)->append_line(0x2889, 0x25);
                        (*list)->set_line(0);
                        goto done;
                    } else {
                        list = &this->default_terrain_drop;
                        if (out == list) {
                            (*list)->append_line(0x297D, 0);
                            (*list)->append_line(0x297E, 0);
                            (*list)->append_line(0x297F, 0);
                            (*list)->append_line(0x2980, 0);
                            (*list)->append_line(0x2981, 0);
                            (*list)->append_line(0x2982, 0);
                            (*list)->append_line(0x2983, 0);
                            (*list)->append_line(0x2984, 0);
                            (*list)->append_line(0x2985, 0);
                            (*list)->set_line(0);
                            goto done;
                        } else {
                            list = this->player_setting_drop;
                            if (out == list) {
                                (*list)->append_line(0x27E3, 0);
                                (*list)->append_line(0x27E4, 0);
                                (*list)->set_line(0);
                                goto done;
                            } else {
                                list = &this->victory_drop_down;
                                if (out == list) {
                                    (*list)->append_line(0x2851, 0);
                                    (*list)->append_line(0x2852, 0);
                                    (*list)->append_line(0x2853, 0);
                                    (*list)->append_line(0x2854, 0);
                                    (*list)->append_line(0x2855, 0);
                                    (*list)->append_line(0x2856, 0);
                                    (*list)->append_line(0x2857, 0);
                                    (*list)->append_line(0x2858, 0);
                                    (*list)->append_line(0x2859, 0);
                                    (*list)->append_line(0x285A, 0);
                                    (*list)->append_line(0x285B, 0);
                                    (*list)->append_line(0x285C, 0);
                                    (*list)->append_line(0x285D, 0);
                                    (*list)->append_line(0x285E, 0);
                                    (*list)->append_line(0x285F, 0);
                                    (*list)->append_line(0x2860, 0);
                                    (*list)->append_line(0x2861, 0);
                                    (*list)->append_line(0x2862, 0);
                                    (*list)->append_line(0x284F, 0);
                                    (*list)->set_line(0);
                                    goto done;
                                } else {
                                    list = this->player_setting_drop + 1;
                                    if (out == list) {
                                        (*list)->append_line(0x27F7, 0);
                                        (*list)->append_line(0x27F8, 0);
                                        (*list)->append_line(0x27F9, 0);
                                        (*list)->append_line(0x27FA, 0);
                                        (*list)->append_line(0x27FB, 0);
                                        (*list)->append_line(0x27FC, 0);
                                        (*list)->append_line(0x27FD, 0);
                                        (*list)->append_line(0x27FE, 0);
                                        (*list)->append_line(0x27FF, 0);
                                        (*list)->append_line(0x2800, 0);
                                        (*list)->append_line(0x2801, 0);
                                        (*list)->append_line(0x2802, 0);
                                        (*list)->append_line(0x2806, 0);
                                        (*list)->append_line(0x2807, 0);
                                        (*list)->append_line(0x2809, 0);
                                        (*list)->append_line(0x2808, 0);
                                        (*list)->set_line(0);
                                        goto done;
                                    } else {
                                        list = &this->victory_ages_list;
                                        if (out == list) {
                                            (*list)->append_line(0x1069, 0);
                                            (*list)->append_line(0x106A, 0);
                                            (*list)->append_line(0x106B, 0);
                                            (*list)->append_line(0x106C, 0);
                                            (*list)->set_line(0);
                                            goto done;
                                        } else {
                                            list = &this->victory_tech_list;
                                            if (out == list) {
                                                this->victory_tech_list->set_sorted(1);
                                                int i = 0;
                                                if (rge_base_game->world->tech->tech_tree_num > 0) {
                                                    int offset = 0;
                                                    do {
                                                        Tech_Entry* tree = rge_base_game->world->tech->tech_tree;
                                                        Tech_Entry* entry = (Tech_Entry*)((char*)tree + offset);
                                                        char* text = this->get_string(
                                                            entry->string_id);
                                                        if (text != 0 && *text != 0) {
                                                            (*list)->append_line(text, i);
                                                        }
                                                        i++;
                                                        offset += 0x3C;
                                                    } while (i < rge_base_game->world->tech->tech_tree_num);
                                                }
                                                (*list)->set_line(0);
                                                goto done;
                                            } else {
                                                if (out == &this->AiRules) {
                                                    this->MakeFileList(this->AiRules,
                                                        rge_base_game->prog_info->ai_dir,
                                                        (char*)".per", 0, 1);
                                                    (*out)->set_line(0);
                                                    goto done;
                                                } else {
                                                    list = &this->BuildList;
                                                    if (out == list) {
                                                        this->MakeFileList(*list,
                                                            rge_base_game->prog_info->ai_dir,
                                                            (char*)".ai", 1, 1);
                                                        (*out)->set_line(0);
                                                        goto done;
                                                    } else {
                                                        list = &this->CityLayout;
                                                        if (out == list) {
                                                            this->MakeFileList(*list,
                                                                rge_base_game->prog_info->ai_dir,
                                                                (char*)".cty", 1, 0);
                                                            (*out)->set_line(0);
                                                            goto done;
                                                        } else {
                                                            if (out == this->cinematic_input ||
                                                                out == this->cinematic_input + 1 ||
                                                                out == this->cinematic_input + 2) {
                                                                this->MakeFileList(*out,
                                                                    rge_base_game->prog_info->avi_dir,
                                                                    (char*)".avi", 1, 0);
                                                                (*out)->set_line(0);
                                                                goto done;
                                                            } else {
                                                                if (out == this->cinematic_input + 3) {
                                                                    this->MakeFileList(*out,
                                                                        s_592A40,
                                                                        (char*)".bmp", 1, 0);
                                                                    (*out)->set_line(0);
                                                                    goto done;
                                                                } else {
                                                                    list = &this->victory_object_list;
                                                                    if (out != list) {
                                                                        goto done;
                                                                    }

                                                                    this->victory_object_list->set_sorted(1);
                                                                    this->victory_object_list->empty_list();

                                                                    int i = 0;
                                                                    RGE_Player* player = this->world->players[1];
                                                                    int count = player->master_object_num;
                                                                    if (count > 0) {
                                                                        char str[256];
                                                                        do {
                                                                            RGE_Master_Static_Object* object = player->master_objects[i];
                                                                            if (object != 0 && object->hide_in_scenario_editor == 0) {
                                                                                if (object->string_id > 0) {
                                                                                    rge_base_game->get_string(object->string_id, str, 0x100);
                                                                                } else {
                                                                                    strcpy(str, object->name);
                                                                                }
                                                                                this->victory_object_list->append_line(str, i);
                                                                            }
                                                                            i++;
                                                                        } while (i < count);
                                                                    }
                                                                    this->victory_object_list->set_line(0);
                                                                    goto done;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

done:
    return this->error_code == 0;
}

int TRIBE_Screen_Sed::SetupListOfTerrain(TListPanel* list) {
    list->empty_list();
    list->append_line(0x297D, 0);
    list->append_line(0x297E, 0);
    list->append_line(0x297F, 0);
    list->append_line(0x2980, 0);
    list->append_line(0x2981, 0);
    list->append_line(0x2982, 0);
    list->append_line(0x2983, 0);
    list->append_line(0x2984, 0);
    list->append_line(0x2985, 0);
    return 8;
}

int TRIBE_Screen_Sed::create_list(TPanel* panel, TListPanel** out, TScrollBarPanel** scroll)
{
    char str1[50];
    char str2[60];

    if (this->TEasy_Panel::create_list(panel, out, 0, 0, 0, 0, 10) == 0)
        return 0;

    (*out)->set_active(0);
    (*out)->empty_list();

    if (this->TEasy_Panel::create_auto_scrollbar(scroll, *out, 0x14) == 0)
        return 0;

    if (out == &this->paint_elevation_list) {
        this->set_string(str1, 0x2987, 0x32);
        for (int i = 0; i < 7; i++) {
            sprintf(str2, "%s %d", str1, i + 1);
            this->paint_elevation_list->append_line(str2, 0);
        }
        return 1;
    }

    if (out == &this->paint_terrain_list) {
        this->SetupListOfTerrain(this->paint_terrain_list);
    }

    return 1;
}

TRIBE_Screen_Sed::~TRIBE_Screen_Sed()
{
    panel_system.destroyPanel((char*)0x00586D18);
    panel_system.destroyPanel((char*)0x00586D08);
    panel_system.destroyPanel((char*)0x00586CF8);
    panel_system.destroyPanel((char*)0x005843B8);
    panel_system.destroyPanel((char*)0x005843CC);

    this->delete_panel(&this->map_type_label);
    {
        TPanel** pp = (TPanel**)this->map_type_text;
        int count = 3;
        do {
            this->delete_panel(pp - 3);
            this->delete_panel(pp);
            pp++;
            count--;
        } while (count != 0);
    }
    this->delete_panel(&this->default_terrain_label);
    this->delete_panel(&this->default_terrain_drop);
    this->delete_panel(&this->map_size_label);
    this->delete_panel(&this->map_size_drop);
    this->delete_panel(&this->map_style_drop);
    this->delete_panel(&this->map_style_label);
    this->delete_panel(&this->map_generating_text);
    this->delete_panel(&this->random_seed_label);
    this->delete_panel(&this->random_seed_input);
    this->delete_panel(&this->random_seed_used_label);
    this->delete_panel(&this->random_seed_used_text);
    this->delete_panel(&this->generate_map_button);
    this->delete_panel(&this->brush_size_label);
    {
        TPanel** pp = (TPanel**)this->brush_size_button_label;
        int count = 5;
        do {
            this->delete_panel(pp - 5);
            this->delete_panel(pp);
            pp++;
            count--;
        } while (count != 0);
    }
    this->delete_panel(&this->paint_type_label);
    {
        TPanel** pp = (TPanel**)this->paint_type_button_label;
        int count = 3;
        do {
            this->delete_panel(pp - 3);
            this->delete_panel(pp);
            pp++;
            count--;
        } while (count != 0);
    }
    this->delete_panel(&this->paint_terrain_label);
    this->delete_panel(&this->paint_terrain_list);
    this->delete_panel(&this->paint_terrain_scrollbar);
    this->delete_panel(&this->paint_elevation_list);
    this->delete_panel(&this->paint_elevation_scrollbar);
    this->delete_panel(&this->player_advance_civilization_drop);
    this->delete_panel(&this->player_label);
    this->delete_panel(&this->player_starting_age_label);
    this->delete_panel(&this->player_build_text);
    this->delete_panel(&this->player_city_text);
    this->delete_panel(&this->AiRules_text);
    this->delete_panel(&this->player_list);
    this->delete_panel(&this->player_number_list);
    {
        TPanel** pp = (TPanel**)this->player_inven_input;
        int count = 5;
        do {
            this->delete_panel(pp - 5);
            this->delete_panel(pp);
            pp++;
            count--;
        } while (count != 0);
    }
    {
        TPanel** pp = (TPanel**)this->player_setting_drop;
        int count = 2;
        do {
            this->delete_panel(pp - 3);
            this->delete_panel(pp);
            pp++;
            count--;
        } while (count != 0);
    }
    this->delete_panel(&this->BuildList);
    this->delete_panel(&this->CityLayout);
    this->delete_panel(&this->AiRules);
    this->delete_panel(&this->unit_player_list);
    {
        TPanel** pp = (TPanel**)this->unit_mode_select_label;
        int count = 4;
        do {
            this->delete_panel(pp - 4);
            this->delete_panel(pp);
            pp++;
            count--;
        } while (count != 0);
    }
    this->delete_panel(&this->unit_list);
    this->delete_panel(&this->unit_scrollbar);
    if (this->unit_list_info != 0) {
        free(this->unit_list_info);
        this->unit_list_info = 0;
    }
    if (this->object_panel != 0) {
        this->object_panel->slot0(1);
        this->object_panel = 0;
    }
    if (this->button_unit_pics != 0) {
        TShape* p = this->button_unit_pics;
        delete p;
        this->button_unit_pics = 0;
    }
    {
        TShape** pp = this->button_bldg_pics;
        int count = 5;
        do {
            TShape* p = *pp;
            if (p != 0) {
                delete p;
                *pp = 0;
            }
            pp++;
            count--;
        } while (count != 0);
    }
    {
        TPanel** pp = (TPanel**)this->victory_cond_on;
        int count = 6;
        do {
            this->delete_panel(pp);
            pp++;
            count--;
        } while (count != 0);
    }
    {
        TPanel** pp = (TPanel**)this->victory_text_and_or;
        int count = 2;
        do {
            this->delete_panel(pp - 5);
            this->delete_panel(pp);
            pp++;
            count--;
        } while (count != 0);
    }
    this->delete_panel(&this->victory_amount_label);
    this->delete_panel(&this->victory_long_label);
    this->delete_panel(&this->victory_condition_label);
    this->delete_panel(&this->victory_label_conquest);
    this->delete_panel(&this->victory_label_explore);
    this->delete_panel(&this->victory_label_explore_percent);
    this->delete_panel(&this->victory_label_ruins);
    this->delete_panel(&this->victory_label_artifacts);
    this->delete_panel(&this->victory_label_discoveries);
    this->delete_panel(&this->victory_label_gold);
    this->delete_panel(&this->victory_condition_explore);
    this->delete_panel(&this->victory_condition_ruins);
    this->delete_panel(&this->victory_condition_artifacts);
    this->delete_panel(&this->victory_condition_discoveries);
    this->delete_panel(&this->victory_condition_gold);
    {
        TPanel** pp = (TPanel**)this->victory_cond_type;
        int count = 5;
        do {
            this->delete_panel(pp - 5);
            this->delete_panel(pp);
            pp++;
            count--;
        } while (count != 0);
    }
    this->delete_panel(&this->victory_score_label);
    this->delete_panel(&this->victory_score);
    this->delete_panel(&this->victory_time_label);
    this->delete_panel(&this->victory_time);
    {
        TPanel** pp = (TPanel**)this->victory_button;
        int count = 12;
        do {
            this->delete_panel(pp);
            pp++;
            count--;
        } while (count != 0);
    }
    this->delete_panel(&this->victory_drop_down);
    this->delete_panel(&this->victory_object_list);
    this->delete_panel(&this->victory_player_list);
    this->delete_panel(&this->victory_ages_list);
    this->delete_panel(&this->victory_tech_list);
    this->delete_panel(&this->victory_button_set_object);
    this->delete_panel(&this->victory_button_set_destination);
    this->delete_panel(&this->victory_button_go_to_dest);
    this->delete_panel(&this->victory_condition_text);
    this->delete_panel(&this->victory_condition_type);
    this->delete_panel(&this->victory_amount_text);
    this->delete_panel(&this->victory_amount_input);
    this->delete_panel(&this->victory_enemy_player_list);
    this->delete_panel(&this->victory_attribute_list);
    this->delete_panel(&this->victory_which_enemy_text);
    this->delete_panel(&this->victory_object_scrollbar);
    {
        TPanel** pp = (TPanel**)this->message_button_label;
        int count = 5;
        do {
            this->delete_panel(pp - 5);
            this->delete_panel(pp);
            pp++;
            count--;
        } while (count != 0);
    }
    this->delete_panel(&this->message_input);
    {
        TPanel** pp = (TPanel**)this->cinematic_input;
        int count = 4;
        do {
            this->delete_panel(pp - 4);
            this->delete_panel(pp);
            pp++;
            count--;
        } while (count != 0);
    }
    {
        TPanel** pp = (TPanel**)this->options_button;
        int count = 1;
        do {
            this->delete_panel(pp - 1);
            this->delete_panel(pp);
            pp++;
            count--;
        } while (count != 0);
    }
    this->delete_panel(&this->options_player_list);
    this->delete_panel(&this->options_disable_tech_text);
    {
        TPanel** pp = (TPanel**)this->options_disable_text;
        int count = 16;
        do {
            this->delete_panel(pp - 16);
            this->delete_panel(pp);
            pp++;
            count--;
        } while (count != 0);
    }
    {
        for (int i = 0; i < 8; i++) {
            this->delete_panel(&this->Diplomacy_player_list);
            this->delete_panel(&this->Diplomacy_player_text[i]);
            this->delete_panel(&this->Diplomacy_friend_box_flat[i * 3 + 0]);
            this->delete_panel(&this->Diplomacy_friend_box_flat[i * 3 + 1]);
            this->delete_panel(&this->Diplomacy_friend_box_flat[i * 3 + 2]);
            this->delete_panel(&this->Diplomacy_AlliedVictory[i]);
        }
    }
    this->delete_panel(&this->Diplomacy_status_label[0]);
    this->delete_panel(&this->Diplomacy_status_label[1]);
    this->delete_panel(&this->Diplomacy_status_label[2]);
    this->delete_panel(&this->Diplomacy_status_label[3]);
    this->delete_panel(&this->menu_button);
    this->delete_panel(&this->help_button);
    {
        TPanel** pp = (TPanel**)this->scenario_mode_button;
        int count = 10;
        do {
            this->delete_panel(pp);
            pp++;
            count--;
        } while (count != 0);
    }
    this->delete_panel(&this->bottom_panel);
    this->delete_panel(&this->message_panel);
    this->delete_panel(&this->main_view);
    this->delete_panel(&this->map_view);
    if (this->background_pic != 0) {
        TShape* p = this->background_pic;
        delete p;
        this->background_pic = 0;
    }
    if (this->world != 0) {
        this->world->del_game_info();
    }
}

void TRIBE_Screen_Sed::set_scenario_mode(TRIBE_Screen_Sed::ScenarioMode param_1)
{
    int cur_mode;
    int mode = 0;
    int active = 0;
    TButtonPanel** ppv;
    TButtonPanel** ppf;
    int i;
    int activate_counter;

    this->valid_save_spot_flag = 0;
    do {
        if (mode == 0) {
            cur_mode = this->scenario_mode;
            active = 0;
        } else {
            if (param_1 != ScenarioModeSave) {
                cur_mode = param_1;
            }
            active = 1;
        }

        switch (cur_mode) {
        case ScenarioModeMap:
            this->map_type_label->set_active(active);
            {
                TButtonPanel** pp = (TButtonPanel**)this->map_type_text;
                int count = 3;
                do {
                    pp[-3]->set_active(active);
                    (*pp)->set_active(active);
                    pp++;
                    count--;
                } while (count != 0);
            }
            this->generate_map_button->set_active(active);
            if (active) {
                this->set_map_type((MapType)this->map_type, 1);
            } else {
                this->set_map_type((MapType)ScenarioModeNone, 0);
            }
            break;

        case ScenarioModeTerrain:
            this->brush_size_label->set_active(active);
            this->paint_type_label->set_active(active);
            this->paint_terrain_label->set_active(active);
            {
                TPanel** pp = (TPanel**)this->brush_size_button_label;
                int count = 5;
                do {
                    pp[-5]->set_active(active);
                    (*pp)->set_active(active);
                    pp++;
                    count--;
                } while (count != 0);
            }
            {
                TPanel** pp = (TPanel**)this->paint_type_button_label;
                int count = 3;
                do {
                    pp[-3]->set_active(active);
                    (*pp)->set_active(active);
                    pp++;
                    count--;
                } while (count != 0);
            }
            if (active) {
                this->set_brush_size(this->brush_size);
                this->set_paint_type((PaintType)this->paint_type, 1);
            } else {
                this->set_brush_size(BrushSizeNone);
                this->set_paint_type((PaintType)0, 0);
            }
            break;

        case ScenarioModePlayers:
            this->player_list->set_active(active);
            this->player_number_list->set_active(active);
            {
                TPanel** pp = (TPanel**)this->player_inven_input;
                int count = 5;
                do {
                    pp[-5]->set_active(active);
                    (*pp)->set_active(active);
                    pp++;
                    count--;
                } while (count != 0);
            }
            {
                TPanel** pp = (TPanel**)this->player_setting_drop;
                int count = 2;
                do {
                    pp[-3]->set_active(active);
                    (*pp)->set_active(active);
                    pp++;
                    count--;
                } while (count != 0);
            }
            if (active) {
                this->player_advance_civilization_drop->setCurrentLineNumber(
                    this->world->scenario->GetPlayerAge(this->player_num - 1));
                this->set_player(this->player_num, 0, 1);
                this->bottom_panel->set_curr_child(0);
                this->map_view->set_active(0);
            } else {
                this->set_player(this->player_num, 1, 0);
                this->map_view->set_active(1);
                this->SavePlayerActiveStatus();
            }
            this->player_advance_civilization_drop->set_active(active);
            this->player_label->set_active(active);
            this->player_starting_age_label->set_active(active);
            this->player_build_text->set_active(active);
            this->player_city_text->set_active(active);
            this->AiRules_text->set_active(active);
            this->BuildList->set_active(active);
            this->CityLayout->set_active(active);
            this->AiRules->set_active(active);
            break;

        case ScenarioModeUnits:
            this->unit_player_list->set_active(active);
            this->unit_list->set_active(active);
            this->object_panel->set_active(active);
            this->unit_mode_select[0]->set_active(active);
            this->unit_mode_select[1]->set_active(active);
            this->unit_mode_select[2]->set_active(active);
            this->unit_mode_select[3]->set_active(active);
            if (active) {
                this->unit_mode_select[0]->set_radio_button();
            }
            this->unit_mode_select_label[0]->set_active(active);
            this->unit_mode_select_label[1]->set_active(active);
            this->unit_mode_select_label[2]->set_active(active);
            this->unit_mode_select_label[3]->set_active(active);
            {
                short s = this->player_num;
                if (active) {
                    this->set_unit_player(s);
                    this->set_unit((short)this->unit_list->currentLineNumber());
                    this->bottom_panel->set_curr_child(this->unit_list);
                    this->set_paint_object_mode();
                    rge_base_game->set_game_mode(rge_base_game->game_mode, 4);
                    if (rge_base_game->master_obj_id != -1 && rge_base_game->get_player() != 0) {
                        s = rge_base_game->master_obj_id;
                        this->object_panel->set_master_info(
                            this->world->players[rge_base_game->get_player()->id]->master_objects[s],
                            (TRIBE_Player*)rge_base_game->get_player());
                    } else {
                        this->object_panel->set_master_info(0, 0);
                    }
                    this->object_panel->set_redraw(1);
                } else {
                    if (s < 1 || s > 8) {
                        this->player_num = 1;
                        this->set_player(1, 0, 0);
                    }
                    rge_base_game->set_game_mode(0, 0);
                    this->set_unit(-1);
                }
            }
            break;

        case ScenarioModeVictory:
            this->activate_victory_panel(active);
            if (active) {
                this->load_victory_cond_from_scenario(this->CurrentVictory);
                this->activate_victory_proper_fields(this->victory_drop_down->get_line(), active);
            } else {
                this->save_victory_cond_in_scenario(this->CurrentVictory);
                this->activate_victory_proper_fields(this->victory_drop_down->get_line(), 0);
                this->SelectedObject = 0;
                this->DestinationObject = 0;
                rge_base_game->get_player()->unselect_object();
            }
            break;

        case ScenarioModeVictoryMulti:
            this->victory_condition_label->set_active(active);
            {
                TPanel** pp = (TPanel**)this->victory_cond_type;
                int count = 5;
                do {
                    pp[-5]->set_active(active);
                    (*pp)->set_active(active);
                    pp++;
                    count--;
                } while (count != 0);
            }
            if (active) {
                this->load_multi_victory_cond_from_scenario();
                this->map_view->set_active(0);
                this->set_mp_victory_type((VictoryType)this->mp_victory_type, 1);
            } else {
                this->save_multi_victory_cond_in_scenario();
                this->map_view->set_active(1);
                this->set_mp_victory_type((VictoryType)0, 0);
            }
            break;

        case ScenarioModeMessages:
            {
                TPanel** pp = (TPanel**)this->message_button_label;
                int count = 5;
                do {
                    pp[-5]->set_active(active);
                    (*pp)->set_active(active);
                    pp++;
                    count--;
                } while (count != 0);
            }
            this->message_button[this->current_message]->set_radio_button();
            if (active) {
                char* text = this->world->scenario->Get_message(this->current_message);
                this->message_input->set_text(text);
                switch (this->current_message) {
                case 0:
                    this->message_input->set_help_info(0x7770, -1);
                    break;
                case 1:
                    this->message_input->set_help_info(0x7771, -1);
                    break;
                case 2:
                    this->message_input->set_help_info(0x7772, -1);
                    break;
                case 3:
                    this->message_input->set_help_info(0x7773, -1);
                    break;
                case 4:
                    this->message_input->set_help_info(0x7774, -1);
                    break;
                default:
                    break;
                }
                this->set_message_type((MessageType)this->message_type, 1);
                this->map_view->set_active(0);
                this->bottom_panel->set_curr_child(this->message_input);
            } else {
                this->world->scenario->Set_message(this->message_input->get_input_buffer(), this->current_message);
                this->set_message_type(MessageTypeNone, 0);
                this->map_view->set_active(1);
                this->save_info_in_scenario();
            }
            break;

        case ScenarioModeCinematics:
            {
                TDropDownPanel** pp = this->cinematic_input;
                activate_counter = 4;
                do {
                    pp[-4]->set_active(active);
                    (*pp)->set_active(active);
                    pp++;
                    activate_counter--;
                } while (activate_counter != 0);
            }
            if (active) {
                this->bottom_panel->set_curr_child(this->cinematic_input[0]);
                {
                    long line;
                    line = this->cinematic_input[0]->get_line(this->world->scenario->Get_Cine_PreGame());
                    this->cinematic_input[0]->setCurrentLineNumber(line);
                    line = this->cinematic_input[1]->get_line(this->world->scenario->Get_Cine_Victory());
                    this->cinematic_input[1]->setCurrentLineNumber(line);
                    line = this->cinematic_input[2]->get_line(this->world->scenario->Get_Cine_Loss());
                    this->cinematic_input[2]->setCurrentLineNumber(line);
                    line = this->cinematic_input[3]->get_line(this->world->scenario->Get_Mission_Bmp());
                    if (line == -1) {
                        this->cinematic_input[3]->append_line(this->world->scenario->Get_Mission_Bmp(), 0);
                        line = this->cinematic_input[3]->get_line(this->world->scenario->Get_Mission_Bmp());
                    }
                    this->cinematic_input[3]->setCurrentLineNumber(line);
                }
            } else {
                this->world->scenario->Set_Cine_PreGame(this->cinematic_input[0]->currentLine());
                this->world->scenario->Set_Cine_Victory(this->cinematic_input[1]->currentLine());
                this->world->scenario->Set_Cine_Loss(this->cinematic_input[2]->currentLine());
                this->world->scenario->Set_Mission_Bmp(this->cinematic_input[3]->currentLine());
            }
            break;

        case ScenarioModeDiplomacy:
            if (this->player_num < 1) {
                this->player_num = 1;
            }
            this->Diplomacy_player_list->set_active(active);
            {
                long lVar5;
                i = 0;
                lVar5 = this->player_number_list->get_line();
                if (lVar5 >= 0) {
                    ppf = &this->Diplomacy_friend_box[0][1];
                    ppv = this->Diplomacy_AlliedVictory;
                    do {
                        ppv[-0x25]->set_active(active);
                        {
                            TPanel* p = *ppv;
                            if (i != this->player_num - 1) {
                                p->set_active(0);
                                ppf[-1]->set_active(active);
                                (*ppf)->set_active(active);
                                p = ppf[1];
                            }
                            p->set_active(active);
                        }
                        ppv++;
                        i++;
                        ppf += 3;
                        lVar5 = this->player_number_list->get_line();
                    } while (i <= lVar5);
                }
            }
            this->Diplomacy_status_label[0]->set_active(active);
            this->Diplomacy_status_label[1]->set_active(active);
            this->Diplomacy_status_label[2]->set_active(active);
            this->Diplomacy_status_label[3]->set_active(active);
            if (active) {
                this->load_diplomacy_from_scenario(this->player_num - 1);
            } else {
                this->save_diplomacy_in_scenario(this->player_num - 1);
            }
            break;

        case ScenarioModeOptions:
            if (!active) {
                this->map_view->set_active(1);
                this->SaveDisabledItemsInScenario();
            } else {
                this->map_view->set_active(0);
                this->options_button[0]->set_state(this->world->scenario->GetScenarioOption(2));
                this->LoadDisabledItemsFromScenario();
                if (this->player_num != 0) {
                    this->options_player_list->setCurrentLineNumber(this->player_num - 1);
                } else {
                    this->options_player_list->setCurrentLineNumber(0);
                }
            }
            {
                TButtonPanel** pp = this->options_button;
                int count = 1;
                do {
                    pp[-1]->set_active(active);
                    (*pp)->set_active(active);
                    pp++;
                    count--;
                } while (count != 0);
            }
            this->options_player_list->set_active(active);
            if (active) {
                this->options_player_list->set_line(this->player_num - 1);
            } else {
                this->player_num = (short)(this->options_player_list->get_line() + 1);
            }
            this->options_disable_tech_text->set_active(active);
            {
                TPanel** pp = (TPanel**)this->options_disable_text;
                int count = 16;
                do {
                    pp[-16]->set_active(active);
                    (*pp)->set_active(active);
                    pp++;
                    count--;
                } while (count != 0);
            }
            break;
        }

        mode++;
    } while (mode < 2);

    if (param_1 != ScenarioModeSave) {
        this->scenario_mode = param_1;
        if (param_1 != ScenarioModeNone) {
            this->scenario_mode_button[param_1 - 1]->set_radio_button();
        }
        this->handle_size(this->pnl_wid, this->pnl_hgt);
        this->set_redraw(1);
    }
    this->valid_save_spot_flag = 1;
}

void TRIBE_Screen_Sed::set_paint_object_mode() {
    TRIBE_Screen_Sed* self = this;
    RGE_Base_Game* game = rge_base_game;
    int mo_id = (int)(short)game->master_obj_id;
    int enabled = 0;

    if (mo_id != -1) {
        int pn = (int)self->player_num;
        RGE_Master_Static_Object* obj = (RGE_Master_Static_Object*)(*(pn + self->world->players))->master_objects[mo_id];

        if (obj != 0 && obj->obj_type == 0x50 && obj->flag != 0) {
            enabled = 1;
        }
    }

    if (enabled) {
        game->set_game_mode(0x15, 0);
    } else {
        game->set_game_mode(8, game->sub_game_mode);
    }
}

void TRIBE_Screen_Sed::set_map_type(MapType type, int redraw)
{
    int pass;
    int active;
    int mode;
    TPanel* p;

    pass = 0;
    do {
        if (pass == 0) {
            active = 0;
            mode = this->map_type;
        } else {
            if (type == 0) {
                return;
            }
            if (redraw == 0) {
                break;
            }
            mode = type;
            active = 1;
        }

        switch (mode) {
        case 1:
            this->map_size_label->set_active(active);
            this->map_size_drop->set_active(active);
            this->default_terrain_label->set_active(active);
            p = this->default_terrain_drop;
            p->set_active(active);
            break;
        case 2:
            this->map_size_label->set_active(active);
            this->map_size_drop->set_active(active);
            this->map_style_label->set_active(active);
            this->map_style_drop->set_active(active);
            this->random_seed_used_label->set_active(active);
            p = this->random_seed_used_text;
            p->set_active(active);
            break;
        case 3:
            this->map_size_label->set_active(active);
            this->map_size_drop->set_active(active);
            this->map_style_label->set_active(active);
            this->map_style_drop->set_active(active);
            this->random_seed_label->set_active(active);
            this->random_seed_input->set_active(active);
            if (active != 0) {
                this->bottom_panel->set_curr_child(this->random_seed_input);
            }
            break;
        }
        pass++;
    } while (pass < 2);

    this->map_type = type;
    this->map_type_button[type - 1]->set_radio_button();
    this->bottom_panel->redraw(1);
}

void TRIBE_Screen_Sed::set_mp_victory_type(VictoryType type, int redraw)
{
    int pass;
    int active;
    int mode;
    int count;
    TButtonPanel** ppButton;
    TTextPanel** ppText;

    pass = 0;
    do {
        if (pass == 0) {
            active = 0;
            mode = this->mp_victory_type;
        } else {
            if (type == 0) {
                return;
            }
            if (redraw == 0) {
                break;
            }
            active = 1;
            mode = type;
        }

        switch (mode) {
        case 1:
        case 2:
            break;
        case 3:
            this->victory_score_label->set_active(active);
            this->victory_score->set_active(active);
            break;
        case 4:
            this->victory_time_label->set_active(active);
            this->victory_time->set_active(active);
            break;
        case 5:
            ppButton = this->victory_cond_on;
            count = 5;
            do {
                (*ppButton)->set_active(active);
                ppButton++;
                count--;
            } while (count != 0);

            ppText = this->victory_text_and_or;
            count = 2;
            do {
                ((TButtonPanel*)ppText[-5])->set_active(active);
                (*ppText)->set_active(active);
                ppText++;
                count--;
            } while (count != 0);

            this->victory_amount_label->set_active(active);
            this->victory_label_conquest->set_active(active);
            this->victory_label_explore->set_active(active);
            this->victory_label_ruins->set_active(active);
            this->victory_label_artifacts->set_active(active);
            this->victory_label_discoveries->set_active(active);
            this->victory_condition_explore->set_active(active);
            this->victory_condition_ruins->set_active(active);
            this->victory_condition_artifacts->set_active(active);
            this->victory_condition_discoveries->set_active(active);
            if (active == 1) {
                this->bottom_panel->set_curr_child(this->victory_condition_explore);
            }
            break;
        }
        pass++;
    } while (pass < 2);

    this->mp_victory_type = type;
    this->victory_cond_type[type - 1]->set_radio_button();
    this->bottom_panel->redraw(1);
}

void TRIBE_Screen_Sed::set_brush_size(BrushSize size) {
    if (!size) return;
    brush_size = size;
    brush_size_button[size - 1]->set_radio_button();
    int v;
    switch (brush_size) {
    case 1: v = 1; break;
    case 2: v = 3; break;
    case 3: v = 5; break;
    case 4: v = 7; break;
    case 5: v = 9; break;
    default: v = 2; break;
    }
    rge_base_game->brush_size = v;
}

void TRIBE_Screen_Sed::set_paint_type(PaintType type, int redraw)
{
    int pass;
    int active;
    int mode;
    int count;
    TTextPanel** pp;

    pass = 0;
    do {
        if (pass == 0) {
            mode = this->paint_type;
            active = 0;
        } else {
            if (type == 0) {
                return;
            }
            if (redraw == 0) {
                break;
            }
            mode = type;
            active = 1;
        }

        this->brush_size_label->set_active(active);
        pp = this->brush_size_button_label;
        count = 5;
        do {
            ((TButtonPanel*)pp[-5])->set_active(active);
            (*pp)->set_active(active);
            pp++;
            count--;
        } while (count != 0);

        switch (mode) {
        case 1:
            this->paint_terrain_list->set_active(active);
            this->paint_terrain_label->set_active(active);
            if (active != 0) {
                this->set_terrain((short)this->paint_terrain_list->currentLineNumber());
                rge_base_game->redraw(9, 0);
            } else {
                rge_base_game->redraw(0, 0);
            }
            break;
        case 2:
            this->paint_elevation_list->set_active(active);
            this->paint_terrain_label->set_active(active);
            if (active != 0) {
                this->set_elevation((short)this->paint_elevation_list->currentLineNumber());
                rge_base_game->redraw(10, 0);
            } else {
                rge_base_game->redraw(0, 0);
            }
            break;
        case 3:
            this->paint_elevation_list->set_active(0);
            this->paint_terrain_list->set_active(0);
            this->paint_terrain_label->set_active(0);
            this->brush_size_label->set_active(0);
            pp = this->brush_size_button_label;
            count = 5;
            do {
                ((TButtonPanel*)pp[-5])->set_active(0);
                (*pp)->set_active(0);
                pp++;
                count--;
            } while (count != 0);
            if (active != 0) {
                this->set_elevation((short)this->paint_elevation_list->currentLineNumber());
                rge_base_game->redraw(0x13, 0);
            } else {
                rge_base_game->redraw(0, 0);
            }
            break;
        }
        pass++;
    } while (pass < 2);

    this->paint_type = type;
    this->paint_type_button[type - 1]->set_radio_button();
    this->bottom_panel->redraw(1);
}

void TRIBE_Screen_Sed::set_terrain(short terrain) {
    short v;
    switch (terrain) {
    case 0: v = 0; break;
    case 1: v = 6; break;
    case 2: v = 10; break;
    case 3: v = 1; break;
    case 4: v = 0xD; break;
    case 5: v = 0x14; break;
    case 6: v = 4; break;
    case 7: v = 0x13; break;
    case 8: v = 0x16; break;
    default: v = 0; break;
    }
    RGE_Base_Game* game;
    game = rge_base_game;
    game->terrain_id = v;
    paint_terrain_list->scroll_cur_line(1, terrain, 1);
}

void TRIBE_Screen_Sed::set_elevation(short value) {
    RGE_Base_Game* base_game;

    base_game = rge_base_game;
    base_game->elevation_height = value;
    this->paint_elevation_list->scroll_cur_line(1, value, 1);
}

void TRIBE_Screen_Sed::set_player(short player, uchar update, uchar refresh)
{
    char str[30];
    long oldp = this->player_num - 1;
    if (oldp < 0) oldp = 0;

    rge_base_game->get_player()->unselect_object();

    if (update) {
        int v;
        v = atoi(this->player_inven_input[0]->currentLine());
        ((T_Scenario*)this->world->scenario)->Set_player_Food(oldp, v);
        *(float*)*(int*)((char*)this->world->players[this->player_num] + 0x50) = (float)v;

        v = atoi(this->player_inven_input[1]->currentLine());
        ((T_Scenario*)this->world->scenario)->Set_player_Wood(oldp, v);
        *(float*)(*(int*)((char*)this->world->players[this->player_num] + 0x50) + 4) = (float)v;

        v = atoi(this->player_inven_input[2]->currentLine());
        ((T_Scenario*)this->world->scenario)->Set_player_Stone(oldp, v);
        *(float*)(*(int*)((char*)this->world->players[this->player_num] + 0x50) + 8) = (float)v;

        v = atoi(this->player_inven_input[3]->currentLine());
        ((T_Scenario*)this->world->scenario)->Set_player_Gold(oldp, v);
        *(float*)(*(int*)((char*)this->world->players[this->player_num] + 0x50) + 12) = (float)v;

        ((RGE_Scenario*)this->world->scenario)->SetPlayerName(oldp, this->player_inven_input[4]->currentLine());
        ((RGE_Scenario*)this->world->scenario)->Set_player_Type(oldp, this->player_setting_drop[0]->currentLineNumber());
        ((RGE_Scenario*)this->world->scenario)->Set_player_Civ(oldp, this->player_setting_drop[1]->currentLineNumber() + 1);
        ((RGE_Scenario*)this->world->scenario)->Set_player_AI(oldp, this->AiRules->currentLine(0));
        ((RGE_Scenario*)this->world->scenario)->Set_BuildList(oldp, this->BuildList->currentLine(0));
        ((RGE_Scenario*)this->world->scenario)->Set_CityPlan(oldp, this->CityLayout->currentLine(0));
    }

    long p = player - 1;
    this->player_num = player;
    if (player != 0) {
        this->player_list->set_line(p);
        rge_base_game->set_player(player);
        if (refresh == 1) {
            int v;
            v = ((T_Scenario*)this->world->scenario)->Get_player_Food(p);
            sprintf(str, (char*)0x584610, v);
            this->player_inven_input[0]->set_text(str);
            v = ((T_Scenario*)this->world->scenario)->Get_player_Wood(p);
            sprintf(str, (char*)0x584610, v);
            this->player_inven_input[1]->set_text(str);
            v = ((T_Scenario*)this->world->scenario)->Get_player_Stone(p);
            sprintf(str, (char*)0x584610, v);
            this->player_inven_input[2]->set_text(str);
            v = ((T_Scenario*)this->world->scenario)->Get_player_Gold(p);
            sprintf(str, (char*)0x584610, v);
            this->player_inven_input[3]->set_text(str);
            this->player_inven_input[4]->set_text(((RGE_Scenario*)this->world->scenario)->GetPlayerName(p));
            this->player_setting_drop[0]->setCurrentLineNumber(((RGE_Scenario*)this->world->scenario)->Get_player_Type(p));
            this->player_setting_drop[1]->setCurrentLineNumber(((RGE_Scenario*)this->world->scenario)->Get_player_Civ(p) - 1);

            v = this->AiRules->get_line(((RGE_Scenario*)this->world->scenario)->Get_player_AI(p, 0));
            if (v == -1) {
                this->AiRules->append_line(((RGE_Scenario*)this->world->scenario)->Get_player_AI(p, 0), 0);
                v = this->AiRules->get_line(((RGE_Scenario*)this->world->scenario)->Get_player_AI(p, 0));
            }
            this->AiRules->setCurrentLineNumber(v);

            v = this->BuildList->get_line(((RGE_Scenario*)this->world->scenario)->Get_BuildList(p, 0));
            if (v == -1) {
                this->BuildList->append_line(((RGE_Scenario*)this->world->scenario)->Get_BuildList(p, 0), 0);
                v = this->BuildList->get_line(((RGE_Scenario*)this->world->scenario)->Get_BuildList(p, 0));
            }
            this->BuildList->setCurrentLineNumber(v);

            v = this->CityLayout->get_line(((RGE_Scenario*)this->world->scenario)->Get_CityPlan(p, 0));
            if (v == -1) {
                this->CityLayout->append_line(((RGE_Scenario*)this->world->scenario)->Get_CityPlan(p, 0), 0);
                v = this->CityLayout->get_line(((RGE_Scenario*)this->world->scenario)->Get_CityPlan(p, 0));
            }
            this->CityLayout->setCurrentLineNumber(v);
        }
    }
}

void TRIBE_Screen_Sed::set_player_active(short player, int active) {
    this->world->scenario->Set_player_Active((int)player, active);
}

int __cdecl TRIBE_Screen_Sed_unit_list_compare(const void* a, const void* b) {
    int result = CompareStringA(0x400, 1, (const char*)a, -1, (const char*)b, -1);
    if (result == 1) {
        return -1;
    }
    return result == 3;
}

void TRIBE_Screen_Sed::set_unit_player(short p)
{
    int is_error;
    float save_view_x;
    float save_view_y;
    short save_map_x;
    short save_map_y;

    RGE_Player* oldp = rge_base_game->get_player();
    save_view_x = oldp->view_x;
    save_view_y = oldp->view_y;
    save_map_x = oldp->map_x;
    save_map_y = oldp->map_y;
    rge_base_game->set_player(p);
    this->player_num = p;

    RGE_Player* player = rge_base_game->get_player();
    player->set_view_loc(save_view_x, save_view_y);
    player->set_map_loc(save_map_x, save_map_y);
    this->main_view->set_player(player);
    this->map_view->set_player(player);
    this->unit_player_list->setCurrentLineNumber((int)p);
    this->unit_list->empty_list();
    if (this->unit_list_info != 0) {
        free(this->unit_list_info);
        this->unit_list_info = 0;
    }
    if (player != 0) {
        this->unit_list_size = 1;
        short n = player->master_object_num;
        if (n > 0) {
            int object_offset = 0;
            int count = n;
            do {
                RGE_Master_Static_Object* m = *(RGE_Master_Static_Object**)((char*)player->master_objects + object_offset);
                if (m != 0 && m->disabled == 0) this->unit_list_size++;
                object_offset += 4;
                count--;
            } while (count != 0);
        }
        if (this->unit_list_size == 0) return;
        this->unit_list_info = (List_Info*)calloc((int)this->unit_list_size, 0x66);
        if (this->unit_list_info == 0) return;
        this->unit_list_info[0].id = -1;
        this->set_string(this->unit_list_info[0].text, 0x2775, 0x14);

        short out = 1; // BINARY NOTE: the original loads this index as a word.
        short i = 0;
        // BINARY NOTE: the offset zero store follows the positive-count test.
        if (n > 0) {
            int master_index = 0;
            do {
                RGE_Master_Static_Object* m = player->master_objects[master_index];
                if (m != 0 && m->disabled == 0) {
                    this->unit_list_info[out].id = (short)i;
                    m = player->master_objects[master_index];
                    if (m->string_id > 0) {
                        rge_base_game->get_string(m->string_id, this->unit_list_info[out].text, 100);
                    } else {
                        strcpy(this->unit_list_info[out].text, m->name);
                    }
                    out++;
                }
                i++;
                master_index++;
            } while (i < n);
        }

        qsort(this->unit_list_info, (int)this->unit_list_size, 0x66, TRIBE_Screen_Sed_unit_list_compare);
        char** strings = (char**)calloc((int)this->unit_list_size, 4);
        if (strings == 0) return;
        is_error = 0;
        short selected = 0; // BINARY NOTE: the selected row uses a short home.
        for (i = 0; i < this->unit_list_size; i++) {
            char* s = (char*)calloc(100, 1);
            strings[i] = s;
            if (s == 0) { is_error = 1; break; }
            strcpy(s, this->unit_list_info[i].text);
            if (this->unit_list_info[i].id == rge_base_game->master_obj_id) selected = i;
        }
        if (!is_error) {
            this->unit_list->set_text(strings, this->unit_list_size);
            this->unit_list->scroll_cur_line(1, (short)selected, 1);
        }
        for (i = 0; i < this->unit_list_size; i++) {
            if (strings[i] != 0) free(strings[i]);
        }
        free(strings);
    }
}

void TRIBE_Screen_Sed::set_unit(short unit) {
    if (unit == -1) {
        rge_base_game->master_obj_id = unit;
    } else {
        rge_base_game->master_obj_id = unit_list_info[unit].id;
    }

    unit_list->scroll_cur_line(1, unit, 1);
}

void TRIBE_Screen_Sed::set_message_type(MessageType type, int value) {
    message_input->set_active(value);
    bottom_panel->set_redraw(1);
}

long TRIBE_Screen_Sed::handle_size(long width, long height) {
    TPanel::handle_size(width, height);
    this->position_panels();
    TPanel::handle_size(width, height);
    return 0;
}

long TRIBE_Screen_Sed::handle_idle() {
    if (rge_base_game->prog_mode == 7) {
        unsigned long now = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_sed_cp, 0x8B1);
        if (last_update_time - now >= update_interval) {
            if (panel_system.modalPanel() == 0) {
                main_view->set_redraw(1);
                if (last_map_redraw_time - now >= map_redraw_interval) {
                    map_view->set_redraw(1);
                    last_map_redraw_time = now;
                }
            }
        }
    }
    return TPanel::handle_idle();
}

long TRIBE_Screen_Sed::key_down_action(long param_1, short param_2,
                                        int param_3, int param_4, int param_5)
{
    if (panel_system.modalPanel() == 0) {
        if (param_4 != 0) {
            switch (param_1) {
            case 0x41:
                if (rge_base_game->outline_type != 3) {
                    rge_base_game->outline_type = 3;
                    return 1;
                }
                rge_base_game->outline_type = 0;
                return 1;
            case 0x4D:
                this->scenario_mode_button[0]->set_state(1);
                this->set_scenario_mode(ScenarioModeMap);
                return 0;
            case 0x54:
                this->scenario_mode_button[1]->set_state(1);
                this->set_scenario_mode(ScenarioModeTerrain);
                return 0;
            case 0x50:
                this->scenario_mode_button[2]->set_state(1);
                this->set_scenario_mode(ScenarioModePlayers);
                return 0;
            case 0x55:
                this->scenario_mode_button[3]->set_state(1);
                this->set_scenario_mode(ScenarioModeUnits);
                return 0;
            case 0x44:
                this->scenario_mode_button[4]->set_state(1);
                this->set_scenario_mode(ScenarioModeDiplomacy);
                return 0;
            case 0x49:
                this->scenario_mode_button[5]->set_state(1);
                this->set_scenario_mode(ScenarioModeVictory);
                return 0;
            case 0x56:
                this->scenario_mode_button[6]->set_state(1);
                this->set_scenario_mode(ScenarioModeVictoryMulti);
                return 0;
            case 0x4F:
                this->scenario_mode_button[7]->set_state(1);
                this->set_scenario_mode(ScenarioModeOptions);
                return 0;
            case 0x57:
                this->scenario_mode_button[8]->set_state(1);
                this->set_scenario_mode(ScenarioModeMessages);
                return 0;
            case 0x43:
                this->scenario_mode_button[9]->set_state(1);
                this->set_scenario_mode(ScenarioModeCinematics);
                return 0;
            case 0x42:
                ++View_Grid_Mode;
                if (rge_base_game->gameDeveloperMode() != 0) {
                    if (View_Grid_Mode > 4) {
                        View_Grid_Mode = 0;
                    }
                } else if (View_Grid_Mode > 1) {
                    View_Grid_Mode = 0;
                }
                this->main_view->set_redraw(2);
                return 0;
            default:
                return 0;
            }
        }

        switch (param_1) {
        case 0x30:
        case 0x31:
        case 0x32:
        case 0x33:
        case 0x34:
        case 0x35:
        case 0x36:
        case 0x37:
        case 0x38:
            {
int mode = this->scenario_mode;
                int i = param_1 - 0x30;
                short selected = (short)i;

                if ((mode == ScenarioModeOptions) && (0 < i)) {
                    this->SaveDisabledItemsInScenario();
                    this->options_player_list->setCurrentLineNumber(i - 1);
                    this->action(this->options_player_list, 3, 0, 0);
                    this->set_player(selected, 0, 0);
                    this->player_num = selected;
                    this->LoadDisabledItemsFromScenario();
                    return 0;
                }

                if ((mode == ScenarioModePlayers) && (0 < i)) {
                    if (this->bottom_panel->curr_child == 0) {
                        this->player_list->setCurrentLineNumber(i - 1);
                        this->action(this->player_list, 0, 0, 0);
                        return 0;
                    }
                } else {
                    if (mode == ScenarioModeUnits) {
                        this->unit_player_list->setCurrentLineNumber(i);
                        this->action(this->unit_player_list, 0, 0, 0);
                        return 0;
                    }
                    if ((mode == ScenarioModeVictory) && (0 < i)) {
                        if (this->bottom_panel->curr_child == 0) {
                            this->victory_player_list->setCurrentLineNumber(i - 1);
                            this->action(this->victory_player_list, 1, 0, 0);
                            return 0;
                        }
                    } else if (mode == ScenarioModeDiplomacy) {
                        if (0 < i) {
                            this->Diplomacy_player_list->setCurrentLineNumber(i - 1);
                            this->action(this->Diplomacy_player_list, 1, 0, 0);
                            return 0;
                        }
                    } else if (0 < i) {
                        this->set_player(selected, 0, 0);
                        this->player_num = selected;
                        return 0;
                    }
                }
            }
            break;
        case 9:
            if (this->scenario_mode == ScenarioModePlayers) {
                if (this->bottom_panel->curr_child == 0) {
                    this->bottom_panel->set_curr_child(this->player_inven_input[0]);
                    return 0;
                }
            } else if ((this->scenario_mode == ScenarioModeVictory) &&
                       (this->bottom_panel->curr_child == 0) &&
                       (this->victory_amount_input->field_6C != 0)) {
                this->bottom_panel->set_curr_child(this->victory_amount_input);
                return 0;
            }
            break;
        case 0x1B:
            this->command_cancel();
            return 0;
        case 0x2E:
            if (this->scenario_mode == ScenarioModeUnits) {
                RGE_Player* player = rge_base_game->get_player();
                RGE_Static_Object* object = player->selected_obj;
                if (object != 0) {
                    uchar draw_level;
                    if (object->sprite_list != 0) {
                        draw_level = object->sprite_list->get_lowest_draw_level();
                    } else if (object->sprite != 0) {
                        draw_level = object->sprite->get_lowest_draw_level();
                    } else {
                        draw_level = 0x14;
                    }
                    object->set_selected(1);
                    if (draw_level == 0) {
                        this->main_view->set_redraw(2);
                    }
                }
                return 1;
            }
            break;
        default:
            break;
        }
    }

    return 0;
}

long TRIBE_Screen_Sed::action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4)
{
    int i;
    int map_size;
    int center;
    long line;
    long x2;
    long x1;
    long y1;
    long y2;
    char random_val[28];
    float f1;
    float f2;
    RGE_Player* player;
    char* panel_name;
    unsigned char* scan;
    unsigned char* lit;
    unsigned char ch;
    int cmp_value;

    if (param_1 == 0) {
        return 0;
    }

    if (param_1 != (TPanel*)this->main_view) {
        {
        RGE_Static_Object* selected_object = this->SelectedObject;
        if (selected_object != 0) {
            rge_base_game->get_player()->select_one_object(selected_object, 0);
        }
    }
        {
        RGE_Static_Object* selected_object = this->DestinationObject;
        if (selected_object != 0) {
            rge_base_game->get_player()->select_one_object(selected_object, 0);
        }
    }
    }

    if (param_2 == 0) {
        if (param_1 == (TPanel*)this->random_seed_input ||
            param_1 == (TPanel*)this->player_inven_input[0] ||
            param_1 == (TPanel*)this->player_inven_input[1] ||
            param_1 == (TPanel*)this->player_inven_input[2] ||
            param_1 == (TPanel*)this->player_inven_input[3] ||
            param_1 == (TPanel*)this->player_inven_input[4] ||
            param_1 == (TPanel*)this->player_setting_label[0] ||
            param_1 == (TPanel*)this->victory_condition_explore ||
            param_1 == (TPanel*)this->victory_condition_ruins ||
            param_1 == (TPanel*)this->victory_condition_artifacts ||
            param_1 == (TPanel*)this->victory_condition_discoveries ||
            param_1 == (TPanel*)this->victory_condition_gold ||
            param_1 == (TPanel*)this->victory_amount_input ||
            param_1 == (TPanel*)this->message_input) {
            this->need_to_save_flag = 1;
        }
    }

    if (param_1 == (TPanel*)this->main_view) {
        if (param_2 == 0x10) {
            rge_base_game->get_player()->unselect_object();
            if (this->SelectRegionFlag == SELECT_OBJECT) this->SelectedObject = (RGE_Static_Object*)param_3;
            if (this->SelectRegionFlag == SELECT_DEST_OBJECT) this->DestinationObject = (RGE_Static_Object*)param_3;
            {
        RGE_Static_Object* selected_object = this->SelectedObject;
        if (selected_object != 0) {
            rge_base_game->get_player()->select_one_object(selected_object, 0);
        }
    }
            {
        RGE_Static_Object* selected_object = this->DestinationObject;
        if (selected_object != 0) {
            rge_base_game->get_player()->select_one_object(selected_object, 0);
        }
    }
            rge_base_game->set_game_mode(0, 0);
            return 1;
        }
        if (param_2 == 0x11 && rge_base_game->game_mode == 0x11) {
            rge_base_game->set_game_mode(0, 0);
        }
    }

    if (param_2 == 1) {
        for (i = 0; i < 10; i++) {
            if (param_1 == this->scenario_mode_button[i]) {
                this->set_scenario_mode((ScenarioMode)(i + ScenarioModeMap));
                return 1;
            }
        }
        if (param_1 == this->menu_button) {
            this->command_menu();
            return 1;
        }
        if (param_1 == this->help_button) {
            this->setup_popup_help();
            return 1;
        }
    } else {
        for (i = 0; i < 10; i++) {
            if (param_1 == this->scenario_mode_button[i]) return 1;
        }
        if (param_1 == this->menu_button || param_1 == this->help_button) return 1;
    }

    if (param_1->panelName() != 0 && strcmp(param_1->panelName(), s_OKDialog) == 0) {
            if (param_2 == 0) {
                panel_system.destroyPanel(s_OKDialog);
                this->set_scenario_mode(ScenarioModePlayers);
            }
            return 1;
    }

    switch (this->scenario_mode) {
    case ScenarioModeMessages:
        if (this->valid_save_spot_flag != 0) this->need_to_save_flag = 1;
        if (param_2 == 1) {
            line = this->current_message;
            this->world->scenario->Set_message(this->message_input->get_input_buffer(), line);
            for (i = 0; i < 5; i++) if (param_1 == this->message_button[i]) { this->current_message = i; break; }
            this->message_input->set_text(this->world->scenario->Get_message(this->current_message));
            switch (this->current_message) {
            case 0: ((TPanel*)this->message_input)->set_help_info(0x7770, -1); break;
            case 1: ((TPanel*)this->message_input)->set_help_info(0x7771, -1); break;
            case 2: ((TPanel*)this->message_input)->set_help_info(0x7772, -1); break;
            case 3: ((TPanel*)this->message_input)->set_help_info(0x7773, -1); break;
            case 4: ((TPanel*)this->message_input)->set_help_info(0x7774, -1); break;
            }
        }
        break;

    case ScenarioModeVictory:
        if (this->valid_save_spot_flag != 0) this->need_to_save_flag = 1;
        if ((param_2 == 0 || param_2 == 1) && param_1 == this->victory_player_list) {
            this->save_victory_cond_in_scenario(this->CurrentVictory);
            this->activate_victory_panel(0);
            this->activate_victory_proper_fields(0, 0);
            line = this->victory_player_list->get_line();
            this->player_num = (short)line + 1;
            this->world->scenario->SetSPWhich(this->player_num - 1);
            this->CurrentVictory = 0;
            this->load_victory_cond_from_scenario(0);
            this->activate_victory_panel(1);
            line = this->victory_drop_down->get_line();
            this->activate_victory_proper_fields(line, 1);
        }
        if (param_2 == 0 && param_1 == this->victory_amount_input) this->bottom_panel->set_curr_child(0);
        if (param_2 == 2 && param_1 == this->victory_drop_down) { line = this->victory_drop_down->get_line(); this->activate_victory_proper_fields(line, 1); }
        if (param_2 == 1) {
            if (param_1 != this->victory_amount_input) {
                line = this->victory_drop_down->get_line();
                if (param_1 == this->victory_drop_down) { rge_base_game->set_game_mode(0, 0); this->DestinationObject = 0; this->SelectedObject = 0; rge_base_game->get_player()->unselect_object(); }
                if (line == 2) { this->DestinationObject = 0; rge_base_game->get_player()->unselect_object(); }
                // BINARY NOTE: both object-selection arms use redraw mode 0x10.
                if (param_1 == this->victory_button_set_object) { this->SelectRegionFlag = SELECT_OBJECT; rge_base_game->set_game_mode(0x10, 0); rge_base_game->get_player()->unselect_object(); {
        RGE_Static_Object* selected_object = this->DestinationObject;
        if (selected_object != 0) {
            rge_base_game->get_player()->select_one_object(selected_object, 0);
        }
    } }
                else if (param_1 == this->victory_button_set_destination && line != 1) { this->SelectRegionFlag = SELECT_AREA; rge_base_game->get_player()->unselect_object(); {
        RGE_Static_Object* selected_object = this->SelectedObject;
        if (selected_object != 0) {
            rge_base_game->get_player()->select_one_object(selected_object, 0);
        }
    } rge_base_game->set_game_mode(0, 0); return 1; }
                else if (param_1 == this->victory_button_set_destination) { this->SelectRegionFlag = SELECT_DEST_OBJECT; rge_base_game->set_game_mode(0x10, 0); rge_base_game->get_player()->unselect_object(); {
        RGE_Static_Object* selected_object = this->SelectedObject;
        if (selected_object != 0) {
            rge_base_game->get_player()->select_one_object(selected_object, 0);
        }
    } }
                else if (param_1 == this->victory_button_go_to_dest && line != 1) {
                    this->main_view->get_selection_area(&y1, &y2, &x1, (long*)random_val, 1);
                    f1 = (float)x1;
                    f2 = (float)*(long*)random_val;
                    this->px1 = (float)y1;
                    this->py1 = (float)y2;
                    this->SelectRegionFlag = SELECT_OFF;
                    this->px2 = f1;
                    this->py2 = f2;
                    if (f1 != -1.0f) {
                        f1 = f1 - (f1 - (float)y1) * 0.5f;
                        f2 = f2 - (f2 - (float)y2) * 0.5f;
                        player = rge_base_game->get_player();
                        player->set_view_loc(f1, f2);
                        rge_base_game->get_player()->set_map_loc((short)f1, (short)f2);
                    }
                } else {
                    if (param_1 == this->victory_drop_down) { line = this->victory_drop_down->get_line(); this->activate_victory_proper_fields(line, 0); }
                    for (i = 0; i < 12; i++) {
                        if (param_1 == this->victory_button[i] && this->CurrentVictory != i) {
                            line = this->victory_drop_down->get_line();
                            this->activate_victory_proper_fields(line, 0);
                            this->save_victory_cond_in_scenario(this->CurrentVictory);
                            this->activate_victory_panel(0);
                            rge_base_game->get_player()->unselect_object();
                            this->CurrentVictory = i;
                            this->load_victory_cond_from_scenario(i);
                            this->activate_victory_panel(1);
                            line = this->victory_drop_down->get_line();
                            this->activate_victory_proper_fields(line, 1);
                            {
        RGE_Static_Object* selected_object = this->SelectedObject;
        if (selected_object != 0) {
            rge_base_game->get_player()->select_one_object(selected_object, 0);
        }
    }
                            {
        RGE_Static_Object* selected_object = this->DestinationObject;
        if (selected_object != 0) {
            rge_base_game->get_player()->select_one_object(selected_object, 0);
        }
    }
                        }
                    }
                }
            }
            return 1;
        }
        break;

    case ScenarioModeMap:
        if (this->valid_save_spot_flag != 0) this->need_to_save_flag = 1;
        if (param_2 == 1) {
            for (i = 0; i < 3; i++) {
                if (param_1 == this->map_type_button[i]) {
                    this->set_map_type((MapType)(i + MapTypeBlank), 1);
                    return 1;
                }
            }
            if (param_1 == this->generate_map_button) {
                this->map_generating_text->set_active(1);
                this->set_redraw(2);
                InvalidateRect(rge_base_game->prog_window, 0, 0);
                rge_base_game->draw_window();
                i = this->map_size_drop->currentLineNumber();
                f1 = (float)this->map_style_drop->currentLineNumber();
                switch (i) {
                case 0: map_size = 0x48; break;
                case 1: map_size = 0x60; break;
                case 2: map_size = 0x78; break;
                case 3: map_size = 0x90; break;
                case 4: map_size = 0xC8; break;
                case 5: map_size = 0xFA; break;
                default: map_size = i; break;
                }
                line = this->player_number_list->get_line();
                if (this->map_type == MapTypeBlank) {
                    switch (this->default_terrain_drop->currentLineNumber()) {
                    case 0:
                        this->world->map->clear_map(this->world->players[0], this->world, 0, map_size, map_size);
                        break;
                    case 1:
                        this->world->map->clear_map(this->world->players[0], this->world, 6, map_size, map_size);
                        break;
                    case 2:
                        this->world->map->clear_map(this->world->players[0], this->world, 10, map_size, map_size);
                        break;
                    case 3:
                        this->world->map->clear_map(this->world->players[0], this->world, 1, map_size, map_size);
                        break;
                    case 4:
                        this->world->map->clear_map(this->world->players[0], this->world, 13, map_size, map_size);
                        break;
                    case 5:
                        this->world->map->clear_map(this->world->players[0], this->world, 20, map_size, map_size);
                        break;
                    case 6:
                        this->world->map->clear_map(this->world->players[0], this->world, 4, map_size, map_size);
                        break;
                    case 7:
                        this->world->map->clear_map(this->world->players[0], this->world, 19, map_size, map_size);
                        break;
                    case 8:
                        this->world->map->clear_map(this->world->players[0], this->world, 22, map_size, map_size);
                        break;
                    }
                } else {
                    if (this->map_type == MapTypeSeed) {
                        rge_base_game->random_map_seed = atoi(this->random_seed_input->currentLine());
                    } else {
                        rge_base_game->random_map_seed = -1;
                    }
                    for (i = 0; i < 9; i++) this->world->players[i]->reset_selected();
                    this->world->new_random_map((float)map_size, (float)map_size, f1, line + 1);
                    rge_base_game->random_map_seed = *(int*)(random_val + 4);
                    itoa(rge_base_game->save_random_map_seed, random_val, 10);
                    this->random_seed_used_text->set_text(random_val);
                    debug_rand(s_C__msdev_work_age1_x1_scr_sed_cp, 0xB58);
                }
                center = map_size / 2;
                for (i = 0; i < 8; i++) {
                    this->world->players[i]->set_map_loc((short)center, (short)center);
                    this->world->players[i]->set_view_loc((float)center, (float)center);
                }
                for (i = 0; i < 8; i++) {
                    this->world->players[i]->tile_list.del_list();
                    this->world->players[i]->set_map_visible();
                }
                this->set_panel_info();
                this->map_generating_text->set_active(0);
                return 1;
            }
        }
        break;

    case ScenarioModeTerrain:
        if (this->valid_save_spot_flag != 0) this->need_to_save_flag = 1;
        if (param_2 == 2 || param_2 == 1) {
            if (param_1 == this->paint_terrain_list) {
                i = ((TTextPanel*)this->paint_terrain_list)->currentLineNumber();
                this->set_terrain((short)i);
                this->brush_size_button[0]->set_active(1);
                return 1;
            } else if (param_1 == this->paint_elevation_list) {
                i = ((TTextPanel*)this->paint_elevation_list)->currentLineNumber();
                this->set_elevation((short)i);
                return 1;
            } else if (param_2 == 1) {
                if (this->valid_save_spot_flag != 0) this->need_to_save_flag = 1;
                for (i = 0; i < 5; i++) {
                    if (param_1 == this->brush_size_button[i]) { this->set_brush_size((BrushSize)(i + BrushSizeVerySmall)); return 1; }
                }
                for (i = 0; i < 3; i++) {
                    if (param_1 == this->paint_type_button[i]) { this->set_paint_type((PaintType)(i + PaintTypeTerrain), 1); return 1; }
                }
            }
        }
        break;

    case ScenarioModePlayers:
        if (this->valid_save_spot_flag != 0) this->need_to_save_flag = 1;
        if (param_2 == 0) {
            for (i = 0; i < 5; i++) if (param_1 == this->player_inven_input[i]) { this->bottom_panel->set_curr_child(0); break; }
            if (this->valid_save_spot_flag != 0) this->need_to_save_flag = 1;
            if (param_1 == this->player_advance_civilization_drop) {
                if (this->valid_save_spot_flag != 0) this->need_to_save_flag = 1;
                i = this->player_advance_civilization_drop->currentLineNumber();
                this->world->scenario->SetPlayerAge(this->player_num - 1, i);
            }
            if (param_1 == this->player_list) {
                line = this->player_list->get_line();
                this->set_player((short)line + 1, 1, 1);
                line = this->player_list->get_line();
                i = this->world->scenario->GetPlayerAge(line);
                this->player_advance_civilization_drop->setCurrentLineNumber(i);
            }
            if (param_1 == this->player_number_list) {
                this->set_player(this->player_num, 1, 0);
                this->SavePlayerActiveStatus();
                this->set_player(this->player_num, 0, 1);
            }
        }
        if (param_2 == 1 && param_1 == this->player_advance_civilization_drop) {
            i = this->player_advance_civilization_drop->currentLineNumber();
            this->world->scenario->SetPlayerAge(this->player_num - 1, i);
        }
        break;

    case ScenarioModeUnits:
        if (this->valid_save_spot_flag != 0) this->need_to_save_flag = 1;
        if (param_2 == 0) {
            if (this->valid_save_spot_flag != 0) this->need_to_save_flag = 1;
            if (param_1 == this->unit_player_list) {
                line = this->unit_player_list->get_line();
                this->set_unit_player((short)line);
                line = this->unit_player_list->get_line();
                if (line == 0) {
                    // BINARY NOTE: the shipped path redraws with status 3.
                    rge_base_game->set_game_mode(rge_base_game->game_mode, 3);
                } else {
                    // BINARY NOTE: status 4 precedes master-panel setup.
                    rge_base_game->set_game_mode(rge_base_game->game_mode, 4);
                    // BINARY NOTE: master ownership is world->players[id].
                    RGE_Master_Static_Object* player_master;
                    TRIBE_Player* player_tribe;
                    short master_id = rge_base_game->master_obj_id;
                    if (rge_base_game->master_obj_id == -1 || rge_base_game->get_player() == 0) {
                        player_tribe = 0;
                        player_master = 0;
                    } else {
                        player_master = this->world->players[rge_base_game->get_player()->id]->master_objects[master_id];
                        player_tribe = (TRIBE_Player*)rge_base_game->get_player();
                    }
                    this->object_panel->set_master_info(player_master, player_tribe);
                    this->set_paint_object_mode();
                this->object_panel->set_redraw(2);
                    return 1;
                }
            }
        }
        if (param_2 == 2 || param_2 == 1) {
            if (param_1 == this->unit_list) {
                RGE_Master_Static_Object* list_master;
                TRIBE_Player* list_tribe;
                i = ((TTextPanel*)this->unit_list)->currentLineNumber();
                this->set_unit((short)i);
                if (rge_base_game->game_mode != 8 && rge_base_game->game_mode != 0x15) this->unit_mode_select[0]->set_radio_button();
                if (rge_base_game->master_obj_id == -1 || rge_base_game->get_player() == 0) { list_tribe = 0; list_master = 0; }
                else {
                    short master_id = rge_base_game->master_obj_id;
                    list_master = this->world->players[rge_base_game->get_player()->id]->master_objects[master_id];
                    list_tribe = (TRIBE_Player*)rge_base_game->get_player();
                }
                this->object_panel->set_master_info(list_master, list_tribe);
                this->set_paint_object_mode();
                // BINARY NOTE: the list path redraws with flag 1, not 2.
                this->object_panel->set_redraw(1);
                return 1;
            }
            if (param_2 == 1) {
                if (param_1 == this->unit_mode_select[0]) this->set_paint_object_mode();
                else if (param_1 == this->unit_mode_select[1]) { rge_base_game->get_player()->unselect_object(); rge_base_game->set_game_mode(0xE, 0); }
                else if (param_1 == this->unit_mode_select[2]) rge_base_game->set_game_mode(0xF, 0);
                else if (param_1 == this->unit_mode_select[3]) rge_base_game->set_game_mode(0x14, 0);
            }
        }
        break;

    case ScenarioModeVictoryMulti:
        if (this->valid_save_spot_flag != 0) this->need_to_save_flag = 1;
        if (param_2 == 1) {
            for (i = 0; i < 5; i++) {
                if (param_1 == this->victory_cond_type[i]) {
                    this->set_mp_victory_type((VictoryType)(i + VictoryTypeStandard), 1);
                    if (i != 4) { this->world->scenario->Set_Multi_Conquest(1); this->victory_cond_on[0]->set_state(1); }
                    return 1;
                }
            }
        }
        break;

    case ScenarioModeDiplomacy:
        if (this->valid_save_spot_flag != 0) this->need_to_save_flag = 1;
        if (param_2 == 0 || param_2 == 1) {
            if (param_1 == this->Diplomacy_player_list) {
                this->Diplomacy_friend_box[this->player_num - 1][0]->set_active(1);
                this->Diplomacy_friend_box[this->player_num - 1][1]->set_active(1);
                this->Diplomacy_friend_box[this->player_num - 1][2]->set_active(1);
                this->Diplomacy_AlliedVictory[this->player_num - 1]->set_active(0);
                line = this->Diplomacy_player_list->get_line();
                this->player_num = (short)line + 1;
                this->Diplomacy_friend_box[this->player_num - 1][0]->set_active(0);
                this->Diplomacy_friend_box[this->player_num - 1][1]->set_active(0);
                this->Diplomacy_friend_box[this->player_num - 1][2]->set_active(0);
                this->Diplomacy_AlliedVictory[this->player_num - 1]->set_active(1);
                line = this->Diplomacy_player_list->get_line();
                this->load_diplomacy_from_scenario(line);
            }
            if (param_2 == 1) { this->save_diplomacy_in_scenario(this->player_num - 1); return 1; }
        }
        break;

    case ScenarioModeOptions:
        if (this->valid_save_spot_flag != 0) this->need_to_save_flag = 1;
        if (param_2 == 1) {
            this->SaveDisabledItemsInScenario();
            this->LoadDisabledItemsFromScenario();
            if (param_1 == this->options_button[0]) {
                i = this->options_button[0]->get_state();
                this->world->scenario->SetScenarioOption(2, i);
            }
        }
        break;

    }

    if (param_1->panelName() != 0 && strcmp(param_1->panelName(), s_QuitSaveDialog) == 0) {
            panel_system.setCurrentPanel(s_Scenario_Editor_Screen, 0);
            panel_system.destroyPanel(s_QuitSaveDialog);
            if (param_2 == 0) this->command_save((unsigned char)param_2, 1);
            else if (param_2 == 1) {
                if (((TRIBE_Game*)rge_base_game)->start_menu() == 0) rge_base_game->close();
                else panel_system.destroyPanel(s_Scenario_Editor_Screen);
            }
            return 1;
    }

    if (param_1->panelName() != 0 && strcmp(param_1->panelName(), s_OpenSaveDialog) == 0) {
            panel_system.setCurrentPanel(s_Scenario_Editor_Screen, 0);
            panel_system.destroyPanel(s_OpenSaveDialog);
            if (param_2 == 0) this->command_save((unsigned char)param_2, 2);
            else if (param_2 == 1) {
                TRIBE_Screen_Sed_Open* open = new TRIBE_Screen_Sed_Open;
                (void)open;
                panel_system.setCurrentPanel(s_Scenario_Editor_Open, 0);
            }
            return 1;
    }

    if (param_1->panelName() != 0 && strcmp(param_1->panelName(), s_NewSaveDialog) == 0) {
            panel_system.setCurrentPanel(s_Scenario_Editor_Screen, 0);
            panel_system.destroyPanel(s_NewSaveDialog);
            if (param_2 == 0) this->command_save((unsigned char)param_2, 3);
            else if (param_2 == 1) ((TRIBE_Game*)rge_base_game)->start_scenario_editor(0, 0);
            return 1;
    }

    return 0;
}

void TRIBE_Screen_Sed::draw()
{
    tagRECT rect_local;

    this->TEasy_Panel::draw();

    if (use_bevels != 0 && main_view != 0) {
        if (stored_rect.left == clip_rect.left &&
            stored_rect.top == clip_rect.top &&
            stored_rect.right == clip_rect.right &&
            stored_rect.bottom == clip_rect.bottom)
        {
            this->draw_setup(0);

            unsigned char* locked = render_area->Lock("scr_sed::draw", 1);
            if (locked) {
                tagRECT* mrect = &main_view->stored_rect;
                rect_local = *mrect;

                render_area->DrawBevel3(0, 0, pnl_wid - 1, rect_local.top - 1,
                    bevel_color1, bevel_color2, bevel_color3, bevel_color4,
                    bevel_color5, bevel_color6);

                render_area->DrawBevel3(0, rect_local.bottom + 1,
                    pnl_wid - 1, pnl_hgt - 1,
                    bevel_color1, bevel_color2, bevel_color3, bevel_color4,
                    bevel_color5, bevel_color6);

                render_area->Unlock("scr_sed::draw");
            }

            this->draw_finish();
        }
    }
}

void TRIBE_Screen_Sed::command_cancel() {
    ((RGE_Player*)rge_base_game->get_player())->unselect_object();
    ((RGE_Player*)rge_base_game->get_player())->unselect_area();
}

int TRIBE_Screen_Sed::command_menu()
{
    TRIBE_Dialog_Sed_Menu* dlg = new TRIBE_Dialog_Sed_Menu(this);
    if (dlg != 0 && dlg->field_D8 != 0) {
        dlg->activate(1);
        return 0;
    }
    return 1;
}

void TRIBE_Screen_Sed::command_new(void) {
    if (this->need_to_save()) {
        this->popupYesNoCancelDialog(0x2447, s_NewSaveDialog, 0x1C2, 100);
        return;
    }
    ((TRIBE_Game*)rge_base_game)->start_scenario_editor((char*)0, 0);
}

int TRIBE_Screen_Sed::command_new_map(char* scenario_name_in, int is_multi_player_in,
                                      int random_seed_in, int width, int height,
                                      int display_in)
{
    int tribe;
    int result;
    RGE_Player_Info player_info;
    RGE_Map_Gen_Info map_info;

    this->need_to_save_flag = 0;
    if (rge_base_game->world == 0) {
        if (display_in != 0) {
            ((TRIBE_Game*)rge_base_game)->show_status_message(0x44d, 0, -1);
        }
        if (((TRIBE_Game*)rge_base_game)->load_game_data() == 0) {
            if (display_in != 0) {
                ((TRIBE_Game*)rge_base_game)->close_status_message();
            }
            return 0;
        }
    }

    this->world = rge_base_game->world;
    if (display_in != 0) {
        if (scenario_name_in == 0) {
            ((TRIBE_Game*)rge_base_game)->show_status_message(0x44e, 0, -1);
        } else {
            ((TRIBE_Game*)rge_base_game)->show_status_message(0x44f, 0, -1);
        }
    }

    player_info.scenario = scenario_name_in;
    player_info.map_info = (RGE_Map_Gen_Info*)&map_info.land;
    player_info.map_width = (short)width;
    player_info.map_height = (short)height;
    player_info.ai_info = 0;
    player_info.player_num = 8;
    tribe = 0;

    int i;
    for (i = 0; i < 8; i++) {
        tribe++;
        if (tribe >= this->world->player_count) {
            tribe = 1;
        }
        this->set_string(player_info.name[i], 0x2865 + i, 0x41);
        player_info.type[i] = 0;
        player_info.tribe[i] = (char)tribe;
        player_info.color[i] = -1;
        player_info.player_id_hash[i] = i;
    }
    player_info.player_id_hash[i] = i;
    map_info.land.clump_num = 0;

    if (rge_base_game->sound_system != 0) {
        ((Sound_Driver*)rge_base_game->sound_system)->mute = 1;
    }
    result = this->world->new_scenario(&player_info, random_seed_in) & 0xff;
    if (result != 0 && this->world->player_num < 8) {
        result = 0;
        this->world->del_game_info();
    }
    if (rge_base_game->sound_system != 0) {
        ((Sound_Driver*)rge_base_game->sound_system)->mute = 0;
    }

    if (result != 0 && this->player_number_list != 0) {
        i = 0;
        while (i < 8) {
            if (this->world->scenario->Get_player_Active(i) == 0) {
                break;
            }
            i++;
        }
        if (i < 8 && i > 0) {
            this->player_number_list->set_line(i - 1);
        }
        this->SavePlayerActiveStatus();
    }
    return result;
}

void TRIBE_Screen_Sed::command_open(void)
{
    if (this->need_to_save()) {
        this->popupYesNoCancelDialog(0x2447, s_OpenSaveDialog, 0x1C2, 100);
        return;
    }

    TRIBE_Screen_Sed_Open* open = new TRIBE_Screen_Sed_Open();
    panel_system.setCurrentPanel(s_Scenario_Editor_Open, 0);
}

void TRIBE_Screen_Sed::command_outline(void)
{
    unsigned char* game = (unsigned char*)rge_base_game;
    switch (game[0x50]) {
    case 0:
    case 3:
        game[0x50] = 2;
        return;
    case 2:
        game[0x50] = 1;
        return;
    case 1:
        game[0x50] = 0;
        return;
    }
}

void TRIBE_Screen_Sed::command_player(int player) {
    rge_base_game->set_player(player);
}

void TRIBE_Screen_Sed::command_quit() {
    if (need_to_save()) {
        popupYesNoCancelDialog(0x2447, (char*)0x586D18, 0x1C2, 0x64);
        return;
    }
    if (!((TRIBE_Game*)rge_base_game)->start_menu()) {
        ((TRIBE_Game*)rge_base_game)->close();
        return;
    }
    panel_system.destroyPanel((char*)0x584414);
}

void TRIBE_Screen_Sed::command_save(unsigned char closeMenu, unsigned char postAction)
{
    char temp_name[260];

    this->set_scenario_mode(ScenarioModeSave);
    this->world->scenario->Save_victory_conditions_into_players(1);
    if (((RGE_Scenario*)this->world->scenario)->active_player_count() < 1) {
        panel_system.destroyPanel((char*)0x005843CC);
        this->popupOKDialog(0x2742, 0, 0x1c2, 100);
    } else if (((RGE_Scenario*)this->world->scenario)->any_player_count() < 1) {
        panel_system.destroyPanel((char*)0x005843CC);
        this->popupOKDialog(0x2743, 0, 0x1c2, 100);
    } else {
        char* name = ((RGE_Scenario*)this->world->scenario)->Get_scenario_name();
        if (*name == 0) {
            this->command_save_as(postAction);
        } else {
            ((TRIBE_Game*)rge_base_game)->show_status_message(0x450, 0, -1);
            if (closeMenu != 0) {
                panel_system.destroyPanel((char*)0x005843CC);
            }
            if (this->world->save(name) == 0) {
                ((TRIBE_Game*)rge_base_game)->close_status_message();
                this->popupOKDialog(0x963, 0, 0x1c2, 100);
            } else {
                ((TRIBE_Game*)rge_base_game)->close_status_message();
                sprintf(temp_name, (char*)0x00586D38, rge_base_game->registry->RegGetInt(0, (char*)0x0057FA58));
                if (strcmp(name, temp_name) != 0) {
                    this->need_to_save_flag = 0;
                }
                if (postAction == 1) {
                    if (((TRIBE_Game*)rge_base_game)->start_menu() == 0) {
                        ((TRIBE_Game*)rge_base_game)->close();
                    } else {
                        panel_system.destroyPanel((char*)0x00584414);
                    }
                } else if (postAction == 2) {
                    TRIBE_Screen_Sed_Open* p = new TRIBE_Screen_Sed_Open;
                    panel_system.setCurrentPanel((char*)0x005843FC, 0);
                } else if (postAction == 3) {
                    ((TRIBE_Game*)rge_base_game)->start_scenario_editor(0, 0);
                }
            }
        }
    }
}

// BINARY NOTE: The scenario buffer retains the shipped malformed-name behavior.

void TRIBE_Screen_Sed::command_save_as(unsigned char post_action)
{
    char scenario_name[224];

    this->set_scenario_mode(ScenarioModeSave);
    static_cast<T_Scenario*>(this->world->scenario)->Save_victory_conditions_into_players(1);
    if (this->world->scenario->active_player_count() < 1) {
        static_cast<TEasy_Panel*>(this)->popupOKDialog(0x2742, (char*)0, 0x1C2, 100);
    } else if (this->world->scenario->any_player_count() < 1) {
        static_cast<TEasy_Panel*>(this)->popupOKDialog(0x2743, (char*)0, 0x1C2, 100);
    } else {
        scenario_name[0] = 0;
        new TribeSaveGameScreen(TribeSaveGameScreen::SaveScenarioEdit,
                                scenario_name, post_action);
        panel_system.setCurrentPanel(s_Save_Game_Screen, 0);
        panel_system.destroyPanel(s_Scenario_Menu_Dialog);
    }
    return;
}

char* TRIBE_Screen_Sed::scenario_get_default_name() {
    char temp_name[260];
    char* name;

    name = this->world->scenario->Get_scenario_name();
    if (name == 0 || name[0] == 0) {
        int file_num = rge_base_game->registry->RegGetInt(0, (char*)"Game File Number");
        sprintf(temp_name, "default%d.scx", file_num);
        this->world->scenario->Set_scenario_name(temp_name);
    }
    return this->world->scenario->Get_scenario_name();
}

void TRIBE_Screen_Sed::command_quick_save(void) {
    this->scenario_get_default_name();
    this->command_save(0, 0);
}

char* TRIBE_Screen_Sed::scenario_save_defaulted() {
    this->set_scenario_mode(ScenarioModeSave);
    this->world->scenario->Save_victory_conditions_into_players(1);
    if (((RGE_Scenario*)this->world->scenario)->active_player_count() < 1) {
        this->popupOKDialog(0x2742, 0, 0x1c2, 100);
        return 0;
    }
    if (((RGE_Scenario*)this->world->scenario)->any_player_count() < 1) {
        this->popupOKDialog(0x2743, 0, 0x1c2, 100);
        return 0;
    }

    ((TRIBE_Game*)rge_base_game)->show_status_message(0x450, 0, -1);
    sprintf(DAT_0086bad8, "default%d.scx",
            rge_base_game->registry->RegGetInt(0, (char*)"Game File Number"));
    if (this->world->save(DAT_0086bad8) == 0) {
        ((TRIBE_Game*)rge_base_game)->close_status_message();
        this->popupOKDialog(0x963, 0, 0x1c2, 100);
        return 0;
    }

    sprintf(DAT_0086bad8, "default%d",
            rge_base_game->registry->RegGetInt(0, (char*)"Game File Number"));
    return DAT_0086bad8;
}

unsigned char TRIBE_Screen_Sed::need_to_save() { return this->need_to_save_flag; }

void TRIBE_Screen_Sed::set_focus(int v) {
    this->TScreenPanel::set_focus(v);
    if (this->have_focus) {
        rge_base_game->set_windows_mouse(0);
    } else {
        rge_base_game->set_windows_mouse(1);
    }
}
