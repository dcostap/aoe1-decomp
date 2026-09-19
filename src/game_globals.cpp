#include "../include/game_globals.h"
#include "../include/dsutil.h"
#include "../include/Res_file.h"
#include "../include/visible.h"
#include "../include/Panel.h"
#include "../include/view.h"
#include "../include/Dib.h"
#include "../include/tribegam.h"

struct PLAYER_SCORE;
class TMousePointer;
class DClipInfo_List;

// Original static initialization: 00463BA0; object storage: 0062E870.
TPanelSystem panel_system;

// Original runtime data; addresses and initial bytes are recorded in executable_runtime_abi.md.
FILE* draw_log = 0;
char draw_log_name[260] = {0};
int do_draw_log = 0;
int safe_draw_log = 0;
int do_fps_log = 0;
FILE* fps_log = 0;
int debugActions = 0;
long fog_next_shape = 0;
int shape_version_110 = 0x30312E31;
int version_marker = 0x30302E31;
int startLoggingAI = 0;
float g_discovery_artifact_scan_lower_adjustment = 1.0f;
unsigned int DAT_0086b240 = 0;
unsigned int DAT_0086b244 = 0;
int player_dropped[9] = {0};
long DAT_0062D208[9] = {0};
unsigned long DAT_0062D230 = 0;
float DAT_0086b290 = 0.0f;
unsigned int DAT_0086b294 = 0;
int DAT_0086b298 = 0;
int DAT_0086b29c = 0;
int DAT_0086b2a0 = 0;
unsigned char DAT_0086b2a4 = 0;
tagPALETTEENTRY DAT_0086b2a8 = {0};
float DAT_0086b2ac = 0.0f;
tagPALETTEENTRY DAT_0086b2b0[256] = {0};
tagPALETTEENTRY DAT_0086b6b0[256] = {0};
TDrawArea* DAT_0086bab0 = 0;
int do_run_log = 0;
int do_debug_timeGetTime = 0;
int debug_timeGetTime_interval = 5;
int chatCheatCodes = 1;
int logUpdateChanges = 0;
int useInfluencePlacement = 0;
int all_grassland_on = 0;
int numberPathingIterations = 2500;
int useNewPathing = 0;
int pathingCapValue = 2;
int force_cd = 0;
int Sys_DDLOG_Enable = 0;
int Sys_DDLOG_ErrorOn = 0;
int DDlogAutoFlush = 1;
int debug_log_lock = 0;
int do_debug_random = 0;
int logDebugID = -1;
int speed_val1 = 0;
int speed_val2 = 0;
int log_output = 0;
int DDSys_CanColorFill = 1;
unsigned char do_color_log = 0;
int wrote_debug_random_log = 0;
int debug_random_index = 0;
int snapshot_number = 1;
int out_of_sync = 0;
int out_of_sync2 = 0;
unsigned char sound_file_first = 0;
unsigned char shape_file_first = 0;
GUID gAppGUID = {0};
GUID gServGUID = {0};
IDirectPlay3* glpSERV = 0;
unsigned long start_mem_total = 0;
unsigned long start_mem_high = 0;
unsigned long cur_mem_total = 0;
unsigned long cur_mem_high = 0;
char debug_random_log[5000][100] = {0};
int AniPalSets = 0;
FILE* DDlogf = 0;
int FullPalSets = 0;
int MapPathsDisplay = 0;
TMousePointer* MouseSystem = 0;
int PalSetRes = 0;
DClipInfo_List* SDI_List = 0;
long SDI_Object_ID = 0;
int confirmed_close = 0;
int displayPathObjectID = 83;
int displayPathingFlags = 0;
int imc_retval = 0;
RGE_Pick_Obj_Info Picked_Objects[64] = {0};
unsigned char ObstructionValueShift[4] = {0, 2, 4, 6};
unsigned char ObstructionValueMask[4] = {0xFC, 0xF3, 0xCF, 0x3F};
int DiagionalDistance[256] = {0};
int SDI_Capture_Info = 0;
int SDI_Draw_Level = 0;
int SDI_Draw_Line = 0;
void* StringTableX = 0;
int View_Grid_Mode = 0;
FILE* debugOut = 0;
int disable_terrain_sounds = 0;
int memory_dump_sequence = 0;
unsigned char production_queues_is_use = 1;
int quick_start_game_mode = 0;
int run_log_created = 0;
FILE* run_log_file = 0;
int show_timing_max = 0;
int video_codec_available = 0;
int view_debug_Objects = 0;
int view_debug_ObstructionMap = 0;
int view_debug_palette = 0;
int view_debug_redraw_all = 0;
int view_debug_spans = 0;
char DAT_0062E670[0x200] = {0};
class TCommunications_Sessions;
TCommunications_Sessions* Sess = 0;
int rge_write_error = 0;
int ENABLE_COMPRESSION = 1;
float DAT_0086bc08 = 0.0f;
unsigned int DAT_0086bc8c = 0;
unsigned int DAT_0086be00 = 0;
int start_paused = 0;
int multi_updates = 1;
int Shape_Loads = 0;
int ASM_Fast_Count = 0;
long tiles_drawn = 0;
long frame_count = 0;
int Clip_draw = 0;
int Clip_remove = 0;
int Tribe1btnMouseRightClickTableSize = 40;
int Tribe1btnMouseLeftClickTableSize = 40;
int Tribe2btnMouseRightClickTableSize = 40;
int Tribe2btnMouseLeftClickTableSize = 40;

res_file_type_info res_extension_table[] = {
    {"voc", 0x766F6320},
    {"wav", RES_TYPE_WAVE},
    {"xmi", 0x6D696469},
    {"lbm", 0x696C626D},
    {"pcx", 0x70637820},
    {"gif", 0x67696620},
    {"shp", RES_TYPE_SHAPE},
    {"slp", RES_TYPE_SLP},
    {"cel", 0x63656C6C},
    {"flc", 0x63656C6C},
    {"fli", 0x63656C6C},
    {"ccs", 0x63637372},
    {"fnt", 0x726F6E74},
    {"rgb", 0x72676270},
    {"xxx", 0}
};

const PLAYER_SCORE* DAT_0086babc = 0;
const PLAYER_SCORE* DAT_0086bac0 = 0;

FILE* actionFile = 0;
int taskedThisUpdate = 0;
int searchedThisUpdate = 0;
int numberVisibleObjects = 0;
int numberDifferentPlayerObjectsVisible = 0;
FILE* commonHistoryLogFile = 0;
int specificAIPlayerToLog = -1;
short visible_combats = 0;
FILE* logStatusFile = 0;
unsigned long lastStatusLogTime = 0;

RGE_Static_Object** VIS_UNIT_objectsValue = 0;
VISIBLE_UNIT_REC* VisibleUnitList[5] = {0};
int VisibleUnitList_Size[5] = {0};
Visible_Unit_Manager* VisibleUnitManager = 0;
unsigned long* unified_map_offsets[1024] = {0};
int Map_Update_Suppresion = 0;
int VCALL_LOG_HEAD = -1;
int VCALL_LOG_TAIL = -1;
VC_LOG VCALL_LOG[1024] = {0};


namespace tplayer_globals {
unsigned int selectedObjectId = 0;
unsigned int selectedObjectCount = 0;
unsigned int buildListCategoryCount1 = 0;
unsigned int buildListCategoryCount2 = 0;
unsigned int buildListCategoryCount3 = 0;
unsigned int buildListCategoryCount4 = 0;
unsigned int buildListCategoryCount5 = 0;
unsigned int buildListCategoryCount6 = 0;
unsigned int buildListCategoryCount7 = 0;
unsigned int attackTimingCategoryCount = 0;
unsigned int fastAttackListCount = 0;
unsigned int defaultAttackListCount = 0;
int selectedBuildListCount = 0;
unsigned int aggressiveBuildListCount = 0;
}

float g_attack_radius_distance_adjustment = -0.300000012f;
float g_gather_positive_amount_threshold = 0.0f;
double g_gather_dropoff_distance_threshold = 1.0;
float g_missile_half_time_factor = 0.5f;
double g_missile_positive_value_threshold = 0.0;
float g_missile_target_speed_normalization_limit = 1.0f;
float g_missile_minimum_speed = 0.0f;
float g_transport_lower_coordinate_adjustment = 1.0f;
float g_transport_upper_coordinate_adjustment = -1.0f;
float g_unit_ai_distance_priority_scale = 100.0f;
float g_unit_ai_reaction_distance_scale = 0.00999999978f;
float g_unit_ai_zero_float = 0.0f;
float g_unit_ai_map_boundary_adjustment = 1.0f;
float g_unit_ai_weapon_range_adjustment = -1.0f;
float g_unit_ai_damage_capability_scale = 50.0f;
float g_unit_ai_multi_attacker_distance_scale = 0.5f;
float g_unit_ai_resource_los_adjustment = -5.0f;
float g_unit_ai_half_coordinate_adjustment = -0.5f;
float g_unit_ai_desired_distance_adjustment = -2.0f;
double g_unit_ai_coordinate_lower_bound = -1.0;
double g_unit_ai_coordinate_upper_bound = 1.0;
double g_sprite_minimum_animation_interval = 0.001;
float g_sprite_random_frame_scale = 3.05185094e-05f;
const unsigned char u_0123456789ABCDEF_0056f230[2] = { 0x30, 0x00 };
float g_combat_attack_modifier_one = 1.0f;
double g_combat_area_zero_range = 0.0;
float g_combat_area_zero_float = 0.0f;
float g_combat_missile_range_adjustment = -6.0f;
double g_command_group_extent_limit = 8.0;
double g_command_zero_coordinate = 0.0;
float g_command_map_boundary_adjustment = 1.0f;
float g_diplomacy_attribute_percent_scale = 100.0f;
float g_doppleganger_save_version_7_06 = 7.05999994f;
float g_master_action_save_version_6_92 = 6.92000008f;
float g_master_combat_save_version_7_01 = 7.01000023f;
float g_damage_ability_initial_total = 0.0f;
double g_damage_ability_positive_difference_threshold = 0.0;
double g_damage_ability_minimum_total_threshold = 1.0;
float g_damage_ability_minimum_total = 1.0f;
float g_static_object_save_version_7_04 = 7.03999996f;
float g_static_object_save_version_7_12 = 7.11999989f;
float g_static_object_zero_float = 0.0f;
float g_static_object_coordinate_epsilon = 0.00100000005f;
double g_static_object_zero = 0.0;
float g_static_object_bounds_min_adjustment = 3.0f;
float g_static_object_bounds_max_adjustment = -3.0f;
float g_map_save_version_7_0 = 7.0f;
float g_map_zero_interval = 0.0f;
double g_tile_map_half = 0.5;
double g_tile_map_negative_half = -0.5;
double g_tile_map_one = 1.0;
float g_map_time_scale = 0.00100000005f;
float g_missile_zero_float = 0.0f;
float g_missile_bounds_min_adjustment = 3.0f;
float g_missile_bounds_max_adjustment = -3.0f;
float g_missile_vertical_adjustment = -0.100000001f;
double g_move_full_circle_double = 6.2831853000000004;
float g_move_zero_angle = 0.0f;
float g_move_negative_two_pi = -6.28318548f;
float g_move_two_pi = 6.28318548f;
float g_move_save_version_1_3 = 1.29999995f;
float g_move_save_version_7_22 = 7.21999979f;
float g_move_save_version_7_23 = 7.23000002f;
float g_move_positive_one = 1.0f;
float g_move_negative_one = -1.0f;
double g_move_pi_double = 3.1415926500000002;
double g_move_negative_pi_double = -3.1415926500000002;
float g_move_inverse_full_circle = 0.159154937f;
float g_move_half_float = 0.5f;
float g_move_negative_half_float = -0.5f;
float g_move_time_scale = 0.00100000005f;
float g_move_quarter_pi = 0.785398185f;
double g_move_half_double = 0.5;
double g_move_zero_double = 0.0;
float g_move_waypoint_distance_threshold = 4.0f;
float g_move_radius_distance_adjustment = -0.300000012f;
double g_move_turn_delta_upper = 0.80000000000000004;
double g_move_turn_delta_lower = -0.80000000000000004;
float g_move_speed_offset_base = 0.100000001f;
double g_move_turn_delta_upper_wide = 0.90000000000000002;
double g_move_turn_delta_lower_wide = -0.90000000000000002;
float g_move_waypoint_distance_threshold_close = 0.25f;
double g_move_speed_offset_lower = -0.02;
double g_move_speed_offset_upper = 0.02;
float g_move_facet_angle = 0.392699093f;
double g_move_angle_tolerance = 0.10000000000000001;
float g_music_fade_volume_scale = -10000.0f;
float g_path_zero_length = 0.0f;
float g_path_diagonal_scale = 1.41419995f;
float g_path_diagonal_sign = -16.0f;
float g_path_diagonal_base = 0.5f;
float g_path_min_action_range = 1.0f;
float g_path_goal_tolerance_scale = 16.0f;
float g_path_zero_speed = 0.0f;
float g_path_coordinate_scale = 4.0f;
float g_path_tile_center_adjustment = -0.5f;
float g_path_bounds_offset = -100.0f;
float g_path_rounding_adjustment = -4.99999987e-05f;
float g_path_bounds_offset_large = -100.000053f;
float g_path_coordinate_scale_negative = -4.0f;
double g_path_distance_scale = 16.0;
double g_path_zero_terrain_value = 0.0;
float g_player_save_version_4_01 = 4.01000023f;
float g_player_save_version_7_09 = 7.09000015f;
float g_player_zero_attribute_amount = 0.0f;
float g_rmm_path_terrain_cost_adjustment = -1.36000001f;
float g_rmm_path_vertical_adjustment_positive = 0.409999996f;
float g_rmm_path_vertical_adjustment_negative = -0.409999996f;
float g_rmm_path_vertical_adjustment_small_positive = 0.400000006f;
float g_rmm_path_vertical_adjustment_small_negative = -0.400000006f;
double g_rmm_land_octagon_scale = 0.66666599999999998;
double g_rmm_terrain_land_area_factor = 0.80000000000000004;
float g_rmm_terrain_tile_ratio_scale = 4.99999987e-05f;
double g_rmm_terrain_tile_ratio_threshold = 1.0;
double g_rmm_object_land_area_factor = 0.69999999999999996;
double g_rmm_object_perimeter_factor = 1.25;
float g_rmm_elevation_random_offset = -0.00183111057f;
float g_rmm_elevation_random_base = 70.0f;
float g_rmm_elevation_random_scale = 0.00999999978f;
float g_rmm_elevation_map_type_factor = 5.0f;
float g_scroll_time_scale = 0.00100000005f;
float g_fade_progress_scale = 100.0f;
float g_no_area_effect_range = 0.0f;
float g_spawn_panel_empty_attribute_amount = 0.0f;
double g_sprite_zero_delta_time = 0.0;
float g_damage_health_percent_scale = 100.0f;
float g_damage_sprite_random_scale = 6.10370189e-05f;
float g_object_bounds_min_adjustment = 3.0f;
float g_object_bounds_max_adjustment = -3.0f;
double g_build_tile_coordinate_epsilon = 0.001;
float g_building_zero_hp = 0.0f;
double g_build_cancel_refund_factor = 0.5;
double g_building_one_threshold = 1.0;
float g_building_minimum_damage = 1.0f;
double g_building_small_damage_threshold = 0.10000000000000001;
float g_building_small_damage_amount = 0.100000001f;
float g_combat_one_float = 1.0f;
float g_combat_negative_one = -1.0f;
double g_combat_one_threshold = 1.0;
float g_combat_zero_float = 0.0f;
float g_combat_tile_center_adjustment = -0.5f;
float g_angle_negative_two_pi = -6.28318548f;
double g_combat_zero_range = 0.0;
double g_artifact_timer_threshold = 0.0;
float g_artifact_scan_lower_adjustment = 1.0f;
float g_artifact_scan_upper_adjustment = -1.0f;
float g_conversion_random_scale = 3.05185094e-05f;
float g_conversion_special_player_factor = 4.0f;
float g_conversion_special_group_factor = 8.0f;
double g_discovery_artifact_timer_threshold = 0.0;
float g_discovery_artifact_scan_upper_adjustment = -1.0f;
float g_heal_attribute_threshold = 0.100000001f;
double g_heal_distance_threshold = 0.5;
float g_hunt_empty_amount = 0.0f;
double g_hunt_drop_distance_threshold = 1.0;
float g_make_obj_radius_adjustment = -0.00999999978f;
float g_make_obj_random_scale = 3.05185094e-05f;
float g_make_obj_progress_percent = 100.0f;
float g_repair_distance_offset = 2.0f;
double g_repair_distance_threshold = 0.40000000000000002;
float g_trade_positive_amount_threshold = 0.0f;
float g_trade_distance_modifier_factor = 0.000251256279f;
float g_trade_distance_modifier_scale = 0.699999988f;
float g_trade_minimum_transfer_modifier = 0.349999994f;
double g_trade_modifier_threshold = 0.34999999999999998;
float g_trade_max_transfer_amount = 75.0f;
float g_information_ai_save_version_1_6 = 1.60000002f;
float g_information_ai_save_version_2_5 = 2.5f;
float g_information_ai_save_version_6_8 = 6.80000019f;
float g_information_ai_save_version_6_91 = 6.90999985f;
float g_information_ai_save_version_6_99 = 6.98999977f;
float g_main_decision_save_version_1_2 = 1.20000005f;
float g_main_decision_save_version_7_08 = 7.07999992f;
float g_strategy_ai_save_version_1_5 = 1.5f;
float g_tactical_group_save_version_6_94 = 6.94000006f;
float g_tactical_group_save_version_7_13 = 7.13000011f;
float g_tactical_group_save_version_7_14 = 7.13999987f;
float g_tactical_group_save_version_7_20 = 7.19999981f;
float g_tactical_ai_minimum_distance = 0.0f;
float g_tactical_ai_distance_offset = 1.0f;
float g_tactical_ai_retreat_los_factor = 0.333333343f;
float g_tactical_ai_defender_los_factor = 0.5f;
double g_trade_zero_value = 0.0;
float g_ai_evasive_distance_scale = 3.0f;
float g_soldier_evasive_distance_threshold = 1.0f;
float g_soldier_evasive_coordinate_offset = 2.0f;
float g_ranged_ai_zero_distance = 0.0f;
float g_fishing_ship_evasive_distance_scale = 7.0f;
float g_soldier_random_evasive_offset = 4.0f;
float g_soldier_evasive_coordinate_threshold = 10.0f;
float g_soldier_evasive_fallback_adjustment = -2.0f;
float g_task_invalid_coordinate = -1.0f;
float g_task_nonpositive_amount_threshold = 0.0f;
const char s_NOMUTE_00576551[7] = { 0x4E, 0x4F, 0x4D, 0x55, 0x54, 0x45, 0x00 };
double g_tech_zero_attribute = 0.0;
float g_master_combat_pierce_armor_save_version = 7.01000023f;
float g_player_selection_zero_attribute = 0.0f;
const float g_tactical_panel_rounding_offset = -0.5f;
float g_trade_display_distance_factor = 0.000251256279f;
float g_trade_display_distance_scale = 0.699999988f;
double g_trade_display_modifier_threshold = 0.34999999999999998;
float g_trade_display_minimum_modifier = 0.349999994f;
float g_trade_display_distance_scale_percent = 20.0f;
float g_trade_display_max_transfer_amount = 75.0f;
float g_trade_display_range_threshold = 0.99000001f;
double g_trade_display_zero_amount = 0.0;
float g_building_progress_redraw_threshold = 99.0f;
float g_scenario_file_version_1_13 = 1.13f;
float g_scenario_file_version_1_02 = 1.02f;
float g_scenario_file_version_1_03 = 1.03f;
float g_scenario_file_version_1_04 = 1.04f;
float g_scenario_file_version_1_12 = 1.12f;
float g_scenario_file_version_1_05 = 1.05f;
double g_scenario_victory_zero_coordinate = 0.0;
float g_view_tile_fraction_scale = 0.5f;
float g_view_pick_coordinate_offset = -0.5f;
float g_view_scroll_fraction_scale = 0.0625f;
float g_visible_resource_save_version = 7.11000013f;
double g_visible_resource_diagonal_factor = 1.3999999999999999;
double g_visible_resource_diagonal_adjustment = -0.60999999999999999;
float g_main_view_initial_scroll_distance = 1.0f;
float g_main_view_scroll_fraction_threshold = 0.5f;
float g_main_view_zero_scroll_distance = 0.0f;
float g_world_difficulty_save_version = 7.15999985f;
float g_world_milliseconds_to_seconds = 0.00100000005f;
double g_zone_passability_zero_threshold = 0.0;
const char s_t_00577b28[26] = { 0x49, 0x73, 0x50, 0x72, 0x6F, 0x63, 0x65, 0x73, 0x73, 0x6F, 0x72, 0x46, 0x65, 0x61, 0x74, 0x75, 0x72, 0x65, 0x50, 0x72, 0x65, 0x73, 0x65, 0x6E, 0x74, 0x00 };
const char s_t_00577b40[2] = { 0x74, 0x00 };
const char s_0_00577b58[6] = { 0x65, 0x2B, 0x30, 0x30, 0x30, 0x00 };
const char s_0_00577b5c[2] = { 0x30, 0x00 };
const char s_nMonTueWedThuFriSat_00577bda[20] = { 0x6E, 0x4D, 0x6F, 0x6E, 0x54, 0x75, 0x65, 0x57, 0x65, 0x64, 0x54, 0x68, 0x75, 0x46, 0x72, 0x69, 0x53, 0x61, 0x74, 0x00 };
const char s_nFebMarAprMayJunJulAugSepOctNovD_00577bf2[35] = { 0x6E, 0x46, 0x65, 0x62, 0x4D, 0x61, 0x72, 0x41, 0x70, 0x72, 0x4D, 0x61, 0x79, 0x4A, 0x75, 0x6E, 0x4A, 0x75, 0x6C, 0x41, 0x75, 0x67, 0x53, 0x65, 0x70, 0x4F, 0x63, 0x74, 0x4E, 0x6F, 0x76, 0x44, 0x65, 0x63, 0x00 };
const char s_AN_00578010[7] = { 0x31, 0x23, 0x51, 0x4E, 0x41, 0x4E, 0x00 };
const char s_AN_00578014[3] = { 0x41, 0x4E, 0x00 };
const char s_F_00578018[6] = { 0x31, 0x23, 0x49, 0x4E, 0x46, 0x00 };
const char s_F_0057801c[2] = { 0x46, 0x00 };
const char s_D_00578020[6] = { 0x31, 0x23, 0x49, 0x4E, 0x44, 0x00 };
const char s_D_00578024[2] = { 0x44, 0x00 };
const char s_AN_00578028[7] = { 0x31, 0x23, 0x53, 0x4E, 0x41, 0x4E, 0x00 };
const char s_AN_0057802c[3] = { 0x41, 0x4E, 0x00 };
unsigned int DAT_0057a808 = 0x19930520u;
unsigned char DAT_0057f075 = 0x6E;
unsigned char DAT_0057f09d = 0x61;
unsigned char DAT_0057f0b5 = 0x74;
const char s_oveNoSearch_0057f0dd[12] = { 0x6F, 0x76, 0x65, 0x4E, 0x6F, 0x53, 0x65, 0x61, 0x72, 0x63, 0x68, 0x00 };
const char s_nvalidated_0057f0ed[11] = { 0x6E, 0x76, 0x61, 0x6C, 0x69, 0x64, 0x61, 0x74, 0x65, 0x64, 0x00 };
unsigned char DAT_0057f101 = 0x6F;
unsigned char DAT_0057f149 = 0x61;
unsigned char DAT_0057f299 = 0x55;
unsigned char DAT_0057f351 = 0x4F;
const char s_engeful_0057f405[8] = { 0x65, 0x6E, 0x67, 0x65, 0x66, 0x75, 0x6C, 0x00 };
const char s_assive_0057f411[7] = { 0x61, 0x73, 0x73, 0x69, 0x76, 0x65, 0x00 };
const char s_riendly_0057f419[8] = { 0x72, 0x69, 0x65, 0x6E, 0x64, 0x6C, 0x79, 0x00 };
const char s_efensive_0057f425[9] = { 0x65, 0x66, 0x65, 0x6E, 0x73, 0x69, 0x76, 0x65, 0x00 };
const char s_ompassionate_0057f431[13] = { 0x6F, 0x6D, 0x70, 0x61, 0x73, 0x73, 0x69, 0x6F, 0x6E, 0x61, 0x74, 0x65, 0x00 };
const char s_ggressive_0057f441[10] = { 0x67, 0x67, 0x72, 0x65, 0x73, 0x73, 0x69, 0x76, 0x65, 0x00 };
unsigned char DAT_0057f509 = 0x65;
const char s_etAliveCount_0057f50b[13] = { 0x65, 0x74, 0x41, 0x6C, 0x69, 0x76, 0x65, 0x43, 0x6F, 0x75, 0x6E, 0x74, 0x00 };
unsigned char DAT_0057f519 = 0x65;
const char s_etHitPoints_0057f51b[12] = { 0x65, 0x74, 0x48, 0x69, 0x74, 0x50, 0x6F, 0x69, 0x6E, 0x74, 0x73, 0x00 };
unsigned char DAT_0057f529 = 0x65;
unsigned char DAT_0057f531 = 0x65;
unsigned char DAT_0057f539 = 0x74;
const char s_ackSavedTarget_0057f53b[15] = { 0x61, 0x63, 0x6B, 0x53, 0x61, 0x76, 0x65, 0x64, 0x54, 0x61, 0x72, 0x67, 0x65, 0x74, 0x00 };
unsigned char DAT_0057f555 = 0x69;
unsigned char DAT_0057f55d = 0x6D;
const char s_ediate_0057f55f[7] = { 0x65, 0x64, 0x69, 0x61, 0x74, 0x65, 0x00 };
unsigned char DAT_0057f569 = 0x65;
const char s_lOfGroup_0057f56b[9] = { 0x6C, 0x4F, 0x66, 0x47, 0x72, 0x6F, 0x75, 0x70, 0x00 };
unsigned char DAT_0057f575 = 0x65;
const char s_thOfGroup_0057f577[10] = { 0x74, 0x68, 0x4F, 0x66, 0x47, 0x72, 0x6F, 0x75, 0x70, 0x00 };
unsigned char DAT_0057f585 = 0x65;
const char s_el2EnemySighted_0057f587[16] = { 0x65, 0x6C, 0x32, 0x45, 0x6E, 0x65, 0x6D, 0x79, 0x53, 0x69, 0x67, 0x68, 0x74, 0x65, 0x64, 0x00 };
unsigned char DAT_0057f599 = 0x65;
const char s_el1EnemySighted_0057f59b[16] = { 0x65, 0x6C, 0x31, 0x45, 0x6E, 0x65, 0x6D, 0x79, 0x53, 0x69, 0x67, 0x68, 0x74, 0x65, 0x64, 0x00 };
unsigned char DAT_0057f5ad = 0x61;
const char s_ageToAnyGroup_0057f5af[14] = { 0x61, 0x67, 0x65, 0x54, 0x6F, 0x41, 0x6E, 0x79, 0x47, 0x72, 0x6F, 0x75, 0x70, 0x00 };
unsigned char DAT_0057f5c1 = 0x61;
const char s_ageToGroup_0057f5c3[11] = { 0x61, 0x67, 0x65, 0x54, 0x6F, 0x47, 0x72, 0x6F, 0x75, 0x70, 0x00 };
unsigned char DAT_0057f5d1 = 0x65;
const char s_lthLost_0057f5d3[8] = { 0x6C, 0x74, 0x68, 0x4C, 0x6F, 0x73, 0x74, 0x00 };
unsigned char DAT_0057f5dd = 0x65;
unsigned char DAT_0057f5e5 = 0x65;
unsigned char DAT_0057f5ed = 0x6C;
unsigned char DAT_0057f5f5 = 0x6E;
unsigned char DAT_0057f605 = 0x6E;
unsigned char DAT_0057f60d = 0x54;
const char s_igger_0057f60f[6] = { 0x69, 0x67, 0x67, 0x65, 0x72, 0x00 };
unsigned char DAT_0057f62d = 0x72;
unsigned char DAT_0057f649 = 0x68;
unsigned char DAT_0057f665 = 0x72;
unsigned char DAT_0057f66d = 0x75;
const char s_berGroups_0057f66f[10] = { 0x62, 0x65, 0x72, 0x47, 0x72, 0x6F, 0x75, 0x70, 0x73, 0x00 };
unsigned char DAT_0057f67d = 0x61;
const char s_getType_0057f67f[8] = { 0x67, 0x65, 0x74, 0x54, 0x79, 0x70, 0x65, 0x00 };
unsigned char DAT_0057f689 = 0x61;
const char s_getChar_0057f68b[8] = { 0x67, 0x65, 0x74, 0x43, 0x68, 0x61, 0x72, 0x00 };
unsigned char DAT_0057f695 = 0x6E;
const char s_elligence_0057f697[10] = { 0x65, 0x6C, 0x6C, 0x69, 0x67, 0x65, 0x6E, 0x63, 0x65, 0x00 };
unsigned char DAT_0057f6a5 = 0x65;
const char s_thPercentage_0057f6a7[13] = { 0x74, 0x68, 0x50, 0x65, 0x72, 0x63, 0x65, 0x6E, 0x74, 0x61, 0x67, 0x65, 0x00 };
unsigned char DAT_0057f6b5 = 0x69;
const char s_stGroup_0057f6b7[8] = { 0x73, 0x74, 0x47, 0x72, 0x6F, 0x75, 0x70, 0x00 };
unsigned char DAT_0057f6c1 = 0x61;
unsigned char DAT_0057f6c9 = 0x76;
const char s_rflow_0057f6cb[6] = { 0x72, 0x66, 0x6C, 0x6F, 0x77, 0x00 };
unsigned char DAT_0057f6d5 = 0x6F;
unsigned char DAT_0057f6dd = 0x61;
const char s_Units_0057f6df[6] = { 0x55, 0x6E, 0x69, 0x74, 0x73, 0x00 };
unsigned char DAT_0057f6f1 = 0x69;
const char s_Units_0057f6f3[6] = { 0x55, 0x6E, 0x69, 0x74, 0x73, 0x00 };
unsigned char DAT_0057f705 = 0x6C;
const char s_yType_0057f707[6] = { 0x79, 0x54, 0x79, 0x70, 0x65, 0x00 };
unsigned char DAT_0057f711 = 0x6C;
unsigned char DAT_0057f71d = 0x6E;
unsigned char DAT_0057f721 = 0x61;
unsigned char DAT_0057f729 = 0x6C;
unsigned char DAT_0057f731 = 0x6F;
unsigned char DAT_0057f739 = 0x74;
const char s_tionary_0057f73b[8] = { 0x74, 0x69, 0x6F, 0x6E, 0x61, 0x72, 0x79, 0x00 };
unsigned char DAT_00584351 = 0x65;
const char s_ignDialog_00584353[10] = { 0x69, 0x67, 0x6E, 0x44, 0x69, 0x61, 0x6C, 0x6F, 0x67, 0x00 };
unsigned char DAT_00584371 = 0x65;
const char s_tartDialog_00584373[11] = { 0x74, 0x61, 0x72, 0x74, 0x44, 0x69, 0x61, 0x6C, 0x6F, 0x67, 0x00 };
unsigned char DAT_00584395 = 0x75;
const char s_tGameDialog_00584397[12] = { 0x74, 0x47, 0x61, 0x6D, 0x65, 0x44, 0x69, 0x61, 0x6C, 0x6F, 0x67, 0x00 };
unsigned char DAT_005843a5 = 0x75;
const char s_tAndLoadDialog_005843a7[15] = { 0x74, 0x41, 0x6E, 0x64, 0x4C, 0x6F, 0x61, 0x64, 0x44, 0x69, 0x61, 0x6C, 0x6F, 0x67, 0x00 };
unsigned char DAT_005843e5 = 0x65;
const char s_Dialog_005843e7[8] = { 0x20, 0x44, 0x69, 0x61, 0x6C, 0x6F, 0x67, 0x00 };
unsigned char DAT_005843f1 = 0x70;
const char s_n_Dialog_005843f3[9] = { 0x6E, 0x20, 0x44, 0x69, 0x61, 0x6C, 0x6F, 0x67, 0x00 };
unsigned char DAT_00584612 = 0x00;
const char s_cr10_00586089[5] = { 0x63, 0x72, 0x31, 0x30, 0x00 };
unsigned char DAT_005860d9 = 0x6F;
const char s_d_Dialog_005860db[9] = { 0x64, 0x20, 0x44, 0x69, 0x61, 0x6C, 0x6F, 0x67, 0x00 };
unsigned char DAT_005860e5 = 0x61;
const char s_cel_Dialog_005860e7[11] = { 0x63, 0x65, 0x6C, 0x20, 0x44, 0x69, 0x61, 0x6C, 0x6F, 0x67, 0x00 };
const char s_gA640_00586305[6] = { 0x67, 0x41, 0x36, 0x34, 0x30, 0x00 };
unsigned char DAT_005863b5 = 0x6C;
const char s_seProgramDialog_005863b7[16] = { 0x73, 0x65, 0x50, 0x72, 0x6F, 0x67, 0x72, 0x61, 0x6D, 0x44, 0x69, 0x61, 0x6C, 0x6F, 0x67, 0x00 };
unsigned char DAT_00586589 = 0x65;
const char s_hInfo_0058658b[6] = { 0x68, 0x49, 0x6E, 0x66, 0x6F, 0x00 };
unsigned char DAT_0058659d = 0x65;
const char s_turesInfo_0058659f[10] = { 0x74, 0x75, 0x72, 0x65, 0x73, 0x49, 0x6E, 0x66, 0x6F, 0x00 };
unsigned char DAT_005865ad = 0x6E;
const char s_tInfo3_005865af[7] = { 0x74, 0x49, 0x6E, 0x66, 0x6F, 0x33, 0x00 };
unsigned char DAT_005865c5 = 0x6E;
const char s_tInfo2_005865c7[7] = { 0x74, 0x49, 0x6E, 0x66, 0x6F, 0x32, 0x00 };
unsigned char DAT_005865dd = 0x6E;
const char s_tInfo1_005865df[7] = { 0x74, 0x49, 0x6E, 0x66, 0x6F, 0x31, 0x00 };
unsigned char DAT_005865f5 = 0x63;
const char s_narioEditorInfo_005865f7[16] = { 0x6E, 0x61, 0x72, 0x69, 0x6F, 0x45, 0x64, 0x69, 0x74, 0x6F, 0x72, 0x49, 0x6E, 0x66, 0x6F, 0x00 };
unsigned char DAT_00586609 = 0x6F;
const char s_o2Screen_0058660b[9] = { 0x6F, 0x32, 0x53, 0x63, 0x72, 0x65, 0x65, 0x6E, 0x00 };
unsigned char DAT_00586621 = 0x6F;
const char s_o1Screen_00586623[9] = { 0x6F, 0x31, 0x53, 0x63, 0x72, 0x65, 0x65, 0x6E, 0x00 };
unsigned char DAT_0058662d = 0x65;
const char s_thMatch_0058662f[8] = { 0x74, 0x68, 0x4D, 0x61, 0x74, 0x63, 0x68, 0x00 };
unsigned char DAT_0058664d = 0x61;
const char s_domMap_0058664f[7] = { 0x64, 0x6F, 0x6D, 0x4D, 0x61, 0x70, 0x00 };
unsigned char DAT_005866a5 = 0x6F;
const char s_firm_Dialog_005866a7[12] = { 0x66, 0x69, 0x72, 0x6D, 0x20, 0x44, 0x69, 0x61, 0x6C, 0x6F, 0x67, 0x00 };
unsigned char DAT_00586739 = 0x74;
const char s_rt_Zone_0058673b[8] = { 0x72, 0x74, 0x20, 0x5A, 0x6F, 0x6E, 0x65, 0x00 };
unsigned char DAT_00586745 = 0x69;
const char s_t_Error_00586747[8] = { 0x74, 0x20, 0x45, 0x72, 0x72, 0x6F, 0x72, 0x00 };
unsigned char DAT_00586751 = 0x61;
const char s_e_Error_00586753[8] = { 0x65, 0x20, 0x45, 0x72, 0x72, 0x6F, 0x72, 0x00 };
unsigned char DAT_005867e9 = 0x69;
const char s_k_Dialog_005867eb[9] = { 0x6B, 0x20, 0x44, 0x69, 0x61, 0x6C, 0x6F, 0x67, 0x00 };
unsigned char DAT_00586809 = 0x61;
const char s_e_Settings_Screen_0058680b[18] = { 0x65, 0x20, 0x53, 0x65, 0x74, 0x74, 0x69, 0x6E, 0x67, 0x73, 0x20, 0x53, 0x63, 0x72, 0x65, 0x65, 0x6E, 0x00 };
unsigned char DAT_00586c65 = 0x65;
const char s_Name_Dialog_00586c67[13] = { 0x20, 0x4E, 0x61, 0x6D, 0x65, 0x20, 0x44, 0x69, 0x61, 0x6C, 0x6F, 0x67, 0x00 };
unsigned char DAT_00586cf9 = 0x65;
const char s_SaveDialog_00586cfb[11] = { 0x53, 0x61, 0x76, 0x65, 0x44, 0x69, 0x61, 0x6C, 0x6F, 0x67, 0x00 };
unsigned char DAT_00586d09 = 0x70;
const char s_nSaveDialog_00586d0b[12] = { 0x6E, 0x53, 0x61, 0x76, 0x65, 0x44, 0x69, 0x61, 0x6C, 0x6F, 0x67, 0x00 };
unsigned char DAT_00586d19 = 0x75;
const char s_tSaveDialog_00586d1b[12] = { 0x74, 0x53, 0x61, 0x76, 0x65, 0x44, 0x69, 0x61, 0x6C, 0x6F, 0x67, 0x00 };
TRIBE_Cliff_Higher_Check_Record TRIBE_Cliff_Higher_Check_Table[25] = {
    { 3.1400001f, 4.71000004f, -1.0f, -1.0f, 1.5f, -1.0f, 1.0f, 1.0f },
    { 1.58000004f, 4.69999981f, -1.0f, -1.0f, 1.5f, -1.5f, 1.5f, 1.5f },
    { 1.58000004f, 4.69999981f, -1.0f, -1.0f, 1.5f, -1.5f, 1.5f, 1.5f },
    { 1.57000005f, 3.1400001f, -1.0f, -1.0f, 1.0f, -1.5f, 1.5f, -1.0f },
    { 0.00999999978f, 3.13000011f, -1.0f, -1.0f, -1.5f, -1.5f, 1.5f, -1.5f },
    { 0.00999999978f, 3.13000011f, -1.0f, -1.0f, -1.5f, -1.5f, 1.5f, -1.5f },
    { 0.0f, 1.57000005f, -1.0f, -1.0f, -1.0f, -1.0f, 1.0f, -1.5f },
    { 4.71999979f, 6.28000021f, 0.0f, 1.55999994f, 0.5f, -1.5f, 0.5f, 1.5f },
    { 4.71999979f, 6.28000021f, 0.0f, 1.55999994f, 0.5f, -1.5f, 0.5f, 1.5f },
    { 4.71000004f, 6.28000021f, -1.0f, -1.0f, -1.0f, -1.0f, 1.0f, 1.0f },
    { 3.1500001f, 6.26999998f, -1.0f, -1.0f, -1.5f, -0.5f, 1.5f, -0.5f },
    { 3.1500001f, 6.26999998f, -1.0f, -1.0f, -1.5f, -0.5f, 1.5f, -0.5f },
    { 0.0f, 1.57000005f, -1.0f, -1.0f, 1.0f, -1.5f, 0.0f, 1.5f },
    { 4.71000004f, 6.28000021f, -1.0f, -1.0f, 0.0f, -1.0f, 1.0f, 0.0f },
    { 3.1400001f, 4.71000004f, -1.0f, -1.0f, -1.5f, 0.0f, 1.5f, -1.0f },
    { 1.57000005f, 3.1400001f, -1.0f, -1.0f, -1.5f, -1.5f, 1.5f, 1.5f },
    { 0.00999999978f, 3.13000011f, -1.0f, -1.0f, -1.5f, 0.0f, 1.5f, -1.5f },
    { 0.00999999978f, 3.13000011f, -1.0f, -1.0f, -1.5f, -1.5f, 1.5f, 0.0f },
    { 1.58000004f, 4.69999981f, -1.0f, -1.0f, 0.0f, -1.5f, 1.5f, 1.5f },
    { 1.58000004f, 4.69999981f, -1.0f, -1.0f, 1.5f, -1.5f, 0.0f, 1.5f },
    { 3.1500001f, 6.26999998f, -1.0f, -1.0f, -1.5f, 0.0f, 1.5f, -1.0f },
    { 3.1500001f, 6.26999998f, -1.0f, -1.0f, -1.5f, -1.0f, 1.5f, 0.0f },
    { 4.71999979f, 6.28000021f, 0.0f, 1.55999994f, 0.0f, -1.5f, 1.0f, 1.5f },
    { 4.71999979f, 6.28000021f, 0.0f, 1.55999994f, 1.0f, -1.5f, 0.0f, 1.5f },
    { 1.57000005f, 3.1400001f, -1.0f, -1.0f, -1.5f, -1.5f, 1.5f, 1.5f }
};
unsigned char DAT_00587a55 = 0x65;
unsigned char DAT_00587a5d = 0x61;
unsigned char DAT_00587a65 = 0x69;
unsigned char DAT_00587a6d = 0x72;
unsigned char DAT_00587a75 = 0x61;
unsigned char DAT_00587a7d = 0x61;
unsigned char DAT_0058af79 = 0x61;
const char s_domGameSpecialized_0058af7b[19] = { 0x64, 0x6F, 0x6D, 0x47, 0x61, 0x6D, 0x65, 0x53, 0x70, 0x65, 0x63, 0x69, 0x61, 0x6C, 0x69, 0x7A, 0x65, 0x64, 0x00 };
unsigned char DAT_0058bbdd = 0x74;
unsigned char DAT_0058bfb1 = 0x3F;
unsigned char DAT_0058bfcd = 0x55;
unsigned char DAT_0058bfd5 = 0x45;
const char s_ECTOBJ_0058bfd7[7] = { 0x45, 0x43, 0x54, 0x4F, 0x42, 0x4A, 0x00 };
unsigned char DAT_0058bfe1 = 0x57;
unsigned char DAT_0058bfed = 0x25;
unsigned char DAT_0058c001 = 0x5F;
unsigned char DAT_0058c015 = 0x24;
unsigned char DAT_0058c029 = 0x78;
unsigned char DAT_0058c039 = 0x33;
unsigned char DAT_0058c04d = 0x43;
unsigned char DAT_0058c05d = 0x3E;
unsigned char DAT_0058c07d = 0x5A;
unsigned char DAT_0058c089 = 0x25;
unsigned char DAT_0058c099 = 0x29;
unsigned char DAT_0058c0ad = 0x57;
unsigned char DAT_0058c0b9 = 0x57;
unsigned char DAT_0058c0c5 = 0x57;
unsigned char DAT_0058c0d1 = 0x57;
unsigned char DAT_0058c0dd = 0x57;
unsigned char DAT_0058c0e9 = 0x57;
unsigned char DAT_0058c0f5 = 0x57;
unsigned char DAT_0058c101 = 0x57;
unsigned char DAT_0058c10d = 0x3E;
unsigned char DAT_0058c121 = 0x4C;
unsigned char DAT_0058c12d = 0x63;
unsigned char DAT_0058c13d = 0x5F;
unsigned char DAT_0058c155 = 0x3E;
unsigned char DAT_0058c169 = 0x29;
unsigned char DAT_0058c17d = 0x6A;
unsigned char DAT_0058c1a1 = 0x6D;
unsigned char DAT_0058c1c1 = 0x5F;
unsigned char DAT_0058c1d5 = 0x7B;
unsigned char DAT_0058c1f1 = 0x6D;
unsigned char DAT_0058c209 = 0x3E;
unsigned char DAT_0058c26d = 0x29;
const char s_tandard_0058c335[8] = { 0x74, 0x61, 0x6E, 0x64, 0x61, 0x72, 0x64, 0x00 };
unsigned char DAT_0058c3b5 = 0x61;
unsigned char DAT_0058ef30 = 0x10;
unsigned char DAT_0058ef42 = 0x0F;
unsigned short DAT_0058ef48 = 0x0101;
unsigned char DAT_0058f148 = 0x00;
unsigned char DAT_0058f248 = 0x00;
unsigned char DAT_0058f347 = 0x00;
unsigned char DAT_0058f547 = 0x11;
unsigned char DAT_0058f747 = 0x07;
unsigned char DAT_0058f948 = 0x00;
unsigned char DAT_0058f9c8 = 0x00;
unsigned short DAT_0058fa48 = 0x0000;
unsigned int DAT_0058fb54 = 0x00000000u;
unsigned int DAT_0058fb58 = 0x00000000u;
unsigned int DAT_0058fb5c = 0x00000000u;
unsigned int DAT_0058fbf8 = 0xFFFFFFFFu;
unsigned int DAT_0058fbfc = 0xFFFFFFFFu;
unsigned int DAT_0058fc00 = 0x000000F0u;
unsigned int DAT_0058fc04 = 0x000000F1u;
unsigned int DAT_0058fc08 = 0x00000000u;
unsigned int DAT_00591bf8 = 0x00000000u;
unsigned int DAT_00591c18 = 0x00000001u;
unsigned int DAT_00591c24 = 0x00000002u;
unsigned char DAT_00591da3 = 0x00;
unsigned char DAT_00591ddf = 0x00;
unsigned char DAT_00591de0 = 0x50;
unsigned char DAT_00591de3 = 0x00;
unsigned char DAT_00591e1f = 0x00;
unsigned int DAT_00591e28 = 0xFFFFFFFFu;
unsigned int DAT_00591e2c = 0x00000000u;
unsigned int DAT_00591e30 = 0x00000000u;
unsigned int DAT_00591e38 = 0xFFFFFFFFu;
unsigned int DAT_00591e3c = 0x00000000u;
unsigned int DAT_00591e40 = 0x00000000u;
unsigned int DAT_00591e58 = 0x00000000u;
unsigned char DAT_005920cc = 0x00;
unsigned char DAT_005920db = 0x00;
unsigned char DAT_005922f0 = 0x01;
unsigned int DAT_005922f8 = 0x000003A4u;
unsigned int DAT_0059232c = 0xA3DAA3C1u;
unsigned int DAT_00592330 = 0x00000020u;
unsigned int DAT_00592334 = 0x00000000u;
unsigned char DAT_00592338 = 0x00;
unsigned char DAT_00592339 = 0x00;
unsigned char DAT_0059233a = 0x00;
unsigned int DAT_005923e4 = 0x00000000u;
unsigned int DAT_0059241c = 0x00000000u;
unsigned int DAT_00592424 = 0x0000001Eu;
unsigned int DAT_00592428 = 0x0000003Au;
unsigned int DAT_00592458 = 0x00000014u;
double DAT_00592558 = -0.0;
double DAT_00592568 = -4.9406564584124654e-324;
unsigned int DAT_0059257c = 0x0000000Bu;
unsigned int DAT_00592584 = 0xC000001Du;
unsigned int DAT_00592588 = 0x00000004u;
unsigned int DAT_005925a4 = 0x00000000u;
unsigned int DAT_00592600 = 0x00000002u;
unsigned int DAT_00592610 = 0x00000009u;
unsigned int DAT_00592820 = 0x7525C460u;
unsigned int DAT_00592824 = 0x00000000u;

// Dsutil process globals. The names and types follow the period SDK surface
// and the direct uses in the stream helpers.
unsigned int _uLastPercent = 0;
LPDIRECTSOUNDBUFFER _lpDSBStreamBuffer = 0;
int _bFileOpen = 0;
int _bPlaying = 0;
int _bTimerInstalled = 0;
unsigned int _uTimerID = 0;
HWND _main_wnd = 0;
LPDIRECTSOUNDBUFFER _lpBuffer = 0;
LPDIRECTSOUND _lpDS = 0;
int _ds_ready = 0;
int _stream_paused = 0;
LPWAVEFORMATEX _wiWave = 0;
HMMIO ds_wave_file = 0;
MMCKINFO ds_wave_data_chunk = {0};
MMCKINFO ds_wave_riff_chunk = {0};
LPDIRECTSOUNDBUFFER ds_stream_buffer = 0;
unsigned int ds_buffer_size = 0;
unsigned int ds_chunk_size = 0;
unsigned int ds_write_cursor = 0;
unsigned int ds_last_play_cursor = 0;
unsigned long ds_stream_position = 0;
int ds_stream_stop_requested = 0;
unsigned int ds_stream_loop = 0;
int ds_stream_at_end = 0;
unsigned int ds_silence_chunks = 0;
long ds_last_percent = 0;

void* AppInst = 0;
HMODULE StringTable = 0;
TRegistry* Regs = 0;
TSound_Driver* sound_driver = 0;
TChat* chat = 0;
TCommunications_Handler* comm = 0;
DriveInformation* driveInfo = 0;
HWND AppWnd = 0;
RGE_Base_Game* rge_base_game = 0;
int system_ignore_size_messages = 0;
int basegame_is_active = 0;
int MouseCursorInChildContol = 0;
HWND save_active_wnd = 0;
int do_restore_palette = 0;
unsigned long restore_palette_timer = 0;
int restore_mouse_after_paint = 0;
extern "C" HCURSOR last_mouse_cursor = 0;
extern "C" GUID TRIBE_GUID = {
    0xF2E846A8, 0xEBE2, 0x11D1,
    { 0x83, 0x9B, 0x00, 0x60, 0x97, 0x07, 0xF5, 0x08 }
};
extern "C" GUID ZONE_GUID = {
    0xF2E846AA, 0xEBE2, 0x11D1,
    { 0x83, 0x9B, 0x00, 0x60, 0x97, 0x07, 0xF5, 0x08 }
};
unsigned int basegame_shift_key_down = 0;
unsigned int basegame_key_message = 0;
unsigned int basegame_key_parameter = 0;
unsigned int basegame_alt_key_down = 0;
unsigned int basegame_control_key_down = 0;
unsigned int basegame_palette_restore_time = 0;
unsigned int basegame_palette_restore_pending = 0;
TDebuggingLog* L = 0;
// Shared DirectPlay identity.
IDirectPlay3* direct_play_interface = 0;
unsigned long local_player_dpid = 0;
unsigned char comm_rate_initialized = 0;
unsigned long comm_last_rate_update = 0;
unsigned long comm_last_rx_bytes = 0;
unsigned long comm_last_tx_bytes = 0;
unsigned long comm_last_dump_time = 0;
unsigned long comm_last_sent_time = 0;
char* comm_receive_message = 0;
unsigned long comm_receive_base = 0;
unsigned long comm_drop_count = 0;
unsigned long comm_resent_bytes = 0;
unsigned long comm_resend_last_time = 0;
unsigned long comm_highest_acknowledged_turn = 0;
// C++ globals named by the original resend option references.
int resend_adj1 = 0;
int resend_adj2 = 0;
int comm_resend_min_delay = 0;
int comm_resend_latency_base = 0;
float comm_resend_rate_limit = 0.0f;
unsigned char comm_messages_initialized = 0;
COMM_DEBUG_PING comm_debug_ping = {0};
COMM_DEBUG_PING comm_ping_packet = {0};
unsigned char guid_format_positions[20] = {
    3, 2, 1, 0, '-', 5, 4, '-', 7, 6, '-', 8, 9, '-',
    10, 11, 12, 13, 14, 15
};
unsigned short guid_hex_digits[16] = {
    '0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
};
char comm_enum_buffer[0x100] = {0};
char comm_info_buffers[0x700] = {0};
char g_status_buffer[0x20] = {0};
char ready_player_buffer[64] = {0};
char ready_player_template[64] = "Ready=                         ";
char com_hand_source_path[] = "C:\\msdev\\work\\age1_x1\\Com_hand.cpp";
unsigned int DAT_0086bc88 = 0;
unsigned int DAT_0088c000 = 0x00000000u;
unsigned int DAT_0088c004 = 0x00000000u;
unsigned int DAT_0088c008 = 0x00000000u;
unsigned int DAT_0088c00c = 0x00000000u;
unsigned int DAT_0088c010 = 0x00000000u;
unsigned int DAT_0088c014 = 0x00000000u;
unsigned int DAT_0088c018 = 0x00000000u;
unsigned int DAT_0088c01c = 0x00000000u;
unsigned int DAT_0088c020 = 0x00000000u;
unsigned int DAT_0088c024 = 0x00000000u;
unsigned int DAT_0088c028 = 0x00000000u;
unsigned int DAT_0088c02c = 0x00000000u;
unsigned int DAT_0088c038 = 0x00000000u;
unsigned int DAT_0088c03c = 0x00000000u;
unsigned int DAT_0088c040 = 0x00000000u;
unsigned int DAT_0088c044 = 0x00000000u;
unsigned int DAT_0088c054 = 0x00000000u;
unsigned int DAT_0088c058 = 0x00000000u;
unsigned int DAT_0088c080 = 0x00000000u;
unsigned int DAT_0088c084 = 0x00000000u;
unsigned int DAT_0088c088 = 0x00000000u;
unsigned int DAT_0088c08c = 0x00000000u;

long world_update_counter = 0;
int computerPlayerSetup[13] = {0};
FILE* DVlogf = 0;
int debug_random_on = 0;
int global_save_debug_random_on1 = 0;
int global_save_debug_random_on2 = 0;
int global_save_debug_random_on3 = 0;
int global_save_debug_random_on4 = 0;
int allowAIToCheat = 1;
int debug_timeGetTime_on = 0;
int debug_timeGetTime_cnt = 0;
int debug_timeGetTime_time = 0;
int all_cp = 0;
int logStatusOn = 0;
int do_fixed_update = 0;
// Original initial data: 0057F9E4 and 0058EBCC.
long fixed_update_time = 100;
float save_game_version = 7.23f;
int allow_user_commands = 1;
unsigned char die_die_die = 0;
int useComputerPlayers = 1;

// Original string storage. All current references have exact function evidence.
// See decomp_notes/executable_build_evidence/string_definitions.json.
extern const char s_taunt_mute_command[] = "!MUTE";
extern const char s_taunt_nomute_command[] = "!NOMUTE";
char STR_STAT_OBJ[] = "C:\\msdev\\work\\age1_x1\\stat_obj.cpp";
char _s_Release[] = "Release";
char close_confirmation_text[] = "CloseProgramDialog";
char pnl_inp_draw[] = "pnl_inp::draw";
char s_0[] = "0";
char s_1200[] = "1200";
char s_1500[] = "1500";
char s_1800[] = "1800";
char s_2100[] = "2100";
char s_2400[] = "2400";
char s_2700[] = "2700";
char s_3000[] = "3000";
char s_300[] = "300";
char s_400[] = "400";
char s_500[] = "500";
char s_600[] = "600";
char s_700[] = "700";
char s_800[] = "800";
char s_900[] = "900";
char s_ALLOWCTRLU[] = "ALLOWCTRLU";
char s_Annoy[] = "Annoy";
char s_Any[] = "Any";
char s_Attack[] = "Attack";
char s_AttackSavedTarget[] = "AttackSavedTarget";
char s_Campaign_Editor_Screen[] = "Campaign Editor Screen";
char s_DamageToAnyGroup[] = "DamageToAnyGroup";
char s_DamageToGroup[] = "DamageToGroup";
char s_Death[] = "Death";
char s_DeathOfGroup[] = "DeathOfGroup";
char s_Fast[] = "Fast";
char s_Flank[] = "Flank";
char s_Gather[] = "Gather";
char s_Heal[] = "Heal";
char s_HealOfGroup[] = "HealOfGroup";
char s_HealthLost[] = "HealthLost";
char s_Immediate[] = "Immediate";
char s_Invalid[] = "Invalid";
char s_Level1EnemySighted[] = "Level1EnemySighted";
char s_Level2EnemySighted[] = "Level2EnemySighted";
char s_Main_Menu[] = "Main Menu";
char s_Move[] = "Move";
char s_Moving[] = "Moving";
char s_Recon[] = "Recon";
char s_ResetAliveCount[] = "ResetAliveCount";
char s_ResetHitPoints[] = "ResetHitPoints";
extern const char s_Resource_AI[] = "Resource AI";
char s_Retreat[] = "Retreat";
char s_Scenario_Editor_Menu[] = "Scenario Editor Menu";
char s_Scenario_Menu_Dialog[] = "Scenario Menu Dialog";
char s_Slow[] = "Slow";
char s_Stationary[] = "Stationary";
char s_Time[] = "Time";
char s_Wait[] = "Wait";
extern const char s_Writing_out_memory_info[] = "Writing out memory info (%d)...";
char s_angle_d[] = "<%d>";
char s_angle_d_star[] = "<%d*>";
extern const char s_fmt_ld[] = "%ld";
char s_force_ctrl_u[] = "*** !!! %%% USER PRESSED CTRL-U TO FORCE OUT OF SYNC %%% !!! ***";
extern const char s_memory_filename[] = "c:\\mem%d.txt";
char s_percent_d[] = "%d";
char s_percent_d_star[] = "%d*";
char s_pnl_lst__draw[] = "pnl_lst::draw";
char s_pnl_lst__draw_highlight_bar[] = "pnl_lst::draw_highlight_bar";
char s_pnl_txt__get_text_rect[] = "pnl_txt::get_text_rect";
char s_scr4[] = "scr4";
char s_scr_cred_draw_005862e0[] = "scr_cred::draw";
char s_setResource_n_v[] = "setResource: n=%d, v=%d.";
char s_setResource_r_v[] = "  setResource: r[%d]=%d.";
char s_space[] = " ";
char s_tpnl_inv_draw[] = "tpnl_inv::draw";
char s_tpnl_tml_draw_axis[] = "tpnl_tml::draw_axis";
char s_tpnl_txl_draw[] = "tpnl_txl::draw";
extern const char str_taiuaimd_path[] = "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp";
extern const char str_aiuaimod_path[] = "C:\\msdev\\work\\age1_x1\\aiuaimod.cpp";
extern const char str_fmt_stopObject[] = "#%d call stopObject %s %d\n";

// Original AI play-file tokens and formats used by 00410220.
char s_NULL[] = "NULL";
char s_NONE[] = "NONE";
char s_592A40[] = "";
char s_format_percent_s[] = "%s";
char s_mode_r[] = "r";
char s_format_percent_s_space[] = "%s ";
char s_format_comment[] = " %c%c";
char s_Play[] = "Play";
char s_PlayType[] = "PlayType";
char s_MinUnits[] = "MinUnits";
char s_MaxUnits[] = "MaxUnits";
char s_Power[] = "Power";
char s_Overflow[] = "Overflow";
char s_Balance[] = "Balance";
char s_FirstGroup[] = "FirstGroup";
char s_DeathPercentage[] = "DeathPercentage";
char s_Intelligence[] = "Intelligence";
char s_TargetChar[] = "TargetChar";
char s_TargetType[] = "TargetType";
char s_NumberGroups[] = "NumberGroups";
char s_Group[] = "Group";
char s_Phase[] = "Phase";
char s_Trigger[] = "Trigger";
char s_RTrigger[] = "RTrigger";
char s_EndPlay[] = "EndPlay";
char s_format_skip_string_int[] = "%*s %d ";
char s_format_skip_string_string[] = "%*s %s ";
char s_format_group_range[] = "%*s %d %s %d - %d ";
char s_format_command[] = "%*s %d %s %d %d %d ";
char s_format_trigger[] = "%*s %d %s %d %d ";
char s_format_play_variant[] = "%sF%d";
char s_Save_Game_Screen[] = "Save Game Screen";
char s_C__msdev_work_age1_x1_color_cpp[] = "C:\\msdev\\work\\age1_x1\\color.cpp";
char s_pnl_btn_draw2[] = "pnl_btn::draw2";
char s_pnl_btn_draw[] = "pnl_btn::draw";
char s_pnl_txt__word_wrap_append[] = "pnl_txt::word_wrap_append";
char s_pnl_txt__draw[] = "pnl_txt::draw";
char s_rmm_obj_cpp[] = "C:\\msdev\\work\\age1_x1\\rmm_obj.cpp";
char s_PAUSE[] = "PAUSE";
char s_map_bmp[] = "map.bmp";
char s_bordline[] = "bordline";
char s_btnbldg_d_shp[] = "btnbldg%d.shp";
char s_btncmd_shp[] = "btncmd.shp";
char s_btntech_shp[] = "btntech.shp";
char s_btnunit_shp[] = "btnunit.shp";
char s_scr6[] = "scr6";
char s_Game_Screen[] = "Game Screen";
char s_Config_Dialog[] = "Config Dialog";
char s_Help_Dialog[] = "Help Dialog";
char s_Send_Quick_Message_Dialog[] = "Send Quick Message Dialog";
char s_scr_game_cpp[] = "C:\\msdev\\work\\age1_x1\\scr_game.cpp";
char s_lost_wav[] = "lost.wav";
char s_won_wav[] = "won.wav";
char s_NewSaveDialog[] = "NewSaveDialog";
char s_OpenSaveDialog[] = "OpenSaveDialog";
char s_QuitSaveDialog[] = "QuitSaveDialog";
char s_C__msdev_work_age1_x1_scr_sed_cp[] = "C:\\msdev\\work\\age1_x1\\scr_sed.cpp";
char s_Scenario_Editor_Open[] = "Scenario Editor Open";
char s_Scenario_Editor_Screen[] = "Scenario Editor Screen";
char s_OKDialog[] = "OKDialog";
char s_view__view_function_terrain[] = "view::view_function_terrain";
extern const char s_C__msdev_work_age1_x1_view_cpp[] = "C:\\msdev\\work\\age1_x1\\view.cpp";

PAL_TABLE System_color_Table[21] = {
    {0, 0, 0, 0, 0},
    {1, 128, 0, 0, 0},
    {2, 0, 128, 0, 0},
    {3, 128, 128, 0, 0},
    {4, 0, 0, 128, 0},
    {5, 128, 0, 128, 0},
    {6, 0, 128, 128, 0},
    {7, 192, 192, 192, 0},
    {8, 192, 220, 192, 0},
    {9, 166, 202, 240, 0},
    {246, 255, 251, 240, 0},
    {247, 160, 160, 164, 0},
    {248, 128, 128, 128, 0},
    {249, 255, 0, 0, 0},
    {250, 0, 255, 0, 0},
    {251, 255, 255, 0, 0},
    {252, 0, 0, 255, 0},
    {253, 255, 0, 255, 0},
    {254, 0, 255, 255, 0},
    {255, 255, 255, 255, 0},
    {-1, 0, 0, 0, 0},
};

int FacetSkipMask[9] = {
    56, 112, 224, 193, 131, 7, 14, 28,
    0,
};

unsigned long ObstructionMasks[192] = {
    0x00000003u, 0x00000000u, 0x0000000Cu, 0x00000000u, 0x00000030u, 0x00000000u, 0x000000C0u, 0x00000000u,
    0x0000000Fu, 0x00000000u, 0x0000003Cu, 0x00000000u, 0x000000F0u, 0x00000000u, 0x000003C0u, 0x00000000u,
    0x0000003Fu, 0x00000000u, 0x000000FCu, 0x00000000u, 0x000003F0u, 0x00000000u, 0x00000FC0u, 0x00000000u,
    0x000000FFu, 0x00000000u, 0x000003FCu, 0x00000000u, 0x00000FF0u, 0x00000000u, 0x00003FC0u, 0x00000000u,
    0x000003FFu, 0x00000000u, 0x00000FFCu, 0x00000000u, 0x00003FF0u, 0x00000000u, 0x0000FFC0u, 0x00000000u,
    0x00000FFFu, 0x00000000u, 0x00003FFCu, 0x00000000u, 0x0000FFF0u, 0x00000000u, 0x0003FFC0u, 0x00000000u,
    0x00003FFFu, 0x00000000u, 0x0000FFFCu, 0x00000000u, 0x0003FFF0u, 0x00000000u, 0x000FFFC0u, 0x00000000u,
    0x0000FFFFu, 0x00000000u, 0x0003FFFCu, 0x00000000u, 0x000FFFF0u, 0x00000000u, 0x003FFFC0u, 0x00000000u,
    0x0003FFFFu, 0x00000000u, 0x000FFFFCu, 0x00000000u, 0x003FFFF0u, 0x00000000u, 0x00FFFFC0u, 0x00000000u,
    0x000FFFFFu, 0x00000000u, 0x003FFFFCu, 0x00000000u, 0x00FFFFF0u, 0x00000000u, 0x03FFFFC0u, 0x00000000u,
    0x003FFFFFu, 0x00000000u, 0x00FFFFFCu, 0x00000000u, 0x03FFFFF0u, 0x00000000u, 0x0FFFFFC0u, 0x00000000u,
    0x00FFFFFFu, 0x00000000u, 0x03FFFFFCu, 0x00000000u, 0x0FFFFFF0u, 0x00000000u, 0x3FFFFFC0u, 0x00000000u,
    0x03FFFFFFu, 0x00000000u, 0x0FFFFFFCu, 0x00000000u, 0x3FFFFFF0u, 0x00000000u, 0xFFFFFFC0u, 0x00000000u,
    0x0FFFFFFFu, 0x00000000u, 0x3FFFFFFCu, 0x00000000u, 0xFFFFFFF0u, 0x00000000u, 0xFFFFFFC0u, 0x00000003u,
    0x3FFFFFFFu, 0x00000000u, 0xFFFFFFFCu, 0x00000000u, 0xFFFFFFF0u, 0x00000003u, 0xFFFFFFC0u, 0x0000000Fu,
    0xFFFFFFFFu, 0x00000000u, 0xFFFFFFFCu, 0x00000003u, 0xFFFFFFF0u, 0x0000000Fu, 0xFFFFFFC0u, 0x0000003Fu,
    0xFFFFFFFFu, 0x00000003u, 0xFFFFFFFCu, 0x0000000Fu, 0xFFFFFFF0u, 0x0000003Fu, 0xFFFFFFC0u, 0x000000FFu,
    0xFFFFFFFFu, 0x0000000Fu, 0xFFFFFFFCu, 0x0000003Fu, 0xFFFFFFF0u, 0x000000FFu, 0xFFFFFFC0u, 0x000003FFu,
    0xFFFFFFFFu, 0x0000003Fu, 0xFFFFFFFCu, 0x000000FFu, 0xFFFFFFF0u, 0x000003FFu, 0xFFFFFFC0u, 0x00000FFFu,
    0xFFFFFFFFu, 0x000000FFu, 0xFFFFFFFCu, 0x000003FFu, 0xFFFFFFF0u, 0x00000FFFu, 0xFFFFFFC0u, 0x00003FFFu,
    0xFFFFFFFFu, 0x000003FFu, 0xFFFFFFFCu, 0x00000FFFu, 0xFFFFFFF0u, 0x00003FFFu, 0xFFFFFFC0u, 0x0000FFFFu,
    0xFFFFFFFFu, 0x00000FFFu, 0xFFFFFFFCu, 0x00003FFFu, 0xFFFFFFF0u, 0x0000FFFFu, 0xFFFFFFC0u, 0x0003FFFFu,
    0xFFFFFFFFu, 0x00003FFFu, 0xFFFFFFFCu, 0x0000FFFFu, 0xFFFFFFF0u, 0x0003FFFFu, 0xFFFFFFC0u, 0x000FFFFFu,
    0xFFFFFFFFu, 0x0000FFFFu, 0xFFFFFFFCu, 0x0003FFFFu, 0xFFFFFFF0u, 0x000FFFFFu, 0xFFFFFFC0u, 0x003FFFFFu,
};

MouseClickInfo Tribe2btnMouseRightClickTable[40] = {
    {0, 4, 3900, 3, 0, 4, 3900, 8, 3901, 8, 3901},
    {1, 0, 0, 3, 0, 3, 0, 3, 0, 3, 0},
    {2, 0, 0, 3, 0, 0, 0, 8, 3904, 8, 3904},
    {3, 5, 3905, 3, 0, 5, 3905, 8, 3902, 8, 3902},
    {4, 4, 3900, 3, 0, 4, 3900, 8, 3901, 8, 3901},
    {5, 0, 0, 6, 3907, 0, 0, 0, 0, 0, 0},
    {6, 4, 3900, 3, 0, 4, 3900, 8, 3901, 8, 3901},
    {7, 0, 0, 6, 3909, 0, 0, 0, 0, 0, 0},
    {8, 0, 0, 6, 3911, 0, 0, 0, 0, 0, 0},
    {9, 0, 0, 9, 3910, 0, 0, 0, 0, 0, 0},
    {10, 0, 0, 9, 3910, 0, 0, 0, 0, 0, 0},
    {11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {12, 4, 3900, 3, 0, 4, 3900, 8, 3901, 8, 3901},
    {13, 4, 3900, 3, 0, 4, 3900, 8, 3901, 8, 3901},
    {14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {15, 0, 0, 6, 3908, 0, 0, 0, 0, 0, 0},
    {16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {17, 4, 3900, 3, 0, 4, 3900, 8, 3901, 8, 3901},
    {18, 4, 3900, 3, 0, 4, 3900, 8, 3901, 8, 3901},
    {19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {20, 2, 3906, 3, 0, 2, 3906, 8, 3904, 8, 3904},
    {21, 0, 0, 3, 0, 0, 0, 8, 3904, 8, 3904},
    {22, 0, 0, 3, 0, 0, 0, 8, 3904, 8, 3904},
    {23, 4, 3900, 3, 0, 4, 3900, 8, 3901, 8, 3901},
    {24, 4, 3900, 3, 0, 4, 3900, 8, 3901, 8, 3901},
    {25, 4, 3900, 3, 0, 4, 3900, 8, 3901, 8, 3901},
    {26, 4, 3900, 3, 0, 4, 3900, 8, 3901, 8, 3901},
    {27, 5, 3913, 3, 0, 5, 3913, 1, 3903, 1, 3903},
    {28, 4, 3900, 3, 0, 4, 3900, 8, 3901, 8, 3901},
    {29, 0, 0, 9, 3910, 0, 0, 0, 0, 0, 0},
    {30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {31, 0, 0, 6, 3907, 0, 0, 0, 0, 0, 0},
    {32, 0, 0, 6, 3912, 0, 0, 0, 0, 0, 0},
    {33, 0, 0, 6, 3907, 0, 0, 0, 0, 0, 0},
    {34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {35, 4, 3900, 3, 0, 4, 3900, 8, 3901, 8, 3901},
    {36, 4, 3900, 3, 0, 4, 3900, 8, 3901, 8, 3901},
    {37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {39, 4, 3900, 3, 0, 4, 3900, 8, 3901, 8, 3901},
};

MouseClickInfo Tribe2btnMouseLeftClickTable[40] = {
    {0, 0, 3803, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 3807, 0, 3820, 0, 3820, 0, 3820, 0, 3820},
    {2, 0, 3804, 0, 0, 0, 0, 0, 0, 0, 0},
    {3, 0, 3801, 0, 0, 0, 0, 0, 0, 0, 0},
    {4, 0, 3800, 0, 0, 0, 0, 0, 0, 0, 0},
    {5, 0, 0, 0, 3821, 0, 0, 0, 0, 0, 0},
    {6, 0, 3803, 0, 0, 0, 0, 0, 0, 0, 0},
    {7, 0, 0, 0, 3823, 0, 0, 0, 0, 0, 0},
    {8, 0, 0, 0, 3824, 0, 0, 0, 0, 0, 0},
    {9, 0, 0, 0, 3826, 0, 0, 0, 0, 0, 0},
    {10, 0, 0, 0, 3826, 0, 0, 0, 0, 0, 0},
    {11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {12, 0, 3803, 0, 0, 0, 0, 0, 0, 0, 0},
    {13, 0, 3805, 0, 0, 0, 0, 0, 0, 0, 0},
    {14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {15, 0, 0, 0, 3822, 0, 0, 0, 0, 0, 0},
    {16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {18, 0, 3806, 0, 0, 0, 0, 0, 0, 0, 0},
    {19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {20, 0, 3804, 0, 0, 0, 0, 0, 0, 0, 0},
    {21, 0, 3804, 0, 0, 0, 0, 0, 0, 0, 0},
    {22, 0, 3804, 0, 0, 0, 0, 0, 0, 0, 0},
    {23, 0, 3803, 0, 0, 0, 0, 0, 0, 0, 0},
    {24, 0, 3803, 0, 0, 0, 0, 0, 0, 0, 0},
    {25, 0, 3803, 0, 0, 0, 0, 0, 0, 0, 0},
    {26, 0, 3803, 0, 0, 0, 0, 0, 0, 0, 0},
    {27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {28, 0, 3803, 0, 0, 0, 0, 0, 0, 0, 0},
    {29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {32, 0, 0, 0, 3825, 0, 0, 0, 0, 0, 0},
    {33, 0, 0, 0, 3821, 0, 0, 0, 0, 0, 0},
    {34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {35, 0, 3803, 0, 0, 0, 0, 0, 0, 0, 0},
    {36, 0, 3803, 0, 0, 0, 0, 0, 0, 0, 0},
    {37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {39, 0, 3803, 0, 0, 0, 0, 0, 0, 0, 0},
};

MouseClickInfo Tribe1btnMouseRightClickTable[40] = {
    {0, 4, 3700, 3, 0, 4, 3700, 8, 3701, 8, 3701},
    {1, 0, 0, 3, 0, 3, 0, 3, 0, 3, 0},
    {2, 0, 0, 3, 0, 0, 0, 8, 3704, 8, 3704},
    {3, 5, 3705, 3, 0, 5, 3705, 8, 3702, 8, 3702},
    {4, 4, 3700, 3, 0, 4, 3700, 8, 3701, 8, 3701},
    {5, 0, 0, 6, 3707, 0, 0, 0, 0, 0, 0},
    {6, 4, 3700, 3, 0, 4, 3700, 8, 3701, 8, 3701},
    {7, 0, 0, 6, 3709, 0, 0, 0, 0, 0, 0},
    {8, 0, 0, 6, 3711, 0, 0, 0, 0, 0, 0},
    {9, 0, 0, 9, 3710, 0, 0, 0, 0, 0, 0},
    {10, 0, 0, 9, 3710, 0, 0, 0, 0, 0, 0},
    {11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {12, 4, 3700, 3, 0, 4, 3700, 8, 3701, 8, 3701},
    {13, 4, 3700, 3, 0, 4, 3700, 8, 3701, 8, 3701},
    {14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {15, 0, 0, 6, 3708, 0, 0, 0, 0, 0, 0},
    {16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {17, 4, 3700, 3, 0, 4, 3700, 8, 3701, 8, 3701},
    {18, 4, 3700, 3, 0, 4, 3700, 8, 3701, 8, 3701},
    {19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {20, 2, 3706, 3, 0, 2, 3706, 8, 3704, 8, 3704},
    {21, 0, 0, 3, 0, 0, 0, 8, 3704, 8, 3704},
    {22, 0, 0, 3, 0, 0, 0, 8, 3704, 8, 3704},
    {23, 4, 3700, 3, 0, 4, 3700, 8, 3701, 8, 3701},
    {24, 4, 3700, 3, 0, 4, 3700, 8, 3701, 8, 3701},
    {25, 4, 3700, 3, 0, 4, 3700, 8, 3701, 8, 3701},
    {26, 4, 3700, 3, 0, 4, 3700, 8, 3701, 8, 3701},
    {27, 5, 3713, 3, 0, 5, 3713, 1, 3703, 1, 3703},
    {28, 4, 3700, 3, 0, 4, 3700, 8, 3701, 8, 3701},
    {29, 0, 0, 9, 3710, 0, 0, 0, 0, 0, 0},
    {30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {31, 0, 0, 6, 3707, 0, 0, 0, 0, 0, 0},
    {32, 0, 0, 6, 3712, 0, 0, 0, 0, 0, 0},
    {33, 0, 0, 6, 3707, 0, 0, 0, 0, 0, 0},
    {34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {35, 4, 3700, 3, 0, 4, 3700, 8, 3701, 8, 3701},
    {36, 4, 3700, 3, 0, 4, 3700, 8, 3701, 8, 3701},
    {37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {39, 4, 3700, 3, 0, 4, 3700, 8, 3701, 8, 3701},
};

MouseClickInfo Tribe1btnMouseLeftClickTable[40] = {
    {0, 0, 3803, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 3807, 0, 3820, 0, 3820, 0, 3820, 0, 3820},
    {2, 0, 3804, 0, 0, 0, 0, 0, 0, 0, 0},
    {3, 0, 3801, 0, 0, 0, 0, 0, 0, 0, 0},
    {4, 0, 3800, 0, 0, 0, 0, 0, 0, 0, 0},
    {5, 0, 0, 0, 3821, 0, 0, 0, 0, 0, 0},
    {6, 0, 3803, 0, 0, 0, 0, 0, 0, 0, 0},
    {7, 0, 0, 0, 3823, 0, 0, 0, 0, 0, 0},
    {8, 0, 0, 0, 3824, 0, 0, 0, 0, 0, 0},
    {9, 0, 0, 0, 3826, 0, 0, 0, 0, 0, 0},
    {10, 0, 0, 0, 3826, 0, 0, 0, 0, 0, 0},
    {11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {12, 0, 3803, 0, 0, 0, 0, 0, 0, 0, 0},
    {13, 0, 3805, 0, 0, 0, 0, 0, 0, 0, 0},
    {14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {15, 0, 0, 0, 3822, 0, 0, 0, 0, 0, 0},
    {16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {18, 0, 3806, 0, 0, 0, 0, 0, 0, 0, 0},
    {19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {20, 0, 3804, 0, 0, 0, 0, 0, 0, 0, 0},
    {21, 0, 3804, 0, 0, 0, 0, 0, 0, 0, 0},
    {22, 0, 3804, 0, 0, 0, 0, 0, 0, 0, 0},
    {23, 0, 3803, 0, 0, 0, 0, 0, 0, 0, 0},
    {24, 0, 3803, 0, 0, 0, 0, 0, 0, 0, 0},
    {25, 0, 3803, 0, 0, 0, 0, 0, 0, 0, 0},
    {26, 0, 3803, 0, 0, 0, 0, 0, 0, 0, 0},
    {27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {28, 0, 3803, 0, 0, 0, 0, 0, 0, 0, 0},
    {29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {32, 0, 0, 0, 3825, 0, 0, 0, 0, 0, 0},
    {33, 0, 0, 0, 3821, 0, 0, 0, 0, 0, 0},
    {34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {35, 0, 3803, 0, 0, 0, 0, 0, 0, 0, 0},
    {36, 0, 3803, 0, 0, 0, 0, 0, 0, 0, 0},
    {37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {39, 0, 3803, 0, 0, 0, 0, 0, 0, 0, 0},
};

extern const int encrypt_table[32] = {
    11569, 26744, 10847, 13123, 16190, 16749, 19053, 12634,
    16425, 9036, 32123, 25431, 11041, 9571, 25687, 9566,
    30526, 26744, 9509, 12580, 8286, 24426, 9812, 13363,
    10536, 14906, 21311, 9803, 21113, 14168, 15209, 10790,
};
