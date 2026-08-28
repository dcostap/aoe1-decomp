// PDB source module: C:\\msdev\\work\\age1_x1\\basegame.cpp.
//
// PDB lines 199-481.  0041BAA0 begins the reviewed setup hold.

#include <windows.h>
#include <io.h>
#include <new.h>
#include <stdio.h>
#include <string.h>

#include "../include/basegame.h"
#include "../include/main.h"
#include "../include/rge_base_game_global.h"

extern FILE* draw_log;
extern char draw_log_name[260];
extern int do_draw_log;
extern int safe_draw_log;
extern int g_592A58;
extern int g_62C4A0;
extern int g_62C4A8;
extern int g_62C4B0;
extern int g_62C4B8;
extern int g_62C4C0;
extern int g_62C4FC;
extern int g_5B215C;
extern int g_5B236C;

// 0041B620 write_draw_log, basegame.cpp:199-205 (44 bytes).
void __cdecl write_draw_log(char* text)
{
    if (draw_log != 0) {
        fprintf(draw_log, "%s", text);
        fflush(draw_log);
    }
}

// 0041B650 write_draw_log2, basegame.cpp:208-215 (67 bytes).
void __cdecl write_draw_log2(char* text)
{
    if (draw_log != 0) {
        fprintf(draw_log, "%s", text);
        fclose(draw_log);
        draw_log = fopen(draw_log_name, "a+");
    }
}

// 0041E7A0 rge_base_game_wnd_proc, basegame.cpp:230-235 (43 bytes).
unsigned long __stdcall rge_base_game_wnd_proc(
    unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    RGE_Base_Game* game = rge_base_game;
    if (game != 0)
        return (unsigned long)game->wnd_proc((void*)a, b, c, (long)d);
    return 0;
}

// 0041B6A0 RGE_Base_Game::RGE_Base_Game, basegame.cpp:247-481 (988 bytes).
RGE_Base_Game::RGE_Base_Game(RGE_Prog_Info* info, int do_setup)
    : player_game_info(0),
      random_game_seed(-1),
      random_map_seed(-1),
      save_random_game_seed(-1),
      save_random_map_seed(-1),
      quick_build(0)
{
    int i;

    do_draw_log = 0;
    safe_draw_log = 0;
    draw_log_name[0] = 0;
    draw_log = 0;

    this->setVersion(1.0f);
    this->setScenarioGame(0);
    this->setCampaignGame(0);
    this->setSavedGame(0);
    this->setSinglePlayerGame(1);
    this->setMultiplayerGame(0);
    this->setMapSize(0x60, 0x60, 8);
    this->setAllowCheatCodes(0);
    this->setCheatNotification(1);
    this->setFullVisibility(0);
    this->setFogOfWar(1);
    this->setColoredChat(1);
    this->setGameDeveloperMode(0);
    this->setDifficulty(0);

    for (i = 0; i < 9; i++) {
        this->setPlayerCDAndVersion(i, 0);
        this->setPlayerHasCD(i, 0);
        this->setPlayerVersion(i, 0);
        this->setPlayerTeam(i, 1);
    }

    this->setPathFinding(0);
    this->setMpPathFinding(0);
    this->setNumberPlayers(4);
    this->setScenarioName("");

    rge_base_game = this;
    this->prog_info = info;
    this->prog_window = 0;
    this->prog_ready = 0;
    this->prog_active = 1;
    this->prog_palette = 0;
    this->window_style = 0;
    g_62C4A0 = 0;
    this->screen_saver_enabled = 0;
    this->error_code = 0;
    this->is_timer = 0;
    this->draw_system = 0;
    this->draw_area = 0;
    this->outline_type = 2;
    this->custom_mouse = 0;
    this->shapes = 0;
    this->sound_system = 0;
    this->music_system = 0;
    this->sound_num = 0;
    this->sounds = 0;
    this->save_music_type = 0;
    this->save_music_track_from = 0;
    this->save_music_track_to = 0;
    this->save_music_cur_track = 0;
    this->save_music_file[0] = 0;
    this->save_music_loop = 0;
    this->save_music_pos = 0;
    this->comm_handler = 0;
    this->debugLog = 0;
    this->log_comm = 0;
    this->comm_syncstop = 0;
    this->comm_syncmsg = 0;
    this->comm_stepmode = 0;
    this->comm_speed = 1;
    this->comm_droppackets = 0;
    this->registry = 0;
    this->prog_mode = 0;
    this->game_mode = 0;
    this->sub_game_mode = 0;
    this->paused = 0;
    this->mouse_pointer = 0;
    this->erase_mouse = 0;
    this->mouse_blit_sync = 0;
    this->is_mouse_on = 1;
    this->windows_mouse = 1;
    this->mouse_cursor = LoadCursorA(0, IDC_ARROW);
    this->font_num = 0;
    this->fonts = 0;
    GetCurrentDirectoryA(0x105, this->work_dir);

    strcpy(this->string_dll_name, "language.dll");

    this->master_obj_id = -1;
    this->terrain_id = -1;
    this->elevation_height = -1;
    this->world = 0;
    this->render_all = 1;
    this->brush_size = 1;
    this->timing_text[0] = 0;
    this->frame_count = 0;
    this->world_update_count = 0;
    this->view_update_count = 0;
    this->last_frame_count = 0;
    this->last_world_update_count = 0;
    this->last_view_update_count = 0;
    this->fps = 0;
    this->world_update_fps = 0;
    this->view_update_fps = 0;
    this->last_view_time = 0;

    for (i = 0; i < 30; i++) {
        this->timings[i].accum_time = 0;
        this->timings[i].last_time = 0;
        this->timings[i].start_time = 0;
        this->timings[i].last_single_time = 0;
        this->timings[i].max_time = 0;
        this->timings[i].last_max_time = 0;
        this->timings[i].include_in_total = 0;
        this->timings[i].is_summary = 0;
    }

    this->do_show_timings = 0;
    this->do_show_comm = 0;
    this->do_show_ai = 0;
    this->save_check_for_cd = 1;
    g_62C4FC = 0;
    g_592A58 = (int)this->prog_info->instance;
    g_5B236C = 0;
    g_62C4B8 = 0;
    g_62C4C0 = 0;
    g_62C4A8 = 0;
    g_62C4B0 = 0;
    g_5B215C = 0;
    this->scenario_info = 0;
    for (i = 0; i < 9; i++) {
        this->playerIDValue[i] = 0;
        this->resigned[i] = 0;
    }
    this->auto_paused = 0;
    this->rollover = 1;
    this->map_save_area = 0;
    this->game_speed = 1.0f;
    this->single_player_difficulty = 2;

    if (!this->setup_registry()) {
        this->error_code = 0x0E;
        return;
    }
    g_62C4A8 = (int)this->registry;
    if (!this->setup_debugging_log()) {
        this->error_code = 0x0F;
        return;
    }
    g_62C4FC = (int)this->debugLog;
    if (do_setup) {
        if (!this->setup()) {
            if (!this->error_code)
                this->error_code = 1;
        }
    }
    this->display_selected_ids = 0;
}

// 0041BAA0 RGE_Base_Game::setup remains an accepted-drift hold.
