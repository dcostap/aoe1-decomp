// Authentic World.cpp game-setup and scenario span.
//
// The owners follow PDB line order and share one reviewed World surface.
// Each included file remains the sole source owner of its VA body. The span
// starts at the World.cpp destructor and continues through scenario loading.
// Generated companions remain outside. The grouped check uses the authentic
// World-module /O2 /Oy /GX response file.
#include "matching/00540A40_RGE_Game_World.cpp"

// BINARY NOTE: 00540750 is exact as a standalone owner, but its source has a
// private RGE_Game_World and RGE_Object_List surface plus a raw vptr store.
// The grouped probe failed with VC5 C2011 redefinition errors for both types.
// Keep this owner outside the grouped span until a natural shared reconstruction
// exists. Do not solve this with a raw vptr or a duplicate class surface.
#include "matching/00540CF0_reset_object_count.cpp"
#include "matching/00540D30_pause.cpp"
#include "matching/00540D60_set_map_visible.cpp"
#include "matching/00540D80_set_map_fog.cpp"
#include "matching/00540DA0_data_load_sounds.cpp"
#include "matching/00540EB0_data_load_terrain_tables.cpp"
#include "accepted_drift/00540FD0_data_load_color_tables.cpp"
#include "matching/005410E0_data_load_sprites.cpp"
#include "matching/00541240_data_load_players_type.cpp"

// BINARY NOTE: These World.cpp bodies remain included to preserve the
// authentic source context, but are not grouped owners. Fresh /GX checks for
// 00542BF0, 00543E00, and 00544090 remain non-exact.
#include "accepted_drift/005412B0_data_load_players.cpp"
#include "matching/00541380_data_load_objects.cpp"
#include "accepted_drift/005414A0_data_load_effects.cpp"
#include "matching/00541500_data_load_map.cpp"
#include "matching/00541590_data_load_random_map.cpp"
#include "matching/005415B0_data_load_world.cpp"
#include "matching/00541720_data_load.cpp"
#include "matching/00541770_init_player_type.cpp"
#include "matching/00541800_init_player.cpp"
#include "matching/00541880_terrain_tables_init.cpp"
#include "matching/00541930_color_table_init.cpp"
#include "matching/005419E0_init_sounds.cpp"
#include "matching/00541A80_init_sprites.cpp"
#include "accepted_drift/00541B60_scenario_init.cpp"
#include "accepted_drift/00541BC0_scenario_init.cpp"
#include "accepted_drift/00541C20_map_init.cpp"
#include "accepted_drift/00541C90_effects_init.cpp"
#include "matching/00541CF0_master_player_init.cpp"
#include "accepted_drift/00541D00_command_init.cpp"
#include "matching/00541D60_world_init.cpp"
#include "matching/00541DB0_init.cpp"
#include "matching/00541E70_turn_sound_off.cpp"
#include "matching/00541EA0_reset_communications.cpp"
#include "matching/00541EB0_reset_player_visible_maps.cpp"
#include "matching/00541EE0_del_game_info.cpp"
#include "matching/00542060_load_player.cpp"
#include "accepted_drift/005420F0_load_world.cpp"
#include "matching/00542360_load_game.cpp"
#include "matching/00542470_set_game_speed.cpp"
#include "accepted_drift/00542480_setup_gaia.cpp"
#include "matching/005424F0_setup_players.cpp"
#include "accepted_drift/005425B0_setup_player_colors.cpp"
#include "matching/005426E0_setup_player_colors.cpp"
#include "matching/00542750_new_game.cpp"
#include "scratch/00542BF0_new_scenario.cpp"
#include "matching/00542D10_new_random_game.cpp"
#include "matching/00542E50_update_sounds.cpp"
#include "matching/00542E90_update_sprites.cpp"
#include "matching/00542ED0_update.cpp"
#include "matching/00543380_is_player_turn.cpp"
#include "matching/005433A0_get_accum_time_delta.cpp"
#include "matching/005433B0_get_game_state.cpp"
#include "matching/005433C0_check_game_state.cpp"
#include "matching/00543540_save.cpp"
#include "matching/00543770_save_game.cpp"
#include "matching/00543850_base_save.cpp"
#include "matching/005439C0_base_save.cpp"
#include "matching/00543A00_save_scenario.cpp"
#include "accepted_drift/00543E00_load_scenario.cpp"
#include "accepted_drift/00544090_load_scenario.cpp"
#include "matching/00544250_scenario_make_player.cpp"
#include "matching/005442E0_scenario_make_map.cpp"
#include "matching/00544300_load_scenario1.cpp"
#include "matching/005445C0_load_scenario2.cpp"
#include "matching/00544880_load_scenario3.cpp"
#include "matching/00544B90_load_scenario4.cpp"
#include "matching/00544E70_load_scenario5.cpp"
#include "matching/005451A0_load_scenario6.cpp"
