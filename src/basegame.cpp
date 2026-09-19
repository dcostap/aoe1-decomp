
#include <windows.h>
#include <fcntl.h>
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
#include "../include/sprite.h"
#include "../include/pathsys.h"
#include "../include/colorlog.h"
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
#include "../include/resource_ids.h"

extern FILE* draw_log;
extern char draw_log_name[260];

void __cdecl write_draw_log(char* s) {
    if (draw_log != 0) {
        fprintf(draw_log, "%s", s);
        fflush(draw_log);
    }
}

void __cdecl write_draw_log2(char* s) {
    if (draw_log != 0) {
        fprintf(draw_log, "%s", s);
        fclose(draw_log);
        draw_log = fopen(draw_log_name, "a+");
    }
}

LRESULT CALLBACK rge_base_game_wnd_proc(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    RGE_Base_Game* game = rge_base_game;
    if (game != 0)
        return game->wnd_proc(wnd, msg, wparam, lparam);
    return 0;
}

RGE_Base_Game::RGE_Base_Game(RGE_Prog_Info* prog_info_in, int do_setup)
    : player_game_info(0),
      random_game_seed(-1),
      random_map_seed(-1),
      save_random_game_seed(-1),
      save_random_map_seed(-1),
      quick_build(0) {
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
    this->setMapSize(96, 96, 8);
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
    this->prog_info = prog_info_in;
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
    GetCurrentDirectoryA(261, this->work_dir);

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
        this->error_code = RGE_ERROR_SETUP_REGISTRY;
        return;
    }
    Regs = this->registry;
    if (!this->setup_debugging_log()) {
        this->error_code = RGE_ERROR_SETUP_DEBUG_LOG;
        return;
    }
    L = this->debugLog;
    if (do_setup) {
        if (!this->setup()) {
            if (!this->error_code)
                this->error_code = RGE_ERROR_SETUP;
        }
    }
    this->display_selected_ids = 0;
}

void __cdecl debug_srand(char* file, int line,
                         unsigned int seed);
extern void __cdecl GetDXVersion(unsigned long* version, unsigned long* platform);
extern int debugActions;
extern int do_fps_log;
extern FILE* fps_log;

enum {
    RGE_REQUIRED_DIRECTX_VERSION = 0x501
};

#define RGE_MB(value) ((unsigned long)(value) * 1024UL * 1024UL)

int RGE_Base_Game::setup() {
    int temp_val;
    MEMORYSTATUS ms;
    char filename[260];
    char s[256];
    OFSTRUCT of;
    _finddata_t file_info;
    debug_srand("C:\\msdev\\work\\age1_x1\\basegame.cpp", 522, debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 522));

    temp_val = this->registry->RegGetInt(1, "Screen Size");
    switch (temp_val) {
    case 640:
        this->prog_info->main_wid = temp_val;
        this->prog_info->main_hgt = 480;
        break;
    case 800:
        this->prog_info->main_wid = temp_val;
        this->prog_info->main_hgt = 600;
        break;
    case 1024:
        this->prog_info->main_wid = temp_val;
        this->prog_info->main_hgt = 768;
        break;
    case 1280:
        this->prog_info->main_wid = temp_val;
        this->prog_info->main_hgt = 1024;
        break;
    }

    temp_val = this->registry->RegGetInt(1, "Rollover Text");
    if (temp_val == 2)
        this->rollover = 0;
    else
        this->rollover = 1;

    temp_val = this->registry->RegGetInt(1, "Mouse Style");
    if (temp_val == 2)
        this->prog_info->interface_style = 2;
    else if (temp_val == 1)
        this->prog_info->interface_style = 1;

    temp_val = this->registry->RegGetInt(1, "Game Speed");
    if (temp_val != -1)
        this->game_speed = (float)temp_val * 0.1f;

    temp_val = this->registry->RegGetInt(1, "Difficulty");
    if (temp_val != -1)
        this->single_player_difficulty = temp_val;

    temp_val = this->registry->RegGetInt(1, "Path Finding");
    if (temp_val >= 1 && temp_val <= 3)
        this->setPathFinding((unsigned char)(temp_val - 1));

    temp_val = this->registry->RegGetInt(1, "MP Path Finding");
    if (temp_val >= 1 && temp_val <= 3)
        this->setMpPathFinding((unsigned char)(temp_val - 1));

    temp_val = this->registry->RegGetInt(1, "Scroll Speed");
    if (temp_val != -1 && temp_val >= 10 && temp_val <= 200) {
        this->prog_info->mouse_scroll_interval = temp_val;
        this->prog_info->key_scroll_interval = temp_val;
    }

    if (_findfirst("empires.exe", &file_info) == -1) {
        this->error_code = RGE_ERROR_GAME_EXECUTABLE;
    } else {
        if (!this->setup_cmd_options()) {
            this->error_code = RGE_ERROR_SETUP_COMMAND_OPTIONS;
        } else {
            StringTable = LoadLibraryA(this->string_dll_name);
            if (StringTable == 0) {
                this->error_code = RGE_ERROR_SETUP;
            } else {
                GlobalMemoryStatus(&ms);
                if ((ms.dwTotalPageFile >= RGE_MB(20) && ms.dwTotalVirtual >= RGE_MB(10))
                    || (ms.dwTotalPageFile >= RGE_MB(10) && ms.dwTotalVirtual >= RGE_MB(20))
                    || ms.dwTotalVirtual >= RGE_MB(30)) {
                    this->set_interface_messages();

                    if (debugActions == 1)
                        actionFile = fopen("c:\\aoeact.txt", "w");

                    unsigned long DXVersion;
                    unsigned long DXPlatform;
                    if (this->prog_info->check_expiration != 0 && this->check_expiration() == 0) {
                        this->error_code = RGE_ERROR_CHECK_EXPIRATION;
                    } else if (this->prog_info->check_multi_copies != 0 && this->check_multi_copies() == 0) {
                        this->error_code = RGE_ERROR_CHECK_MULTI_COPIES;
                    } else if (this->check_prog_argument("NODXCHECK") == 0 && (GetDXVersion(&DXVersion, &DXPlatform), DXVersion < RGE_REQUIRED_DIRECTX_VERSION)) {
                        this->error_code = RGE_ERROR_DIRECTX_VERSION;
                    } else {
                        SystemParametersInfoA(SPI_GETSCREENSAVEACTIVE, 0, &this->screen_saver_enabled, 0);
                        if (this->screen_saver_enabled != 0)
                            SystemParametersInfoA(SPI_SETSCREENSAVEACTIVE, 0, 0, SPIF_SENDCHANGE);
                        SystemParametersInfoA(SPI_GETLOWPOWERACTIVE, 0, &this->low_power_enabled, 0);
                        if (this->low_power_enabled != 0)
                            SystemParametersInfoA(SPI_SETLOWPOWERACTIVE, 0, 0, SPIF_SENDCHANGE);

                        this->save_check_for_cd = this->check_for_cd(0);
                        if (!this->setup_class())
                            this->error_code = RGE_ERROR_SETUP_CLASS;
                        else if (!this->setup_main_window())
                            this->error_code = RGE_ERROR_SETUP_MAIN_WINDOW;
                        else if (!this->setup_graphics_system()) {
                            if (this->error_code == RGE_ERROR_NONE)
                                this->error_code = RGE_ERROR_SETUP_GRAPHICS;
                        } else if (!this->setup_palette())
                            this->error_code = RGE_ERROR_SETUP_PALETTE;
                        else if (!this->setup_shapes())
                            this->error_code = RGE_ERROR_SETUP_GRAPHICS;
                        else if (!this->setup_map_save_area())
                            this->error_code = RGE_ERROR_SETUP_GRAPHICS;
                        else if (!this->setup_mouse())
                            this->error_code = RGE_ERROR_SETUP_MOUSE;
                        else if (!this->setup_sound_system())
                            this->error_code = RGE_ERROR_SETUP_SOUND;
                        else if (!this->setup_chat())
                            this->error_code = RGE_ERROR_SETUP_CHAT;
                        else if (!this->setup_comm())
                            this->error_code = RGE_ERROR_SETUP_COMM;
                        else if (!this->setup_fonts())
                            this->error_code = RGE_ERROR_SETUP_FONTS;
                        else if (!this->setup_sounds())
                            this->error_code = RGE_ERROR_SETUP_SOUNDS;
                        else {
                            driveInfo = new DriveInformation;
                            if (driveInfo != 0) {
                                if (!this->setup_blank_screen()) {
                                    this->error_code = RGE_ERROR_SETUP_BLANK_SCREEN;
                                } else {
                                    int file_number;
                                    this->set_prog_mode(0);
                                    this->setup_timings();
                                    this->handle_size(this->prog_window, 0, 0, 0);
                                    this->prog_ready = 1;
                                    ShowWindow(this->prog_window, SW_SHOW);
                                    SetFocus(this->prog_window);
                                    this->mouse_on();
                                    this->is_timer = SetTimer(this->prog_window, 1, 50, 0);

                                    file_number = this->registry->RegGetInt(0, "Game File Number");
                                    if (file_number >= 0) {
                                        file_number = this->registry->RegGetInt(0, "Game File Number");
                                        sprintf(filename, "game%d.nfo", file_number);
                                        this->player_game_info =
                                            new RGE_Game_Info(filename);
                                    } else {
                                        int i;
                                        for (i = 0; i < 9999; ++i) {
                                            sprintf(filename, "game%d.nfo", i);
                                            if (_findfirst(filename, &file_info) == -1) {
                                                this->registry->RegSetInt(0, "Game File Number", i);
                                                this->player_game_info =
                                                    new RGE_Game_Info(filename);
                                                break;
                                            }
                                        }
                                    }
                                    sprintf(filename, "%sscenario.inf", this->prog_info->scenario_dir);
                                    this->scenario_info = new RGE_Scenario_File_Info(filename);

                                    if (do_draw_log != 0) {
                                        if (draw_log_name[0] == 0) {
                                            int i;
                                            for (i = 0; i < 1000; ++i) {
                                                sprintf(s, "drawlog%d.txt", i);
                                                if (OpenFile(s, &of, OF_EXIST) == -1) {
                                                    draw_log = fopen(s, "w");
                                                    strcpy(draw_log_name, s);
                                                    break;
                                                }
                                            }
                                        } else {
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
                } else {
                    this->error_code = RGE_ERROR_MEMORY;
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

RGE_Base_Game::~RGE_Base_Game() {
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

    this->registry->RegSetInt(1, "Rollover Text", 2 + (this->rollover ? -1 : 0));

    if (this->prog_info->interface_style == 2)
        this->registry->RegSetInt(1, "Mouse Style", 2);
    else
        this->registry->RegSetInt(1, "Mouse Style", 1);

    this->registry->RegSetInt(1, "Game Speed", (int)(this->game_speed * 10.0f));
    this->registry->RegSetInt(1, "Difficulty", this->single_player_difficulty);
    this->registry->RegSetInt(1, "Path Finding", this->pathFinding() + 1);
    this->registry->RegSetInt(1, "MP Path Finding", this->mpPathFinding() + 1);
    this->registry->RegSetInt(1, "Scroll Speed", this->prog_info->mouse_scroll_interval);

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
        i = 0;
        if (this->font_num > 0) {
            do {
                if (this->fonts[i].font)
                    DeleteObject(this->fonts[i].font);
                i++;
            } while (i < this->font_num);
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
        SystemParametersInfoA(SPI_SETSCREENSAVEACTIVE, 1, 0, SPIF_SENDCHANGE);
    if (this->low_power_enabled != 0)
        SystemParametersInfoA(SPI_SETLOWPOWERACTIVE, 1, 0, SPIF_SENDCHANGE);

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

    this->get_string(STRING_ID_HELP_WINDOW_TITLE, str, 256);
    if (str[0] != 0) {
        HWND help_window = FindWindowA("MS_WINHELP", str);
        if (help_window != 0)
            SendMessageA(help_window, WM_CLOSE, 0, 0);
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

void RGE_Base_Game::add_to_timing(int id, unsigned long time) {
    timings[id].accum_time += time;
    timings[id].last_single_time = time;
    if (time > timings[id].max_time) {
        timings[id].max_time = time;
    }
}

void RGE_Base_Game::increment_world_update_count() {
    this->world_update_count++;
}

void RGE_Base_Game::increment_view_update_count() {
    this->view_update_count++;
}

void RGE_Base_Game::set_last_single_time(int id, unsigned long time) {
    this->timings[id].last_single_time = time;
}

unsigned long RGE_Base_Game::get_last_time(int id) {
    return this->timings[id].last_time;
}

unsigned long RGE_Base_Game::get_last_single_time(int id) {
    return this->timings[id].last_single_time;
}

unsigned long RGE_Base_Game::get_accum_time(int id) {
    return this->timings[id].accum_time;
}

unsigned long RGE_Base_Game::get_max_time(int id) {
    return this->timings[id].max_time;
}

unsigned long RGE_Base_Game::get_last_max_time(int id) {
    return this->timings[id].last_max_time;
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

static char g_string_buffer[512];

char* RGE_Base_Game::get_string(long text_id) {
    // The next get_string(long) call overwrites this shared buffer.
    this->get_string(text_id, g_string_buffer, 512);
    return g_string_buffer;
}

char* RGE_Base_Game::get_string(long string_id, char* str, int max_len) {
    int result = LoadStringA(StringTable, string_id, str, max_len);
    if (!result) {
        *str = 0;
    }
    str[max_len - 1] = 0;
    return str;
}

char* RGE_Base_Game::get_string(int string_type, long id, char* str, int max_len) {
    return this->get_string2(string_type, id, 0, str, max_len);
}

char* RGE_Base_Game::get_string2(int string_type, long id, long id2, char* str, int max_len) {
    *str = 0;

    switch (string_type) {
    case RGE_STRING_TYPE_ERROR:
        switch (id) {
        case RGE_ERROR_SETUP:
        case RGE_ERROR_SETUP_COMMAND_OPTIONS:
        case RGE_ERROR_CHECK_EXPIRATION:
        case RGE_ERROR_CHECK_MULTI_COPIES:
        case RGE_ERROR_SETUP_CLASS:
        case RGE_ERROR_SETUP_MAIN_WINDOW:
        case RGE_ERROR_SETUP_REGISTRY:
        case RGE_ERROR_SETUP_DEBUG_LOG:
            return this->get_string(STRING_ID_ERROR_INITIALIZE_PROGRAM, str, max_len);
        case RGE_ERROR_SETUP_GRAPHICS:
        case RGE_ERROR_SETUP_MOUSE:
        case RGE_ERROR_SETUP_FONTS:
        case RGE_ERROR_SETUP_BLANK_SCREEN:
        case RGE_ERROR_SETUP_PALETTE:
            return this->get_string(STRING_ID_ERROR_INITIALIZE_GRAPHICS, str, max_len);
        case RGE_ERROR_SETUP_COLOR_DEPTH:
            return this->get_string(STRING_ID_ERROR_COLOR_PALETTE, str, max_len);
        case RGE_ERROR_SETUP_COMM:
        case RGE_ERROR_SETUP_CHAT:
            return this->get_string(STRING_ID_ERROR_INITIALIZE_COMMUNICATIONS, str, max_len);
        case RGE_ERROR_SETUP_SOUND:
        case RGE_ERROR_SETUP_SOUNDS:
            return this->get_string(STRING_ID_ERROR_INITIALIZE_SOUND, str, max_len);
        case RGE_ERROR_OUT_OF_SYNC:
            return this->get_string(STRING_ID_ERROR_OUT_OF_SYNC, str, max_len);
        case RGE_ERROR_DIRECTX_VERSION:
            return this->get_string(STRING_ID_ERROR_DIRECTX_VERSION, str, max_len);
        case RGE_ERROR_WINDOWS_VERSION:
            return this->get_string(STRING_ID_ERROR_WINDOWS_VERSION, str, max_len);
        case RGE_ERROR_MEMORY:
            return this->get_string(STRING_ID_ERROR_MEMORY, str, max_len);
        case RGE_ERROR_GAME_EXECUTABLE:
            return this->get_string(STRING_ID_ERROR_GAME_EXECUTABLE, str, max_len);
        default:
            break;
        }
        break;
    case RGE_STRING_TYPE_RESOURCE:
        return this->get_string(id, str, max_len);
    default:
        break;
    }

    str[max_len - 1] = 0;
    return str;
}

extern int rge_open(char* path, int flags);
extern void rge_read_uncompressed(int fd, void* buf, int len);
extern void rge_read(int fd, void* buf, int len);
extern int rge_close(int fd);

RGE_Scenario* RGE_Base_Game::get_scenario_info(char* scenario_file, int from_campaign) {
    char temp_name[300];
    int fd;
    int version;
    int obj_id;
    int header_size;
    RGE_Scenario* result;
    void* buf;

    sprintf(temp_name, "%s%s", this->prog_info->scenario_dir, scenario_file);

    if (from_campaign) {
        fd = this->player_game_info->open_scenario();
    } else {
        if (!scenario_file)
            return 0;
        fd = rge_open(temp_name, _O_BINARY);
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


RGE_Scenario_Header* RGE_Base_Game::get_scenario_header(char* scenario_file, int from_campaign) {
    char temp_name[300];
    long version;
    int fd;
    RGE_Scenario_Header* result;

    sprintf(temp_name, "%s%s", this->prog_info->scenario_dir, scenario_file);

    if (from_campaign) {
        fd = this->player_game_info->open_scenario();
    } else {
        if (!scenario_file)
            return 0;
        fd = rge_open(temp_name, _O_BINARY);
    }

    if (fd == -1)
        return 0;

    rge_read_uncompressed(fd, &version, sizeof(version));

    result = 0;
    if (version == *(const long*)"1.03" || version == *(const long*)"1.04" || version == *(const long*)"1.05" ||
        version == *(const long*)"1.06" || version == *(const long*)"1.07" || version == *(const long*)"1.08" ||
        version == *(const long*)"1.09" || version == *(const long*)"1.10" || version == *(const long*)"1.11") {
        result = this->new_scenario_header(fd);
    }

    rge_close(fd);
    return result;
}

void RGE_Base_Game::write_scenario_header(int outfile) {
    RGE_Scenario_Header* header = new_scenario_header(world->scenario);

    if (header != 0) {
        header->save(outfile);
        delete header;
    } else {
        int header_size = 0;
        rge_write_uncompressed(outfile, &header_size, sizeof(header_size));
    }
}

RGE_Scenario_Header* RGE_Base_Game::new_scenario_header(int infile) {
    return new RGE_Scenario_Header(infile);
}

RGE_Scenario_Header* RGE_Base_Game::new_scenario_header(RGE_Scenario* scenario_info) {
    return new RGE_Scenario_Header(scenario_info);
}

RGE_Scenario* RGE_Base_Game::new_scenario_info(int infile) {
    return new RGE_Scenario(infile, 0);
}

void RGE_Base_Game::get_campaign_info(long& campaign, long& campaign_player, long& campaign_scenario) {
    int c = this->player_game_info->get_current_campaign();
    campaign = c;
    int p = this->player_game_info->get_current_player();
    campaign_player = p;
    int n = this->player_game_info->get_current_scenario();
    campaign_scenario = n;
}

unsigned char RGE_Base_Game::set_campaign_info(long campaign, long campaign_player, long campaign_scenario) {
    unsigned char ok;

    ok = this->player_game_info->set_current_campaign(campaign);
    if (ok != 0) {
        ok = this->player_game_info->set_current_person(campaign_player);
        if (ok != 0) {
            ok = this->player_game_info->set_current_scenario(campaign_scenario);
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

int RGE_Base_Game::run() {
    MSG msg;

    while (1) {
        if (this->prog_active != 0 && (this->prog_mode == 4 || this->prog_mode == 2)) {
            TCommunications_Handler* comm = this->comm_handler;
            if (comm == 0 || comm->IsPaused() == 0) {
                if (PeekMessageA(&msg, 0, 0, 0, PM_REMOVE) != 0) {
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

extern int startLoggingAI;

extern "C" {
char* __cdecl _mbsstr(const char* str, const char* substr);
char* __cdecl _mbsninc(const char* str, unsigned int count);
int __cdecl _ismbcspace(unsigned int c);
char* __cdecl _mbsncat(char* dst, const char* src, unsigned int count);
}

extern int do_run_log;
extern int do_debug_timeGetTime;
extern int debug_timeGetTime_interval;
extern int chatCheatCodes;
extern int logUpdateChanges;
extern int useInfluencePlacement;
extern int all_grassland_on;
extern int useNewPathing;
extern int pathingCapValue;
extern int force_cd;
extern int Sys_DDLOG_Enable;
extern int Sys_DDLOG_ErrorOn;
extern int DDlogAutoFlush;
extern int debug_log_lock;
extern int logDebugID;
extern int speed_val1;
extern int speed_val2;
extern int log_output;
extern int DDSys_CanColorFill;

int RGE_Base_Game::setup_cmd_options() {
    char cmd_line[256];
    char temp_str[256];
    char character;
    char* argument;

    strncpy(cmd_line, this->prog_info->cmd_line, 255);
    cmd_line[255] = 0;
    CharUpperA(cmd_line);

    if ((strstr(cmd_line, "NOSTARTUP") != 0) || (strstr(cmd_line, "NO STARTUP") != 0) || (strstr(cmd_line, "NO_STARTUP") != 0)) {
        this->prog_info->skip_startup = 1;
    }

    if ((strstr(cmd_line, "SYSTEMMEMORY") != 0) || (strstr(cmd_line, "SYSTEM MEMORY") != 0) || (strstr(cmd_line, "SYSTEM_MEMORY") != 0)) {
        this->prog_info->use_sys_mem = 1;
    }

    if ((strstr(cmd_line, "MIDIMUSIC") != 0) || (strstr(cmd_line, "MIDI MUSIC") != 0) || (strstr(cmd_line, "MIDI_MUSIC") != 0)) {
        this->prog_info->use_music = 1;
        this->prog_info->use_cd_audio = 0;
        this->prog_info->use_ima = 0;
        this->prog_info->use_midi = 1;
        this->prog_info->use_wave_music = 0;
    }

    if (strstr(cmd_line, "MSYNC") != 0) {
        this->mouse_blit_sync = 1;
    }

    DDSys_CanColorFill = (strstr(cmd_line, "MFILL") == 0);

    if ((strstr(cmd_line, "NOSOUND") != 0) || (strstr(cmd_line, "NO SOUND") != 0) || (strstr(cmd_line, "NO_SOUND") != 0)) {
        this->prog_info->use_sound = 0;
    }

    if (strstr(cmd_line, "640") != 0) {
        this->prog_info->main_wid = 640;
        this->prog_info->main_hgt = 480;
    }

    if (strstr(cmd_line, "800") != 0) {
        this->prog_info->main_wid = 800;
        this->prog_info->main_hgt = 600;
    }

    if (strstr(cmd_line, "1024") != 0) {
        this->prog_info->main_wid = 1024;
        this->prog_info->main_hgt = 768;
    }

    if (strstr(cmd_line, "ALLCP") != 0) {
        all_cp = 1;
        do_run_log = 1;
        this->comm_speed = 0;
        do_debug_timeGetTime = 1;
        debug_timeGetTime_interval = 10;
        do_fixed_update = 1;
        fixed_update_time = 20;
    }

    argument = _mbsstr(cmd_line, "RESEND1");
    if (argument) {
        character = *argument;
        while (character != '=') {
            argument = _mbsninc(argument, 1);
            character = *argument;
        }
        argument = _mbsninc(argument, 1);
        temp_str[0] = 0;
        while (!_ismbcspace((unsigned char)*argument) && *argument != 0) {
            _mbsncat(temp_str, argument, 1);
            argument = _mbsninc(argument, 1);
        }
        resend_adj1 = atol(temp_str);
    }

    argument = _mbsstr(cmd_line, "RESEND2");
    if (argument) {
        character = *argument;
        while (character != '=') {
            argument = _mbsninc(argument, 1);
            character = *argument;
        }
        argument = _mbsninc(argument, 1);
        temp_str[0] = 0;
        while (!_ismbcspace((unsigned char)*argument) && *argument != 0) {
            _mbsncat(temp_str, argument, 1);
            argument = _mbsninc(argument, 1);
        }
        resend_adj2 = atol(temp_str);
    }

    if ((strstr(cmd_line, "NOMOUSE") != 0) || (strstr(cmd_line, "NO_MOUSE") != 0)) {
        this->custom_mouse = 0;
    }

    if (strstr(cmd_line, "WING") != 0) {
        this->prog_info->full_screen = 0;
        this->prog_info->use_dir_draw = 0;
    }

    if ((strstr(cmd_line, "DIRECTDRAW") != 0) || (strstr(cmd_line, "DIRECT DRAW") != 0)) {
        this->prog_info->use_dir_draw = 1;
    }

    if ((strstr(cmd_line, "FULLSCREEN") != 0) || (strstr(cmd_line, "FULL SCREEN") != 0) || (strstr(cmd_line, "FULL_SCREEN") != 0)) {
        this->prog_info->full_screen = 1;
        this->prog_info->use_dir_draw = 1;
    }

    if ((strstr(cmd_line, "VIDEOMEMORY") != 0) || (strstr(cmd_line, "VIDEO MEMORY") != 0) || (strstr(cmd_line, "VIDEO_MEMORY") != 0)) {
        this->prog_info->use_sys_mem = 0;
    }

    if ((strstr(cmd_line, "STREAMMUSIC") != 0) || (strstr(cmd_line, "STREAM MUSIC") != 0) || (strstr(cmd_line, "STREAM_MUSIC") != 0)) {
        this->prog_info->use_music = 1;
        this->prog_info->use_cd_audio = 0;
        this->prog_info->use_ima = 0;
        this->prog_info->use_midi = 0;
        this->prog_info->use_wave_music = 1;
    }

    if ((strstr(cmd_line, "IMAMUSIC") != 0) || (strstr(cmd_line, "IMA MUSIC") != 0) || (strstr(cmd_line, "IMA_MUSIC") != 0)) {
        this->prog_info->use_music = 1;
        this->prog_info->use_cd_audio = 0;
        this->prog_info->use_ima = 1;
        this->prog_info->use_midi = 0;
        this->prog_info->use_wave_music = 0;
    }

    if ((strstr(cmd_line, "FASTVIEW") != 0) || (strstr(cmd_line, "FAST VIEW") != 0) || (strstr(cmd_line, "FAST_VIEW") != 0)) {
        this->prog_info->fast_view = 1;
    }

    if ((strstr(cmd_line, "SLOWVIEW") != 0) || (strstr(cmd_line, "SLOW VIEW") != 0) || (strstr(cmd_line, "SLOW_VIEW") != 0)) {
        this->prog_info->fast_view = 0;
    }

    if ((strstr(cmd_line, "ONEBUTTON") != 0) || (strstr(cmd_line, "ONE BUTTON") != 0) || (strstr(cmd_line, "ONE_BUTTON") != 0)) {
        this->prog_info->interface_style = 1;
    }

    if ((strstr(cmd_line, "TWOBUTTON") != 0) || (strstr(cmd_line, "TWO BUTTON") != 0) || (strstr(cmd_line, "TWO_BUTTON") != 0)) {
        this->prog_info->interface_style = 2;
    }

    if (strstr(cmd_line, "RUNLOG")) {
        do_run_log = 1;
    }

    if (strstr(cmd_line, "SYNCMSG")) {
        this->comm_syncmsg = 1;
    }

    if (strstr(cmd_line, "DROPPACKETS")) {
        this->comm_droppackets = 1;
    }

    if (strstr(cmd_line, "NOCOMMSPEED")) {
        this->comm_speed = 0;
    }

    if (strstr(cmd_line, "SYNCSTOP")) {
        this->comm_syncstop = 1;
    }

    if (strstr(cmd_line, "STEPMODE")) {
        this->comm_stepmode = 1;
    }

    if ((strstr(cmd_line, "SQUAREOUTLINE") != 0) || (strstr(cmd_line, "SQUARE OUTLINE") != 0) || (strstr(cmd_line, "SQUARE_OUTLINE") != 0)) {
        this->outline_type = 0;
    }

    if ((strstr(cmd_line, "CUBEOUTLINE") != 0) || (strstr(cmd_line, "CUBE OUTLINE") != 0) || (strstr(cmd_line, "CUBE_OUTLINE") != 0)) {
        this->outline_type = 1;
    }

    if ((strstr(cmd_line, "GROUNDOUTLINE") != 0) || (strstr(cmd_line, "GROUND OUTLINE") != 0) || (strstr(cmd_line, "GROUND_OUTLINE") != 0)) {
        this->outline_type = 2;
    }

    if ((strstr(cmd_line, "EDGEOUTLINE") != 0) || (strstr(cmd_line, "EDGE OUTLINE") != 0) || (strstr(cmd_line, "EDGE_OUTLINE") != 0)) {
        this->outline_type = 3;
    }

    if ((strstr(cmd_line, "CUSTOMMOUSE") != 0) || (strstr(cmd_line, "CUSTOM MOUSE") != 0) || (strstr(cmd_line, "CUSTOM_MOUSE") != 0)) {
        this->custom_mouse = 1;
    }

    if (strstr(cmd_line, "NOCP")) {
        useComputerPlayers = 0;
    }

    if (strstr(cmd_line, "LOGAI")) {
        startLoggingAI = 1;
    }

    if (strstr(cmd_line, "NOLOGSTATUS")) {
        logStatusOn = 0;
    }

    if (strstr(cmd_line, "DOLOGSTATUS")) {
        logStatusOn = 1;
    }

    if (strstr(cmd_line, "NOAICHEAT")) {
        allowAIToCheat = 0;
    }

    if (strstr(cmd_line, "NOCHATCHEATCODES")) {
        chatCheatCodes = 0;
    }

    if (strstr(cmd_line, "LOGUPDATECHANGES")) {
        logUpdateChanges = 1;
    }

    if (strstr(cmd_line, "UIP")) {
        useInfluencePlacement = 1;
    }

    if (strstr(cmd_line, "ALLGRASS")) {
        all_grassland_on = 1;
    }

    if (strstr(cmd_line, "ALLCP")) {
        all_cp = 1;
    }

    if (strstr(cmd_line, "ALLCP1")) {
        all_cp = 2;
    }

    if (strstr(cmd_line, "NOPATHLIMIT")) {
        numberPathingIterations = -1;
    }

    if (strstr(cmd_line, "UNP")) {
        useNewPathing = -1;
    }

    if (strstr(cmd_line, "COLORLOG")) {
        do_color_log = 1;
    }

    argument = _mbsstr(cmd_line, "LOGAI");
    if (argument) {
        character = *argument;
        while (character != '=') {
            argument = _mbsninc(argument, 1);
            character = *argument;
        }
        argument = _mbsninc(argument, 1);
        temp_str[0] = 0;
        while (!_ismbcspace((unsigned char)*argument) && *argument != 0) {
            _mbsncat(temp_str, argument, 1);
            argument = _mbsninc(argument, 1);
        }
        specificAIPlayerToLog = atol(temp_str);
    }

    argument = _mbsstr(cmd_line, "LOGDEBUG");
    if (argument) {
        character = *argument;
        while (character != '=') {
            argument = _mbsninc(argument, 1);
            character = *argument;
        }
        argument = _mbsninc(argument, 1);
        temp_str[0] = 0;
        while (!_ismbcspace((unsigned char)*argument) && *argument != 0) {
            _mbsncat(temp_str, argument, 1);
            argument = _mbsninc(argument, 1);
        }
        logDebugID = atol(temp_str);
    }

    if (strstr(cmd_line, "NOPATHCAP")) {
        pathingCapValue = -1;
    }

    if (strstr(cmd_line, "GAMECD")) {
        force_cd = 1;
    }

    if (strstr(cmd_line, "1280")) {
        this->prog_info->main_wid = 1280;
        this->prog_info->main_hgt = 1024;
    }

    if ((strstr(cmd_line, "LOGFPS") != 0) || (strstr(cmd_line, "LOG FPS") != 0) || (strstr(cmd_line, "LOG_FPS") != 0)) {
        do_fps_log = 1;
    }

    if (strstr(cmd_line, "DDERRORLOG")) {
        Sys_DDLOG_Enable = 1;
        Sys_DDLOG_ErrorOn = 1;
    }

    if (strstr(cmd_line, "DDLOG")) {
        Sys_DDLOG_Enable = 1;
        Sys_DDLOG_ErrorOn = 0;
    }

    if (strstr(cmd_line, "DDFLUSHLOG")) {
        DDlogAutoFlush = 1;
    }

    if (strstr(cmd_line, "DDNOFLUSHLOG")) {
        DDlogAutoFlush = 0;
    }

    if (strstr(cmd_line, "DDLOCKLOG")) {
        debug_log_lock = 1;
    }

    if (strstr(cmd_line, "LOGRANDOM")) {
        do_debug_random = 1;
    }

    if (strstr(cmd_line, "FIXEDUPDATE")) {
        do_debug_timeGetTime = 1;
        do_fixed_update = 1;
    }

    if (strstr(cmd_line, "LOGACTION")) {
        debugActions = 1;
    }

    if (strstr(cmd_line, "RES_WARN")) {
        RESFILE_Set_Missing_Flag(1);
    }

    argument = _mbsstr(cmd_line, "SCENARIOS");
    if (argument) {
        character = *argument;
        while (character != '=') {
            argument = _mbsninc(argument, 1);
            character = *argument;
        }
        argument = _mbsninc(argument, 1);
        this->prog_info->scenario_dir[0] = 0;
        while (!_ismbcspace((unsigned char)*argument) && *argument != 0) {
            _mbsncat(this->prog_info->scenario_dir, argument, 1);
            argument = _mbsninc(argument, 1);
        }
        _mbsncat(this->prog_info->scenario_dir, "\\", 1);
    }

    argument = _mbsstr(cmd_line, "WORLD");
    if (argument) {
        character = *argument;
        while (character != '=') {
            argument = _mbsninc(argument, 1);
            character = *argument;
        }
        argument = _mbsninc(argument, 1);
        this->prog_info->world_db_file[0] = 0;
        while (!_ismbcspace((unsigned char)*argument) && *argument != 0) {
            _mbsncat(this->prog_info->world_db_file, argument, 1);
            argument = _mbsninc(argument, 1);
        }
    }

    argument = _mbsstr(cmd_line, "FIXEDUPDATE");
    if (argument) {
        do_debug_timeGetTime = 1;
        do_fixed_update = 1;
        character = *argument;
        while (character != '=') {
            argument = _mbsninc(argument, 1);
            character = *argument;
        }
        argument = _mbsninc(argument, 1);
        temp_str[0] = 0;
        while (!_ismbcspace((unsigned char)*argument) && *argument != 0) {
            _mbsncat(temp_str, argument, 1);
            argument = _mbsninc(argument, 1);
        }
        fixed_update_time = atol(temp_str);
    }

    argument = _mbsstr(cmd_line, "AISPEED");
    if (argument) {
        do_debug_timeGetTime = 1;
        do_fixed_update = 1;
        character = *argument;
        while (character != '=') {
            argument = _mbsninc(argument, 1);
            character = *argument;
        }
        argument = _mbsninc(argument, 1);
        temp_str[0] = 0;
        while (!_ismbcspace((unsigned char)*argument) && *argument != 0) {
            _mbsncat(temp_str, argument, 1);
            argument = _mbsninc(argument, 1);
        }
        debug_timeGetTime_interval = atol(temp_str);
    }

    argument = _mbsstr(cmd_line, "RANDOMGAME");
    if (argument) {
        character = *argument;
        while (character != '=') {
            argument = _mbsninc(argument, 1);
            character = *argument;
        }
        argument = _mbsninc(argument, 1);
        temp_str[0] = 0;
        while (!_ismbcspace((unsigned char)*argument) && *argument != 0) {
            _mbsncat(temp_str, argument, 1);
            argument = _mbsninc(argument, 1);
        }
        this->random_game_seed = atol(temp_str);
    }

    argument = _mbsstr(cmd_line, "RANDOMMAP");
    if (argument) {
        character = *argument;
        while (character != '=') {
            argument = _mbsninc(argument, 1);
            character = *argument;
        }
        argument = _mbsninc(argument, 1);
        temp_str[0] = 0;
        while (!_ismbcspace((unsigned char)*argument) && *argument != 0) {
            _mbsncat(temp_str, argument, 1);
            argument = _mbsninc(argument, 1);
        }
        this->random_map_seed = atol(temp_str);
    }

    argument = _mbsstr(cmd_line, "DRAWLOG");
    if (argument) {
        character = *argument;
        while (character != '=') {
            argument = _mbsninc(argument, 1);
            character = *argument;
        }
        argument = _mbsninc(argument, 1);
        draw_log_name[0] = 0;
        while (!_ismbcspace((unsigned char)*argument) && *argument != 0) {
            _mbsncat(draw_log_name, argument, 1);
            argument = _mbsninc(argument, 1);
        }
    }

    if (strstr(cmd_line, "DRAWLOG")) {
        do_draw_log = 1;
    }

    if (strstr(cmd_line, "SAFEDRAWLOG")) {
        safe_draw_log = 1;
    }

    argument = _mbsstr(cmd_line, "DATA");
    if (argument) {
        character = *argument;
        while (character != '=') {
            argument = _mbsninc(argument, 1);
            character = *argument;
        }
        argument = _mbsninc(argument, 1);
        this->prog_info->game_data_file[0] = 0;
        while (!_ismbcspace((unsigned char)*argument) && *argument != 0) {
            _mbsncat(this->prog_info->game_data_file, argument, 1);
            argument = _mbsninc(argument, 1);
        }
    }

    if ((strstr(cmd_line, "CDAUDIO") != 0) || (strstr(cmd_line, "CD AUDIO") != 0) || (strstr(cmd_line, "CD_AUDIO") != 0)) {
        this->prog_info->use_music = 1;
        this->prog_info->use_cd_audio = 1;
        this->prog_info->use_ima = 0;
        this->prog_info->use_midi = 0;
        this->prog_info->use_wave_music = 0;
    }

    if (strstr(cmd_line, "WINDOW")) {
        this->prog_info->full_screen = 0;
    }

    if ((strstr(cmd_line, "FILEFIRST") != 0) || (strstr(cmd_line, "FILE FIRST") != 0) || (strstr(cmd_line, "FILE_FIRST") != 0)) {
        shape_file_first = 1;
        sound_file_first = 1;
    }

    if (((strstr(cmd_line, "LOGCOMM") != 0) || (strstr(cmd_line, "LOG COMM") != 0) || (strstr(cmd_line, "LOG_COMM") != 0)) &&
        (this->log_comm = 1, L != 0)) {
        L->LogFile(1);
        L->LogTimestamp(1);
    }

    if (((strstr(cmd_line, "LOGOUTPUT") != 0) || (strstr(cmd_line, "LOG OUTPUT") != 0) || (strstr(cmd_line, "LOG_OUTPUT") != 0)) &&
        (log_output = 1, L != 0)) {
        L->LogOutput(1);
    }

    if (strstr(cmd_line, "DEVELOPER")) {
        this->setGameDeveloperMode(1);
    }

    argument = _mbsstr(cmd_line, "SPEED1");
    if (argument) {
        character = *argument;
        while (character != '=') {
            argument = _mbsninc(argument, 1);
            character = *argument;
        }
        argument = _mbsninc(argument, 1);
        temp_str[0] = 0;
        while (!_ismbcspace((unsigned char)*argument) && *argument != 0) {
            _mbsncat(temp_str, argument, 1);
            argument = _mbsninc(argument, 1);
        }
        speed_val1 = atol(temp_str);
    }

    argument = _mbsstr(cmd_line, "SPEED2");
    if (argument) {
        character = *argument;
        while (character != '=') {
            argument = _mbsninc(argument, 1);
            character = *argument;
        }
        argument = _mbsninc(argument, 1);
        temp_str[0] = 0;
        while (!_ismbcspace((unsigned char)*argument) && *argument != 0) {
            _mbsncat(temp_str, argument, 1);
            argument = _mbsninc(argument, 1);
        }
        speed_val2 = atol(temp_str);
    }

    if (this->prog_info->use_sound == 0 || strstr(cmd_line, "NOMUSIC") != 0 || strstr(cmd_line, "NO MUSIC") != 0 ||
        strstr(cmd_line, "NO_MUSIC") != 0) {
        this->prog_info->use_music = 0;
    }

    if (this->prog_info->use_dir_draw == 1 && this->prog_info->full_screen == 1) {
        this->custom_mouse = 1;
    }

    if ((strstr(cmd_line, "NORMALMOUSE") != 0) || (strstr(cmd_line, "NORMAL MOUSE") != 0) || (strstr(cmd_line, "NORMAL_MOUSE") != 0)) {
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
    char menu_name_first = *prog_info->menu_name;
    cls.lpszMenuName = s_592A40;
    if (menu_name_first != 0) {
        cls.lpszMenuName = prog_info->menu_name;
    }
    cls.hIcon = LoadIconA(prog_info->instance, prog_info->icon_name);
    cls.lpszClassName = prog_info->prog_name;
    cls.hbrBackground = 0;

    cls.hInstance = static_cast<HINSTANCE>(prog_info->instance);
    cls.style = CS_VREDRAW | CS_HREDRAW | CS_DBLCLKS;
    cls.lpfnWndProc = rge_base_game_wnd_proc;
    cls.cbWndExtra = 0;
    cls.cbClsExtra = 0;

    return RegisterClassA(&cls) != 0;
}

int RGE_Base_Game::setup_main_window() {
    int screen_width = GetSystemMetrics(SM_CXSCREEN);
    int screen_height = GetSystemMetrics(SM_CYSCREEN);
    RECT win_rect;
    RECT client_rect;

    if (this->prog_info->full_screen == 0 && (screen_width != this->prog_info->main_wid ||
         screen_height != this->prog_info->main_hgt)) {
        this->prog_window = CreateWindowExA(0, this->prog_info->prog_name, this->prog_info->prog_title,
                                            WS_CLIPCHILDREN | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, 0, 0,
                                            this->prog_info->main_wid, this->prog_info->main_hgt, 0, 0, this->prog_info->instance, 0);
    } else {
        this->prog_window = CreateWindowExA(0, this->prog_info->prog_name, this->prog_info->prog_title,
                                            WS_POPUP | WS_CLIPCHILDREN | WS_SYSMENU, 0, 0, screen_width, screen_height, 0, 0, this->prog_info->instance, 0);
    }

    if (this->prog_window == 0)
        return 0;

    GetWindowRect(this->prog_window, &win_rect);
    GetClientRect(this->prog_window, &client_rect);

    if (client_rect.right != this->prog_info->main_wid || client_rect.bottom != this->prog_info->main_hgt) {
        SetWindowPos(this->prog_window, 0, win_rect.left, win_rect.top,
                     (win_rect.right - win_rect.left) - client_rect.right + this->prog_info->main_wid,
                     (win_rect.bottom - win_rect.top) - client_rect.bottom + this->prog_info->main_hgt, 0);
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

int RGE_Base_Game::setup_graphics_system() {
    TDrawSystem* draw_system;

    if (this->prog_info->use_dir_draw != 0) {
        HDC dc = GetDC(0);
        int bits = GetDeviceCaps(dc, BITSPIXEL);
        ReleaseDC(0, dc);
        if (bits < 8) {
            this->error_code = RGE_ERROR_SETUP_COLOR_DEPTH;
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
        if (this->prog_info->main_wid != 640) {
            if (this->draw_system->IsModeAvail(640, 0, 8)) {
                this->prog_info->main_wid = 640;
                this->prog_info->main_hgt = 480;
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

        if (this->prog_info->main_wid != 1024) {
            if (this->draw_system->IsModeAvail(1024, 0, 8)) {
                this->prog_info->main_wid = 1024;
                this->prog_info->main_hgt = 768;
                goto init_step;
            }
        }

        if (this->prog_info->main_wid == 1280)
            goto init_fail;

        if (!this->draw_system->IsModeAvail(1024, 0, 8))
            goto init_fail;

        this->prog_info->main_wid = 1280;
        this->prog_info->main_hgt = 1024;
    }

init_step:
    if (this->draw_system->Init(this->prog_info->instance, this->prog_window, this->prog_palette, draw_type, draw_mode,
                                this->prog_info->main_wid, this->prog_info->main_hgt, use_sys_mem) == 0)
        goto init_fail;

    panel_system.release_palette(this->prog_palette);
    this->prog_palette = static_cast<HPALETTE>(panel_system.get_palette(this->prog_info->pal_file, 0xC544));

    this->draw_area = this->draw_system->DrawArea;
    this->draw_area->Clear(0, 0);
    this->draw_system->Paint(0);

    return 1;

init_fail:
    return 0;
}

int RGE_Base_Game::setup_palette() {
    HPALETTE result = static_cast<HPALETTE>(panel_system.get_palette(this->prog_info->pal_file, 0xC544));
    this->prog_palette = result;
    return result != 0;
}

int RGE_Base_Game::setup_mouse() {
    register int result;
    int custom_type;
    TMousePointer* mouse_pointer;

    result = this->registry->RegGetInt(0, "Custom Mouse");
    if (result == -1) {
        this->registry->RegSetInt(0, "Custom Mouse", 0);
        custom_type = 0;
    } else if (result == 1) {
        custom_type = result;
    } else if (result == 2) {
        this->custom_mouse = 0;
    } else {
        custom_type = 0;
    }

    mouse_pointer = new TMousePointer(custom_type);
    this->mouse_pointer = mouse_pointer;
    if (mouse_pointer == 0)
        return 0;

    if (mouse_pointer->setup(this->custom_mouse, this->draw_area, this->prog_info->cursor_file, 0xC738, 10) == 0)
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

int RGE_Base_Game::setup_registry() {
    TRegistry* reg = new TRegistry(this->prog_info->registry_key);
    this->registry = reg;
    return reg != 0;
}


int RGE_Base_Game::setup_debugging_log() {
    TDebuggingLog* log = new TDebuggingLog;
    debugLog = log;
    if (log == 0)
        return 0;

    log->LogFile(log_comm);
    debugLog->LogOutput(log_output);
    debugLog->LogTimestamp(1);
    return 1;
}


int RGE_Base_Game::setup_comm() {
    TCommunications_Handler* new_comm;

    new_comm = new TCommunications_Handler(this->prog_window, (unsigned char)this->prog_info->max_players, chat,
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
int RGE_Base_Game::setup_sound_system() {
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

int RGE_Base_Game::setup_music_system() {
    if (this->prog_info->use_music != 0) {
        int volume = -5000;
        int result = this->registry->RegGetInt(1, "Music Volume");
        if (result != -1)
            volume = -result;

        if (volume <= -9900) {
            this->prog_info->use_music = 0;
            TMusic_System* music = this->music_system;
            if (music != 0) {
                delete music;
                this->music_system = 0;
            }
        } else if (this->music_system == 0) {
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

            sprintf(music_path, "%s\\%s", this->work_dir, this->prog_info->sounds_dir);

            TMusic_System* music_system =
                new TMusic_System(music_type, this->prog_info->instance, this->prog_window, this->sound_system, music_path);
            this->music_system = music_system;

            if (music_system != 0 && music_type == 1 && this->prog_info->use_cd_audio == 0) {
                if (music_system->device_open == 0 || music_system->track_count < 2) {
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

int RGE_Base_Game::setup_shapes() {
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

int RGE_Base_Game::setup_sounds() {
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

int RGE_Base_Game::setup_fonts() {
    short i;
    TEXTMETRICA tm;

    this->font_num = 12;
    this->fonts = static_cast<RGE_Font*>(calloc(this->font_num, sizeof(RGE_Font)));
    if (this->fonts == 0)
        return 0;

    HDC dc = static_cast<HDC>(this->draw_area->GetDc("basegame::setup_fonts"));
    if (dc == 0)
        return 0;

    for (i = 0; i < this->font_num; i++) {
        HFONT font;
        switch (i) {
        case 0:
            font = this->make_font(dc, STRING_ID_FONT_COPPERPLATE_12_BOLD, 0);
            break;
        case 1:
            font = this->make_font(dc, STRING_ID_FONT_COPPERPLATE_21_BOLD, 0);
            break;
        case 4:
            font = this->make_font(dc, STRING_ID_FONT_COPPERPLATE_12_BOLD_ALT, 0);
            break;
        case 6:
            font = this->make_font(dc, STRING_ID_FONT_ARIAL_8_NORMAL, 0);
            break;
        case 7:
            font = this->make_font(dc, STRING_ID_FONT_ARIAL_10_NORMAL, 0);
            break;
        case 8:
            font = this->make_font(dc, STRING_ID_FONT_ARIAL_10_BOLD, 1);
            break;
        case 9:
            font = this->make_font(dc, STRING_ID_FONT_ARIAL_9_BOLD, 0);
            break;
        case 10:
            font = this->make_font(dc, STRING_ID_FONT_ARIAL_10_NORMAL_ALT, 0);
            break;
        case 11:
            font = this->make_font(dc, STRING_ID_FONT_ARIAL_10_BOLD, 0);
            break;
        default:
            font = 0;
            break;
        }

        if (font != 0) {
            HGDIOBJ old_font = SelectObject(dc, font);
            // The original keeps the array index outside the complete metrics object.
            GetTextMetricsA(dc, &tm);
            this->fonts[i].font = font;
            this->fonts[i].font_wid = tm.tmAveCharWidth;
            this->fonts[i].font_hgt = tm.tmHeight + tm.tmExternalLeading;
            SelectObject(dc, old_font);
        }
    }

    this->draw_area->ReleaseDc("basegame::setup_fonts");
    return 1;
}

int RGE_Base_Game::setup_blank_screen() {
    TScreenPanel* panel;

    panel = new TScreenPanel("Blank Screen");
    if (panel == 0)
        return 0;

    if (panel->setup(this->draw_area, 0, -1, 0) == 0)
        return 0;

    panel_system.setCurrentPanel("Blank Screen", 0);
    this->set_render_all();
    SendMessageA(this->prog_window, WM_PAINT, 0, 0);
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

int RGE_Base_Game::restart_sound_system() {
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

int RGE_Base_Game::restart_music_system() {
    TMusic_System* music_system = this->music_system;
    if (music_system == 0)
        return 1;

    int track_from = this->save_music_track_from;
    if (track_from != 0) {
        if (track_from == this->save_music_track_to) {
            music_system->play_track(track_from, this->save_music_loop, this->save_music_pos);
            return 1;
        }

        if (track_from != 0 && this->save_music_track_to != 0) {
            music_system->play_tracks(track_from, this->save_music_track_to, this->save_music_loop,
                                      this->save_music_cur_track, this->save_music_pos);
            return 1;
        }
    }

    if (this->save_music_file[0] != 0)
        music_system->play_file(this->save_music_file, this->save_music_loop, this->save_music_pos);

    return 1;
}

void RGE_Base_Game::shutdown_music_system() {
    if (music_system == 0)
        return;
    this->stop_music_system();
    registry->RegSetInt(1, "Music Volume", -music_system->volume);
    delete music_system;
    music_system = 0;
}

HFONT RGE_Base_Game::make_font(HDC dc, long string_id, int strike_out) {
    char face_name[256];
    char point_size_str[10];
    char style[10];
    int point_size;
    int weight;

    this->get_string(string_id, face_name, 256);
    if (face_name[0] == 0)
        return 0;

    this->get_string(string_id + 1, point_size_str, 10);
    point_size = atoi(point_size_str);

    this->get_string(string_id + 2, style, 10);
    if (strstr(style, "B") != 0 || strstr(style, "b") != 0)
        weight = 700;
    else
        weight = 400;

    return this->make_font(dc, face_name, point_size, weight, strike_out);
}

HFONT RGE_Base_Game::make_font(HDC dc, char* face_name, int point_size, int wgt, int strike_out) {
    char str[256];
    LOGFONTA logfont;
    char charset;

    this->get_string(STRING_ID_FONT_CHARSET, str, 256);
    charset = (char)atoi(str);
    memset(&logfont, 0, sizeof(logfont));
    logfont.lfHeight = -MulDiv(point_size, 96, 72);
    logfont.lfWidth = 0;
    logfont.lfEscapement = 0;
    logfont.lfOrientation = 0;
    logfont.lfWeight = wgt;
    logfont.lfItalic = 0;
    logfont.lfUnderline = 0;
    logfont.lfStrikeOut = (char)strike_out;
    logfont.lfCharSet = charset;
    logfont.lfOutPrecision = 0;
    logfont.lfClipPrecision = 0;
    logfont.lfQuality = 2;
    logfont.lfPitchAndFamily = 2;
    strcpy(logfont.lfFaceName, face_name);
    return CreateFontIndirectA(&logfont);
}


int RGE_Base_Game::check_for_cd(int num_players) {
    char vol_name[256];
    char file_sys_name[256];
    unsigned long vol_ser_num;
    unsigned long max_comp_len;
    unsigned long file_sys_flags;

    if (this->prog_info->verify_cd == 0)
        return 1;

    if (num_players > 0) {
        int cd_count = 0;
        int i = 0;
        do {
            if (this->comm_handler->GetPlayerHumanity(i + 1) == 2 && this->playerHasCD(i) != 0) {
                ++cd_count;
            }
            ++i;
        } while (i < 9);

        return num_players <= this->prog_info->max_players_per_cd * cd_count;
    }

    if (force_cd != 0)
        return 1;

    char* path = this->registry->RegGetAscii(0, "CDPath");
    if (path == 0)
        return 0;

    if (GetDriveTypeA(path) != 5)
        return 0;

    if (GetVolumeInformationA(path, vol_name, 256, &vol_ser_num, &max_comp_len, &file_sys_flags, file_sys_name, 256) == 0)
        return 0;

    return stricmp(vol_name, this->prog_info->vol_name) == 0;
}

int RGE_Base_Game::check_expiration() {
    struct tm kill_def;
    long cur_date;
    long expiration_time;

    memset(&kill_def, 0, sizeof(kill_def));
    kill_def.tm_mon = (int)this->prog_info->expire_month - 1;
    kill_def.tm_mday = (int)this->prog_info->expire_day;
    kill_def.tm_year = (int)this->prog_info->expire_year;

    expiration_time = mktime(&kill_def);
    time(&cur_date);
    return cur_date <= expiration_time;
}

int RGE_Base_Game::check_multi_copies() {
    this->prog_mutex = CreateMutexA(0, 1, this->prog_info->prog_name);
    if (GetLastError() == ERROR_ALREADY_EXISTS) {
        HWND window = FindWindowA(this->prog_info->prog_name, this->prog_info->prog_title);
        if (window != 0) {
            if (this->check_prog_argument("LOBBY") != 0) {
                SendMessageA(window, WM_CLOSE, 0, 0);
                if (this->prog_mutex != 0)
                    ReleaseMutex(this->prog_mutex);
                return 1;
            }
            if (IsIconic(window) != 0)
                ShowWindow(window, SW_SHOWNORMAL);
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

int RGE_Base_Game::check_paint() {
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
        brush = GetStockObject(BLACK_BRUSH);
        FillRect(dc, &rect, brush);
        ReleaseDC(this->prog_window, dc);
    }
}

RGE_Game_World* RGE_Base_Game::create_world() {
    return new RGE_Game_World;
}

void RGE_Base_Game::close() {
    PostMessageA(this->prog_window, WM_CLOSE, 0, 0);
}

int RGE_Base_Game::create_dialog(TPanel** dialog_ptr, TPanel* new_dialog) {
    *dialog_ptr = 0;
    if (new_dialog == 0) {
        return 0;
    }
    if (new_dialog->error_code != 0) {
        delete new_dialog;
        return 0;
    }
    *dialog_ptr = new_dialog;
    return 1;
}

void RGE_Base_Game::delete_dialog(TPanel** dialog_ptr) {
    if (*dialog_ptr) {
        delete *dialog_ptr;
        *dialog_ptr = 0;
    }
}

void RGE_Base_Game::set_game_mode(int new_mode, int new_sub_mode) {
    this->game_mode = new_mode;
    this->sub_game_mode = new_sub_mode;
}

void RGE_Base_Game::set_player(short new_player_id) {
    RGE_Game_World* w = this->world;
    if (w == 0)
        return;
    if (new_player_id >= w->player_num)
        return;
    w->curr_player = new_player_id;
    this->world->map->clear_map_view_info();
}

int RGE_Base_Game::get_paused() {
    if (this->prog_mode == 7)
        return 0;
    return this->comm_handler->IsPaused();
}

RGE_Font* RGE_Base_Game::get_font(int font_id) {
    if (!this->fonts)
        return 0;
    return this->fonts + font_id;
}

TShape* RGE_Base_Game::get_shape(int shape_id) {
    if (!this->shapes)
        return 0;
    return this->shapes[shape_id];
}

TDigital* RGE_Base_Game::get_sound(int sound_id) {
    if (!this->sounds)
        return 0;
    return this->sounds[sound_id];
}

void RGE_Base_Game::request_pause() {
    this->comm_handler->TogglePauseGame();
    if (this->world)
        this->world->temp_pause = 1;
}

void RGE_Base_Game::set_paused(int paused_in, int non_user_pause_in) {
    this->save_paused = this->get_paused();
    if (paused_in != this->save_paused) {
        if (paused_in != 0) {
            this->non_user_pause = non_user_pause_in;
        } else {
            this->non_user_pause = 0;
        }
        this->request_pause();
    }
}

void RGE_Base_Game::get_mouse_info(WPARAM wparam, LPARAM lparam, tagPOINT& point, int& left_btn, int& right_btn, int& ctrl_key, int& shift_key) {
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
    left_btn = wparam & 1;
    right_btn = wparam & 2;
    ctrl_key = wparam & 8;
    shift_key = wparam & 4;
}

void RGE_Base_Game::get_mouse_pos(tagPOINT& point) {
    GetCursorPos(&point);
    if (this->prog_info->full_screen == 0) {
        ScreenToClient(this->prog_window, &point);
        if (point.x > 60000) {
            point.x += -0x10000;
        }
        if (point.y > 60000) {
            point.y += -0x10000;
        }
    }
}

RGE_Player* RGE_Base_Game::get_player(void) {
    RGE_Game_World* w = this->world;
    if (!w)
        return 0;
    if (!w->player_num)
        return 0;
    if (w->curr_player >= w->player_num)
        return 0;
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
        SetClassLongA(this->prog_window, GCL_HCURSOR, reinterpret_cast<LONG>(this->mouse_cursor));
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
        SetCursor(NULL);
        SetClassLongA(prog_window, GCL_HCURSOR, 0);
        is_mouse_on = 0;
    }
}
void RGE_Base_Game::set_windows_mouse(int val) {
    if (this->custom_mouse != 0) {
        this->windows_mouse = val;
    } else {
        this->windows_mouse = 1;
    }

    if ((this->custom_mouse != 0) && (this->windows_mouse == 0)) {
        SetCursor(NULL);
        SetClassLongA(this->prog_window, GCL_HCURSOR, 0);
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
        SetClassLongA(this->prog_window, GCL_HCURSOR, reinterpret_cast<LONG>(this->mouse_cursor));
    } else {
        SetCursor(NULL);
        SetClassLongA(this->prog_window, GCL_HCURSOR, 0);
    }
}
void RGE_Base_Game::set_mouse_cursor(HCURSOR val) {
    this->mouse_cursor = val;

    if (val != 0) {
        last_mouse_cursor = val;
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
    SetClassLongA(this->prog_window, GCL_HCURSOR, reinterpret_cast<LONG>(this->mouse_cursor));
}

void RGE_Base_Game::set_mouse_facet(long facet) {
    this->mouse_pointer->set_facet(facet);
}

int __stdcall enum_wnd_proc(void* hwnd, long lParam) {
    char wnd_title[256];
    GetWindowTextA(hwnd, wnd_title, 255);
    return 1;
}

int __stdcall enum_child_proc(void* hwnd, long lParam) {
    char wnd_title[256];
    GetWindowTextA(hwnd, wnd_title, 255);
    return 1;
}

int __stdcall enum_thread_proc(void* hwnd, long lParam) {
    char wnd_title[256];
    GetWindowTextA(hwnd, wnd_title, 255);
    return 1;
}

int __stdcall close_thread_windows(void* hwnd, long lParam) {
    if (hwnd != AppWnd) {
        if (GetParent(hwnd) != AppWnd) {
            SendMessageA(hwnd, WM_CLOSE, 0, 0);
        }
    }
    return 1;
}

int __stdcall close_child_windows(void* hwnd, long lParam) {
    char str[256];

    str[0] = 0;
    GetWindowTextA(hwnd, str, 255);

    if (strcmp(str, "Locate Session") != 0) {
        SendMessageA(hwnd, WM_CLOSE, 0, 0);
    }

    return 1;
}

extern void color_log(unsigned char a, unsigned char b, int c);

LRESULT CALLBACK RGE_Base_Game::wnd_proc(HWND wnd, UINT msg,
                                         WPARAM wparam, LPARAM lparam) {
    LRESULT retval = 0;
    int mouse_down;
    int save_debug_timeGetTime_on;
    DWORD game_thread;
    DWORD window_thread;
    TPanel* panel;

    color_log(0x24, 0x24, 3);

    mouse_down = msg >= WM_LBUTTONDOWN && msg <= WM_RBUTTONUP;
    if (mouse_down != 0) {
        color_log(0x4C, 0x4C, 4);
    }

    if (this->sound_system != 0) {
        this->sound_system->handle_messages(wnd, msg, wparam, lparam);
    }

    color_log(0x24, 0x16, 3);

    if (this->music_system != 0) {
        this->music_system->handle_messages(wnd, msg, wparam, lparam);
    }

    color_log(0x24, 0x4C, 3);

    panel = panel_system.currentPanel();
    if (panel != 0) {
        color_log(0x24, 0x32, 3);
        panel = panel_system.currentPanel();
        retval = panel->wnd_proc(wnd, msg, wparam, lparam);
        if (retval != 0 && msg != WM_MOUSEMOVE && msg != WM_TIMER) {
            goto handled;
        }
    }

    color_log(0x24, 0x45, 3);

    switch (msg) {
    case WM_TIMER:
        this->handle_idle();
        break;

    case WM_MOUSEMOVE:
        color_log(0x24, 0x54, 3);
        if (this->handle_mouse_move(wnd, msg, wparam, lparam) == 0) {
            goto handled;
        }

        if (MouseCursorInChildContol != 0) {
            if (this->windows_mouse == 0) {
                SetCursor(NULL);
                SetClassLongA(this->prog_window, GCL_HCURSOR, 0);
                this->mouse_on();
            } else {
                SetCursor(this->mouse_cursor);
            }
            MouseCursorInChildContol = 0;
        }
        break;

    case WM_SYSKEYDOWN:
    case WM_KEYDOWN:
        color_log(0x24, 0xBA, 3);
        if (this->handle_key_down(wnd, msg, wparam, lparam) == 0) {
            goto handled;
        }
        break;

    case WM_SYSKEYUP:
        if (wparam == VK_MENU) {
            panel = panel_system.currentPanel();
            if (panel != 0) {
                panel = panel_system.currentPanel();
                panel->handle_reactivate();
            }
        }
        break;

    case WM_SYSCOMMAND:
        if (wparam == SC_KEYMENU && this->prog_info->full_screen != 0 && IsIconic(this->prog_window) == 0) {
            return 0;
        }
        break;

    case WM_USER:
        color_log(0x32, 0x24, 3);
        save_debug_timeGetTime_on = debug_timeGetTime_on;
        debug_timeGetTime_on = 0;
        if (this->handle_user_command(wnd, msg, wparam, lparam) == 0) {
            if (mouse_down != 0) {
                color_log(0x4C, 0x5F, 4);
            }
            color_log(0x24, 0x5F, 3);
            debug_timeGetTime_on = save_debug_timeGetTime_on;
            return retval;
        }
        debug_timeGetTime_on = save_debug_timeGetTime_on;
        break;

    case WM_COMMAND:
        color_log(0x32, 0x16, 3);
        if (this->handle_command(wnd, msg, wparam, lparam) == 0) {
            goto handled;
        }
        break;

    case 953:
    case 0x500:
        color_log(0x32, 0x4C, 3);
        if (this->handle_music_done(wnd, msg, wparam, lparam) == 0) {
            goto handled;
        }
        break;

    case WM_PAINT:
        color_log(0x32, 0x45, 3);
        if (this->handle_paint(wnd, msg, wparam, lparam) == 0) {
            goto handled;
        }
        break;

    case WM_ACTIVATEAPP:
        if (this->prog_ready != 0) {
            if (wparam == 1) {
                if (basegame_is_active != 0) {
                    SetCursor(NULL);
                    SetClassLongA(this->prog_window, GCL_HCURSOR, 0);

                    if (this->prog_mode != 1) {
                        this->restart_sound_system();
                    }

                    basegame_is_active = 0;

                    if (this->draw_system != 0) {
                        this->draw_system->CheckSurfaces();
                        this->draw_system->ClearRestored();
                        this->set_render_all();
                    }

                    if (this->prog_mode != 1) {
                        if (this->draw_system != 0) {
                            this->draw_system->ClearPrimarySurface();
                            this->draw_system->ModifyPalette(0, 256, this->draw_system->palette);
                        }

                        this->set_render_all();
                        InvalidateRect(this->prog_window, NULL, TRUE);
                        do_restore_palette = 10;
                        restore_palette_timer = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 3739);
                        restore_mouse_after_paint = 1;
                    }
                }
            } else if (basegame_is_active == 0) {
                SetClassLongA(this->prog_window, GCL_HCURSOR, 0);

                if (this->prog_mode != 1) {
                    this->stop_sound_system();
                }

                basegame_is_active = 1;

                if (this->prog_mode != 1 && this->mouse_pointer != 0) {
                    this->mouse_pointer->Shutdown_Mouse();
                }
            }
        }

        color_log(0x32, 0x54, 3);
        if (this->handle_activate(wnd, msg, wparam, lparam) == 0) {
            goto handled;
        }
        break;

    case WM_ACTIVATE:
        if (this->prog_ready != 0) {
            if (LOWORD(wparam) == 0) {
                game_thread = GetWindowThreadProcessId(this->prog_window, 0);
                window_thread = GetWindowThreadProcessId(reinterpret_cast<HWND>(lparam), 0);
                if (window_thread == game_thread) {
                    save_active_wnd = reinterpret_cast<HWND>(lparam);
                }
            }

            if (wnd == this->prog_window && LOWORD(wparam) != 0 && HIWORD(wparam) != 0 && save_active_wnd != 0) {
                save_active_wnd = 0;
            }
        }
        break;

    case WM_INITMENU:
        color_log(0x32, 0xBA, 3);
        if (this->handle_init_menu(wnd, msg, wparam, lparam) == 0) {
            goto handled;
        }
        break;

    case WM_EXITMENULOOP:
        color_log(0x32, 0xBA, 3);
        if (this->handle_exit_menu(wnd, msg, wparam, lparam) == 0) {
            goto handled;
        }
        break;

    case WM_SIZE:
        if (system_ignore_size_messages != 0) {
            break;
        }

        color_log(0x32, 0xBA, 3);
        if (this->handle_size(wnd, msg, wparam, lparam) == 0) {
            goto handled;
        }
        break;

    case WM_PALETTECHANGED:
        color_log(0x32, 0xBA, 3);
        if (this->handle_palette_changed(wnd, msg, wparam, lparam) == 0) {
            goto handled;
        }
        break;

    case WM_QUERYNEWPALETTE:
        color_log(0x32, 0xBA, 3);
        if (this->handle_query_new_palette(wnd, msg, wparam, lparam) == 0) {
            goto handled;
        }
        // The original intentionally continues into the close handler.

    case WM_CLOSE:
        color_log(0x32, 0xBA, 3);
        if (this->handle_close(wnd, msg, wparam, lparam) == 0) {
            goto handled;
        }
        break;

    case WM_DESTROY:
        color_log(0x32, 0xBA, 3);
        if (this->handle_destroy(wnd, msg, wparam, lparam) == 0) {
            goto handled;
        }
        break;

    case WM_POWERBROADCAST:
        if (wparam == 0) {
            return 0x424D5144;
        }
        break;
    }

    color_log(0x54, 0x24, 3);
    retval = DefWindowProcA(wnd, msg, wparam, lparam);

    if (mouse_down != 0) {
        color_log(0x4C, 0x5F, 4);
    }
    color_log(0x24, 0x5F, 3);
    return retval;

handled:
    if (mouse_down != 0) {
        color_log(0x4C, 0x5F, 4);
    }
    color_log(0x24, 0x5F, 3);
    return retval;
}


int RGE_Base_Game::handle_idle() {
    if (!this->prog_ready || !this->prog_window)
        return 0;

    color_log(0x16, 0x16, 2);

    if (do_restore_palette && this->prog_active) {
        int delay = 250;
        if (do_restore_palette > 5)
            delay = 500;

        unsigned long t = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 3994);
        if ((t - restore_palette_timer) >= static_cast<unsigned long>(delay)) {
            if (this->draw_system) {
                this->draw_system->ModifyPalette(0, 256, this->draw_system->palette);
            }
            do_restore_palette--;
            restore_palette_timer = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 4004);
        }
    }

    color_log(0x32, 0x32, 5);

    if (this->sound_system) {
        color_log(0x16, 0xBA, 2);
        this->sound_system->handle_messages(this->prog_window, WM_TIMER, 0, 0);
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

int RGE_Base_Game::handle_mouse_move(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    int ctrl_key;
    int right_btn;
    int left_btn;
    tagPOINT point;
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

    this->get_mouse_info(wparam, lparam, point, left_btn, right_btn, ctrl_key, shift_key);
    this->action_mouse_move(point.x, point.y, left_btn, right_btn, ctrl_key, shift_key);
    this->handle_idle();
    return 1;
}

extern int snapshot_number;

int RGE_Base_Game::handle_key_down(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    if (this->prog_ready == 0) {
        return 1;
    }

    short(__stdcall * get_key_state)(int) = GetKeyState;

    basegame_key_message = wparam;
    basegame_key_parameter = lparam & 0xFFFF;
    basegame_control_key_down = (get_key_state(VK_CONTROL) < 0);
    basegame_alt_key_down = (get_key_state(VK_MENU) < 0);
    basegame_shift_key_down = (get_key_state(VK_SHIFT) < 0);

    if (wnd == this->prog_window && msg == WM_SYSKEYDOWN &&
        (basegame_key_message == VK_MENU || basegame_key_message == VK_SPACE || basegame_key_message == VK_F10) &&
        this->prog_info->full_screen != 0 && IsIconic(this->prog_window) == 0) {
        return 0;
    }

    if (basegame_control_key_down != 0 && basegame_key_message == VK_F12) {
        this->draw_system->DrawArea->take_snapshot(".\\AoE%04d.bmp", snapshot_number);
        return 0;
    }

    return this->action_key_down(basegame_key_message, basegame_key_parameter, basegame_control_key_down,
                                 basegame_alt_key_down, basegame_shift_key_down) != 0;
}

extern int out_of_sync;

int RGE_Base_Game::handle_user_command(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    if (this->comm_handler->MultiplayerGameStart() != 0 && out_of_sync == 0) {
        if (wparam == 0x17B3) {
            this->world->players[this->playerID(lparam)]->command_resign((int)lparam, 1);
        } else if (wparam == 0x17B4) {
            this->world->players[this->playerID(lparam)]->command_resign((int)lparam, 0);
        }
    }

    switch (wparam) {
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

    return this->action_user_command(wparam, lparam) != 0;
}

int RGE_Base_Game::handle_command(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    return this->action_command(static_cast<unsigned long>(wparam), static_cast<unsigned long>(lparam)) != 0;
}

int RGE_Base_Game::handle_music_done(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    return this->action_music_done() != 0;
}

int RGE_Base_Game::handle_paint(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    unsigned long time_a;
    unsigned long time_b;
    unsigned long time_c;
    int result;

    color_log(0x32, 0x32, 4);

    time_a = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 4330);
    result = this->check_paint();
    time_b = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 4334);
    this->add_to_timing(5, time_b - time_a);

    if (result == 0) {
        color_log(0x32, 0x5F, 4);
        return 0;
    }

    if (((this->prog_mode == 4 || this->prog_mode == 6 || this->prog_mode == 7) &&
         this->draw_system->DrawType != 1 && this->custom_mouse != 0) && this->mouse_blit_sync != 0) {
        IDirectDrawSurface* surface = this->draw_system->PrimarySurface;
        result = surface->GetBltStatus(1);
        time_a = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 4348);
        time_a += 100;

        do {
            if (result != (int)0x8876021C)
                goto paint_done;

            surface = this->draw_system->PrimarySurface;
            result = surface->GetBltStatus(1);
            time_b = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 4352);
        } while (time_b <= time_a);

        this->mouse_blit_sync = 0;
    }

paint_done:
    color_log(0x32, 0xBA, 4);

    time_a = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 4364);
    TSound_Driver* sound = rge_base_game->sound_system;
    if (sound != 0) {
        sound->play_list();
        sound->reset_play_list();
    }

    time_b = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 4373);
    this->add_to_timing(10, time_b - time_a);

    time_a = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 4380);
    if (this->erase_mouse != 0) {
        color_log(0x32, 0x4C, 4);
        if (this->render_all == 0 && this->custom_mouse != 0)
            this->mouse_pointer->erase();
        this->erase_mouse = 0;
    }

    time_c = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 4391) - time_a;
    time_a = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 4394);
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
        if ((this->prog_mode == 4 || this->prog_mode == 5) && this->do_show_timings != 0)
            this->show_timings();
    }

    time_b = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 4423);
    this->add_to_timing(2, time_b - time_a);

    time_a = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 4427);
    color_log(0x32, 0x54, 4);
    if (this->custom_mouse != 0 && this->windows_mouse == 0) {
        this->mouse_pointer->draw(1);
        this->erase_mouse = 1;
    }

    time_c += debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 4443) - time_a;
    this->add_to_timing(8, time_c);

    time_a = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 4448);
    color_log(0x32, 0x45, 4);
    this->draw_system->Paint(0);
    ValidateRect(this->prog_window, 0);
    ValidateRect(this->prog_window, 0);
    this->render_all = 0;

    time_b = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 4470);
    this->add_to_timing(3, time_b - time_a);

    color_log(0x32, 0x5F, 4);
    ++this->frame_count;

    time_a = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 4482);
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
                    SetClassLongA(this->prog_window, GCL_HCURSOR, reinterpret_cast<LONG>(this->mouse_cursor));
                } else {
                    this->mouse_pointer->on();
                    this->mouse_pointer->draw(1);
                }
            }
            InvalidateRect(wnd, NULL, FALSE);
        }
        restore_mouse_after_paint = 0;
    }

    return 1;
}

int RGE_Base_Game::handle_activate(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    if (wparam != 0) {
        this->prog_active = 1;
    } else {
        this->prog_active = 0;
    }

    if (this->prog_active != 0) {
        if ((this->prog_mode == 4 || this->prog_mode == 6 || this->prog_mode == 7) && this->auto_paused == 1) {
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

int RGE_Base_Game::handle_init_menu(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    return this->action_init_menu() != 0;
}

int RGE_Base_Game::handle_exit_menu(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    return this->action_exit_menu() != 0;
}

int RGE_Base_Game::handle_size(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    if (wparam == 1)
        return 1;

    if (this->draw_system != 0) {
        this->draw_system->HandleSize(wnd, msg, wparam, lparam);

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

int RGE_Base_Game::handle_palette_changed(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    if (this->draw_system != 0) {
        this->draw_system->HandlePaletteChanged(wnd, msg, wparam, lparam);
    }

    if (reinterpret_cast<void*>(wparam) != wnd) {
        TDrawSystem* ds = this->draw_system;
        if (ds->DrawType == 1 || ds->ScreenMode == 1 || ds == 0) {
            this->handle_query_new_palette(wnd, msg, wparam, lparam);
        } else if (this->prog_mode != 1) {
            ds->ModifyPalette(0, 256, ds->palette);
            return 1;
        }
    }

    return 1;
}

int RGE_Base_Game::handle_query_new_palette(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    TDrawSystem* ds = this->draw_system;
    if (ds != 0 && ds->DrawType != 1 && ds->ScreenMode != 1) {
        InvalidateRect(wnd, NULL, FALSE);
        return this->draw_system->HandleQueryNewPalette(wnd, msg, wparam, lparam);
    }

    HDC dc = GetDC(wnd);
    if (panel_system.currentPanel() != 0) {
        TEasy_Panel* panel = static_cast<TEasy_Panel*>(panel_system.currentPanel());
        if (panel->get_palette() != 0)
            SelectPalette(dc, panel->get_palette(), 0);
    } else {
        if (this->prog_palette != 0)
            SelectPalette(dc, this->prog_palette, 0);
    }
    int result = RealizePalette(dc);
    ReleaseDC(wnd, dc);
    if (result != 0)
        InvalidateRect(wnd, NULL, FALSE);
    if (this->draw_system != 0)
        return this->draw_system->HandleQueryNewPalette(wnd, msg, wparam, lparam);
    return 1;
}

int RGE_Base_Game::handle_close(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    if (this->action_close() == 0) {
        return 0;
    }
    if (this->draw_area != 0 && this->draw_system != 0) {
        this->draw_area->Clear(0, 0);
        this->draw_system->Paint(0);
    }
    return 1;
}
int RGE_Base_Game::handle_destroy(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    this->prog_ready = 0;
    if (this->is_timer != 0) {
        KillTimer(this->prog_window, 1);
    }
    this->prog_window = 0;
    PostQuitMessage(0);
    return 1;
}

extern unsigned long start_mem_total;
extern unsigned long start_mem_high;
extern unsigned long cur_mem_total;
extern unsigned long cur_mem_high;

void RGE_Base_Game::calc_timings() {
    unsigned long total_time = 0;
    for (int i = 0; i < 30; ++i) {
        if (this->timings[i].is_summary == 0) {
            this->timings[i].last_time = this->timings[i].accum_time;
            this->timings[i].last_max_time = this->timings[i].max_time;
            this->timings[i].accum_time = 0;
            this->timings[i].max_time = 0;
            this->timings[i].start_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 4789);

            if (this->timings[i].include_in_total != 0)
                total_time += this->timings[i].last_time;
        }
    }

    if (this->timings[0].start_time > 0) {
        this->timings[0].last_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 4798) -
                                     this->timings[0].start_time;
    } else {
        this->timings[0].last_time = total_time;
    }

    this->timings[0].start_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\basegame.cpp", 4801);

    if (this->timings[0].last_time > total_time)
        this->timings[4].last_time =
            this->timings[0].last_time - total_time;
    else
        this->timings[4].last_time = 0;

    if (this->timings[2].last_time > this->timings[6].last_time + this->timings[7].last_time)
        this->timings[9].last_time =
            this->timings[2].last_time - this->timings[6].last_time -
            this->timings[7].last_time;
    else
        this->timings[9].last_time = 0;

    unsigned long total = this->timings[0].last_time;
    if (total == 0 || this->frame_count == 0 || total / this->frame_count == 0) {
        this->fps = 1000;
    } else {
        this->fps = 1000 / (total / this->frame_count);
    }

    if (total == 0 || this->view_update_count == 0 || total / this->view_update_count == 0) {
        this->view_update_fps = 0;
    } else {
        this->view_update_fps =
            1000 / (total / this->view_update_count);
    }

    if (total == 0 || this->world_update_count == 0 || total / this->world_update_count == 0) {
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

        fprintf(fps_log,
                "%lu, %ld, %ld, %ld, %ld, %d, %d, %d, %d, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %d, %d, %d \n",
                this->world->world_time, start_mem_total, start_mem_high, cur_mem_total, cur_mem_high,
                (*this->world->players)->objects->number_of_objects,
                (*this->world->players)->sleeping_objects->number_of_objects, object_count, sleeping_object_count,
                this->world_update_count, this->view_update_count, this->world_update_fps, this->view_update_fps,
                this->world_update_count == 0 ? 0 : this->timings[6].last_time / this->world_update_count,
                this->timings[6].last_max_time, this->world_update_count == 0 ? 0
                : this->timings[7].last_time / this->world_update_count, this->timings[7].last_max_time,
                this->world_update_count == 0 ? 0 : this->timings[3].last_time / this->world_update_count,
                this->timings[3].last_max_time, this->world_update_count == 0 ? 0
                : this->timings[1].last_time / this->world_update_count, this->timings[1].last_max_time,
                this->world_update_count == 0 ? 0 : (this->timings[10].last_time + this->timings[12].last_time) /
                this->world_update_count, this->timings[10].last_max_time + this->timings[12].last_max_time,
                this->world_update_count == 0 ? 0 : this->timings[13].last_time / this->world_update_count,
                this->timings[13].last_max_time, this->world_update_count == 0 ? 0
                : this->timings[4].last_time / this->world_update_count, this->timings[4].last_max_time, 0, -1, -1);
        fflush(fps_log);
    }

    this->last_frame_count = this->frame_count;
    this->last_world_update_count = this->world_update_count;
    this->last_view_update_count = this->view_update_count;
    this->frame_count = 0;
    this->world_update_count = 0;
    this->view_update_count = 0;
}
void RGE_Base_Game::calc_timing_text() {
    unsigned long divisor = this->frame_count;
    if (divisor == 0)
        divisor = 1;

    sprintf(this->timing_text,
            "fps=%lu, rend=%lu, view=%lu, map=%lu, scr=%lu, draw=%lu, prog=%lu, ui=%lu, sfx=%lu, misc=%lu", this->fps,
            this->timings[2].last_time / divisor, this->timings[6].last_time / divisor,
            this->timings[7].last_time / divisor, this->timings[3].last_time / divisor,
            this->timings[1].last_time / divisor, this->timings[10].last_time / divisor,
            this->timings[13].last_time / divisor, this->timings[4].last_time / divisor,
            this->timings[0].last_time / divisor);
}
void RGE_Base_Game::show_timings() {
    SetWindowTextA(this->prog_window, this->timing_text);
}
void RGE_Base_Game::show_comm(void) {
    char str[256];
    sprintf(str, "%s", this->comm_handler->GetCommInfo(1));
    SetWindowTextA(this->prog_window, str);
}
void RGE_Base_Game::show_ai(void) {
    char str[256];
    sprintf(str, "No AI Information for Player #%d.", (int)this->world->curr_player);
    SetWindowTextA(this->prog_window, str);
}

void RGE_Base_Game::send_game_options() {
    if (this->comm_handler)
        this->comm_handler->SetMyGameOptions(reinterpret_cast<char*>(&this->rge_game_options), 0xA8);
}

void RGE_Base_Game::receive_game_options(void) {
    if (this->comm_handler != 0) {
        unsigned long size = 0;
        void* options = this->comm_handler->GetMyGameOptions(&size);
        if (options != 0 && size == 0xA8)
            this->set_game_options(static_cast<RGE_Game_Options*>(options));
    }
}

void RGE_Base_Game::set_game_options(RGE_Game_Options* options) {
    int i;

    this->setVersion(options->versionValue);
    this->setScenarioGame(options->scenarioGameValue);
    this->setScenarioName(options->scenarioNameValue);
    this->setSinglePlayerGame(options->singlePlayerGameValue);
    this->setMultiplayerGame(options->multiplayerGameValue);
    this->setMapSize(options->mapXSizeValue, options->mapYSizeValue, options->mapZSizeValue);
    this->setAllowCheatCodes(options->allowCheatCodesValue);
    this->setCheatNotification(options->cheatNotificationValue);
    this->setFullVisibility(options->fullVisibilityValue);
    this->setFogOfWar(options->fogOfWarValue);
    this->setColoredChat(options->coloredChatValue);
    this->setNumberPlayers(options->numberPlayersValue);
    this->setGameDeveloperMode(options->gameDeveloperModeValue);
    this->setDifficulty(options->difficultyValue);
    this->setMpPathFinding(options->mpPathFindingValue);

    for (i = 0; i < 9; i++) {
        this->setPlayerCDAndVersion(i, options->playerCDAndVersionValue[i]);
        this->setPlayerTeam(i, options->playerTeamValue[i]);
    }
}

void RGE_Base_Game::get_game_options(RGE_Game_Options* options) {
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

int RGE_Base_Game::playerHasCD(int player_num) {
    return this->rge_game_options.playerCDAndVersionValue[player_num] & 1;
}

unsigned char RGE_Base_Game::playerVersion(int player_num) {
    return this->rge_game_options.playerCDAndVersionValue[player_num] >> 1;
}

char* RGE_Base_Game::playerVersionString(int player_num) {
    unsigned char ver = playerVersion(player_num);

    switch (ver) {
    case 0:
        return "";
    case 1:
        return "1.0";
    case 2:
        return "1.0a";
    case 3:
        return "1.0b";
    case 4:
        return "1.0c";
    case 5:
        return "1.0d";
    case 6:
        return "1.0e";
    case 7:
        return "1.1";
    case 8:
        return "1.1a";
    case 9:
        return "1.1b";
    case 10:
        return "1.1c";
    case 11:
        return "1.2";
    case 12:
        return "1.2a";
    case 13:
        return "1.2b";
    case 14:
        return "1.2c";
    case 15:
        return "1.3";
    case 16:
        return "1.3a";
    case 17:
        return "1.3b";
    case 18:
        return "1.3c";
    case 19:
        return "1.4";
    case 20:
        return "1.4a";
    case 21:
        return "1.4b";
    case 22:
        return "1.4c";
    default:
        return "1.X";
    }
}

unsigned char RGE_Base_Game::playerCDAndVersion(int player_num) {
    return this->rge_game_options.playerCDAndVersionValue[player_num];
}

int RGE_Base_Game::difficulty() {
    return this->rge_game_options.difficultyValue;
}

int RGE_Base_Game::numberPlayers() const {
    return this->rge_game_options.numberPlayersValue;
}

int RGE_Base_Game::playerTeam(int player_num) {
    return this->rge_game_options.playerTeamValue[player_num];
}

unsigned char RGE_Base_Game::pathFinding() {
    return this->pathFindingValue;
}

unsigned char RGE_Base_Game::mpPathFinding() {
    return this->rge_game_options.mpPathFindingValue;
}

static char temp;

char* RGE_Base_Game::gameSummary() {
    temp = 0;
    return &temp;
}

void RGE_Base_Game::find_campaigns() {
    this->player_game_info->find_campaigns();
}

void RGE_Base_Game::setScenarioGame(int v) {
    this->rge_game_options.scenarioGameValue = v;
}

void RGE_Base_Game::setVersion(float val) {
    this->rge_game_options.versionValue = val;
}

void RGE_Base_Game::setScenarioName(char* n) {
    strncpy(this->rge_game_options.scenarioNameValue, n, 128);
    this->rge_game_options.scenarioNameValue[0x7F] = 0;
}

void RGE_Base_Game::setCampaignGame(int v) {
    this->campaignGameValue = v;
}

void RGE_Base_Game::setSavedGame(int v) {
    this->savedGameValue = v;
}

void RGE_Base_Game::setSinglePlayerGame(int v) {
    this->rge_game_options.singlePlayerGameValue = (unsigned char)v;
    this->rge_game_options.multiplayerGameValue = (unsigned char)(v == 0);
}

void RGE_Base_Game::setMultiplayerGame(int v) {
    this->rge_game_options.multiplayerGameValue = (unsigned char)v;
    this->rge_game_options.singlePlayerGameValue = (unsigned char)(v == 0);
}

void RGE_Base_Game::setMapSize(int x, int y, int z) {
    this->rge_game_options.mapXSizeValue = x;
    this->rge_game_options.mapYSizeValue = y;
    this->rge_game_options.mapZSizeValue = z;
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

void RGE_Base_Game::setPlayerHasCD(int player_num, int has_cd) {
    unsigned char val = this->rge_game_options.playerCDAndVersionValue[player_num];
    val = (val & 0xFE) | has_cd;
    this->rge_game_options.playerCDAndVersionValue[player_num] = val;
}

void RGE_Base_Game::setPlayerVersion(int player_num, unsigned char player_version) {
    unsigned char v = player_version << 1;
    unsigned char old = this->rge_game_options.playerCDAndVersionValue[player_num];
    v = v | (old & 1);
    this->rge_game_options.playerCDAndVersionValue[player_num] = v;
}

void RGE_Base_Game::setPlayerCDAndVersion(int player_num, unsigned char val) {
    this->rge_game_options.playerCDAndVersionValue[player_num] = val;
}

void RGE_Base_Game::setDifficulty(int difficulty) {
    this->rge_game_options.difficultyValue = difficulty;
}

void RGE_Base_Game::setPlayerTeam(int player_num, int team) {
    this->rge_game_options.playerTeamValue[player_num] = team;
}

void RGE_Base_Game::setPathFinding(unsigned char val) {
    this->pathFindingValue = val;
}

void RGE_Base_Game::setMpPathFinding(unsigned char val) {
    this->rge_game_options.mpPathFindingValue = val;
}

void RGE_Base_Game::set_map_visible(unsigned char flag) {
    if (this->world)
        this->world->set_map_visible((unsigned char)flag);
}

void RGE_Base_Game::set_map_fog(unsigned char flag) {
    if (this->world)
        this->world->set_map_fog((unsigned char)flag);
}

void RGE_Base_Game::turn_world_sound_off() {
    this->world->turn_sound_off();
}

int RGE_Base_Game::campaign_open_scenario() {
    return this->player_game_info->open_scenario();
}

long RGE_Base_Game::GetChecksum(long player) {
    RGE_Game_World* world = this->world;
    if (world != 0) {
        if (player < 0) {
            return world->players[world->curr_player]->get_checksum();
        }
        if (player < world->player_num) {
            return world->players[player]->get_checksum();
        }
    }
    return 0;
}

unsigned char RGE_Base_Game::GetWorldChecksums(long& new_checksum, long& new_position_checksum, long& new_action_checksum) {
    long checksum1;
    long checksum2;
    long checksum3;
    int i;
    RGE_Game_World* w;

    checksum1 = 0;
    checksum2 = 0;
    checksum3 = 0;
    i = 0;
    new_checksum = 0;
    new_position_checksum = 0;
    new_action_checksum = 0;
    w = world;
    if (w != 0) {
        if (w->player_num > 0) {
            do {
                w->players[i]->get_checksums(checksum1, checksum2, checksum3);
                new_checksum += checksum1;
                new_position_checksum += checksum2;
                new_action_checksum += checksum3;
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

void RGE_Base_Game::set_screen_size(long wid, long hgt) {
    RECT win_rect;
    RECT client_rect;

    if (this->draw_area->Width != wid || this->draw_area->Height != hgt) {
        if (this->draw_system->DrawType == 2 && this->draw_system->ScreenMode == 2) {
            SetCursor(NULL);
            SetClassLongA(this->prog_window, GCL_HCURSOR, 0);
            this->mouse_pointer->Shutdown_Mouse();
            this->draw_system->SetDisplaySize(wid, hgt, 8);
            this->draw_system->CheckSurfaces();
            this->draw_system->ClearRestored();
            this->set_render_all();
            restore_mouse_after_paint = 1;
            return;
        }

        long horz_res = 0;
        long vert_res = 0;
        HDC dc = CreateICA("DISPLAY", 0, 0, 0);
        if (dc != 0) {
        horz_res = GetDeviceCaps(dc, HORZRES);
        vert_res = GetDeviceCaps(dc, VERTRES);
            DeleteDC(dc);
        }

        if (wid <= horz_res && hgt <= vert_res) {
            if (horz_res == wid && vert_res == hgt) {
                this->window_style = WS_POPUP | WS_VISIBLE | WS_CLIPCHILDREN | WS_SYSMENU;
                SetWindowLongA(this->prog_window, GWL_STYLE, this->window_style);
                SetWindowLongA(this->prog_window, GWL_EXSTYLE, this->window_style);
            } else {
                this->window_style = WS_VISIBLE | WS_CLIPCHILDREN | WS_CAPTION |
                                     WS_SYSMENU | WS_MINIMIZEBOX;
                SetWindowLongA(this->prog_window, GWL_EXSTYLE, this->window_style);
                SetWindowLongA(this->prog_window, GWL_STYLE, this->window_style);
            }

            SetWindowPos(this->prog_window, 0, 0, 0, wid, hgt, 0);
            GetWindowRect(this->prog_window, &win_rect);
            GetClientRect(this->prog_window, &client_rect);

            if (client_rect.right != wid || client_rect.bottom != hgt) {
                SetWindowPos(this->prog_window, 0, win_rect.left, win_rect.top,
                             wid + win_rect.right - win_rect.left - client_rect.right,
                             hgt + win_rect.bottom - win_rect.top - client_rect.bottom, 0);
            }
        }
    }
}

unsigned char RGE_Base_Game::check_prog_argument(char* argument) {
    char cmd_line[256];

    strncpy(cmd_line, this->prog_info->cmd_line, 255);
    cmd_line[255] = 0;
    CharUpperA(cmd_line);
    if (strstr(cmd_line, argument) != 0) {
        return 1;
    }
    return 0;
}

long RGE_Base_Game::get_scenario_checksum(char* scenario_file) {
    RGE_Scenario_Header* hdr = this->get_scenario_header(scenario_file, 0);
    if (!hdr)
        return 0;
    unsigned long checksum = hdr->checksum;
    delete hdr;
    return checksum;
}

unsigned char RGE_Base_Game::check_scenario_checksum(char* scenario, long checksum) {
    long cs = this->get_scenario_checksum(scenario);
    if (cs != 0 && cs == checksum)
        return 1;
    return 0;
}

void RGE_Base_Game::dump_memory_usage(char* file_name) {
}

int RGE_Base_Game::playerID(int player_index) {
    return this->playerIDValue[player_index];
}

void RGE_Base_Game::setPlayerID(int player_index, int player_id) {
    this->playerIDValue[player_index] = player_id;
}

void RGE_Base_Game::reset_countdown_timer(long in_countdown_player_id) {
    this->countdown_timer[in_countdown_player_id] = -1;
}

void RGE_Base_Game::set_countdown_timer(long in_countdown_player_id, long in_countdown_timer) {
    long current = this->countdown_timer[in_countdown_player_id];
    if (current > in_countdown_timer || current < 0) {
        this->countdown_timer[in_countdown_player_id] = in_countdown_timer;
    }
}

void RGE_Base_Game::get_countdown_timer(long out_countdown_player_id, long& out_countdown_timer) {
    out_countdown_timer = this->countdown_timer[out_countdown_player_id];
}

int RGE_Base_Game::play_video(char* file_name) {
    return 0;
}

void RGE_Base_Game::close_video(void) {
}

void RGE_Base_Game::handle_video_notify(void) {
}

int RGE_Base_Game::play_sound(int sound_id) {
    if (this->sounds == 0)
        return 0;

    if (this->sounds[sound_id] == 0)
        return 0;

    if (this->sounds[sound_id]->is_playing() != 0)
        return 1;

    return this->sounds[sound_id]->play();
}

float RGE_Base_Game::get_game_speed() {
    return this->game_speed;
}

void RGE_Base_Game::set_game_speed(float val) {
    this->game_speed = val;
}

int RGE_Base_Game::get_single_player_difficulty() {
    return this->single_player_difficulty;
}

void RGE_Base_Game::set_single_player_difficulty(int val) {
    this->single_player_difficulty = val;
}

int RGE_Base_Game::setup_map_save_area() {
    TDrawArea* area = new TDrawArea("Diamond Map Save Area", 0);
    this->map_save_area = area;

    if (area == 0) {
        return 0;
    }

    if (area->Init(this->draw_system, 280, 140, 0, 0) == 0) {
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

void RGE_Base_Game::set_interface_messages(void) {
}

void RGE_Base_Game::set_render_all() {
    this->render_all = 1;
    panel_system.set_restore();
}

extern char debug_random_log[5000][100];
extern int debug_random_index;

void __cdecl debug_random_reset() {
    for (int index = 0; index < 5000; ++index)
        debug_random_log[index][0] = 0;
    debug_random_index = -1;
}


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
        } else {
            marker = " ";
        }
        fprintf(file, "%s%d - %s\n", marker, index, debug_random_log[index]);
        index++;
    }

    fclose(file);
    wrote_debug_random_log = 1;
}


int __cdecl debug_rand(char* source_name, int source_line) {
    int rv = rand();
    if (do_debug_random && debug_random_on) {
        char temp_name[9];
        source_name += 10;
        char* dst = temp_name;
        char* end = source_name + 8;
        char c = *source_name;
        while (c != '.' && source_name < end) {
            *dst = c;
            c = source_name[1];
            ++dst;
            ++source_name;
        }
        int idx = debug_random_index;
        *dst = 0;
        if (idx < 4999)
            ++idx;
        else
            idx = 0;
        debug_random_index = idx;
        sprintf(debug_random_log[idx], "t%d,%s,l%d,r%d", rge_base_game->world->world_time, temp_name, source_line, rv);
    }
    return rv;
}


void __cdecl debug_srand(char* source_name, int source_line,
                         unsigned int seed) {
    if (do_debug_random && debug_random_on) {
        char temp_name[9];
        source_name += 10;
        char* d = temp_name;
        char* end = source_name + 8;
        char c = *source_name;
        while (c != '.' && source_name < end) {
            *d = c;
            c = source_name[1];
            d++;
            source_name++;
        }
        *d = 0;
        int idx = debug_random_index;
        if (idx < 4999)
            idx++;
        else
            idx = 0;
        debug_random_index = idx;
        sprintf(debug_random_log[idx], "t%d,%s,l%d,s%u", rge_base_game->world->world_time, temp_name, source_line, seed);
    }
    srand(seed);
}

unsigned long __cdecl debug_timeGetTime(char* source_name, int source_line) {
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
