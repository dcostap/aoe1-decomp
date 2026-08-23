// VA: 004AF320 TRIBE_Screen_Sed::init_module_variables (925 B)
// PDB source: scr_sed2.cpp:1145-1350
// Baseline: typed field ownership and the loop/pointer shapes shown by the
// scr_sed2.cpp source-line bands and original assembly.
// Attempt log:
// - Replaced the incomplete raw-offset placeholder with the complete
//   period-plausible member reconstruction.  The paired arrays are modeled
//   as their actual adjacent fields so the negative-index loop stores retain
//   their canonical ownership.
// - Replaced the decompiler-shaped negative-index paired-array loops with
//   natural indexed loops over each adjacent field pair; this restored the
//   925-byte size and left a localized reset-order/register hunk.
// - A natural fixed-count loop over the five button_bldg_pics entries lets
//   VC5 share its zero value with the following rep stosd and exactly restores
//   the remaining 50-byte scheduling hunk.  The loop is retained as the
//   plausible source form rather than five codegen-only assignments.
// - Promoted unit_list_info to its proven nested List_Info pointer type; code
//   generation was unchanged.

#include "../../include/scr_sed2_context.h"

void TRIBE_Screen_Sed::init_module_variables()
{
    TButtonPanel** ppTVar3;
    int iVar6;

    this->background_pic = (TShape*)0;
    this->main_view = (TRIBE_Main_View*)0;
    this->map_view = (RGE_Diamond_Map_View*)0;
    this->message_panel = (TMessagePanel*)0;
    this->bottom_panel = (TPanel*)0;
    this->set_player_first_flag = 0;
    ppTVar3 = this->scenario_mode_button;
    for (iVar6 = 10; iVar6 != 0; iVar6 = iVar6 + -1) {
        *ppTVar3 = (TButtonPanel*)0;
        ppTVar3 = ppTVar3 + 1;
    }
    this->menu_button = (TButtonPanel*)0;
    this->help_button = (TButtonPanel*)0;
    this->map_type_label = (TTextPanel*)0;
    for (iVar6 = 0; iVar6 < 3; ++iVar6) {
        this->map_type_button[iVar6] = (TButtonPanel*)0;
        this->map_type_text[iVar6] = (TTextPanel*)0;
    }
    this->default_terrain_drop = (TDropDownPanel*)0;
    this->default_terrain_label = (TTextPanel*)0;
    this->map_size_drop = (TDropDownPanel*)0;
    this->map_size_label = (TTextPanel*)0;
    this->map_style_drop = (TDropDownPanel*)0;
    this->map_style_label = (TTextPanel*)0;
    this->map_generating_text = (TTextPanel*)0;
    this->random_seed_label = (TTextPanel*)0;
    this->random_seed_input = (TEditPanel*)0;
    this->random_seed_used_label = (TTextPanel*)0;
    this->random_seed_used_text = (TTextPanel*)0;
    this->generate_map_button = (TButtonPanel*)0;
    this->brush_size_label = (TTextPanel*)0;
    this->paint_type_label = (TTextPanel*)0;
    this->paint_terrain_label = (TTextPanel*)0;
    for (iVar6 = 0; iVar6 < 5; ++iVar6) {
        this->brush_size_button[iVar6] = (TButtonPanel*)0;
        this->brush_size_button_label[iVar6] = (TTextPanel*)0;
    }
    for (iVar6 = 0; iVar6 < 3; ++iVar6) {
        this->paint_type_button[iVar6] = (TButtonPanel*)0;
        this->paint_type_button_label[iVar6] = (TTextPanel*)0;
    }
    this->paint_terrain_list = (TListPanel*)0;
    this->paint_terrain_scrollbar = (TScrollBarPanel*)0;
    this->paint_elevation_list = (TListPanel*)0;
    this->paint_elevation_scrollbar = (TScrollBarPanel*)0;
    this->player_advance_civilization_drop = (TDropDownPanel*)0;
    this->player_label = (TTextPanel*)0;
    this->player_starting_age_label = (TTextPanel*)0;
    this->player_build_text = (TTextPanel*)0;
    this->player_city_text = (TTextPanel*)0;
    this->player_list = (TDropDownPanel*)0;
    this->player_number_list = (TDropDownPanel*)0;
    for (iVar6 = 0; iVar6 < 5; ++iVar6) {
        this->player_inven_label[iVar6] = (TTextPanel*)0;
        this->player_inven_input[iVar6] = (TEditPanel*)0;
    }
    for (iVar6 = 0; iVar6 < 2; ++iVar6) {
        this->player_setting_label[iVar6] = (TTextPanel*)0;
        this->player_setting_drop[iVar6] = (TDropDownPanel*)0;
    }
    this->BuildList = (TDropDownPanel*)0;
    this->CityLayout = (TDropDownPanel*)0;
    this->AiRules = (TDropDownPanel*)0;
    this->unit_player_list = (TDropDownPanel*)0;
    for (iVar6 = 0; iVar6 < 4; ++iVar6) {
        this->unit_mode_select[iVar6] = (TButtonPanel*)0;
        this->unit_mode_select_label[iVar6] = (TTextPanel*)0;
    }
    this->unit_list = (TListPanel*)0;
    this->unit_scrollbar = (TScrollBarPanel*)0;
    this->unit_list_info = (List_Info*)0;
    this->button_unit_pics = (TShape*)0;
    for (iVar6 = 0; iVar6 < 5; ++iVar6)
        this->button_bldg_pics[iVar6] = (TShape*)0;
    this->object_panel = (TRIBE_Scenario_Editor_Panel_Object*)0;
    this->unit_list_size = 0;
    ppTVar3 = this->victory_cond_on;
    for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {
        *ppTVar3 = (TButtonPanel*)0;
        ppTVar3 = ppTVar3 + 1;
    }
    for (iVar6 = 0; iVar6 < 2; ++iVar6) {
        this->victory_and_or[iVar6] = (TButtonPanel*)0;
        this->victory_text_and_or[iVar6] = (TTextPanel*)0;
    }
    this->victory_amount_label = (TTextPanel*)0;
    this->victory_long_label = (TTextPanel*)0;
    this->victory_condition_label = (TTextPanel*)0;
    this->victory_label_conquest = (TTextPanel*)0;
    this->victory_label_explore = (TTextPanel*)0;
    this->victory_label_explore_percent = (TTextPanel*)0;
    this->victory_label_ruins = (TTextPanel*)0;
    this->victory_label_artifacts = (TTextPanel*)0;
    this->victory_label_discoveries = (TTextPanel*)0;
    this->victory_label_gold = (TTextPanel*)0;
    this->victory_condition_explore = (TEditPanel*)0;
    this->victory_condition_ruins = (TEditPanel*)0;
    this->victory_condition_artifacts = (TEditPanel*)0;
    this->victory_condition_discoveries = (TEditPanel*)0;
    this->victory_condition_gold = (TEditPanel*)0;
    for (iVar6 = 0; iVar6 < 5; ++iVar6) {
        this->victory_cond_type_label[iVar6] = (TTextPanel*)0;
        this->victory_cond_type[iVar6] = (TButtonPanel*)0;
    }
    this->victory_score_label = (TTextPanel*)0;
    this->victory_score = (TDropDownPanel*)0;
    this->victory_time_label = (TTextPanel*)0;
    this->victory_time = (TDropDownPanel*)0;
    ppTVar3 = this->victory_button;
    for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {
        *ppTVar3 = (TButtonPanel*)0;
        ppTVar3 = ppTVar3 + 1;
    }
    this->victory_drop_down = (TDropDownPanel*)0;
    this->victory_object_list = (TDropDownPanel*)0;
    this->victory_player_list = (TDropDownPanel*)0;
    this->victory_ages_list = (TDropDownPanel*)0;
    this->victory_tech_list = (TDropDownPanel*)0;
    this->victory_button_set_object = (TButtonPanel*)0;
    this->victory_button_set_destination = (TButtonPanel*)0;
    this->victory_button_go_to_dest = (TButtonPanel*)0;
    this->victory_condition_text = (TTextPanel*)0;
    this->victory_condition_type = (TTextPanel*)0;
    this->victory_amount_text = (TTextPanel*)0;
    this->victory_amount_input = (TEditPanel*)0;
    this->victory_enemy_player_list = (TDropDownPanel*)0;
    this->victory_attribute_list = (TDropDownPanel*)0;
    this->victory_which_enemy_text = (TTextPanel*)0;
    this->victory_object_scrollbar = (TScrollBarPanel*)0;
    for (iVar6 = 0; iVar6 < 5; ++iVar6) {
        this->message_button[iVar6] = (TButtonPanel*)0;
        this->message_button_label[iVar6] = (TTextPanel*)0;
    }
    this->message_input = (TEditPanel*)0;
    for (iVar6 = 0; iVar6 < 4; ++iVar6) {
        this->cinematic_label[iVar6] = (TTextPanel*)0;
        this->cinematic_input[iVar6] = (TDropDownPanel*)0;
    }
    for (iVar6 = 0; iVar6 < 1; ++iVar6) {
        this->options_label[iVar6] = (TTextPanel*)0;
        this->options_button[iVar6] = (TButtonPanel*)0;
    }
    this->options_player_list = (TDropDownPanel*)0;
    this->options_disable_tech_text = (TTextPanel*)0;
    for (iVar6 = 0; iVar6 < 0x10; ++iVar6) {
        this->options_disable_button[iVar6] = (TButtonPanel*)0;
        this->options_disable_text[iVar6] = (TTextPanel*)0;
    }
    this->Diplomacy_player_list = (TDropDownPanel*)0;
    for (iVar6 = 0; iVar6 < 8; ++iVar6) {
        this->Diplomacy_player_text[iVar6] = (TTextPanel*)0;
        this->Diplomacy_friend_box[iVar6][0] = (TButtonPanel*)0;
        this->Diplomacy_friend_box[iVar6][1] = (TButtonPanel*)0;
        this->Diplomacy_friend_box[iVar6][2] = (TButtonPanel*)0;
        this->Diplomacy_AlliedVictory[iVar6] = (TButtonPanel*)0;
    }
    this->Diplomacy_status_label[0] = (TTextPanel*)0;
    this->Diplomacy_status_label[1] = (TTextPanel*)0;
    this->Diplomacy_status_label[2] = (TTextPanel*)0;
    this->Diplomacy_status_label[3] = (TTextPanel*)0;
    this->world = (TRIBE_World*)0;
}
