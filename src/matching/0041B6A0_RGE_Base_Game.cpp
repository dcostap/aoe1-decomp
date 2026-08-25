// VA: 0041B6A0 RGE_Base_Game::RGE_Base_Game (988 B)
// PDB source: basegame.cpp
// Attempt log:
// - Baseline was a packet-grounded free-function/raw-offset scaffold; it rebuilt
//   with the right call sequence but had a non-member prologue and wrong imported
//   call surfaces.  The current candidate uses the generated RGE_Base_Game layout,
//   the real virtual-destructor class context, named member setters, and the
//   period string/intrinsic surfaces.
// - Moving the six binary-first member initializations into a natural constructor
//   initializer list reproduced the delayed vptr scheduling and reached MATCH.
// Source audit: the byte-exact variant used __declspec(novtable) plus an explicit
// vptr store; that compiler-steering form is rejected.  The retained virtual
// destructor class and member initializer list are natural and produce the same
// delayed vptr store without an explicit vptr write.
// Declaration probe: packet symbols require _iobuf* and char[260]. The full
// binary-backed virtual surface through +0x140 changed no bytes. Exact setter
// donors preserve their real narrow and wide parameter types. The remaining
// drift starts at the natural implicit vptr store.

#include <string.h>

class RGE_Scenario;




class TDrawArea;



class TSound_Driver;
class TMusic_System;
class TDigital;







struct _iobuf;


class RGE_Base_Game;
struct tagMSG;
class TPanel;

extern "C" __declspec(dllimport) void* __stdcall LoadCursorA(void* instance, const char* cursor);
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentDirectoryA(unsigned long size, char* buffer);

extern int do_draw_log;
extern int safe_draw_log;
extern char draw_log_name[260];
extern _iobuf* draw_log;
extern RGE_Base_Game* rge_base_game;
extern void* StringTable;
extern int debugActions;
extern _iobuf* actionFile;
extern int do_fps_log;
extern _iobuf* fps_log;
extern DriveInformation* driveInfo;
extern TChat* chat;
extern TPanelSystem panel_system;
extern int do_debug_random;
extern int wrote_debug_random_log;
extern float DAT_0056f014;
extern float DAT_0056f018;
extern "C" unsigned long __cdecl debug_timeGetTime(char* file, int line);
extern "C" void __cdecl debug_srand(char* file, int line,
                                      unsigned int seed);
extern "C" void __cdecl GetDXVersion(unsigned long* version,
                                      unsigned long* platform);
extern void __cdecl debug_random_write(void);
extern void __cdecl dump_vismap_log(void);
extern int g_592A58; // AppInst
extern int g_62C4A0; // StringTable
extern int g_62C4A8; // Regs
extern int g_62C4B0; // sound_driver
extern int g_62C4B8; // chat
extern int g_62C4C0; // comm
extern int g_62C4FC; // L
extern int g_5B215Ch; // driveInfo
extern int g_5B2160; // AppWnd
extern int g_5B236C; // comm/global window state
extern int g_62C574; // rge_base_game storage

#ifndef IDC_ARROW
#define IDC_ARROW ((const char*)32512)
#endif


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
    g_5B215Ch = 0;
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
