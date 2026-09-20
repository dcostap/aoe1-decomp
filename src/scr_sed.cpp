
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
#include "../include/resource_ids.h"
#include "../include/world.h"
#include "../include/world_info.h"
#include "../include/tworld.h"
#include "../include/player.h"
#include "../include/tplayer.h"
#include "../include/scenario.h"
#include "../include/tscenaro.h"
#include "../include/map.h"
#include "../include/m_s_obj.h"
#include "../include/tm_b_obj.h"
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
    unsigned long, unsigned long, const char *, int, const char *, int);

int __cdecl TRIBE_Screen_Sed_unit_list_compare(const void *, const void *);

TRIBE_Screen_Sed::TRIBE_Screen_Sed(char *scenario_name_in, int is_multi_player_in) : TScreenPanel("Scenario Editor Screen") {
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
    this->last_update_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_sed.cpp", 279);
    this->map_redraw_interval = 1000;
    this->last_map_redraw_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_sed.cpp", 282);
    this->save_text_color = 0;
    this->save_window_color = 0;
    this->changed_system_colors = 0;
    this->CurrentVictory = 0;
    rge_base_game->set_prog_mode(7);
    if (!this->command_new_map(scenario_name_in, is_multi_player_in, 0, 144, 144, 1)) {
        this->error_code = 1;
        return;
    }
    int game_file_number = rge_base_game->registry->RegGetInt(0, "Game File Number");
    sprintf(temp_name, "default%d.scx", game_file_number);
    if (scenario_name_in && strcmp(scenario_name_in, temp_name) == 0)
        this->need_to_save_flag = 1;
    if (!this->TScreenPanel::setup(rge_base_game->draw_area, "scr5", 0xC387, 1)) {
        this->error_code = 1;
        return;
    }
    this->TEasy_Panel::setup_shadow_area(0);
    this->main_view = new TRIBE_Main_View;
    if (this->main_view == 0 || this->main_view->error_code != 0) {
        this->error_code = 1;
        return;
    }
    if (!this->main_view->RGE_View::setup(this->render_area, this, 0, 0, 0, 0, 0xA1, 0, "bordline")) {
        this->error_code = 1;
        return;
    }
    this->map_view = new RGE_Diamond_Map_View;
    if (this->map_view == 0 || this->map_view->error_code != 0) {
        this->error_code = 1;
        return;
    }
    if (!this->map_view->RGE_Diamond_Map::setup(this->render_area, this, 0, 0, 0, 0, 0xA1, 0,
                                                rge_base_game->map_save_area)) {
        this->error_code = 1;
        return;
    }
    this->map_view->set_bitmap("map640.bmp", 0xC4E1);
    {
        TRIBE_Main_View *main_view = this->main_view;
        RGE_Diamond_Map_View *map_view = this->map_view;
        map_view->main_view = main_view;
    }
    {
        RGE_Diamond_Map_View *map_view = this->map_view;
        TRIBE_Main_View *main_view = this->main_view;
        main_view->map_view = map_view;
    }
    this->main_view->set_help_info(-1, -1);
    RGE_Font *font = rge_base_game->get_font(RGE_FONT_STANDARD);
    this->message_panel = new TMessagePanel(font->font, font->font_wid, font->font_hgt);
    if (this->message_panel == 0 || this->message_panel->error_code != 0) {
        this->error_code = 1;
        return;
    }
    if (!this->message_panel->setup(this->render_area, this->main_view, 0, 0, 0, 0, 0)) {
        this->error_code = 1;
        return;
    }
    this->bottom_panel = new TPanel;
    if (this->bottom_panel == 0 || this->bottom_panel->error_code != 0) {
        this->error_code = 1;
        return;
    }
    if (!this->bottom_panel->setup(this->render_area, this, 0, 0, 0, 0, 0)) {
        this->error_code = 1;
        return;
    }
    this->create_all_buttons_etc();
    int idx;
    if (scenario_name_in && *scenario_name_in) {
        if (strstr(scenario_name_in, ".scn") != 0 || strstr(scenario_name_in, ".SCN") != 0) {
            char *source = scenario_name_in;
            int i = 0;
            do {
                name[i++] = source[0];
                source++;
            } while (source[0] != '.');
            name[i] = 0;
            sprintf(scenario_name_in, "%s.scx", name);
            this->world->scenario->Set_scenario_name(scenario_name_in);
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
    this->set_scenario_mode(ScenarioModeMap);
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

void TRIBE_Screen_Sed::set_string(char *text, long text_id, int max_size) {
    this->get_string(text_id, text, max_size);
}

int TRIBE_Screen_Sed::create_button(TPanel *parent, TButtonPanel **button, long text_id, int ButtonSelectFlag) {
    char str1[120];
    this->get_string(text_id, str1, 120);
    return this->create_button(parent, button, str1, 0, 0, 0);
}

int TRIBE_Screen_Sed::create_button(TPanel *parent, TButtonPanel **button,
                                    char *text1, char *text2,
                                    char *text3, char *text4) {
    if (this->TEasy_Panel::create_button(parent, button, text1, text2, 0, 0, 0, 0, RGE_FONT_ARIAL_10_NORMAL_ALT, 1, 0) == 0)
        return 0;

    if (text3 != 0)
        (*button)->set_text(2, text3);
    if (text4 != 0)
        (*button)->set_text(3, text4);

    (*button)->set_z_order(1, 0);
    (*button)->set_active(0);

    if (this->use_bevels != 0) {
        (*button)->set_bevel_info(3, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4,
                                  this->bevel_color5, this->bevel_color6);
    }

    return 1;
}

int TRIBE_Screen_Sed::create_text(TPanel *parent, TTextPanel **text_panel, long text_id) {
    int ok = this->TEasy_Panel::create_text(parent, text_panel, text_id, 0, 0, 0, 0, RGE_FONT_ARIAL_10_NORMAL_ALT, 0, 0, 0);
    if (!ok)
        return 0;
    (*text_panel)->set_z_order(1, 0);
    (*text_panel)->set_active(0);
    return 1;
}

int TRIBE_Screen_Sed::create_text(TPanel *parent, TTextPanel **text_panel, char *text) {
    int ok = this->TEasy_Panel::create_text(parent, text_panel, text, 0, 0, 0, 0, RGE_FONT_ARIAL_10_NORMAL_ALT, 0, 0, 0);
    if (!ok)
        return 0;
    (*text_panel)->set_z_order(1, 0);
    (*text_panel)->set_active(0);
    return 1;
}

int TRIBE_Screen_Sed::create_input(TPanel *parent, TInputPanel **input_panel,
                                   char *value, short max_len,
                                   TInputPanel::FormatType format_type) {
    if (this->TEasy_Panel::create_input(parent, input_panel, value, max_len,
                                        static_cast<TInputPanel::FormatType>(format_type), 0, 0, 0, 0, RGE_FONT_ARIAL_10_NORMAL_ALT) == 0) {
        return 0;
    }
    (*input_panel)->set_z_order(1, 0);
    (*input_panel)->set_active(0);
    return 1;
}

int TRIBE_Screen_Sed::create_edit(TPanel *parent, TEditPanel **edit_panel,
                                  char *value, short max_len,
                                  TEditPanel::FormatType format_type, int enable_ime,
                                  int turn_ime_on) {
    int result = this->TEasy_Panel::create_edit(parent, edit_panel, value, max_len,
                                                static_cast<TEditPanel::FormatType>(format_type), 0, 0, 0, 0, RGE_FONT_ARIAL_10_NORMAL_ALT, enable_ime, turn_ime_on);
    if (result == 0)
        return 0;
    (*edit_panel)->set_z_order(1, 0);
    (*edit_panel)->set_active(0);
    return 1;
}

int TRIBE_Screen_Sed::create_drop_down(TPanel *parent, TDropDownPanel **drop_panel) {
    long height;

    if (drop_panel == &this->victory_object_list || drop_panel == &this->victory_attribute_list ||
        drop_panel == &this->victory_ages_list || drop_panel == &this->victory_tech_list ||
        drop_panel == &this->BuildList || drop_panel == &this->CityLayout || drop_panel == &this->AiRules ||
        drop_panel == &this->victory_time) {
        height = 220;
        goto create;
    }
    if (drop_panel != &this->victory_drop_down) {
        if (drop_panel == this->cinematic_input || drop_panel == this->cinematic_input + 1 ||
            drop_panel == this->cinematic_input + 2 || drop_panel == this->cinematic_input + 3 ||
            drop_panel == &this->default_terrain_drop || drop_panel == &this->map_size_drop ||
            drop_panel == &this->map_style_drop) {
            height = 170;
            goto create;
        }
        if (drop_panel == &this->player_advance_civilization_drop || drop_panel == &this->player_list ||
            drop_panel == &this->player_number_list || drop_panel == &this->unit_player_list ||
            drop_panel == &this->victory_player_list || drop_panel == &this->options_player_list ||
            drop_panel == &this->Diplomacy_player_list || drop_panel == &this->victory_enemy_player_list) {
            height = 150;
            goto create;
        }
        height = 130;
    } else {
        height = 180;
    }

create:

    if (this->TEasy_Panel::create_drop_down(parent, drop_panel, height, 100, 0, 0, height, 22, RGE_FONT_ARIAL_10_NORMAL_ALT) == 0) {
        return 0;
    }

    (*drop_panel)->set_z_order(1, 0);
    (*drop_panel)->set_active(0);
    (*drop_panel)->empty_list();

    TDropDownPanel **list;

    list = &this->map_size_drop;
    if (drop_panel == list) {
        (*list)->append_line(STRING_ID_MAP_SIZE_BASE, 0);
        (*list)->append_line(STRING_ID_MAP_SIZE_BASE + 1, 0);
        (*list)->append_line(STRING_ID_MAP_SIZE_BASE + 2, 0);
        (*list)->append_line(STRING_ID_MAP_SIZE_BASE + 3, 0);
        (*list)->append_line(STRING_ID_MAP_SIZE_BASE + 4, 0);
        (*list)->append_line(STRING_ID_MAP_SIZE_BASE + 5, 0);
        (*list)->set_line(3);
        goto done;
    } else {
        list = &this->map_style_drop;
        if (drop_panel == list) {
            (*list)->append_line(STRING_ID_MAP_TYPE_BASE, 0);
            (*list)->append_line(STRING_ID_MAP_TYPE_BASE + 1, 0);
            (*list)->append_line(STRING_ID_MAP_TYPE_BASE + 2, 0);
            (*list)->append_line(STRING_ID_MAP_TYPE_BASE + 3, 0);
            (*list)->append_line(STRING_ID_MAP_TYPE_BASE + 4, 0);
            (*list)->append_line(STRING_ID_MAP_TYPE_BASE + 5, 0);
            (*list)->append_line(STRING_ID_MAP_TYPE_BASE + 6, 0);
            (*list)->append_line(STRING_ID_MAP_TYPE_BASE + 7, 0);
            (*list)->append_line(STRING_ID_MAP_TYPE_BASE + 8, 0);
            (*list)->set_line(3);
            goto done;
        } else {
            list = &this->player_number_list;
            if (drop_panel == list) {
                int i = 0;
                do {
                    (*list)->append_line(i + STRING_ID_PLAYER_COUNT_BASE, 0);
                    i++;
                } while (i < 8);
                (*list)->set_line(0);
                goto done;
            } else {
                list = &this->victory_enemy_player_list;
                if (drop_panel == list) {
                    int i = 0;
                    do {
                        (*list)->append_line(i + STRING_ID_PLAYER_COUNT_BASE, 0);
                        i++;
                    } while (i < 8);
                    (*list)->set_line(0);
                    goto done;
                } else {
                    list = &this->victory_attribute_list;
                    if (drop_panel == list) {
                        // These attribute codes have no reviewed symbolic names.
                        (*list)->append_line(STRING_ID_VICTORY_RAZINGS, 0x2B);
                        (*list)->append_line(STRING_ID_VICTORY_CONVERSIONS, 0x29);
                        (*list)->append_line(STRING_ID_VICTORY_KILL_RATIO, 0x2C);
                        (*list)->append_line(STRING_ID_VICTORY_MILITARY_POPULATION, 0x28);
                        (*list)->append_line(STRING_ID_VICTORY_TECHNOLOGIES, 0x15);
                        (*list)->append_line(STRING_ID_VICTORY_KILLS, 0x14);
                        (*list)->append_line(STRING_ID_VICTORY_VILLAGER_POPULATION, 0x25);
                        (*list)->set_line(0);
                        goto done;
                    } else {
                        list = &this->default_terrain_drop;
                        if (drop_panel == list) {
                            (*list)->append_line(STRING_ID_DEFAULT_TERRAIN_BASE, 0);
                            (*list)->append_line(STRING_ID_DEFAULT_TERRAIN_BASE + 1, 0);
                            (*list)->append_line(STRING_ID_DEFAULT_TERRAIN_BASE + 2, 0);
                            (*list)->append_line(STRING_ID_DEFAULT_TERRAIN_BASE + 3, 0);
                            (*list)->append_line(STRING_ID_DEFAULT_TERRAIN_BASE + 4, 0);
                            (*list)->append_line(STRING_ID_DEFAULT_TERRAIN_BASE + 5, 0);
                            (*list)->append_line(STRING_ID_DEFAULT_TERRAIN_BASE + 6, 0);
                            (*list)->append_line(STRING_ID_DEFAULT_TERRAIN_BASE + 7, 0);
                            (*list)->append_line(STRING_ID_DEFAULT_TERRAIN_BASE + 8, 0);
                            (*list)->set_line(0);
                            goto done;
                        } else {
                            list = this->player_setting_drop;
                            if (drop_panel == list) {
                                (*list)->append_line(STRING_ID_PLAYER_SETTING_COMPUTER, 0);
                                (*list)->append_line(STRING_ID_PLAYER_SETTING_EITHER, 0);
                                (*list)->set_line(0);
                                goto done;
                            } else {
                                list = &this->victory_drop_down;
                                if (drop_panel == list) {
                                    (*list)->append_line(STRING_ID_VICTORY_CONDITION_OPTION_BASE, 0);
                                    (*list)->append_line(STRING_ID_VICTORY_CONDITION_OPTION_BASE + 1, 0);
                                    (*list)->append_line(STRING_ID_VICTORY_CONDITION_OPTION_BASE + 2, 0);
                                    (*list)->append_line(STRING_ID_VICTORY_CONDITION_OPTION_BASE + 3, 0);
                                    (*list)->append_line(STRING_ID_VICTORY_CONDITION_OPTION_BASE + 4, 0);
                                    (*list)->append_line(STRING_ID_VICTORY_CONDITION_OPTION_BASE + 5, 0);
                                    (*list)->append_line(STRING_ID_VICTORY_CONDITION_OPTION_BASE + 6, 0);
                                    (*list)->append_line(STRING_ID_VICTORY_CONDITION_OPTION_BASE + 7, 0);
                                    (*list)->append_line(STRING_ID_VICTORY_CONDITION_OPTION_BASE + 8, 0);
                                    (*list)->append_line(STRING_ID_VICTORY_CONDITION_OPTION_BASE + 9, 0);
                                    (*list)->append_line(STRING_ID_VICTORY_CONDITION_OPTION_BASE + 10, 0);
                                    (*list)->append_line(STRING_ID_VICTORY_CONDITION_OPTION_BASE + 11, 0);
                                    (*list)->append_line(STRING_ID_VICTORY_CONDITION_OPTION_BASE + 12, 0);
                                    (*list)->append_line(STRING_ID_VICTORY_CONDITION_OPTION_BASE + 13, 0);
                                    (*list)->append_line(STRING_ID_VICTORY_CONDITION_OPTION_BASE + 14, 0);
                                    (*list)->append_line(STRING_ID_VICTORY_CONDITION_OPTION_BASE + 15, 0);
                                    (*list)->append_line(STRING_ID_VICTORY_CONDITION_OPTION_BASE + 16, 0);
                                    (*list)->append_line(STRING_ID_VICTORY_CONDITION_OPTION_BASE + 17, 0);
                                    (*list)->append_line(STRING_ID_TECHNOLOGIES_LABEL, 0);
                                    (*list)->set_line(0);
                                    goto done;
                                } else {
                                    list = this->player_setting_drop + 1;
                                    if (drop_panel == list) {
                                        (*list)->append_line(STRING_ID_CIVILIZATION_EGYPTIAN, 0);
                                        (*list)->append_line(STRING_ID_CIVILIZATION_GREEK, 0);
                                        (*list)->append_line(STRING_ID_CIVILIZATION_BABYLONIAN, 0);
                                        (*list)->append_line(STRING_ID_CIVILIZATION_ASSYRIAN, 0);
                                        (*list)->append_line(STRING_ID_CIVILIZATION_MINOAN, 0);
                                        (*list)->append_line(STRING_ID_CIVILIZATION_HITTITE, 0);
                                        (*list)->append_line(STRING_ID_CIVILIZATION_PHOENICIAN, 0);
                                        (*list)->append_line(STRING_ID_CIVILIZATION_SUMERIAN, 0);
                                        (*list)->append_line(STRING_ID_CIVILIZATION_PERSIAN, 0);
                                        (*list)->append_line(STRING_ID_CIVILIZATION_SHANG, 0);
                                        (*list)->append_line(STRING_ID_CIVILIZATION_YAMATO, 0);
                                        (*list)->append_line(STRING_ID_CIVILIZATION_CHOSON, 0);
                                        (*list)->append_line(STRING_ID_CIVILIZATION_ROMAN, 0);
                                        (*list)->append_line(STRING_ID_CIVILIZATION_CARTHAGINIAN, 0);
                                        (*list)->append_line(STRING_ID_CIVILIZATION_PALMYRAN, 0);
                                        (*list)->append_line(STRING_ID_CIVILIZATION_MACEDONIAN, 0);
                                        (*list)->set_line(0);
                                        goto done;
                                    } else {
                                        list = &this->victory_ages_list;
                                        if (drop_panel == list) {
                                            (*list)->append_line(STRING_ID_HELP_AGE_STONE, 0);
                                            (*list)->append_line(STRING_ID_HELP_AGE_TOOL, 0);
                                            (*list)->append_line(STRING_ID_HELP_AGE_BRONZE, 0);
                                            (*list)->append_line(STRING_ID_HELP_AGE_IRON, 0);
                                            (*list)->set_line(0);
                                            goto done;
                                        } else {
                                            list = &this->victory_tech_list;
                                            if (drop_panel == list) {
                                                this->victory_tech_list->set_sorted(1);
                                                int i = 0;
                                                if (static_cast<TRIBE_World *>(rge_base_game->world)->tech->tech_tree_num > 0) {
                                                    int offset = 0;
                                                    do {
                                                        Tech_Tree *tree = static_cast<TRIBE_World *>(rge_base_game->world)->tech->tech_tree;
                                                        Tech_Tree *entry = (Tech_Tree *)((char *)tree + offset);
                                                        char *text = this->get_string(entry->string_id);
                                                        if (text != 0 && *text != 0) {
                                                            (*list)->append_line(text, i);
                                                        }
                                                        i++;
                                                        offset += sizeof(Tech_Tree);
                                                    } while (i < static_cast<TRIBE_World *>(rge_base_game->world)->tech->tech_tree_num);
                                                }
                                                (*list)->set_line(0);
                                                goto done;
                                            } else {
                                                if (drop_panel == &this->AiRules) {
                                                    this->MakeFileList(this->AiRules, rge_base_game->prog_info->ai_dir,
                                                                       (char *)".per", 0, 1);
                                                    (*drop_panel)->set_line(0);
                                                    goto done;
                                                } else {
                                                    list = &this->BuildList;
                                                    if (drop_panel == list) {
                                                        this->MakeFileList(*list, rge_base_game->prog_info->ai_dir,
                                                                           (char *)".ai", 1, 1);
                                                        (*drop_panel)->set_line(0);
                                                        goto done;
                                                    } else {
                                                        list = &this->CityLayout;
                                                        if (drop_panel == list) {
                                                            this->MakeFileList(*list, rge_base_game->prog_info->ai_dir,
                                                                               (char *)".cty", 1, 0);
                                                            (*drop_panel)->set_line(0);
                                                            goto done;
                                                        } else {
                                                            if (drop_panel == this->cinematic_input ||
                                                                drop_panel == this->cinematic_input + 1 ||
                                                                drop_panel == this->cinematic_input + 2) {
                                                                this->MakeFileList(*drop_panel,
                                                                                   rge_base_game->prog_info->avi_dir,
                                                                                   (char *)".avi", 1, 0);
                                                                (*drop_panel)->set_line(0);
                                                                goto done;
                                                            } else {
                                                                if (drop_panel == this->cinematic_input + 3) {
                                                                    this->MakeFileList(*drop_panel, s_592A40,
                                                                                       (char *)".bmp", 1, 0);
                                                                    (*drop_panel)->set_line(0);
                                                                    goto done;
                                                                } else {
                                                                    list = &this->victory_object_list;
                                                                    if (drop_panel != list) {
                                                                        goto done;
                                                                    }

                                                                    this->victory_object_list->set_sorted(1);
                                                                    this->victory_object_list->empty_list();

                                                                    int i = 0;
                                                                    RGE_Player *player = this->world->players[1];
                                                                    int count = player->master_object_num;
                                                                    if (count > 0) {
                                                                        char str[256];
                                                                        do {
                                                                            RGE_Master_Static_Object *object = player->master_objects[i];
                                                                            if (object != 0 && object->hide_in_scenario_editor == 0) {
                                                                                if (object->string_id > 0) {
                                                                                    rge_base_game->get_string(object->string_id, str, 256);
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

int TRIBE_Screen_Sed::SetupListOfTerrain(TListPanel *list) {
    list->empty_list();
    list->append_line(STRING_ID_DEFAULT_TERRAIN_BASE, 0);
    list->append_line(STRING_ID_DEFAULT_TERRAIN_BASE + 1, 0);
    list->append_line(STRING_ID_DEFAULT_TERRAIN_BASE + 2, 0);
    list->append_line(STRING_ID_DEFAULT_TERRAIN_BASE + 3, 0);
    list->append_line(STRING_ID_DEFAULT_TERRAIN_BASE + 4, 0);
    list->append_line(STRING_ID_DEFAULT_TERRAIN_BASE + 5, 0);
    list->append_line(STRING_ID_DEFAULT_TERRAIN_BASE + 6, 0);
    list->append_line(STRING_ID_DEFAULT_TERRAIN_BASE + 7, 0);
    list->append_line(STRING_ID_DEFAULT_TERRAIN_BASE + 8, 0);
    return 8;
}

int TRIBE_Screen_Sed::create_list(TPanel *parent, TListPanel **list_panel, TScrollBarPanel **scrollbar_panel) {
    char str1[50];
    char str2[60];
    int i;

    if (this->TEasy_Panel::create_list(parent, list_panel, 0, 0, 0, 0, RGE_FONT_ARIAL_10_NORMAL_ALT) == 0)
        return 0;

    (*list_panel)->set_active(0);
    (*list_panel)->empty_list();

    if (this->TEasy_Panel::create_auto_scrollbar(scrollbar_panel, *list_panel, 20) == 0)
        return 0;

    if (list_panel == &this->paint_elevation_list) {
        this->set_string(str1, STRING_ID_TERRAIN_ELEVATION_LABEL, 50);
        for (i = 0; i < 7; i++) {
            sprintf(str2, "%s %d", str1, i + 1);
            this->paint_elevation_list->append_line(str2, 0);
        }
        return 1;
    }

    if (list_panel == &this->paint_terrain_list) {
        this->SetupListOfTerrain(this->paint_terrain_list);
    }

    return 1;
}

TRIBE_Screen_Sed::~TRIBE_Screen_Sed() {
    int i;
    panel_system.destroyPanel(s_QuitSaveDialog);
    panel_system.destroyPanel(s_OpenSaveDialog);
    panel_system.destroyPanel(s_NewSaveDialog);
    panel_system.destroyPanel(s_Save_Game_Screen);
    panel_system.destroyPanel(s_Scenario_Menu_Dialog);

    this->delete_panel(reinterpret_cast<TPanel **>(&this->map_type_label));
    for (i = 0; i < 3; ++i) {
        this->delete_panel(reinterpret_cast<TPanel **>(&this->map_type_button[i]));
        this->delete_panel(reinterpret_cast<TPanel **>(&this->map_type_text[i]));
    }
    this->delete_panel(reinterpret_cast<TPanel **>(&this->default_terrain_label));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->default_terrain_drop));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->map_size_label));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->map_size_drop));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->map_style_drop));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->map_style_label));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->map_generating_text));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->random_seed_label));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->random_seed_input));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->random_seed_used_label));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->random_seed_used_text));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->generate_map_button));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->brush_size_label));
    for (i = 0; i < 5; ++i) {
        this->delete_panel(reinterpret_cast<TPanel **>(&this->brush_size_button[i]));
        this->delete_panel(reinterpret_cast<TPanel **>(&this->brush_size_button_label[i]));
    }
    this->delete_panel(reinterpret_cast<TPanel **>(&this->paint_type_label));
    for (i = 0; i < 3; ++i) {
        this->delete_panel(reinterpret_cast<TPanel **>(&this->paint_type_button[i]));
        this->delete_panel(reinterpret_cast<TPanel **>(&this->paint_type_button_label[i]));
    }
    this->delete_panel(reinterpret_cast<TPanel **>(&this->paint_terrain_label));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->paint_terrain_list));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->paint_terrain_scrollbar));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->paint_elevation_list));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->paint_elevation_scrollbar));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->player_advance_civilization_drop));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->player_label));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->player_starting_age_label));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->player_build_text));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->player_city_text));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->AiRules_text));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->player_list));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->player_number_list));
    for (i = 0; i < 5; ++i) {
        this->delete_panel(reinterpret_cast<TPanel **>(&this->player_inven_label[i]));
        this->delete_panel(reinterpret_cast<TPanel **>(&this->player_inven_input[i]));
    }
    for (i = 0; i < 2; ++i) {
        this->delete_panel(reinterpret_cast<TPanel **>(&this->player_setting_label[i]));
        this->delete_panel(reinterpret_cast<TPanel **>(&this->player_setting_drop[i]));
    }
    this->delete_panel(reinterpret_cast<TPanel **>(&this->BuildList));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->CityLayout));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->AiRules));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->unit_player_list));
    for (i = 0; i < 4; ++i) {
        this->delete_panel(reinterpret_cast<TPanel **>(&this->unit_mode_select[i]));
        this->delete_panel(reinterpret_cast<TPanel **>(&this->unit_mode_select_label[i]));
    }
    this->delete_panel(reinterpret_cast<TPanel **>(&this->unit_list));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->unit_scrollbar));
    if (this->unit_list_info != 0) {
        free(this->unit_list_info);
        this->unit_list_info = 0;
    }
    if (this->object_panel != 0) {
        delete this->object_panel;
        this->object_panel = 0;
    }
    if (this->button_unit_pics != 0) {
        delete this->button_unit_pics;
        this->button_unit_pics = 0;
    }
    {
        TShape **pp = this->button_bldg_pics;
        int count = 5;
        do {
            TShape *p = *pp;
            if (p != 0) {
                delete p;
                *pp = 0;
            }
            pp++;
            count--;
        } while (count != 0);
    }
    for (i = 0; i < 6; ++i)
        this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_cond_on[i]));
    for (i = 0; i < 2; ++i) {
        this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_and_or[i]));
        this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_text_and_or[i]));
    }
    this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_amount_label));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_long_label));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_condition_label));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_label_conquest));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_label_explore));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_label_explore_percent));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_label_ruins));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_label_artifacts));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_label_discoveries));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_label_gold));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_condition_explore));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_condition_ruins));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_condition_artifacts));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_condition_discoveries));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_condition_gold));
    for (i = 0; i < 5; ++i) {
        this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_cond_type_label[i]));
        this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_cond_type[i]));
    }
    this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_score_label));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_score));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_time_label));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_time));
    for (i = 0; i < 12; ++i)
        this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_button[i]));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_drop_down));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_object_list));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_player_list));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_ages_list));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_tech_list));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_button_set_object));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_button_set_destination));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_button_go_to_dest));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_condition_text));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_condition_type));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_amount_text));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_amount_input));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_enemy_player_list));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_attribute_list));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_which_enemy_text));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->victory_object_scrollbar));
    for (i = 0; i < 5; ++i) {
        this->delete_panel(reinterpret_cast<TPanel **>(&this->message_button[i]));
        this->delete_panel(reinterpret_cast<TPanel **>(&this->message_button_label[i]));
    }
    this->delete_panel(reinterpret_cast<TPanel **>(&this->message_input));
    for (i = 0; i < 4; ++i) {
        this->delete_panel(reinterpret_cast<TPanel **>(&this->cinematic_label[i]));
        this->delete_panel(reinterpret_cast<TPanel **>(&this->cinematic_input[i]));
    }
    for (i = 0; i < 1; ++i) {
        this->delete_panel(reinterpret_cast<TPanel **>(&this->options_label[i]));
        this->delete_panel(reinterpret_cast<TPanel **>(&this->options_button[i]));
    }
    this->delete_panel(reinterpret_cast<TPanel **>(&this->options_player_list));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->options_disable_tech_text));
    for (i = 0; i < 16; ++i) {
        this->delete_panel(reinterpret_cast<TPanel **>(&this->options_disable_button[i]));
        this->delete_panel(reinterpret_cast<TPanel **>(&this->options_disable_text[i]));
    }
    for (i = 0; i < 8; ++i) {
        this->delete_panel(reinterpret_cast<TPanel **>(&this->Diplomacy_player_list));
        this->delete_panel(reinterpret_cast<TPanel **>(&this->Diplomacy_player_text[i]));
        this->delete_panel(reinterpret_cast<TPanel **>(&this->Diplomacy_friend_box[i][0]));
        this->delete_panel(reinterpret_cast<TPanel **>(&this->Diplomacy_friend_box[i][1]));
        this->delete_panel(reinterpret_cast<TPanel **>(&this->Diplomacy_friend_box[i][2]));
        this->delete_panel(reinterpret_cast<TPanel **>(&this->Diplomacy_AlliedVictory[i]));
    }
    this->delete_panel(reinterpret_cast<TPanel **>(&this->Diplomacy_status_label[0]));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->Diplomacy_status_label[1]));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->Diplomacy_status_label[2]));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->Diplomacy_status_label[3]));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->menu_button));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->help_button));
    for (i = 0; i < 10; ++i)
        this->delete_panel(reinterpret_cast<TPanel **>(&this->scenario_mode_button[i]));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->bottom_panel));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->message_panel));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->main_view));
    this->delete_panel(reinterpret_cast<TPanel **>(&this->map_view));
    if (this->background_pic != 0) {
        TShape *p = this->background_pic;
        delete p;
        this->background_pic = 0;
    }
    if (this->world != 0) {
        this->world->del_game_info();
    }
}

void TRIBE_Screen_Sed::set_scenario_mode(TRIBE_Screen_Sed::ScenarioMode new_mode) {
    int mode;
    int activate_counter = 0;
    int active = 0;
    int i;

    this->valid_save_spot_flag = 0;
    do {
        if (activate_counter == 0) {
            mode = this->scenario_mode;
            active = 0;
        } else {
            if (new_mode != ScenarioModeSave) {
                mode = new_mode;
            }
            active = 1;
        }

        switch (mode) {
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
                    static_cast<T_Scenario *>(this->world->scenario)->GetPlayerAge(this->player_num - 1));
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
                            static_cast<TRIBE_Player *>(rge_base_game->get_player()));
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
                char *text = this->world->scenario->Get_message(this->current_message);
                this->message_input->set_text(text);
                switch (this->current_message) {
                case 0:
                        this->message_input->set_help_info(STRING_ID_HELP_EDIT_SCENARIO_INSTRUCTIONS, -1);
                    break;
                case 1:
                        this->message_input->set_help_info(STRING_ID_HELP_EDIT_SCENARIO_HINTS, -1);
                    break;
                case 2:
                        this->message_input->set_help_info(STRING_ID_HELP_EDIT_VICTORY_MESSAGE, -1);
                    break;
                case 3:
                        this->message_input->set_help_info(STRING_ID_HELP_EDIT_LOSS_MESSAGE, -1);
                    break;
                case 4:
                        this->message_input->set_help_info(STRING_ID_HELP_EDIT_HISTORY, -1);
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
                long player_line;
                i = 0;
                player_line = this->player_number_list->get_line();
                if (player_line >= 0) {
                    do {
                        this->Diplomacy_player_text[i]->set_active(active);
                        TButtonPanel *p = this->Diplomacy_AlliedVictory[i];
                        if (i != this->player_num - 1) {
                            p->set_active(0);
                            this->Diplomacy_friend_box[i][0]->set_active(active);
                            this->Diplomacy_friend_box[i][1]->set_active(active);
                            p = this->Diplomacy_friend_box[i][2];
                        }
                        p->set_active(active);
                        i++;
                        player_line = this->player_number_list->get_line();
                    } while (i <= player_line);
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
                this->options_button[0]->set_state(static_cast<T_Scenario *>(this->world->scenario)->GetScenarioOption(2));
                this->LoadDisabledItemsFromScenario();
                if (this->player_num != 0) {
                    this->options_player_list->setCurrentLineNumber(this->player_num - 1);
                } else {
                    this->options_player_list->setCurrentLineNumber(0);
                }
            }
            i = 0;
            do {
                this->options_label[i]->set_active(active);
                this->options_button[i]->set_active(active);
                i++;
            } while (i < 1);
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

        activate_counter++;
    } while (activate_counter < 2);

    if (new_mode != ScenarioModeSave) {
        this->scenario_mode = new_mode;
        if (new_mode != ScenarioModeNone) {
            this->scenario_mode_button[new_mode - 1]->set_radio_button();
        }
        this->handle_size(this->pnl_wid, this->pnl_hgt);
        this->set_redraw(TPanel::RedrawNormal);
    }
    this->valid_save_spot_flag = 1;
}

void TRIBE_Screen_Sed::set_paint_object_mode() {
    RGE_Base_Game *game = rge_base_game;
    int mo_id = static_cast<short>(game->master_obj_id);
    int enabled = 0;

    if (mo_id != -1) {
        int pn = this->player_num;
        RGE_Master_Static_Object *obj = this->world->players[pn]->master_objects[mo_id];

        if (obj != 0 && obj->master_type == 0x50 &&
            static_cast<TRIBE_Master_Building_Object *>(obj)->building_connect_flag != 0) {
            enabled = 1;
        }
    }

    if (enabled) {
        game->set_game_mode(0x15, 0);
    } else {
        game->set_game_mode(8, game->sub_game_mode);
    }
}

void TRIBE_Screen_Sed::set_map_type(MapType new_val, int activate_panels) {
    int pass;
    int active;
    int mode;
    TPanel *p;

    pass = 0;
    do {
        if (pass == 0) {
            active = 0;
            mode = this->map_type;
        } else {
            if (new_val == 0) {
                return;
            }
            if (activate_panels == 0) {
                break;
            }
            mode = new_val;
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

    this->map_type = new_val;
    this->map_type_button[new_val - 1]->set_radio_button();
    this->bottom_panel->set_redraw(TPanel::RedrawNormal);
}

void TRIBE_Screen_Sed::set_mp_victory_type(VictoryType new_val, int activate_panels) {
    int activate_counter;
    int active;
    int mode;
    int i;

    activate_counter = 0;
    do {
        if (activate_counter == 0) {
            active = 0;
            mode = this->mp_victory_type;
        } else {
            if (new_val == 0) {
                return;
            }
            if (activate_panels == 0) {
                break;
            }
            active = 1;
            mode = new_val;
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
        activate_counter++;
    } while (activate_counter < 2);

    this->mp_victory_type = new_val;
    this->victory_cond_type[new_val - 1]->set_radio_button();
    this->bottom_panel->set_redraw(TPanel::RedrawNormal);
}

void TRIBE_Screen_Sed::set_brush_size(BrushSize new_val) {
    if (!new_val)
        return;
    brush_size = new_val;
    brush_size_button[new_val - 1]->set_radio_button();
    int v;
    switch (brush_size) {
    case 1:
        v = 1;
        break;
    case 2:
        v = 3;
        break;
    case 3:
        v = 5;
        break;
    case 4:
        v = 7;
        break;
    case 5:
        v = 9;
        break;
    default:
        v = 2;
        break;
    }
    rge_base_game->brush_size = v;
}

void TRIBE_Screen_Sed::set_paint_type(PaintType new_val, int activate_panels) {
    int activate_counter;
    int active;
    int val;
    int i;

    activate_counter = 0;
    do {
        if (activate_counter == 0) {
            val = this->paint_type;
            active = 0;
        } else {
            if (new_val == 0) {
                return;
            }
            if (activate_panels == 0) {
                break;
            }
            val = new_val;
            active = 1;
        }

        this->brush_size_label->set_active(active);
        for (i = 0; i < 5; ++i) {
            this->brush_size_button[i]->set_active(active);
            this->brush_size_button_label[i]->set_active(active);
        }

        switch (val) {
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
        activate_counter++;
    } while (activate_counter < 2);

    this->paint_type = new_val;
    this->paint_type_button[new_val - 1]->set_radio_button();
    this->bottom_panel->set_redraw(TPanel::RedrawNormal);
}

void TRIBE_Screen_Sed::set_terrain(short val) {
    short v;
    switch (val) {
    case 0:
        v = 0;
        break;
    case 1:
        v = 6;
        break;
    case 2:
        v = 10;
        break;
    case 3:
        v = 1;
        break;
    case 4:
        v = 0xD;
        break;
    case 5:
        v = 0x14;
        break;
    case 6:
        v = 4;
        break;
    case 7:
        v = 0x13;
        break;
    case 8:
        v = 0x16;
        break;
    default:
        v = 0;
        break;
    }
    RGE_Base_Game *game;
    game = rge_base_game;
    game->terrain_id = v;
    paint_terrain_list->scroll_cur_line(1, val, 1);
}

void TRIBE_Screen_Sed::set_elevation(short val) {
    RGE_Base_Game *base_game;

    base_game = rge_base_game;
    base_game->elevation_height = val;
    this->paint_elevation_list->scroll_cur_line(1, val, 1);
}

void TRIBE_Screen_Sed::set_player(short val, uchar save_player, uchar load_player) {
    char str[30];
    long oldp = this->player_num - 1;
    if (oldp < 0)
        oldp = 0;

    rge_base_game->get_player()->unselect_object();

    if (save_player) {
        int amount;
        amount = atoi(this->player_inven_input[0]->currentLine());
        static_cast<T_Scenario *>(this->world->scenario)->Set_player_Food(oldp, amount);
        this->world->players[this->player_num]->attributes[0] = amount;

        amount = atoi(this->player_inven_input[1]->currentLine());
        static_cast<T_Scenario *>(this->world->scenario)->Set_player_Wood(oldp, amount);
        this->world->players[this->player_num]->attributes[1] = amount;

        amount = atoi(this->player_inven_input[2]->currentLine());
        static_cast<T_Scenario *>(this->world->scenario)->Set_player_Stone(oldp, amount);
        this->world->players[this->player_num]->attributes[2] = amount;

        amount = atoi(this->player_inven_input[3]->currentLine());
        static_cast<T_Scenario *>(this->world->scenario)->Set_player_Gold(oldp, amount);
        this->world->players[this->player_num]->attributes[3] = amount;

        this->world->scenario->SetPlayerName(oldp, this->player_inven_input[4]->currentLine());
        this->world->scenario->Set_player_Type(oldp, this->player_setting_drop[0]->currentLineNumber());
        this->world->scenario->Set_player_Civ(oldp, this->player_setting_drop[1]->currentLineNumber() + 1);
        this->world->scenario->Set_player_AI(oldp, this->AiRules->currentLine(), 0);
        this->world->scenario->Set_BuildList(oldp, this->BuildList->currentLine(), 0);
        this->world->scenario->Set_CityPlan(oldp, this->CityLayout->currentLine(), 0);
    }

    long p = val - 1;
    this->player_num = val;
    if (val != 0) {
        this->player_list->set_line(p);
        rge_base_game->set_player(val);
        if (load_player == 1) {
            int v;
            v = static_cast<T_Scenario *>(this->world->scenario)->Get_player_Food(p);
            sprintf(str, "%d", v);
            this->player_inven_input[0]->set_text(str);
            v = static_cast<T_Scenario *>(this->world->scenario)->Get_player_Wood(p);
            sprintf(str, "%d", v);
            this->player_inven_input[1]->set_text(str);
            v = static_cast<T_Scenario *>(this->world->scenario)->Get_player_Stone(p);
            sprintf(str, "%d", v);
            this->player_inven_input[2]->set_text(str);
            v = static_cast<T_Scenario *>(this->world->scenario)->Get_player_Gold(p);
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

void TRIBE_Screen_Sed::set_player_active(short player_num_in, int active_in) {
    this->world->scenario->Set_player_Active(player_num_in, active_in);
}

int __cdecl TRIBE_Screen_Sed_unit_list_compare(const void *arg1, const void *arg2) {
    int result = CompareStringA(LOCALE_USER_DEFAULT, NORM_IGNORECASE, static_cast<const char *>(arg1), -1,
                                static_cast<const char *>(arg2), -1);
    if (result == 1) {
        return -1;
    }
    return result == 3;
}

void TRIBE_Screen_Sed::set_unit_player(short val) {
    int is_error;
    float save_view_x;
    float save_view_y;
    short save_map_x;
    short save_map_y;

    RGE_Player *oldp = rge_base_game->get_player();
    save_view_x = oldp->view_x;
    save_view_y = oldp->view_y;
    save_map_x = oldp->map_x;
    save_map_y = oldp->map_y;
    rge_base_game->set_player(val);
    this->player_num = val;

    RGE_Player *player = rge_base_game->get_player();
    player->set_view_loc(save_view_x, save_view_y);
    player->set_map_loc(save_map_x, save_map_y);
    this->main_view->set_player(player);
    this->map_view->set_player(player);
    this->unit_player_list->setCurrentLineNumber(val);
    this->unit_list->empty_list();
    if (this->unit_list_info != 0) {
        free(this->unit_list_info);
        this->unit_list_info = 0;
    }
    if (player != 0) {
        this->unit_list_size = 1;
        short n = player->master_object_num;
        if (n > 0) {
            int count = n;
            int index = 0;
            do {
                RGE_Master_Static_Object *m = player->master_objects[index];
                if (m != 0 && m->hide_in_scenario_editor == 0)
                    this->unit_list_size++;
                ++index;
                --count;
            } while (count != 0);
        }
        if (this->unit_list_size == 0)
            return;
        this->unit_list_info = static_cast<List_Info *>(calloc(this->unit_list_size, sizeof(List_Info)));
        if (this->unit_list_info == 0)
            return;
        this->unit_list_info[0].id = -1;
        this->set_string(this->unit_list_info[0].text, STRING_ID_FILE_NONE, 20);

        short out = 1; // The original loads this index as a word.
        short i = 0;
        // the offset zero store follows the positive-count test.
        if (n > 0) {
            int master_index = 0;
            do {
                RGE_Master_Static_Object *m = player->master_objects[master_index];
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
        char **list = static_cast<char **>(calloc(this->unit_list_size, sizeof(char *)));
        if (list == 0)
            return;
        is_error = 0;
        short selected = 0;
        for (i = 0; i < this->unit_list_size; i++) {
            char *s = static_cast<char *>(calloc(100, sizeof(char)));
            list[i] = s;
            if (s == 0) {
                is_error = 1;
                break;
            }
            strcpy(s, this->unit_list_info[i].text);
            if (this->unit_list_info[i].id == rge_base_game->master_obj_id)
                selected = i;
        }
        if (!is_error) {
            this->unit_list->set_text(list, this->unit_list_size);
            this->unit_list->scroll_cur_line(1, selected, 1);
        }
        for (i = 0; i < this->unit_list_size; i++) {
            if (list[i] != 0)
                free(list[i]);
        }
        free(list);
    }
}

void TRIBE_Screen_Sed::set_unit(short val) {
    if (val == -1) {
        rge_base_game->master_obj_id = val;
    } else {
        rge_base_game->master_obj_id = unit_list_info[val].id;
    }

    unit_list->scroll_cur_line(1, val, 1);
}

void TRIBE_Screen_Sed::set_message_type(MessageType new_val, int activate_panels) {
    message_input->set_active(activate_panels);
    bottom_panel->set_redraw(TPanel::RedrawNormal);
}

long TRIBE_Screen_Sed::handle_size(long win_wid, long win_hgt) {
    TPanel::handle_size(win_wid, win_hgt);
    this->position_panels();
    TPanel::handle_size(win_wid, win_hgt);
    return 0;
}

long TRIBE_Screen_Sed::handle_idle() {
    if (rge_base_game->prog_mode == 7) {
        unsigned long now = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_sed_cp, 2225);
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

long TRIBE_Screen_Sed::key_down_action(long key, short count,
                                       int alt_key, int ctrl_key, int shift_key) {
    if (panel_system.modalPanel() == 0) {
        if (ctrl_key != 0) {
            switch (key) {
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

        switch (key) {
        case 0x30:
        case 0x31:
        case 0x32:
        case 0x33:
        case 0x34:
        case 0x35:
        case 0x36:
        case 0x37:
        case 0x38: {
            int mode = this->scenario_mode;
            int i = key - 0x30;
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
        } break;
        case 9:
            if (this->scenario_mode == ScenarioModePlayers) {
                if (this->bottom_panel->curr_child == 0) {
                    this->bottom_panel->set_curr_child(this->player_inven_input[0]);
                    return 0;
                }
            } else if ((this->scenario_mode == ScenarioModeVictory) && (this->bottom_panel->curr_child == 0) &&
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
                RGE_Player *player = rge_base_game->get_player();
                RGE_Static_Object *object = player->selected_obj;
                if (object != 0) {
                    uchar draw_level;
                    if (object->sprite_list != 0) {
                        draw_level = object->sprite_list->get_lowest_draw_level();
                    } else if (object->sprite != 0) {
                        draw_level = object->sprite->get_lowest_draw_level();
                    } else {
                        draw_level = 0x14;
                    }
                    delete object;
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

long TRIBE_Screen_Sed::action(TPanel *from_panel, long action_in,
                              unsigned long action_val1, unsigned long action_val2) {
    int i;
    int map_size;
    int player_count;
    int center;
    long line;
    long x1;
    long y1;
    long y2;
    long x2;
    char random_val[24];
    long old_seed;
    float cy;
    float cx;

    if (from_panel == 0) {
        return 0;
    }

    if (from_panel != this->main_view) {
        RGE_Static_Object *selected_object = this->SelectedObject;
        if (selected_object != 0) {
            rge_base_game->get_player()->select_one_object(selected_object, 0);
        }
        RGE_Static_Object *destination_object = this->DestinationObject;
        if (destination_object != 0) {
            rge_base_game->get_player()->select_one_object(destination_object, 0);
        }
    }

    if (action_in == 0) {
        if (from_panel == this->random_seed_input || from_panel == this->player_inven_input[0] ||
            from_panel == this->player_inven_input[1] || from_panel == this->player_inven_input[2] ||
            from_panel == this->player_inven_input[3] || from_panel == this->player_inven_input[4] ||
            from_panel == this->player_setting_label[0] || from_panel == this->victory_condition_explore ||
            from_panel == this->victory_condition_ruins || from_panel == this->victory_condition_artifacts ||
            from_panel == this->victory_condition_discoveries || from_panel == this->victory_condition_gold ||
            from_panel == this->victory_amount_input || from_panel == this->message_input) {
            this->need_to_save_flag = 1;
        }
    }

    if (from_panel == this->main_view) {
        if (action_in == 0x10) {
            rge_base_game->get_player()->unselect_object();
            // but the main-view event carries an RGE_Static_Object pointer.
            RGE_Static_Object *event_object =
                reinterpret_cast<RGE_Static_Object *>(action_val1);
            if (this->SelectRegionFlag == SelectObject)
                this->SelectedObject = event_object;
            if (this->SelectRegionFlag == SelectDestinationObject)
                this->DestinationObject = event_object;
            RGE_Static_Object *selected_object = this->SelectedObject;
            if (selected_object != 0) {
                rge_base_game->get_player()->select_one_object(selected_object, 0);
            }
            RGE_Static_Object *destination_object = this->DestinationObject;
            if (destination_object != 0) {
                rge_base_game->get_player()->select_one_object(destination_object, 0);
            }
            rge_base_game->set_game_mode(0, 0);
            return 1;
        }
        if (action_in == 0x11 && rge_base_game->game_mode == 0x11) {
            rge_base_game->set_game_mode(0, 0);
        }
    }

    if (action_in == 1) {
        for (i = 0; i < 10; i++) {
            if (from_panel == this->scenario_mode_button[i]) {
                this->set_scenario_mode(static_cast<ScenarioMode>(i + ScenarioModeMap));
                return 1;
            }
        }
        if (from_panel == this->menu_button) {
            this->command_menu();
            return 1;
        }
        if (from_panel == this->help_button) {
            this->setup_popup_help();
            return 1;
        }
    } else {
        for (i = 0; i < 10; i++) {
            if (from_panel == this->scenario_mode_button[i])
                return 1;
        }
        if (from_panel == this->menu_button || from_panel == this->help_button)
            return 1;
    }

    if (from_panel->panelName() != 0 && strcmp(from_panel->panelName(), s_OKDialog) == 0) {
        if (action_in == 0) {
            panel_system.destroyPanel(s_OKDialog);
            this->set_scenario_mode(ScenarioModePlayers);
        }
        return 1;
    }

    switch (this->scenario_mode) {
    case ScenarioModeMessages:
        if (this->valid_save_spot_flag != 0)
            this->need_to_save_flag = 1;
        if (action_in == 1) {
            line = this->current_message;
            this->world->scenario->Set_message(this->message_input->get_input_buffer(), line);
            for (i = 0; i < 5; i++)
                if (from_panel == this->message_button[i]) {
                    this->current_message = i;
                    break;
                }
            this->message_input->set_text(this->world->scenario->Get_message(this->current_message));
            switch (this->current_message) {
            case 0:
                this->message_input->set_help_info(STRING_ID_HELP_EDIT_SCENARIO_INSTRUCTIONS, -1);
                break;
            case 1:
                this->message_input->set_help_info(STRING_ID_HELP_EDIT_SCENARIO_HINTS, -1);
                break;
            case 2:
                this->message_input->set_help_info(STRING_ID_HELP_EDIT_VICTORY_MESSAGE, -1);
                break;
            case 3:
                this->message_input->set_help_info(STRING_ID_HELP_EDIT_LOSS_MESSAGE, -1);
                break;
            case 4:
                this->message_input->set_help_info(STRING_ID_HELP_EDIT_HISTORY, -1);
                break;
            }
        }
        break;

    case ScenarioModeVictory:
        if (this->valid_save_spot_flag != 0)
            this->need_to_save_flag = 1;
        if ((action_in == 0 || action_in == 1) && from_panel == this->victory_player_list) {
            this->save_victory_cond_in_scenario(this->CurrentVictory);
            this->activate_victory_panel(0);
            this->activate_victory_proper_fields(0, 0);
            line = this->victory_player_list->get_line();
            this->player_num = static_cast<short>(line + 1);
            static_cast<T_Scenario *>(this->world->scenario)->SetSPWhich(this->player_num - 1);
            this->CurrentVictory = 0;
            this->load_victory_cond_from_scenario(0);
            this->activate_victory_panel(1);
            this->activate_victory_proper_fields(this->victory_drop_down->get_line(), 1);
        }
        if (action_in == 0 && from_panel == this->victory_amount_input)
            this->bottom_panel->set_curr_child(0);
        if (action_in == 2 && from_panel == this->victory_drop_down) {
            this->activate_victory_proper_fields(this->victory_drop_down->get_line(), 1);
        }
        if (action_in == 1) {
            if (from_panel != this->victory_amount_input) {
                line = this->victory_drop_down->get_line();
                if (from_panel == this->victory_drop_down) {
                    rge_base_game->set_game_mode(0, 0);
                    this->DestinationObject = 0;
                    this->SelectedObject = 0;
                    rge_base_game->get_player()->unselect_object();
                }
                if (line == 2) {
                    this->DestinationObject = 0;
                    rge_base_game->get_player()->unselect_object();
                }
                // both object-selection arms use redraw mode 0x10.
                if (from_panel == this->victory_button_set_object) {
                    this->SelectRegionFlag = SelectObject;
                    rge_base_game->set_game_mode(0x10, 0);
                    rge_base_game->get_player()->unselect_object();
                    RGE_Static_Object *destination_object = this->DestinationObject;
                    if (destination_object != 0) {
                        rge_base_game->get_player()->select_one_object(destination_object, 0);
                    }
                    return 1;
                } else {
                    if (from_panel == this->victory_button_set_destination && line != 1) {
                        this->SelectRegionFlag = SelectArea;
                        rge_base_game->get_player()->unselect_object();
                        RGE_Static_Object *selected_object = this->SelectedObject;
                        if (selected_object != 0) {
                            rge_base_game->get_player()->select_one_object(selected_object, 0);
                        }
                        rge_base_game->set_game_mode(0x11, 0);
                        return 1;
                    }
                    if (from_panel == this->victory_button_set_destination && line == 1) {
                        this->SelectRegionFlag = SelectDestinationObject;
                        rge_base_game->set_game_mode(0x10, 0);
                        rge_base_game->get_player()->unselect_object();
                        RGE_Static_Object *selected_object = this->SelectedObject;
                        if (selected_object != 0) {
                            rge_base_game->get_player()->select_one_object(selected_object, 0);
                        }
                        return 1;
                    } else if (from_panel == this->victory_button_go_to_dest && line != 1) {
                        this->main_view->get_selection_area(y1, y2, x1, x2, 1);
                        cy = static_cast<float>(x1);
                        this->px1 = static_cast<float>(y1);
                        this->py1 = static_cast<float>(y2);
                        this->SelectRegionFlag = SelectOff;
                        cx = static_cast<float>(x2);
                        this->px2 = cy;
                        this->py2 = cx;
                        if (cy == -1.0f) {
                            return 1;
                        }
                        cy = cy - (cy - static_cast<float>(y1)) * 0.5f;
                        cx = cx - (cx - static_cast<float>(y2)) * 0.5f;
                        rge_base_game->get_player()->set_view_loc(cy, cx);
                        rge_base_game->get_player()->set_map_loc(static_cast<short>(cy), static_cast<short>(cx));
                        return 1;
                    } else {
                        if (from_panel == this->victory_drop_down) {
                            this->activate_victory_proper_fields(this->victory_drop_down->get_line(), 0);
                        }
                        for (i = 0; i < 12; i++) {
                            if (from_panel == this->victory_button[i] && this->CurrentVictory != i) {
                                this->activate_victory_proper_fields(this->victory_drop_down->get_line(), 0);
                                this->save_victory_cond_in_scenario(this->CurrentVictory);
                                this->activate_victory_panel(0);
                                rge_base_game->get_player()->unselect_object();
                                this->CurrentVictory = i;
                                this->load_victory_cond_from_scenario(i);
                                this->activate_victory_panel(1);
                                this->activate_victory_proper_fields(this->victory_drop_down->get_line(), 1);
                                RGE_Static_Object *selected_object = this->SelectedObject;
                                if (selected_object != 0) {
                                    rge_base_game->get_player()->select_one_object(selected_object, 0);
                                }
                                RGE_Static_Object *destination_object = this->DestinationObject;
                                if (destination_object != 0) {
                                    rge_base_game->get_player()->select_one_object(destination_object, 0);
                                }
                            }
                        }
                    }
                }
            } else {
                return 1;
            }
        }
        break;

    case ScenarioModeMap:
        if (this->valid_save_spot_flag != 0)
            this->need_to_save_flag = 1;
        if (action_in == 1) {
            for (i = 0; i < 3; i++) {
                if (from_panel == this->map_type_button[i]) {
                    this->set_map_type(static_cast<MapType>(i + MapTypeBlankValue), 1);
                    return 1;
                }
            }
            if (from_panel == this->generate_map_button) {
                this->map_generating_text->set_active(1);
                this->set_redraw(TPanel::RedrawImmediate);
                InvalidateRect(rge_base_game->prog_window, 0, 0);
                rge_base_game->draw_window();
                i = this->map_size_drop->currentLineNumber();
                int map_style = this->map_style_drop->currentLineNumber();
                switch (i) {
                case 0:
                    map_size = 72;
                    break;
                case 1:
                    map_size = 96;
                    break;
                case 2:
                    map_size = 120;
                    break;
                case 3:
                    map_size = 144;
                    break;
                case 4:
                    map_size = 200;
                    break;
                case 5:
                    map_size = 250;
                    break;
                default:
                    map_size = map_style;
                    break;
                }
                player_count = this->player_number_list->get_line() + 1;
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
                    old_seed = rge_base_game->random_map_seed;
                    if (this->map_type == MapTypeSeedValue) {
                        rge_base_game->random_map_seed = atoi(this->random_seed_input->currentLine());
                    } else {
                        rge_base_game->random_map_seed = -1;
                    }
                    for (i = 0; i < 9; i++)
                        this->world->players[i]->reset_selected();
                    this->world->map->map_generate2(this->world, map_size, map_size,
                                                    static_cast<unsigned char>(map_style), player_count);
                    rge_base_game->random_map_seed = old_seed;
                    itoa(rge_base_game->save_random_map_seed, random_val, 10);
                    this->random_seed_used_text->set_text(random_val);
                    debug_rand(s_C__msdev_work_age1_x1_scr_sed_cp, 2904);
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
        if (this->valid_save_spot_flag != 0)
            this->need_to_save_flag = 1;
        if (action_in == 2 || action_in == 1) {
            if (from_panel == this->paint_terrain_list) {
                i = this->paint_terrain_list->currentLineNumber();
                this->set_terrain(static_cast<short>(i));
                this->brush_size_button[0]->set_active(1);
                return 1;
            } else if (from_panel == this->paint_elevation_list) {
                i = this->paint_elevation_list->currentLineNumber();
                this->set_elevation(static_cast<short>(i));
                return 1;
            } else if (action_in == 1) {
                if (this->valid_save_spot_flag != 0)
                    this->need_to_save_flag = 1;
                for (i = 0; i < 5; i++) {
                    if (from_panel == this->brush_size_button[i]) {
                        this->set_brush_size(static_cast<BrushSize>(i + BrushSizeVerySmall));
                        return 1;
                    }
                }
                for (i = 0; i < 3; i++) {
                    if (from_panel == this->paint_type_button[i]) {
                        this->set_paint_type(static_cast<PaintType>(i + PaintTypeTerrainValue), 1);
                        return 1;
                    }
                }
            }
        }
        break;

    case ScenarioModePlayers:
        if (this->valid_save_spot_flag != 0)
            this->need_to_save_flag = 1;
        if (action_in == 0) {
            for (i = 0; i < 5; i++)
                if (from_panel == this->player_inven_input[i]) {
                    this->bottom_panel->set_curr_child(0);
                    break;
                }
        }
        if (action_in == 0) {
            if (this->valid_save_spot_flag != 0)
                this->need_to_save_flag = 1;
            if (from_panel == this->player_advance_civilization_drop) {
                if (this->valid_save_spot_flag != 0)
                    this->need_to_save_flag = 1;
                i = this->player_advance_civilization_drop->currentLineNumber();
                static_cast<T_Scenario *>(this->world->scenario)->SetPlayerAge(this->player_num - 1, i);
            }
            if (from_panel == this->player_list) {
                this->set_player(static_cast<short>(this->player_list->get_line() + 1), 1, 1);
                line = this->player_list->get_line();
                i = static_cast<T_Scenario *>(this->world->scenario)->GetPlayerAge(line);
                this->player_advance_civilization_drop->setCurrentLineNumber(i);
            }
            if (from_panel == this->player_number_list) {
                this->set_player(this->player_num, 1, 0);
                this->SavePlayerActiveStatus();
                this->set_player(this->player_num, 0, 1);
            }
        }
        if (action_in == 1 && from_panel == this->player_advance_civilization_drop) {
            i = this->player_advance_civilization_drop->currentLineNumber();
            static_cast<T_Scenario *>(this->world->scenario)->SetPlayerAge(this->player_num - 1, i);
        }
        break;

    case ScenarioModeUnits:
        if (this->valid_save_spot_flag != 0)
            this->need_to_save_flag = 1;
        if (action_in == 0) {
            if (this->valid_save_spot_flag != 0)
                this->need_to_save_flag = 1;
            if (from_panel == this->unit_player_list) {
                line = this->unit_player_list->get_line();
                this->set_unit_player(static_cast<short>(line));
                line = this->unit_player_list->get_line();
                if (line == 0) {
                    // the shipped path redraws with status 3.
                    rge_base_game->set_game_mode(rge_base_game->game_mode, 3);
                } else {
                    rge_base_game->set_game_mode(rge_base_game->game_mode, 4);
                    // master ownership is world->players[id].
                    if (rge_base_game->master_obj_id == -1 || rge_base_game->get_player() == 0) {
                        this->object_panel->set_master_info(0, 0);
                    } else {
                        short master_id = rge_base_game->master_obj_id;
                        this->object_panel->set_master_info(
                            this->world->players[rge_base_game->get_player()->id]->master_objects[master_id],
                            static_cast<TRIBE_Player *>(rge_base_game->get_player()));
                    }
                    this->set_paint_object_mode();
                    this->object_panel->set_redraw(TPanel::RedrawImmediate);
                    return 1;
                }
            }
        }
        if (action_in == 2 || action_in == 1) {
            if (from_panel == this->unit_list) {
                i = this->unit_list->currentLineNumber();
                this->set_unit(static_cast<short>(i));
                if (rge_base_game->game_mode != 8 && rge_base_game->game_mode != 0x15)
                    this->unit_mode_select[0]->set_radio_button();
                if (rge_base_game->master_obj_id == -1 || rge_base_game->get_player() == 0) {
                    this->object_panel->set_master_info(0, 0);
                } else {
                    short master_id = rge_base_game->master_obj_id;
                    this->object_panel->set_master_info(
                        this->world->players[rge_base_game->get_player()->id]->master_objects[master_id],
                        static_cast<TRIBE_Player *>(rge_base_game->get_player()));
                }
                this->set_paint_object_mode();
                this->object_panel->set_redraw(TPanel::RedrawNormal);
                return 1;
            }
            if (action_in == 1) {
                if (from_panel == this->unit_mode_select[0])
                    this->set_paint_object_mode();
                else if (from_panel == this->unit_mode_select[1]) {
                    rge_base_game->get_player()->unselect_object();
                    rge_base_game->set_game_mode(0xE, 0);
                } else if (from_panel == this->unit_mode_select[2])
                    rge_base_game->set_game_mode(0xF, 0);
                else if (from_panel == this->unit_mode_select[3])
                    rge_base_game->set_game_mode(0x14, 0);
            }
        }
        break;

    case ScenarioModeVictoryMulti:
        if (this->valid_save_spot_flag != 0)
            this->need_to_save_flag = 1;
        if (action_in == 1) {
            for (i = 0; i < 5; i++) {
                if (from_panel == this->victory_cond_type[i]) {
                    this->set_mp_victory_type(static_cast<VictoryType>(i + VictoryTypeStandardValue), 1);
                    if (i != 4) {
                        static_cast<T_Scenario *>(this->world->scenario)->Set_Multi_Conquest(1);
                        this->victory_cond_on[0]->set_state(1);
                    }
                    return 1;
                }
            }
        }
        break;

    case ScenarioModeDiplomacy:
        if (this->valid_save_spot_flag != 0)
            this->need_to_save_flag = 1;
        if (action_in == 0 || action_in == 1) {
            if (from_panel == this->Diplomacy_player_list) {
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
            if (action_in == 1) {
                this->save_diplomacy_in_scenario(this->player_num - 1);
                return 1;
            }
        }
        break;

    case ScenarioModeOptions:
        if (this->valid_save_spot_flag != 0)
            this->need_to_save_flag = 1;
        if (action_in == 1) {
            this->SaveDisabledItemsInScenario();
            this->LoadDisabledItemsFromScenario();
            if (from_panel == this->options_button[0]) {
                i = this->options_button[0]->get_state();
                static_cast<T_Scenario *>(this->world->scenario)->SetScenarioOption(2, i);
            }
        }
        break;
    }

    if (from_panel->panelName() != 0 && strcmp(from_panel->panelName(), s_QuitSaveDialog) == 0) {
        panel_system.setCurrentPanel(s_Scenario_Editor_Screen, 0);
        panel_system.destroyPanel(s_QuitSaveDialog);
        if (action_in == 0)
            this->command_save(static_cast<unsigned char>(action_in), 1);
        else if (action_in == 1) {
            if (static_cast<TRIBE_Game *>(rge_base_game)->start_menu() == 0)
                rge_base_game->close();
            else
                panel_system.destroyPanel(s_Scenario_Editor_Screen);
        }
        return 1;
    }

    if (from_panel->panelName() != 0 && strcmp(from_panel->panelName(), s_OpenSaveDialog) == 0) {
        panel_system.setCurrentPanel(s_Scenario_Editor_Screen, 0);
        panel_system.destroyPanel(s_OpenSaveDialog);
        if (action_in == 0)
            this->command_save(static_cast<unsigned char>(action_in), 2);
        else if (action_in == 1) {
            new TRIBE_Screen_Sed_Open;
            panel_system.setCurrentPanel(s_Scenario_Editor_Open, 0);
        }
        return 1;
    }

    if (from_panel->panelName() != 0 && strcmp(from_panel->panelName(), s_NewSaveDialog) == 0) {
        panel_system.setCurrentPanel(s_Scenario_Editor_Screen, 0);
        panel_system.destroyPanel(s_NewSaveDialog);
        if (action_in == 0)
            this->command_save(static_cast<unsigned char>(action_in), 3);
        else if (action_in == 1)
            static_cast<TRIBE_Game *>(rge_base_game)->start_scenario_editor(0, 0);
        return 1;
    }

    return 0;
}

void TRIBE_Screen_Sed::draw() {
    tagRECT rect;

    this->TEasy_Panel::draw();

    if (use_bevels != 0 && main_view != 0) {
        if (render_rect.left == clip_rect.left && render_rect.top == clip_rect.top &&
            render_rect.right == clip_rect.right && render_rect.bottom == clip_rect.bottom) {
            this->draw_setup(0);

            unsigned char *locked = render_area->Lock("scr_sed::draw", 1);
            if (locked) {
                tagRECT *mrect = &main_view->render_rect;
                rect = *mrect;

                render_area->DrawBevel3(0, 0, pnl_wid - 1, rect.top - 1,
                                        bevel_color1, bevel_color2, bevel_color3, bevel_color4, bevel_color5, bevel_color6);

                render_area->DrawBevel3(0, rect.bottom + 1, pnl_wid - 1, pnl_hgt - 1,
                                        bevel_color1, bevel_color2, bevel_color3, bevel_color4, bevel_color5, bevel_color6);

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

int TRIBE_Screen_Sed::command_menu() {
    TRIBE_Dialog_Sed_Menu *dlg = new TRIBE_Dialog_Sed_Menu(this);
    if (dlg != 0 && dlg->error_code != 0) {
        delete dlg;
        return 0;
    }
    return 1;
}

void TRIBE_Screen_Sed::command_new(void) {
    if (this->need_to_save()) {
        this->popupYesNoCancelDialog(STRING_ID_CONFIRM_SAVE_SCENARIO_CHANGES, s_NewSaveDialog, TEASY_POPUP_WIDTH, 100);
        return;
    }
    static_cast<TRIBE_Game *>(rge_base_game)->start_scenario_editor(0, 0);
}

int TRIBE_Screen_Sed::command_new_map(char *scenario_name_in, int is_multi_player_in,
                                      int random_seed_in, int width, int height,
                                      int display_in) {
    int tribe;
    int result;
    RGE_Player_Info player_info;
    RGE_Map_Gen_Info map_info;

    this->need_to_save_flag = 0;
    if (rge_base_game->world == 0) {
        if (display_in != 0) {
            static_cast<TRIBE_Game *>(rge_base_game)->show_status_message(STRING_ID_STATUS_LOADING_GAME_DATA, 0, -1);
        }
        if (static_cast<TRIBE_Game *>(rge_base_game)->load_game_data() == 0) {
            if (display_in != 0) {
                static_cast<TRIBE_Game *>(rge_base_game)->close_status_message();
            }
            return 0;
        }
    }

    this->world = static_cast<TRIBE_World *>(rge_base_game->world);
    if (display_in != 0) {
        if (scenario_name_in == 0) {
            static_cast<TRIBE_Game *>(rge_base_game)->show_status_message(STRING_ID_STATUS_SETTING_UP_SCENARIO, 0, -1);
        } else {
            static_cast<TRIBE_Game *>(rge_base_game)->show_status_message(STRING_ID_STATUS_LOADING_SCENARIO, 0, -1);
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
        this->set_string(player_info.name[i], STRING_ID_PLAYER_NAME_BASE + i, 65);
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

void TRIBE_Screen_Sed::command_open(void) {
    if (this->need_to_save()) {
        this->popupYesNoCancelDialog(STRING_ID_CONFIRM_SAVE_SCENARIO_CHANGES, s_OpenSaveDialog, TEASY_POPUP_WIDTH, 100);
        return;
    }

    new TRIBE_Screen_Sed_Open();
    panel_system.setCurrentPanel(s_Scenario_Editor_Open, 0);
}

void TRIBE_Screen_Sed::command_outline(void) {
    unsigned char outline_type = rge_base_game->outline_type;
    switch (outline_type) {
    case 0:
    case 3:
        outline_type = 2;
        break;
    case 2:
        outline_type = 1;
        break;
    case 1:
        outline_type = 0;
        break;
    }
    rge_base_game->outline_type = outline_type;
}

void TRIBE_Screen_Sed::command_player(int id) {
    rge_base_game->set_player(id);
}

void TRIBE_Screen_Sed::command_quit() {
    if (need_to_save()) {
        popupYesNoCancelDialog(STRING_ID_CONFIRM_SAVE_SCENARIO_CHANGES, s_QuitSaveDialog, TEASY_POPUP_WIDTH, TEASY_POPUP_HEIGHT);
        return;
    }
    if (!static_cast<TRIBE_Game *>(rge_base_game)->start_menu()) {
        rge_base_game->close();
        return;
    }
    panel_system.destroyPanel(s_Scenario_Editor_Screen);
}

void TRIBE_Screen_Sed::command_save(unsigned char kill_menu, unsigned char quit_after_save) {
    char temp_name[260];

    this->set_scenario_mode(ScenarioModeSave);
    static_cast<T_Scenario *>(this->world->scenario)->Save_victory_conditions_into_players(1);
    if (this->world->scenario->active_player_count() < 1) {
        panel_system.destroyPanel(s_Scenario_Menu_Dialog);
        this->popupOKDialog(STRING_ID_ERROR_NO_ACTIVE_PLAYERS, 0, TEASY_POPUP_WIDTH, 100);
    } else if (this->world->scenario->any_player_count() < 1) {
        panel_system.destroyPanel(s_Scenario_Menu_Dialog);
        this->popupOKDialog(STRING_ID_ERROR_CIVILIZATION_EITHER_REQUIRED, 0, TEASY_POPUP_WIDTH, 100);
    } else {
        char *name = this->world->scenario->Get_scenario_name();
        if (*name == 0) {
            this->command_save_as(quit_after_save);
        } else {
            static_cast<TRIBE_Game *>(rge_base_game)->show_status_message(STRING_ID_STATUS_SAVING_SCENARIO, 0, -1);
            if (kill_menu != 0) {
                panel_system.destroyPanel(s_Scenario_Menu_Dialog);
            }
            if (this->world->save_scenario(name) == 0) {
                static_cast<TRIBE_Game *>(rge_base_game)->close_status_message();
                this->popupOKDialog(STRING_ID_ERROR_CANNOT_SAVE_SCENARIO, 0, TEASY_POPUP_WIDTH, 100);
            } else {
                static_cast<TRIBE_Game *>(rge_base_game)->close_status_message();
                sprintf(temp_name, "default%d", rge_base_game->registry->RegGetInt(0, "Game File Number"));
                if (strcmp(name, temp_name) != 0) {
                    this->need_to_save_flag = 0;
                }
                if (quit_after_save == 1) {
                    if (static_cast<TRIBE_Game *>(rge_base_game)->start_menu() == 0) {
                        rge_base_game->close();
                    } else {
                        panel_system.destroyPanel(s_Scenario_Editor_Screen);
                    }
                } else if (quit_after_save == 2) {
                    TRIBE_Screen_Sed_Open *p = new TRIBE_Screen_Sed_Open;
                    panel_system.setCurrentPanel(s_Scenario_Editor_Open, 0);
                } else if (quit_after_save == 3) {
                    static_cast<TRIBE_Game *>(rge_base_game)->start_scenario_editor(0, 0);
                }
            }
        }
    }
}

// The scenario buffer retains the shipped malformed-name behavior.

void TRIBE_Screen_Sed::command_save_as(unsigned char quit_after_save) {
    char scenario_name[224];

    this->set_scenario_mode(ScenarioModeSave);
    static_cast<T_Scenario *>(this->world->scenario)->Save_victory_conditions_into_players(1);
    if (this->world->scenario->active_player_count() < 1) {
        this->popupOKDialog(STRING_ID_ERROR_NO_ACTIVE_PLAYERS, 0, TEASY_POPUP_WIDTH, 100);
    } else if (this->world->scenario->any_player_count() < 1) {
        this->popupOKDialog(STRING_ID_ERROR_CIVILIZATION_EITHER_REQUIRED, 0, TEASY_POPUP_WIDTH, 100);
    } else {
        scenario_name[0] = 0;
        new TribeSaveGameScreen(TribeSaveGameScreen::SaveScenarioEdit, scenario_name, quit_after_save);
        panel_system.setCurrentPanel(s_Save_Game_Screen, 0);
        panel_system.destroyPanel(s_Scenario_Menu_Dialog);
    }
    return;
}

char *TRIBE_Screen_Sed::scenario_get_default_name() {
    char temp_name[260];
    char *name;

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

char *TRIBE_Screen_Sed::scenario_save_defaulted() {
    this->set_scenario_mode(ScenarioModeSave);
    static_cast<T_Scenario *>(this->world->scenario)->Save_victory_conditions_into_players(1);
    if (this->world->scenario->active_player_count() < 1) {
        this->popupOKDialog(STRING_ID_ERROR_NO_ACTIVE_PLAYERS, 0, TEASY_POPUP_WIDTH, 100);
        return 0;
    }
    if (this->world->scenario->any_player_count() < 1) {
        this->popupOKDialog(STRING_ID_ERROR_CIVILIZATION_EITHER_REQUIRED, 0, TEASY_POPUP_WIDTH, 100);
        return 0;
    }

    static_cast<TRIBE_Game *>(rge_base_game)->show_status_message(STRING_ID_STATUS_SAVING_SCENARIO, 0, -1);
    sprintf(scenario_default_file_name, "default%d.scx", rge_base_game->registry->RegGetInt(0, "Game File Number"));
    if (this->world->save_scenario(scenario_default_file_name) == 0) {
        static_cast<TRIBE_Game *>(rge_base_game)->close_status_message();
        this->popupOKDialog(STRING_ID_ERROR_CANNOT_SAVE_SCENARIO, 0, TEASY_POPUP_WIDTH, 100);
        return 0;
    }

    sprintf(scenario_default_file_name, "default%d", rge_base_game->registry->RegGetInt(0, "Game File Number"));
    return scenario_default_file_name;
}

unsigned char TRIBE_Screen_Sed::need_to_save() { return this->need_to_save_flag; }

void TRIBE_Screen_Sed::set_focus(int have_focus_in) {
    this->TScreenPanel::set_focus(have_focus_in);
    if (this->have_focus) {
        rge_base_game->set_windows_mouse(0);
    } else {
        rge_base_game->set_windows_mouse(1);
    }
}
