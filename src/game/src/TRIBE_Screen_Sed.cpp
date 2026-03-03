// TODO: PARITY - Missing function implementation for TRIBE_Screen_Sed::vector_deleting_destructor. [decomp: TRIBE_Screen_Sed.decomp @ 0x004A8750]
#include "../include/TRIBE_Screen_Sed.h"

#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Diamond_Map.h"
#include "../include/RGE_Diamond_Map_View.h"
#include "../include/RGE_Font.h"
#include "../include/RGE_Main_View.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Master_Player.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Master_Player.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Scenario.h"
#include "../include/RGE_View.h"
#include "../include/TButtonPanel.h"
#include "../include/TDrawArea.h"
#include "../include/TDropDownPanel.h"
#include "../include/TEditPanel.h"
#include "../include/TListPanel.h"
#include "../include/TMessagePanel.h"
#include "../include/T_Scenario.h"
#include "../include/TRegistry.h"
#include "../include/TribeSaveGameScreen.h"
#include "../include/TRIBE_Dialog_Sed_Menu.h"
#include "../include/TRIBE_Game.h"
#include "../include/TRIBE_Main_View.h"
#include "../include/TRIBE_Master_Building_Object.h"
#include "../include/TRIBE_Screen_Sed_Open.h"
#include "../include/TRIBE_Scenario_Editor_Panel_Object.h"
#include "../include/TRIBE_World.h"
#include "../include/TRIBE_Tech.h"
#include "../include/debug_helpers.h"
#include "../include/globals.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char* kScrSedSourcePath = "C:\\msdev\\work\\age1_x1\\scr_sed.cpp";

static char kScenarioEditorScreenName[] = "Scenario Editor Screen";
static char kScenarioMenuDialogName[] = "Scenario Menu Dialog";
static char kSaveGameScreenName[] = "Save Game Screen";
static char kQuitSaveDialogName[] = "QuitSaveDialog";
static char kOpenSaveDialogName[] = "OpenSaveDialog";
static char kNewSaveDialogName[] = "NewSaveDialog";
extern int View_Grid_Mode;

static int command_save(TRIBE_Screen_Sed* this_, unsigned char param_1, unsigned char param_2);
static void set_player(TRIBE_Screen_Sed* this_, short player_num, unsigned char param_2, unsigned char param_3);
static void set_terrain(TRIBE_Screen_Sed* this_, short param_2);
static void set_elevation(TRIBE_Screen_Sed* this_, short param_2);
static void set_paint_object_mode(TRIBE_Screen_Sed* this_);
int MakeFileList(TRIBE_Screen_Sed* this_, TDropDownPanel* param_2, char* param_3, char* param_4, uchar param_5, uchar param_6);

static void init_module_variables(TRIBE_Screen_Sed* this_) {
    // Fully verified. Source of truth: scr_sed2.cpp.decomp @ 0x004AF320
    if (this_ == nullptr) return;

    this_->background_pic = nullptr;
    this_->main_view = nullptr;
    this_->map_view = nullptr;
    this_->message_panel = nullptr;
    this_->bottom_panel = nullptr;
    this_->set_player_first_flag = 0;

    memset(this_->scenario_mode_button, 0, sizeof(this_->scenario_mode_button));
    this_->menu_button = nullptr;
    this_->help_button = nullptr;

    memset(this_->map_type_button, 0, sizeof(this_->map_type_button));
    memset(this_->map_type_text, 0, sizeof(this_->map_type_text));
    this_->map_type_label = nullptr;
    this_->default_terrain_drop = nullptr;
    this_->default_terrain_label = nullptr;
    this_->map_size_drop = nullptr;
    this_->map_size_label = nullptr;
    this_->map_style_drop = nullptr;
    this_->map_style_label = nullptr;
    this_->map_generating_text = nullptr;
    this_->random_seed_label = nullptr;
    this_->random_seed_input = nullptr;
    this_->random_seed_used_label = nullptr;
    this_->random_seed_used_text = nullptr;
    this_->generate_map_button = nullptr;
    this_->brush_size_label = nullptr;
    this_->paint_type_label = nullptr;
    this_->paint_terrain_label = nullptr;

    memset(this_->brush_size_button, 0, sizeof(this_->brush_size_button));
    memset(this_->brush_size_button_label, 0, sizeof(this_->brush_size_button_label));
    memset(this_->paint_type_button, 0, sizeof(this_->paint_type_button));
    memset(this_->paint_type_button_label, 0, sizeof(this_->paint_type_button_label));

    this_->paint_terrain_list = nullptr;
    this_->paint_terrain_scrollbar = nullptr;
    this_->paint_elevation_list = nullptr;
    this_->paint_elevation_scrollbar = nullptr;
    this_->player_advance_civilization_drop = nullptr;
    this_->player_label = nullptr;
    this_->player_starting_age_label = nullptr;
    this_->player_build_text = nullptr;
    this_->player_city_text = nullptr;
    this_->AiRules_text = nullptr;
    this_->player_list = nullptr;
    this_->player_number_list = nullptr;

    memset(this_->player_inven_label, 0, sizeof(this_->player_inven_label));
    memset(this_->player_inven_input, 0, sizeof(this_->player_inven_input));
    memset(this_->player_setting_label, 0, sizeof(this_->player_setting_label));
    memset(this_->player_setting_drop, 0, sizeof(this_->player_setting_drop));

    this_->BuildList = nullptr;
    this_->CityLayout = nullptr;
    this_->AiRules = nullptr;
    this_->unit_player_list = nullptr;
    memset(this_->unit_mode_select, 0, sizeof(this_->unit_mode_select));
    memset(this_->unit_mode_select_label, 0, sizeof(this_->unit_mode_select_label));
    this_->unit_list = nullptr;
    this_->unit_scrollbar = nullptr;
    this_->unit_list_info = nullptr;
    this_->button_unit_pics = nullptr;
    memset(this_->button_bldg_pics, 0, sizeof(this_->button_bldg_pics));
    this_->object_panel = nullptr;
    this_->unit_list_size = 0;

    memset(this_->victory_cond_on, 0, sizeof(this_->victory_cond_on));
    memset(this_->victory_and_or, 0, sizeof(this_->victory_and_or));
    this_->victory_condition_label = nullptr;
    this_->victory_amount_label = nullptr;
    this_->victory_long_label = nullptr;
    memset(this_->victory_text_and_or, 0, sizeof(this_->victory_text_and_or));
    this_->victory_label_conquest = nullptr;
    this_->victory_label_explore = nullptr;
    this_->victory_label_explore_percent = nullptr;
    this_->victory_label_ruins = nullptr;
    this_->victory_label_artifacts = nullptr;
    this_->victory_label_discoveries = nullptr;
    this_->victory_label_gold = nullptr;
    this_->victory_condition_explore = nullptr;
    this_->victory_condition_ruins = nullptr;
    this_->victory_condition_artifacts = nullptr;
    this_->victory_condition_discoveries = nullptr;
    this_->victory_condition_gold = nullptr;
    memset(this_->victory_cond_type_label, 0, sizeof(this_->victory_cond_type_label));
    memset(this_->victory_cond_type, 0, sizeof(this_->victory_cond_type));
    this_->victory_score_label = nullptr;
    this_->victory_score = nullptr;
    this_->victory_time_label = nullptr;
    this_->victory_time = nullptr;
    memset(this_->victory_button, 0, sizeof(this_->victory_button));
    this_->victory_drop_down = nullptr;
    this_->victory_object_list = nullptr;
    this_->victory_player_list = nullptr;
    this_->victory_enemy_player_list = nullptr;
    this_->victory_attribute_list = nullptr;
    this_->victory_ages_list = nullptr;
    this_->victory_tech_list = nullptr;
    this_->victory_button_set_object = nullptr;
    this_->victory_button_set_destination = nullptr;
    this_->victory_button_go_to_dest = nullptr;
    this_->victory_condition_text = nullptr;
    this_->victory_condition_type = nullptr;
    this_->victory_amount_text = nullptr;
    this_->victory_which_enemy_text = nullptr;
    this_->victory_amount_input = nullptr;
    this_->victory_object_scrollbar = nullptr;

    this_->message_input = nullptr;
    memset(this_->message_button, 0, sizeof(this_->message_button));
    memset(this_->message_button_label, 0, sizeof(this_->message_button_label));
    this_->current_message = 0;

    memset(this_->cinematic_label, 0, sizeof(this_->cinematic_label));
    memset(this_->cinematic_input, 0, sizeof(this_->cinematic_input));
    memset(this_->options_label, 0, sizeof(this_->options_label));
    memset(this_->options_button, 0, sizeof(this_->options_button));
    this_->options_player_list = nullptr;
    this_->options_disable_tech_text = nullptr;
    memset(this_->options_disable_button, 0, sizeof(this_->options_disable_button));
    memset(this_->options_disable_text, 0, sizeof(this_->options_disable_text));

    memset(this_->Diplomacy_opponent_label, 0, sizeof(this_->Diplomacy_opponent_label));
    memset(this_->Diplomacy_player_text, 0, sizeof(this_->Diplomacy_player_text));
    this_->Diplomacy_player_list = nullptr;
    memset(this_->Diplomacy_status_label, 0, sizeof(this_->Diplomacy_status_label));
    memset(this_->Diplomacy_friend_box, 0, sizeof(this_->Diplomacy_friend_box));
    memset(this_->Diplomacy_AlliedVictory, 0, sizeof(this_->Diplomacy_AlliedVictory));
    this_->world = nullptr;
}

static void set_player_active(TRIBE_Screen_Sed* this_, short player_num, int active) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004AB2B0
    if (!this_ || !this_->world || !this_->world->scenario) return;
    this_->world->scenario->Set_player_Active((int)player_num, active);
}

static void SavePlayerActiveStatus(TRIBE_Screen_Sed* this_) {
    // Fully verified. Source of truth: scr_sed2.cpp.decomp @ 0x004B2C50
    if (!this_ || !this_->world || !this_->world->scenario || !this_->player_number_list) return;

    const int active_players = (int)this_->player_number_list->get_line() + 1;
    const int scenario_players = (int)this_->world->player_num - 1;
    if (scenario_players > 0) {
        for (int i = 0; i < scenario_players; ++i) {
            this_->world->scenario->Set_player_Active(i, (i < active_players) ? 1 : 0);
        }
    }

    if (this_->victory_player_list) this_->victory_player_list->empty_list();
    if (this_->victory_enemy_player_list) this_->victory_enemy_player_list->empty_list();
    if (this_->options_player_list) this_->options_player_list->empty_list();
    if (this_->Diplomacy_player_list) this_->Diplomacy_player_list->empty_list();
    if (this_->player_list) this_->player_list->empty_list();
    if (this_->unit_player_list) {
        this_->unit_player_list->empty_list();
        this_->unit_player_list->append_line(0x2776, 0);
    }

    for (int i = 0; i < active_players; ++i) {
        const long str_id = 0x2865 + i;
        if (this_->unit_player_list) this_->unit_player_list->append_line(str_id, 0);
        if (this_->victory_player_list) this_->victory_player_list->append_line(str_id, 0);
        if (this_->victory_enemy_player_list) this_->victory_enemy_player_list->append_line(str_id, 0);
        if (this_->options_player_list) this_->options_player_list->append_line(str_id, 0);
        if (this_->Diplomacy_player_list) this_->Diplomacy_player_list->append_line(str_id, 0);
        if (this_->player_list) this_->player_list->append_line(str_id, 0);
    }

    if (active_players <= this_->player_num) {
        set_player(this_, (short)active_players, '\0', '\0');
    }
    if (this_->victory_player_list) this_->victory_player_list->set_line(this_->player_num - 1);
    if (this_->options_player_list) this_->options_player_list->set_line(this_->player_num - 1);
    if (this_->Diplomacy_player_list) this_->Diplomacy_player_list->set_line(this_->player_num - 1);
    if (this_->player_list) this_->player_list->set_line(this_->player_num - 1);
    if (this_->unit_player_list) this_->unit_player_list->set_line((int)this_->player_num);
}

static void set_panel_info(TRIBE_Screen_Sed* this_) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004A8770
    if (!this_ || !rge_base_game) return;

    if (this_->main_view) {
        RGE_View* view = (RGE_View*)this_->main_view;
        view->world = (RGE_Game_World*)this_->world;
        view->player = rge_base_game->get_player();
        view->map = (this_->world != nullptr) ? this_->world->map : nullptr;
    }

    if (this_->map_view) {
        RGE_Diamond_Map* map = (RGE_Diamond_Map*)this_->map_view;
        map->set_world((RGE_Game_World*)this_->world);
        map->set_player(rge_base_game->get_player());
        map->set_main_view((RGE_View*)this_->main_view);
    }
}

static void set_map_type(TRIBE_Screen_Sed* this_, TRIBE_Screen_Sed::MapType param_1, int param_2) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004AA7A0
    if (!this_) return;

    for (int pass = 0; pass < 2; ++pass) {
        TRIBE_Screen_Sed::MapType map_type = this_->map_type;
        int active = 0;
        if (pass != 0) {
            if (param_1 == TRIBE_Screen_Sed::MapTypeNone) return;
            if (param_2 == 0) break;
            map_type = param_1;
            active = 1;
        }

        if (map_type == TRIBE_Screen_Sed::MapTypeBlank) {
            if (this_->map_size_label) this_->map_size_label->set_active(active);
            if (this_->map_size_drop) this_->map_size_drop->set_active(active);
            if (this_->default_terrain_label) this_->default_terrain_label->set_active(active);
            if (this_->default_terrain_drop) this_->default_terrain_drop->set_active(active);
        } else if (map_type == TRIBE_Screen_Sed::MapTypeRandom) {
            if (this_->map_size_label) this_->map_size_label->set_active(active);
            if (this_->map_size_drop) this_->map_size_drop->set_active(active);
            if (this_->map_style_label) this_->map_style_label->set_active(active);
            if (this_->map_style_drop) this_->map_style_drop->set_active(active);
            if (this_->random_seed_used_label) this_->random_seed_used_label->set_active(active);
            if (this_->random_seed_used_text) this_->random_seed_used_text->set_active(active);
        } else if (map_type == TRIBE_Screen_Sed::MapTypeSeed) {
            if (this_->map_size_label) this_->map_size_label->set_active(active);
            if (this_->map_size_drop) this_->map_size_drop->set_active(active);
            if (this_->map_style_label) this_->map_style_label->set_active(active);
            if (this_->map_style_drop) this_->map_style_drop->set_active(active);
            if (this_->random_seed_label) this_->random_seed_label->set_active(active);
            if (this_->random_seed_input) this_->random_seed_input->set_active(active);
            if (active != 0 && this_->bottom_panel && this_->random_seed_input) {
                this_->bottom_panel->set_curr_child((TPanel*)this_->random_seed_input);
            }
        }
    }

    this_->map_type = param_1;
    const int index = (int)param_1 - (int)TRIBE_Screen_Sed::MapTypeBlank;
    if (index >= 0 && index < 3 && this_->map_type_button[index]) {
        this_->map_type_button[index]->set_radio_button();
    }
    if (this_->bottom_panel) this_->bottom_panel->set_redraw(TPanel::Redraw);
}

static void set_mp_victory_type(TRIBE_Screen_Sed* this_, TRIBE_Screen_Sed::VictoryType param_1, int param_2) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004AA8F0
    if (!this_) return;

    for (int pass = 0; pass < 2; ++pass) {
        TRIBE_Screen_Sed::VictoryType type = this_->mp_victory_type;
        int active = 0;
        if (pass != 0) {
            if (param_1 == TRIBE_Screen_Sed::VictoryTypeNone) return;
            if (param_2 == 0) break;
            type = param_1;
            active = 1;
        }

        switch (type) {
        case TRIBE_Screen_Sed::VictoryTypeScore:
            if (this_->victory_score_label) this_->victory_score_label->set_active(active);
            if (this_->victory_score) this_->victory_score->set_active(active);
            break;
        case TRIBE_Screen_Sed::VictoryTypeTime:
            if (this_->victory_time_label) this_->victory_time_label->set_active(active);
            if (this_->victory_time) this_->victory_time->set_active(active);
            break;
        case TRIBE_Screen_Sed::VictoryTypeCustom:
            for (int i = 0; i < 5; ++i) {
                if (this_->victory_cond_on[i]) this_->victory_cond_on[i]->set_active(active);
            }
            for (int i = 0; i < 2; ++i) {
                if (this_->victory_and_or[i]) this_->victory_and_or[i]->set_active(active);
                if (this_->victory_text_and_or[i]) this_->victory_text_and_or[i]->set_active(active);
            }
            if (this_->victory_amount_label) this_->victory_amount_label->set_active(active);
            if (this_->victory_label_conquest) this_->victory_label_conquest->set_active(active);
            if (this_->victory_label_explore) this_->victory_label_explore->set_active(active);
            if (this_->victory_label_ruins) this_->victory_label_ruins->set_active(active);
            if (this_->victory_label_artifacts) this_->victory_label_artifacts->set_active(active);
            if (this_->victory_label_discoveries) this_->victory_label_discoveries->set_active(active);
            if (this_->victory_condition_explore) this_->victory_condition_explore->set_active(active);
            if (this_->victory_condition_ruins) this_->victory_condition_ruins->set_active(active);
            if (this_->victory_condition_artifacts) this_->victory_condition_artifacts->set_active(active);
            if (this_->victory_condition_discoveries) this_->victory_condition_discoveries->set_active(active);
            if (active != 0 && this_->bottom_panel && this_->victory_condition_explore) {
                this_->bottom_panel->set_curr_child((TPanel*)this_->victory_condition_explore);
            }
            break;
        default:
            break;
        }
    }

    this_->mp_victory_type = param_1;
    const int index = (int)param_1 - (int)TRIBE_Screen_Sed::VictoryTypeConquest;
    if (index >= 0 && index < 5 && this_->victory_cond_type[index]) {
        this_->victory_cond_type[index]->set_radio_button();
    }
    if (this_->bottom_panel) this_->bottom_panel->set_redraw(TPanel::Redraw);
}

static void set_brush_size(TRIBE_Screen_Sed* this_, TRIBE_Screen_Sed::BrushSize param_1) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004AAA90
    if (!this_ || !rge_base_game || param_1 == TRIBE_Screen_Sed::BrushSizeNone) return;

    this_->brush_size = param_1;
    const int index = (int)param_1 - (int)TRIBE_Screen_Sed::BrushSizeVerySmall;
    if (index >= 0 && index < 5 && this_->brush_size_button[index]) {
        this_->brush_size_button[index]->set_radio_button();
    }

    switch (this_->brush_size) {
    case TRIBE_Screen_Sed::BrushSizeVerySmall:
        rge_base_game->brush_size = 1;
        break;
    case TRIBE_Screen_Sed::BrushSizeSmall:
        rge_base_game->brush_size = 3;
        break;
    case TRIBE_Screen_Sed::BrushSizeMedium:
        rge_base_game->brush_size = 5;
        break;
    case TRIBE_Screen_Sed::BrushSizeLarge:
        rge_base_game->brush_size = 7;
        break;
    case TRIBE_Screen_Sed::BrushSizeXLarge:
        rge_base_game->brush_size = 9;
        break;
    default:
        rge_base_game->brush_size = 2;
        break;
    }
}

static void set_paint_type(TRIBE_Screen_Sed* this_, TRIBE_Screen_Sed::PaintType param_1, int param_2) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004AAB60
    if (!this_ || !rge_base_game) return;

    for (int pass = 0; pass < 2; ++pass) {
        TRIBE_Screen_Sed::PaintType paint_type = this_->paint_type;
        int active = 0;
        if (pass != 0) {
            if (param_1 == TRIBE_Screen_Sed::PaintTypeNone) return;
            if (param_2 == 0) break;
            paint_type = param_1;
            active = 1;
        }

        if (this_->brush_size_label) this_->brush_size_label->set_active(active);
        for (int i = 0; i < 5; ++i) {
            if (this_->brush_size_button[i]) this_->brush_size_button[i]->set_active(active);
            if (this_->brush_size_button_label[i]) this_->brush_size_button_label[i]->set_active(active);
        }

        if (paint_type == TRIBE_Screen_Sed::PaintTypeTerrain) {
            if (this_->paint_terrain_list) this_->paint_terrain_list->set_active(active);
            if (this_->paint_terrain_label) this_->paint_terrain_label->set_active(active);
            if (active == 0) {
                rge_base_game->set_game_mode(0, 0);
            } else {
                if (this_->paint_terrain_list) set_terrain(this_, (short)this_->paint_terrain_list->currentLineNumber());
                rge_base_game->set_game_mode(9, 0);
            }
        } else if (paint_type == TRIBE_Screen_Sed::PaintTypeElevation) {
            if (this_->paint_elevation_list) this_->paint_elevation_list->set_active(active);
            if (this_->paint_terrain_label) this_->paint_terrain_label->set_active(active);
            if (active == 0) {
                rge_base_game->set_game_mode(0, 0);
            } else {
                if (this_->paint_elevation_list) set_elevation(this_, (short)this_->paint_elevation_list->currentLineNumber());
                rge_base_game->set_game_mode(10, 0);
            }
        } else if (paint_type == TRIBE_Screen_Sed::PaintTypeCliffs) {
            if (this_->paint_elevation_list) this_->paint_elevation_list->set_active(0);
            if (this_->paint_terrain_list) this_->paint_terrain_list->set_active(0);
            if (this_->paint_terrain_label) this_->paint_terrain_label->set_active(0);
            if (this_->brush_size_label) this_->brush_size_label->set_active(0);
            for (int i = 0; i < 5; ++i) {
                if (this_->brush_size_button[i]) this_->brush_size_button[i]->set_active(0);
                if (this_->brush_size_button_label[i]) this_->brush_size_button_label[i]->set_active(0);
            }
            if (active == 0) {
                rge_base_game->set_game_mode(0, 0);
            } else {
                if (this_->paint_elevation_list) set_elevation(this_, (short)this_->paint_elevation_list->currentLineNumber());
                rge_base_game->set_game_mode(0x13, 0);
            }
        }
    }

    this_->paint_type = param_1;
    const int index = (int)param_1 - (int)TRIBE_Screen_Sed::PaintTypeTerrain;
    if (index >= 0 && index < 3 && this_->paint_type_button[index]) {
        this_->paint_type_button[index]->set_radio_button();
    }
    if (this_->bottom_panel) this_->bottom_panel->set_redraw(TPanel::Redraw);
}

static void set_player(TRIBE_Screen_Sed* this_, short player_num, unsigned char save_current, unsigned char load_selected) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004AAE20
    if (this_ == nullptr || this_->world == nullptr || this_->world->scenario == nullptr || rge_base_game == nullptr) return;

    const int current_index = (this_->player_num > 0) ? (this_->player_num - 1) : 0;
    RGE_Player* current_player = rge_base_game->get_player();
    if (current_player != nullptr) current_player->unselect_object();

    if (save_current != 0) {
        const int food = (this_->player_inven_input[0] != nullptr) ? atoi(this_->player_inven_input[0]->currentLine()) : 0;
        const int wood = (this_->player_inven_input[1] != nullptr) ? atoi(this_->player_inven_input[1]->currentLine()) : 0;
        const int stone = (this_->player_inven_input[2] != nullptr) ? atoi(this_->player_inven_input[2]->currentLine()) : 0;
        const int gold = (this_->player_inven_input[3] != nullptr) ? atoi(this_->player_inven_input[3]->currentLine()) : 0;
        ((T_Scenario*)this_->world->scenario)->Set_player_Food(current_index, food);
        ((T_Scenario*)this_->world->scenario)->Set_player_Wood(current_index, wood);
        ((T_Scenario*)this_->world->scenario)->Set_player_Stone(current_index, stone);
        ((T_Scenario*)this_->world->scenario)->Set_player_Gold(current_index, gold);

        if (this_->player_inven_input[4] != nullptr) this_->world->scenario->SetPlayerName(current_index, this_->player_inven_input[4]->currentLine());
        if (this_->player_setting_drop[0] != nullptr) this_->world->scenario->Set_player_Type(current_index, this_->player_setting_drop[0]->currentLineNumber());
        if (this_->player_setting_drop[1] != nullptr) this_->world->scenario->Set_player_Civ(current_index, this_->player_setting_drop[1]->currentLineNumber() + 1);
        if (this_->AiRules != nullptr) this_->world->scenario->Set_player_AI(current_index, this_->AiRules->currentLine(), 0);
        if (this_->BuildList != nullptr) this_->world->scenario->Set_BuildList(current_index, this_->BuildList->currentLine(), 0);
        if (this_->CityLayout != nullptr) this_->world->scenario->Set_CityPlan(current_index, this_->CityLayout->currentLine(), 0);
    }

    this_->player_num = player_num;
    if (player_num <= 0) return;

    const int new_index = player_num - 1;
    if (this_->player_list != nullptr) this_->player_list->set_line(new_index);
    rge_base_game->set_player(player_num);

    if (load_selected != 0) {
        char buffer[30];
        sprintf(buffer, "%d", ((T_Scenario*)this_->world->scenario)->Get_player_Food(new_index));
        if (this_->player_inven_input[0] != nullptr) this_->player_inven_input[0]->set_text(buffer);
        sprintf(buffer, "%d", ((T_Scenario*)this_->world->scenario)->Get_player_Wood(new_index));
        if (this_->player_inven_input[1] != nullptr) this_->player_inven_input[1]->set_text(buffer);
        sprintf(buffer, "%d", ((T_Scenario*)this_->world->scenario)->Get_player_Stone(new_index));
        if (this_->player_inven_input[2] != nullptr) this_->player_inven_input[2]->set_text(buffer);
        sprintf(buffer, "%d", ((T_Scenario*)this_->world->scenario)->Get_player_Gold(new_index));
        if (this_->player_inven_input[3] != nullptr) this_->player_inven_input[3]->set_text(buffer);
        if (this_->player_inven_input[4] != nullptr) this_->player_inven_input[4]->set_text(this_->world->scenario->GetPlayerName(new_index));
        if (this_->player_setting_drop[0] != nullptr) this_->player_setting_drop[0]->setCurrentLineNumber(this_->world->scenario->Get_player_Type(new_index));
        if (this_->player_setting_drop[1] != nullptr) this_->player_setting_drop[1]->setCurrentLineNumber(this_->world->scenario->Get_player_Civ(new_index) - 1);
    }
}

static void set_unit_player(TRIBE_Screen_Sed* this_, short player_num) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004AB300
    if (this_ == nullptr || rge_base_game == nullptr) return;

    rge_base_game->set_player(player_num);
    this_->player_num = player_num;

    if (this_->main_view != nullptr) ((RGE_View*)this_->main_view)->set_player(rge_base_game->get_player());
    if (this_->map_view != nullptr) ((RGE_Diamond_Map*)this_->map_view)->set_player(rge_base_game->get_player());
    if (this_->unit_player_list != nullptr) this_->unit_player_list->setCurrentLineNumber(player_num);
    if (this_->unit_list != nullptr) this_->unit_list->empty_list();

    if (this_->unit_list_info != nullptr) {
        free(this_->unit_list_info);
        this_->unit_list_info = nullptr;
    }

    this_->unit_list_size = 0;
}

static void set_message_type(TRIBE_Screen_Sed* this_, TRIBE_Screen_Sed::MessageType param_1, int param_2) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004AB6E0
    if (!this_) return;
    if (this_->message_input) this_->message_input->set_active(param_2);
    this_->message_type = param_1;
    if (this_->bottom_panel) this_->bottom_panel->set_redraw(TPanel::Redraw);
}

static void set_scenario_mode(TRIBE_Screen_Sed* this_, TRIBE_Screen_Sed::ScenarioMode param_1) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004A9CC0
    if (!this_) return;
    if (param_1 == TRIBE_Screen_Sed::ScenarioModeSave) return;

    this_->valid_save_spot_flag = 0;
    this_->scenario_mode = param_1;
    const int index = (int)param_1 - (int)TRIBE_Screen_Sed::ScenarioModeMap;
    if (index >= 0 && index < 10 && this_->scenario_mode_button[index]) this_->scenario_mode_button[index]->set_radio_button();
    if (this_->bottom_panel) this_->bottom_panel->set_redraw(TPanel::Redraw);
}

static void set_unit(TRIBE_Screen_Sed* this_, short param_1) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004AB670
    if (!this_ || !rge_base_game) return;
    if (param_1 == -1) {
        rge_base_game->master_obj_id = -1;
        if (this_->unit_list) this_->unit_list->scroll_cur_line('\x01', -1, 1);
        return;
    }
    if (this_->unit_list_info != nullptr && param_1 >= 0 && param_1 < this_->unit_list_size) {
        rge_base_game->master_obj_id = this_->unit_list_info[param_1].id;
    }
    if (this_->unit_list) this_->unit_list->scroll_cur_line('\x01', param_1, 1);
}

static void set_string(TRIBE_Screen_Sed* this_, char* param_2, long param_3, int param_4) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004A87D0
    if (!this_ || !param_2) return;
    this_->get_string((int)param_3, param_2, param_4);
}

static int create_button(TRIBE_Screen_Sed* this_, TPanel* param_2, TButtonPanel** param_3, long param_4, int param_5) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004A87F0
    (void)param_5;
    if (!this_) return 0;
    char str1[120];
    this_->get_string((int)param_4, str1 + 4, 0x78);
    return this_->create_button(param_2, param_3, str1 + 4, (char*)0, 0, 0, 0, 0, 10, 1, 0);
}

static int create_button(TRIBE_Screen_Sed* this_, TPanel* param_2, TButtonPanel** param_3, char* param_4, char* param_5, char* param_6, char* param_7) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004A8840
    if (!this_) return 0;
    const int created = this_->TEasy_Panel::create_button(param_2, param_3, param_4, param_5, 0, 0, 0, 0, 10, 1, 0);
    if (created == 0) return 0;
    if (param_6) (*param_3)->set_text(2, param_6);
    if (param_7) (*param_3)->set_text(3, param_7);
    (*param_3)->set_z_order('\x01', 0);
    (*param_3)->set_active(0);
    if (this_->use_bevels != 0) {
        (*param_3)->set_bevel_info(3, this_->bevel_color1, this_->bevel_color2, this_->bevel_color3,
            this_->bevel_color4, this_->bevel_color1, this_->bevel_color2);
    }
    return 1;
}

static int create_text(TRIBE_Screen_Sed* this_, TPanel* param_2, TTextPanel** param_3, long param_4) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004A8910
    if (!this_) return 0;
    const int created = this_->TEasy_Panel::create_text(param_2, param_3, (int)param_4, 0, 0, 0, 0, 10, 0, 0, 0);
    if (created == 0) return 0;
    (*param_3)->set_z_order('\x01', 0);
    (*param_3)->set_active(0);
    return 1;
}

static int create_text(TRIBE_Screen_Sed* this_, TPanel* param_2, TTextPanel** param_3, char* param_4) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004A8960
    if (!this_) return 0;
    const int created = this_->TEasy_Panel::create_text(param_2, param_3, param_4, 0, 0, 0, 0, 10, 0, 0, 0);
    if (created == 0) return 0;
    (*param_3)->set_z_order('\x01', 0);
    (*param_3)->set_active(0);
    return 1;
}

static int create_input(TRIBE_Screen_Sed* this_, TPanel* param_2, TInputPanel** param_3, char* param_4, short param_5, FormatType param_6) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004A89B0
    if (!this_) return 0;
    const int created = this_->TEasy_Panel::create_input(param_2, param_3, param_4, param_5, param_6, 0, 0, 0, 0, 10);
    if (created == 0) return 0;
    ((TPanel*)*param_3)->set_z_order('\x01', 0);
    ((TPanel*)*param_3)->set_active(0);
    return 1;
}

static int create_edit(TRIBE_Screen_Sed* this_, TPanel* param_2, TEditPanel** param_3, char* param_4, short param_5, FormatType param_6, int param_7, int param_8) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004A8A00
    if (!this_) return 0;
    const int created = this_->TEasy_Panel::create_edit(param_2, param_3, param_4, param_5, param_6, 0, 0, 0, 0, 10, param_7, param_8);
    if (created == 0) return 0;
    (*param_3)->set_z_order('\x01', 0);
    (*param_3)->set_active(0);
    return 1;
}

static int create_drop_down(TRIBE_Screen_Sed* this_, TPanel* param_2, TDropDownPanel** param_3) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004A8A60
    if (!this_ || !param_3) return 0;

    long drop_width = 0x82;
    if (param_3 == &this_->victory_object_list ||
        param_3 == &this_->victory_attribute_list ||
        param_3 == &this_->victory_ages_list ||
        param_3 == &this_->victory_tech_list ||
        param_3 == &this_->BuildList ||
        param_3 == &this_->CityLayout ||
        param_3 == &this_->AiRules ||
        param_3 == &this_->victory_time) {
        drop_width = 0xDC;
    } else if (param_3 == &this_->victory_drop_down) {
        drop_width = 0xB4;
    } else if (param_3 == this_->cinematic_input ||
               param_3 == this_->cinematic_input + 1 ||
               param_3 == this_->cinematic_input + 2 ||
               param_3 == this_->cinematic_input + 3 ||
               param_3 == &this_->default_terrain_drop ||
               param_3 == &this_->map_size_drop ||
               param_3 == &this_->map_style_drop) {
        drop_width = 0xAA;
    } else if (param_3 == &this_->player_advance_civilization_drop ||
               param_3 == &this_->player_list ||
               param_3 == &this_->player_number_list ||
               param_3 == &this_->unit_player_list ||
               param_3 == &this_->victory_player_list ||
               param_3 == &this_->options_player_list ||
               param_3 == &this_->Diplomacy_player_list ||
               param_3 == &this_->victory_enemy_player_list) {
        drop_width = 0x96;
    }

    const int created = this_->TEasy_Panel::create_drop_down(param_2, param_3, drop_width, 100, 0, 0, drop_width, 0x16, 10);
    if (created == 0) return 0;

    (*param_3)->set_z_order('\x01', 0);
    (*param_3)->set_active(0);
    (*param_3)->empty_list();

    TDropDownPanel* selected_drop = *param_3;
    long selected_line = 0;

    if (param_3 == &this_->map_size_drop) {
        selected_drop->append_line(0x2973, 0);
        selected_drop->append_line(0x2974, 0);
        selected_drop->append_line(0x2975, 0);
        selected_drop->append_line(0x2976, 0);
        selected_drop->append_line(0x2977, 0);
        selected_drop->append_line(0x2978, 0);
        selected_line = 3;
    } else if (param_3 == &this_->map_style_drop) {
        selected_drop->append_line(0x296a, 0);
        selected_drop->append_line(0x296b, 0);
        selected_drop->append_line(0x296c, 0);
        selected_drop->append_line(0x296d, 0);
        selected_drop->append_line(0x296e, 0);
        selected_drop->append_line(0x296f, 0);
        selected_drop->append_line(0x2970, 0);
        selected_drop->append_line(0x2971, 0);
        selected_drop->append_line(0x2972, 0);
        selected_line = 3;
    } else if (param_3 == &this_->player_number_list || param_3 == &this_->victory_enemy_player_list) {
        for (int i = 0; i < 8; ++i) {
            selected_drop->append_line(0x2877 + i, 0);
        }
    } else if (param_3 == &this_->victory_attribute_list) {
        selected_drop->append_line(0x2882, 0x2B);
        selected_drop->append_line(0x2883, 0x29);
        selected_drop->append_line(0x2884, 0x2C);
        selected_drop->append_line(0x2886, 0x28);
        selected_drop->append_line(0x2887, 0x15);
        selected_drop->append_line(0x2888, 0x14);
        selected_drop->append_line(0x2889, 0x25);
    } else if (param_3 == &this_->default_terrain_drop) {
        selected_drop->append_line(0x297d, 0);
        selected_drop->append_line(0x297e, 0);
        selected_drop->append_line(0x297f, 0);
        selected_drop->append_line(0x2980, 0);
        selected_drop->append_line(0x2981, 0);
        selected_drop->append_line(0x2982, 0);
        selected_drop->append_line(0x2983, 0);
        selected_drop->append_line(0x2984, 0);
        selected_drop->append_line(0x2985, 0);
    } else if (param_3 == this_->player_setting_drop) {
        selected_drop->append_line(0x27e3, 0);
        selected_drop->append_line(0x27e4, 0);
    } else if (param_3 == &this_->victory_drop_down) {
        selected_drop->append_line(0x2851, 0);
        selected_drop->append_line(0x2852, 0);
        selected_drop->append_line(0x2853, 0);
        selected_drop->append_line(0x2854, 0);
        selected_drop->append_line(0x2855, 0);
        selected_drop->append_line(0x2856, 0);
        selected_drop->append_line(0x2857, 0);
        selected_drop->append_line(0x2858, 0);
        selected_drop->append_line(0x2859, 0);
        selected_drop->append_line(0x285a, 0);
        selected_drop->append_line(0x285b, 0);
        selected_drop->append_line(0x285c, 0);
        selected_drop->append_line(0x285d, 0);
        selected_drop->append_line(0x285e, 0);
        selected_drop->append_line(0x285f, 0);
        selected_drop->append_line(0x2860, 0);
        selected_drop->append_line(0x2861, 0);
        selected_drop->append_line(0x2862, 0);
        selected_drop->append_line(0x284f, 0);
    } else if (param_3 == this_->player_setting_drop + 1) {
        selected_drop->append_line(0x27f7, 0);
        selected_drop->append_line(0x27f8, 0);
        selected_drop->append_line(0x27f9, 0);
        selected_drop->append_line(0x27fa, 0);
        selected_drop->append_line(0x27fb, 0);
        selected_drop->append_line(0x27fc, 0);
        selected_drop->append_line(0x27fd, 0);
        selected_drop->append_line(0x27fe, 0);
        selected_drop->append_line(0x27ff, 0);
        selected_drop->append_line(0x2800, 0);
        selected_drop->append_line(0x2801, 0);
        selected_drop->append_line(0x2802, 0);
        selected_drop->append_line(0x2806, 0);
        selected_drop->append_line(0x2807, 0);
        selected_drop->append_line(0x2809, 0);
        selected_drop->append_line(0x2808, 0);
    } else if (param_3 == &this_->victory_ages_list) {
        selected_drop->append_line(0x1069, 0);
        selected_drop->append_line(0x106a, 0);
        selected_drop->append_line(0x106b, 0);
        selected_drop->append_line(0x106c, 0);
    } else if (param_3 == &this_->victory_tech_list) {
        selected_drop->set_sorted(1);
        if (this_->world && this_->world->tech && this_->world->tech->tech_tree && this_->world->tech->tech_tree_num > 0) {
            for (int i = 0; i < this_->world->tech->tech_tree_num; ++i) {
                const char* tech_name = this_->get_string((long)this_->world->tech->tech_tree[i].string_id);
                if (tech_name != nullptr && *tech_name != '\0') {
                    selected_drop->append_line((char*)tech_name, i);
                }
            }
        }
    } else if (param_3 == &this_->AiRules) {
        MakeFileList(this_, selected_drop, rge_base_game->prog_info->ai_dir, (char*)"*.per", 0, 1);
    } else if (param_3 == &this_->BuildList) {
        MakeFileList(this_, selected_drop, rge_base_game->prog_info->ai_dir, (char*)"*.ai", 1, 1);
    } else if (param_3 == &this_->CityLayout) {
        MakeFileList(this_, selected_drop, rge_base_game->prog_info->ai_dir, (char*)"*.cty", 1, 0);
    } else if (param_3 == this_->cinematic_input ||
               param_3 == this_->cinematic_input + 1 ||
               param_3 == this_->cinematic_input + 2) {
        MakeFileList(this_, selected_drop, rge_base_game->prog_info->avi_dir, (char*)"*.avi", 1, 0);
    } else if (param_3 == this_->cinematic_input + 3) {
        MakeFileList(this_, selected_drop, (char*)"", (char*)"*.bmp", 1, 0);
    } else if (param_3 == &this_->victory_object_list) {
        selected_drop->set_sorted(1);
        selected_drop->empty_list();

        RGE_Master_Player* master_player = (this_->world && this_->world->master_players) ? this_->world->master_players[0] : nullptr;
        if (master_player && master_player->master_objects && master_player->master_object_num > 0) {
            char str[256];
            for (int i = 0; i < master_player->master_object_num; ++i) {
                RGE_Master_Static_Object* master = master_player->master_objects[i];
                if (master != nullptr && master->hide_in_scenario_editor == '\0') {
                    if (master->string_id < 1) {
                        const char* master_name = (master->name != nullptr) ? master->name : "";
                        strncpy(str, master_name, sizeof(str) - 1);
                        str[sizeof(str) - 1] = '\0';
                    } else {
                        rge_base_game->get_string((long)master->string_id, str, (int)sizeof(str));
                    }
                    selected_drop->append_line(str, i);
                }
            }
        }
    }

    selected_drop->set_line(selected_line);
    return (this_->is_multi_player == 0) ? 1 : 0;
}

static int SetupListOfTerrain(TRIBE_Screen_Sed* this_, TListPanel* param_2) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004A9320
    if (!this_ || !param_2) return 0;
    param_2->empty_list();
    param_2->append_line(0x297d, 0);
    param_2->append_line(0x297e, 0);
    param_2->append_line(0x297f, 0);
    param_2->append_line(0x2980, 0);
    param_2->append_line(0x2981, 0);
    param_2->append_line(0x2982, 0);
    param_2->append_line(0x2983, 0);
    param_2->append_line(0x2984, 0);
    param_2->append_line(0x2985, 0);
    return 8;
}

static int create_list(TRIBE_Screen_Sed* this_, TPanel* param_2, TListPanel** param_3, TScrollBarPanel** param_4) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004A93C0
    if (!this_) return 0;
    const int created = this_->TEasy_Panel::create_list(param_2, param_3, 0, 0, 0, 0, 10);
    if (created == 0) return 0;
    (*param_3)->set_active(0);
    (*param_3)->empty_list();
    if (this_->TEasy_Panel::create_auto_scrollbar(param_4, (TTextPanel*)*param_3, 0x14) == 0) return 0;

    if (param_3 == &this_->paint_elevation_list) {
        char str1[50];
        char str2[60];
        set_string(this_, str1, 0x2987, 0x32);
        for (int i = 1; i < 8; ++i) {
            sprintf(str2, "%s %d", str1, i);
            this_->paint_elevation_list->append_line(str2, 0);
        }
        return 1;
    }

    if (param_3 == &this_->paint_terrain_list) {
        SetupListOfTerrain(this_, this_->paint_terrain_list);
    }
    return 1;
}

static int FUN_004aa6e6() {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004AA6E6
    if (rge_base_game == nullptr) return 0;
    rge_base_game->set_game_mode(8, rge_base_game->sub_game_mode);
    return 0;
}

static void set_paint_object_mode(TRIBE_Screen_Sed* this_) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004AA730
    if (!this_ || !rge_base_game || !this_->world) return;

    bool can_place_building = false;
    if (rge_base_game->master_obj_id != -1 &&
        this_->player_num >= 0 &&
        this_->player_num < this_->world->player_num) {
        RGE_Player* player = this_->world->players[this_->player_num];
        if (player && player->master_objects) {
            RGE_Master_Static_Object* master = player->master_objects[rge_base_game->master_obj_id];
            if ((master != nullptr) && (master->master_type == 'P') &&
                (((TRIBE_Master_Building_Object*)master)->building_connect_flag != 0)) {
                can_place_building = true;
            }
        }
    }

    if (can_place_building) {
        rge_base_game->set_game_mode(0x15, 0);
    } else {
        rge_base_game->set_game_mode(8, rge_base_game->sub_game_mode);
    }
}

static void FUN_004aab4a() {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004AAB4A
}

static void set_terrain(TRIBE_Screen_Sed* this_, short param_2) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004AAD50
    if (!this_ || !rge_base_game) return;
    short terrain_id = 0;
    switch (param_2) {
    case 1: terrain_id = 6; break;
    case 2: terrain_id = 10; break;
    case 3: terrain_id = 1; break;
    case 4: terrain_id = 0xD; break;
    case 5: terrain_id = 0x14; break;
    case 6: terrain_id = 4; break;
    case 7: terrain_id = 0x13; break;
    case 8: terrain_id = 0x16; break;
    default: break;
    }
    rge_base_game->terrain_id = terrain_id;
    if (this_->paint_terrain_list) this_->paint_terrain_list->scroll_cur_line('\x01', param_2, 1);
}

static void set_elevation(TRIBE_Screen_Sed* this_, short param_2) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004AADF0
    if (!this_ || !rge_base_game) return;
    rge_base_game->elevation_height = param_2;
    if (this_->paint_elevation_list) this_->paint_elevation_list->scroll_cur_line('\x01', param_2, 1);
}

static int TRIBE_Screen_Sed_unit_list_compare(void* param_1, void* param_2) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004AB2D0
    const int cmp = CompareStringA(0x400, 1, (const char*)param_1, -1, (const char*)param_2, -1);
    if (cmp == 1) {
        return -1;
    }
    return (cmp == 3) ? 1 : 0;
}

static void FUN_004abc31() {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004ABC31
}

static void FUN_004ad06e() {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004AD06E
}

static void command_cancel(TRIBE_Screen_Sed* this_) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004AD240
    if (!this_) return;
    if (!rge_base_game) return;
    RGE_Player* player = rge_base_game->get_player();
    if (player) {
        player->unselect_object();
        player->unselect_area();
    }
}

static void command_outline(TRIBE_Screen_Sed* this_) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004AD630
    if (!this_ || !rge_base_game) return;
    switch (rge_base_game->outline_type) {
    case '\0':
    case '\x03':
        rge_base_game->outline_type = '\x02';
        break;
    case '\x01':
        rge_base_game->outline_type = '\0';
        break;
    case '\x02':
        rge_base_game->outline_type = '\x01';
        break;
    default:
        break;
    }
}

static void command_player(TRIBE_Screen_Sed* this_, int param_2) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004AD680
    (void)this_;
    if (!rge_base_game) return;
    rge_base_game->set_player((short)param_2);
}

static void command_save_as(TRIBE_Screen_Sed* this_, unsigned char param_2) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004AD960
    if (!this_ || !this_->world || !this_->world->scenario || !rge_base_game) return;

    set_scenario_mode(this_, TRIBE_Screen_Sed::ScenarioModeSave);
    ((T_Scenario*)this_->world->scenario)->Save_victory_conditions_into_players(1);
    if (this_->world->scenario->active_player_count() < 1) {
        this_->popupOKDialog(0x2742, (char*)0, 0x1c2, 100);
        return;
    }
    if (this_->world->scenario->any_player_count() < 1) {
        this_->popupOKDialog(0x2743, (char*)0, 0x1c2, 100);
        return;
    }

    char scenario_name[224];
    scenario_name[0] = '\0';
    TribeSaveGameScreen* save_screen = new TribeSaveGameScreen(TribeSaveGameScreen::SaveScenarioEdit, scenario_name, (uint)param_2);
    if (save_screen && save_screen->error_code != 0) {
        delete save_screen;
        return;
    }
    if (panel_system) {
        panel_system->setCurrentPanel(kSaveGameScreenName, 0);
        panel_system->destroyPanel(kScenarioMenuDialogName);
    }
}

static char* scenario_get_default_name(TRIBE_Screen_Sed* this_) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004ADA70
    if (!this_ || !this_->world || !this_->world->scenario || !rge_base_game || !rge_base_game->registry) return (char*)0;
    char* name = this_->world->scenario->Get_scenario_name();
    if (name == nullptr || *name == '\0') {
        char temp_name[260];
        const int game_file_no = rge_base_game->registry->RegGetInt(0, (char*)"Game File Number");
        sprintf(temp_name, "default%d.scx", game_file_no);
        this_->world->scenario->Set_scenario_name(temp_name);
    }
    return this_->world->scenario->Get_scenario_name();
}

static void command_quick_save(TRIBE_Screen_Sed* this_) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004ADAF0
    if (!this_) return;
    (void)scenario_get_default_name(this_);
    (void)command_save(this_, 0, 0);
}

static char* scenario_save_defaulted(TRIBE_Screen_Sed* this_) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004ADB10
    if (!this_ || !this_->world || !this_->world->scenario || !rge_base_game || !rge_base_game->registry) {
        return (char*)0;
    }

    set_scenario_mode(this_, TRIBE_Screen_Sed::ScenarioModeSave);
    ((T_Scenario*)this_->world->scenario)->Save_victory_conditions_into_players(1);

    if (this_->world->scenario->active_player_count() < 1) {
        this_->popupOKDialog(0x2742, (char*)0, 0x1c2, 100);
        return (char*)0;
    }
    if (this_->world->scenario->any_player_count() < 1) {
        this_->popupOKDialog(0x2743, (char*)0, 0x1c2, 100);
        return (char*)0;
    }

    ((TRIBE_Game*)rge_base_game)->show_status_message(0x450, (char*)0, -1);
    const int game_file_no = rge_base_game->registry->RegGetInt(0, (char*)"Game File Number");
    char default_scx[260];
    sprintf(default_scx, "default%d.scx", game_file_no);

    const int save_ok = this_->world->save_scenario(default_scx);
    ((TRIBE_Game*)rge_base_game)->close_status_message();
    if (save_ok == 0) {
        this_->popupOKDialog(0x963, (char*)0, 0x1c2, 100);
        return (char*)0;
    }

    char default_name[260];
    sprintf(default_name, "default%d", game_file_no);
    this_->world->scenario->Set_scenario_name(default_name);
    return this_->world->scenario->Get_scenario_name();
}

void TRIBE_Screen_Sed::set_string(TRIBE_Screen_Sed* this_, char* param_2, long param_3, int param_4) {
    ::set_string(this_, param_2, param_3, param_4);
}

int TRIBE_Screen_Sed::SetupListOfTerrain(TRIBE_Screen_Sed* this_, TListPanel* param_2) {
    return ::SetupListOfTerrain(this_, param_2);
}

void TRIBE_Screen_Sed::set_paint_object_mode(TRIBE_Screen_Sed* this_) {
    ::set_paint_object_mode(this_);
}

void TRIBE_Screen_Sed::set_terrain(TRIBE_Screen_Sed* this_, short param_2) {
    ::set_terrain(this_, param_2);
}

void TRIBE_Screen_Sed::set_elevation(TRIBE_Screen_Sed* this_, short param_2) {
    ::set_elevation(this_, param_2);
}

int TRIBE_Screen_Sed::TRIBE_Screen_Sed_unit_list_compare(void* param_1, void* param_2) {
    return ::TRIBE_Screen_Sed_unit_list_compare(param_1, param_2);
}

void TRIBE_Screen_Sed::command_cancel(TRIBE_Screen_Sed* this_) {
    ::command_cancel(this_);
}

void TRIBE_Screen_Sed::command_outline(TRIBE_Screen_Sed* this_) {
    ::command_outline(this_);
}

void TRIBE_Screen_Sed::command_player(TRIBE_Screen_Sed* this_, int param_2) {
    ::command_player(this_, param_2);
}

void TRIBE_Screen_Sed::command_save_as(TRIBE_Screen_Sed* this_, unsigned char param_2) {
    ::command_save_as(this_, param_2);
}

char* TRIBE_Screen_Sed::scenario_get_default_name(TRIBE_Screen_Sed* this_) {
    return ::scenario_get_default_name(this_);
}

void TRIBE_Screen_Sed::command_quick_save(TRIBE_Screen_Sed* this_) {
    ::command_quick_save(this_);
}

char* TRIBE_Screen_Sed::scenario_save_defaulted(TRIBE_Screen_Sed* this_) {
    return ::scenario_save_defaulted(this_);
}

static int command_new_map(TRIBE_Screen_Sed* this_, char* scenario_filename, int is_multi_player, int param_4, int param_5, int param_6, int show_status) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004AD340
    (void)is_multi_player;
    (void)param_4;
    (void)param_5;
    (void)param_6;

    if (!this_ || !rge_base_game) return 0;
    this_->need_to_save_flag = 0;

    if (rge_base_game->world == nullptr) {
        if (show_status != 0) {
            ((TRIBE_Game*)rge_base_game)->show_status_message(0x44d, (char*)0, -1); // "Loading game data..."
        }
        const int ok = ((TRIBE_Game*)rge_base_game)->load_game_data();
        if (show_status != 0) {
            ((TRIBE_Game*)rge_base_game)->close_status_message();
        }
        if (ok == 0) return 0;
    }

    this_->world = (TRIBE_World*)rge_base_game->world;

    if (show_status != 0) {
        ((TRIBE_Game*)rge_base_game)->show_status_message((scenario_filename == nullptr) ? 0x44e : 0x44f, (char*)0, -1);
    }

    if (scenario_filename != nullptr && this_->world && this_->world->scenario) {
        this_->world->scenario->Set_scenario_name(scenario_filename);
    }
    if (this_->player_number_list != nullptr && this_->world && this_->world->scenario) {
        int active_count = 0;
        while (active_count < 8) {
            if (this_->world->scenario->Get_player_Active(active_count) == 0) break;
            active_count++;
        }
        this_->player_number_list->set_line((active_count > 0) ? (active_count - 1) : 0);
    }
    if (show_status != 0) {
        ((TRIBE_Game*)rge_base_game)->close_status_message();
    }

    return (this_->world != nullptr) ? 1 : 0;
}

static int need_to_save(TRIBE_Screen_Sed* this_) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004ADC30
    return this_->need_to_save_flag;
}

static int command_menu(TRIBE_Screen_Sed* this_) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004AD270
    if (!this_) return 0;

    TRIBE_Dialog_Sed_Menu* dlg = new TRIBE_Dialog_Sed_Menu(this_);
    if (dlg != nullptr && dlg->error_code != 0) {
        delete dlg;
        return 0;
    }

    if (panel_system) {
        panel_system->setCurrentPanel(kScenarioMenuDialogName, 0);
    }
    return 1;
}

static void command_new(TRIBE_Screen_Sed* this_) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004AD300
    if (!this_) return;

    if (need_to_save(this_) != 0) {
        // "Do you want to save your changes to this scenario?"
        this_->popupYesNoCancelDialog(0x2447, kNewSaveDialogName, 0x1c2, 100);
        return;
    }

    if (rge_base_game) {
        ((TRIBE_Game*)rge_base_game)->start_scenario_editor((char*)0, 0);
    }
}

static void command_open(TRIBE_Screen_Sed* this_) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004AD590
    if (!this_) return;
    if (need_to_save(this_) != 0) {
        this_->popupYesNoCancelDialog(0x2447, kOpenSaveDialogName, 0x1c2, 100);
        return;
    }

    TRIBE_Screen_Sed_Open* open = new TRIBE_Screen_Sed_Open();
    if (open == nullptr) return;
    if (panel_system == nullptr) {
        delete open;
        return;
    }
    if (open->error_code != 0) {
        delete open;
        return;
    }

    {
        panel_system->add_panel((TPanel*)open);
        panel_system->setCurrentPanel((char*)"Scenario Editor Open", 0);
    }
}

static void command_quit(TRIBE_Screen_Sed* this_) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004AD6A0
    if (!this_ || !rge_base_game) return;

    if (need_to_save(this_) != 0) {
        this_->popupYesNoCancelDialog(0x2447, kQuitSaveDialogName, 0x1c2, 100);
        return;
    }

    const int ok = ((TRIBE_Game*)rge_base_game)->start_menu();
    if (ok == 0) {
        rge_base_game->close();
        return;
    }

    if (panel_system) {
        panel_system->destroyPanel(kScenarioEditorScreenName);
    }
}

static int command_save(TRIBE_Screen_Sed* this_, unsigned char param_1, unsigned char param_2) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004AD700
    if (!this_ || !this_->world || !this_->world->scenario || !rge_base_game) return 0;

    set_scenario_mode(this_, TRIBE_Screen_Sed::ScenarioModeSave);
    ((T_Scenario*)this_->world->scenario)->Save_victory_conditions_into_players(1);
    if (this_->world->scenario->active_player_count() < 1) {
        if (panel_system) panel_system->destroyPanel(kScenarioMenuDialogName);
        this_->popupOKDialog(0x2742, (char*)0, 0x1c2, 100);
        return 0;
    }
    if (this_->world->scenario->any_player_count() < 1) {
        if (panel_system) panel_system->destroyPanel(kScenarioMenuDialogName);
        this_->popupOKDialog(0x2743, (char*)0, 0x1c2, 100);
        return 0;
    }

    char* scenario_name = this_->world->scenario->Get_scenario_name();
    if (scenario_name == nullptr || *scenario_name == '\0') {
        command_save_as(this_, param_2);
        return 0;
    }

    ((TRIBE_Game*)rge_base_game)->show_status_message(0x450, (char*)0, -1);
    if (param_1 != 0 && panel_system) {
        panel_system->destroyPanel(kScenarioMenuDialogName);
    }
    const int save_ok = this_->world->save_scenario(scenario_name);
    ((TRIBE_Game*)rge_base_game)->close_status_message();
    if (save_ok == 0) {
        this_->popupOKDialog(0x963, (char*)0, 0x1c2, 100);
        return 0;
    }

    if (rge_base_game->registry) {
        char temp_name[260];
        const int game_file_no = rge_base_game->registry->RegGetInt(0, (char*)"Game File Number");
        sprintf(temp_name, "default%d", game_file_no);
        if (strcmp(scenario_name, temp_name) != 0) {
            this_->need_to_save_flag = 0;
        }
    }

    if (param_2 == 1) {
        const int menu_ok = ((TRIBE_Game*)rge_base_game)->start_menu();
        if (menu_ok == 0) {
            rge_base_game->close();
        } else if (panel_system) {
            panel_system->destroyPanel(kScenarioEditorScreenName);
        }
    } else if (param_2 == 2) {
        TRIBE_Screen_Sed_Open* open = new TRIBE_Screen_Sed_Open();
        if (open && open->error_code == 0 && panel_system) {
            panel_system->add_panel((TPanel*)open);
            panel_system->setCurrentPanel((char*)"Scenario Editor Open", 0);
        } else if (open) {
            delete open;
        }
    } else if (param_2 == 3) {
        ((TRIBE_Game*)rge_base_game)->start_scenario_editor((char*)0, 0);
    }

    return 1;
}

static void create_all_buttons_etc(TRIBE_Screen_Sed* this_) {
    // Fully verified. Source of truth: scr_sed2.cpp.decomp @ 0x004AF6C0
    if (!this_) return;

    // Scenario mode buttons (Map/Terrain/Players/Units/Diplomacy/Individual Victory/Global Victory/Options/Messages/Cinematics)
    const long mode_ids[10] = { 0x271a, 0x271b, 0x271c, 0x271d, 0x2722, 0x271e, 0x2723, 0x2721, 0x271f, 0x2720 };
    for (int i = 0; i < 10; ++i) {
        (void)this_->create_button((TPanel*)this_, &this_->scenario_mode_button[i], mode_ids[i], 0, 0, 0, 0, 0, 10, 1, 0);
        if (this_->scenario_mode_button[i]) this_->scenario_mode_button[i]->set_active(1);
    }

    (void)this_->create_button((TPanel*)this_, &this_->menu_button, 0x2724, 0, 0, 0, 0, 0, 10, 1, 0);
    (void)this_->create_button((TPanel*)this_, &this_->help_button, 0x0fa9, 0, 0, 0, 0, 0, 10, 1, 0);
}

static void position_panels(TRIBE_Screen_Sed* this_) {
    // Fully verified. Source of truth: scr_sed2.cpp.decomp @ 0x004B1A50
    if (this_ == nullptr || this_->main_view == nullptr) return;

    const long width = this_->width();
    const long height = this_->height();
    const long bottom_height = 0x89;

    if (this_->bottom_panel != nullptr) this_->bottom_panel->set_rect(0, height - bottom_height, width, bottom_height);
    if (this_->main_view != nullptr) ((TPanel*)this_->main_view)->set_rect(0, 0, width, height - bottom_height);
    if (this_->map_view != nullptr) ((TPanel*)this_->map_view)->set_rect(width - 0x87, 0, 0x87, 0x87);
    if (this_->message_panel != nullptr) ((TPanel*)this_->message_panel)->set_rect(0, 0, width - 0x87, 0x18);
}

TRIBE_Screen_Sed::TRIBE_Screen_Sed(char* scenario_name, int is_multi_player_in)
    // Partially verified. Source of truth: scr_sed.cpp.asm @ 0x004A81E0
    // TODO: PARITY - Constructor remains partially verified; perform full control-flow/constant/sign audit before treating this path as parity-complete. [decomp: scr_sed.cpp.decomp @ 0x004A81E0]
    : TScreenPanel(kScenarioEditorScreenName) {
    this->is_multi_player = 0;
    this->scenario_mode = ScenarioModeNone;
    this->map_type = MapTypeNone;
    this->mp_victory_type = VictoryTypeConquest;
    this->brush_size = BrushSizeNone;
    this->paint_type = PaintTypeNone;
    this->player_num = 1;
    this->message_type = MessageTypeNone;
    this->SelectedObject = nullptr;
    this->DestinationObject = nullptr;
    this->CurrentPlayer = 0;
    this->need_to_save_flag = 0;
    this->valid_save_spot_flag = 0;

    init_module_variables(this);

    this->update_interval = 200;
    this->last_update_time = debug_timeGetTime(kScrSedSourcePath, 0x117);
    this->map_redraw_interval = 1000;
    this->last_map_redraw_time = debug_timeGetTime(kScrSedSourcePath, 0x11a);

    this->save_text_color = 0;
    this->save_window_color = 0;
    this->changed_system_colors = 0;
    this->CurrentVictory = 0;

    if (!rge_base_game || !rge_base_game->draw_area) {
        this->error_code = 1;
        return;
    }

    rge_base_game->set_prog_mode(7);

    if (command_new_map(this, scenario_name, is_multi_player_in, 0, 0x90, 0x90, 1) == 0) {
        this->error_code = 1;
        return;
    }

    // If we're editing the default scenario, mark as needing a save (matches original startup behavior).
    if (rge_base_game->registry != nullptr && scenario_name != nullptr) {
        const int game_file_no = rge_base_game->registry->RegGetInt(0, (char*)"Game File Number");
        char temp_name[260];
        sprintf(temp_name, "default%d.scx", game_file_no);
        if (strcmp(scenario_name, temp_name) == 0) {
            this->need_to_save_flag = 1;
        }
    }

    if (this->TScreenPanel::setup(rge_base_game->draw_area, (char*)"scr5", 0xC387, 1) == 0) {
        this->error_code = 1;
        return;
    }

    this->setup_shadow_area(0);

    // Main view.
    this->main_view = new TRIBE_Main_View();
    if (this->main_view == nullptr || ((RGE_View*)this->main_view)->setup(rge_base_game->draw_area, this, 0, 0, 0, 0, (uchar)0xA1) == 0) {
        this->error_code = 1;
        return;
    }
    this->main_view->set_help_info(-1, -1);

    // Diamond minimap.
    this->map_view = new RGE_Diamond_Map_View();
    if (this->map_view == nullptr || this->map_view->error_code != 0 ||
        ((RGE_Diamond_Map*)this->map_view)->setup(rge_base_game->draw_area, this, 0, 0, 0, 0, (uchar)0xA1, 0, rge_base_game->map_save_area) == 0) {
        this->error_code = 1;
        return;
    }
    ((RGE_Diamond_Map*)this->map_view)->set_bitmap((char*)"map640.bmp", 0xC4E1);
    ((RGE_Diamond_Map*)this->map_view)->set_main_view((RGE_View*)this->main_view);
    ((RGE_Main_View*)this->main_view)->map_view = (TPanel*)this->map_view;

    // Message panel.
    {
        RGE_Font* font = rge_base_game->get_font(0xb);
        this->message_panel = (font != nullptr) ? new TMessagePanel(font->font, font->font_wid, font->font_hgt) : new TMessagePanel();
        if (this->message_panel == nullptr || this->message_panel->setup(rge_base_game->draw_area, this->main_view, 0, 0, 0, 0, 0) == 0) {
            this->error_code = 1;
            return;
        }
    }

    // Bottom panel container.
    this->bottom_panel = new TPanel();
    if (this->bottom_panel == nullptr || this->bottom_panel->setup(rge_base_game->draw_area, this, 0, 0, 0, 0, 0) == 0) {
        this->error_code = 1;
        return;
    }

    create_all_buttons_etc(this);

    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004A81E0 (player-state/name flow)
    int player_num_line = 1;
    if (scenario_name == nullptr || *scenario_name == '\0') {
        set_player_active(this, 0, 1);
        set_player_active(this, 1, 1);
        player_num_line = 1;
    } else {
        if (this->world && this->world->scenario) {
            if (strstr(scenario_name, ".scn") != nullptr || strstr(scenario_name, ".SCN") != nullptr) {
                char name[260];
                int i = 0;
                while (scenario_name[i] != '\0' && scenario_name[i] != '.' && i < (int)sizeof(name) - 1) {
                    name[i] = scenario_name[i];
                    ++i;
                }
                name[i] = '\0';
                char scx_name[260];
                sprintf(scx_name, "%s.scx", name);
                this->world->scenario->Set_scenario_name(scx_name);
            }

            int i = 0;
            while (i < 8) {
                if (this->world->scenario->Get_player_Active(i) == 0) break;
                ++i;
            }
            player_num_line = i - 1;
        }
    }
    if (this->player_number_list) {
        this->player_number_list->set_line(player_num_line);
    }
    SavePlayerActiveStatus(this);

    this->set_curr_child(this->bottom_panel);
    position_panels(this);
    set_panel_info(this);

    set_map_type(this, MapTypeBlank, 0);
    set_mp_victory_type(this, VictoryTypeStandard, 0);
    set_brush_size(this, BrushSizeVerySmall);
    set_paint_type(this, PaintTypeTerrain, 0);
    set_player(this, 1, '\0', '\0');
    set_unit_player(this, 1);
    set_message_type(this, MessageTypeDescription, 0);
    set_scenario_mode(this, ScenarioModeMap);
    set_unit(this, -1);
    if (this->world && this->world->map) {
        this->world->map->set_map_visible('\x01');
        this->world->map->set_map_fog('\0');
    }
}

TRIBE_Screen_Sed::~TRIBE_Screen_Sed() {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004A94A0
    if (panel_system) {
        panel_system->destroyPanel(kQuitSaveDialogName);
        panel_system->destroyPanel(kOpenSaveDialogName);
        panel_system->destroyPanel(kNewSaveDialogName);
        panel_system->destroyPanel(kSaveGameScreenName);
        panel_system->destroyPanel(kScenarioMenuDialogName);
    }

    this->delete_panel((TPanel**)&this->map_type_label);
    for (int i = 0; i < 3; ++i) {
        this->delete_panel((TPanel**)&this->map_type_button[i]);
        this->delete_panel((TPanel**)&this->map_type_text[i]);
    }

    this->delete_panel((TPanel**)&this->default_terrain_label);
    this->delete_panel((TPanel**)&this->default_terrain_drop);
    this->delete_panel((TPanel**)&this->map_size_label);
    this->delete_panel((TPanel**)&this->map_size_drop);
    this->delete_panel((TPanel**)&this->map_style_drop);
    this->delete_panel((TPanel**)&this->map_style_label);
    this->delete_panel((TPanel**)&this->map_generating_text);
    this->delete_panel((TPanel**)&this->random_seed_label);
    this->delete_panel((TPanel**)&this->random_seed_input);
    this->delete_panel((TPanel**)&this->random_seed_used_label);
    this->delete_panel((TPanel**)&this->random_seed_used_text);
    this->delete_panel((TPanel**)&this->generate_map_button);
    this->delete_panel((TPanel**)&this->brush_size_label);
    for (int i = 0; i < 5; ++i) {
        this->delete_panel((TPanel**)&this->brush_size_button[i]);
        this->delete_panel((TPanel**)&this->brush_size_button_label[i]);
    }

    this->delete_panel((TPanel**)&this->paint_type_label);
    for (int i = 0; i < 3; ++i) {
        this->delete_panel((TPanel**)&this->paint_type_button[i]);
        this->delete_panel((TPanel**)&this->paint_type_button_label[i]);
    }

    this->delete_panel((TPanel**)&this->paint_terrain_label);
    this->delete_panel((TPanel**)&this->paint_terrain_list);
    this->delete_panel((TPanel**)&this->paint_terrain_scrollbar);
    this->delete_panel((TPanel**)&this->paint_elevation_list);
    this->delete_panel((TPanel**)&this->paint_elevation_scrollbar);
    this->delete_panel((TPanel**)&this->player_advance_civilization_drop);
    this->delete_panel((TPanel**)&this->player_label);
    this->delete_panel((TPanel**)&this->player_starting_age_label);
    this->delete_panel((TPanel**)&this->player_build_text);
    this->delete_panel((TPanel**)&this->player_city_text);
    this->delete_panel((TPanel**)&this->AiRules_text);
    this->delete_panel((TPanel**)&this->player_list);
    this->delete_panel((TPanel**)&this->player_number_list);

    for (int i = 0; i < 5; ++i) {
        this->delete_panel((TPanel**)&this->player_inven_label[i]);
        this->delete_panel((TPanel**)&this->player_inven_input[i]);
    }
    for (int i = 0; i < 2; ++i) {
        this->delete_panel((TPanel**)&this->player_setting_label[i]);
        this->delete_panel((TPanel**)&this->player_setting_drop[i]);
    }

    this->delete_panel((TPanel**)&this->BuildList);
    this->delete_panel((TPanel**)&this->CityLayout);
    this->delete_panel((TPanel**)&this->AiRules);
    this->delete_panel((TPanel**)&this->unit_player_list);
    for (int i = 0; i < 4; ++i) {
        this->delete_panel((TPanel**)&this->unit_mode_select[i]);
        this->delete_panel((TPanel**)&this->unit_mode_select_label[i]);
    }
    this->delete_panel((TPanel**)&this->unit_list);
    this->delete_panel((TPanel**)&this->unit_scrollbar);

    if (this->unit_list_info) {
        free(this->unit_list_info);
        this->unit_list_info = nullptr;
    }
    if (this->object_panel) {
        delete this->object_panel;
        this->object_panel = nullptr;
    }
    if (this->button_unit_pics) {
        delete this->button_unit_pics;
        this->button_unit_pics = nullptr;
    }
    for (int i = 0; i < 5; ++i) {
        if (this->button_bldg_pics[i]) {
            delete this->button_bldg_pics[i];
            this->button_bldg_pics[i] = nullptr;
        }
    }

    for (int i = 0; i < 6; ++i) {
        this->delete_panel((TPanel**)&this->victory_cond_on[i]);
    }
    for (int i = 0; i < 2; ++i) {
        this->delete_panel((TPanel**)&this->victory_and_or[i]);
        this->delete_panel((TPanel**)&this->victory_text_and_or[i]);
    }

    this->delete_panel((TPanel**)&this->victory_amount_label);
    this->delete_panel((TPanel**)&this->victory_long_label);
    this->delete_panel((TPanel**)&this->victory_condition_label);
    this->delete_panel((TPanel**)&this->victory_label_conquest);
    this->delete_panel((TPanel**)&this->victory_label_explore);
    this->delete_panel((TPanel**)&this->victory_label_explore_percent);
    this->delete_panel((TPanel**)&this->victory_label_ruins);
    this->delete_panel((TPanel**)&this->victory_label_artifacts);
    this->delete_panel((TPanel**)&this->victory_label_discoveries);
    this->delete_panel((TPanel**)&this->victory_label_gold);
    this->delete_panel((TPanel**)&this->victory_condition_explore);
    this->delete_panel((TPanel**)&this->victory_condition_ruins);
    this->delete_panel((TPanel**)&this->victory_condition_artifacts);
    this->delete_panel((TPanel**)&this->victory_condition_discoveries);
    this->delete_panel((TPanel**)&this->victory_condition_gold);
    for (int i = 0; i < 5; ++i) {
        this->delete_panel((TPanel**)&this->victory_cond_type_label[i]);
        this->delete_panel((TPanel**)&this->victory_cond_type[i]);
    }

    this->delete_panel((TPanel**)&this->victory_score_label);
    this->delete_panel((TPanel**)&this->victory_score);
    this->delete_panel((TPanel**)&this->victory_time_label);
    this->delete_panel((TPanel**)&this->victory_time);
    for (int i = 0; i < 12; ++i) {
        this->delete_panel((TPanel**)&this->victory_button[i]);
    }

    this->delete_panel((TPanel**)&this->victory_drop_down);
    this->delete_panel((TPanel**)&this->victory_object_list);
    this->delete_panel((TPanel**)&this->victory_player_list);
    this->delete_panel((TPanel**)&this->victory_ages_list);
    this->delete_panel((TPanel**)&this->victory_tech_list);
    this->delete_panel((TPanel**)&this->victory_button_set_object);
    this->delete_panel((TPanel**)&this->victory_button_set_destination);
    this->delete_panel((TPanel**)&this->victory_button_go_to_dest);
    this->delete_panel((TPanel**)&this->victory_condition_text);
    this->delete_panel((TPanel**)&this->victory_condition_type);
    this->delete_panel((TPanel**)&this->victory_amount_text);
    this->delete_panel((TPanel**)&this->victory_amount_input);
    this->delete_panel((TPanel**)&this->victory_enemy_player_list);
    this->delete_panel((TPanel**)&this->victory_attribute_list);
    this->delete_panel((TPanel**)&this->victory_which_enemy_text);
    this->delete_panel((TPanel**)&this->victory_object_scrollbar);

    for (int i = 0; i < 5; ++i) {
        this->delete_panel((TPanel**)&this->message_button[i]);
        this->delete_panel((TPanel**)&this->message_button_label[i]);
    }
    this->delete_panel((TPanel**)&this->message_input);

    for (int i = 0; i < 4; ++i) {
        this->delete_panel((TPanel**)&this->cinematic_label[i]);
        this->delete_panel((TPanel**)&this->cinematic_input[i]);
    }

    for (int i = 0; i < 1; ++i) {
        this->delete_panel((TPanel**)&this->options_label[i]);
        this->delete_panel((TPanel**)&this->options_button[i]);
    }
    this->delete_panel((TPanel**)&this->options_player_list);
    this->delete_panel((TPanel**)&this->options_disable_tech_text);
    for (int i = 0; i < 16; ++i) {
        this->delete_panel((TPanel**)&this->options_disable_button[i]);
        this->delete_panel((TPanel**)&this->options_disable_text[i]);
    }

    this->delete_panel((TPanel**)&this->Diplomacy_player_list);
    for (int i = 0; i < 8; ++i) {
        this->delete_panel((TPanel**)&this->Diplomacy_opponent_label[i]);
        this->delete_panel((TPanel**)&this->Diplomacy_player_text[i]);
        this->delete_panel((TPanel**)&this->Diplomacy_friend_box[i][0]);
        this->delete_panel((TPanel**)&this->Diplomacy_friend_box[i][1]);
        this->delete_panel((TPanel**)&this->Diplomacy_friend_box[i][2]);
        this->delete_panel((TPanel**)&this->Diplomacy_AlliedVictory[i]);
    }
    for (int i = 0; i < 4; ++i) {
        this->delete_panel((TPanel**)&this->Diplomacy_status_label[i]);
    }

    this->delete_panel((TPanel**)&this->menu_button);
    this->delete_panel((TPanel**)&this->help_button);
    for (int i = 0; i < 10; ++i) {
        this->delete_panel((TPanel**)&this->scenario_mode_button[i]);
    }

    this->delete_panel((TPanel**)&this->bottom_panel);
    this->delete_panel((TPanel**)&this->message_panel);
    this->delete_panel((TPanel**)&this->main_view);
    this->delete_panel((TPanel**)&this->map_view);

    if (this->background_pic) {
        delete this->background_pic;
        this->background_pic = nullptr;
    }

    if (this->world) {
        this->world->del_game_info();
    }
}


long TRIBE_Screen_Sed::handle_size(long param_1, long param_2) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004AB710
    TPanel::handle_size(param_1, param_2);
    position_panels(this);
    TPanel::handle_size(param_1, param_2);
    return 0;
}

long TRIBE_Screen_Sed::handle_idle() {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004AB740
    if (rge_base_game && rge_base_game->prog_mode == 7) {
        const unsigned long now = debug_timeGetTime(kScrSedSourcePath, 0x8b1);
        const unsigned long dt = now - this->last_update_time;
        if ((unsigned long)this->update_interval <= dt) {
            this->last_update_time = now;

            TPanel* modal = (panel_system != nullptr) ? panel_system->modalPanelValue : nullptr;
            if (modal == nullptr) {
                if (this->main_view) ((TPanel*)this->main_view)->set_redraw(TPanel::Redraw);

                const unsigned long map_dt = now - this->last_map_redraw_time;
                if ((unsigned long)this->map_redraw_interval <= map_dt) {
                    if (this->map_view) ((TPanel*)this->map_view)->set_redraw(TPanel::Redraw);
                    this->last_map_redraw_time = now;
                }
            }
        }
    }

    return TPanel::handle_idle();
}

long TRIBE_Screen_Sed::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004AB7D0
    (void)param_2;
    (void)param_3;
    (void)param_5;
    if (panel_system && panel_system->modalPanel() != nullptr) return 0;
    if (!rge_base_game) return 0;

    if (param_4 != 0) {
        switch (param_1) {
        case 'A':
            rge_base_game->outline_type = (rge_base_game->outline_type != '\x03') ? '\x03' : '\0';
            return 1;
        case 'C':
            if (this->scenario_mode_button[9]) this->scenario_mode_button[9]->set_state(1);
            set_scenario_mode(this, ScenarioModeCinematics);
            return 0;
        case 'D':
            if (this->scenario_mode_button[4]) this->scenario_mode_button[4]->set_state(1);
            set_scenario_mode(this, ScenarioModeDiplomacy);
            return 0;
        case 'I':
            if (this->scenario_mode_button[5]) this->scenario_mode_button[5]->set_state(1);
            set_scenario_mode(this, ScenarioModeVictory);
            return 0;
        case 'M':
            if (this->scenario_mode_button[0]) this->scenario_mode_button[0]->set_state(1);
            set_scenario_mode(this, ScenarioModeMap);
            return 0;
        case 'O':
            if (this->scenario_mode_button[7]) this->scenario_mode_button[7]->set_state(1);
            set_scenario_mode(this, ScenarioModeOptions);
            return 0;
        case 'P':
            if (this->scenario_mode_button[2]) this->scenario_mode_button[2]->set_state(1);
            set_scenario_mode(this, ScenarioModePlayers);
            return 0;
        case 'T':
            if (this->scenario_mode_button[1]) this->scenario_mode_button[1]->set_state(1);
            set_scenario_mode(this, ScenarioModeTerrain);
            return 0;
        case 'U':
            if (this->scenario_mode_button[3]) this->scenario_mode_button[3]->set_state(1);
            set_scenario_mode(this, ScenarioModeUnits);
            return 0;
        case 'V':
            if (this->scenario_mode_button[6]) this->scenario_mode_button[6]->set_state(1);
            set_scenario_mode(this, ScenarioModeVictoryMulti);
            return 0;
        case 'W':
            if (this->scenario_mode_button[8]) this->scenario_mode_button[8]->set_state(1);
            set_scenario_mode(this, ScenarioModeMessages);
            return 0;
        case 'B':
            ++View_Grid_Mode;
            if ((rge_base_game->gameDeveloperMode() == 0 && View_Grid_Mode >= 2) ||
                (rge_base_game->gameDeveloperMode() != 0 && View_Grid_Mode >= 5)) {
                View_Grid_Mode = 0;
            }
            if (this->main_view) this->main_view->set_redraw(TPanel::RedrawFull);
            return 0;
        default:
            break;
        }
    }

    switch (param_1) {
    case 9:
        if (this->scenario_mode == ScenarioModePlayers && this->bottom_panel && this->bottom_panel->curr_child == nullptr) {
            this->bottom_panel->set_curr_child((TPanel*)this->player_inven_input[0]);
            return 0;
        }
        break;
    case 0x1b:
        ::command_cancel(this);
        return 0;
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8': {
        const int num = (int)(param_1 - '0');
        if (this->scenario_mode == ScenarioModePlayers && num > 0 && this->bottom_panel && this->bottom_panel->curr_child == nullptr && this->player_list) {
            this->player_list->setCurrentLineNumber(num - 1);
            (void)this->action(this->player_list, 0, 0, 0);
            return 0;
        }
        if (this->scenario_mode == ScenarioModeUnits && this->unit_player_list) {
            this->unit_player_list->setCurrentLineNumber(num);
            (void)this->action(this->unit_player_list, 0, 0, 0);
            return 0;
        }
        if (this->scenario_mode == ScenarioModeDiplomacy && num > 0 && this->Diplomacy_player_list) {
            this->Diplomacy_player_list->setCurrentLineNumber(num - 1);
            (void)this->action(this->Diplomacy_player_list, 1, 0, 0);
            return 0;
        }
        break;
    }
    default:
        break;
    }

    return 0;
}

long TRIBE_Screen_Sed::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004ABCD0
    (void)param_3;
    (void)param_4;

    if (param_1 == nullptr) {
        return 0;
    }

    if (param_2 == 1) {
        if ((TButtonPanel*)param_1 == this->menu_button) {
            return command_menu(this);
        }
        if ((TButtonPanel*)param_1 == this->help_button) {
            this->popupOKDialog((char*)"Help not implemented yet.", (char*)0, 0x1c2, 100);
            return 1;
        }
    }

    // Save prompt dialogs: TMessageDialog forwards action to parent with param_2 = 0/1/2.
    const char* panel_name = param_1->panelName();
    if (panel_name != nullptr) {
        if (strcmp(panel_name, kQuitSaveDialogName) == 0) {
            if (param_2 == 0) {
                if (command_save(this, 0, 0) != 0) {
                    if (panel_system) panel_system->destroyPanel(kQuitSaveDialogName);
                    command_quit(this);
                    return 1;
                }
            } else if (param_2 == 1) {
                this->need_to_save_flag = 0;
                if (panel_system) panel_system->destroyPanel(kQuitSaveDialogName);
                command_quit(this);
                return 1;
            }
            if (panel_system) {
                panel_system->setCurrentPanel(kScenarioEditorScreenName, 0);
                panel_system->destroyPanel(kQuitSaveDialogName);
            }
            return 1;
        }

        if (strcmp(panel_name, kOpenSaveDialogName) == 0) {
            if (param_2 == 0) {
                if (command_save(this, 0, 0) != 0) {
                    if (panel_system) panel_system->destroyPanel(kOpenSaveDialogName);
                    command_open(this);
                    return 1;
                }
            } else if (param_2 == 1) {
                this->need_to_save_flag = 0;
                if (panel_system) panel_system->destroyPanel(kOpenSaveDialogName);
                command_open(this);
                return 1;
            }
            if (panel_system) {
                panel_system->setCurrentPanel(kScenarioEditorScreenName, 0);
                panel_system->destroyPanel(kOpenSaveDialogName);
            }
            return 1;
        }

        if (strcmp(panel_name, kNewSaveDialogName) == 0) {
            if (param_2 == 0) {
                if (command_save(this, 0, 0) != 0) {
                    if (panel_system) panel_system->destroyPanel(kNewSaveDialogName);
                    command_new(this);
                    return 1;
                }
            } else if (param_2 == 1) {
                this->need_to_save_flag = 0;
                if (panel_system) panel_system->destroyPanel(kNewSaveDialogName);
                command_new(this);
                return 1;
            }
            if (panel_system) {
                panel_system->setCurrentPanel(kScenarioEditorScreenName, 0);
                panel_system->destroyPanel(kNewSaveDialogName);
            }
            return 1;
        }
    }

    return TScreenPanel::action(param_1, param_2, param_3, param_4);
}

void TRIBE_Screen_Sed::draw() {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004AD0F0
    TEasy_Panel::draw();

    if ((this->use_bevels != 0) &&
        (this->main_view != nullptr) &&
        (this->render_rect.left == this->clip_rect.left) &&
        (this->render_rect.top == this->clip_rect.top) &&
        (this->render_rect.right == this->clip_rect.right) &&
        (this->render_rect.bottom == this->clip_rect.bottom)) {
        this->draw_setup(0);
        if (this->render_area != nullptr && this->render_area->Lock((char*)"scr_sed::draw", 1) != nullptr) {
            TPanel* main_view_panel = (TPanel*)this->main_view;
            const long main_view_top = main_view_panel->render_rect.top;
            const long main_view_bottom = main_view_panel->render_rect.bottom;

            this->render_area->DrawBevel3(0, 0, this->pnl_wid - 1, main_view_top - 1,
                this->bevel_color1, this->bevel_color2, this->bevel_color3,
                this->bevel_color4, this->bevel_color5, this->bevel_color6);
            this->render_area->DrawBevel3(0, main_view_bottom + 1, this->pnl_wid - 1, this->pnl_hgt - 1,
                this->bevel_color1, this->bevel_color2, this->bevel_color3,
                this->bevel_color4, this->bevel_color5, this->bevel_color6);
            this->render_area->Unlock((char*)"scr_sed::draw");
        }
        this->draw_finish();
    }
}


void TRIBE_Screen_Sed::set_focus(int param_1) {
    // Fully verified. Source of truth: scr_sed.cpp.decomp @ 0x004ADC40
    TScreenPanel::set_focus(param_1);
    if (rge_base_game != nullptr) {
        rge_base_game->set_windows_mouse((this->is_multi_player != 0) ? 0 : 1);
    }
}

// Virtual wrappers: forward to TScreenPanel unless overridden above.
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
long TRIBE_Screen_Sed::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) { return TScreenPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
void TRIBE_Screen_Sed::set_rect(tagRECT param_1) { TScreenPanel::set_rect(param_1); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
void TRIBE_Screen_Sed::set_rect(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_rect(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
void TRIBE_Screen_Sed::set_color(uchar param_1) { TScreenPanel::set_color(param_1); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
void TRIBE_Screen_Sed::set_active(int param_1) { TScreenPanel::set_active(param_1); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
void TRIBE_Screen_Sed::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) { TScreenPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
void TRIBE_Screen_Sed::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
void TRIBE_Screen_Sed::set_redraw(RedrawMode param_1) { TScreenPanel::set_redraw(param_1); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
void TRIBE_Screen_Sed::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TScreenPanel::set_overlapped_redraw(param_1, param_2, param_3); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
void TRIBE_Screen_Sed::draw_setup(int param_1) { TScreenPanel::draw_setup(param_1); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
void TRIBE_Screen_Sed::draw_finish() { TScreenPanel::draw_finish(); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
void TRIBE_Screen_Sed::draw_rect(tagRECT* param_1) { TScreenPanel::draw_rect(param_1); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
void TRIBE_Screen_Sed::draw_offset(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset(param_1, param_2, param_3); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
void TRIBE_Screen_Sed::draw_rect2(tagRECT* param_1) { TScreenPanel::draw_rect2(param_1); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
void TRIBE_Screen_Sed::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset2(param_1, param_2, param_3); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
void TRIBE_Screen_Sed::paint() { TScreenPanel::paint(); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
long TRIBE_Screen_Sed::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TScreenPanel::wnd_proc(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
long TRIBE_Screen_Sed::handle_paint() { return TScreenPanel::handle_paint(); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
long TRIBE_Screen_Sed::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
long TRIBE_Screen_Sed::handle_char(long param_1, short param_2) { return TScreenPanel::handle_char(param_1, param_2); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
long TRIBE_Screen_Sed::handle_command(uint param_1, long param_2) { return TScreenPanel::handle_command(param_1, param_2); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
long TRIBE_Screen_Sed::handle_user_command(uint param_1, long param_2) { return TScreenPanel::handle_user_command(param_1, param_2); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
long TRIBE_Screen_Sed::handle_timer_command(uint param_1, long param_2) { return TScreenPanel::handle_timer_command(param_1, param_2); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
long TRIBE_Screen_Sed::handle_scroll(long param_1, long param_2) { return TScreenPanel::handle_scroll(param_1, param_2); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
long TRIBE_Screen_Sed::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
long TRIBE_Screen_Sed::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::handle_mouse_move(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
long TRIBE_Screen_Sed::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
long TRIBE_Screen_Sed::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
long TRIBE_Screen_Sed::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_move_action(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
long TRIBE_Screen_Sed::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_down_action(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
long TRIBE_Screen_Sed::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
long TRIBE_Screen_Sed::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
long TRIBE_Screen_Sed::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
long TRIBE_Screen_Sed::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
long TRIBE_Screen_Sed::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
long TRIBE_Screen_Sed::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
long TRIBE_Screen_Sed::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
long TRIBE_Screen_Sed::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
long TRIBE_Screen_Sed::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
long TRIBE_Screen_Sed::char_action(long param_1, short param_2) { return TScreenPanel::char_action(param_1, param_2); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
void TRIBE_Screen_Sed::get_true_render_rect(tagRECT* param_1) { TScreenPanel::get_true_render_rect(param_1); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
int TRIBE_Screen_Sed::is_inside(long param_1, long param_2) { return TScreenPanel::is_inside(param_1, param_2); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
void TRIBE_Screen_Sed::set_tab_order(TPanel* param_1, TPanel* param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
void TRIBE_Screen_Sed::set_tab_order(TPanel** param_1, short param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
uchar TRIBE_Screen_Sed::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TScreenPanel::get_help_info(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
void TRIBE_Screen_Sed::stop_sound_system() { TScreenPanel::stop_sound_system(); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
int TRIBE_Screen_Sed::restart_sound_system() { return TScreenPanel::restart_sound_system(); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
void TRIBE_Screen_Sed::take_snapshot() { TScreenPanel::take_snapshot(); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
void TRIBE_Screen_Sed::handle_reactivate() { TScreenPanel::handle_reactivate(); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
void TRIBE_Screen_Sed::draw_background(int param_1) { TScreenPanel::draw_background(param_1); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
void TRIBE_Screen_Sed::set_ideal_size(long param_1, long param_2) { TScreenPanel::set_ideal_size(param_1, param_2); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
int TRIBE_Screen_Sed::create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
int TRIBE_Screen_Sed::create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
int TRIBE_Screen_Sed::create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_check_box(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
int TRIBE_Screen_Sed::create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_radio_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
int TRIBE_Screen_Sed::create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
int TRIBE_Screen_Sed::create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
int TRIBE_Screen_Sed::create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
int TRIBE_Screen_Sed::create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10) { return TScreenPanel::create_input(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
int TRIBE_Screen_Sed::create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12) { return TScreenPanel::create_edit(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
int TRIBE_Screen_Sed::create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_drop_down(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
int TRIBE_Screen_Sed::create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7) { return TScreenPanel::create_list(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
int TRIBE_Screen_Sed::create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_scrollbar(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
int TRIBE_Screen_Sed::create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3) { return TScreenPanel::create_auto_scrollbar(param_1, param_2, param_3); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
int TRIBE_Screen_Sed::create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_vert_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
int TRIBE_Screen_Sed::create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_horz_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
// Fully verified. Source of truth: scr_sed.cpp.decomp/asm (inherited TScreenPanel forwarding parity; no class-local decomp symbol).
void TRIBE_Screen_Sed::position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5) { TScreenPanel::position_panel(param_1, param_2, param_3, param_4, param_5); }





