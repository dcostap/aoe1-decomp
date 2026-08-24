// Authentic PDB-ordered World.cpp candidate wrapper.
//
// The World.cpp module owns the included source bodies from the destructor
// through load_scenario6. The constructor owner at 00540750 is omitted because
// it writes a private vptr and has a private duplicate class surface. The
// later scenario7/8 and helper suffix owners are omitted because they still
// carry private local class declarations. The validation packet carries the
// proven field surface. The durable header proposal is include/world_context.h.
//
// Omitted normal owners: 00540750 (private constructor vptr owner), 00542470
// (alternate game-speed field spelling), 00542750 (alternate Player_Info field
// spellings), 005454D0 and 00545800 (private scenario-loader declarations),
// and 00545B30-005462D0 (private helper declarations). These owners require a
// natural shared class surface before inclusion. No replacement alias is used.
//
// The wrapper uses /nologo /c /O2 /Oy /GX. Initial owner comparisons may show
// mismatch. This packet records source order and compile context only.
// Proposed shared header: include/world_context.h. The candidate validation
// supplies the same header from its response-file include path.
#include "../include/world_context.h"

#include "matching/00540CF0_reset_object_count.cpp"
#include "matching/00540D30_pause.cpp"
#include "matching/00540D60_set_map_visible.cpp"
#include "matching/00540D80_set_map_fog.cpp"
#include "matching/00540DA0_data_load_sounds.cpp"
#include "matching/00540EB0_data_load_terrain_tables.cpp"
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
#include "accepted_drift/00542480_setup_gaia.cpp"
#include "matching/005424F0_setup_players.cpp"
#include "accepted_drift/005425B0_setup_player_colors.cpp"
#include "matching/005426E0_setup_player_colors.cpp"
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
