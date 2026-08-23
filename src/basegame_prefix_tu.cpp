// Canonical basegame.cpp prefix in PDB source and address order.
// Compile this translation unit with /O2 /Oy /GX.
#include <windows.h>
#include <stdio.h>
#include <io.h>
#include <new.h>
#include <string.h>

#define BASEGAME_GROUPED_TU
extern FILE* draw_log;
extern char draw_log_name[260];

#include "matching/0041B620_write_draw_log.cpp"
#include "matching/0041B650_write_draw_log2.cpp"
#include "matching/0041B6A0_RGE_Base_Game.cpp"
#include "accepted_drift/0041BAA0_setup.cpp"
#include "matching/0041C240_set_prog_mode.cpp"
#include "matching/0041C250_get_view_panel.cpp"
#include "matching/0041C260_get_map_panel.cpp"
#include "scratch/0041C270_RGE_Base_Game.cpp"
#include "matching/0041C6E0_notification.cpp"
#include "matching/0041C6F0_processCheatCode.cpp"
#include "matching/0041C700_handle_message.cpp"
#include "matching/0041C710_action_update.cpp"
#include "matching/0041C720_action_mouse_move.cpp"
#include "matching/0041C730_action_key_down.cpp"
#include "matching/0041C740_action_user_command.cpp"
#include "matching/0041C750_action_command.cpp"
#include "matching/0041C760_action_music_done.cpp"
#include "matching/0041C770_action_activate.cpp"
#include "matching/0041C780_action_deactivate.cpp"
#include "matching/0041C790_action_init_menu.cpp"
#include "matching/0041C7A0_action_exit_menu.cpp"
#include "matching/0041C7B0_action_size.cpp"
#include "matching/0041C7C0_action_close.cpp"
#include "matching/0041C7D0_reset_timings.cpp"
#include "matching/0041C830_add_to_timing.cpp"
#include "matching/0041c870_increment_world_update_count.cpp"
#include "matching/0041c880_increment_view_update_count.cpp"
#include "matching/0041C890_set_last_single_time.cpp"
#include "matching/0041C8B0_get_last_time.cpp"
#include "matching/0041C8D0_get_last_single_time.cpp"
#include "matching/0041C8F0_get_accum_time.cpp"
#include "matching/0041C910_get_max_time.cpp"
#include "matching/0041C930_get_last_max_time.cpp"
#include "matching/0041c950_get_last_world_update_count.cpp"
#include "matching/0041c960_get_last_view_update_count.cpp"
#include "matching/0041c970_get_world_update_count.cpp"
#include "matching/0041c980_get_view_update_count.cpp"
#include "matching/0041c990_get_error_code.cpp"
#include "matching/0041C9A0_get_string.cpp"
#include "matching/0041C9C0_get_string.cpp"
#include "matching/0041C9F0_get_string.cpp"
#include "matching/0041CA10_get_string2.cpp"
#include "matching/0041CB80_get_scenario_info.cpp"
#include "matching/0041CCA0_get_scenario_header.cpp"
#include "matching/0041CDA0_write_scenario_header.cpp"
#include "matching/0041CE00_new_scenario_header.cpp"
#include "matching/0041CE60_new_scenario_header.cpp"
#include "matching/0041CEC0_new_scenario_info.cpp"
#include "matching/0041CF30_get_campaign_info.cpp"
#include "matching/0041CF70_set_campaign_info.cpp"
#include "matching/0041CFC0_set_campaign_win.cpp"
#include "matching/0041CFD0_run.cpp"
#include "matching/0041D0A0_setup_cmd_options.cpp"
#include "matching/0041E700_setup_class.cpp"
#include "matching/0041E7A0_rge_base_game_wnd_proc.cpp"
#include "verified_logic/0041E7D0_setup_main_window.cpp"

#include "accepted_drift/0041E920_setup_graphics_system.cpp"
#include "matching/0041EBC0_setup_palette.cpp"
#include "matching/0041EBF0_setup_mouse.cpp"

// NEXT BLOCKER: 0041ED00 setup_chat still owns incompatible local
// RGE_Base_Game, TChat, and rge_base_game declarations.  The compiler then
// loses the TChat constructor and taunt member surface.
