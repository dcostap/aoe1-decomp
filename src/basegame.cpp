
#include <windows.h>
#include <io.h>
#include <new.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/basegame.h"
#include "../include/main.h"
#include "../include/rge_base_game_global.h"
#include "../include/gameinfo.h"
#include "../include/game_globals.h"
#include "../include/sceninfo.h"
#include "../include/scenario.h"
#include "../include/file_stf.h"
#include "../include/drawarea.h"
#include "../include/sounddrv.h"
#include "../include/music.h"
#include "../include/chat.h"
#include "../include/com_hand.h"
#include "../include/debuglog.h"
#include "../include/registry.h"
#include "../include/Mouseptr.h"
#include "../include/Shape.h"
#include "../include/panel.h"
#include "../include/panel_ez.h"
#include "../include/Pnl_scr.h"
#include "../include/world.h"
#include "../include/map.h"
#include "../include/player.h"
#include "../include/obj_list.h"
#include "../include/sound.h"
#include "../include/rge_fio.h"

extern FILE* draw_log;
extern char draw_log_name[260];
extern int do_draw_log;
extern int safe_draw_log;

void __cdecl write_draw_log(char* text)
{
    if (draw_log != 0) {
        fprintf(draw_log, "%s", text);
        fflush(draw_log);
    }
}

void __cdecl write_draw_log2(char* text)
{
    if (draw_log != 0) {
        fprintf(draw_log, "%s", text);
        fclose(draw_log);
        draw_log = fopen(draw_log_name, "a+");
    }
}

LRESULT CALLBACK rge_base_game_wnd_proc(
    HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
    RGE_Base_Game* game = rge_base_game;
    if (game != 0)
        return game->wnd_proc(hwnd, message, wparam, lparam);
    return 0;
}

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
    StringTable = 0;
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
    L = 0;
    AppInst = this->prog_info->instance;
    AppWnd = 0;
    chat = 0;
    comm = 0;
    Regs = 0;
    sound_driver = 0;
    driveInfo = 0;
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
    Regs = this->registry;
    if (!this->setup_debugging_log()) {
        this->error_code = 0x0F;
        return;
    }
    L = this->debugLog;
    if (do_setup) {
        if (!this->setup()) {
            if (!this->error_code)
                this->error_code = 1;
        }
    }
    this->display_selected_ids = 0;
}




void __cdecl debug_srand(char* file, int line,
                                     unsigned int seed);
extern "C" void __cdecl GetDXVersion(unsigned long* version, unsigned long* platform);
extern int debugActions;
extern int do_draw_log;
extern char draw_log_name[260];
extern FILE* draw_log;
extern int do_fps_log;
extern FILE* fps_log;
int RGE_Base_Game::setup()
{
    unsigned long directx_version;
    unsigned long directx_platform;
    int game_speed_setting;
    MEMORYSTATUS ms;
    char filename[260];
    char s[256];
    OFSTRUCT of;
    _finddata_t file_info;
    debug_srand("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x20A,
                debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x20A));

    int screen_size = this->registry->RegGetInt(1, "Screen Size");
    switch (screen_size) {
    case 0x280:
            this->prog_info->main_wid = 0x280;
            this->prog_info->main_hgt = 0x1E0;
        break;
    case 0x320:
            this->prog_info->main_wid = 0x320;
            this->prog_info->main_hgt = 0x258;
        break;
    case 0x400:
            this->prog_info->main_wid = 0x400;
            this->prog_info->main_hgt = 0x300;
        break;
    case 0x500:
            this->prog_info->main_wid = screen_size;
            this->prog_info->main_hgt = 0x400;
        break;
    }

    int rollover = this->registry->RegGetInt(1, "Rollover Text");
    if (rollover == 2)
        this->rollover = 0;
    else
        this->rollover = 1;

    int mouse_style = this->registry->RegGetInt(1, "Mouse Style");
    if (mouse_style == 2)
        this->prog_info->interface_style = 2;
    else if (mouse_style == 1)
        this->prog_info->interface_style = 1;

    game_speed_setting = this->registry->RegGetInt(1, "Game Speed");
    if (game_speed_setting != -1)
        this->game_speed = (float)game_speed_setting * 0.1f;

    int difficulty = this->registry->RegGetInt(1, "Difficulty");
    if (difficulty != -1)
        this->single_player_difficulty = difficulty;

    int path_finding = this->registry->RegGetInt(1, "Path Finding");
    if (path_finding >= 1 && path_finding <= 3)
        this->setPathFinding((unsigned char)(path_finding - 1));

    int mp_path_finding = this->registry->RegGetInt(1, "MP Path Finding");
    if (mp_path_finding >= 1 && mp_path_finding <= 3)
        this->setMpPathFinding((unsigned char)(mp_path_finding - 1));

    int scroll_speed = this->registry->RegGetInt(1, "Scroll Speed");
    if (scroll_speed != -1 && scroll_speed >= 10 && scroll_speed <= 200) {
        this->prog_info->mouse_scroll_interval = scroll_speed;
        this->prog_info->key_scroll_interval = scroll_speed;
    }

    if (_findfirst("empires.exe", &file_info) == -1) {
        this->error_code = 0x17;
    }
    else {
        if (!this->setup_cmd_options()) {
            this->error_code = 2;
        }
        else {
            StringTable = LoadLibraryA(this->string_dll_name);
            if (StringTable == 0) {
                this->error_code = 1;
            }
            else {
                GlobalMemoryStatus(&ms);
                if ((ms.dwTotalPageFile >= 0x1400000 &&
                     ms.dwTotalVirtual >= 0xA00000) ||
                    (ms.dwTotalPageFile >= 0xA00000 &&
                     ms.dwTotalVirtual >= 0x1400000) ||
                    ms.dwTotalVirtual >= 0x1E00000) {
                this->set_interface_messages();

                if (debugActions == 1)
                    actionFile = fopen("c:\\aoeact.txt", "w");

                if (this->prog_info->check_expiration != 0 &&
                    this->check_expiration() == 0) {
                    this->error_code = 3;
                }
                else if (this->prog_info->check_multi_copies != 0 &&
                         this->check_multi_copies() == 0) {
                    this->error_code = 4;
                }
                else if (this->check_prog_argument("NODXCHECK") == 0 &&
                         (GetDXVersion(&directx_version, &directx_platform),
                          directx_version < 0x501)) {
                    this->error_code = 0x14;
                }
                else {
                    SystemParametersInfoA(0x10, 0,
                                           &this->screen_saver_enabled, 0);
                    if (this->screen_saver_enabled != 0)
                        SystemParametersInfoA(0x11, 0, 0, 2);
                    SystemParametersInfoA(0x53, 0,
                                           &this->low_power_enabled, 0);
                    if (this->low_power_enabled != 0)
                        SystemParametersInfoA(0x55, 0, 0, 2);

                    this->save_check_for_cd = this->check_for_cd(0);
                    if (!this->setup_class())
                        this->error_code = 5;
                    else if (!this->setup_main_window())
                        this->error_code = 6;
                    else if (!this->setup_graphics_system()) {
                        if (this->error_code == 0)
                            this->error_code = 7;
                    }
                    else if (!this->setup_palette())
                        this->error_code = 0x11;
                    else if (!this->setup_shapes())
                        this->error_code = 7;
                    else if (!this->setup_map_save_area())
                        this->error_code = 7;
                    else if (!this->setup_mouse())
                        this->error_code = 8;
                    else if (!this->setup_sound_system())
                        this->error_code = 0x0A;
                    else if (!this->setup_chat())
                        this->error_code = 0x10;
                    else if (!this->setup_comm())
                        this->error_code = 9;
                    else if (!this->setup_fonts())
                        this->error_code = 0x0B;
                    else if (!this->setup_sounds())
                        this->error_code = 0x0C;
                    else {
                        driveInfo = new DriveInformation;
                        if (driveInfo != 0) {
                            if (!this->setup_blank_screen()) {
                                this->error_code = 0x0D;
                            }
                            else {
                            int file_number;
                            this->set_prog_mode(0);
                            this->setup_timings();
                            this->handle_size(this->prog_window, 0, 0, 0);
                            this->prog_ready = 1;
                            ShowWindow(this->prog_window, 5);
                            SetFocus(this->prog_window);
                            this->mouse_on();
                            this->is_timer = SetTimer(this->prog_window,
                                                      1, 0x32, 0);

                            file_number = this->registry->RegGetInt(
                                0, "Game File Number");
                            if (file_number >= 0) {
                                file_number = this->registry->RegGetInt(
                                    0, "Game File Number");
                                sprintf(filename, "game%d.nfo",
                                        file_number);
                                this->player_game_info =
                                    new RGE_Game_Info(filename);
                            }
                            else {
                                int i;
                                for (i = 0; i < 9999; ++i) {
                                    sprintf(filename, "game%d.nfo", i);
                                    if (_findfirst(
                                            filename, &file_info) == -1) {
                                        this->registry->RegSetInt(
                                            0, "Game File Number", i);
                                        this->player_game_info =
                                            new RGE_Game_Info(filename);
                                        break;
                                    }
                                }
                            }
                            sprintf(filename, "%sscenario.inf",
                                    this->prog_info->scenario_dir);
                            this->scenario_info = new RGE_Scenario_File_Info(
                                filename);

                            if (do_draw_log != 0) {
                                if (draw_log_name[0] == 0) {
                                    int i;
                                    for (i = 0; i < 1000; ++i) {
                                        sprintf(s, "drawlog%d.txt", i);
                                        if (OpenFile(s, &of,
                                                     0x4000) == -1) {
                                            draw_log = fopen(s, "w");
                                            strcpy(draw_log_name, s);
                                            break;
                                        }
                                    }
                                }
                                else {
                                    draw_log = fopen(draw_log_name, "w");
                                }
                            }

                            if (do_fps_log != 0) {
                                fps_log = fopen("c:\\fps.txt", "w");
                                if (fps_log == 0)
                                    do_fps_log = 0;
                            }

                                return 1;
                            }
                        }
                    }
                }
            }
            else {
                this->error_code = 0x16;
            }
        }
    }
    }
    return 0;
}






extern void __cdecl debug_random_write(void);
extern void __cdecl dump_vismap_log(void);
extern int do_debug_random;
extern int wrote_debug_random_log;
extern FILE* fps_log;
extern FILE* draw_log;












RGE_Base_Game::~RGE_Base_Game()
{
    int i;
    char filename[13];
    char str[256];

    if (do_debug_random && !wrote_debug_random_log) {
        debug_random_write();
        dump_vismap_log();
    }

    if (this->draw_system != 0) {
        this->registry->RegSetInt(1, "Screen Size", this->draw_system->ScreenWidth);
    }

    this->registry->RegSetInt(1, "Rollover Text",
        2 + (this->rollover ? -1 : 0));

    if (this->prog_info->interface_style == 2)
        this->registry->RegSetInt(1, "Mouse Style", 2);
    else
        this->registry->RegSetInt(1, "Mouse Style", 1);

    this->registry->RegSetInt(1, "Game Speed",
        (int)(this->game_speed * 10.0f));
    this->registry->RegSetInt(1, "Difficulty", this->single_player_difficulty);
    this->registry->RegSetInt(1, "Path Finding", this->pathFinding() + 1);
    this->registry->RegSetInt(1, "MP Path Finding", this->mpPathFinding() + 1);
    this->registry->RegSetInt(
        1, "Scroll Speed", this->prog_info->mouse_scroll_interval);

    if (actionFile != 0) {
        fclose(actionFile);
        actionFile = 0;
    }
    if (fps_log != 0) {
        fclose(fps_log);
        fps_log = 0;
    }
    if (draw_log != 0) {
        fclose(draw_log);
        draw_log = 0;
    }

    if (this->scenario_info != 0) {
        delete this->scenario_info;
        this->scenario_info = 0;
    }

    if (this->player_game_info != 0) {
        if (this->registry->RegGetInt(0, "Game File Number") >= 0) {
            int file_number = this->registry->RegGetInt(0, "Game File Number");
            sprintf(filename, "game%d.nfo", file_number);
            this->player_game_info->save(filename);
        }
        delete this->player_game_info;
        this->player_game_info = 0;
    }

    this->prog_mode = 0;
    if (this->world != 0) {
        delete this->world;
        this->world = 0;
    }

    if (this->map_save_area != 0) {
        delete this->map_save_area;
        this->map_save_area = 0;
    }
    if (this->mouse_pointer != 0) {
        delete this->mouse_pointer;
        this->mouse_pointer = 0;
    }

    if (driveInfo != 0) {
        delete driveInfo;
        driveInfo = 0;
    }

    if (this->comm_handler != 0) {
        delete this->comm_handler;
        this->comm_handler = 0;
    }
    if (chat != 0) {
        delete chat;
        chat = 0;
    }

    if (this->fonts != 0) {
        if (this->font_num > 0) {
            for (i = 0; i < this->font_num; i++) {
                if (this->fonts[i].font)
                    DeleteObject(this->fonts[i].font);
            }
        }
        free(this->fonts);
        this->fonts = 0;
    }

    this->stop_sound_system();
    panel_system.destroyPanel("Blank Screen");

    if (this->draw_system != 0) {
        delete this->draw_system;
        this->draw_system = 0;
        this->draw_area = 0;
    }

    if (this->screen_saver_enabled != 0)
        SystemParametersInfoA(0x11, 1, 0, 2);
    if (this->low_power_enabled != 0)
        SystemParametersInfoA(0x55, 1, 0, 2);

    if (this->prog_palette != 0) {
        panel_system.release_palette(this->prog_palette);
        this->prog_palette = 0;
    }

    if (this->registry != 0) {
        delete this->registry;
        this->registry = 0;
    }

    if (this->prog_mutex != 0) {
        CloseHandle(this->prog_mutex);
        this->prog_mutex = 0;
    }

    rge_base_game = 0;

    if (this->prog_window != 0)
        DestroyWindow(this->prog_window);

    this->get_string(0x3EB, str, 0x100);
    if (str[0] != 0) {
        HWND help_window = FindWindowA("MS_WINHELP", str);
        if (help_window != 0)
            SendMessageA(help_window, 0x10, 0, 0);
    }

    if (StringTable != 0 && StringTable != this->prog_info->instance) {
        FreeLibrary(StringTable);
        StringTable = 0;
    }

    if (this->debugLog != 0) {
        delete this->debugLog;
        this->debugLog = 0;
    }

    if (this->shapes != 0) {
        for (i = 0; i < this->shape_num; ++i) {
            TShape* shape = this->shapes[i];
            if (shape != 0) {
                delete shape;
            }
        }
        free(this->shapes);
    }
}


void RGE_Base_Game::reset_timings() {
    this->frame_count = 0;
    this->world_update_count = 0;
    this->view_update_count = 0;
    this->last_frame_count = 0;
    this->last_world_update_count = 0;
    this->last_view_update_count = 0;
    this->fps = 0;
    this->world_update_fps = 0;
    this->view_update_fps = 0;

    for (int i = 0; i < 30; ++i) {
        this->timings[i].accum_time = 0;
        this->timings[i].last_time = 0;
        this->timings[i].start_time = 0;
        this->timings[i].last_single_time = 0;
        this->timings[i].max_time = 0;
        this->timings[i].last_max_time = 0;
    }
}




void RGE_Base_Game::add_to_timing(int index, unsigned long value) {
    timings[index].accum_time += value;
    timings[index].last_single_time = value;
    if (value > timings[index].max_time) {
        timings[index].max_time = value;
    }
}


void RGE_Base_Game::increment_world_update_count() {
    this->world_update_count++;
}


void RGE_Base_Game::increment_view_update_count() {
    this->view_update_count++;
}


void RGE_Base_Game::set_last_single_time(int i, unsigned long v) {
    this->timings[i].last_single_time = v;
}


unsigned long RGE_Base_Game::get_last_time(int i) {
    return this->timings[i].last_time;
}


unsigned long RGE_Base_Game::get_last_single_time(int i) {
    return this->timings[i].last_single_time;
}


unsigned long RGE_Base_Game::get_accum_time(int i) {
    return this->timings[i].accum_time;
}


unsigned long RGE_Base_Game::get_max_time(int i) {
    return this->timings[i].max_time;
}


unsigned long RGE_Base_Game::get_last_max_time(int i) {
    return this->timings[i].last_max_time;
}


unsigned long RGE_Base_Game::get_last_world_update_count() {
    return this->last_world_update_count;
}


unsigned long RGE_Base_Game::get_last_view_update_count() {
    return this->last_view_update_count;
}


unsigned long RGE_Base_Game::get_world_update_count() {
    return this->world_update_count;
}


unsigned long RGE_Base_Game::get_view_update_count() {
    return this->view_update_count;
}


int RGE_Base_Game::get_error_code() {
    return this->error_code;
}


static char g_string_buffer[0x200];

char* RGE_Base_Game::get_string(long id)
{
    this->get_string(id, g_string_buffer, 0x200);
    return g_string_buffer;
}


char* RGE_Base_Game::get_string(long string_id, char* buffer, int buffer_size) {
    int result = LoadStringA(StringTable, string_id, buffer, buffer_size);
    if (!result) {
        *buffer = 0;
    }
    buffer[buffer_size - 1] = 0;
    return buffer;
}


char* RGE_Base_Game::get_string(int p1, long p2, char* buf, int maxlen)
{
    return this->get_string2(p1, p2, 0, buf, maxlen);
}




char* RGE_Base_Game::get_string2(int param_1, long param_2, long param_3, char* param_4, int param_5)
{
    *param_4 = 0;

    switch (param_1) {
    case 1:
        switch (param_2) {
        case 1: case 2: case 3: case 4: case 5: case 6:
        case 0x0E: case 0x0F:
            return this->get_string(0x7D2, param_4, param_5);
        case 7: case 8: case 0x0B: case 0x0D: case 0x11:
            return this->get_string(0x7D3, param_4, param_5);
        case 0x13:
            return this->get_string(0x7DB, param_4, param_5);
        case 9: case 0x10:
            return this->get_string(0x7D5, param_4, param_5);
        case 0x0A: case 0x0C:
            return this->get_string(0x7D4, param_4, param_5);
        case 0x12:
            return this->get_string(0x7DC, param_4, param_5);
        case 0x14:
            return this->get_string(0x7DD, param_4, param_5);
        case 0x15:
            return this->get_string(0x7DE, param_4, param_5);
        case 0x16:
            return this->get_string(0x7DF, param_4, param_5);
        case 0x17:
            return this->get_string(0x7E0, param_4, param_5);
        default:
            break;
        }
        break;
    case 2:
        return this->get_string(param_2, param_4, param_5);
    default:
        break;
    }

    param_4[param_5 - 1] = 0;
    return param_4;
}



extern int rge_open(char* path, int flags);
extern void rge_read_uncompressed(int fd, void* buf, int len);
extern void rge_read(int fd, void* buf, int len);
extern int rge_close(int fd);




RGE_Scenario* RGE_Base_Game::get_scenario_info(char* param1, int param2)
{
    char temp_name[300];
    int fd;
    int version;
    int obj_id;
    int header_size;
    RGE_Scenario* result;
    void* buf;

    sprintf(temp_name, "%s%s", this->prog_info->scenario_dir, param1);

    if (param2) {
        fd = this->player_game_info->open_scenario();
    } else {
        if (!param1)
            return 0;
        fd = rge_open(temp_name, 0x8000);
    }

    if (fd == -1)
        return 0;

    rge_read_uncompressed(fd, &obj_id, 4);
    rge_read_uncompressed(fd, &version, 4);

    if (version > 0) {
        buf = malloc(version);
        if (!buf) {
            rge_close(fd);
            return 0;
        }
        rge_read_uncompressed(fd, buf, version);
        free(buf);
    }

    rge_read(fd, &header_size, 4);

    result = this->new_scenario_info(fd);
    rge_close(fd);
    return result;
}



extern int rge_open(char* path, int flags);
extern void rge_read_uncompressed(int fd, void* buf, int len);
extern int rge_close(int fd);




RGE_Scenario_Header* RGE_Base_Game::get_scenario_header(char* param1, int param2)
{
    char temp_name[300];
    char version[4];
    int fd;
    RGE_Scenario_Header* result;

    sprintf(temp_name, "%s%s", this->prog_info->scenario_dir, param1);

    if (param2) {
        fd = this->player_game_info->open_scenario();
    } else {
        if (!param1)
            return 0;
        fd = rge_open(temp_name, 0x8000);
    }

    if (fd == -1)
        return 0;

    rge_read_uncompressed(fd, version, sizeof(version));

    result = 0;
    if (memcmp(version, "1.03", sizeof(version)) == 0 ||
        memcmp(version, "1.04", sizeof(version)) == 0 ||
        memcmp(version, "1.05", sizeof(version)) == 0 ||
        memcmp(version, "1.06", sizeof(version)) == 0 ||
        memcmp(version, "1.07", sizeof(version)) == 0 ||
        memcmp(version, "1.08", sizeof(version)) == 0 ||
        memcmp(version, "1.09", sizeof(version)) == 0 ||
        memcmp(version, "1.10", sizeof(version)) == 0 ||
        memcmp(version, "1.11", sizeof(version)) == 0)
    {
        result = this->new_scenario_header(fd);
    }

    rge_close(fd);
    return result;
}


void RGE_Base_Game::write_scenario_header(int file)
{
    RGE_Scenario_Header* header = new_scenario_header(world->scenario);

    if (header != 0) {
        header->save(file);
        delete header;
    } else {
        int header_size = 0;
        rge_write_uncompressed(file, &header_size, sizeof(header_size));
    }
}




RGE_Scenario_Header* RGE_Base_Game::new_scenario_header(int param_1) {
    return new RGE_Scenario_Header(param_1);
}



RGE_Scenario_Header* RGE_Base_Game::new_scenario_header(RGE_Scenario* param_1) {
    return new RGE_Scenario_Header(param_1);
}





RGE_Scenario* RGE_Base_Game::new_scenario_info(int param_1) {
    return new RGE_Scenario(param_1, 0);
}




void RGE_Base_Game::get_campaign_info(long& campaign, long& player, long& num_campaigns) {
    int c = this->player_game_info->get_current_campaign();
    campaign = c;
    int p = this->player_game_info->get_current_player();
    player = p;
    int n = this->player_game_info->get_current_scenario();
    num_campaigns = n;
}


unsigned char RGE_Base_Game::set_campaign_info(long campaign, long person, long scenario) {
    unsigned char ok;

    ok = this->player_game_info->set_current_campaign(campaign);
    if (ok != 0) {
        ok = this->player_game_info->set_current_person(person);
        if (ok != 0) {
            ok = this->player_game_info->set_current_scenario(scenario);
            if (ok != 0) {
                return 1;
            }
        }
    }
    return 0;
}


void RGE_Base_Game::set_campaign_win() {
    this->player_game_info->notify_of_scenario_complete();
}



int RGE_Base_Game::run()
{
    MSG msg;

    while (1) {
        if (this->prog_active != 0 && (this->prog_mode == 4 || this->prog_mode == 2)) {
            TCommunications_Handler* comm = this->comm_handler;
            if (comm == 0 || comm->IsPaused() == 0) {
                if (PeekMessageA(&msg, 0, 0, 0, PM_NOREMOVE) != 0) {
                    if (msg.message == WM_QUIT) {
                        return (int)msg.wParam;
                    }
                    if (this->handle_message(&msg) != 0) {
                        TranslateMessage(&msg);
                        DispatchMessageA(&msg);
                    }
                } else {
                    this->handle_idle();
                }
                continue;
            }
        }

        if (GetMessageA(&msg, 0, 0, 0) == 0) {
            return (int)msg.wParam;
        }
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }
}



extern "C" {
char* __cdecl _mbsstr(const char* str, const char* substr);
char* __cdecl _mbsninc(const char* str, unsigned int count);
int __cdecl _ismbcspace(unsigned int c);
char* __cdecl _mbsncat(char* dst, const char* src, unsigned int count);
}

extern "C" {
extern int do_run_log;
extern int do_debug_timeGetTime;
extern int debug_timeGetTime_interval;
extern int startLoggingAI;
extern int chatCheatCodes;
extern int logUpdateChanges;
extern int useInfluencePlacement;
extern int all_grassland_on;
extern int numberPathingIterations;
extern int useNewPathing;
extern int pathingCapValue;
extern int force_cd;
extern int do_fps_log;
extern int Sys_DDLOG_Enable;
extern int Sys_DDLOG_ErrorOn;
extern int DDlogAutoFlush;
extern int debug_log_lock;
extern int do_debug_random;
extern int debugActions;
extern int resend_adj1;
extern int resend_adj2;
extern int specificAIPlayerToLog;
extern int logDebugID;
extern int speed_val1;
extern int speed_val2;
extern int do_draw_log;
extern int safe_draw_log;
extern char draw_log_name[260];
extern int log_output;
extern int DDSys_CanColorFill;
extern unsigned char do_color_log;
}

int RGE_Base_Game::setup_cmd_options()
{
    char cmdLine[256];
    char tempStr[256];
    char cVar1;
    char* pcVar3;

    strncpy(cmdLine, this->prog_info->cmd_line, 0xFF);
    cmdLine[0xFF] = 0;
    CharUpperA(cmdLine);

    if ((strstr(cmdLine, "NOSTARTUP") != 0) || (strstr(cmdLine, "NO STARTUP") != 0) || (strstr(cmdLine, "NO_STARTUP") != 0)) {
        this->prog_info->skip_startup = 1;
    }

    if ((strstr(cmdLine, "SYSTEMMEMORY") != 0) || (strstr(cmdLine, "SYSTEM MEMORY") != 0) || (strstr(cmdLine, "SYSTEM_MEMORY") != 0)) {
        this->prog_info->use_sys_mem = 1;
    }

    if ((strstr(cmdLine, "MIDIMUSIC") != 0) || (strstr(cmdLine, "MIDI MUSIC") != 0) || (strstr(cmdLine, "MIDI_MUSIC") != 0)) {
        this->prog_info->use_music = 1;
        this->prog_info->use_cd_audio = 0;
        this->prog_info->use_ima = 0;
        this->prog_info->use_midi = 1;
        this->prog_info->use_wave_music = 0;
    }

    if (strstr(cmdLine, "MSYNC") != 0) {
        this->mouse_blit_sync = 1;
    }

    DDSys_CanColorFill = (strstr(cmdLine, "MFILL") == 0);

    if ((strstr(cmdLine, "NOSOUND") != 0) || (strstr(cmdLine, "NO SOUND") != 0) || (strstr(cmdLine, "NO_SOUND") != 0)) {
        this->prog_info->use_sound = 0;
    }

    if (strstr(cmdLine, "640") != 0) {
        this->prog_info->main_wid = 0x280;
        this->prog_info->main_hgt = 0x1E0;
    }

    if (strstr(cmdLine, "800") != 0) {
        this->prog_info->main_wid = 800;
        this->prog_info->main_hgt = 600;
    }

    if (strstr(cmdLine, "1024") != 0) {
        this->prog_info->main_wid = 0x400;
        this->prog_info->main_hgt = 0x300;
    }

    if (strstr(cmdLine, "ALLCP") != 0) {
        all_cp = 1;
        do_run_log = 1;
        this->comm_speed = 0;
        do_debug_timeGetTime = 1;
        debug_timeGetTime_interval = 10;
        do_fixed_update = 1;
        fixed_update_time = 20;
    }

    pcVar3 = _mbsstr(cmdLine, "RESEND1");
    if (pcVar3) {
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        tempStr[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(tempStr, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
        resend_adj1 = atol(tempStr);
    }

    pcVar3 = _mbsstr(cmdLine, "RESEND2");
    if (pcVar3) {
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        tempStr[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(tempStr, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
        resend_adj2 = atol(tempStr);
    }

    if ((strstr(cmdLine, "NOMOUSE") != 0) || (strstr(cmdLine, "NO_MOUSE") != 0)) {
        this->custom_mouse = 0;
    }

    if (strstr(cmdLine, "WING") != 0) {
        this->prog_info->full_screen = 0;
        this->prog_info->use_dir_draw = 0;
    }

    if ((strstr(cmdLine, "DIRECTDRAW") != 0) || (strstr(cmdLine, "DIRECT DRAW") != 0)) {
        this->prog_info->use_dir_draw = 1;
    }

    if ((strstr(cmdLine, "FULLSCREEN") != 0) || (strstr(cmdLine, "FULL SCREEN") != 0) || (strstr(cmdLine, "FULL_SCREEN") != 0)) {
        this->prog_info->full_screen = 1;
        this->prog_info->use_dir_draw = 1;
    }

    if ((strstr(cmdLine, "VIDEOMEMORY") != 0) || (strstr(cmdLine, "VIDEO MEMORY") != 0) || (strstr(cmdLine, "VIDEO_MEMORY") != 0)) {
        this->prog_info->use_sys_mem = 0;
    }

    if ((strstr(cmdLine, "STREAMMUSIC") != 0) || (strstr(cmdLine, "STREAM MUSIC") != 0) || (strstr(cmdLine, "STREAM_MUSIC") != 0)) {
        this->prog_info->use_music = 1;
        this->prog_info->use_cd_audio = 0;
        this->prog_info->use_ima = 0;
        this->prog_info->use_midi = 0;
        this->prog_info->use_wave_music = 1;
    }

    if ((strstr(cmdLine, "IMAMUSIC") != 0) || (strstr(cmdLine, "IMA MUSIC") != 0) || (strstr(cmdLine, "IMA_MUSIC") != 0)) {
        this->prog_info->use_music = 1;
        this->prog_info->use_cd_audio = 0;
        this->prog_info->use_ima = 1;
        this->prog_info->use_midi = 0;
        this->prog_info->use_wave_music = 0;
    }

    if ((strstr(cmdLine, "FASTVIEW") != 0) || (strstr(cmdLine, "FAST VIEW") != 0) || (strstr(cmdLine, "FAST_VIEW") != 0)) {
        this->prog_info->fast_view = 1;
    }

    if ((strstr(cmdLine, "SLOWVIEW") != 0) || (strstr(cmdLine, "SLOW VIEW") != 0) || (strstr(cmdLine, "SLOW_VIEW") != 0)) {
        this->prog_info->fast_view = 0;
    }

    if ((strstr(cmdLine, "ONEBUTTON") != 0) || (strstr(cmdLine, "ONE BUTTON") != 0) || (strstr(cmdLine, "ONE_BUTTON") != 0)) {
        this->prog_info->interface_style = 1;
    }

    if ((strstr(cmdLine, "TWOBUTTON") != 0) || (strstr(cmdLine, "TWO BUTTON") != 0) || (strstr(cmdLine, "TWO_BUTTON") != 0)) {
        this->prog_info->interface_style = 2;
    }

    if (strstr(cmdLine, "RUNLOG")) {
        do_run_log = 1;
    }

    if (strstr(cmdLine, "SYNCMSG")) {
        this->comm_syncmsg = 1;
    }

    if (strstr(cmdLine, "DROPPACKETS")) {
        this->comm_droppackets = 1;
    }

    if (strstr(cmdLine, "NOCOMMSPEED")) {
        this->comm_speed = 0;
    }

    if (strstr(cmdLine, "SYNCSTOP")) {
        this->comm_syncstop = 1;
    }

    if (strstr(cmdLine, "STEPMODE")) {
        this->comm_stepmode = 1;
    }

    if ((strstr(cmdLine, "SQUAREOUTLINE") != 0) || (strstr(cmdLine, "SQUARE OUTLINE") != 0) || (strstr(cmdLine, "SQUARE_OUTLINE") != 0)) {
        this->outline_type = 0;
    }

    if ((strstr(cmdLine, "CUBEOUTLINE") != 0) || (strstr(cmdLine, "CUBE OUTLINE") != 0) || (strstr(cmdLine, "CUBE_OUTLINE") != 0)) {
        this->outline_type = 1;
    }

    if ((strstr(cmdLine, "GROUNDOUTLINE") != 0) || (strstr(cmdLine, "GROUND OUTLINE") != 0) || (strstr(cmdLine, "GROUND_OUTLINE") != 0)) {
        this->outline_type = 2;
    }

    if ((strstr(cmdLine, "EDGEOUTLINE") != 0) || (strstr(cmdLine, "EDGE OUTLINE") != 0) || (strstr(cmdLine, "EDGE_OUTLINE") != 0)) {
        this->outline_type = 3;
    }

    if ((strstr(cmdLine, "CUSTOMMOUSE") != 0) || (strstr(cmdLine, "CUSTOM MOUSE") != 0) || (strstr(cmdLine, "CUSTOM_MOUSE") != 0)) {
        this->custom_mouse = 1;
    }

    if (strstr(cmdLine, "NOCP")) {
        useComputerPlayers = 0;
    }

    if (strstr(cmdLine, "LOGAI")) {
        startLoggingAI = 1;
    }

    if (strstr(cmdLine, "NOLOGSTATUS")) {
        logStatusOn = 0;
    }

    if (strstr(cmdLine, "DOLOGSTATUS")) {
        logStatusOn = 1;
    }

    if (strstr(cmdLine, "NOAICHEAT")) {
        allowAIToCheat = 0;
    }

    if (strstr(cmdLine, "NOCHATCHEATCODES")) {
        chatCheatCodes = 0;
    }

    if (strstr(cmdLine, "LOGUPDATECHANGES")) {
        logUpdateChanges = 1;
    }

    if (strstr(cmdLine, "UIP")) {
        useInfluencePlacement = 1;
    }

    if (strstr(cmdLine, "ALLGRASS")) {
        all_grassland_on = 1;
    }

    if (strstr(cmdLine, "ALLCP")) {
        all_cp = 1;
    }

    if (strstr(cmdLine, "ALLCP1")) {
        all_cp = 2;
    }

    if (strstr(cmdLine, "NOPATHLIMIT")) {
        numberPathingIterations = -1;
    }

    if (strstr(cmdLine, "UNP")) {
        useNewPathing = -1;
    }

    if (strstr(cmdLine, "COLORLOG")) {
        do_color_log = 1;
    }

    pcVar3 = _mbsstr(cmdLine, "LOGAI");
    if (pcVar3) {
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        tempStr[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(tempStr, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
        specificAIPlayerToLog = atol(tempStr);
    }

    pcVar3 = _mbsstr(cmdLine, "LOGDEBUG");
    if (pcVar3) {
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        tempStr[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(tempStr, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
        logDebugID = atol(tempStr);
    }

    if (strstr(cmdLine, "NOPATHCAP")) {
        pathingCapValue = -1;
    }

    if (strstr(cmdLine, "GAMECD")) {
        force_cd = 1;
    }

    if (strstr(cmdLine, "1280")) {
        this->prog_info->main_wid = 0x500;
        this->prog_info->main_hgt = 0x400;
    }

    if ((strstr(cmdLine, "LOGFPS") != 0) || (strstr(cmdLine, "LOG FPS") != 0) || (strstr(cmdLine, "LOG_FPS") != 0)) {
        do_fps_log = 1;
    }

    if (strstr(cmdLine, "DDERRORLOG")) {
        Sys_DDLOG_Enable = 1;
        Sys_DDLOG_ErrorOn = 1;
    }

    if (strstr(cmdLine, "DDLOG")) {
        Sys_DDLOG_Enable = 1;
        Sys_DDLOG_ErrorOn = 0;
    }

    if (strstr(cmdLine, "DDFLUSHLOG")) {
        DDlogAutoFlush = 1;
    }

    if (strstr(cmdLine, "DDNOFLUSHLOG")) {
        DDlogAutoFlush = 0;
    }

    if (strstr(cmdLine, "DDLOCKLOG")) {
        debug_log_lock = 1;
    }

    if (strstr(cmdLine, "LOGRANDOM")) {
        do_debug_random = 1;
    }

    if (strstr(cmdLine, "FIXEDUPDATE")) {
        do_debug_timeGetTime = 1;
        do_fixed_update = 1;
    }

    if (strstr(cmdLine, "LOGACTION")) {
        debugActions = 1;
    }

    if (strstr(cmdLine, "RES_WARN")) {
        RESFILE_Set_Missing_Flag(1);
    }

    pcVar3 = _mbsstr(cmdLine, "SCENARIOS");
    if (pcVar3) {
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        this->prog_info->scenario_dir[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(this->prog_info->scenario_dir, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
        _mbsncat(this->prog_info->scenario_dir, "\\", 1);
    }

    pcVar3 = _mbsstr(cmdLine, "WORLD");
    if (pcVar3) {
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        this->prog_info->world_db_file[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(this->prog_info->world_db_file, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
    }

    pcVar3 = _mbsstr(cmdLine, "FIXEDUPDATE");
    if (pcVar3) {
        do_debug_timeGetTime = 1;
        do_fixed_update = 1;
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        tempStr[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(tempStr, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
        fixed_update_time = atol(tempStr);
    }

    pcVar3 = _mbsstr(cmdLine, "AISPEED");
    if (pcVar3) {
        do_debug_timeGetTime = 1;
        do_fixed_update = 1;
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        tempStr[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(tempStr, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
        debug_timeGetTime_interval = atol(tempStr);
    }

    pcVar3 = _mbsstr(cmdLine, "RANDOMGAME");
    if (pcVar3) {
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        tempStr[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(tempStr, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
        this->random_game_seed = atol(tempStr);
    }

    pcVar3 = _mbsstr(cmdLine, "RANDOMMAP");
    if (pcVar3) {
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        tempStr[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(tempStr, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
        this->random_map_seed = atol(tempStr);
    }

    pcVar3 = _mbsstr(cmdLine, "DRAWLOG");
    if (pcVar3) {
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        draw_log_name[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(draw_log_name, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
    }

    if (strstr(cmdLine, "DRAWLOG")) {
        do_draw_log = 1;
    }

    if (strstr(cmdLine, "SAFEDRAWLOG")) {
        safe_draw_log = 1;
    }

    pcVar3 = _mbsstr(cmdLine, "DATA");
    if (pcVar3) {
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        this->prog_info->game_data_file[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(this->prog_info->game_data_file, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
    }

    if ((strstr(cmdLine, "CDAUDIO") != 0) || (strstr(cmdLine, "CD AUDIO") != 0) || (strstr(cmdLine, "CD_AUDIO") != 0)) {
        this->prog_info->use_music = 1;
        this->prog_info->use_cd_audio = 1;
        this->prog_info->use_ima = 0;
        this->prog_info->use_midi = 0;
        this->prog_info->use_wave_music = 0;
    }

    if (strstr(cmdLine, "WINDOW")) {
        this->prog_info->full_screen = 0;
    }

    if ((strstr(cmdLine, "FILEFIRST") != 0) || (strstr(cmdLine, "FILE FIRST") != 0) || (strstr(cmdLine, "FILE_FIRST") != 0)) {
        shape_file_first = 1;
        sound_file_first = 1;
    }

    if (((strstr(cmdLine, "LOGCOMM") != 0) || (strstr(cmdLine, "LOG COMM") != 0) || (strstr(cmdLine, "LOG_COMM") != 0)) &&
        (this->log_comm = 1, L != 0)) {
        L->LogFile(1);
        L->LogTimestamp(1);
    }

    if (((strstr(cmdLine, "LOGOUTPUT") != 0) || (strstr(cmdLine, "LOG OUTPUT") != 0) || (strstr(cmdLine, "LOG_OUTPUT") != 0)) &&
        (log_output = 1, L != 0)) {
        L->LogOutput(1);
    }

    if (strstr(cmdLine, "DEVELOPER")) {
        this->setGameDeveloperMode(1);
    }

    pcVar3 = _mbsstr(cmdLine, "SPEED1");
    if (pcVar3) {
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        tempStr[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(tempStr, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
        speed_val1 = atol(tempStr);
    }

    pcVar3 = _mbsstr(cmdLine, "SPEED2");
    if (pcVar3) {
        cVar1 = *pcVar3;
        while (cVar1 != '=') {
            pcVar3 = _mbsninc(pcVar3, 1);
            cVar1 = *pcVar3;
        }
        pcVar3 = _mbsninc(pcVar3, 1);
        tempStr[0] = 0;
        while (!_ismbcspace((unsigned char)*pcVar3) && *pcVar3 != 0) {
            _mbsncat(tempStr, pcVar3, 1);
            pcVar3 = _mbsninc(pcVar3, 1);
        }
        speed_val2 = atol(tempStr);
    }

    if (this->prog_info->use_sound == 0 ||
        strstr(cmdLine, "NOMUSIC") != 0 ||
        strstr(cmdLine, "NO MUSIC") != 0 ||
        strstr(cmdLine, "NO_MUSIC") != 0) {
        this->prog_info->use_music = 0;
    }

    if (this->prog_info->use_dir_draw == 1 && this->prog_info->full_screen == 1) {
        this->custom_mouse = 1;
    }

    if ((strstr(cmdLine, "NORMALMOUSE") != 0) || (strstr(cmdLine, "NORMAL MOUSE") != 0) || (strstr(cmdLine, "NORMAL_MOUSE") != 0)) {
        this->custom_mouse = 0;
    }

    return 1;
}


int RGE_Base_Game::setup_class() {
    if (prog_info->prev_instance != 0) {
        return 1;
    }

    WNDCLASSA cls;
    cls.hCursor = 0;
    cls.lpszMenuName = prog_info->menu_name[0] ? prog_info->menu_name : 0;
    cls.hIcon = LoadIconA(prog_info->instance, prog_info->icon_name);
    cls.lpszClassName = prog_info->prog_name;
    cls.hbrBackground = 0;

    cls.hInstance = static_cast<HINSTANCE>(prog_info->instance);
    cls.style = 0x0B;
    cls.lpfnWndProc = rge_base_game_wnd_proc;
    cls.cbWndExtra = 0;
    cls.cbClsExtra = 0;

    return RegisterClassA(&cls) != 0;
}



int RGE_Base_Game::setup_main_window()
{
    int screen_width = GetSystemMetrics(0);
    int screen_height = GetSystemMetrics(1);
    RECT win_rect;
    RECT client_rect;

    if (this->prog_info->full_screen == 0 &&
        (screen_width != this->prog_info->main_wid ||
         screen_height != this->prog_info->main_hgt)) {
        this->prog_window = CreateWindowExA(
            0, this->prog_info->prog_name, this->prog_info->prog_title,
            0x02CA0000, 0, 0,
            this->prog_info->main_wid, this->prog_info->main_hgt,
            0, 0, this->prog_info->instance, 0);
    }
    else {
        this->prog_window = CreateWindowExA(
            0, this->prog_info->prog_name, this->prog_info->prog_title,
            0x82080000, 0, 0, screen_width, screen_height,
            0, 0, this->prog_info->instance, 0);
    }

    if (this->prog_window == 0)
        return 0;

    GetWindowRect(this->prog_window, &win_rect);
    GetClientRect(this->prog_window, &client_rect);

    if (client_rect.right != this->prog_info->main_wid ||
        client_rect.bottom != this->prog_info->main_hgt) {
        SetWindowPos(
            this->prog_window, 0, win_rect.left, win_rect.top,
            (win_rect.right - win_rect.left) - client_rect.right +
                this->prog_info->main_wid,
            (win_rect.bottom - win_rect.top) - client_rect.bottom +
                this->prog_info->main_hgt,
            0);
    }

    if (this->prog_info->full_screen != 0) {
        ShowWindow(this->prog_window, this->prog_info->show_wnd_flag);
        UpdateWindow(this->prog_window);
        SetFocus(this->prog_window);
    }

    AppWnd = this->prog_window;
    panel_system.DisableIME();
    return 1;
}








int RGE_Base_Game::setup_graphics_system()
{
    TDrawSystem* draw_system;

    if (this->prog_info->use_dir_draw != 0) {
        HDC dc = GetDC(0);
        int bits = GetDeviceCaps(dc, 0x0C);
        ReleaseDC(0, dc);
        if (bits < 8) {
            this->error_code = 0x13;
            return 0;
        }
    }

    char draw_mode;
    char draw_type;
    int use_sys_mem;

    draw_type = (this->prog_info->use_dir_draw != 0) + 1;
    draw_mode = (this->prog_info->full_screen != 0) + 1;
    use_sys_mem = this->prog_info->use_sys_mem != 0;

    draw_system = new TDrawSystem;
    this->draw_system = draw_system;
    if (draw_system == 0)
        return 0;

    draw_system->CheckAvailModes(this->prog_info->full_screen);

    if (!this->draw_system->IsModeAvail(this->prog_info->main_wid, 0, 8)) {
        if (this->prog_info->main_wid != 0x280) {
            if (this->draw_system->IsModeAvail(0x280, 0, 8)) {
                this->prog_info->main_wid = 0x280;
                this->prog_info->main_hgt = 0x1E0;
                goto init_step;
            }
        }

        if (this->prog_info->main_wid != 800) {
            if (this->draw_system->IsModeAvail(800, 0, 8)) {
                this->prog_info->main_wid = 800;
                this->prog_info->main_hgt = 600;
                goto init_step;
            }
        }

        if (this->prog_info->main_wid != 0x400) {
            if (this->draw_system->IsModeAvail(0x400, 0, 8)) {
                this->prog_info->main_wid = 0x400;
                this->prog_info->main_hgt = 0x300;
                goto init_step;
            }
        }

        if (this->prog_info->main_wid == 0x500)
            goto init_fail;

        if (!this->draw_system->IsModeAvail(0x400, 0, 8))
            goto init_fail;

        this->prog_info->main_wid = 0x500;
        this->prog_info->main_hgt = 0x400;
    }

init_step:
    if (this->draw_system->Init(
            this->prog_info->instance,
            this->prog_window,
            this->prog_palette,
            draw_type,
            draw_mode,
            this->prog_info->main_wid,
            this->prog_info->main_hgt,
            use_sys_mem) == 0)
        goto init_fail;

    panel_system.release_palette(this->prog_palette);
    this->prog_palette = static_cast<HPALETTE>(panel_system.get_palette(
        this->prog_info->pal_file, 0xC544));

    this->draw_area = this->draw_system->DrawArea;
    this->draw_area->Clear(0, 0);
    this->draw_system->Paint(0);

    return 1;

init_fail:
    return 0;
}





int RGE_Base_Game::setup_palette()
{
    HPALETTE result = static_cast<HPALETTE>(
        panel_system.get_palette(this->prog_info->pal_file, 0xC544));
    this->prog_palette = result;
    return result != 0;
}






int RGE_Base_Game::setup_mouse()
{
    register int result;
    int custom_type;
    TMousePointer* mouse_pointer;

    result = this->registry->RegGetInt(0, "Custom Mouse");
    if (result == -1) {
        this->registry->RegSetInt(0, "Custom Mouse", 0);
        custom_type = 0;
    }
    else if (result == 1) {
        custom_type = result;
    }
    else if (result == 2) {
        this->custom_mouse = 0;
    }
    else {
        custom_type = 0;
    }

    mouse_pointer = new TMousePointer(custom_type);
    this->mouse_pointer = mouse_pointer;
    if (mouse_pointer == 0)
        return 0;

    if (mouse_pointer->setup(this->custom_mouse, this->draw_area,
                             this->prog_info->cursor_file,
                             0xC738, 10) == 0)
        return 0;

    this->mouse_off();
    return 1;
}

int RGE_Base_Game::setup_chat() {
    TChat* new_chat;

    new_chat = new TChat(this->prog_window);
    chat = new_chat;
    return new_chat != 0;
}

int RGE_Base_Game::setup_registry()
{
    TRegistry* reg = new TRegistry(this->prog_info->registry_key);
    this->registry = reg;
    return reg != 0;
}


extern int log_output;



int RGE_Base_Game::setup_debugging_log()
{
    TDebuggingLog* log = new TDebuggingLog;
    debugLog = log;
    if (log == 0)
        return 0;

    log->LogFile(log_comm);
    debugLog->LogOutput(log_output);
    debugLog->LogTimestamp(1);
    return 1;
}


extern int speed_val1;
extern int speed_val2;

int RGE_Base_Game::setup_comm()
{
    TCommunications_Handler* new_comm;

    new_comm = new TCommunications_Handler(
        this->prog_window,
        (unsigned char)this->prog_info->max_players,
        chat,
        this->prog_info->game_guid);
    this->comm_handler = new_comm;

    if (new_comm == 0)
        return 0;

    new_comm->StopIfSyncFail(this->comm_syncstop);
    this->comm_handler->ShowSyncChatMsgs(this->comm_syncmsg);
    this->comm_handler->SetStepMode(this->comm_stepmode);
    this->comm_handler->SetSpeedControl(this->comm_speed);
    this->comm_handler->DropPacketsIntentionally(this->comm_droppackets);
    comm = this->comm_handler;

    if (this->world != 0)
        this->world->reset_communications(this->comm_handler);

    if (speed_val1 != 0)
        this->comm_handler->SetSpeedV1(speed_val1);
    if (speed_val2 != 0)
        this->comm_handler->SetSpeedV1(speed_val2);

    return 1;
}

int RGE_Base_Game::reset_comm() {
    if (comm_handler != 0) {
        delete comm_handler;
        comm_handler = 0;
        comm = 0;
    }
    return setup_comm();
}
int RGE_Base_Game::setup_sound_system()
{
    if (this->prog_info->use_sound != 0) {
        TSound_Driver* driver = new TSound_Driver(this->prog_window, this->prog_info->sounds_dir);
        this->sound_system = driver;
        if (driver != 0 && driver->driver_active() == 0) {
            if (this->sound_system != 0) {
                delete this->sound_system;
            }
            this->sound_system = 0;
            return 1;
        }
        sound_driver = this->sound_system;
        int volume = 0;
        int result = this->registry->RegGetInt(1, "Sound Volume");
        if (result != -1) {
            volume = -result;
        }
        this->sound_system->set_volume(volume, 1);
    }
    this->setup_music_system();
    return 1;
}







int RGE_Base_Game::setup_music_system()
{
    if (this->prog_info->use_music != 0) {
        int volume = -5000;
        int result = this->registry->RegGetInt(1, "Music Volume");
        if (result != -1)
            volume = -result;

        if (volume <= -0x26AC) {
            this->prog_info->use_music = 0;
            TMusic_System* music = this->music_system;
            if (music != 0) {
                delete music;
                this->music_system = 0;
            }
        }
        else if (this->music_system == 0) {
            unsigned char music_type;
            char music_path[260];

            if (this->prog_info->use_cd_audio != 0)
                music_type = 1;
            else if (this->prog_info->use_midi != 0)
                music_type = 2;
            else if (this->prog_info->use_ima != 0)
                music_type = 4;
            else {
                if (this->prog_info->use_wave_music != 0)
                    music_type = 3;
                else
                    music_type = 1;
            }

            sprintf(music_path, "%s\\%s", this->work_dir,
                    this->prog_info->sounds_dir);

            TMusic_System* music_system =
                new TMusic_System(music_type, this->prog_info->instance, this->prog_window,
                                  this->sound_system, music_path);
            this->music_system = music_system;

            if (music_system != 0 && music_type == 1 &&
                this->prog_info->use_cd_audio == 0) {
                if (music_system->device_open == 0 ||
                    music_system->track_count < 2) {
                    if (music_system->set_music_type(2) == 0)
                        this->music_system->set_music_type(3);
                }
            }

            if (this->music_system != 0)
                this->music_system->set_volume(volume, 1);
        }
    }

    return 1;
}


int RGE_Base_Game::setup_shapes()
{
    TShape* shape;
    TShape** shape_array;
    int i;

    this->shape_num = 3;
    shape_array = static_cast<TShape**>(calloc(3, sizeof(*shape_array)));
    this->shapes = shape_array;
    if (shape_array == 0)
        return 0;

    for (i = 0; i < this->shape_num; ++i)
        this->shapes[i] = 0;

    shape = new TShape("groupnum.shp", 0xC4E3);
    this->shapes[0] = shape;

    shape = new TShape("waypoint.shp", 0xC4E4);
    this->shapes[1] = shape;

    shape = new TShape("moveto.shp", 0xC4E5);
    this->shapes[2] = shape;

    return 1;
}


int RGE_Base_Game::setup_sounds()
{
    TDigital* sound;
    int i;

    this->sound_num = 3;
    this->sounds = static_cast<TDigital**>(calloc(3, sizeof(*this->sounds)));
    if (this->sounds == 0)
        return 0;

    for (i = 0; i < this->sound_num; ++i)
        this->sounds[i] = 0;

    sound = new TDigital(this->sound_system, "button1.wav", 0xC47C);
    this->sounds[0] = sound;

    sound = new TDigital(this->sound_system, "button2.wav", 0xC47D);
    this->sounds[1] = sound;

    sound = new TDigital(this->sound_system, "chatrcvd.wav", 0xC47E);
    this->sounds[2] = sound;

    i = 0;
    for (; i < this->sound_num; ++i) {
        if (this->sounds[i] != 0)
            this->sounds[i]->load(0, -1);
    }

    return 1;
}


int RGE_Base_Game::setup_fonts()
{
    RGE_Font* font_array;
    HDC dc;
    HGDIOBJ old_font;
    short i;
    HFONT font;
    int font_index;
    TEXTMETRICA tm;

    this->font_num = 12;
    font_array = static_cast<RGE_Font*>(calloc(12, sizeof(*font_array)));
    this->fonts = font_array;
    if (font_array == 0)
        return 0;

    dc = static_cast<HDC>(this->draw_area->GetDc("basegame::setup_fonts"));
    if (dc == 0)
        return 0;

    i = 0;
    if (this->font_num > 0) {
        do {
            tm.tmHeight = static_cast<LONG>(i);
            switch (tm.tmHeight) {
            case 0:
                font = this->make_font(dc, 0x6E, 0);
                break;
            case 1:
                font = this->make_font(dc, 0x71, 0);
                break;
            case 4:
                font = this->make_font(dc, 0x74, 0);
                break;
            case 6:
                font = this->make_font(dc, 0x83, 0);
                break;
            case 7:
                font = this->make_font(dc, 0x77, 0);
                break;
            case 8:
                font = this->make_font(dc, 0x80, 1);
                break;
            case 9:
                font = this->make_font(dc, 0x7A, 0);
                break;
            case 10:
                font = this->make_font(dc, 0x7D, 0);
                break;
            case 11:
                font = this->make_font(dc, 0x80, 0);
                break;
            default:
                font = 0;
                break;
            }

            if (font != 0) {
                old_font = SelectObject(dc, font);
                GetTextMetricsA(dc, &tm);
                font_index = tm.tmHeight;
                this->fonts[font_index].font = font;
                this->fonts[font_index].font_wid = tm.tmMaxCharWidth;
                this->fonts[font_index].font_hgt =
                    tm.tmAscent + tm.tmAveCharWidth;
                SelectObject(dc, old_font);
            }

            i = i + 1;
        } while (i < this->font_num);
    }

    this->draw_area->ReleaseDc("basegame::setup_fonts");
    return 1;
}









int RGE_Base_Game::setup_blank_screen()
{
    TScreenPanel* panel;

    panel = new TScreenPanel("Blank Screen");
    if (panel == 0)
        return 0;

    if (panel->setup(this->draw_area, 0, -1, 0) == 0)
        return 0;

    panel_system.setCurrentPanel("Blank Screen", 0);
    this->set_render_all();
    SendMessageA(this->prog_window, 0x0F, 0, 0);
    return 1;
}


void RGE_Base_Game::setup_timings(void) {
    int val = 1;
    this->timings[1].include_in_total = val;
    this->timings[2].include_in_total = val;
    this->timings[3].include_in_total = val;
    this->timings[10].include_in_total = val;
    this->timings[13].include_in_total = val;
    this->timings[0].is_summary = val;
    this->timings[4].is_summary = val;
}


void RGE_Base_Game::stop_sound_system(void) {
    if (chat != 0)
        chat->StopSoundSystem();

    panel_system.stop_sound_system();

    if (this->world != 0) {
        for (int i = 0; i < this->world->sound_num; ++i)
            this->world->sounds[i]->restart_sound(0);
    }

    if (this->sounds != 0) {
        for (int i = 0; i < this->sound_num; ++i) {
            if (this->sounds[i] != 0)
                delete this->sounds[i];
        }
        free(this->sounds);
        this->sounds = 0;
    }

    this->shutdown_music_system();

    if (this->sound_system != 0) {
        this->registry->RegSetInt(1, "Sound Volume", -this->sound_system->get_volume());
        delete this->sound_system;
        this->sound_system = 0;
        sound_driver = 0;
    }
}


int RGE_Base_Game::restart_sound_system()
{
    if (this->sound_system != 0)
        goto done;

    if (this->setup_sound_system() == 0)
        return 0;
    if (this->setup_sounds() == 0)
        return 0;

    if (this->world != 0) {
        for (int i = 0; i < this->world->sound_num; ++i)
            this->world->sounds[i]->restart_sound(this->sound_system);
    }

    panel_system.restart_sound_system();

    if (chat != 0)
        chat->RestartSoundSystem(this->sound_system);

    this->restart_music_system();

done:
    return 1;
}





void RGE_Base_Game::stop_music_system(void) {
    if (this->music_system != 0) {
        this->music_system->get_play_info(&this->save_music_type, &this->save_music_track_from, &this->save_music_track_to, &this->save_music_cur_track, this->save_music_file, &this->save_music_loop, &this->save_music_pos);
        this->music_system->stop_track();
    }
}





int RGE_Base_Game::restart_music_system()
{
    if (this->music_system == 0)
        return 1;

    if (this->save_music_track_from != 0 &&
        this->save_music_track_from == this->save_music_track_to) {
        this->music_system->play_track(this->save_music_track_from,
                                       this->save_music_loop,
                                       this->save_music_pos);
        return 1;
    }

    if (this->save_music_track_from != 0 && this->save_music_track_to != 0) {
        this->music_system->play_tracks(this->save_music_track_from,
                                        this->save_music_track_to,
                                        this->save_music_loop,
                                        this->save_music_cur_track,
                                        this->save_music_pos);
        return 1;
    }

    if (this->save_music_file[0] != 0)
        this->music_system->play_file(this->save_music_file,
                                      this->save_music_loop,
                                      this->save_music_pos);
    return 1;
}



void RGE_Base_Game::shutdown_music_system() {
    if (music_system == 0) return;
    this->stop_music_system();
    registry->RegSetInt(1, "Music Volume", -music_system->volume);
    delete music_system;
    music_system = 0;
}



HFONT RGE_Base_Game::make_font(HDC dc, long id, int italic)
{
    char face_name[256];
    char point_size_str[10];
    char style[10];
    int point_size;
    int weight;

    this->get_string(id, face_name, 0x100);
    if (face_name[0] == 0)
        return 0;

    this->get_string(id + 1, point_size_str, 10);
    point_size = atoi(point_size_str);

    this->get_string(id + 2, style, 10);
    if (strstr(style, "B") != 0 || strstr(style, "b") != 0)
        weight = 700;
    else
        weight = 400;

    return this->make_font(dc, face_name, point_size, weight, italic);
}


HFONT RGE_Base_Game::make_font(HDC dc, char* name, int size, int weight, int strikeout)
{
    char str[256];
    LOGFONTA logfont;
    char charset;

    this->get_string(0x65, str, 0x100);
    charset = (char)atoi(str);
    memset(&logfont, 0, sizeof(logfont));
    logfont.lfHeight = -MulDiv(size, 0x60, 0x48);
    logfont.lfWidth = 0;
    logfont.lfEscapement = 0;
    logfont.lfOrientation = 0;
    logfont.lfWeight = weight;
    logfont.lfItalic = 0;
    logfont.lfUnderline = 0;
    logfont.lfStrikeOut = (char)strikeout;
    logfont.lfCharSet = charset;
    logfont.lfOutPrecision = 0;
    logfont.lfClipPrecision = 0;
    logfont.lfQuality = 2;
    logfont.lfPitchAndFamily = 2;
    strcpy(logfont.lfFaceName, name);
    return CreateFontIndirectA(&logfont);
}


extern int force_cd;





int RGE_Base_Game::check_for_cd(int value)
{
    char vol_name[256];
    char file_sys_name[256];
    unsigned long vol_ser_num;
    unsigned long max_comp_len;
    unsigned long file_sys_flags;

    if (this->prog_info->verify_cd == 0)
        return 1;

    if (value > 0) {
        int cd_count = 0;
        int i = 0;
        do {
            if (this->comm_handler->GetPlayerHumanity(i + 1) == 2 &&
                this->playerHasCD(i) != 0) {
                ++cd_count;
            }
            ++i;
        } while (i < 9);

        return value <= this->prog_info->max_players_per_cd * cd_count;
    }

    if (force_cd != 0)
        return 1;

    char* path = this->registry->RegGetAscii(0, "CDPath");
    if (path == 0)
        return 0;

    if (GetDriveTypeA(path) != 5)
        return 0;

    if (GetVolumeInformationA(path, vol_name, 256, &vol_ser_num,
                               &max_comp_len, &file_sys_flags,
                               file_sys_name, 256) == 0)
        return 0;

    return stricmp(vol_name, this->prog_info->vol_name) == 0;
}



int RGE_Base_Game::check_expiration() {
    struct tm expiration;
    long cur_date;
    long expiration_time;

    memset(&expiration, 0, sizeof(expiration));
    expiration.tm_year = (int)this->prog_info->expire_year - 1;
    expiration.tm_mon = (int)this->prog_info->expire_month;
    expiration.tm_wday = (int)this->prog_info->expire_day;

    expiration_time = mktime(&expiration);
    time(&cur_date);
    return cur_date <= expiration_time;
}



int RGE_Base_Game::check_multi_copies()
{
    this->prog_mutex = CreateMutexA(0, 1, this->prog_info->prog_name);
    if (GetLastError() == 0xB7) {
        HWND window = FindWindowA(this->prog_info->prog_name,
                                  this->prog_info->prog_title);
        if (window != 0) {
            if (this->check_prog_argument("LOBBY") != 0) {
                SendMessageA(window, 0x10, 0, 0);
                if (this->prog_mutex != 0)
                    ReleaseMutex(this->prog_mutex);
                return 1;
            }
            if (IsIconic(window) != 0)
                ShowWindow(window, 1);
            SetForegroundWindow(window);
            BringWindowToTop(GetLastActivePopup(window));
        }

        if (this->prog_mutex != 0) {
            ReleaseMutex(this->prog_mutex);
            CloseHandle(this->prog_mutex);
            this->prog_mutex = 0;
        }
        return 0;
    }

    if (this->prog_mutex != 0)
        ReleaseMutex(this->prog_mutex);
    return 1;
}



int RGE_Base_Game::check_paint()
{
    tagRECT update_rect;
    unsigned char surface_status;

    if (this->prog_ready == 0) {
        this->clear_window();
        ValidateRect(this->prog_window, 0);
        return 0;
    }

    if (IsIconic(this->prog_window) != 0) {
        ValidateRect(this->prog_window, 0);
        return 0;
    }

    if (this->prog_active == 0) {
        if (GetUpdateRect(this->prog_window, &update_rect, 0) != 0) {
            this->draw_system->Paint(&update_rect);
        }
        ValidateRect(this->prog_window, 0);
        return 0;
    }

    surface_status = this->draw_system->CheckSurfaces();
    switch (surface_status) {
    case 1:
        return 0;
    case 2:
        this->draw_system->ClearRestored();
        this->set_render_all();
        break;
    case 3:
        ValidateRect(this->prog_window, 0);
        DestroyWindow(this->prog_window);
        return 0;
    default:
        break;
    }
    return 1;
}




void RGE_Base_Game::clear_window() {
    RECT rect;
    HDC dc;
    HBRUSH brush;

    if (this->prog_window != 0) {
        dc = GetDC(this->prog_window);
        GetClientRect(this->prog_window, &rect);
        brush = GetStockObject(4);
        FillRect(dc, &rect, brush);
        ReleaseDC(this->prog_window, dc);
    }
}


RGE_Game_World* RGE_Base_Game::create_world() {
    return new RGE_Game_World;
}


void RGE_Base_Game::close()
{
    PostMessageA(this->prog_window, 0x10, 0, 0);
}





int RGE_Base_Game::create_dialog(TPanel** out, TPanel* panel) {
    *out = 0;
    if (panel == 0) {
        return 0;
    }
    if (panel->error_code != 0) {
        delete panel;
        return 0;
    }
    *out = panel;
    return 1;
}





void RGE_Base_Game::delete_dialog(TPanel** p)
{
    if (*p) {
        delete *p;
        *p = 0;
    }
}




void RGE_Base_Game::set_game_mode(int a, int b) {
    this->game_mode = a;
    this->sub_game_mode = b;
}






void RGE_Base_Game::set_player(short player_id) {
    RGE_Game_World* w = this->world;
    if (w == 0) return;
    if (player_id >= w->player_num) return;
    w->curr_player = player_id;
    this->world->map->clear_map_view_info();
}


int RGE_Base_Game::get_paused()
{
    if (this->prog_mode == 7)
        return 0;
    return this->comm_handler->IsPaused();
}




RGE_Font* RGE_Base_Game::get_font(int index)
{
    if (!this->fonts)
        return 0;
    return this->fonts + index;
}


TShape* RGE_Base_Game::get_shape(int i) {
    if (!this->shapes) return 0;
    return this->shapes[i];
}


TDigital* RGE_Base_Game::get_sound(int i) {
    if (!this->sounds) return 0;
    return this->sounds[i];
}






void RGE_Base_Game::request_pause()
{
    this->comm_handler->TogglePauseGame();
    if (this->world)
        this->world->temp_pause = 1;
}




void RGE_Base_Game::set_paused(int paused, int non_user_pause) {
    this->save_paused = this->get_paused();
    if (paused != this->save_paused) {
        if (paused != 0) {
            this->non_user_pause = non_user_pause;
        } else {
            this->non_user_pause = 0;
        }
        this->request_pause();
    }
}





void RGE_Base_Game::get_mouse_info(WPARAM flags, LPARAM lparam, tagPOINT& point, int& lbtn, int& rbtn, int& mbtn, int& wheel) {
    int x = lparam & 0xFFFF;
    int y = static_cast<unsigned long>(lparam) >> 0x10;
    point.x = x;
    point.y = y;
    if (60000 < x) {
        point.x = x - 0x10000;
    }
    if (60000 < y) {
        point.y = y - 0x10000;
    }
    lbtn = flags & 1;
    rbtn = flags & 2;
    mbtn = flags & 8;
    wheel = flags & 4;
}


void RGE_Base_Game::get_mouse_pos(tagPOINT& pt) {
    GetCursorPos(&pt);
    if (this->prog_info->full_screen == 0) {
        ScreenToClient(this->prog_window, &pt);
        if (pt.x > 60000) {
            pt.x += -0x10000;
        }
        if (pt.y > 60000) {
            pt.y += -0x10000;
        }
    }
}


RGE_Player* RGE_Base_Game::get_player(void) {
    RGE_Game_World* w = this->world;
    if (!w) return 0;
    if (!w->player_num) return 0;
    if (w->curr_player >= w->player_num) return 0;
    return w->players[(int)(short)w->curr_player];
}


void RGE_Base_Game::draw_window() {
    UpdateWindow(this->prog_window);
}

void RGE_Base_Game::mouse_on() {
    if (this->is_mouse_on == 0) {
        if ((this->custom_mouse != 0) && (this->windows_mouse == 0)) {
            this->mouse_pointer->on();
            this->is_mouse_on = 1;
            return;
        }
        SetCursor(this->mouse_cursor);
        SetClassLongA(this->prog_window, GCL_HCURSOR,
                      reinterpret_cast<LONG>(this->mouse_cursor));
        this->is_mouse_on = 1;
    }
}
void RGE_Base_Game::mouse_off() {
    if (is_mouse_on) {
        if (custom_mouse && !windows_mouse) {
            mouse_pointer->off();
            is_mouse_on = 0;
            return;
        }
        SetCursor(0);
        SetClassLongA(prog_window, -12, 0);
        is_mouse_on = 0;
    }
}
void RGE_Base_Game::set_windows_mouse(int value) {
    if (this->custom_mouse != 0) {
        this->windows_mouse = value;
    } else {
        this->windows_mouse = 1;
    }

    if ((this->custom_mouse != 0) && (this->windows_mouse == 0)) {
        SetCursor(0);
        SetClassLongA(this->prog_window, -12, 0);
        if (this->is_mouse_on != 0) {
            this->mouse_pointer->on();
            return;
        }
        this->mouse_pointer->off();
        return;
    }

    this->mouse_pointer->off();
    if (this->is_mouse_on != 0) {
        SetCursor(this->mouse_cursor);
        SetClassLongA(this->prog_window, GCL_HCURSOR,
                      reinterpret_cast<LONG>(this->mouse_cursor));
    } else {
        SetCursor(0);
        SetClassLongA(this->prog_window, -12, 0);
    }
}
void RGE_Base_Game::set_mouse_cursor(HCURSOR new_cursor) {
    this->mouse_cursor = new_cursor;

    if (new_cursor != 0) {
        last_mouse_cursor = new_cursor;
    }

    if (this->is_mouse_on == 0) {
        return;
    }

    if (this->custom_mouse != 0) {
        if (this->windows_mouse == 0) {
            return;
        }
    }

    SetCursor(this->mouse_cursor);
    SetClassLongA(this->prog_window, GCL_HCURSOR,
                  reinterpret_cast<LONG>(this->mouse_cursor));
}


void RGE_Base_Game::set_mouse_facet(long param)
{
    this->mouse_pointer->set_facet(param);
}



int __stdcall enum_wnd_proc(void* param_1, long param_2) {
    char buffer[256];
    GetWindowTextA(param_1, buffer, 255);
    return 1;
}



int __stdcall enum_child_proc(void* param_1, long param_2) {
    char buffer[256];
    GetWindowTextA(param_1, buffer, 255);
    return 1;
}



int __stdcall enum_thread_proc(void* param_1, long param_2) {
    char buffer[256];
    GetWindowTextA(param_1, buffer, 255);
    return 1;
}



int __stdcall close_thread_windows(void* wnd, long unused) {
    if (wnd != AppWnd) {
        if (GetParent(wnd) != AppWnd) {
            SendMessageA(wnd, 0x10, 0, 0);
        }
    }
    return 1;
}



int __stdcall close_child_windows(void* hwnd, long param)
{
    char str[256];

    str[0] = 0;
    GetWindowTextA(hwnd, str, 0xff);

    if (strcmp(str, "Locate Session") != 0) {
        SendMessageA(hwnd, 0x10, 0, 0);
    }

    return 1;
}


extern void color_log(unsigned char a, unsigned char b, int c);







LRESULT CALLBACK RGE_Base_Game::wnd_proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    RGE_Base_Game* self = this;
    color_log(0x24, 0x24, 3);
    int mouse_down = 0;
    if (msg >= 0x201 && msg <= 0x206) {
        mouse_down = 1;
        color_log(0x4C, 0x4C, 4);
    }

    if (self->sound_system != 0) {
        self->sound_system->handle_messages(hwnd, msg, wparam, lparam);
    }

    color_log(0x24, 0x16, 3);
    if (self->music_system != 0) {
        self->music_system->handle_messages(hwnd, msg, wparam, lparam);
    }

    color_log(0x24, 0x4C, 3);

    long panel_result = 0;
    TPanel* panel = panel_system.currentPanel();
    if (panel != 0) {
        color_log(0x24, 0x32, 3);
        panel = panel_system.currentPanel();
        panel_result = panel->wnd_proc(hwnd, msg, wparam, lparam);
        if (panel_result != 0 && msg != 0x200 && msg != 0x113)
            goto panel_return_after_exit_menu;
    }

    color_log(0x24, 0x45, 3);

    switch (msg) {
    case 2:
        color_log(0x32, 0xBA, 3);
        if (self->handle_destroy(hwnd, 2, wparam, lparam) != 0)
            goto default_window_proc;
        goto panel_return_alt;

    case 5:
        {
        if (system_ignore_size_messages != 0)
            goto default_window_proc;
        color_log(0x32, 0xBA, 3);
        int size_handled = self->handle_size(hwnd, 5, wparam, lparam);
        if (size_handled != 0)
            goto default_window_proc;
        if (mouse_down == 0)
            goto wparam_return;
        color_log(0x4C, 0x5F, 4);
        color_log(0x24, 0x5F, 3);
        return static_cast<LRESULT>(wparam);
        }

    case 6:
        if (self->prog_ready != 0) {
            int active_state = wparam & 0xFFFF;
            int minimized = wparam >> 16;
            if (active_state == 0) {
                if (GetWindowThreadProcessId(reinterpret_cast<HWND>(lparam), 0) ==
                    GetWindowThreadProcessId(self->prog_window, 0))
                    save_active_wnd = reinterpret_cast<HWND>(lparam);
            }
            if (hwnd == self->prog_window && active_state != 0 &&
                minimized != 0 && save_active_wnd != 0) {
                save_active_wnd = 0;
            }
        }
        goto default_window_proc;

    case 0x0F:
        color_log(0x32, 0x45, 3);
        if (self->handle_paint(hwnd, 0x0F, wparam, lparam) != 0)
            goto default_window_proc;
        goto panel_return;

    case 0x1C:
        if (self->prog_ready != 0) {
            if (wparam == 1) {
                if (basegame_is_active != 0) {
                    SetCursor(0);
                    SetClassLongA(self->prog_window, -12, 0);
                    if (self->prog_mode != 1)
                        self->restart_sound_system();
                    basegame_is_active = 0;
                    if (self->draw_system != 0) {
                        self->draw_system->CheckSurfaces();
                        self->draw_system->ClearRestored();
                        self->set_render_all();
                    }
                    if (self->prog_mode != 1) {
                        if (self->draw_system != 0) {
                            self->draw_system->ClearPrimarySurface();
                            self->draw_system->ModifyPalette(
                                0, 0x100, self->draw_system->palette);
                        }
                        self->set_render_all();
                        InvalidateRect(self->prog_window, 0, 1);
                        do_restore_palette = 10;
                        restore_palette_timer = debug_timeGetTime(
                            "C:\\msdev\\work\\age1_x1\\basegame.cpp", 0xE9B);
                        restore_mouse_after_paint = 1;
                    }
                }
            } else if (basegame_is_active == 0) {
                SetClassLongA(self->prog_window, -12, 0);
                if (self->prog_mode != 1)
                    self->stop_sound_system();
                basegame_is_active = 1;
                if (self->prog_mode != 1 && self->mouse_pointer != 0)
                    self->mouse_pointer->Shutdown_Mouse();
            }
        }
        color_log(0x32, 0x54, 3);
        if (self->handle_activate(hwnd, 0x1C, wparam, lparam) != 0)
            goto default_window_proc;
        goto panel_return;

    case 0x104:
        color_log(0x24, 0xBA, 3);
        {
            int handled = self->handle_key_down(hwnd, 0x104, wparam, lparam);
            if (handled != 0)
                goto default_window_proc;
        }
        goto panel_return;

    case 0x100:
        color_log(0x24, 0xBA, 3);
        {
            int handled = self->handle_key_down(hwnd, 0x100, wparam, lparam);
            if (handled != 0)
                goto default_window_proc;
        }
        goto panel_return;

    case 0x105:
        if (wparam == 0x12 && panel_system.currentPanel() != 0) {
            panel = panel_system.currentPanel();
            panel->handle_reactivate();
        }
        goto default_window_proc;

    case 0x111:
        color_log(0x32, 0x16, 3);
        if (self->handle_command(hwnd, 0x111, wparam, lparam) != 0)
            goto default_window_proc;
        goto panel_return_after_exit_menu;

    case 0x112:
        if (wparam == 0xF100 && self->prog_info->skip_startup != 0 &&
            IsIconic(self->prog_window) == 0)
            return 0;
        goto default_window_proc;

    case 0x113:
        if (self->handle_idle() != 0)
            goto default_window_proc;
        goto panel_return;

    case 0x116:
        color_log(0x32, 0xBA, 3);
        if (self->handle_init_menu(hwnd, 0x116, wparam, lparam) != 0)
            goto default_window_proc;
        goto panel_return;

    case 0x200:
        color_log(0x24, 0x54, 3);
        if (self->handle_mouse_move(hwnd, 0x200, wparam, lparam) != 0) {
            if (MouseCursorInChildContol != 0) {
                if (self->windows_mouse == 0) {
                    SetCursor(0);
                    SetClassLongA(self->prog_window, -12, 0);
                    self->mouse_on();
                    MouseCursorInChildContol = 0;
                } else {
                    SetCursor(self->mouse_cursor);
                    MouseCursorInChildContol = 0;
                }
            }
            goto default_window_proc;
        }
        goto panel_return;

    case 0x212:
        color_log(0x32, 0xBA, 3);
        if (self->handle_exit_menu(hwnd, 0x212, wparam, lparam) != 0)
            goto default_window_proc;
        goto panel_return_after_exit_menu;

panel_return_after_exit_menu:
        if (mouse_down != 0)
            color_log(0x4C, 0x5F, 4);
        color_log(0x24, 0x5F, 3);
        return static_cast<LRESULT>(wparam);

    case 0x218:
        if (wparam == 0)
            return 0x424D5144;
        goto default_window_proc;

    case 0x10:
        goto close_message;

    case 0x30F:
        color_log(0x32, 0xBA, 3);
        if (self->handle_query_new_palette(hwnd, 0x30F, wparam, lparam) != 0)
            goto close_message;
        goto panel_return_alt;

    case 0x311:
        color_log(0x32, 0xBA, 3);
        if (self->handle_palette_changed(hwnd, 0x311, wparam, lparam) != 0)
            goto default_window_proc;
        goto panel_return_alt;

    case 0x3B9:
        goto music_done_message;

    case 0x400:
        color_log(0x32, 0x24, 3);
        {
            int old_time = debug_timeGetTime_on;
            debug_timeGetTime_on = 0;
            if (self->handle_user_command(hwnd, 0x400, wparam, lparam) == 0) {
                if (mouse_down != 0)
                    color_log(0x4C, 0x5F, 4);
                color_log(0x24, 0x5F, 3);
                debug_timeGetTime_on = old_time;
                return static_cast<LRESULT>(panel_result);
            }
            debug_timeGetTime_on = old_time;
        }
        goto default_window_proc;

    case 0x500:
        goto music_done_message;

close_message:
    color_log(0x32, 0xBA, 3);
    if (self->handle_close(hwnd, msg, wparam, lparam) != 0)
        goto default_window_proc;
    if (panel_result != 0) {
        color_log(0x4C, 0x5F, 4);
        color_log(0x24, 0x5F, 3);
        return static_cast<LRESULT>(panel_result);
    }
    goto panel_return_alt;

music_done_message:
    {
    color_log(0x32, 0x4C, 3);
    int music_handled = self->handle_music_done(hwnd, msg, wparam, lparam);
    if (music_handled != 0)
        goto default_window_proc;
    if (mouse_down != 0)
        color_log(0x4C, 0x5F, 4);
    color_log(0x24, 0x5F, 3);
    return static_cast<LRESULT>(wparam);
    }

    default:
        goto default_window_proc;
    }

 wparam_return:
    color_log(0x24, 0x5F, 3);
    return static_cast<LRESULT>(wparam);

panel_return:
    if (mouse_down == 0)
        goto panel_return_alt;
    color_log(0x4C, 0x5F, 4);
    color_log(0x24, 0x5F, 3);
    return static_cast<LRESULT>(wparam);

panel_return_alt:
    if (mouse_down != 0)
        color_log(0x4C, 0x5F, 4);
    color_log(0x24, 0x5F, 3);
    return static_cast<LRESULT>(wparam);

default_window_proc:
    {
        color_log(0x24, 0x54, 3);
        long result = DefWindowProcA(hwnd, msg, wparam, lparam);
        if (mouse_down != 0)
            color_log(0x4C, 0x5F, 4);
        color_log(0x24, 0x5F, 3);
        return result;
    }

}



extern void color_log(unsigned char a, unsigned char b, int c);


int RGE_Base_Game::handle_idle()
{
    if (!this->prog_ready || !this->prog_window)
        return 0;

    color_log(0x16, 0x16, 2);

    if (do_restore_palette && this->prog_active) {
        int delay = 0xFA;
        if (do_restore_palette > 5)
            delay = 0x1F4;

        unsigned long t = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0xF9A);
        if ((t - restore_palette_timer) >= static_cast<unsigned long>(delay)) {
            if (this->draw_system) {
                this->draw_system->ModifyPalette(0, 0x100,
                    this->draw_system->palette);
            }
            do_restore_palette--;
            restore_palette_timer = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp",
                                                       0xFA4);
        }
    }

    color_log(0x32, 0x32, 5);

    if (this->sound_system) {
        color_log(0x16, 0xBA, 2);
        this->sound_system->handle_messages(this->prog_window, 0x113, 0, 0);
    }

    TPanel* panel = panel_system.currentPanel();
    if (panel != 0) {
        color_log(0x16, 0x45, 2);
        panel = panel_system.currentPanel();
        panel->handle_idle();
    }

    if (this->comm_handler) {
        if (this->multiplayerGame()) {
            color_log(0x45, 0x45, 1);
            this->comm_handler->ReceiveGameMessages();
            color_log(0x45, 0x5F, 1);
        }
    }

    if (this->do_show_comm) {
        color_log(0x16, 0x32, 2);
        this->show_comm();
    }

    if (this->do_show_ai) {
        color_log(0x16, 0x24, 2);
        this->show_ai();
    }

    color_log(0x32, 0x5F, 5);
    color_log(0x16, 0x5F, 2);

    return 1;
}








int RGE_Base_Game::handle_mouse_move(HWND p1, UINT p2, WPARAM p3, LPARAM p4)
{
    int ctrl_key;
    int right_btn;
    int left_btn;
    tagPOINT point;
    // ORIGINAL BUG: 00421110 passes this local without a write.
    // action_mouse_move receives its stack value. Do not initialize it.
    int shift_key;
    if (this->prog_ready == 0) {
        return 1;
    }

    if (this->custom_mouse != 0 && this->windows_mouse == 0) {
        if (this->mouse_pointer->in_game_mode()) {
            this->mouse_pointer->Poll();
        } else {
            this->mouse_pointer->draw(0);
        }
    }

    this->get_mouse_info(p3, p4, &point.y, &point.x, &left_btn, &right_btn,
                         &ctrl_key);
    this->action_mouse_move(
        point.y, shift_key, point.x, left_btn, right_btn, ctrl_key);
    this->handle_idle();
    return 1;
}



extern int snapshot_number;








int RGE_Base_Game::handle_key_down(HWND param_1, UINT param_2, WPARAM param_3, LPARAM param_4)
{
    if (this->prog_ready == 0) {
        return 1;
    }

    short (__stdcall *get_key_state)(int) = GetKeyState;

    basegame_key_message = param_3;
    basegame_key_parameter = param_4 & 0xFFFF;
    basegame_control_key_down = (get_key_state(0x11) < 0);
    basegame_alt_key_down = (get_key_state(0x12) < 0);
    basegame_shift_key_down = (get_key_state(0x10) < 0);

    if (param_1 == this->prog_window && param_2 == 0x104 &&
        (basegame_key_message == 0x12 || basegame_key_message == 0x20 ||
         basegame_key_message == 0x79) &&
        this->prog_info->full_screen != 0 &&
        IsIconic(this->prog_window) == 0) {
        return 0;
    }

    if (basegame_control_key_down != 0 && basegame_key_message == 0x7B) {
        this->draw_system->DrawArea->take_snapshot(
            ".\\AoE%04d.bmp", snapshot_number);
        return 0;
    }

    return this->action_key_down(basegame_key_message, basegame_key_parameter,
                                 basegame_control_key_down,
                                 basegame_alt_key_down,
                                 basegame_shift_key_down) != 0;
}



extern int out_of_sync;




int RGE_Base_Game::handle_user_command(HWND param_1, UINT param_2, WPARAM command, LPARAM param)
{
    if (this->comm_handler->MultiplayerGameStart() != 0 && out_of_sync == 0) {
        if (command == 0x17B3) {
            this->world->players[this->playerID(param)]->command_resign((int)param, 1);
        } else if (command == 0x17B4) {
            this->world->players[this->playerID(param)]->command_resign((int)param, 0);
        }
    }

    switch (command) {
    case 0x17A2:
        if (this->world != 0) {
            this->world->pause((unsigned char)1);
        }
        break;
    case 0x17A3:
        if (this->world != 0) {
            this->world->pause((unsigned char)0);
        }
        break;
    }

    return this->action_user_command(command, param) != 0;
}




int RGE_Base_Game::handle_command(HWND a, UINT b, WPARAM c, LPARAM d)
{
    return this->action_command(static_cast<unsigned long>(c),
                                static_cast<unsigned long>(d)) != 0;
}




int RGE_Base_Game::handle_music_done(HWND p0, UINT p1, WPARAM p2, LPARAM p3) {
    return this->action_music_done() != 0;
}


extern void color_log(unsigned char a, unsigned char b, int c);
int RGE_Base_Game::handle_paint(HWND param_1, UINT param_2, WPARAM param_3, LPARAM param_4)
{
    unsigned long time_a;
    unsigned long time_b;
    unsigned long time_c;
    int result;

    color_log(0x32, 0x32, 4);

    time_a = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x10EA);
    result = this->check_paint();
    time_b = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x10EE);
    this->add_to_timing(5, time_b - time_a);

    if (result == 0) {
        color_log(0x32, 0x5F, 4);
        return 0;
    }

    if (((this->prog_mode == 4 || this->prog_mode == 6 ||
          this->prog_mode == 7) &&
         this->draw_system->DrawType != 1 && this->custom_mouse != 0) &&
        this->mouse_blit_sync != 0) {
        IDirectDrawSurface* surface = this->draw_system->PrimarySurface;
        result = surface->GetBltStatus(1);
        time_a = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x10FC);
        time_a += 100;

        do {
            if (result != (int)0x8876021C)
                goto paint_done;

            surface = this->draw_system->PrimarySurface;
            result = surface->GetBltStatus(1);
            time_b = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x1100);
        } while (time_b <= time_a);

        this->mouse_blit_sync = 0;
    }

paint_done:
    color_log(0x32, 0xBA, 4);

    time_a = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x110C);
    TSound_Driver* sound = rge_base_game->sound_system;
    if (sound != 0) {
        sound->play_list();
        sound->reset_play_list();
    }

    time_b = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x1115);
    this->add_to_timing(10, time_b - time_a);

    time_a = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x111C);
    if (this->erase_mouse != 0) {
        color_log(0x32, 0x4C, 4);
        if (this->render_all == 0 && this->custom_mouse != 0)
            this->mouse_pointer->erase();
        this->erase_mouse = 0;
    }

    time_c = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x1127) - time_a;
    time_a = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x112A);
    color_log(0x32, 0x16, 4);

    TPanel* panel;
    if (panel_system.currentPanel() != 0) {
        color_log(0x16, 0x16, 1);
        if (this->render_all != 0) {
            panel = panel_system.currentPanel();
            panel->set_redraw(TPanel::RedrawImmediate);
        }
        panel = panel_system.currentPanel();
        panel->handle_paint();
        color_log(0x16, 0x5F, 1);
    } else {
        this->clear_window();
    }

    color_log(0x32, 0x24, 4);
    if (basegame_palette_restore_pending != 0) {
        basegame_palette_restore_pending = 0;
        if ((this->prog_mode == 4 || this->prog_mode == 5) &&
            this->do_show_timings != 0)
            this->show_timings();
    }

    time_b = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x1147);
    this->add_to_timing(2, time_b - time_a);

    time_a = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x114B);
    color_log(0x32, 0x54, 4);
    if (this->custom_mouse != 0 && this->windows_mouse == 0) {
        this->mouse_pointer->draw(1);
        this->erase_mouse = 1;
    }

    time_c += debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x115B) - time_a;
    this->add_to_timing(8, time_c);

    time_a = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x1160);
    color_log(0x32, 0x45, 4);
    this->draw_system->Paint(0);
    ValidateRect(this->prog_window, 0);
    ValidateRect(this->prog_window, 0);
    this->render_all = 0;

    time_b = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x1176);
    this->add_to_timing(3, time_b - time_a);

    color_log(0x32, 0x5F, 4);
    ++this->frame_count;

    time_a = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x1182);
    if (time_a - basegame_palette_restore_time >= 1000) {
        this->calc_timings();
        basegame_palette_restore_time = time_a;
        basegame_palette_restore_pending = 1;
    }

    if (restore_mouse_after_paint != 0) {
        if (this->mouse_pointer != 0) {
            this->mouse_pointer->Restore_Mouse(this->draw_area);
            if (this->is_mouse_on != 0) {
                if (this->custom_mouse == 0 || this->windows_mouse != 0) {
                    SetCursor(this->mouse_cursor);
                    SetClassLongA(this->prog_window, GCL_HCURSOR,
                                  reinterpret_cast<LONG>(this->mouse_cursor));
                } else {
                    this->mouse_pointer->on();
                    this->mouse_pointer->draw(1);
                }
            }
            InvalidateRect(param_1, 0, 0);
        }
        restore_mouse_after_paint = 0;
    }

    return 1;
}









int RGE_Base_Game::handle_activate(HWND param_1, UINT param_2, WPARAM param_3, LPARAM param_4)
{
    if (param_3 != 0) {
        this->prog_active = 1;
    } else {
        this->prog_active = 0;
    }

    if (this->prog_active != 0) {
        if ((this->prog_mode == 4 || this->prog_mode == 6 || this->prog_mode == 7) &&
            this->auto_paused == 1) {
            this->auto_paused = 0;
            this->set_paused(0, 0);
        }

        TPanel* panel = panel_system.currentPanel();
        if (panel != 0) {
            panel = panel_system.currentPanel();
            panel->handle_reactivate();
        }
        this->action_activate();
    } else {
        if (this->prog_mode == 4 || this->prog_mode == 6 || this->prog_mode == 7) {
            if (this->singlePlayerGame() == 1 && this->get_paused() == 0) {
                this->auto_paused = 1;
                this->set_paused(1, 0);
            }
        }
        this->action_deactivate();
    }

    return 1;
}




int RGE_Base_Game::handle_init_menu(HWND p0, UINT p1, WPARAM p2, LPARAM p3) {
    return this->action_init_menu() != 0;
}




int RGE_Base_Game::handle_exit_menu(HWND p0, UINT p1, WPARAM p2, LPARAM p3) {
    return this->action_exit_menu() != 0;
}









int RGE_Base_Game::handle_size(HWND p1, UINT p2, WPARAM p3, LPARAM p4)
{
    if (p3 == 1) return 1;

    if (this->draw_system != 0) {
        this->draw_system->HandleSize(p1, p2, p3, p4);

        if (this->draw_system != 0 && this->draw_system->ScreenWidth != 0) {
            this->prog_info->main_wid = this->draw_system->ScreenWidth;
            this->prog_info->main_hgt = this->draw_system->ScreenHeight;
        }

        TPanel* panel = panel_system.currentPanel();
        if (panel != 0) {
            panel = panel_system.currentPanel();
            panel->handle_size(this->prog_info->main_wid, this->prog_info->main_hgt);
        }
    }

    this->action_size();
    return 1;
}





int RGE_Base_Game::handle_palette_changed(HWND p1, UINT p2, WPARAM p3, LPARAM p4) {
    if (this->draw_system != 0) {
        this->draw_system->HandlePaletteChanged(p1, p2, p3, p4);
    }

    if (reinterpret_cast<void*>(p3) != p1) {
        TDrawSystem* ds = this->draw_system;
        if (ds->DrawType == 1 || ds->ScreenMode == 1 || ds == 0) {
            this->handle_query_new_palette(p1, p2, p3, p4);
        }
        else if (this->prog_mode != 1) {
            ds->ModifyPalette(0, 0x100, ds->palette);
            return 1;
        }
    }

    return 1;
}









int RGE_Base_Game::handle_query_new_palette(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    TDrawSystem* ds = this->draw_system;
    if (ds != 0 && ds->DrawType != 1 && ds->ScreenMode != 1) {
        InvalidateRect(hwnd, 0, 0);
        return this->draw_system->HandleQueryNewPalette(hwnd, msg, wparam, lparam);
    }

    HDC dc = GetDC(hwnd);
    if (panel_system.currentPanel() != 0) {
        TEasy_Panel* panel = static_cast<TEasy_Panel*>(panel_system.currentPanel());
        if (panel->get_palette() != 0)
            SelectPalette(dc, panel->get_palette(), 0);
    } else {
        if (this->prog_palette != 0)
            SelectPalette(dc, this->prog_palette, 0);
    }
    int result = RealizePalette(dc);
    ReleaseDC(hwnd, dc);
    if (result != 0)
        InvalidateRect(hwnd, 0, 0);
    if (this->draw_system != 0)
        return this->draw_system->HandleQueryNewPalette(hwnd, msg, wparam, lparam);
    return 1;
}






int RGE_Base_Game::handle_close(HWND param_1, UINT param_2, WPARAM param_3, LPARAM param_4) {
    if (this->action_close() == 0) {
        return 0;
    }
    if (this->draw_area != 0 && this->draw_system != 0) {
        this->draw_area->Clear(0, 0);
        this->draw_system->Paint(0);
    }
    return 1;
}
int RGE_Base_Game::handle_destroy(HWND param1, UINT param2, WPARAM param3, LPARAM param4) {
    this->prog_ready = 0;
    if (this->is_timer != 0) {
        KillTimer(this->prog_window, 1);
    }
    this->prog_window = 0;
    PostQuitMessage(0);
    return 1;
}


extern int do_fps_log;
extern FILE* fps_log;
extern unsigned long start_mem_total;
extern unsigned long start_mem_high;
extern unsigned long cur_mem_total;
extern unsigned long cur_mem_high;







void RGE_Base_Game::calc_timings()
{
    unsigned long total_time = 0;
    for (int i = 0; i < 30; ++i) {
        if (this->timings[i].is_summary == 0) {
            this->timings[i].last_time = this->timings[i].accum_time;
            this->timings[i].last_max_time = this->timings[i].max_time;
            this->timings[i].accum_time = 0;
            this->timings[i].max_time = 0;
            this->timings[i].start_time = debug_timeGetTime(
                "C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x12B5);

            if (this->timings[i].include_in_total != 0)
                total_time += this->timings[i].last_time;
        }
    }

    if (this->timings[0].start_time > 0) {
        this->timings[0].last_time = debug_timeGetTime(
            "C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x12BE) - this->timings[0].start_time;
    } else {
        this->timings[0].last_time = total_time;
    }

    this->timings[0].start_time = debug_timeGetTime(
        "C:\\msdev\\work\\age1_x1\\basegame.cpp", 0x12C1);

    if (this->timings[0].last_time > total_time)
        this->timings[4].last_time =
            this->timings[0].last_time - total_time;
    else
        this->timings[4].last_time = 0;

    if (this->timings[2].last_time >
        this->timings[6].last_time + this->timings[7].last_time)
        this->timings[9].last_time =
            this->timings[2].last_time - this->timings[6].last_time -
            this->timings[7].last_time;
    else
        this->timings[9].last_time = 0;

    unsigned long total = this->timings[0].last_time;
    if (total == 0 || this->frame_count == 0 ||
        total / this->frame_count == 0) {
        this->fps = 1000;
    } else {
        this->fps = 1000 / (total / this->frame_count);
    }

    if (total == 0 || this->view_update_count == 0 ||
        total / this->view_update_count == 0) {
        this->view_update_fps = 0;
    } else {
        this->view_update_fps =
            1000 / (total / this->view_update_count);
    }

    if (total == 0 || this->world_update_count == 0 ||
        total / this->world_update_count == 0) {
        this->world_update_fps = 0;
    } else {
        this->world_update_fps =
            1000 / (total / this->world_update_count);
    }

    this->calc_timing_text();

    if (do_fps_log != 0 && this->prog_mode == 4) {
        int object_count = 0;
        int sleeping_object_count = 0;
        int player_count = this->world->player_num;

        if (player_count > 1) {
            RGE_Player** players = this->world->players;
            ++players;
            --player_count;
            do {
                RGE_Player* player = *players;
                ++players;
                object_count += player->objects->number_of_objects;
                sleeping_object_count +=
                    player->sleeping_objects->number_of_objects;
                --player_count;
            } while (player_count != 0);
        }

        fprintf(
            fps_log,
            "%lu, %ld, %ld, %ld, %ld, %d, %d, %d, %d, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %d, %d, %d \n",
            this->world->world_time,
            start_mem_total,
            start_mem_high,
            cur_mem_total,
            cur_mem_high,
            (*this->world->players)->objects->number_of_objects,
            (*this->world->players)->sleeping_objects->number_of_objects,
            object_count,
            sleeping_object_count,
            this->world_update_count,
            this->view_update_count,
            this->world_update_fps,
            this->view_update_fps,
            this->world_update_count == 0
                ? 0 : this->timings[6].last_time / this->world_update_count,
            this->timings[6].last_max_time,
            this->world_update_count == 0
                ? 0 : this->timings[7].last_time / this->world_update_count,
            this->timings[7].last_max_time,
            this->world_update_count == 0
                ? 0 : this->timings[3].last_time / this->world_update_count,
            this->timings[3].last_max_time,
            this->world_update_count == 0
                ? 0 : this->timings[1].last_time / this->world_update_count,
            this->timings[1].last_max_time,
            this->world_update_count == 0
                ? 0 : (this->timings[10].last_time +
                       this->timings[12].last_time) /
                      this->world_update_count,
            this->timings[10].last_max_time +
                this->timings[12].last_max_time,
            this->world_update_count == 0
                ? 0 : this->timings[13].last_time / this->world_update_count,
            this->timings[13].last_max_time,
            this->world_update_count == 0
                ? 0 : this->timings[4].last_time / this->world_update_count,
            this->timings[4].last_max_time,
            0,
            -1,
            -1);
        fflush(fps_log);
    }

    this->last_frame_count = this->frame_count;
    this->last_world_update_count = this->world_update_count;
    this->last_view_update_count = this->view_update_count;
    this->frame_count = 0;
    this->world_update_count = 0;
    this->view_update_count = 0;
}
void RGE_Base_Game::calc_timing_text()
{
    unsigned long divisor = this->frame_count;
    if (divisor == 0)
        divisor = 1;

    sprintf(this->timing_text,
        "fps=%lu, rend=%lu, view=%lu, map=%lu, scr=%lu, draw=%lu, prog=%lu, ui=%lu, sfx=%lu, misc=%lu",
        this->fps,
        this->world_update_count / divisor,
        this->view_update_count / divisor,
        this->timings[0].last_time / divisor,
        this->timings[0].accum_time / divisor,
        this->timings[0].start_time / divisor,
        this->timings[1].last_time / divisor,
        this->timings[1].accum_time / divisor,
        this->timings[1].start_time / divisor,
        this->timings[0].last_single_time / divisor);
}
void RGE_Base_Game::show_timings()
{
    SetWindowTextA(this->prog_window, this->timing_text);
}
void RGE_Base_Game::show_comm(void) {
    char str[256];
    sprintf(str, "%s", this->comm_handler->GetCommInfo(1));
    SetWindowTextA(this->prog_window, str);
}
void RGE_Base_Game::show_ai(void) {
    char str[256];
    sprintf(str, "No AI Information for Player #%d.",
            (int)this->world->curr_player);
    SetWindowTextA(this->prog_window, str);
}


void RGE_Base_Game::send_game_options()
{
    if (this->comm_handler)
        this->comm_handler->SetMyGameOptions(
            reinterpret_cast<char*>(&this->rge_game_options), 0xA8);
}


void RGE_Base_Game::receive_game_options(void)
{
    if (this->comm_handler != 0) {
        unsigned long size = 0;
        void* options = this->comm_handler->GetMyGameOptions(&size);
        if (options != 0 && size == 0xA8)
            this->set_game_options(static_cast<RGE_Game_Options*>(options));
    }
}


void RGE_Base_Game::set_game_options(RGE_Game_Options* opt)
{
    int i;

    this->setVersion(opt->versionValue);
    this->setScenarioGame(opt->scenarioGameValue);
    this->setScenarioName(opt->scenarioNameValue);
    this->setSinglePlayerGame(opt->singlePlayerGameValue);
    this->setMultiplayerGame(opt->multiplayerGameValue);
    this->setMapSize(opt->mapXSizeValue, opt->mapYSizeValue,
                     opt->mapZSizeValue);
    this->setAllowCheatCodes(opt->allowCheatCodesValue);
    this->setCheatNotification(opt->cheatNotificationValue);
    this->setFullVisibility(opt->fullVisibilityValue);
    this->setFogOfWar(opt->fogOfWarValue);
    this->setColoredChat(opt->coloredChatValue);
    this->setNumberPlayers(opt->numberPlayersValue);
    this->setGameDeveloperMode(opt->gameDeveloperModeValue);
    this->setDifficulty(opt->difficultyValue);
    this->setMpPathFinding(opt->mpPathFindingValue);

    for (i = 0; i < 9; i++) {
        this->setPlayerCDAndVersion(i, opt->playerCDAndVersionValue[i]);
        this->setPlayerTeam(i, opt->playerTeamValue[i]);
    }
}


void RGE_Base_Game::get_game_options(RGE_Game_Options* options)
{
    options->versionValue = this->version();
    options->scenarioGameValue = (unsigned char)this->scenarioGame();
    strcpy(options->scenarioNameValue, this->scenarioName());

    options->singlePlayerGameValue = (unsigned char)this->singlePlayerGame();
    options->multiplayerGameValue = (unsigned char)this->multiplayerGame();
    options->mapXSizeValue = (unsigned char)this->mapXSize();
    options->mapYSizeValue = (unsigned char)this->mapYSize();
    options->mapZSizeValue = (unsigned char)this->mapZSize();
    options->allowCheatCodesValue = (unsigned char)this->allowCheatCodes();
    options->cheatNotificationValue = (unsigned char)this->cheatNotification();
    options->fullVisibilityValue = (unsigned char)this->fullVisibility();
    options->fogOfWarValue = (unsigned char)this->fogOfWar();
    options->coloredChatValue = (unsigned char)this->coloredChat();
    options->numberPlayersValue = (unsigned char)this->numberPlayers();
    options->gameDeveloperModeValue = (unsigned char)this->gameDeveloperMode();
    options->difficultyValue = (unsigned char)this->difficulty();
    options->mpPathFindingValue = this->mpPathFinding();

    for (int i = 0; i < 9; i++) {
        options->playerCDAndVersionValue[i] = this->playerCDAndVersion(i);
        options->playerTeamValue[i] = (unsigned char)this->playerTeam(i);
    }
}




float RGE_Base_Game::version() const {
    return this->rge_game_options.versionValue;
}


int RGE_Base_Game::scenarioGame() const {
    return this->rge_game_options.scenarioGameValue;
}




int RGE_Base_Game::randomGame() const {
    return !this->rge_game_options.scenarioGameValue;
}




int RGE_Base_Game::campaignGame() const {
    return this->campaignGameValue;
}




int RGE_Base_Game::savedGame() const {
    return this->savedGameValue;
}




char* RGE_Base_Game::scenarioName() {
    return this->rge_game_options.scenarioNameValue;
}


int RGE_Base_Game::singlePlayerGame() const {
    return this->rge_game_options.singlePlayerGameValue;
}


int RGE_Base_Game::multiplayerGame() const {
    return this->rge_game_options.multiplayerGameValue;
}




int RGE_Base_Game::mapXSize() const {
    return this->rge_game_options.mapXSizeValue;
}




int RGE_Base_Game::mapYSize() const {
    return this->rge_game_options.mapYSizeValue;
}




int RGE_Base_Game::mapZSize() const {
    return this->rge_game_options.mapZSizeValue;
}




int RGE_Base_Game::allowCheatCodes() const {
    return this->rge_game_options.allowCheatCodesValue;
}




int RGE_Base_Game::cheatNotification() const {
    return this->rge_game_options.cheatNotificationValue;
}




int RGE_Base_Game::fullVisibility() const {
    return this->rge_game_options.fullVisibilityValue;
}




int RGE_Base_Game::fogOfWar() const {
    return this->rge_game_options.fogOfWarValue;
}




int RGE_Base_Game::coloredChat() const {
    return this->rge_game_options.coloredChatValue;
}




int RGE_Base_Game::gameDeveloperMode() const {
    return this->rge_game_options.gameDeveloperModeValue;
}


int RGE_Base_Game::playerHasCD(int i) {
    return this->rge_game_options.playerCDAndVersionValue[i] & 1;
}


unsigned char RGE_Base_Game::playerVersion(int i) {
    return this->rge_game_options.playerCDAndVersionValue[i] >> 1;
}




char* RGE_Base_Game::playerVersionString(int param)
{
    unsigned char v = playerVersion(param);

    switch (v) {
        case 0:   return "";
        case 1:   return "1.0";
        case 2:   return "1.0a";
        case 3:   return "1.0b";
        case 4:   return "1.0c";
        case 5:   return "1.0d";
        case 6:   return "1.0e";
        case 7:   return "1.1";
        case 8:   return "1.1a";
        case 9:   return "1.1b";
        case 10:  return "1.1c";
        case 11:  return "1.2";
        case 12:  return "1.2a";
        case 13:  return "1.2b";
        case 14:  return "1.2c";
        case 15:  return "1.3";
        case 16:  return "1.3a";
        case 17:  return "1.3b";
        case 18:  return "1.3c";
        case 19:  return "1.4";
        case 20:  return "1.4a";
        case 21:  return "1.4b";
        case 22:  return "1.4c";
        default:  return "1.X";
    }
}




unsigned char RGE_Base_Game::playerCDAndVersion(int idx) {
    return this->rge_game_options.playerCDAndVersionValue[idx];
}


int RGE_Base_Game::difficulty() {
    return this->rge_game_options.difficultyValue;
}


int RGE_Base_Game::numberPlayers() const {
    return this->rge_game_options.numberPlayersValue;
}


int RGE_Base_Game::playerTeam(int player) {
    return this->rge_game_options.playerTeamValue[player];
}




unsigned char RGE_Base_Game::pathFinding() {
    return this->pathFindingValue;
}




unsigned char RGE_Base_Game::mpPathFinding() {
    return this->rge_game_options.mpPathFindingValue;
}


static char game_summary_buf;


char* RGE_Base_Game::gameSummary() {
    game_summary_buf = 0;
    return &game_summary_buf;
}


void RGE_Base_Game::find_campaigns() {
    this->player_game_info->find_campaigns();
}




void RGE_Base_Game::setScenarioGame(int v) {
    this->rge_game_options.scenarioGameValue = v;
}




void RGE_Base_Game::setVersion(float v) {
    this->rge_game_options.versionValue = v;
}


void RGE_Base_Game::setScenarioName(char* name) {
    strncpy(this->rge_game_options.scenarioNameValue, name, 0x80);
    this->rge_game_options.scenarioNameValue[0x7F] = 0;
}




void RGE_Base_Game::setCampaignGame(int v) {
    this->campaignGameValue = v;
}




void RGE_Base_Game::setSavedGame(int v) {
    this->savedGameValue = v;
}


void RGE_Base_Game::setSinglePlayerGame(int v)
{
    this->rge_game_options.singlePlayerGameValue = (unsigned char)v;
    this->rge_game_options.multiplayerGameValue = (unsigned char)(v == 0);
}


void RGE_Base_Game::setMultiplayerGame(int v)
{
    this->rge_game_options.multiplayerGameValue = (unsigned char)v;
    this->rge_game_options.singlePlayerGameValue = (unsigned char)(v == 0);
}




void RGE_Base_Game::setMapSize(int a, int b, int c) {
    this->rge_game_options.mapXSizeValue = a;
    this->rge_game_options.mapYSizeValue = b;
    this->rge_game_options.mapZSizeValue = c;
}




void RGE_Base_Game::setAllowCheatCodes(int v) {
    this->rge_game_options.allowCheatCodesValue = v;
}




void RGE_Base_Game::setCheatNotification(int v) {
    this->rge_game_options.cheatNotificationValue = v;
}




void RGE_Base_Game::setFullVisibility(int v) {
    this->rge_game_options.fullVisibilityValue = v;
}




void RGE_Base_Game::setFogOfWar(int v) {
    this->rge_game_options.fogOfWarValue = v;
}




void RGE_Base_Game::setColoredChat(int v) {
    this->rge_game_options.coloredChatValue = v;
}




void RGE_Base_Game::setNumberPlayers(int v) {
    this->rge_game_options.numberPlayersValue = v;
}




void RGE_Base_Game::setGameDeveloperMode(int v) {
    this->rge_game_options.gameDeveloperModeValue = v;
}


void RGE_Base_Game::setPlayerHasCD(int player, int hasCD) {
    unsigned char val = this->rge_game_options.playerCDAndVersionValue[player];
    val = (val & 0xFE) | hasCD;
    this->rge_game_options.playerCDAndVersionValue[player] = val;
}


void RGE_Base_Game::setPlayerVersion(int player, unsigned char version) {
    unsigned char v = version << 1;
    unsigned char old = this->rge_game_options.playerCDAndVersionValue[player];
    v = v | (old & 1);
    this->rge_game_options.playerCDAndVersionValue[player] = v;
}


void RGE_Base_Game::setPlayerCDAndVersion(int i, unsigned char v) {
    this->rge_game_options.playerCDAndVersionValue[i] = v;
}




void RGE_Base_Game::setDifficulty(int v) {
    this->rge_game_options.difficultyValue = v;
}


void RGE_Base_Game::setPlayerTeam(int i, int v) {
    this->rge_game_options.playerTeamValue[i] = v;
}




void RGE_Base_Game::setPathFinding(unsigned char v) {
    this->pathFindingValue = v;
}




void RGE_Base_Game::setMpPathFinding(unsigned char v) {
    this->rge_game_options.mpPathFindingValue = v;
}


void RGE_Base_Game::set_map_visible(unsigned char param)
{
    if (this->world)
        this->world->set_map_visible((unsigned char)param);
}


void RGE_Base_Game::set_map_fog(unsigned char param)
{
    if (this->world)
        this->world->set_map_fog((unsigned char)param);
}


void RGE_Base_Game::turn_world_sound_off() {
    this->world->turn_sound_off();
}


int RGE_Base_Game::campaign_open_scenario() {
    return this->player_game_info->open_scenario();
}






long RGE_Base_Game::GetChecksum(long param_1) {
    RGE_Game_World* world = this->world;
    if (world != 0) {
        if (param_1 < 0) {
            return world->players[world->curr_player]->get_checksum();
        }
        if (param_1 < world->player_num) {
            return world->players[param_1]->get_checksum();
        }
    }
    return 0;
}






unsigned char RGE_Base_Game::GetWorldChecksums(long& checksum1, long& checksum2, long& checksum3)
{
    long c1;
    long c2;
    long c3;
    int i;
    RGE_Game_World* w;

    i = 0;
    c1 = 0;
    checksum1 = 0;
    checksum2 = 0;
    checksum3 = 0;
    w = world;
    c2 = 0;
    c3 = 0;
    if (w != 0) {
        if (w->player_num > 0) {
            do {
                w->players[i]->get_checksums(c1, c2, c3);
                checksum1 += c1;
                checksum2 += c2;
                checksum3 += c3;
                ++i;
                w = this->world;
            } while (i < w->player_num);
        }
        return 1;
    }
    return 0;
}






long RGE_Base_Game::GetWorldChecksum(void) {
    long sum;
    RGE_Game_World* world;

    sum = 0;
    world = this->world;
    if (world != 0) {
        int i = 0;
        if (world->player_num > 0) {
            do {
                sum += world->players[i]->get_checksum();
                world = this->world;
                i++;
            } while (i < world->player_num);
        }
        return sum;
    }
    return 0;
}




void RGE_Base_Game::disable_input() {
    if (this->is_mouse_on != 0) {
        HCURSOR cursor = LoadCursorA(0, IDC_WAIT);
        set_mouse_cursor(cursor);
    }
    panel_system.DisableInput();
    this->input_enabled = 0;
    if (this->input_disabled_window != 0) {
        if (GetCapture()) {
            ReleaseCapture();
        }
        SetCapture(this->input_disabled_window);
    }
}





void RGE_Base_Game::enable_input() {
    if (this->input_disabled_window != 0) {
        if (GetCapture()) {
            ReleaseCapture();
        }
    }
    panel_system.EnableInput();
    this->input_enabled = 1;
    if (this->is_mouse_on != 0) {
        HCURSOR cursor = LoadCursorA(0, IDC_ARROW);
        set_mouse_cursor(cursor);
    }
}


void RGE_Base_Game::set_screen_size(long width, long height)
{
    RECT win_rect;
    RECT client_rect;

    if (this->draw_area->Width != width || this->draw_area->Height != height) {
        if (this->draw_system->DrawType == 2 &&
            this->draw_system->ScreenMode == 2) {
            SetCursor(0);
            SetClassLongA(this->prog_window, -12, 0);
            this->mouse_pointer->Shutdown_Mouse();
            this->draw_system->SetDisplaySize(width, height, 8);
            this->draw_system->CheckSurfaces();
            this->draw_system->ClearRestored();
            this->set_render_all();
            restore_mouse_after_paint = 1;
            return;
        }

        int display_width = 0;
        int display_height = 0;
        HDC dc = CreateICA("DISPLAY", 0, 0, 0);
        if (dc != 0) {
            display_width = GetDeviceCaps(dc, 8);
            display_height = GetDeviceCaps(dc, 10);
            DeleteDC(dc);
        }

        if (width <= display_width && height <= display_height) {
            if (display_width == width && display_height == height) {
                this->window_style = 0x92080000;
                SetWindowLongA(this->prog_window, -16, 0x92080000);
                SetWindowLongA(this->prog_window, -20, this->window_style);
            } else {
                this->window_style = 0x12CA0000;
                SetWindowLongA(this->prog_window, -20, 0x12CA0000);
                SetWindowLongA(this->prog_window, -16, this->window_style);
            }

            SetWindowPos(this->prog_window, 0, 0, 0, width, height, 0);
            GetWindowRect(this->prog_window, &win_rect);
            GetClientRect(this->prog_window, &client_rect);

            if (client_rect.right != width || client_rect.bottom != height) {
                SetWindowPos(this->prog_window, 0,
                    win_rect.left, win_rect.top,
                    width + win_rect.right - win_rect.left - client_rect.right,
                    height + win_rect.bottom - win_rect.top - client_rect.bottom,
                    0);
            }
        }
    }
}

unsigned char RGE_Base_Game::check_prog_argument(char* param_1) {
    char buffer[256];

    strncpy(buffer, this->prog_info->cmd_line, 0xFF);
    buffer[0xFF] = 0;
    CharUpperA(buffer);
    if (strstr(buffer, param_1) != 0) {
        return 1;
    }
    return 0;
}


long RGE_Base_Game::get_scenario_checksum(char* scenario_name) {
    RGE_Scenario_Header* hdr = this->get_scenario_header(scenario_name, 0);
    if (!hdr) return 0;
    unsigned long checksum = hdr->checksum;
    delete hdr;
    return checksum;
}




unsigned char RGE_Base_Game::check_scenario_checksum(char* filename, long expected) {
    long cs = this->get_scenario_checksum(filename);
    if (cs != 0 && cs == expected) return 1;
    return 0;
}




void RGE_Base_Game::dump_memory_usage(char*) {
}




int RGE_Base_Game::playerID(int idx) {
    return this->playerIDValue[idx];
}


void RGE_Base_Game::setPlayerID(int i, int v) {
    this->playerIDValue[i] = v;
}


void RGE_Base_Game::reset_countdown_timer(long i) {
    this->countdown_timer[i] = -1;
}


void RGE_Base_Game::set_countdown_timer(long index, long value) {
    long current = this->countdown_timer[index];
    if (current > value || current < 0) {
        this->countdown_timer[index] = value;
    }
}




void RGE_Base_Game::get_countdown_timer(long index, long& output)
{
    output = this->countdown_timer[index];
}




int RGE_Base_Game::play_video(char*) {
    return 0;
}




void RGE_Base_Game::close_video(void)
{
}




void RGE_Base_Game::handle_video_notify(void)
{
}





int RGE_Base_Game::play_sound(int param_1)
{
    if (this->sounds == 0)
        return 0;

    if (this->sounds[param_1] == 0)
        return 0;

    if (this->sounds[param_1]->is_playing() != 0)
        return 1;

    return this->sounds[param_1]->play();
}




float RGE_Base_Game::get_game_speed() {
    return this->game_speed;
}




void RGE_Base_Game::set_game_speed(float v) {
    this->game_speed = v;
}




int RGE_Base_Game::get_single_player_difficulty() {
    return this->single_player_difficulty;
}




void RGE_Base_Game::set_single_player_difficulty(int v) {
    this->single_player_difficulty = v;
}





int RGE_Base_Game::setup_map_save_area()
{
    TDrawArea* area = new TDrawArea("Diamond Map Save Area", 0);
    this->map_save_area = area;

    if (area == 0) {
        return 0;
    }

    if (area->Init(this->draw_system, 0x118, 0x8C, 0, 0) == 0) {
        TDrawArea* to_delete = this->map_save_area;
        if (to_delete != 0) {
            delete to_delete;
        }
        this->map_save_area = 0;
        return 0;
    }

    return 1;
}


void RGE_Base_Game::reload_scenarios_info() {
    this->scenario_info->reload_scenarios();
}




void RGE_Base_Game::set_interface_messages(void)
{
}


void RGE_Base_Game::set_render_all()
{
    this->render_all = 1;
    panel_system.set_restore();
}


extern char debug_random_log[5000][100];
extern int debug_random_index;

void __cdecl debug_random_reset() {
    for (int index = 0; index < 25; ++index)
        debug_random_log[index][0] = 0;
    debug_random_index = -1;
}


extern int debug_random_index;
extern int wrote_debug_random_log;

void debug_random_write(void) {
    FILE* file;
    int index;
    const char* marker;

    file = fopen("c:\\aoerand.txt", "w");
    if (file == 0) {
        return;
    }

    index = 0;
    while (index < 5000) {
        if (index == debug_random_index) {
            marker = ">";
        }
        else {
            marker = " ";
        }
        fprintf(file, "%s%d - %s\n", marker, index,
                debug_random_log[index]);
        index++;
    }

    fclose(file);
    wrote_debug_random_log = 1;
}


extern int do_debug_random;
extern int debug_random_on;
extern int debug_random_index;
extern char debug_random_log[5000][100];

int __cdecl debug_rand(char* param_1, int param_2)
{
    int rv = rand();
    if (do_debug_random && debug_random_on) {
        char temp_name[9];
        param_1 += 10;
        char* dst = temp_name;
        char* end = param_1 + 8;
        char c = *param_1;
        while (c != '.' && param_1 < end) {
            *dst = c;
            c = param_1[1];
            ++dst;
            ++param_1;
        }
        int idx = debug_random_index;
        *dst = 0;
        if (idx < 4999)
            ++idx;
        else
            idx = 0;
        debug_random_index = idx;
        sprintf(debug_random_log[idx], "t%d,%s,l%d,r%d",
                rge_base_game->world->world_time, temp_name, param_2, rv);
    }
    return rv;
}


extern int do_debug_random;
extern int debug_random_on;
extern int debug_random_index;
extern char debug_random_log[5000][100];



void __cdecl debug_srand(char* param_1, int param_2,
                                     unsigned int param_3)
{
    if (do_debug_random && debug_random_on) {
        char buf[9]; param_1 += 10; char* d = buf; char* end = param_1 + 8; char c = *param_1;
        while (c != '.' && param_1 < end) { *d = c; c = param_1[1]; d++; param_1++; }
        *d = 0;
        int idx = debug_random_index;
        if (idx < 4999) idx++; else idx = 0;
        debug_random_index = idx;
        sprintf(debug_random_log[idx], "t%d,%s,l%d,s%u", rge_base_game->world->world_time, buf, param_2, param_3);
    }
    srand(param_3);
}
extern int do_debug_timeGetTime;
extern int debug_timeGetTime_cnt;
extern int debug_timeGetTime_interval;
extern int debug_timeGetTime_time;

unsigned long __cdecl debug_timeGetTime(char* param_1, int param_2) {
    if (do_debug_timeGetTime != 0 && debug_timeGetTime_on != 0) {
        debug_timeGetTime_cnt = debug_timeGetTime_cnt + 1;
        if (debug_timeGetTime_cnt == debug_timeGetTime_interval) {
            debug_timeGetTime_cnt = 0;
            debug_timeGetTime_time = debug_timeGetTime_time + 1;
        }
        return debug_timeGetTime_time;
    }
    return timeGetTime();
}
