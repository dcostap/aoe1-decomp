// Authentic complete owner wrapper for C:\\msdev\\work\\age1_x1\\scr_sed.cpp.
// Owner includes follow the PDB source-line and address order.  The nearby
// vector-deleting destructor at 004A8750 is compiler-generated and has no
// standalone source owner.  Accepted-drift owners remain in their reviewed
// source bank; the action scratch owner is observed, not reopened here.

// The first source owners retain standalone declarations for their original
// exact builds.  The TU context joins those bodies without changing their
// source order.  Do not add helper code, dummy functions, or manual vtables.

#define SCR_SED_TU_CONTEXT 1
#include "../include/scr_sed_context.h"

// The short names are period-local names from the small wrapper donors.  The
// shared context carries the canonical panel virtual names and world cleanup
// slot, so these aliases preserve the same call slots without fake methods.
#define v5 set_active
#define v46 del_game_info

// The destructor donor uses offset labels from its standalone layout.  These
// aliases name the same reviewed fields in scr_sed_context.h; they add no
// storage and keep the wrapper include-only.
#define p500 menu_button
#define p504 help_button
#define arrA map_type_button
#define arrB map_type_text
#define p520 map_type_label
#define p524 default_terrain_label
#define p528 default_terrain_drop
#define p52C map_size_label
#define p530 map_size_drop
#define p534 map_style_label
#define p538 map_style_drop
#define p53C random_seed_label
#define p540 random_seed_input
#define p544 random_seed_used_label
#define p548 random_seed_used_text
#define p54C generate_map_button
#define p550 map_generating_text
#define p554 brush_size_label
#define arrC brush_size_button
#define arrC2 brush_size_button_label
#define p580 paint_type_label
#define arrD paint_type_button
#define arrD2 paint_type_button_label
#define p59C paint_terrain_label
#define p5A0 paint_terrain_list
#define p5A4 paint_terrain_scrollbar
#define p5A8 paint_elevation_list
#define p5AC paint_elevation_scrollbar
#define p5B0 player_label
#define p5B4 player_list
#define p5B8 player_number_list
#define p5BC player_advance_civilization_drop
#define arrE player_inven_label
#define arrE2 player_inven_input
#define arrF player_setting_label
#define p5F4 player_starting_age_label
#define arrF2 player_setting_drop
#define p600 BuildList
#define p604 CityLayout
#define p608 AiRules
#define p60C player_build_text
#define p610 player_city_text
#define p614 AiRules_text
#define p618 unit_player_list
#define arrG unit_mode_select
#define arrG2 unit_mode_select_label
#define p63C unit_list
#define p640 unit_scrollbar
#define arrH victory_and_or
#define p688 victory_condition_label
#define p68C victory_amount_label
#define p690 victory_long_label
#define arrH2 victory_text_and_or
#define p69C victory_label_conquest
#define p6A0 victory_label_explore
#define p6A4 victory_label_explore_percent
#define p6A8 victory_label_ruins
#define p6AC victory_label_artifacts
#define p6B0 victory_label_discoveries
#define p6B4 victory_label_gold
#define p6B8 victory_condition_explore
#define p6BC victory_condition_ruins
#define p6C0 victory_condition_artifacts
#define p6C4 victory_condition_discoveries
#define p6C8 victory_condition_gold
#define arrI victory_cond_type_label
#define arrI2 victory_cond_type
#define p6F4 victory_score_label
#define p6F8 victory_score
#define p6FC victory_time_label
#define p700 victory_time
#define p734 victory_drop_down
#define p738 victory_object_list
#define p73C victory_player_list
#define p740 victory_enemy_player_list
#define p744 victory_attribute_list
#define p748 victory_ages_list
#define p74C victory_tech_list
#define p750 victory_button_set_object
#define p754 victory_button_set_destination
#define p758 victory_button_go_to_dest
#define p75C victory_condition_text
#define p760 victory_condition_type
#define p764 victory_amount_text
#define p768 victory_which_enemy_text
#define p76C victory_amount_input
#define p770 victory_object_scrollbar
#define p774 message_input
#define arrJ message_button
#define arrJ2 message_button_label
#define arrK cinematic_label
#define arrK2 cinematic_input
#define arrL options_label
#define arrL2 options_button
#define p7CC options_player_list
#define p7D0 options_disable_tech_text
#define arrM options_disable_button
#define arrM2 options_disable_text
#define diplA Diplomacy_player_text
#define dipplayer Diplomacy_player_list
#define p898 Diplomacy_status_label[0]
#define p89C Diplomacy_status_label[1]
#define p8A0 Diplomacy_status_label[2]
#define p8A4 Diplomacy_status_label[3]
#define diplB Diplomacy_friend_box_flat
#define diplAllied Diplomacy_AlliedVictory

#include "matching/004A81E0_TRIBE_Screen_Sed.cpp"
#include "matching/004A8770_set_panel_info.cpp"
#include "matching/004A87D0_set_string.cpp"
#include "matching/004A87F0_create_button.cpp"
#include "matching/004A8840_create_button.cpp"
#include "matching/004A8910_create_text.cpp"
#include "matching/004A8960_create_text.cpp"
#include "matching/004A89B0_create_input.cpp"
#include "matching/004A8A00_create_edit.cpp"
#include "accepted_drift/004A8A60_create_drop_down.cpp"
#include "matching/004A9320_SetupListOfTerrain.cpp"
#include "matching/004A93C0_create_list.cpp"
#include "matching/004A94A0_TRIBE_Screen_Sed.cpp"
#include "accepted_drift/004A9CC0_set_scenario_mode.cpp"
#include "accepted_drift/004AA730_set_paint_object_mode.cpp"
#include "matching/004AA7A0_set_map_type.cpp"
#include "matching/004AA8F0_set_mp_victory_type.cpp"
#include "matching/004AAA90_set_brush_size.cpp"
#include "matching/004AAB60_set_paint_type.cpp"
#include "matching/004AAD50_set_terrain.cpp"
#include "matching/004AADF0_set_elevation.cpp"
#include "matching/004AAE20_set_player.cpp"
#include "matching/004AB2B0_set_player_active.cpp"
#include "matching/004AB2D0_TRIBE_Screen_Sed_unit_list_compare.cpp"
#include "matching/004AB300_set_unit_player.cpp"
#include "accepted_drift/004AB670_set_unit.cpp"
#include "matching/004AB6E0_set_message_type.cpp"
#include "matching/004AB710_handle_size.cpp"
#include "matching/004AB740_handle_idle.cpp"
#include "matching/004AB7D0_key_down_action.cpp"
#include "scratch/004ABCD0_action.cpp"
#include "matching/004AD0F0_draw.cpp"
#include "matching/004AD240_command_cancel.cpp"
#include "matching/004AD270_command_menu.cpp"
#include "matching/004AD300_command_new.cpp"
#include "matching/004AD340_command_new_map.cpp"
#include "matching/004AD590_command_open.cpp"
#include "accepted_drift/004AD630_command_outline.cpp"
#include "matching/004AD680_command_player.cpp"
#include "matching/004AD6A0_command_quit.cpp"
#include "matching/004AD700_command_save.cpp"
#include "matching/004AD960_command_save_as.cpp"
#include "matching/004ADA70_scenario_get_default_name.cpp"
#include "matching/004ADAF0_command_quick_save.cpp"
#include "matching/004ADB10_scenario_save_defaulted.cpp"
#include "matching/004ADC30_need_to_save.cpp"
#include "matching/004ADC40_set_focus.cpp"

#undef v46
#undef v5
#undef SCR_SED_TU_CONTEXT
