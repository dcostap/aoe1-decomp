
#include "../include/scr_sed.h"

// Shared declarations are consumed privately by this source owner. The
// screen header owns only TRIBE_Screen_Sed and its local list record.
#include "../include/pnl_msg.h"
#include "../include/pnl_btn.h"
#include "../include/Pnl_txt.h"
#include "../include/Pnl_inp.h"
#include "../include/pnl_edit.h"
#include "../include/pnl_drop.h"
#include "../include/pnl_lst.h"
#include "../include/Pnl_scbr.h"
#include "../include/basegame.h"
#include "../include/main.h"
#include "../include/tribegam.h"
#include "../include/world.h"
#include "../include/world_info.h"
#include "../include/tworld.h"
#include "../include/player.h"
#include "../include/tplayer.h"
#include "../include/scenario.h"
#include "../include/tscenaro.h"
#include "../include/map.h"
#include "../include/m_s_obj.h"
#include "../include/stat_obj.h"
#include "../include/sprite.h"
#include "../include/asp_list.h"
#include "../include/registry.h"
#include "../include/sounddrv.h"
#include "../include/tech.h"
#include "../include/diam_map.h"
#include "../include/vw_dimap.h"
#include "../include/vw_main.h"
#include "../include/spnl_obj.h"
#include "../include/dlg_sedm.h"
#include "../include/scr_sedo.h"
#include "../include/scr_save.h"
#include "../include/rge_base_game_global.h"

#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char scenario_default_file_name[260];

extern char s_space[];
extern char s_percent_d[];
extern char s_btnbldg_d_shp[];
extern char s_btnunit_shp[];
extern char s_0[];
extern char s_angle_d_star[];
extern char s_percent_d_star[];
extern char s_angle_d[];
extern char s_300[];
extern char s_400[];
extern char s_500[];
extern char s_600[];
extern char s_700[];
extern char s_900[];
extern char s_1200[];
extern char s_1500[];
extern char s_1800[];
extern char s_2100[];
extern char s_2400[];
extern char s_2700[];
extern char s_3000[];
extern char s_800[];
extern char s_empty[];
extern char s_592A40[];
extern char s_OKDialog[];
extern char s_QuitSaveDialog[];
extern char s_OpenSaveDialog[];
extern char s_NewSaveDialog[];
extern char s_Save_Game_Screen[];
extern char s_Scenario_Menu_Dialog[];
extern char s_Scenario_Editor_Screen[];
extern char s_Scenario_Editor_Open[];
extern char s_C__msdev_work_age1_x1_scr_sed_cp[];

extern int View_Grid_Mode;
extern "C" __declspec(dllimport) int __stdcall CompareStringA(
    unsigned long, unsigned long, const char*, int, const char*, int);

int __cdecl TRIBE_Screen_Sed_unit_list_compare(const void*, const void*);

TRIBE_Screen_Sed::TRIBE_Screen_Sed(char* file, int mode) : TScreenPanel("Scenario Editor Screen")
{
    char name[260];
    char temp_name[260];
    this->is_multi_player = 0;
    this->scenario_mode = ScenarioModeNone;
    this->map_type = MapTypeNone;
    this->mp_victory_type = VictoryTypeConquestValue;
    this->brush_size = BrushSizeNone;
    this->paint_type = PaintTypeNone;
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
        this->error_code = 1;
        return;
    }
    int game_file_number = rge_base_game->registry->RegGetInt(0, "Game File Number");
    sprintf(temp_name, "default%d.scx", game_file_number);
    if (file && strcmp(file, temp_name) == 0)
        this->need_to_save_flag = 1;
    if (!this->TScreenPanel::setup(rge_base_game->draw_area,
                                   "scr5", 0xC387, 1)) {
        this->error_code = 1;
        return;
    }
    this->TEasy_Panel::setup_shadow_area(0);
    this->main_view = new TRIBE_Main_View;
    if (this->main_view == 0 || this->main_view->error_code != 0) {
        this->error_code = 1;
        return;
    }
    if (!this->main_view->RGE_View::setup(this->render_area, this,
                                          0, 0, 0, 0, 0xA1, 0,
                                          "bordline")) {
        this->error_code = 1;
        return;
    }
    this->map_view = new RGE_Diamond_Map_View;
    if (this->map_view == 0 || this->map_view->error_code != 0) {
        this->error_code = 1;
        return;
    }
    if (!this->map_view->RGE_Diamond_Map::setup(
            this->render_area, this, 0, 0, 0, 0, 0xA1, 0,
            rge_base_game->map_save_area)) {
        this->error_code = 1;
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
    if (this->message_panel == 0 || this->message_panel->error_code != 0) {
        this->error_code = 1;
        return;
    }
    if (!this->message_panel->setup(this->render_area, this->main_view,
                                    0, 0, 0, 0, 0)) {
        this->error_code = 1;
        return;
    }
    this->bottom_panel = new TPanel;
    if (this->bottom_panel == 0 || this->bottom_panel->error_code != 0) {
        this->error_code = 1;
        return;
    }
    if (!this->bottom_panel->setup(this->render_area, this,
                                   0, 0, 0, 0, 0)) {
        this->error_code = 1;
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
    this->set_map_type(static_cast<MapType>(1), 0);
    this->set_mp_victory_type(static_cast<VictoryType>(1), 0);
    this->set_brush_size(BrushSizeVerySmall);
    this->set_paint_type(static_cast<PaintType>(1), 0);
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
    this->get_string(string_id, buffer, 0x78);
    return this->create_button(panel, button, buffer, 0, 0, 0);
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
    int ok = this->TEasy_Panel::create_text(panel, text_panel, value, 0, 0, 0, 0, 10, 0, 0, 0);
    if (!ok) return 0;
    (*text_panel)->set_z_order(1, 0);
    (*text_panel)->set_active(0);
    return 1;
}

int TRIBE_Screen_Sed::create_text(TPanel* panel, TTextPanel** text_panel, char* text) {
    int ok = this->TEasy_Panel::create_text(panel, text_panel, text, 0, 0, 0, 0, 10, 0, 0, 0);
    if (!ok) return 0;
    (*text_panel)->set_z_order(1, 0);
    (*text_panel)->set_active(0);
    return 1;
}

int TRIBE_Screen_Sed::create_input(TPanel* param_1, TInputPanel** param_2,
                                   char* param_3, short param_4,
                                   TInputPanel::FormatType param_5) {
    if (this->TEasy_Panel::create_input(param_1, param_2, param_3, param_4, param_5, 0, 0, 0, 0, 10) == 0) {
        return 0;
    }
    (*param_2)->set_z_order(1, 0);
    (*param_2)->set_active(0);
    return 1;
}

int TRIBE_Screen_Sed::create_edit(TPanel* panel, TEditPanel** out_edit,
                                  char* text, short width,
                                  TEditPanel::FormatType format, int a6,
                                  int a7) {
    int result = this->TEasy_Panel::create_edit(panel, out_edit, text, width, format, 0, 0, 0, 0, 10, a6, a7);
    if (result == 0) return 0;
    (*out_edit)->set_z_order(1, 0);
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
    } else if (out == &this->victory_drop_down) {
        height = 0xB4;
    } else if (out == this->cinematic_input ||
               out == this->cinematic_input + 1 ||
               out == this->cinematic_input + 2 ||
               out == this->cinematic_input + 3 ||
               out == &this->default_terrain_drop ||
               out == &this->map_size_drop ||
               out == &this->map_style_drop) {
        height = 0xAA;
    } else if (out == &this->player_advance_civilization_drop ||
               out == &this->player_list ||
               out == &this->player_number_list ||
               out == &this->unit_player_list ||
               out == &this->victory_player_list ||
               out == &this->options_player_list ||
               out == &this->Diplomacy_player_list ||
               out == &this->victory_enemy_player_list) {
        height = 0x96;
    } else {
        height = 0x82;
    }

    if (this->TEasy_Panel::create_drop_down(parent, out, height, 100, 0, 0,
                                             height, 0x16, 10) == 0) {
        return 0;
    }

    (*out)->set_z_order(1, 0);
    (*out)->set_active(0);
    (*out)->empty_list();

    if (out == &this->map_size_drop) {
        (*out)->append_line(0x2973, 0);
        (*out)->append_line(0x2974, 0);
        (*out)->append_line(0x2975, 0);
        (*out)->append_line(0x2976, 0);
        (*out)->append_line(0x2977, 0);
        (*out)->append_line(0x2978, 0);
        (*out)->set_line(3);
    } else if (out == &this->map_style_drop) {
        (*out)->append_line(0x296A, 0);
        (*out)->append_line(0x296B, 0);
        (*out)->append_line(0x296C, 0);
        (*out)->append_line(0x296D, 0);
        (*out)->append_line(0x296E, 0);
        (*out)->append_line(0x296F, 0);
        (*out)->append_line(0x2970, 0);
        (*out)->append_line(0x2971, 0);
        (*out)->append_line(0x2972, 0);
        (*out)->set_line(3);
    } else if (out == &this->player_number_list ||
               out == &this->victory_enemy_player_list) {
        int i = 0;
        do {
            (*out)->append_line(i + 0x2877, 0);
            i++;
        } while (i < 8);
        (*out)->set_line(0);
    } else if (out == &this->victory_attribute_list) {
        (*out)->append_line(0x2882, 0x2B);
        (*out)->append_line(0x2883, 0x29);
        (*out)->append_line(0x2884, 0x2C);
        (*out)->append_line(0x2886, 0x28);
        (*out)->append_line(0x2887, 0x15);
        (*out)->append_line(0x2888, 0x14);
        (*out)->append_line(0x2889, 0x25);
        (*out)->set_line(0);
    } else if (out == &this->default_terrain_drop) {
        (*out)->append_line(0x297D, 0);
        (*out)->append_line(0x297E, 0);
        (*out)->append_line(0x297F, 0);
        (*out)->append_line(0x2980, 0);
        (*out)->append_line(0x2981, 0);
        (*out)->append_line(0x2982, 0);
        (*out)->append_line(0x2983, 0);
        (*out)->append_line(0x2984, 0);
        (*out)->append_line(0x2985, 0);
        (*out)->set_line(0);
    } else if (out == this->player_setting_drop) {
        (*out)->append_line(0x27E3, 0);
        (*out)->append_line(0x27E4, 0);
        (*out)->set_line(0);
    } else if (out == &this->victory_drop_down) {
        (*out)->append_line(0x2851, 0);
        (*out)->append_line(0x2852, 0);
        (*out)->append_line(0x2853, 0);
        (*out)->append_line(0x2854, 0);
        (*out)->append_line(0x2855, 0);
        (*out)->append_line(0x2856, 0);
        (*out)->append_line(0x2857, 0);
        (*out)->append_line(0x2858, 0);
        (*out)->append_line(0x2859, 0);
        (*out)->append_line(0x285A, 0);
        (*out)->append_line(0x285B, 0);
        (*out)->append_line(0x285C, 0);
        (*out)->append_line(0x285D, 0);
        (*out)->append_line(0x285E, 0);
        (*out)->append_line(0x285F, 0);
        (*out)->append_line(0x2860, 0);
        (*out)->append_line(0x2861, 0);
        (*out)->append_line(0x2862, 0);
        (*out)->append_line(0x284F, 0);
        (*out)->set_line(0);
    } else if (out == this->player_setting_drop + 1) {
        (*out)->append_line(0x27F7, 0);
        (*out)->append_line(0x27F8, 0);
        (*out)->append_line(0x27F9, 0);
        (*out)->append_line(0x27FA, 0);
        (*out)->append_line(0x27FB, 0);
        (*out)->append_line(0x27FC, 0);
        (*out)->append_line(0x27FD, 0);
        (*out)->append_line(0x27FE, 0);
        (*out)->append_line(0x27FF, 0);
        (*out)->append_line(0x2800, 0);
        (*out)->append_line(0x2801, 0);
        (*out)->append_line(0x2802, 0);
        (*out)->append_line(0x2806, 0);
        (*out)->append_line(0x2807, 0);
        (*out)->append_line(0x2809, 0);
        (*out)->append_line(0x2808, 0);
        (*out)->set_line(0);
    } else if (out == &this->victory_ages_list) {
        (*out)->append_line(0x1069, 0);
        (*out)->append_line(0x106A, 0);
        (*out)->append_line(0x106B, 0);
        (*out)->append_line(0x106C, 0);
        (*out)->set_line(0);
    } else if (out == &this->victory_tech_list) {
        this->victory_tech_list->set_sorted(1);
        int i = 0;
        TRIBE_World* world = static_cast<TRIBE_World*>(rge_base_game->world);
        if (world->tech->tech_tree_num > 0) {
            do {
                Tech_Tree* entry = world->tech->tech_tree + i;
                char* text = this->get_string(entry->string_id);
                if (text != 0 && *text != 0) {
                    (*out)->append_line(text, i);
                }
                i++;
            } while (i < world->tech->tech_tree_num);
        }
        (*out)->set_line(0);
    } else if (out == &this->AiRules) {
        this->MakeFileList(this->AiRules, rge_base_game->prog_info->ai_dir,
                           ".per", 0, 1);
        (*out)->set_line(0);
    } else if (out == &this->BuildList) {
        this->MakeFileList(*out, rge_base_game->prog_info->ai_dir,
                           ".ai", 1, 1);
        (*out)->set_line(0);
    } else if (out == &this->CityLayout) {
        this->MakeFileList(*out, rge_base_game->prog_info->ai_dir,
                           ".cty", 1, 0);
        (*out)->set_line(0);
    } else if (out == this->cinematic_input ||
               out == this->cinematic_input + 1 ||
               out == this->cinematic_input + 2) {
        this->MakeFileList(*out, rge_base_game->prog_info->avi_dir,
                           ".avi", 1, 0);
        (*out)->set_line(0);
    } else if (out == this->cinematic_input + 3) {
        this->MakeFileList(*out, s_592A40, ".bmp", 1, 0);
        (*out)->set_line(0);
    } else if (out == &this->victory_object_list) {
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
    }

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
    int i;

    if (this->TEasy_Panel::create_list(panel, out, 0, 0, 0, 0, 10) == 0)
        return 0;

    (*out)->set_active(0);
    (*out)->empty_list();

    if (this->TEasy_Panel::create_auto_scrollbar(scroll, *out, 0x14) == 0)
        return 0;

    if (out == &this->paint_elevation_list) {
        this->set_string(str1, 0x2987, 0x32);
        for (i = 0; i < 7; i++) {
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
    int i;
    int j;
    panel_system.destroyPanel(s_QuitSaveDialog);
    panel_system.destroyPanel(s_OpenSaveDialog);
    panel_system.destroyPanel(s_NewSaveDialog);
    panel_system.destroyPanel(s_Save_Game_Screen);
    panel_system.destroyPanel(s_Scenario_Menu_Dialog);

    delete this->map_type_label;
    for (i = 0; i < 3; ++i) {
        delete this->map_type_button[i];
        delete this->map_type_text[i];
    }
    delete this->default_terrain_label;
    delete this->default_terrain_drop;
    delete this->map_size_label;
    delete this->map_size_drop;
    delete this->map_style_drop;
    delete this->map_style_label;
    delete this->map_generating_text;
    delete this->random_seed_label;
    delete this->random_seed_input;
    delete this->random_seed_used_label;
    delete this->random_seed_used_text;
    delete this->generate_map_button;
    delete this->brush_size_label;
    for (i = 0; i < 5; ++i) {
        delete this->brush_size_button[i];
        delete this->brush_size_button_label[i];
    }
    delete this->paint_type_label;
    for (i = 0; i < 3; ++i) {
        delete this->paint_type_button[i];
        delete this->paint_type_button_label[i];
    }
    delete this->paint_terrain_label;
    delete this->paint_terrain_list;
    delete this->paint_terrain_scrollbar;
    delete this->paint_elevation_list;
    delete this->paint_elevation_scrollbar;
    delete this->player_advance_civilization_drop;
    delete this->player_label;
    delete this->player_starting_age_label;
    delete this->player_build_text;
    delete this->player_city_text;
    delete this->AiRules_text;
    delete this->player_list;
    delete this->player_number_list;
    for (i = 0; i < 5; ++i) {
        delete this->player_inven_label[i];
        delete this->player_inven_input[i];
    }
    for (i = 0; i < 2; ++i) {
        delete this->player_setting_label[i];
        delete this->player_setting_drop[i];
    }
    delete this->BuildList;
    delete this->CityLayout;
    delete this->AiRules;
    delete this->unit_player_list;
    for (i = 0; i < 4; ++i) {
        delete this->unit_mode_select[i];
        delete this->unit_mode_select_label[i];
    }
    delete this->unit_list;
    delete this->unit_scrollbar;
    if (this->unit_list_info != 0) {
        delete[] this->unit_list_info;
        this->unit_list_info = 0;
    }
    if (this->object_panel != 0) {
        delete this->object_panel;
        this->object_panel = 0;
    }
    delete this->button_unit_pics;
    for (i = 0; i < 5; ++i)
        delete this->button_bldg_pics[i];
    for (i = 0; i < 6; ++i)
        delete this->victory_cond_on[i];
    for (i = 0; i < 2; ++i) {
        delete this->victory_and_or[i];
        delete this->victory_text_and_or[i];
    }
    delete this->victory_amount_label;
    delete this->victory_long_label;
    delete this->victory_condition_label;
    delete this->victory_label_conquest;
    delete this->victory_label_explore;
    delete this->victory_label_explore_percent;
    delete this->victory_label_ruins;
    delete this->victory_label_artifacts;
    delete this->victory_label_discoveries;
    delete this->victory_label_gold;
    delete this->victory_condition_explore;
    delete this->victory_condition_ruins;
    delete this->victory_condition_artifacts;
    delete this->victory_condition_discoveries;
    delete this->victory_condition_gold;
    for (i = 0; i < 5; ++i) {
        delete this->victory_cond_type_label[i];
        delete this->victory_cond_type[i];
    }
    delete this->victory_score_label;
    delete this->victory_score;
    delete this->victory_time_label;
    delete this->victory_time;
    for (i = 0; i < 12; ++i)
        delete this->victory_button[i];
    delete this->victory_drop_down;
    delete this->victory_object_list;
    delete this->victory_player_list;
    delete this->victory_ages_list;
    delete this->victory_tech_list;
    delete this->victory_button_set_object;
    delete this->victory_button_set_destination;
    delete this->victory_button_go_to_dest;
    delete this->victory_condition_text;
    delete this->victory_condition_type;
    delete this->victory_amount_text;
    delete this->victory_amount_input;
    delete this->victory_enemy_player_list;
    delete this->victory_attribute_list;
    delete this->victory_which_enemy_text;
    delete this->victory_object_scrollbar;
    for (i = 0; i < 5; ++i) {
        delete this->message_button[i];
        delete this->message_button_label[i];
    }
    delete this->message_input;
    for (i = 0; i < 4; ++i) {
        delete this->cinematic_label[i];
        delete this->cinematic_input[i];
    }
    for (i = 0; i < 1; ++i) {
        delete this->options_label[i];
        delete this->options_button[i];
    }
    delete this->options_player_list;
    delete this->options_disable_tech_text;
    for (i = 0; i < 16; ++i) {
        delete this->options_disable_button[i];
        delete this->options_disable_text[i];
    }
    delete this->Diplomacy_player_list;
    for (i = 0; i < 8; ++i) {
        delete this->Diplomacy_opponent_label[i];
        delete this->Diplomacy_player_text[i];
        delete this->Diplomacy_AlliedVictory[i];
        for (j = 0; j < 3; ++j)
            delete this->Diplomacy_friend_box[i][j];
    }
    for (i = 0; i < 4; ++i)
        delete this->Diplomacy_status_label[i];
    delete this->menu_button;
    delete this->help_button;
    for (i = 0; i < 10; ++i)
        delete this->scenario_mode_button[i];
    delete this->bottom_panel;
    delete this->message_panel;
    delete this->main_view;
    delete this->map_view;
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
    int i;

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
            for (i = 0; i < 3; ++i) {
                this->map_type_button[i]->set_active(active);
                this->map_type_text[i]->set_active(active);
            }
            this->generate_map_button->set_active(active);
            if (active) {
                this->set_map_type(static_cast<MapType>(this->map_type), 1);
            } else {
                this->set_map_type(static_cast<MapType>(ScenarioModeNone), 0);
            }
            break;

        case ScenarioModeTerrain:
            this->brush_size_label->set_active(active);
            this->paint_type_label->set_active(active);
            this->paint_terrain_label->set_active(active);
            for (i = 0; i < 5; ++i) {
                this->brush_size_button[i]->set_active(active);
                this->brush_size_button_label[i]->set_active(active);
            }
            for (i = 0; i < 3; ++i) {
                this->paint_type_button[i]->set_active(active);
                this->paint_type_button_label[i]->set_active(active);
            }
            if (active) {
                this->set_brush_size(this->brush_size);
                this->set_paint_type(static_cast<PaintType>(this->paint_type), 1);
            } else {
                this->set_brush_size(BrushSizeNone);
                this->set_paint_type(static_cast<PaintType>(0), 0);
            }
            break;

        case ScenarioModePlayers:
            this->player_list->set_active(active);
            this->player_number_list->set_active(active);
            for (i = 0; i < 5; ++i) {
                this->player_inven_label[i]->set_active(active);
                this->player_inven_input[i]->set_active(active);
            }
            for (i = 0; i < 2; ++i) {
                this->player_setting_label[i]->set_active(active);
                this->player_setting_drop[i]->set_active(active);
            }
            if (active) {
                this->player_advance_civilization_drop->setCurrentLineNumber(
                    static_cast<T_Scenario*>(this->world->scenario)->GetPlayerAge(this->player_num - 1));
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
                    this->set_unit(static_cast<short>(this->unit_list->currentLineNumber()));
                    this->bottom_panel->set_curr_child(this->unit_list);
                    this->set_paint_object_mode();
                    rge_base_game->set_game_mode(rge_base_game->game_mode, 4);
                    if (rge_base_game->master_obj_id != -1 && rge_base_game->get_player() != 0) {
                        s = rge_base_game->master_obj_id;
                        this->object_panel->set_master_info(
                            this->world->players[rge_base_game->get_player()->id]->master_objects[s],
                            static_cast<TRIBE_Player*>(rge_base_game->get_player()));
                    } else {
                        this->object_panel->set_master_info(0, 0);
                    }
                    this->object_panel->set_redraw(TPanel::RedrawNormal);
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
            for (i = 0; i < 5; ++i) {
                this->victory_cond_type_label[i]->set_active(active);
                this->victory_cond_type[i]->set_active(active);
            }
            if (active) {
                this->load_multi_victory_cond_from_scenario();
                this->map_view->set_active(0);
                this->set_mp_victory_type(static_cast<VictoryType>(this->mp_victory_type), 1);
            } else {
                this->save_multi_victory_cond_in_scenario();
                this->map_view->set_active(1);
                this->set_mp_victory_type(static_cast<VictoryType>(0), 0);
            }
            break;

        case ScenarioModeMessages:
            for (i = 0; i < 5; ++i) {
                this->message_button[i]->set_active(active);
                this->message_button_label[i]->set_active(active);
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
                this->set_message_type(static_cast<MessageType>(this->message_type), 1);
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
            for (i = 0; i < 4; ++i) {
                this->cinematic_label[i]->set_active(active);
                this->cinematic_input[i]->set_active(active);
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
                    ppv = this->Diplomacy_AlliedVictory;
                    do {
                        this->Diplomacy_player_text[i]->set_active(active);
                        TButtonPanel* p = ppv[0];
                        if (i != this->player_num - 1) {
                            p->set_active(0);
                            this->Diplomacy_friend_box[i][0]->set_active(active);
                            this->Diplomacy_friend_box[i][1]->set_active(active);
                            p = this->Diplomacy_friend_box[i][2];
                        }
                        p->set_active(active);
                        ppv++;
                        i++;
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
                this->options_button[0]->set_state(static_cast<T_Scenario*>(this->world->scenario)->GetScenarioOption(2));
                this->LoadDisabledItemsFromScenario();
                if (this->player_num != 0) {
                    this->options_player_list->setCurrentLineNumber(this->player_num - 1);
                } else {
                    this->options_player_list->setCurrentLineNumber(0);
                }
            }
            this->options_label[0]->set_active(active);
            this->options_button[0]->set_active(active);
            this->options_player_list->set_active(active);
            if (active) {
                this->options_player_list->set_line(this->player_num - 1);
            } else {
                this->player_num = static_cast<short>(this->options_player_list->get_line() + 1);
            }
            this->options_disable_tech_text->set_active(active);
            for (i = 0; i < 16; ++i) {
                this->options_disable_button[i]->set_active(active);
                this->options_disable_text[i]->set_active(active);
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
        this->set_redraw(TPanel::RedrawNormal);
    }
    this->valid_save_spot_flag = 1;
}

void TRIBE_Screen_Sed::set_paint_object_mode() {
    RGE_Base_Game* game = rge_base_game;
    int mo_id = static_cast<short>(game->master_obj_id);
    int enabled = 0;

    if (mo_id != -1) {
        int pn = this->player_num;
        RGE_Master_Static_Object* obj = this->world->players[pn]->master_objects[mo_id];

        if (obj != 0 && obj->master_type == 0x50 &&
            obj->hide_in_scenario_editor != 0) {
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
    this->bottom_panel->set_redraw(TPanel::RedrawNormal);
}

void TRIBE_Screen_Sed::set_mp_victory_type(VictoryType type, int redraw)
{
    int pass;
    int active;
    int mode;
    int i;

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
            for (i = 0; i < 5; ++i)
                this->victory_cond_on[i]->set_active(active);
            for (i = 0; i < 2; ++i) {
                this->victory_and_or[i]->set_active(active);
                this->victory_text_and_or[i]->set_active(active);
            }

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
    this->bottom_panel->set_redraw(TPanel::RedrawNormal);
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
    int i;

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
        for (i = 0; i < 5; ++i) {
            this->brush_size_button[i]->set_active(active);
            this->brush_size_button_label[i]->set_active(active);
        }

        switch (mode) {
        case 1:
            this->paint_terrain_list->set_active(active);
            this->paint_terrain_label->set_active(active);
            if (active != 0) {
                this->set_terrain(static_cast<short>(this->paint_terrain_list->currentLineNumber()));
                rge_base_game->set_game_mode(9, 0);
            } else {
                rge_base_game->set_game_mode(0, 0);
            }
            break;
        case 2:
            this->paint_elevation_list->set_active(active);
            this->paint_terrain_label->set_active(active);
            if (active != 0) {
                this->set_elevation(static_cast<short>(this->paint_elevation_list->currentLineNumber()));
                rge_base_game->set_game_mode(10, 0);
            } else {
                rge_base_game->set_game_mode(0, 0);
            }
            break;
        case 3:
            this->paint_elevation_list->set_active(0);
            this->paint_terrain_list->set_active(0);
            this->paint_terrain_label->set_active(0);
            this->brush_size_label->set_active(0);
            for (i = 0; i < 5; ++i) {
                this->brush_size_button[i]->set_active(0);
                this->brush_size_button_label[i]->set_active(0);
            }
            if (active != 0) {
                this->set_elevation(static_cast<short>(this->paint_elevation_list->currentLineNumber()));
                rge_base_game->set_game_mode(0x13, 0);
            } else {
                rge_base_game->set_game_mode(0, 0);
            }
            break;
        }
        pass++;
    } while (pass < 2);

    this->paint_type = type;
    this->paint_type_button[type - 1]->set_radio_button();
    this->bottom_panel->set_redraw(TPanel::RedrawNormal);
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
        static_cast<T_Scenario*>(this->world->scenario)->Set_player_Food(oldp, v);
        this->world->players[this->player_num]->attributes[0] = v;

        v = atoi(this->player_inven_input[1]->currentLine());
        static_cast<T_Scenario*>(this->world->scenario)->Set_player_Wood(oldp, v);
        this->world->players[this->player_num]->attributes[1] = v;

        v = atoi(this->player_inven_input[2]->currentLine());
        static_cast<T_Scenario*>(this->world->scenario)->Set_player_Stone(oldp, v);
        this->world->players[this->player_num]->attributes[2] = v;

        v = atoi(this->player_inven_input[3]->currentLine());
        static_cast<T_Scenario*>(this->world->scenario)->Set_player_Gold(oldp, v);
        this->world->players[this->player_num]->attributes[3] = v;

        this->world->scenario->SetPlayerName(oldp, this->player_inven_input[4]->currentLine());
        this->world->scenario->Set_player_Type(oldp, this->player_setting_drop[0]->currentLineNumber());
        this->world->scenario->Set_player_Civ(oldp, this->player_setting_drop[1]->currentLineNumber() + 1);
        this->world->scenario->Set_player_AI(oldp, this->AiRules->currentLine(), 0);
        this->world->scenario->Set_BuildList(oldp, this->BuildList->currentLine(), 0);
        this->world->scenario->Set_CityPlan(oldp, this->CityLayout->currentLine(), 0);
    }

    long p = player - 1;
    this->player_num = player;
    if (player != 0) {
        this->player_list->set_line(p);
        rge_base_game->set_player(player);
        if (refresh == 1) {
            int v;
            v = static_cast<T_Scenario*>(this->world->scenario)->Get_player_Food(p);
            sprintf(str, "%d", v);
            this->player_inven_input[0]->set_text(str);
            v = static_cast<T_Scenario*>(this->world->scenario)->Get_player_Wood(p);
            sprintf(str, "%d", v);
            this->player_inven_input[1]->set_text(str);
            v = static_cast<T_Scenario*>(this->world->scenario)->Get_player_Stone(p);
            sprintf(str, "%d", v);
            this->player_inven_input[2]->set_text(str);
            v = static_cast<T_Scenario*>(this->world->scenario)->Get_player_Gold(p);
            sprintf(str, "%d", v);
            this->player_inven_input[3]->set_text(str);
            this->player_inven_input[4]->set_text(this->world->scenario->GetPlayerName(p));
            this->player_setting_drop[0]->setCurrentLineNumber(this->world->scenario->Get_player_Type(p));
            this->player_setting_drop[1]->setCurrentLineNumber(this->world->scenario->Get_player_Civ(p) - 1);

            v = this->AiRules->get_line(this->world->scenario->Get_player_AI(p, 0));
            if (v == -1) {
                this->AiRules->append_line(this->world->scenario->Get_player_AI(p, 0), 0);
                v = this->AiRules->get_line(this->world->scenario->Get_player_AI(p, 0));
            }
            this->AiRules->setCurrentLineNumber(v);

            v = this->BuildList->get_line(this->world->scenario->Get_BuildList(p, 0));
            if (v == -1) {
                this->BuildList->append_line(this->world->scenario->Get_BuildList(p, 0), 0);
                v = this->BuildList->get_line(this->world->scenario->Get_BuildList(p, 0));
            }
            this->BuildList->setCurrentLineNumber(v);

            v = this->CityLayout->get_line(this->world->scenario->Get_CityPlan(p, 0));
            if (v == -1) {
                this->CityLayout->append_line(this->world->scenario->Get_CityPlan(p, 0), 0);
                v = this->CityLayout->get_line(this->world->scenario->Get_CityPlan(p, 0));
            }
            this->CityLayout->setCurrentLineNumber(v);
        }
    }
}

void TRIBE_Screen_Sed::set_player_active(short player, int active) {
    this->world->scenario->Set_player_Active(player, active);
}

int __cdecl TRIBE_Screen_Sed_unit_list_compare(const void* a, const void* b) {
    int result = CompareStringA(0x400, 1, static_cast<const char*>(a), -1,
                                static_cast<const char*>(b), -1);
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
    this->unit_player_list->setCurrentLineNumber(p);
    this->unit_list->empty_list();
    if (this->unit_list_info != 0) {
        free(this->unit_list_info);
        this->unit_list_info = 0;
    }
    if (player != 0) {
        this->unit_list_size = 1;
        short n = player->master_object_num;
        short i = 0;
        if (n > 0) {
            for (i = 0; i < n; ++i) {
                RGE_Master_Static_Object* m = player->master_objects[i];
                if (m != 0 && m->hide_in_scenario_editor == 0)
                    this->unit_list_size++;
            }
        }
        if (this->unit_list_size == 0) return;
        this->unit_list_info = static_cast<List_Info*>(
            calloc(this->unit_list_size, sizeof(List_Info)));
        if (this->unit_list_info == 0) return;
        this->unit_list_info[0].id = -1;
        this->set_string(this->unit_list_info[0].text, 0x2775, 0x14);

        short out = 1; // BINARY NOTE: the original loads this index as a word.
        // BINARY NOTE: the offset zero store follows the positive-count test.
        if (n > 0) {
            int master_index = 0;
            do {
                RGE_Master_Static_Object* m = player->master_objects[master_index];
                if (m != 0 && m->hide_in_scenario_editor == 0) {
                    this->unit_list_info[out].id = i;
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

        qsort(this->unit_list_info, this->unit_list_size, 0x66, TRIBE_Screen_Sed_unit_list_compare);
        char** strings = static_cast<char**>(
            calloc(this->unit_list_size, sizeof(char*)));
        if (strings == 0) return;
        is_error = 0;
        short selected = 0;
        for (i = 0; i < this->unit_list_size; i++) {
            char* s = static_cast<char*>(calloc(100, sizeof(char)));
            strings[i] = s;
            if (s == 0) { is_error = 1; break; }
            strcpy(s, this->unit_list_info[i].text);
            if (this->unit_list_info[i].id == rge_base_game->master_obj_id) selected = i;
        }
        if (!is_error) {
            this->unit_list->set_text(strings, this->unit_list_size);
            this->unit_list->scroll_cur_line(1, selected, 1);
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
    bottom_panel->set_redraw(TPanel::RedrawNormal);
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
                main_view->set_redraw(TPanel::RedrawNormal);
                if (last_map_redraw_time - now >= map_redraw_interval) {
                    map_view->set_redraw(TPanel::RedrawNormal);
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
                this->main_view->set_redraw(TPanel::RedrawImmediate);
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
                short selected = i;

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
                       (this->victory_amount_input->active != 0)) {
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
                    object->selected = 1;
                    if (draw_level == 0) {
                        this->main_view->set_redraw(TPanel::RedrawImmediate);
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
    char random_seed_text[28];
    long saved_random_map_seed;
    float f1;
    float f2;
    RGE_Player* player;

    if (param_1 == 0) {
        return 0;
    }

    if (param_1 != this->main_view) {
        RGE_Static_Object* selected_object = this->SelectedObject;
        if (selected_object != 0) {
            rge_base_game->get_player()->select_one_object(selected_object, 0);
        }
        RGE_Static_Object* destination_object = this->DestinationObject;
        if (destination_object != 0) {
            rge_base_game->get_player()->select_one_object(destination_object, 0);
        }
    }

    if (param_2 == 0) {
        if (param_1 == this->random_seed_input ||
            param_1 == this->player_inven_input[0] ||
            param_1 == this->player_inven_input[1] ||
            param_1 == this->player_inven_input[2] ||
            param_1 == this->player_inven_input[3] ||
            param_1 == this->player_inven_input[4] ||
            param_1 == this->player_setting_label[0] ||
            param_1 == this->victory_condition_explore ||
            param_1 == this->victory_condition_ruins ||
            param_1 == this->victory_condition_artifacts ||
            param_1 == this->victory_condition_discoveries ||
            param_1 == this->victory_condition_gold ||
            param_1 == this->victory_amount_input ||
            param_1 == this->message_input) {
            this->need_to_save_flag = 1;
        }
    }

    if (param_1 == this->main_view) {
        if (param_2 == 0x10) {
            rge_base_game->get_player()->unselect_object();
            // BINARY NOTE: the PDB ABI names this parameter unsigned long,
            // but the main-view event carries an RGE_Static_Object pointer.
            RGE_Static_Object* event_object =
                reinterpret_cast<RGE_Static_Object*>(param_3);
            if (this->SelectRegionFlag == SelectObject)
                this->SelectedObject = event_object;
            if (this->SelectRegionFlag == SelectDestinationObject)
                this->DestinationObject = event_object;
            RGE_Static_Object* selected_object = this->SelectedObject;
            if (selected_object != 0) {
                rge_base_game->get_player()->select_one_object(selected_object, 0);
            }
            RGE_Static_Object* destination_object = this->DestinationObject;
            if (destination_object != 0) {
                rge_base_game->get_player()->select_one_object(destination_object, 0);
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
                this->set_scenario_mode(static_cast<ScenarioMode>(i + ScenarioModeMap));
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
            case 0: this->message_input->set_help_info(0x7770, -1); break;
            case 1: this->message_input->set_help_info(0x7771, -1); break;
            case 2: this->message_input->set_help_info(0x7772, -1); break;
            case 3: this->message_input->set_help_info(0x7773, -1); break;
            case 4: this->message_input->set_help_info(0x7774, -1); break;
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
            this->player_num = static_cast<short>(line + 1);
            static_cast<T_Scenario*>(this->world->scenario)->SetSPWhich(this->player_num - 1);
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
                if (param_1 == this->victory_button_set_object) {
                    this->SelectRegionFlag = SelectObject;
                    rge_base_game->set_game_mode(0x10, 0);
                    rge_base_game->get_player()->unselect_object();
                    RGE_Static_Object* destination_object = this->DestinationObject;
                    if (destination_object != 0) {
                        rge_base_game->get_player()->select_one_object(destination_object, 0);
                    }
                } else if (param_1 == this->victory_button_set_destination && line != 1) {
                    this->SelectRegionFlag = SelectArea;
                    rge_base_game->get_player()->unselect_object();
                    RGE_Static_Object* selected_object = this->SelectedObject;
                    if (selected_object != 0) {
                        rge_base_game->get_player()->select_one_object(selected_object, 0);
                    }
                    rge_base_game->set_game_mode(0, 0);
                    return 1;
                } else if (param_1 == this->victory_button_set_destination) {
                    this->SelectRegionFlag = SelectDestinationObject;
                    rge_base_game->set_game_mode(0x10, 0);
                    rge_base_game->get_player()->unselect_object();
                    RGE_Static_Object* selected_object = this->SelectedObject;
                    if (selected_object != 0) {
                        rge_base_game->get_player()->select_one_object(selected_object, 0);
                    }
                } else if (param_1 == this->victory_button_go_to_dest && line != 1) {
                    this->main_view->get_selection_area(y1, y2, x1,
                                                        x2, 1);
                    f1 = static_cast<float>(x1);
                    f2 = static_cast<float>(x2);
                    this->px1 = static_cast<float>(y1);
                    this->py1 = static_cast<float>(y2);
                    this->SelectRegionFlag = SelectOff;
                    this->px2 = f1;
                    this->py2 = f2;
                    if (f1 != -1.0f) {
                        f1 = f1 - (f1 - static_cast<float>(y1)) * 0.5f;
                        f2 = f2 - (f2 - static_cast<float>(y2)) * 0.5f;
                        player = rge_base_game->get_player();
                        player->set_view_loc(f1, f2);
                        rge_base_game->get_player()->set_map_loc(static_cast<short>(f1), static_cast<short>(f2));
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
                            RGE_Static_Object* selected_object = this->SelectedObject;
                            if (selected_object != 0) {
                                rge_base_game->get_player()->select_one_object(selected_object, 0);
                            }
                            RGE_Static_Object* destination_object = this->DestinationObject;
                            if (destination_object != 0) {
                                rge_base_game->get_player()->select_one_object(destination_object, 0);
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
                    this->set_map_type(static_cast<MapType>(i + MapTypeBlankValue), 1);
                    return 1;
                }
            }
            if (param_1 == this->generate_map_button) {
                this->map_generating_text->set_active(1);
                this->set_redraw(TPanel::RedrawImmediate);
                InvalidateRect(rge_base_game->prog_window, 0, 0);
                rge_base_game->draw_window();
                i = this->map_size_drop->currentLineNumber();
                f1 = static_cast<float>(this->map_style_drop->currentLineNumber());
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
                if (this->map_type == MapTypeBlankValue) {
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
                    saved_random_map_seed = rge_base_game->random_map_seed;
                    if (this->map_type == MapTypeSeedValue) {
                        rge_base_game->random_map_seed = atoi(this->random_seed_input->currentLine());
                    } else {
                        rge_base_game->random_map_seed = -1;
                    }
                    for (i = 0; i < 9; i++) this->world->players[i]->reset_selected();
                    this->world->map->map_generate2(
                        this->world, map_size, map_size,
                        static_cast<unsigned char>(f1), line + 1);
                    rge_base_game->random_map_seed = saved_random_map_seed;
                    itoa(rge_base_game->save_random_map_seed, random_seed_text, 10);
                    this->random_seed_used_text->set_text(random_seed_text);
                    debug_rand(s_C__msdev_work_age1_x1_scr_sed_cp, 0xB58);
                }
                center = map_size / 2;
                for (i = 0; i < 8; i++) {
                    this->world->players[i]->set_map_loc(static_cast<short>(center), static_cast<short>(center));
                    this->world->players[i]->set_view_loc(static_cast<float>(center), static_cast<float>(center));
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
                i = this->paint_terrain_list->currentLineNumber();
                this->set_terrain(static_cast<short>(i));
                this->brush_size_button[0]->set_active(1);
                return 1;
            } else if (param_1 == this->paint_elevation_list) {
                i = this->paint_elevation_list->currentLineNumber();
                this->set_elevation(static_cast<short>(i));
                return 1;
            } else if (param_2 == 1) {
                if (this->valid_save_spot_flag != 0) this->need_to_save_flag = 1;
                for (i = 0; i < 5; i++) {
                    if (param_1 == this->brush_size_button[i]) { this->set_brush_size(static_cast<BrushSize>(i + BrushSizeVerySmall)); return 1; }
                }
                for (i = 0; i < 3; i++) {
                    if (param_1 == this->paint_type_button[i]) { this->set_paint_type(static_cast<PaintType>(i + PaintTypeTerrainValue), 1); return 1; }
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
                static_cast<T_Scenario*>(this->world->scenario)->SetPlayerAge(this->player_num - 1, i);
            }
            if (param_1 == this->player_list) {
                line = this->player_list->get_line();
                this->set_player(static_cast<short>(line + 1), 1, 1);
                line = this->player_list->get_line();
                i = static_cast<T_Scenario*>(this->world->scenario)->GetPlayerAge(line);
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
                static_cast<T_Scenario*>(this->world->scenario)->SetPlayerAge(this->player_num - 1, i);
        }
        break;

    case ScenarioModeUnits:
        if (this->valid_save_spot_flag != 0) this->need_to_save_flag = 1;
        if (param_2 == 0) {
            if (this->valid_save_spot_flag != 0) this->need_to_save_flag = 1;
            if (param_1 == this->unit_player_list) {
                line = this->unit_player_list->get_line();
                this->set_unit_player(static_cast<short>(line));
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
                        player_tribe = static_cast<TRIBE_Player*>(rge_base_game->get_player());
                    }
                    this->object_panel->set_master_info(player_master, player_tribe);
                    this->set_paint_object_mode();
                        this->object_panel->set_redraw(TPanel::RedrawImmediate);
                    return 1;
                }
            }
        }
        if (param_2 == 2 || param_2 == 1) {
            if (param_1 == this->unit_list) {
                RGE_Master_Static_Object* list_master;
                TRIBE_Player* list_tribe;
                i = this->unit_list->currentLineNumber();
                this->set_unit(static_cast<short>(i));
                if (rge_base_game->game_mode != 8 && rge_base_game->game_mode != 0x15) this->unit_mode_select[0]->set_radio_button();
                if (rge_base_game->master_obj_id == -1 || rge_base_game->get_player() == 0) { list_tribe = 0; list_master = 0; }
                else {
                    short master_id = rge_base_game->master_obj_id;
                    list_master = this->world->players[rge_base_game->get_player()->id]->master_objects[master_id];
                    list_tribe = static_cast<TRIBE_Player*>(rge_base_game->get_player());
                }
                this->object_panel->set_master_info(list_master, list_tribe);
                this->set_paint_object_mode();
                // BINARY NOTE: the list path redraws with flag 1, not 2.
                this->object_panel->set_redraw(TPanel::RedrawNormal);
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
                    this->set_mp_victory_type(static_cast<VictoryType>(i + VictoryTypeStandardValue), 1);
                    if (i != 4) { static_cast<T_Scenario*>(this->world->scenario)->Set_Multi_Conquest(1); this->victory_cond_on[0]->set_state(1); }
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
                this->player_num = static_cast<short>(line + 1);
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
                static_cast<T_Scenario*>(this->world->scenario)->SetScenarioOption(2, i);
            }
        }
        break;

    }

    if (param_1->panelName() != 0 && strcmp(param_1->panelName(), s_QuitSaveDialog) == 0) {
            panel_system.setCurrentPanel(s_Scenario_Editor_Screen, 0);
            panel_system.destroyPanel(s_QuitSaveDialog);
            if (param_2 == 0) this->command_save(static_cast<unsigned char>(param_2), 1);
            else if (param_2 == 1) {
                if (static_cast<TRIBE_Game*>(rge_base_game)->start_menu() == 0) rge_base_game->close();
                else panel_system.destroyPanel(s_Scenario_Editor_Screen);
            }
            return 1;
    }

    if (param_1->panelName() != 0 && strcmp(param_1->panelName(), s_OpenSaveDialog) == 0) {
            panel_system.setCurrentPanel(s_Scenario_Editor_Screen, 0);
            panel_system.destroyPanel(s_OpenSaveDialog);
            if (param_2 == 0) this->command_save(static_cast<unsigned char>(param_2), 2);
            else if (param_2 == 1) {
                new TRIBE_Screen_Sed_Open;
                panel_system.setCurrentPanel(s_Scenario_Editor_Open, 0);
            }
            return 1;
    }

    if (param_1->panelName() != 0 && strcmp(param_1->panelName(), s_NewSaveDialog) == 0) {
            panel_system.setCurrentPanel(s_Scenario_Editor_Screen, 0);
            panel_system.destroyPanel(s_NewSaveDialog);
            if (param_2 == 0) this->command_save(static_cast<unsigned char>(param_2), 3);
            else if (param_2 == 1) static_cast<TRIBE_Game*>(rge_base_game)->start_scenario_editor(0, 0);
            return 1;
    }

    return 0;
}

void TRIBE_Screen_Sed::draw()
{
    tagRECT rect_local;

    this->TEasy_Panel::draw();

    if (use_bevels != 0 && main_view != 0) {
        if (render_rect.left == clip_rect.left &&
            render_rect.top == clip_rect.top &&
            render_rect.right == clip_rect.right &&
            render_rect.bottom == clip_rect.bottom)
        {
            this->draw_setup(0);

            unsigned char* locked = render_area->Lock("scr_sed::draw", 1);
            if (locked) {
                tagRECT* mrect = &main_view->render_rect;
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
    rge_base_game->get_player()->unselect_object();
    rge_base_game->get_player()->unselect_area();
}

int TRIBE_Screen_Sed::command_menu()
{
    TRIBE_Dialog_Sed_Menu* dlg = new TRIBE_Dialog_Sed_Menu(this);
    if (dlg != 0 && dlg->error_code != 0) {
        delete dlg;
        return 0;
    }
    return 1;
}

void TRIBE_Screen_Sed::command_new(void) {
    if (this->need_to_save()) {
        this->popupYesNoCancelDialog(0x2447, s_NewSaveDialog, 0x1C2, 100);
        return;
    }
    static_cast<TRIBE_Game*>(rge_base_game)->start_scenario_editor(0, 0);
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
                static_cast<TRIBE_Game*>(rge_base_game)->show_status_message(0x44d, 0, -1);
        }
        if (static_cast<TRIBE_Game*>(rge_base_game)->load_game_data() == 0) {
            if (display_in != 0) {
                static_cast<TRIBE_Game*>(rge_base_game)->close_status_message();
            }
            return 0;
        }
    }

    this->world = static_cast<TRIBE_World*>(rge_base_game->world);
    if (display_in != 0) {
        if (scenario_name_in == 0) {
            static_cast<TRIBE_Game*>(rge_base_game)->show_status_message(0x44e, 0, -1);
        } else {
            static_cast<TRIBE_Game*>(rge_base_game)->show_status_message(0x44f, 0, -1);
        }
    }

    player_info.scenario = scenario_name_in;
    player_info.map_info = &map_info;
    player_info.map_width = static_cast<short>(width);
    player_info.map_height = static_cast<short>(height);
    player_info.ai_info = 0;
    player_info.player_num = 8;
    tribe = 0;

    int i;
    for (i = 0; i < 8; i++) {
        tribe++;
        if (tribe >= this->world->master_player_num) {
            tribe = 1;
        }
        this->set_string(player_info.name[i], 0x2865 + i, 0x41);
        player_info.type[i] = 0;
        player_info.tribe[i] = static_cast<char>(tribe);
        player_info.color[i] = -1;
        player_info.player_id_hash[i] = i;
    }
    player_info.player_id_hash[i] = i;
    map_info.base_terrain = 0;

    if (rge_base_game->sound_system != 0) {
        rge_base_game->sound_system->mute = 1;
    }
    result = this->world->new_scenario(player_info, random_seed_in) & 0xff;
    if (result != 0 && this->world->player_num < 8) {
        result = 0;
        this->world->del_game_info();
    }
    if (rge_base_game->sound_system != 0) {
        rge_base_game->sound_system->mute = 0;
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

    new TRIBE_Screen_Sed_Open();
    panel_system.setCurrentPanel(s_Scenario_Editor_Open, 0);
}

void TRIBE_Screen_Sed::command_outline(void)
{
    switch (rge_base_game->outline_type) {
    case 0:
    case 3:
        rge_base_game->outline_type = 2;
        return;
    case 2:
        rge_base_game->outline_type = 1;
        return;
    case 1:
        rge_base_game->outline_type = 0;
        return;
    }
}

void TRIBE_Screen_Sed::command_player(int player) {
    rge_base_game->set_player(player);
}

void TRIBE_Screen_Sed::command_quit() {
    if (need_to_save()) {
        popupYesNoCancelDialog(0x2447, s_QuitSaveDialog, 0x1C2, 0x64);
        return;
    }
    if (!static_cast<TRIBE_Game*>(rge_base_game)->start_menu()) {
        rge_base_game->close();
        return;
    }
    panel_system.destroyPanel(s_Scenario_Editor_Screen);
}

void TRIBE_Screen_Sed::command_save(unsigned char closeMenu, unsigned char postAction)
{
    char temp_name[260];

    this->set_scenario_mode(ScenarioModeSave);
    static_cast<T_Scenario*>(this->world->scenario)->Save_victory_conditions_into_players(1);
    if (this->world->scenario->active_player_count() < 1) {
        panel_system.destroyPanel(s_Scenario_Menu_Dialog);
        this->popupOKDialog(0x2742, 0, 0x1c2, 100);
    } else if (this->world->scenario->any_player_count() < 1) {
        panel_system.destroyPanel(s_Scenario_Menu_Dialog);
        this->popupOKDialog(0x2743, 0, 0x1c2, 100);
    } else {
        char* name = this->world->scenario->Get_scenario_name();
        if (*name == 0) {
            this->command_save_as(postAction);
        } else {
            static_cast<TRIBE_Game*>(rge_base_game)->show_status_message(0x450, 0, -1);
            if (closeMenu != 0) {
                panel_system.destroyPanel(s_Scenario_Menu_Dialog);
            }
            if (this->world->save_scenario(name) == 0) {
                static_cast<TRIBE_Game*>(rge_base_game)->close_status_message();
                this->popupOKDialog(0x963, 0, 0x1c2, 100);
            } else {
                static_cast<TRIBE_Game*>(rge_base_game)->close_status_message();
                sprintf(temp_name, "default%d", rge_base_game->registry->RegGetInt(0, "Game File Number"));
                if (strcmp(name, temp_name) != 0) {
                    this->need_to_save_flag = 0;
                }
                if (postAction == 1) {
                    if (static_cast<TRIBE_Game*>(rge_base_game)->start_menu() == 0) {
                        rge_base_game->close();
                    } else {
                        panel_system.destroyPanel(s_Scenario_Editor_Screen);
                    }
                } else if (postAction == 2) {
                    TRIBE_Screen_Sed_Open* p = new TRIBE_Screen_Sed_Open;
                    panel_system.setCurrentPanel(s_Scenario_Editor_Open, 0);
                } else if (postAction == 3) {
                    static_cast<TRIBE_Game*>(rge_base_game)->start_scenario_editor(0, 0);
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
        this->popupOKDialog(0x2742, 0, 0x1C2, 100);
    } else if (this->world->scenario->any_player_count() < 1) {
        this->popupOKDialog(0x2743, 0, 0x1C2, 100);
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
        int file_num = rge_base_game->registry->RegGetInt(0, "Game File Number");
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
    static_cast<T_Scenario*>(this->world->scenario)->Save_victory_conditions_into_players(1);
    if (this->world->scenario->active_player_count() < 1) {
        this->popupOKDialog(0x2742, 0, 0x1c2, 100);
        return 0;
    }
    if (this->world->scenario->any_player_count() < 1) {
        this->popupOKDialog(0x2743, 0, 0x1c2, 100);
        return 0;
    }

    static_cast<TRIBE_Game*>(rge_base_game)->show_status_message(0x450, 0, -1);
    sprintf(scenario_default_file_name, "default%d.scx",
            rge_base_game->registry->RegGetInt(0, "Game File Number"));
    if (this->world->save_scenario(scenario_default_file_name) == 0) {
        static_cast<TRIBE_Game*>(rge_base_game)->close_status_message();
        this->popupOKDialog(0x963, 0, 0x1c2, 100);
        return 0;
    }

    sprintf(scenario_default_file_name, "default%d",
            rge_base_game->registry->RegGetInt(0, "Game File Number"));
    return scenario_default_file_name;
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
