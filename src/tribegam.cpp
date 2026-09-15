#include "../include/com_hand.h"
#include "../include/tribegam.h"
#include "../include/resource_ids.h"
#include "../include/main.h"
#include "../include/game_globals.h"
#include "../include/Res_file.h"
#include "../include/gameinfo.h"
#include "../include/world_info.h"
#include "../include/world.h"
#include "../include/tworld.h"
#include "../include/player.h"
#include "../include/tplayer.h"
#include "../include/scenario.h"
#include "../include/tscenaro.h"
#include "../include/music.h"
#include "../include/sounddrv.h"
#include "../include/panel.h"
#include "../include/panel_ez.h"
#include "../include/Pnl_scr.h"
#include "../include/scr_game.h"
#include "../include/scr_main.h"
#include "../include/scr_cams.h"
#include "../include/scr_stms.h"
#include "../include/scr_sed.h"
#include "../include/scr_ach.h"
#include "../include/scr_vc.h"
#include "../include/scr_mps.h"
#include "../include/scr_cj.h"
#include "../include/act_obj.h"
#include "../include/action.h"
#include "../include/act_list.h"
#include "../include/move_obj.h"
#include "../include/dpl_obj.h"
#include "../include/obj_list.h"
#include "../include/visible.h"
#include "../include/path.h"
#include "../include/pathsys.h"
#include "../include/aiplaybook.h"
#include "../include/tcommand.h"
#include "../include/chat.h"
#include "../include/debuglog.h"
#include "../include/registry.h"
#include "../include/Mouseptr.h"
#include <io.h>
#include <new.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <mbstring.h>

void encrypt_codes(char* source, char* dest, int maxlen) {
    char c = *source;
    char* out = dest;
    int count = 0;
    char* p = source + 1;

    while (c != 0 && count < maxlen) {
        if (c < 'A' || c > '_') {
            *out = c;
            out++;
            count++;
        } else {
            int val = encrypt_table[static_cast<int>(c) - 0x40];
            *out = static_cast<char>(val >> 8);
            out++;
            *out = static_cast<char>(val);
            out++;
            count += 2;
        }
        c = *p;
        p++;
    }
    *out = 0;
}

struct _iobuf;

extern "C" {
_iobuf* __cdecl fopen(const char* path, const char* mode);
int __cdecl fclose(_iobuf* file);
int __cdecl fprintf(_iobuf* file, const char* fmt, ...);
long __cdecl time(long* t);
char* __cdecl ctime(const long* t);
char* __cdecl strncpy(char* dest, const char* src, unsigned int count);
void* __cdecl memset(void* dest, int value, unsigned int count);
}

extern int do_run_log;       // 0x62C4F4
extern int run_log_created;  // 0x86BDFC
extern _iobuf* run_log_file; // 0x86BDF8

void __cdecl run_log(char* str, int show_time) {
    char stime[26];

    if (!do_run_log)
        return;

    if (run_log_created) {
        run_log_file = fopen("c:\\aoerun.txt", "a");
    } else {
        run_log_file = fopen("c:\\aoerun.txt", "w");
        run_log_created = 1;
    }

    if (!run_log_file)
        return;

    if (show_time) {
        time(reinterpret_cast<long*>(&show_time));
        memset(stime, 0, sizeof(stime));
        strncpy(stime, ctime(reinterpret_cast<const long*>(&show_time)), 0x18);
        fprintf(run_log_file, "%s - %s\n", stime, str);
    } else {
        fprintf(run_log_file, "%s\n", str);
    }

    fclose(run_log_file);
}

static long __stdcall video_sub_wnd_proc(void* wnd, unsigned int msg, unsigned int wparam, long lparam) {
    return static_cast<TRIBE_Game*>(rge_base_game)->video_wnd_proc(wnd, msg, wparam, lparam);
}

extern void* StringTableX;
extern int disable_terrain_sounds;
extern int out_of_sync;
extern int out_of_sync2;
extern int player_dropped[9];
extern int video_codec_available;
extern void __cdecl debug_srand(char* file, int line, unsigned int seed);

struct ICINFO {
    unsigned long dwSize;
    unsigned long fccType;
    unsigned long fccHandler;
    unsigned long dwFlags;
    unsigned long dwVersion;
    unsigned long dwVersionICM;
    unsigned short szName[16];
    unsigned short szDescription[128];
    unsigned short szDriver[128];
};

extern "C" int __stdcall ICInfo(unsigned long fccType, unsigned long fccHandler, ICINFO* info);

TRIBE_Game::TRIBE_Game(RGE_Prog_Info* prog_info_in, int do_setup)
    : RGE_Base_Game(prog_info_in, 0), video_window(0), cur_video(-1), old_video_wnd_proc(0), video_paused(0),
      last_video_time(0), video_setup(0), video_double_size(0), video_changed_res(0), video_hi_color(0),
      video_save_res_wid(0), video_save_res_hgt(0), video_save_palette(0), started_menu_music(0), show_object_id(0),
      game_screen(0), inHandleIdle(0) {
    int i;
    int player;
    int civ;

    this->input_enabled = 1;
    this->input_disabled_window = 0;
    this->testing_scenario[0] = 0;
    StringTableX = 0;
    this->startup_scenario[0] = 0;
    this->startup_game[0] = 0;
    this->save_game_name[0] = 0;
    this->load_game_name[0] = 0;
    this->auto_exit_time = 0;
    this->timing_text2[0] = 0;
    disable_terrain_sounds = 0;
    out_of_sync = 0;
    out_of_sync2 = 0;

    this->MouseRightClickTable = 0;
    this->MouseRightClickTableSize = 0;
    this->MouseLeftClickTable = 0;
    this->MouseLeftClickTableSize = 0;
    this->setMapSize(TRIBE_Game::Medium);
    this->setMapType(TRIBE_Game::WaterAndLand);
    this->setAnimals(1);
    this->setPredators(1);
    this->setVictoryType(TRIBE_Game::VictoryConquest, 1);
    this->setAllowTrading(1);
    this->setLongCombat(0);
    this->setRandomizePositions(0);
    this->setFullTechTree(0);
    this->setResourceLevel(TRIBE_Game::DefaultResources);
    this->setStartingAge(TRIBE_Game::DefaultAge);
    this->setStartingUnits(0);
    this->setDeathMatch(0);
    this->setPopLimit(50);
    this->setQuickStartGame(0);
    this->setRandomStartValue(-1);

    for (i = 0; i < 5; ++i) {
        this->notification_loc_x[i] = -1;
        this->notification_loc_y[i] = -1;
    }
    this->current_notification_loc = -1;
    this->current_notification_recalled = -1;

    civ = 1;
    for (player = 0; player < 9; ++player) {
        this->setCivilization(player, civ);
        ++civ;
        if (civ > 16) {
            civ = 1;
        }
        this->setScenarioPlayer(player, player);
        this->setPlayerColor(player, 1);
        this->setComputerName(player, 0);
        player_dropped[player] = 0;
    }

    for (i = 0; i < 9; ++i) {
        this->save_humanity[i] = 0;
    }
    this->setNumberPlayers(4);
    this->resetRandomComputerName();

    if (do_setup != 0) {
        if (this->setup() == 0 && this->error_code == 0) {
            this->error_code = 1;
        }
    }
}

extern void* StringTableX;

TRIBE_Game::~TRIBE_Game() {
    this->inHandleIdle = 0;
    this->prog_mode = 0;

    if (this->input_disabled_window != 0) {
        DestroyWindow(reinterpret_cast<HWND>(this->input_disabled_window));
        this->input_disabled_window = 0;
    }

    this->close_game_screens(1);

    panel_system.destroyPanel("Video Screen");
    panel_system.destroyPanel("Create Dialog");
    panel_system.destroyPanel("Campaign Editor Screen");
    panel_system.destroyPanel("Game Setup Screen");
    panel_system.destroyPanel("Game Settings Screen");
    panel_system.destroyPanel("Select Scenario Screen");
    panel_system.destroyPanel("Campaign Selection Screen");
    panel_system.destroyPanel("Load Saved Game Screen");
    panel_system.destroyPanel("MP Startup Screen");
    panel_system.destroyPanel("MP Setup Screen");
    panel_system.destroyPanel("Connecting Screen");
    panel_system.destroyPanel("Join Screen");
    panel_system.destroyPanel("Main Menu");
    panel_system.destroyPanel("Save Game Screen");
    panel_system.destroyPanel("End Screen");
    panel_system.destroyPanel("Scenario Editor Menu");
    panel_system.destroyPanel("Scenario Editor Open");
    panel_system.destroyPanel("Scenario Editor Screen");
    panel_system.destroyPanel("Single Player Menu");
    panel_system.destroyPanel("New Name Dialog");
    panel_system.destroyPanel("Name Selection Screen");
    panel_system.destroyPanel("Status Screen");
    panel_system.destroyPanel("Temp Screen");
    panel_system.destroyPanel("ScenarioEditorInfo");
    panel_system.destroyPanel("FeaturesInfo");
    panel_system.destroyPanel("QuotesInfo");
    panel_system.destroyPanel("Logo1Screen");
    panel_system.destroyPanel("Logo2Screen");

    RESFILE_close_new_resource_file("sounds.drs");
    RESFILE_close_new_resource_file("graphics.drs");
    RESFILE_close_new_resource_file("Terrain.drs");
    RESFILE_close_new_resource_file("Border.drs");
    RESFILE_close_new_resource_file("Interfac.drs");

    if (StringTableX != 0) {
        FreeLibrary(StringTableX);
        StringTableX = 0;
    }
}

void TRIBE_Game::close_game_screens(int close_main_game_screen) {
    panel_system.destroyPanel("Object List Dialog");
    panel_system.destroyPanel("OKDialog");
    panel_system.destroyPanel("YesNoDialog");
    panel_system.destroyPanel("RestartDialog");
    panel_system.destroyPanel("QuitGameDialog");
    panel_system.destroyPanel("CloseProgramDialog");
    panel_system.destroyPanel("QuitAndLoadDialog");
    panel_system.destroyPanel("ResignDialog");
    panel_system.destroyPanel("Help Dialog");
    panel_system.destroyPanel("About Dialog");
    panel_system.destroyPanel("Send Quick Message Dialog");
    panel_system.destroyPanel("Mission Dialog");
    panel_system.destroyPanel("Send Message Dialog");
    panel_system.destroyPanel("Diplomacy Dialog");
    panel_system.destroyPanel("Menu Dialog");
    panel_system.destroyPanel("Save Game Screen");
    panel_system.destroyPanel("Load Saved Game Screen");
    panel_system.destroyPanel("End Screen");
    panel_system.destroyPanel("Achievements Screen");
    panel_system.destroyPanel("Multiplayer Wait Screen");
    panel_system.destroyPanel("Multiplayer Disconnect Screen");

    if (close_main_game_screen != 0) {
        this->game_screen = 0;
        panel_system.destroyPanel("Game Screen");
    }
}

#include <string.h>
#include <windows.h>

int TRIBE_Game::setup() {
    char cmd_line[256];
    char str[1024];
    ICINFO ici;
    WIN32_FIND_DATAA file_data;
    SYSTEMTIME file_time;
    HANDLE file_handle;
    char* option;
    int result;

    if (this->error_code != 0) {
        return 0;
    }

    if (strstr(this->prog_info->cmd_line, "makeres") != 0 || strstr(this->prog_info->cmd_line, "Makeres") != 0 ||
        strstr(this->prog_info->cmd_line, "MAKERES") != 0) {
        RESFILE_build_res_file("graphics.rm", "resource\\", this->prog_info->resource_dir);
        RESFILE_build_res_file("sounds.rm", "resource\\", this->prog_info->resource_dir);
        RESFILE_build_res_file("interfac.rm", "resource\\", this->prog_info->resource_dir);
    }

    RESFILE_open_new_resource_file("sounds.drs", "tribe", this->prog_info->resource_dir, 1);
    RESFILE_open_new_resource_file("graphics.drs", "tribe", this->prog_info->resource_dir, 0);
    RESFILE_open_new_resource_file("Interfac.drs", "tribe", this->prog_info->resource_dir, 0);
    RESFILE_open_new_resource_file("sounds.drs", "tribe", "data\\", 1);
    RESFILE_open_new_resource_file("graphics.drs", "tribe", "data\\", 0);
    RESFILE_open_new_resource_file("Terrain.drs", "tribe", "data\\", 0);
    RESFILE_open_new_resource_file("Border.drs", "tribe", "data\\", 0);
    RESFILE_open_new_resource_file("Interfac.drs", "tribe", "data\\", 0);

    if (this->RGE_Base_Game::setup() == 0) {
        return 0;
    }

    strncpy(cmd_line, this->prog_info->cmd_line, 0xFF);
    cmd_line[0xFF] = 0;
    CharUpperA(cmd_line);

    option = reinterpret_cast<char*>(
        _mbsstr(reinterpret_cast<unsigned char*>(cmd_line), reinterpret_cast<const unsigned char*>("STRING=")));
    char new_string_dll_name[100] = "languagex.dll";
    if (option != 0) {
        while (*option != '=') {
            option = reinterpret_cast<char*>(_mbsninc(reinterpret_cast<const unsigned char*>(option), 1));
        }
        option = reinterpret_cast<char*>(_mbsninc(reinterpret_cast<const unsigned char*>(option), 1));
        new_string_dll_name[0] = 0;
        while (_ismbcspace(static_cast<unsigned char>(*option)) == 0 && *option != 0) {
            _mbsncat(reinterpret_cast<unsigned char*>(new_string_dll_name),
                     reinterpret_cast<const unsigned char*>(option), 1);
            option = reinterpret_cast<char*>(_mbsninc(reinterpret_cast<const unsigned char*>(option), 1));
        }
    }

    StringTableX = LoadLibraryA(new_string_dll_name);
    if (StringTableX == 0) {
        this->error_code = 1;
        return 0;
    }

    PALETTEENTRY pal_entries[7] = {{0x17, 0x27, 0x7C, 0x00}, {0x27, 0x3F, 0x90, 0x00}, {0x3F, 0x5F, 0x9F, 0x00},
                                   {0x57, 0x7B, 0xB4, 0x00}, {0x3F, 0x5F, 0xA0, 0x00}, {0x27, 0x3F, 0x91, 0x00},
                                   {0x17, 0x27, 0x7B, 0x00}};
    SetPaletteEntries(this->prog_palette, 0xF8, 7, pal_entries);

    this->input_disabled_window =
        CreateWindowExA(0, "STATIC", "InputDisabledWindow", WS_CHILD, 0, 0, 1, 1, this->prog_window, 0,
                        reinterpret_cast<HINSTANCE>(this->prog_info->instance), 0);

    // These packed values are the video type "vidc" and the lowercase handler "iv41".
    video_codec_available = ICInfo(0x63646976, 0x31347669, &ici);

    if (this->check_prog_argument("LOBBY") != 0) {
        new TRIBE_Screen_Status_Message("Status Screen", 0x4BF, "scr1", 0xC383);
        panel_system.setCurrentPanel("Status Screen", 0);

        result = this->comm_handler->LaunchLobbyGame();
        if (result == 1) {
            TribeMPSetupScreen* screen;

            this->setMultiplayerGame(1);
            screen = new TribeMPSetupScreen;
            if (screen == 0 || screen->error_code != 0) {
                return 0;
            }
            panel_system.setCurrentPanel("MP Setup Screen", 0);
            panel_system.destroyPanel("Status Screen");
        } else if (result == -1) {
            TRIBE_Screen_Main_Error* screen = new TRIBE_Screen_Main_Error;
            if (screen == 0 || screen->error_code != 0) {
                return 0;
            }
            screen->set_text(0x96A);
            panel_system.setCurrentPanel("Main Error Screen", 0);
            panel_system.destroyPanel("Status Screen");
        } else {
            this->close();
            return 1;
        }
    } else {
        result = this->comm_handler->LaunchLobbyGame();
        if (result == 1) {
            this->setMultiplayerGame(1);
            new TribeMPSetupScreen;
            panel_system.setCurrentPanel("MP Setup Screen", 0);
            panel_system.destroyPanel("Status Screen");
        } else {
            if (this->startup_scenario[0] != 0) {
                if (this->start_scenario(this->startup_scenario) == 0) {
                    if (this->start_menu() == 0) {
                        return 0;
                    }
                    TEasy_Panel* panel = static_cast<TEasy_Panel*>(panel_system.panel("Main Menu"));
                    if (panel != 0) {
                        panel->popupOKDialog(0x961, 0, 0x1C2, 100);
                    }
                }
            } else if (this->startup_game[0] != 0) {
                if (this->load_game(this->startup_game) == 0) {
                    if (this->start_menu() == 0) {
                        return 0;
                    }
                    TEasy_Panel* panel = static_cast<TEasy_Panel*>(panel_system.panel("Main Menu"));
                    if (panel != 0) {
                        panel->popupOKDialog(0x961, 0, 0x1C2, 100);
                    }
                }
            } else if (this->prog_info->skip_startup == 0) {
                this->start_video(0, "logo1");
            } else {
                if (this->start_menu() == 0) {
                    return 0;
                }
            }
        }
    }

    this->set_interface_messages();

    run_log("------------------------------", 0);
    run_log("", 1);

    file_handle = FindFirstFileA(_pgmptr, &file_data);
    if (file_handle != INVALID_HANDLE_VALUE) {
        ZeroMemory(&file_time, sizeof(file_time));
        FileTimeToSystemTime(&file_data.ftLastWriteTime, &file_time);
        sprintf(str, "program=%s, size=%d, date=%d/%d/%d, time=%d:%d:%d", _pgmptr, file_data.nFileSizeLow,
                file_time.wMonth, file_time.wMonth, file_time.wYear, file_time.wHour, file_time.wMinute,
                file_time.wSecond);
        run_log(str, 0);
        FindClose(file_handle);
    }

    file_handle = FindFirstFileA(this->prog_info->game_data_file, &file_data);
    if (file_handle != INVALID_HANDLE_VALUE) {
        ZeroMemory(&file_time, sizeof(file_time));
        FileTimeToSystemTime(&file_data.ftLastWriteTime, &file_time);
        sprintf(str, "data=%s, size=%d, date=%d/%d/%d, time=%d:%d:%d", this->prog_info->game_data_file,
                file_data.nFileSizeLow, file_time.wMonth, file_time.wMonth, file_time.wYear, file_time.wHour,
                file_time.wMinute, file_time.wSecond);
        run_log(str, 0);
        FindClose(file_handle);
    }

    sprintf(str, "options=%s", this->prog_info->cmd_line);
    run_log(str, 0);

    return 1;
}

// The oracle loads [p+1], then increments p in each scan body.

#include <string.h>

extern "C" {
__declspec(dllimport) char* __stdcall CharUpperA(char* string);
char* __cdecl strncpy(char* destination, const char* source, unsigned int count);
long __cdecl atol(const char* string);
char* __cdecl strstr(const char* string, const char* substring);
char* __cdecl strchr(const char* string, int character);
}

void encrypt_codes(char* source, char* destination, int maxlen);

extern int disable_terrain_sounds;
extern int quick_start_game_mode;

int TRIBE_Game::setup_cmd_options() {
    char c;
    int i;
    char* p;
    char* q;
    char cmd_line[256];
    char temp_str[256];
    char encstr[512];

    strncpy(cmd_line, this->prog_info->cmd_line, 0xFF);
    cmd_line[255] = 0;
    CharUpperA(cmd_line);
    encrypt_codes(cmd_line, encstr, 0x200);

    if (strstr(cmd_line, "NOTERRAINSOUND") != 0) {
        disable_terrain_sounds = 1;
    }

    p = strstr(encstr, "+!#L%c#L ^=");
    if (p != 0) {
        c = *p;
        while (c != '=') {
            c = *++p;
        }
        c = *++p;
        i = 0;
        while (c != ' ' && c != 0) {
            temp_str[i] = c;
            q = p + 1;
            c = *q;
            ++i;
            p = q;
        }
        temp_str[i] = 0;
        i = static_cast<int>(atol(temp_str));
        if (i <= 25) {
            i = 25;
        } else if (i > 200) {
            i = 200;
        }
        this->setPopLimit(static_cast<unsigned char>(i));
    }

    if (strstr(cmd_line, "QUICK1") != 0) {
        quick_start_game_mode = 1;
    }

    p = strstr(cmd_line, "SCN=");
    if (p != 0) {
        c = *p;
        while (c != '=') {
            c = *++p;
        }
        c = *++p;
        i = 0;
        while (c != ' ' && c != 0) {
            this->startup_scenario[i] = c;
            q = p + 1;
            c = *q;
            ++i;
            p = q;
        }
        this->startup_scenario[i] = 0;
    }

    p = strstr(cmd_line, "EXIT=");
    if (p != 0) {
        c = *p;
        while (c != '=') {
            c = *++p;
        }
        c = *++p;
        i = 0;
        while (c != ' ' && c != 0) {
            temp_str[i] = c;
            q = p + 1;
            c = *q;
            ++i;
            p = q;
        }
        temp_str[i] = 0;
        this->auto_exit_time = static_cast<unsigned long>(atol(temp_str));
    }

    p = strstr(cmd_line, "GAM=");
    if (p != 0) {
        c = *p;
        while (c != '=') {
            c = *++p;
        }
        c = *++p;
        i = 0;
        while (c != ' ' && c != 0) {
            this->startup_game[i] = c;
            q = p + 1;
            c = *q;
            ++i;
            p = q;
        }
        this->startup_game[i] = 0;
        if (strchr(this->startup_game, '.') == 0) {
            strcat(this->startup_game, ".gmx");
        }
    }

    return this->RGE_Base_Game::setup_cmd_options();
}

#include <windows.h>

int TRIBE_Game::setup_palette() {
    if (!RGE_Base_Game::setup_palette()) {
        return 0;
    }

    {
        PALETTEENTRY pal_entries[7] = {{0x17, 0x27, 0x7C, 0x00}, {0x27, 0x3F, 0x90, 0x00}, {0x3F, 0x5F, 0x9F, 0x00},
                                       {0x57, 0x7B, 0xB4, 0x00}, {0x3F, 0x5F, 0xA0, 0x00}, {0x27, 0x3F, 0x91, 0x00},
                                       {0x17, 0x27, 0x7B, 0x00}};

        SetPaletteEntries(prog_palette, 0xF8, 7, pal_entries);
    }
    return 1;
}

extern "C" void* __cdecl calloc(unsigned int num, unsigned int size);
extern void* operator new(unsigned int size);

int TRIBE_Game::setup_sounds() {
    TDigital* d;
    int i;

    this->sound_num = 17;
    this->sounds = static_cast<TDigital**>(calloc(17, 4));
    if (this->sounds == 0) {
        return 0;
    }

    for (i = 0; i < this->sound_num; ++i) {
        this->sounds[i] = 0;
    }

    d = new TDigital(this->sound_system, "button1.wav", 0xC47C);
    this->sounds[0] = d;
    d = new TDigital(this->sound_system, "button2.wav", 0xC47D);
    this->sounds[1] = d;
    d = new TDigital(this->sound_system, "chatrcvd.wav", 0xC47E);
    this->sounds[2] = d;
    d = new TDigital(this->sound_system, "cantdo.wav", 0xC47F);
    this->sounds[3] = d;
    d = new TDigital(this->sound_system, "tribute.wav", 0xC480);
    this->sounds[4] = d;
    d = new TDigital(this->sound_system, "resdone.wav", 0xC481);
    this->sounds[5] = d;
    d = new TDigital(this->sound_system, "pkilled.wav", 0xC482);
    this->sounds[6] = d;
    d = new TDigital(this->sound_system, "pdropped.wav", 0xC483);
    this->sounds[7] = d;
    d = new TDigital(this->sound_system, "mstart.wav", 0xC484);
    this->sounds[8] = d;
    d = new TDigital(this->sound_system, "mdone.wav", 0xC485);
    this->sounds[9] = d;
    d = new TDigital(this->sound_system, "mkilled.wav", 0xC486);
    this->sounds[10] = d;
    d = new TDigital(this->sound_system, "artheld.wav", 0xC487);
    this->sounds[11] = d;
    d = new TDigital(this->sound_system, "artlost.wav", 0xC488);
    this->sounds[12] = d;
    d = new TDigital(this->sound_system, "convwarn.wav", 0xC489);
    this->sounds[13] = d;
    d = new TDigital(this->sound_system, "convdone.wav", 0xC48A);
    this->sounds[14] = d;
    d = new TDigital(this->sound_system, "res.wav", 0xC48B);
    this->sounds[15] = d;
    d = new TDigital(this->sound_system, "farmdie.wav", 0xC48C);
    this->sounds[16] = d;

    for (i = 0; i < 3; ++i) {
        if (this->sounds[i] != 0) {
            this->sounds[i]->load(0, -1);
        }
    }

    return 1;
}

#include "../include/game_globals.h"
#include "../include/game_types.h"

RGE_Game_World* TRIBE_Game::create_world() {
    return new TRIBE_World;
}

void TRIBE_Game::set_game_mode(int new_mode, int new_sub_mode) {
    int old_mode = this->game_mode;
    this->RGE_Base_Game::set_game_mode(new_mode, new_sub_mode);
    if (this->game_screen != 0) {
        this->game_screen->game_mode_changed(old_mode, this->game_mode);
    }
}

#include "../include/game_globals.h"

void TRIBE_Game::set_player(short new_player_id) {
    short oldPlayer;
    if (this->world) {
        oldPlayer = this->world->curr_player;
    } else {
        oldPlayer = 0;
    }

    RGE_Base_Game::set_player(new_player_id);

    if (this->world && this->game_screen) {
        this->game_screen->player_changed(oldPlayer, this->world->curr_player);
    }
}

extern "C" char* strcpy(char* dst, const char* src);

void TRIBE_Game::set_save_game_name(char* file_name) {
    if (file_name != 0) {
        strcpy(this->save_game_name, file_name);
    } else {
        this->save_game_name[0] = 0;
    }
}

#include <string.h>

void TRIBE_Game::set_load_game_name(char* file_name) {
    if (file_name != 0) {
        strcpy(this->load_game_name, file_name);
        return;
    }

    this->load_game_name[0] = 0;
}

#include <windows.h>

extern void* StringTableX;

char* TRIBE_Game::get_string(long string_id, char* str, int max_len) {
    // The expansion table takes precedence; the base table supplies missing strings.
    if (LoadStringA(StringTableX, static_cast<int>(string_id), str, max_len) == 0) {
        return this->RGE_Base_Game::get_string(string_id, str, max_len);
    }
    str[max_len - 1] = '\0';
    return str;
}

char* TRIBE_Game::get_string2(int string_type, long id, long id2, char* str, int max_len) {
    *str = 0;

    switch (string_type) {
    case 100:
        switch (id) {
        case 0:
        case 0x0F:
        case 0x10:
        case 0x11:
            return this->get_string(0x10CD, str, max_len);
        case 1:
            return this->get_string(0x10CE, str, max_len);
        case 2:
            return this->get_string(0x10CF, str, max_len);
        case 3:
            return this->get_string(0x10D0, str, max_len);
        case 9:
            return this->get_string(0x10DB, str, max_len);
        }
        break;
    case 101:
        switch (id) {
        case 1:
            return this->get_string(IDS_HELP_AGE_STONE, str, max_len);
        case 2:
            return this->get_string(IDS_HELP_AGE_TOOL, str, max_len);
        case 3:
            return this->get_string(IDS_HELP_AGE_BRONZE, str, max_len);
        case 4:
            return this->get_string(IDS_HELP_AGE_IRON, str, max_len);
        }
        break;
    case 105:
        switch (id) {
        case 1:
            this->get_string(IDS_CIVILIZATION_EGYPTIAN, str, max_len);
            break;
        case 2:
            this->get_string(IDS_CIVILIZATION_GREEK, str, max_len);
            break;
        case 3:
            this->get_string(IDS_CIVILIZATION_BABYLONIAN, str, max_len);
            break;
        case 4:
            this->get_string(IDS_CIVILIZATION_ASSYRIAN, str, max_len);
            break;
        case 5:
            this->get_string(IDS_CIVILIZATION_MINOAN, str, max_len);
            break;
        case 6:
            this->get_string(IDS_CIVILIZATION_HITTITE, str, max_len);
            break;
        case 7:
            this->get_string(IDS_CIVILIZATION_PHOENICIAN, str, max_len);
            break;
        case 8:
            this->get_string(IDS_CIVILIZATION_SUMERIAN, str, max_len);
            break;
        case 9:
            this->get_string(IDS_CIVILIZATION_PERSIAN, str, max_len);
            break;
        case 10:
            this->get_string(IDS_CIVILIZATION_SHANG, str, max_len);
            break;
        case 11:
            this->get_string(IDS_CIVILIZATION_YAMATO, str, max_len);
            break;
        case 12:
            this->get_string(IDS_CIVILIZATION_CHOSON, str, max_len);
            break;
        case 13:
            this->get_string(IDS_CIVILIZATION_ROMAN, str, max_len);
            break;
        case 14:
            this->get_string(IDS_CIVILIZATION_CARTHAGINIAN, str, max_len);
            break;
        case 15:
            this->get_string(IDS_CIVILIZATION_PALMYRAN, str, max_len);
            break;
        case 16:
            this->get_string(IDS_CIVILIZATION_MACEDONIAN, str, max_len);
            break;
        default:
            this->get_string(IDS_CIVILIZATION_UNKNOWN, str, max_len);
            break;
        }
        break;
    case 102:
        switch (id) {
        case 1:
            return this->get_string(0x1005, str, max_len);
        case 2:
            return this->get_string(0x1006, str, max_len);
        case 3:
            return this->get_string(0x1007, str, max_len);
        case 4:
            return this->get_string(0x1008, str, max_len);
        case 5:
            return this->get_string(0x1009, str, max_len);
        case 6:
            return this->get_string(0x100A, str, max_len);
        case 7:
            return this->get_string(0x100B, str, max_len);
        case 8:
            return this->get_string(0x100C, str, max_len);
        case 9:
            return this->get_string(0x100D, str, max_len);
        case 10:
            return this->get_string(0x100E, str, max_len);
        case 11:
            return this->get_string(0x100F, str, max_len);
        case 12:
            return this->get_string(0x1010, str, max_len);
        case 13:
            return this->get_string(0x1011, str, max_len);
        case 14:
            return this->get_string(0x1012, str, max_len);
        case 15:
            return this->get_string(0x1013, str, max_len);
        case 16:
            return this->get_string(0x1014, str, max_len);
        case 17:
            return this->get_string(0x1015, str, max_len);
        case 18:
            return this->get_string(0x1016, str, max_len);
        case 19:
            return this->get_string(0x1017, str, max_len);
        case 20:
            return this->get_string(0x1018, str, max_len);
        case 21:
            return this->get_string(0x1019, str, max_len);
        case 22:
            return this->get_string(0x101A, str, max_len);
        case 23:
            return this->get_string(0x101B, str, max_len);
        case 0x1C:
            return this->get_string(0x101C, str, max_len);
        case 0x1D:
            return this->get_string(0x101D, str, max_len);
        case 0x1E:
            return this->get_string(0x101E, str, max_len);
        case 0x1F:
            return this->get_string(0x101F, str, max_len);
        case 0x19:
            return this->get_string(0x1020, str, max_len);
        case 0x1A:
            return this->get_string(0x1021, str, max_len);
        case 0x1B:
            return this->get_string(0x1022, str, max_len);
        case 0x20:
            return this->get_string(0x1025, str, max_len);
        case 0x21:
            return this->get_string(0x1026, str, max_len);
        }
        break;
    case 1:
        switch (id) {
        case 0x64:
        case 0x65:
        case 0x66:
            return this->get_string(0x961, str, max_len);
        case 0x67:
            return this->get_string(IDS_ERROR_CANNOT_SAVE_GAME, str, max_len);
        case 0x68:
            return this->get_string(IDS_ERROR_CANNOT_SAVE_SCENARIO, str, max_len);
        case 0x69:
            return this->get_string(0x964, str, max_len);
        case 0x6A:
            return this->get_string(0x965, str, max_len);
        default:
            return RGE_Base_Game::get_string2(string_type, id, id2, str, max_len);
        }
    case 103:
        switch (id) {
        case 1:
            switch (id2) {
            case 4:
                return this->get_string(0xBBD, str, max_len);
            case 0:
                return this->get_string(0xBB9, str, max_len);
            case 1:
                return this->get_string(0xBBA, str, max_len);
            case 2:
                return this->get_string(0xBBB, str, max_len);
            case 3:
                return this->get_string(0xBBC, str, max_len);
            case 0x20:
                return this->get_string(0xBE6, str, max_len);
            }
            break;
        case 0x68:
            return this->get_string(0xBC1, str, max_len);
        case 1000:
            return this->get_string(0xBC2, str, max_len);
        case 0x65:
            return this->get_string(0xBBE, str, max_len);
        case 0x66:
            return this->get_string(0xBBF, str, max_len);
        case 0x67:
            return this->get_string(0xBC0, str, max_len);
        case 0x69:
            return this->get_string(0xBC3, str, max_len);
        case 0x6A:
            return this->get_string(0xBCA, str, max_len);
        }
        break;
    case 104:
        switch (id) {
        case 2:
            return this->get_string(0x10D1, str, max_len);
        case 3:
            return this->get_string(0x10D2, str, max_len);
        case 4:
            return this->get_string(0x10D3, str, max_len);
        case 1:
            return this->get_string(0x10D4, str, max_len);
        case 5:
            return this->get_string(0x10D5, str, max_len);
        case 6:
            return this->get_string(0x10D6, str, max_len);
        case 7:
            return this->get_string(0x10D7, str, max_len);
        case 8:
            return this->get_string(0x10D8, str, max_len);
        case 9:
            return this->get_string(0x10D9, str, max_len);
        case 10:
            return this->get_string(0x10DA, str, max_len);
        case 11:
            return this->get_string(0x10DC, str, max_len);
        }
        break;
    default:
        return RGE_Base_Game::get_string2(string_type, id, id2, str, max_len);
    }

    str[max_len - 1] = 0;
    return str;
}

TPanel* TRIBE_Game::get_view_panel() {
    if (this->prog_mode == 4 || this->prog_mode == 6 || this->prog_mode == 5) {
        if (this->game_screen != 0)
            return this->game_screen->get_view_panel();
    }

    if (this->prog_mode == 7) {
        TPanel* panel = panel_system.panel("Scenario Editor Screen");
        if (panel != 0)
            return static_cast<TRIBE_Screen_Sed*>(panel)->main_view;
    }

    return 0;
}

TPanel* TRIBE_Game::get_map_panel(void) {
    if (this->prog_mode == 4 || this->prog_mode == 6 || this->prog_mode == 5) {
        if (this->game_screen != 0) {
            return this->game_screen->get_map_panel();
        }
    }

    if (this->prog_mode == 7) {
        TPanel* p = panel_system.panel("Scenario Editor Screen");
        if (p != 0) {
            return static_cast<TRIBE_Screen_Sed*>(p)->map_view;
        }
    }

    return 0;
}

char* TRIBE_Game::get_save_game_name() {
    return this->save_game_name;
}

char* TRIBE_Game::get_load_game_name() {
    return this->load_game_name;
}

RGE_Scenario_Header* TRIBE_Game::new_scenario_header(int infile) {
    return new TRIBE_Scenario_Header(infile);
}

#include "../include/game_types.h"

RGE_Scenario_Header* TRIBE_Game::new_scenario_header(RGE_Scenario* scenario_info) {
    return new TRIBE_Scenario_Header(static_cast<T_Scenario*>(scenario_info));
}

RGE_Scenario* TRIBE_Game::new_scenario_info(int infile) {
    return new T_Scenario(infile, 0);
}

extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void* hWnd, const char* lpText, const char* lpCaption,
                                                           unsigned int uType);

void TRIBE_Game::show_error_message(int error_code_in) {
    char title[256];
    char msg[256];
    this->get_string(0xFA8, title, 256);
    this->get_string2(1, error_code_in, 0, msg, 256);
    MessageBoxA(this->prog_window, msg, title, 0x10);
}

static char status_screen[] = "Status Screen";

void TRIBE_Game::show_status_message(char* messageIn, char* info_file, long info_id) {
    TRIBE_Screen_Status_Message* panel;
    panel = static_cast<TRIBE_Screen_Status_Message*>(panel_system.panel(status_screen));
    if (panel) {
        panel->set_text(messageIn);
        this->draw_window();
    } else {
        panel = new TRIBE_Screen_Status_Message(status_screen, messageIn, info_file, info_id);
    }
    panel_system.setCurrentPanel(status_screen, 0);
}

void TRIBE_Game::show_status_message(int string_id, char* info_file, long info_id) {
    char str[0x100];
    this->get_string(string_id, str, 0x100);
    this->show_status_message(str, info_file, info_id);
}

void TRIBE_Game::close_status_message() {
    panel_system.restorePreviousPanel(1);
}

#include <stdio.h>
#include <string.h>
#include <windows.h>

extern "C" int __cdecl _open(const char* path, int flags, ...);
extern "C" void* __cdecl MCIWndCreateA(void* parent, void* instance, unsigned long style, const char* file);
static long __stdcall video_sub_wnd_proc(void* wnd, unsigned int msg, unsigned int wparam, long lparam);

int TRIBE_Game::start_video(int video_num, char* video_file) {
    if (this->video_window != 0) {
        char str[100];
        SendMessageA(this->video_window, 0x46A, 100, reinterpret_cast<long>(str));
        if (str[0] != 0 && strcmp(str, "stopped") != 0) {
            SendMessageA(this->video_window, 0x808, 0, 0);
        }
        SendMessageA(this->video_window, 0x10, 0, 0);
        this->video_window = 0;
    }

    this->cur_video = video_num;
    if (this->rge_game_options.multiplayerGameValue != 1 && video_file != 0 && *video_file != 0) {
        char temp_name[260];
        sprintf(temp_name, "%s%s.avi", this->prog_info->avi_dir, video_file);
        int file_handle = _open(temp_name, 0, 0x100);
        if (file_handle == -1) {
            char* cd_path = this->registry->RegGetAscii(0, "CDPath");
            if (cd_path != 0) {
                sprintf(temp_name, "%sgame\\avi\\%s.avi", cd_path, video_file);
                file_handle = _open(temp_name, 0, 0x100);
            }
            if (file_handle == -1) {
                this->stop_video(1);
                return 0;
            }
        }

        if (video_codec_available != 0 && (this->video_setup != 0 || this->setup_video_system() != 0)) {
            this->video_window = MCIWndCreateA(this->prog_window, this->prog_info->instance, 0x50001F0A, temp_name);
            if (this->video_window != 0) {
                RECT video_rect;
                this->old_video_wnd_proc = reinterpret_cast<int(__stdcall*)()>(GetWindowLongA(this->video_window, -4));
                SetWindowLongA(this->video_window, -4, reinterpret_cast<long>(::video_sub_wnd_proc));

                if (this->video_hi_color == 0) {
                    void* palette = reinterpret_cast<void*>(SendMessageA(this->video_window, 0x47E, 0, 0));
                    this->draw_system->SetPalette(palette);
                }

                GetClientRect(this->video_window, &video_rect);
                if (this->video_double_size != 0) {
                    video_rect.right = video_rect.right * 2;
                    video_rect.bottom = video_rect.bottom * 2;
                }

                MoveWindow(this->video_window, this->prog_info->main_wid / 2 - video_rect.right / 2,
                           this->prog_info->main_hgt / 2 - video_rect.bottom / 2, video_rect.right, video_rect.bottom,
                           0);
                this->set_render_all();
                InvalidateRect(this->prog_window, 0, 1);
                SendMessageA(this->prog_window, 0x0F, 0, 0);
                this->draw_system->ClearPrimarySurface();
                this->video_paused = 0;
                this->last_video_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0x598);
                SendMessageA(this->video_window, 0x806, 0, 0);
                this->enable_input();
                SetCursor(0);
                SetClassLongA(this->prog_window, -12, 0);
                return 1;
            }
        }
    }
    this->stop_video(1);
    return 0;
}

#include <new.h>
#include <string.h>
#include <windows.h>

typedef long(__stdcall* SendMessageFn)(void* hwnd, unsigned int message, unsigned int wparam, long lparam);

void TRIBE_Game::stop_video(unsigned char goto_next_video) {
    int save_vid_num;
    char str[100];
    int show_menu_after_video = 0;

    save_vid_num = this->cur_video;
    this->cur_video = -1;

    if (this->video_window != 0) {
        SendMessageFn send_message = SendMessageA;

        send_message(this->video_window, 0x46A, 100, reinterpret_cast<long>(str));
        if (str[0] != 0 && strcmp(str, "stopped") != 0) {
            send_message(this->video_window, 0x808, 0, 0);
        }

        send_message(this->video_window, 0x10, 0, 0);
        this->video_window = 0;
        this->draw_system->ClearPrimarySurface();
        this->draw_system->SetPalette(this->prog_palette);
        this->set_render_all();
        InvalidateRect(this->prog_window, 0, 1);
        send_message(this->prog_window, 0x0F, 0, 0);
        this->draw_system->ClearPrimarySurface();
    }

    switch (save_vid_num) {
    case 0:
        if (goto_next_video != 0) {
            this->start_video(1, "logo2");
            return;
        }
        show_menu_after_video = 1;
        break;

    case 1:
        if (goto_next_video != 0) {
            this->start_video(2, "introx");
            return;
        }
        show_menu_after_video = 1;
        break;

    case 2:
    case 5:
        if (this->start_menu() == 0) {
            this->close();
        }
        return;

    case 3:
        if (this->video_setup != 0) {
            this->shutdown_video_system();
        }

        {
            char* description = this->world->scenario->Get_description();
            if (description != 0 && description[0] != 0 && this->multiplayerGame() == 0 &&
                (this->randomGame() == 0 || this->campaignGame() != 0)) {
                TRIBE_Mission_Screen* screen =
                    new TRIBE_Mission_Screen(description, 0, this->world->scenario->mission_picture);
                panel_system.setCurrentPanel("Mission Dialog", 0);
                return;
            }
        }

        this->create_game_screen();
        return;

    case 4:
        if (this->video_setup != 0) {
            this->shutdown_video_system();
        }

        if (this->world != 0) {
            this->close_game_screens(0);

            TribeAchievementsScreen* screen = new TribeAchievementsScreen(this->game_over_msg(), 1);
            if (screen != 0 && screen->error_code == 0) {
                panel_system.setCurrentPanel("Achievements Screen", 0);

                if (this->music_system != 0) {
                    if (this->music_system->music_type == 1) {
                        RGE_Player* player = this->get_player();
                        if (player->game_status == 1) {
                            this->music_system->play_track(3, 0, 0);
                        } else {
                            this->music_system->play_track(4, 0, 0);
                        }
                        return;
                    }

                    if (this->music_system->music_type == 2) {
                        RGE_Player* player = this->get_player();
                        if (player->game_status == 1) {
                            this->music_system->play_file("won.mid", 0, 0);
                        } else {
                            this->music_system->play_file("lost.mid", 0, 0);
                        }
                        return;
                    }
                }

                return;
            }

            if (screen != 0) {
                delete screen;
            }
            this->quit_game();
            return;
        }
        return;

    default:
        return;
    }

    if (show_menu_after_video && this->start_menu() == 0) {
        this->close();
    }
}

int TRIBE_Game::start_campaign_menu() {
    TRIBE_Screen_Campaign_Selection* screen;
    TMusic_System* music;

    if (this->video_setup != 0)
        this->shutdown_video_system();

    screen = new TRIBE_Screen_Campaign_Selection;
    if (screen == 0)
        return 0;

    if (screen->error_code != 0) {
        delete screen;
        return 0;
    }

    panel_system.setCurrentPanel("Campaign Selection Screen", 0);
    this->set_prog_mode(2);

    music = this->music_system;
    if (music != 0 && this->started_menu_music == 0) {
        if (music->music_type == 1) {
            music->play_track(2, 0, 0);
        } else if (music->music_type == 2) {
            music->play_file("open.mid", 0, 0);
        } else if (music->music_type == 3) {
            music->play_file("open.wav", 0, 0);
        }
        this->started_menu_music = 1;
    }

    return 1;
}

#include <new.h>

extern TPanelSystem panel_system;

int TRIBE_Game::start_menu() {
    TRIBE_Screen_Main_Menu* screen;

    if (this->video_setup)
        this->shutdown_video_system();

    screen = new TRIBE_Screen_Main_Menu;
    if (screen == 0)
        return 0;

    if (screen->error_code) {
        delete screen;
        return 0;
    }

    panel_system.setCurrentPanel("Main Menu", 0);
    this->set_prog_mode(2);

    TMusic_System* music = this->music_system;
    if (music != 0 && this->started_menu_music == 0) {
        if (music->music_type == 1) {
            music->play_track(2, 0, 0);
        } else if (music->music_type == 2) {
            music->play_file("open.mid", 0, 0);
        } else if (music->music_type == 3) {
            music->play_file("open.wav", 0, 0);
        }
        this->started_menu_music = 1;
    }

    return 1;
}

extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);
extern int do_debug_random;
extern void debug_random_write();
extern void dump_vismap_log();

void TRIBE_Game::quit_game() {
    unsigned char campaign = 0;
    char temp_test_scenario[260];
    _finddata_t file_info;

    if (this->comm_handler->IsLobbyLaunched() != 0 && this->world != 0) {
        static_cast<TRIBE_World*>(this->world)->send_zone_score_info();
    }

    this->disconnect_multiplayer_game();
    this->prog_mode = 0;

    if (do_debug_random != 0) {
        debug_random_write();
        dump_vismap_log();
    }

    if (this->singlePlayerGame() == 1) {
        if (this->world != 0 && this->world->campaign > -1) {
            if (this->player_game_info->set_current_person(this->world->campaign_player) != 0 &&
                this->player_game_info->set_current_campaign(this->world->campaign) != 0) {
                campaign = 1;
            }
        }
    }

    if (this->world != 0) {
        this->world->del_game_info();
    }

    if (this->singlePlayerGame() == 1) {
        if (campaign != 0) {
            if (this->start_campaign_menu() == 0) {
                this->close();
            }
        } else {
            if (this->testing_scenario[0] != 0) {
                this->close_game_screens(0);
                this->game_screen = 0;
                panel_system.destroyPanel("Game Screen");

                sprintf(temp_test_scenario, "%s%s.scn", this->prog_info->scenario_dir, this->testing_scenario);
                if (_findfirst(temp_test_scenario, &file_info) == -1) {
                    sprintf(temp_test_scenario, "%s.scx", this->testing_scenario);
                } else {
                    sprintf(temp_test_scenario, "%s.scn", this->testing_scenario);
                }
                this->testing_scenario[0] = 0;
                if (this->start_scenario_editor(temp_test_scenario, 0) != 0) {
                    this->testing_scenario[0] = 0;
                    return;
                }
            }

            if (this->start_menu() == 0) {
                this->close();
            }
        }
    } else {
        if (this->comm_handler->IsLobbyLaunched() != 0) {
            this->close();
            return;
        }

        TribeJoinScreen* join_screen = new TribeJoinScreen;
        panel_system.setCurrentPanel("Join Screen", 0);
        this->set_prog_mode(2);
    }

    this->close_game_screens(0);
    this->game_screen = 0;
    panel_system.destroyPanel("Game Screen");

    this->testing_scenario[0] = 0;
    return;
}

void TRIBE_Game::restart_game() {
    char temp_name[260];
    _finddata_t fileInfo;
    int result;

    this->show_status_message(0x451, 0, -1);
    this->close_game_screens(0);
    this->game_screen = 0;
    panel_system.destroyPanel("Game Screen");
    this->prog_mode = 0;
    this->world->del_game_info();

    for (int player = 1; player < 9; ++player) {
        this->comm_handler->SetPlayerHumanity(player, static_cast<PLAYERHUMANITY>(this->save_humanity[player]));
    }

    if (this->savedGame() != 0) {
        sprintf(temp_name, "%s%s.gmx", this->prog_info->save_dir, this->load_game_name);
        if (_findfirst(temp_name, &fileInfo) == -1) {
            sprintf(temp_name, "%s.gam", this->load_game_name);
        } else {
            sprintf(temp_name, "%s.gmx", this->load_game_name);
        }
        result = this->load_game(temp_name);
    } else {
        int old_random_game_seed = 0;
        if (this->randomGame() == 1 && this->campaignGame() == 0) {
            old_random_game_seed = this->random_game_seed;
            this->random_game_seed = this->save_random_game_seed;
        }
        result = this->start_game(1);
        if (this->randomGame() != 0 && this->campaignGame() == 0) {
            this->random_game_seed = old_random_game_seed;
        }
    }

    if (result == 0) {
        if (this->start_menu() == 0) {
            this->close();
            return;
        }

        TEasy_Panel* panel = static_cast<TEasy_Panel*>(panel_system.panel("Main Menu"));
        if (panel != 0) {
            static_cast<TEasy_Panel*>(panel)->popupOKDialog(0x961, 0, 0x1C2, 100);
        }
    }
}

int TRIBE_Game::load_db_files() {
    this->disable_input();
    this->show_status_message(0x44d, 0, -1);

    int result = 0;
    if (this->world != 0) {
        delete this->world;
        this->world = 0;
    }

    this->world = this->create_world();
    if (this->world != 0) {
        if (this->world->data_load(this->prog_info->game_data_file, this->prog_info->world_db_file)) {
            result = 1;
        }
        delete this->world;
        this->world = 0;
    }

    this->close_status_message();
    this->enable_input();
    return result;
}

#include "../include/game_globals.h"

int TRIBE_Game::load_game_data() {
    if (this->world == 0) {
        this->world = this->create_world();
        if (this->world == 0)
            return 0;

        if (!this->world->init(this->prog_info->game_data_file, this->sound_system, this->comm_handler)) {
            if (this->world != 0)
                delete this->world;
            this->world = 0;
            return 0;
        }
    }
    return 1;
}

extern "C" char* __cdecl strcpy(char* destination, const char* source);
extern "C" char* __cdecl strchr(const char* source, int character);

extern int ENABLE_COMPRESSION; // 00585A6C

int TRIBE_Game::save_game(char* fileName) {
    if (this->prog_mode != 4 && this->prog_mode != 6 && this->prog_mode != 7 && this->prog_mode != 5) {
        return 0;
    }

    this->disable_input();
    this->show_status_message(0x453, 0, -1);

    if (this->check_prog_argument("DEBUGSAVEGAME") != 0) {
        ENABLE_COMPRESSION = 0;
    }

    int retval = this->world->save_game(fileName);
    ENABLE_COMPRESSION = 1;
    if (retval == 0) {
        this->close_status_message();
        this->enable_input();
        return 0;
    }

    char fileNameNoExt[260];
    strcpy(fileNameNoExt, fileName);
    char* extension = strchr(fileNameNoExt, '.');
    if (extension != 0) {
        *extension = 0;
    }
    this->set_save_game_name(fileNameNoExt);

    if (this->singlePlayerGame() == 1) {
        this->set_paused(0, 0);
    }

    panel_system.setCurrentPanel("Game Screen", 0);
    panel_system.destroyPanel("Save Game Screen");
    panel_system.destroyPanel("Status Screen");
    this->enable_input();
    return 1;
}

int TRIBE_Game::save_scenario(char* fileName) {
    if (this->prog_mode != 4 && this->prog_mode != 6 && this->prog_mode != 7 && this->prog_mode != 5) {
        return 0;
    }

    this->disable_input();
    this->show_status_message(IDS_STATUS_SAVING_SCENARIO, 0, -1);

    for (int i = 1; i < this->world->player_num; i++) {
        this->world->scenario->Set_player_Active(i - 1, 1);
    }

    if (this->world->save_scenario(fileName) == 0) {
        this->enable_input();
        return 0;
    }

    if (this->singlePlayerGame() == 1) {
        this->set_paused(0, 0);
    }

    panel_system.setCurrentPanel("Game Screen", 0);
    panel_system.destroyPanel("Save Game Screen");
    panel_system.destroyPanel("Status Screen");

    this->enable_input();
    return 1;
}

extern "C" char* __cdecl strcpy(char* destination, const char* source);
extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);

extern int show_timing_max;

void TRIBE_Game::calc_timing_text() {
    static unsigned long last_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0x7D4);

    last_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0x7D6);

    if (this->world_update_count == 0) {
        strcpy(this->timing_text2, "f?");
    } else if (show_timing_max == 0) {
        sprintf(this->timing_text2, "t%lu,f%lu,avg(r(v%lu,m%lu,o%lu),s%lu,u%lu,c%lu,l%lu,p%lu,o%lu)",
                this->world_update_fps, this->view_update_fps, this->timings[6].last_time / this->world_update_count,
                this->timings[7].last_time / this->world_update_count,
                this->timings[17].last_time / this->world_update_count,
                this->timings[3].last_time / this->world_update_count,
                this->timings[1].last_time / this->world_update_count,
                this->timings[14].last_time / this->world_update_count,
                (this->timings[10].last_time + this->timings[12].last_time) / this->world_update_count,
                this->timings[13].last_time / this->world_update_count,
                this->timings[4].last_time / this->world_update_count);
    } else {
        sprintf(this->timing_text2, "t%lu,f%lu,max(r(v%lu,m%lu,o%lu),s%lu,u%lu,c%lu,ls%lu,lg%lu,p%lu,o%lu)",
                this->world_update_fps, this->view_update_fps, this->timings[6].last_max_time,
                this->timings[7].last_max_time, this->timings[17].last_max_time, this->timings[3].last_max_time,
                this->timings[1].last_max_time, this->timings[14].last_max_time, this->timings[10].last_max_time,
                this->timings[12].last_max_time, this->timings[13].last_max_time, this->timings[4].last_max_time);
    }

    if (this->view_update_count == 0) {
        strcpy(this->timing_text, "avg view time=???");
        return;
    }

    sprintf(this->timing_text, "avg view time=%lu, count=%lu", this->timings[6].last_time / this->view_update_count,
            this->view_update_count);
}

void TRIBE_Game::show_timings() {
    if (this->game_screen)
        this->game_screen->show_timings(this->timing_text, this->timing_text2);
}

void TRIBE_Game::show_comm() {
    if (this->game_screen == 0)
        return;

    this->game_screen->show_comm(this->comm_handler->GetCommInfo(1), this->comm_handler->GetCommInfo(2),
                                 this->comm_handler->GetCommInfo(3), this->comm_handler->GetCommInfo(4),
                                 this->comm_handler->GetCommInfo(5), this->comm_handler->GetCommInfo(6));
}

#include <string.h>
#include <stdio.h>

void TRIBE_Game::show_ai() {
    int i;
    char str[6][256];
    if (this->world->players == 0) {
        return;
    }
    if (this->world->players[this->world->curr_player]->computerPlayer() == 1) {
        const char* n = this->world->players[this->world->curr_player]->aiStatus(1);
        if (n == 0) {
            sprintf(str[0], "Player #%d: AI is not functional.", this->world->curr_player);
        } else {
            sprintf(str[0], "Player #%d: %s", this->world->curr_player, n);
        }
        i = 2;
        char (*destination)[256] = &str[2];
        for (; i <= 6; ++i) {
            const char* p = this->world->players[this->world->curr_player]->aiStatus(i);
            char* output = destination[-1];
            const char* source = "";
            if (p != 0) {
                source = p;
            }
            strcpy(output, source);
            ++destination;
        }
    } else {
        const char* p = this->world->players[this->world->curr_player]->aiStatus(0);
        strcpy(str[0], p);
        sprintf(str[1], "Player #%d is not a computer player.", this->world->curr_player);
        strcpy(str[2], "");
        strcpy(str[3], "");
        strcpy(str[4], "");
        strcpy(str[5], "");
    }

    if (this->game_screen != 0) {
        if (this->world->players[this->world->curr_player]->computerPlayer() == 1) {
            this->game_screen->show_ai(str[5], str[4], str[3], str[2], str[1], str[0]);
        } else {
            this->game_screen->show_ai(str[0], str[1], str[2], str[3], str[4], str[5]);
        }
    }
}

#include <stdio.h>

extern int player_dropped[9];

void TRIBE_Game::notification(int notify_type, long val1, long val2, long val3, long val4) {
    char msg[256];
    char temp_str[256];

    switch (notify_type) {
    case 0x7E:
        if (val1 == this->world->curr_player && this->game_screen != 0) {
            this->play_sound(0x10);
            this->add_notification_loc(val3, val4);
            return;
        }
        break;

    case 0x7C:
        if (val1 == this->world->curr_player && this->game_screen != 0) {
            this->game_screen->setup_buttons();
            return;
        }
        break;

    case 0x7D:
        if (val1 == this->world->curr_player && this->game_screen != 0) {
            this->get_string2(0x67, 1, val2, msg, 256);
            this->game_screen->show_message(TMessagePanel::BadMessage, msg, 0x55, 0);
            return;
        }
        break;

    case 0x64:
        if (val1 == this->world->curr_player && this->game_screen != 0) {
            if (val2 == 0x65 || val2 == 0x66 || val2 == 0x67) {
                this->play_sound(5);
            } else {
                this->play_sound(0x0F);
            }
            this->game_screen->setup_buttons();
            this->add_notification_loc(val3, val4);
            return;
        }
        break;

    case 0x66:
    case 0x69:
        if (val1 == this->world->curr_player && this->game_screen != 0) {
            this->game_screen->setup_buttons();
            this->add_notification_loc(val3, val4);
            return;
        }
        break;

    case 0x68:
        if (val1 == this->world->curr_player && this->game_screen != 0) {
            this->play_sound(3);
            this->get_string2(0x67, 1000, val2, msg, 256);
            this->game_screen->show_message(TMessagePanel::BadMessage, msg, 0x55, 0);
            return;
        }
        break;

    case 0x6B:
        if (val1 == this->world->curr_player && this->game_screen != 0) {
            this->play_sound(3);
            this->get_string2(0x67, 0x6A, 0, msg, 256);
            this->game_screen->show_message(TMessagePanel::BadMessage, msg, 0x55, 0);
            return;
        }
        break;

    case 1:
        if (val1 == this->world->curr_player && this->game_screen != 0) {
            this->play_sound(3);
            this->get_string2(0x67, 0x66, 0, msg, 256);
            this->game_screen->show_message(TMessagePanel::BadMessage, msg, 0x55, 0);
            return;
        }
        break;

    case 2:
        if (val1 == this->world->curr_player && this->game_screen != 0) {
            this->play_sound(3);
            this->get_string2(0x67, 0x69, 0, msg, 256);
            this->game_screen->show_message(TMessagePanel::BadMessage, msg, 0x55, 0);
            return;
        }
        break;

    case 3:
        if (val1 == this->world->curr_player && this->game_screen != 0) {
            this->play_sound(3);
            this->get_string2(0x67, 0x67, 0, msg, 256);
            this->game_screen->show_message(TMessagePanel::BadMessage, msg, 0x55, 0);
            return;
        }
        break;

    case 4:
        if (this->playerID(val1) != this->world->curr_player && this->game_screen != 0 && player_dropped[val1] == 0) {
            player_dropped[val1] = 1;
            this->play_sound(7);
            if (this->playerID(val1) > 0) {
                this->get_string(0xBC4, temp_str, 256);
                sprintf(msg, temp_str, this->world->players[this->playerID(val1)]->name);
                this->game_screen->display_system_message(msg);
                return;
            }
        }
        break;

    case 5:
        if (val1 != this->world->curr_player && this->game_screen != 0 && val1 > 0) {
            this->play_sound(6);
            if (val2 != 0) {
                this->get_string(0xBC4, temp_str, 256);
            } else {
                this->get_string(0xBC5, temp_str, 256);
            }
            sprintf(msg, temp_str, this->world->players[val1]->name);
            this->game_screen->display_system_message(msg);
            return;
        }
        break;

    case 6:
        if (val1 != this->world->curr_player && this->game_screen != 0) {
            this->play_sound(6);
            if (val1 > 0) {
                this->get_string(0xBC6, temp_str, 256);
                sprintf(msg, temp_str, this->world->players[val1]->name);
                this->game_screen->display_system_message(msg);
                return;
            }
        }
        break;

    case 7:
        if (val2 == this->world->curr_player && this->game_screen != 0) {
            this->play_sound(4);
            switch (val3) {
            case 0:
                this->get_string(0xBC8, temp_str, 256);
                break;
            case 1:
                this->get_string(0xBC7, temp_str, 256);
                break;
            case 3:
                this->get_string(0xBC1, temp_str, 256);
                break;
            default:
                this->get_string(0xBC9, temp_str, 256);
                break;
            }
            sprintf(msg, temp_str, this->world->players[val1]->name, val4);
            this->game_screen->display_system_message(msg);
            return;
        }
        break;

    case 8:
        if (this->game_screen != 0) {
            this->game_screen->reset_clocks();
        }
        if (val2 != this->world->curr_player) {
            return;
        }
        if (this->game_screen == 0) {
            return;
        }
        switch (val3) {
        case 0:
            this->get_string(0xBD2, temp_str, 256);
            break;
        case 1:
            this->get_string(0xBD1, temp_str, 256);
            break;
        case 3:
            this->get_string(0xBD3, temp_str, 256);
            break;
        }
        sprintf(msg, temp_str, this->world->players[val1]->name);
        this->game_screen->display_system_message(msg);
        return;

    case 0x6C:
        if (this->game_screen != 0) {
            this->play_sound(8);
            if (val1 == this->world->curr_player) {
                this->get_string(0xBF2, msg, 256);
                this->game_screen->display_system_message(msg);
            } else {
                RGE_Player* p = this->world->players[val1];
                this->get_string(0xBCB, temp_str, 256);
                sprintf(msg, temp_str, p->name);
                this->game_screen->display_system_message(msg);
            }
            this->add_notification_loc(val2, val3);
            return;
        }
        break;

    case 0x6D: {
        RGE_Player* p1;
        RGE_Player* p2;

        if (this->game_screen == 0) {
            return;
        }
        this->play_sound(9);
        p1 = this->world->players[val1];
        p2 = this->world->players[this->world->curr_player];
        if (p1 == p2) {
            if (static_cast<TRIBE_World*>(this->world)->victory_type == 0) {
                this->get_string(0xBCC, msg, 256);
            } else {
                this->get_string(0xBEE, msg, 256);
            }
        } else {
            if ((p1->allied_victory == 0 || p1->relation(p2->id) != 0) ||
                (p2->allied_victory == 0 || p2->relation(p1->id) != 0)) {
                if (static_cast<TRIBE_World*>(this->world)->victory_type == 0) {
                    this->get_string(0xBCE, temp_str, 256);
                } else {
                    this->get_string(0xBEF, temp_str, 256);
                }
            } else if (static_cast<TRIBE_World*>(this->world)->victory_type == 0) {
                this->get_string(0xBCD, temp_str, 256);
            } else {
                this->get_string(0xBEF, temp_str, 256);
            }
            sprintf(msg, temp_str, p1->name);
        }
        this->add_notification_loc(val2, val3);
        this->game_screen->display_system_message(msg);
        this->game_screen->reset_clocks();
        return;
    }

    case 0x6E: {
        RGE_Player* p1;
        RGE_Player* p2;

        if (this->game_screen == 0) {
            return;
        }
        if (static_cast<TRIBE_World*>(this->world)->victory_type != 0) {
            return;
        }
        this->play_sound(10);
        p1 = this->world->players[val1];
        p2 = this->world->players[this->world->curr_player];
        if (p1 == p2) {
            this->get_string(0xBCF, msg, 256);
        } else {
            if ((p1->allied_victory == 0 || p1->relation(p2->id) != 0) ||
                (p2->allied_victory == 0 || p2->relation(p1->id) != 0)) {
                this->get_string(0xBD0, temp_str, 256);
                sprintf(msg, temp_str, p1->name);
            } else {
                this->get_string(0xBD0, temp_str, 256);
                sprintf(msg, temp_str, p1->name);
            }
        }
        this->add_notification_loc(val2, val3);
        this->game_screen->display_system_message(msg);
        this->game_screen->reset_clocks();
        return;
    }

    case 0x72: {
        RGE_Player* p1;
        RGE_Player* p2;
        int i;

        if (this->game_screen == 0) {
            return;
        }
        this->play_sound(0x0B);
        p1 = this->world->players[val1];
        p2 = this->world->players[this->world->curr_player];
        if (static_cast<TRIBE_World*>(this->world)->victory_type == 0) {
            if (p1 == p2) {
                this->get_string(0xBD4, msg, 256);
            } else {
                if ((p1->allied_victory == 0 || p1->relation(p2->id) != 0) ||
                    (p2->allied_victory == 0 || p2->relation(p1->id) != 0)) {
                    this->get_string(0xBD5, msg, 256);
                } else {
                    this->get_string(0xBD4, msg, 256);
                }
            }
        } else {
            this->get_string(0xBF0, msg, 256);
        }
        this->game_screen->display_system_message(msg);
        this->game_screen->reset_clocks();
        i = 1;
        if (i < this->world->player_num) {
            do {
                this->world->players[i]->notify(p1->id, i, 0x72, 0, 0, 0);
                ++i;
            } while (i < this->world->player_num);
        }
        return;
    }

    case 0x73:
        if (this->game_screen == 0) {
            return;
        }
        if (static_cast<TRIBE_World*>(this->world)->victory_type != 0) {
            return;
        }
        this->play_sound(0x0C);
        this->get_string(0xBD6, msg, 256);
        this->game_screen->display_system_message(msg);
        this->game_screen->reset_clocks();
        return;

    case 0x74: {
        RGE_Player* p1;
        RGE_Player* p2;
        int i;

        if (this->game_screen == 0) {
            return;
        }
        this->play_sound(0x0B);
        p1 = this->world->players[val1];
        p2 = this->world->players[this->world->curr_player];
        if (static_cast<TRIBE_World*>(this->world)->victory_type == 0) {
            if (p1 == p2) {
                this->get_string(0xBD9, msg, 256);
            } else {
                if ((p1->allied_victory == 0 || p1->relation(p2->id) != 0) ||
                    (p2->allied_victory == 0 || p2->relation(p1->id) != 0)) {
                    this->get_string(0xBDA, msg, 256);
                } else {
                    this->get_string(0xBD9, msg, 256);
                }
            }
        } else {
            this->get_string(0xBF1, msg, 256);
        }
        this->game_screen->display_system_message(msg);
        this->game_screen->reset_clocks();
        i = 1;
        if (i < this->world->player_num) {
            do {
                this->world->players[i]->notify(p1->id, i, 0x74, 0, 0, 0);
                ++i;
            } while (i < this->world->player_num);
        }
        return;
    }

    case 0x75:
        if (this->game_screen == 0) {
            return;
        }
        if (static_cast<TRIBE_World*>(this->world)->victory_type != 0) {
            return;
        }
        this->play_sound(0x0C);
        this->get_string(0xBDB, msg, 256);
        this->game_screen->display_system_message(msg);
        this->game_screen->reset_clocks();
        return;

    case 0x76:
        if (val1 == this->world->curr_player && this->game_screen != 0) {
            this->play_sound(3);
            this->get_string(0xBE7, msg, 256);
            this->game_screen->show_message(TMessagePanel::BadMessage, msg, 0x55, 0);
            return;
        }
        break;

    case 0x77:
        if (val1 == this->world->curr_player && this->game_screen != 0) {
            this->play_sound(3);
            this->get_string(0xBE8, msg, 256);
            this->game_screen->show_message(TMessagePanel::BadMessage, msg, 0x55, 0);
            return;
        }
        break;

    case 0x78:
        if (val1 == this->world->curr_player && this->game_screen != 0) {
            this->play_sound(3);
            this->get_string(0xBE9, msg, 256);
            this->game_screen->show_message(TMessagePanel::BadMessage, msg, 0x55, 0);
            return;
        }
        break;

    case 0x79:
        if (val1 == this->world->curr_player && this->game_screen != 0) {
            this->play_sound(3);
            this->get_string(0xBEA, msg, 256);
            this->game_screen->show_message(TMessagePanel::BadMessage, msg, 0x55, 0);
            return;
        }
        break;

    case 0x7A:
        if (val1 == this->world->curr_player && this->game_screen != 0) {
            this->play_sound(3);
            this->get_string(0xBEB, msg, 256);
            this->game_screen->show_message(TMessagePanel::BadMessage, msg, 0x55, 0);
            return;
        }
        break;

    case 0x7B:
        if (this->game_screen != 0 && val1 != this->world->curr_player && val2 == this->world->curr_player) {
            this->play_sound(0x0D);
        }
        break;
    }
}
#include <string.h>
#include <stdio.h>

int TRIBE_Game::start_game(int skip_startup_screens) {
    long info_id;
    char info_file[256];

    if (this->singlePlayerGame()) {
        strcpy(info_file, "scr2");
        info_id = 0xC384;
    } else {
        strcpy(info_file, "scr3");
        info_id = 0xC385;
    }

    this->disable_input();

    if (this->world == 0) {
        this->show_status_message(0x44D, info_file, info_id);
        if (this->load_game_data() == 0) {
            this->close_status_message();
            this->enable_input();
            return 0;
        }
    }

    this->show_status_message(0x451, info_file, info_id);
    if (this->create_game(0) == 0) {
        this->close_status_message();
        this->enable_input();
        return 0;
    }

    this->set_save_game_name(0);
    this->set_load_game_name(0);

    if (skip_startup_screens != 0)
        return this->create_game_screen();

    this->start_video(3, this->world->scenario->Cine_PreGame);
    return 1;
}

#include <string.h>

int TRIBE_Game::test_scenario(char* scenario_file) {
    strcpy(this->testing_scenario, scenario_file);
    panel_system.destroyPanel("Scenario Editor Screen");
    this->set_prog_mode(0);

    if (this->start_scenario(this->testing_scenario))
        return 1;

    if (this->start_scenario_editor(this->testing_scenario, 0))
        return 0;

    if (this->start_menu())
        return 0;

    this->close();
    return 0;
}

extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);

int TRIBE_Game::start_scenario(char* scenario_file) {
    char scenario_file2[260];
    _finddata_t file_info;
    int first_any_player;
    int player_count;
    RGE_Scenario* scenario_info;

    this->disable_input();
    this->setSinglePlayerGame(1);
    this->setCampaignGame(0);
    this->setSavedGame(0);
    this->setScenarioGame(1);
    this->setScenarioName(scenario_file);
    this->setVictoryType(TRIBE_Game::VictoryDefault, 0);
    this->setFullVisibility(0);
    this->setFogOfWar(1);
    this->setAllowCheatCodes(1);
    this->setRandomizePositions(0);
    this->setLongCombat(0);
    this->setAllowTrading(1);
    this->setFullTechTree(0);
    this->setResourceLevel(TRIBE_Game::DefaultResources);
    this->setStartingAge(TRIBE_Game::DefaultAge);
    this->setStartingUnits(0);
    this->setDeathMatch(0);
    this->setPopLimit(50);
    this->setDifficulty(this->get_single_player_difficulty());
    this->setQuickStartGame(0);

    player_count = 0;
    first_any_player = -1;
    sprintf(scenario_file2, "%s%s.scn", this->prog_info->scenario_dir, scenario_file);
    if (_findfirst(scenario_file2, &file_info) == -1) {
        sprintf(scenario_file2, "%s.scx", scenario_file);
    } else {
        sprintf(scenario_file2, "%s.scn", scenario_file);
    }

    scenario_info = this->get_scenario_info(scenario_file2, 0);
    if (scenario_info == 0) {
        this->enable_input();
        return 0;
    }

    for (int i = 0; i < 9; ++i) {
        if (scenario_info->Get_player_Active(i) != 0) {
            this->setScenarioPlayer(player_count, i);
            this->setCivilization(i, scenario_info->Get_player_Civ(i));
            this->setPlayerColor(i, i + 1);
            this->setPlayerTeam(i, 1);
            this->setComputerName(i, 0);
            ++player_count;
            if (first_any_player == -1 && scenario_info->Get_player_Type(i) == 1) {
                first_any_player = i;
            }
        }
    }

    delete scenario_info;
    if (player_count == 0) {
        this->enable_input();
        return 0;
    }

    this->setNumberPlayers(player_count);
    if (first_any_player != -1) {
        int i;
        for (i = 1; i < player_count; ++i) {
            if (this->scenarioPlayer(i) == first_any_player) {
                this->setScenarioPlayer(i, this->scenarioPlayer(0));
                break;
            }
        }
        this->setScenarioPlayer(0, first_any_player);
    }

    this->comm_handler->SetPlayerHumanity(1, ME_HUMAN);
    for (int player = 2; player <= player_count; ++player) {
        this->comm_handler->SetPlayerHumanity(player, ME_COMPUTER);
    }
    ++player_count;
    while (player_count <= 9) {
        this->comm_handler->SetPlayerHumanity(player_count, ME_ABSENT);
        ++player_count;
    }

    return this->start_game(1);
}

#include <stdio.h>
#include <string.h>

extern int numberPathingIterations;
extern int ENABLE_COMPRESSION;

int TRIBE_Game::load_game(char* fileName) {
    TPanel* cur_panel;
    char fileNameNoExt[260];
    char fn[260];
    unsigned char loaded;
    unsigned char* extension;
    int i;

    this->inHandleIdle = 0;
    cur_panel = panel_system.currentPanel();
    this->disable_input();

    if (this->prog_mode == 4 || this->prog_mode == 6 || this->prog_mode == 5) {
        this->prog_mode = 0;
        this->world->del_game_info();
        this->game_screen = 0;
        panel_system.destroyPanel("Game Screen");
    }

    this->show_status_message(0x44D, 0, -1);
    if (this->load_game_data() == 0) {
        if (cur_panel == 0 || cur_panel->panelName() == 0)
            goto load_failed;

        if (*cur_panel->panelName() != 0) {
            panel_system.setCurrentPanel(cur_panel->panelName(), 0);
            panel_system.destroyPanel("Status Screen");
            this->enable_input();
            return 0;
        }
        goto load_failed;
    }

    this->show_status_message(0x452, 0, -1);
    if (this->sound_system != 0)
        this->sound_system->mute = 1;

    if (this->check_prog_argument("DEBUGSAVEGAME") != 0)
        ENABLE_COMPRESSION = 0;

    loaded = this->world->load_game(fileName);
    for (i = 0; i < this->world->player_num; ++i)
        this->reset_countdown_timer(i);
    ENABLE_COMPRESSION = 1;
    if (this->sound_system != 0)
        this->sound_system->mute = 0;

    if (loaded == 0) {
        if (cur_panel == 0 || cur_panel->panelName() == 0)
            goto load_failed;

        if (*cur_panel->panelName() != 0) {
            panel_system.setCurrentPanel(cur_panel->panelName(), 0);
            panel_system.destroyPanel("Status Screen");
            this->enable_input();
            return 0;
        }
        goto load_failed;
    }

    this->setFullVisibility(this->world->map->map_visible_flag);
    this->setFogOfWar(this->world->map->fog_flag);
    this->setAllowCheatCodes(1);
    this->setSavedGame(1);
    this->setNumberPlayers(this->world->player_num - 1);

    switch (this->pathFinding()) {
    case 1:
        numberPathingIterations = 5000;
        break;
    case 2:
        numberPathingIterations = 7500;
        break;
    default:
        numberPathingIterations = 2500;
        break;
    }

    for (i = 0; i < 9; ++i) {
        if (i < this->world->player_num) {
            this->setPlayerID(i, i);
            if (i > 0) {
                this->comm_handler->SetPlayerName(i, this->world->players[i]->name);
                this->comm_handler->SetPlayerHumanity(i, i == 1 ? ME_HUMAN : ME_COMPUTER);
            }
        } else {
            this->setPlayerID(i, 0);
            this->comm_handler->SetPlayerHumanity(i, ME_ABSENT);
        }
    }

    strcpy(fileNameNoExt, fileName);
    extension = _mbschr(reinterpret_cast<unsigned char*>(fileNameNoExt), '.');
    if (extension != 0)
        *extension = 0;
    this->set_save_game_name(fileNameNoExt);
    this->set_load_game_name(fileNameNoExt);

    if (this->check_prog_argument("DEBUGLOAD") != 0) {
        sprintf(fn, "c:\\%s.txt", fileNameNoExt);
        FILE* debug_file = fopen(fn, "w");
        if (debug_file != 0) {
            long total_action_checksum = 0;
            long total_checksum = 0;

            fprintf(debug_file, "world_time=%u\n", this->world->world_time);
            fprintf(debug_file, "old_world_time=%u\n", this->world->old_world_time);
            fprintf(debug_file, "game_speed=%6.2f\n", static_cast<double>(this->world->game_speed));

            for (i = 0; i < this->world->player_num; ++i) {
                RGE_Player* p = this->world->players[i];
                char* p_bytes = reinterpret_cast<char*>(p);
                char* player_name;
                RGE_Victory_Conditions* victory_conditions;
                float* attributes;
                RGE_Object_List* sleeping_objects;
                RGE_Object_List* doppleganger_objects;
                RGE_Object_List* objects;
                short player_id;
                short sleeping_count;
                short doppleganger_count;
                long num1;
                long num2;
                long num3;
                long num4;
                long action_checksum;
                float temp_position_checksum;

                player_name = *reinterpret_cast<char**>(p_bytes + 0x44);
                victory_conditions = *reinterpret_cast<RGE_Victory_Conditions**>(p_bytes + 0x34);

                fprintf(debug_file, "player %d, civ=%d, score=%d, %s\n", i,
                        static_cast<int>(*reinterpret_cast<unsigned char*>(p_bytes + 0x105)),
                        victory_conditions->get_victory_points(), player_name);
                attributes = *reinterpret_cast<float**>(p_bytes + 0x50);
                fprintf(debug_file, "  Writing=%f\n", static_cast<double>(attributes[50]));
                sleeping_objects = *reinterpret_cast<RGE_Object_List**>(p_bytes + 0x2C);
                doppleganger_objects = *reinterpret_cast<RGE_Object_List**>(p_bytes + 0x30);
                sleeping_count = sleeping_objects->number_of_objects;
                doppleganger_count = doppleganger_objects->number_of_objects;
                player_id = *reinterpret_cast<short*>(p_bytes + 0x4A);

                num1 = 0;
                num2 = 0;
                num3 = 0;
                num4 = player_id + sleeping_count + doppleganger_count;
                action_checksum = 0;
                temp_position_checksum = 0.0f;
                fprintf(debug_file, "  num_sleep_obj=%d\n", static_cast<int>(sleeping_count));
                fprintf(debug_file, "  num_dopple_obj=%d\n",
                        static_cast<int>((*reinterpret_cast<RGE_Object_List**>(p_bytes + 0x30))->number_of_objects));

                for (int attribute = 0; attribute < *reinterpret_cast<short*>(p_bytes + 0x4C); ++attribute) {
                    float* attribute_value = *reinterpret_cast<float**>(p_bytes + 0x50) + attribute;
                    num1 += static_cast<long>(*attribute_value);
                    short report_player_id = *reinterpret_cast<short*>(p_bytes + 0x4A);
                    float report_attribute = *attribute_value;
                    fprintf(debug_file, "  p#%d attr[%d]=%12.8f\n", static_cast<int>(report_player_id), attribute,
                            static_cast<double>(report_attribute));
                }

                objects = *reinterpret_cast<RGE_Object_List**>(p_bytes + 0x28);
                RGE_Object_Node* list = objects->list;
                while (list != 0) {
                    RGE_Static_Object* object = list->node;
                    num2 += object->object_state + static_cast<long>(object->attribute_amount_held) +
                            object->master_obj->id;
                    ++num3;
                    temp_position_checksum += object->world_x;
                    temp_position_checksum += object->world_y;
                    temp_position_checksum += object->world_z;
                    action_checksum += object->get_action_checksum();

                    char target_name[50];
                    long target_id;
                    object = list->node;
                    RGE_Static_Object* target = object->get_target_obj();
                    if (target == 0) {
                        target_name[0] = 0;
                        target_id = -1;
                    } else {
                        strcpy(target_name, target->master_obj->name);
                        target_id = target->id;
                    }

                    object = list->node;
                    fprintf(debug_file, "  p#%d ob=%d (%s), st=%d, at=%8.4f, pos=%6.2f,%6.2f,%6.2f, tar=%d (%s)\n",
                            static_cast<int>(*reinterpret_cast<short*>(p_bytes + 0x4A)), static_cast<int>(object->id),
                            object->master_obj->name, static_cast<int>(object->object_state),
                            static_cast<double>(object->attribute_amount_held), static_cast<double>(object->world_x),
                            static_cast<double>(object->world_y), static_cast<double>(object->world_z),
                            static_cast<int>(target_id), target_name);

                    object = list->node;
                    if (object->master_obj->master_type > 0x1D && object->master_obj->master_type != 0x5A) {
                        RGE_Moving_Object* moving_object = static_cast<RGE_Moving_Object*>(object);
                        Path* path = &moving_object->pathValue;
                        if (path->numberOfWaypoints() > 0) {
                            path->initToStart();
                            fprintf(debug_file, "    path: s=%6.2f,%6.2f,%6.2f,g=%6.2f,%6.2f,%6.2f,cc=%d,wd=%d\n",
                                    static_cast<double>(moving_object->startValue.x),
                                    static_cast<double>(moving_object->startValue.y),
                                    static_cast<double>(moving_object->startValue.z),
                                    static_cast<double>(moving_object->goalValue.x),
                                    static_cast<double>(moving_object->goalValue.y),
                                    static_cast<double>(moving_object->goalValue.z), moving_object->continueCounter,
                                    static_cast<int>(moving_object->numberWaitDelays));
                            int waypoint_index = 0;
                            while (waypoint_index < path->numberOfWaypoints()) {
                                Waypoint* waypoint = path->currentWaypoint();
                                int facet = waypoint->facetToNextWaypoint;
                                waypoint = path->currentWaypoint();
                                double waypoint_y = waypoint->y;
                                waypoint = path->currentWaypoint();
                                fprintf(debug_file, "        w%i=%6.2f,%6.2f,%d\n", waypoint_index,
                                        static_cast<double>(waypoint->x), static_cast<double>(waypoint_y), facet);
                                ++waypoint_index;
                                path->moveToNextWaypoint();
                            }
                            path->initToStart();
                            path->moveToNextWaypoint();
                        }
                    }

                    object = list->node;
                    if (object->master_obj->master_type > 0x27 && object->master_obj->master_type != 0x5A) {
                        RGE_Action_Node* act_node = static_cast<RGE_Action_Object*>(object)->actions->list;
                        while (act_node != 0) {
                            RGE_Action* action = act_node->action;
                            if (action != 0) {
                                unsigned char action_state = action->state;
                                int target_id = action->targetID;
                                double action_timer = action->timer;
                                short action_type = action->action_type;
                                int target2_id = action->target2ID;
                                unsigned char sub_action = action->subAction();
                                double target_z = action->targetZ();
                                double target_y = action->targetY();
                                double target_x = action->targetX();
                                fprintf(debug_file,
                                        "    action: typ=%d, st=%d, tar1=%d, tar2=%d, tp=%6.2f,%6.2f,%6.2f, subac=%d, tim=%6.2f\n",
                                        static_cast<int>(action_type), static_cast<int>(action_state), target_id,
                                        target2_id, static_cast<double>(target_x), static_cast<double>(target_y),
                                        static_cast<double>(target_z), static_cast<int>(sub_action),
                                        static_cast<double>(action_timer));
                            }
                            act_node = act_node->next;
                        }
                    }
                    list = list->next;
                }

                doppleganger_objects = *reinterpret_cast<RGE_Object_List**>(p_bytes + 0x30);
                list = doppleganger_objects->list;
                while (list != 0) {
                    RGE_Static_Object* object = list->node;
                    num2 += object->object_state + static_cast<long>(object->attribute_amount_held) +
                            object->master_obj->id;
                    ++num3;
                    temp_position_checksum += object->world_x;
                    temp_position_checksum += object->world_y;
                    temp_position_checksum += object->world_z;
                    action_checksum += object->get_action_checksum();

                    char target_name[50];
                    long target_id;
                    object = list->node;
                    RGE_Static_Object* target = object->get_target_obj();
                    if (target == 0) {
                        target_name[0] = 0;
                        target_id = -1;
                    } else {
                        strcpy(target_name, target->master_obj->name);
                        target_id = target->id;
                    }

                    object = list->node;
                    fprintf(debug_file, "  p#%d ob=%d (%s), st=%d, at=%8.4f, pos=%6.2f,%6.2f,%6.2f, tar=%d (%s)\n",
                            static_cast<int>(*reinterpret_cast<short*>(p_bytes + 0x4A)), static_cast<int>(object->id),
                            object->master_obj->name, static_cast<int>(object->object_state),
                            static_cast<double>(object->attribute_amount_held), static_cast<double>(object->world_x),
                            static_cast<double>(object->world_y), static_cast<double>(object->world_z),
                            static_cast<int>(target_id), target_name);

                    object = list->node;
                    if (object != 0) {
                        RGE_Doppleganger_Object* doppleganger = static_cast<RGE_Doppleganger_Object*>(object);
                        RGE_Master_Static_Object* doppled_master_obj = doppleganger->doppled_master_obj;
                        if (doppled_master_obj != 0) {
                            fprintf(debug_file, "    Doppled master obj:  %s, %d.\n", doppled_master_obj->name,
                                    static_cast<int>(doppled_master_obj->id));
                        } else {
                            fprintf(debug_file, "    NULL doppled master obj.\n");
                        }
                    }

                    object = list->node;
                    if (object->master_obj->master_type > 0x1D && object->master_obj->master_type != 0x5A) {
                        RGE_Moving_Object* moving_object = static_cast<RGE_Moving_Object*>(object);
                        Path* path = &moving_object->pathValue;
                        if (path->numberOfWaypoints() > 0) {
                            path->initToStart();
                            fprintf(debug_file, "    path: s=%6.2f,%6.2f,%6.2f,g=%6.2f,%6.2f,%6.2f,cc=%d,wd=%d\n",
                                    static_cast<double>(moving_object->startValue.x),
                                    static_cast<double>(moving_object->startValue.y),
                                    static_cast<double>(moving_object->startValue.z),
                                    static_cast<double>(moving_object->goalValue.x),
                                    static_cast<double>(moving_object->goalValue.y),
                                    static_cast<double>(moving_object->goalValue.z), moving_object->continueCounter,
                                    static_cast<int>(moving_object->numberWaitDelays));
                            int waypoint_index = 0;
                            while (waypoint_index < path->numberOfWaypoints()) {
                                Waypoint* waypoint = path->currentWaypoint();
                                int facet = waypoint->facetToNextWaypoint;
                                waypoint = path->currentWaypoint();
                                double waypoint_y = waypoint->y;
                                waypoint = path->currentWaypoint();
                                fprintf(debug_file, "        w%i=%6.2f,%6.2f,%d\n", waypoint_index,
                                        static_cast<double>(waypoint->x), static_cast<double>(waypoint_y), facet);
                                ++waypoint_index;
                                path->moveToNextWaypoint();
                            }
                            path->initToStart();
                            path->moveToNextWaypoint();
                        }
                    }

                    object = list->node;
                    if (object->master_obj->master_type > 0x27 && object->master_obj->master_type != 0x5A) {
                        RGE_Action_Node* act_node = static_cast<RGE_Action_Object*>(object)->actions->list;
                        while (act_node != 0) {
                            RGE_Action* action = act_node->action;
                            if (action != 0) {
                                unsigned char action_state = action->state;
                                int target_id = action->targetID;
                                double action_timer = action->timer;
                                short action_type = action->action_type;
                                int target2_id = action->target2ID;
                                unsigned char sub_action = action->subAction();
                                double target_z = action->targetZ();
                                double target_y = action->targetY();
                                double target_x = action->targetX();
                                fprintf(debug_file,
                                        "    action: typ=%d, st=%d, tar1=%d, tar2=%d, tp=%6.2f,%6.2f,%6.2f, subac=%d, tim=%6.2f\n",
                                        static_cast<int>(action_type), static_cast<int>(action_state), target_id,
                                        target2_id, static_cast<double>(target_x), static_cast<double>(target_y),
                                        static_cast<double>(target_z), static_cast<int>(sub_action),
                                        static_cast<double>(action_timer));
                            }
                            act_node = act_node->next;
                        }
                    }
                    list = list->next;
                }

                sleeping_objects = *reinterpret_cast<RGE_Object_List**>(p_bytes + 0x2C);
                list = sleeping_objects->list;
                while (list != 0) {
                    RGE_Static_Object* object = list->node;
                    char target_name[50];
                    long target_id;
                    RGE_Static_Object* target = object->get_target_obj();
                    if (target == 0) {
                        target_name[0] = 0;
                        target_id = -1;
                    } else {
                        strcpy(target_name, target->master_obj->name);
                        target_id = target->id;
                    }
                    object = list->node;
                    fprintf(debug_file, "  p#%d ob=%d (%s), st=%d, at=%8.4f, pos=%6.2f,%6.2f,%6.2f, tar=%d (%s)\n",
                            static_cast<int>(*reinterpret_cast<short*>(p_bytes + 0x4A)), static_cast<int>(object->id),
                            object->master_obj->name, static_cast<int>(object->object_state),
                            static_cast<double>(object->attribute_amount_held), static_cast<double>(object->world_x),
                            static_cast<double>(object->world_y), static_cast<double>(object->world_z),
                            static_cast<int>(target_id), target_name);
                    list = list->next;
                }

                long checksum = (((num4 * 0x100 + num3) * 0x100 + num2) * 0x100) + num1;
                total_checksum += checksum;
                total_action_checksum += action_checksum;
                fprintf(debug_file, "  p#%d checksum=%d, 1=%d, 2=%d, 3=%d, 4=%d, act=%d\n",
                        static_cast<int>(*reinterpret_cast<short*>(p_bytes + 0x4A)), static_cast<int>(checksum),
                        static_cast<int>(num1), static_cast<int>(num2), static_cast<int>(num3), static_cast<int>(num4),
                        static_cast<int>(action_checksum));
            }

            fprintf(debug_file, "total checksum=%d, act=%d\n", static_cast<int>(total_checksum),
                    static_cast<int>(total_action_checksum));
            fclose(debug_file);
        }
    }

    this->close_game_screens(0);
    return this->create_game_screen();

load_failed:
    this->close_status_message();
    this->enable_input();
    return 0;
}

#include "../include/game_globals.h"

void TRIBE_Game::do_game_over(void) {
    disconnect_multiplayer_game();

    if (this->testing_scenario[0] != 0) {
        quit_game();
        return;
    }

    int mode = this->prog_mode;
    if (mode == 4 || mode == 6 || mode == 5 || mode == 3) {
        this->prog_mode = 0;
        if (this->world != 0) {
            turn_world_sound_off();

            RGE_Player* player = get_player();
            if (player->game_status == 1) {
                start_video(4, this->world->scenario->Cine_Victory);
                return;
            }
            start_video(4, this->world->scenario->Cine_Loss);
        }
    }
}

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int TRIBE_Game::create_game(int not_used) {
    int i;
    int player_index;
    int scenario_player;
    int humanity;
    int position_used[8];
    unsigned char path_finding_val;
    T_Scenario* scenario_info;
    RGE_Player_Info player_info;
    char scenario_file[260];
    _finddata_t file_info;
    RGE_Map_Gen_Info map_info;

    this->inHandleIdle = 0;
    for (i = 0; i < 5; ++i) {
        this->notification_loc_x[i] = -1;
        this->notification_loc_y[i] = -1;
    }
    this->current_notification_loc = -1;
    this->current_notification_recalled = -1;

    if (this->check_prog_argument("QUICKBUILD")) {
        this->quick_build = 1;
    } else {
        this->quick_build = 0;
    }

    this->do_show_timings = 0;
    this->do_show_comm = 0;
    this->do_show_ai = 0;
    this->set_map_visible(0);
    this->set_map_fog(0);

    for (i = 1; i < 9; ++i) {
        this->resigned[i] = 0;
        player_dropped[i] = 0;
        this->queue_is_waiting_on_pop_counter[i] = 0;
    }
    out_of_sync = 0;
    out_of_sync2 = 0;
    DAT_0086be00 = 0;

    if (this->quickStartGame()) {
        MapType map_type;

        if (quick_start_game_mode == 1) {
            this->setMapSize(Medium);
            map_type = AllLand;
        } else {
            int value;

            this->setMapSize(Large);
            value = debug_rand("C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0xCDD) % 10;
            if (value < 2) {
                map_type = AllLand;
            } else if (value == 2) {
                map_type = MostlyLand;
            } else if (value == 3) {
                map_type = WaterAndLand;
            } else if (value == 4) {
                map_type = MostlyWater;
            } else if (value == 5) {
                map_type = Continental;
            } else if (value == 6) {
                map_type = Lake;
            } else if (value == 7) {
                map_type = Hilly;
            } else if (value == 8) {
                map_type = Isthmas;
            } else {
                map_type = AllWater;
            }
        }
        this->setMapType(map_type);

        this->resetRandomComputerName();
        for (i = 0; i < this->numberPlayers(); ++i) {
            int civilization = debug_rand("C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0xCF8) % 16 + 1;
            this->setCivilization(i, civilization);
            this->setComputerName(i, this->randomComputerName(civilization));
        }
    }

    memset(&player_info, 0, sizeof(player_info));
    memset(&map_info, 0, sizeof(map_info));

    if (this->campaignGame()) {
        player_info.campaign = 1;
    } else if (this->scenarioGame()) {
        if (this->scenarioName() == 0) {
            return 0;
        }

        char* scenario_dir = this->prog_info->scenario_dir;
        sprintf(scenario_file, "%s%s.scn", scenario_dir, this->scenarioName());
        if (_findfirst(scenario_file, &file_info) == -1) {
            sprintf(scenario_file, "%s.scx", this->scenarioName());
        } else {
            sprintf(scenario_file, "%s.scn", this->scenarioName());
        }
        player_info.scenario = scenario_file;
    } else {
        player_info.map_info = &map_info;
        player_info.map_type = static_cast<short>(this->mapType());
        player_info.map_width = static_cast<short>(this->mapXSize());
        player_info.map_height = static_cast<short>(this->mapYSize());
    }

    if (this->multiplayerGame()) {
        debug_srand("C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0xD24, comm->GetRandomSeed());
    } else if (this->random_game_seed != -1) {
        debug_srand("C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0xD28, this->random_game_seed);
    } else {
        debug_srand("C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0xD2A,
                    debug_rand("C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0xD2A));
    }

    player_info.player_num = 0;
    for (i = 0; i < 9; ++i) {
        player_info.type[i] = -1;
        player_info.name[i][0] = 0;
        player_info.player_id_hash[i] = i;
        player_info.tribe[i] = 1;
        player_info.color[i] = -1;
        this->random_civ[i] = 0;

        if (this->civilization(i) > 16 || this->civilization(i) < 0) {
            this->setCivilization(i, debug_rand("C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0xD3B) * 16 / 0x7FFF + 1);
            this->random_civ[i] = 1;
        }
    }

    this->resetRandomComputerName();
    for (i = 0; i < this->numberPlayers(); ++i) {
        if (comm->GetPlayerHumanity(i + 1) == ME_COMPUTER) {
            this->setComputerName(i, this->randomComputerName(this->civilization(i)));
        }
    }

    if (this->campaignGame()) {
        scenario_info = static_cast<T_Scenario*>(this->get_scenario_info(0, 1));
        if (scenario_info == 0) {
            return 0;
        }
    } else if (this->scenarioGame()) {
        scenario_info = static_cast<T_Scenario*>(this->get_scenario_info(player_info.scenario, 0));
        if (scenario_info == 0) {
            return 0;
        }
    } else {
        scenario_info = 0;
    }

    // The original declares eight entries but initializes nine.
    for (i = 0; i < 9; ++i) {
        position_used[i] = -1;
    }
    for (i = 0; i < 9; ++i) {
        this->setPlayerID(i, 0);
    }

    scenario_player = 0;
    for (player_index = 1; player_index <= this->numberPlayers(); ++player_index) {
        if (this->comm_handler->GetPlayerHumanity(player_index) == ME_HUMAN) {
            int position = this->playerColor(player_index - 1) - 1;
            if (position_used[position] == -1) {
                position_used[position] = scenario_player++;
            }
            this->setPlayerID(player_index, position_used[position] + 1);
        } else if (this->comm_handler->GetPlayerHumanity(player_index) == ME_COMPUTER) {
            int position;
            for (position = 0; position < 8; ++position) {
                int used_by_human = 0;
                if (position_used[position] == -1) {
                    int human_player;
                    for (human_player = 1; human_player < 9; ++human_player) {
                        if (this->comm_handler->GetPlayerHumanity(human_player) == ME_HUMAN &&
                            this->playerColor(human_player - 1) - 1 == position) {
                            used_by_human = 1;
                            break;
                        }
                    }
                    if (!used_by_human) {
                        this->setPlayerColor(player_index - 1, position + 1);
                        position_used[position] = scenario_player++;
                        this->setPlayerID(player_index, position_used[position] + 1);
                        break;
                    }
                }
            }
        }
    }

    this->resetRandomComputerName();
    for (i = 0; i < 8; ++i) {
        int color;

        scenario_player = 0;
        for (player_index = 1; player_index < 9; ++player_index) {
            if (this->playerID(player_index) == i + 1) {
                scenario_player = player_index;
                break;
            }
        }
        if (scenario_player == 0) {
            break;
        }

        humanity = this->comm_handler->GetPlayerHumanity(scenario_player);
        player_index = scenario_player - 1;
        color = this->playerColor(player_index) - 1;

        if (humanity == ME_COMPUTER || all_cp == 1 || (all_cp == 2 && i > 0)) {
            player_info.type[i] = ME_COMPUTER;
        } else {
            player_info.type[i] = 0;
        }

        if (this->campaignGame()) {
            player_info.tribe[i] = static_cast<char>(scenario_info->Get_player_Civ(color));
        } else {
            player_info.tribe[i] = static_cast<char>(this->civilization(player_index));
        }

        if (this->multiplayerGame() && humanity == ME_HUMAN) {
            strncpy(player_info.name[i], this->comm_handler->GetPlayerName(scenario_player), 0x40);
        } else {
            if (this->campaignGame() && player_info.type[i] == 0) {
                strcpy(player_info.name[i], this->player_game_info->get_current_player_name());
            } else if (!this->campaignGame() && this->randomGame() && player_info.type[i] == 0) {
                this->get_string(0x286D, player_info.name[i], 0x41);
            } else if (this->campaignGame() || this->scenarioGame()) {
                strcpy(player_info.name[i], scenario_info->GetPlayerName(color));
            }

            if (player_info.name[i][0] == 0) {
                if (player_info.type[i] == 0) {
                    this->get_string(0x286D, player_info.name[i], 0x41);
                } else if (!this->campaignGame() && this->computerName(player_index) != 0) {
                    this->get_string(this->computerName(player_index) + 0x1130, player_info.name[i], 0x41);
                } else {
                    this->get_string(this->randomComputerName(player_info.tribe[i]) + 0x1130, player_info.name[i],
                                     0x41);
                }
            }
            this->comm_handler->SetPlayerName(scenario_player, player_info.name[i]);
        }

        player_info.player_id_hash[i + 1] = color + 1;
        player_info.color[i] = static_cast<short>(color);
        ++player_info.player_num;
    }

    if (scenario_info != 0) {
        delete scenario_info;
    }
    if (player_info.player_num == 0) {
        return 0;
    }

    if (this->sound_system != 0) {
        this->sound_system->mute = 1;
    }

    int current_player = this->multiplayerGame() ? this->comm_handler->WhoAmI() : 1;
    int current_player_id = this->playerID(current_player);
    int result = this->world->new_game(player_info, current_player_id);
    if (result != 0 && this->world->player_num < 2) {
        result = 0;
        this->world->del_game_info();
    }

    if (this->sound_system != 0) {
        this->sound_system->mute = 0;
    }

    for (i = 0; i < this->world->player_num; ++i) {
        this->reset_countdown_timer(i);
    }
    this->world->update_mutual_allies();

    this->set_map_visible(0);
    if (this->fullVisibility()) {
        for (i = 1; i < this->world->player_num; ++i) {
            if (!this->world->players[i]->computerPlayer()) {
                this->world->players[i]->visible->explore_all();
            }
        }
    }
    this->set_map_fog(static_cast<unsigned char>(this->fogOfWar()));

    if (this->multiplayerGame()) {
        path_finding_val = this->mpPathFinding();
    } else {
        path_finding_val = this->pathFinding();
    }
    if (path_finding_val == 1) {
        numberPathingIterations = 5000;
    } else if (path_finding_val == 2) {
        numberPathingIterations = 0x1D4C;
    } else {
        numberPathingIterations = 0x9C4;
    }

    for (i = 1; i < 9; ++i) {
        this->save_humanity[i] = this->comm_handler->GetPlayerHumanity(i);
    }

    return result;
}

int TRIBE_Game::create_game_screen() {
    TRIBE_Screen_Game* screen;

    this->disable_input();
    this->set_game_mode(0, 0);

    screen = new TRIBE_Screen_Game;
    this->game_screen = screen;

    if (screen != 0 && screen->error_code == 0) {
        if (this->comm_handler->MultiplayerGameStart() == 0) {
            TRIBE_Screen_Wait* wait = new TRIBE_Screen_Wait;
            if (wait != 0) {
                wait->set_text(0x454);
                panel_system.setCurrentPanel("Multiplayer Wait Screen", 0);
                panel_system.destroyPanel("Status Screen");
                this->set_prog_mode(3);
                goto create_game_screen_common;
            }

            if (this->game_screen != 0) {
                delete this->game_screen;
            }
            RGE_Game_World* world = this->world;
            this->game_screen = 0;
            world->del_game_info();
            goto create_game_screen_failed;
        }

        panel_system.setCurrentPanel("Game Screen", 0);
        panel_system.destroyPanel("Status Screen");

    create_game_screen_common:
        panel_system.destroyPanel("Single Player Menu");
        panel_system.destroyPanel("Game Setup Screen");
        panel_system.destroyPanel("Select Scenario Screen");
        panel_system.destroyPanel("Game Settings Screen");
        panel_system.destroyPanel("Load Saved Game Screen");
        panel_system.destroyPanel("MP Setup Screen");
        panel_system.destroyPanel("Join Screen");
        panel_system.destroyPanel("MP Startup Screen");
        panel_system.destroyPanel("Main Menu");
        panel_system.destroyPanel("Campaign Selection Screen");
        if (this->prog_mode != 3) {
            this->let_game_begin();
        }
        return 1;
    }

    if (this->game_screen != 0) {
        delete this->game_screen;
        this->game_screen = 0;
    }

    this->world->del_game_info();

create_game_screen_failed:
    this->close_status_message();
    this->enable_input();
    return 0;
}

extern "C" char* __cdecl strcpy(char*, const char*);
extern "C" char* __cdecl strstr(const char*, const char*);
extern "C" int __cdecl strcmp(const char*, const char*);
extern "C" int __cdecl sscanf(const char*, const char*, ...);

extern void __cdecl encrypt_codes(char* source, char* dest, int maxlen);

int TRIBE_Game::processCheatCode(int playerID, char* text) {
    char encstr[512];
    char str[256];

    if (text == 0 || playerID < 0 || playerID >= this->world->player_num) {
        return 0;
    }

    strcpy(str, text);
    _mbsupr(reinterpret_cast<unsigned char*>(str));
    encrypt_codes(str, encstr, 0x200);

    if (this->allowCheatCodes() == 0) {
        return 0;
    }

    if (strcmp(encstr, "@)%^%cAm %%_jdW") == 0 && this->singlePlayerGame() != 0) {
        static_cast<TRIBE_World*>(this->world)->send_cheat(0x66);
        return 1;
    } else if (strstr(str, "STORMBILLY") != 0) {
        static_cast<TRIBE_World*>(this->world)->send_cheat(0x0e);
        return 1;
    } else if (strstr(str, "CONVERT THIS!") != 0) {
        static_cast<TRIBE_World*>(this->world)->send_cheat(0x0f);
        return 1;
    } else if (strstr(str, "BIG MOMMA") != 0) {
        static_cast<TRIBE_World*>(this->world)->send_cheat(0x10);
        return 1;
    } else if (strstr(str, "MINIWINSETT") != 0) {
        static_cast<TRIBE_World*>(this->world)->send_cheat(0x11);
        return 1;
    } else if (strstr(str, "GRANTLINKSPENCE") != 0) {
        static_cast<TRIBE_World*>(this->world)->send_cheat(0x12);
        return 1;
    } else if (strstr(str, "KING ARTHUR") != 0) {
        static_cast<TRIBE_World*>(this->world)->send_cheat(0x13);
        return 1;
    } else if (strcmp(encstr, "w>@)%^ ^%^dW %chxdW") == 0) {
        static_cast<TRIBE_World*>(this->world)->send_cheat(0);
        return 1;
    } else if (strcmp(encstr, "Am=%c3C2  ^%%%^%^w>Am%%") == 0) {
        static_cast<TRIBE_World*>(this->world)->send_cheat(1);
        return 1;
    } else if (strcmp(encstr, "}{hx3CcW *_Am dW#L%c*_+!Am") == 0) {
        static_cast<TRIBE_World*>(this->world)->send_cheat(2);
        return 1;
    } else if (strcmp(encstr, "*_#L1Z *_Am%% ^@)hx") == 0) {
        static_cast<TRIBE_World*>(this->world)->send_cheat(3);
        return 1;
    } else if (strcmp(encstr, "Jm+!::#LdW1Z ?>_j ^3C@)%chxdW") == 0) {
        static_cast<TRIBE_World*>(this->world)->send_cheat(4);
        return 1;
    } else if (strcmp(encstr, "_jw>1$#L?>Jm+!#LdW ^%c%^*_#L+!Am") == 0) {
        static_cast<TRIBE_World*>(this->world)->send_cheat(7);
        return 1;
    } else if (strcmp(encstr, "@)%^::%^@)%^::%^") == 0) {
        static_cast<TRIBE_World*>(this->world)->send_cheat(8);
        return 1;
    } else if (strcmp(encstr, "?>hx%%cW %%hx#LdW") == 0) {
        static_cast<TRIBE_World*>(this->world)->send_cheat(10);
        return 1;
    } else if (strcmp(encstr, "*_+!hx3CcW %%#L?>Am%%") == 0) {
        static_cast<TRIBE_World*>(this->world)->send_cheat(11);
        return 1;
    } else if (strcmp(encstr, "%cAm?>_j1$hx") == 0) {
        static_cast<TRIBE_World*>(this->world)->send_cheat(12);
        return 1;
    } else if (strcmp(encstr, "#L3C*_%c") == 0) {
        static_cast<TRIBE_World*>(this->world)->send_cheat(13);
        return 1;
    } else {
        if (this->singlePlayerGame() != 0) {
            if (strcmp(encstr, "?>#LAm?>#LAm?>#LAm") == 0) {
                static_cast<TRIBE_World*>(this->world)->send_cheat(100);
                return 1;
            } else if (strcmp(encstr, "cW#L+!+!1") == 0) {
                static_cast<TRIBE_World*>(this->world)->send_cheat(0xc9);
                return 1;
            } else if (strcmp(encstr, "cW#L+!+!2") == 0) {
                static_cast<TRIBE_World*>(this->world)->send_cheat(0xca);
                return 1;
            } else if (strcmp(encstr, "cW#L+!+!3") == 0) {
                static_cast<TRIBE_World*>(this->world)->send_cheat(0xcb);
                return 1;
            } else if (strcmp(encstr, "cW#L+!+!4") == 0) {
                static_cast<TRIBE_World*>(this->world)->send_cheat(0xcc);
                return 1;
            } else if (strcmp(encstr, "cW#L+!+!5") == 0) {
                static_cast<TRIBE_World*>(this->world)->send_cheat(0xcd);
                return 1;
            } else if (strcmp(encstr, "cW#L+!+!6") == 0) {
                static_cast<TRIBE_World*>(this->world)->send_cheat(0xce);
                return 1;
            } else if (strcmp(encstr, "cW#L+!+!7") == 0) {
                static_cast<TRIBE_World*>(this->world)->send_cheat(0xcf);
                return 1;
            } else if (strcmp(encstr, "cW#L+!+!9") == 0) {
                static_cast<TRIBE_World*>(this->world)->send_cheat(0xd0);
                return 1;
            }
        }
        if (strcmp(encstr, "@)hx%%#L cWhx%%#L") == 0) {
            static_cast<TRIBE_World*>(this->world)->send_cheat(0x65);
            return 1;
        } else if (strcmp(encstr, "%%Am1$#L1ZdW") == 0) {
            static_cast<TRIBE_World*>(this->world)->send_cheat(0x67);
            return 1;
        } else if (strcmp(encstr, "1Zhx#Lhx") == 0) {
            this->get_player()->unselect_object();
            if (this->game_mode == 6 && this->sub_game_mode == 1)
                this->set_game_mode(0, 0);
            this->set_player(0);
            return 1;
        } else if (strcmp(encstr, "w>Amw>w>Am%%%^dW#L w>#LS?S?hx") == 0) {
            this->get_player()->command_add_attribute(0, 1000.0f);
            return 1;
        } else if (strcmp(encstr, "3C%^#LdWhx1ZAm") == 0) {
            this->get_player()->command_add_attribute(3, 1000.0f);
            return 1;
        } else if (strcmp(encstr, "43%^%^?>1$ ^%^3CcW") == 0) {
            this->get_player()->command_add_attribute(1, 1000.0f);
            return 1;
        } else if (strcmp(encstr, "hx_jhx%%%%::") == 0) {
            this->get_player()->command_add_attribute(2, 1000.0f);
            return 1;
        } else if (strcmp(encstr, "1$ ^Am%%%^#L?>1$") == 0) {
            static_cast<TRIBE_Command*>(this->world->commands)
                ->command_quick_build(static_cast<short>(this->quick_build == 0));
            return 1;
        } else if (strcmp(encstr, "*_#L1Z?>hx?>?>::") == 0) {
            static_cast<TRIBE_World*>(this->world)->send_cheat(0xdc);
            return 1;
        } else if (strcmp(encstr, "%%Am&TAmhx+! %chxw>") == 0) {
            static_cast<TRIBE_World*>(this->world)->send_cheat(0xe6);
            return 1;
        } else if (strcmp(encstr, "dW%^ Jm%^1Z") == 0) {
            static_cast<TRIBE_World*>(this->world)->send_cheat(0xe7);
            return 1;
        } else {
            char tempStr1[256];
            sscanf(str, "%s ", tempStr1);
            if (strcmp(tempStr1, "SELECTOBJ") == 0) {
                int objectID;
                sscanf(text, "%*s %d ", &objectID);
                RGE_Static_Object* obj = this->world->object(objectID);
                if (obj != 0) {
                    obj->selected = 1;
                    this->world->players[playerID]->selected_obj = obj;
                }
            }
            if (strcmp(tempStr1, "RUNPLAY") == 0) {
                int target;
                int commander;
                char playName[256];
                sscanf(text, "%*s %d %s %d ", &target, playName, &commander);
                int play = this->world->playbook->playNumber(playName);
                if (play != -1) {
                    this->world->players[playerID]->sendPlayCommand(target, commander, play);
                    return 1;
                }
            } else {
                if (strcmp(encstr, "S?Am_j1$") != 0) {
                    return 0;
                }
                this->world->players[playerID]->sendAICommand(playerID, 0, 0, 0, 0);
            }
            return 1;
        }
    }

    return 0;
}
#include <stdio.h>
#include <string.h>

extern void __cdecl run_log(char* str, int show_time);
extern "C" __declspec(dllimport) int __stdcall IsIconic(void* window);

extern TPanelSystem panel_system;
extern TChat* chat;

void TRIBE_Game::let_game_begin() {
    int i;
    char int_str[10];
    char map_type_str[20];
    char map_size_str[20];
    char age_str[256];
    char res_str[256];
    char vic_str[256];
    char str[1024];
    char diff_str[256];

    panel_system.setCurrentPanel("Game Screen", 0);
    panel_system.destroyPanel("Status Screen");
    panel_system.destroyPanel("Multiplayer");
    run_log("game started", 1);

    switch (this->mapType()) {
    case TRIBE_Game::AllWater:
        this->get_string(0x296A, map_type_str, 0x14);
        break;
    case TRIBE_Game::MostlyWater:
        this->get_string(0x296B, map_type_str, 0x14);
        break;
    case TRIBE_Game::WaterAndLand:
        this->get_string(0x296C, map_type_str, 0x14);
        break;
    case TRIBE_Game::MostlyLand:
        this->get_string(0x296D, map_type_str, 0x14);
        break;
    case TRIBE_Game::AllLand:
        this->get_string(0x296E, map_type_str, 0x14);
        break;
    case TRIBE_Game::Continental:
        this->get_string(0x296F, map_type_str, 0x14);
        break;
    case TRIBE_Game::Lake:
        this->get_string(0x2970, map_type_str, 0x14);
        break;
    default:
        this->get_string(0x2804, map_type_str, 0x14);
        break;
    }

    switch (this->mapSize()) {
    case 0:
        this->get_string(0x2973, map_size_str, 0x14);
        break;
    case 1:
        this->get_string(0x2974, map_size_str, 0x14);
        break;
    case 2:
        this->get_string(0x2975, map_size_str, 0x14);
        break;
    case 3:
        this->get_string(0x2976, map_size_str, 0x14);
        break;
    case 4:
        this->get_string(0x2977, map_size_str, 0x14);
        break;
    case 5:
        this->get_string(0x2978, map_size_str, 0x14);
        break;
    default:
        this->get_string(0x2804, map_size_str, 0x14);
        break;
    }

    sprintf(str, "    randomgame=%d, randommap=%d, mapsize=%s, maptype=%s", this->save_random_game_seed,
            this->save_random_map_seed, map_size_str, map_type_str);
    run_log(str, 0);

    switch (this->victoryType()) {
    case TRIBE_Game::VictoryDefault:
        strcpy(vic_str, "Default");
        break;
    case TRIBE_Game::VictoryTime:
        sprintf(vic_str, "Time(%d)", this->victoryAmount());
        break;
    case TRIBE_Game::VictoryScore:
        sprintf(vic_str, "Score(%d)", this->victoryAmount());
        break;
    case TRIBE_Game::VictoryStandard:
        strcpy(vic_str, "Standard");
        break;
    default:
        strcpy(vic_str, "Unknown");
        break;
    }

    if (this->deathMatch() != 0) {
        strcpy(res_str, "DeathMatch");
    } else {
        switch (this->resourceLevel()) {
        case TRIBE_Game::DefaultResources:
            strcpy(res_str, "Default");
            break;
        case TRIBE_Game::LowResources:
            strcpy(res_str, "Low");
            break;
        case TRIBE_Game::MediumResources:
            strcpy(res_str, "Medium");
            break;
        case TRIBE_Game::HighResources:
            strcpy(res_str, "High");
            break;
        default:
            strcpy(res_str, "Unknown");
            break;
        }
    }

    switch (this->startingAge()) {
    case TRIBE_Game::DefaultAge:
        strcpy(age_str, "Default");
        break;
    case TRIBE_Game::StoneAge:
        strcpy(age_str, "Stone");
        break;
    case TRIBE_Game::ToolAge:
        strcpy(age_str, "Tool");
        break;
    case TRIBE_Game::BronzeAge:
        strcpy(age_str, "Bronze");
        break;
    case TRIBE_Game::IronAge:
        strcpy(age_str, "Iron");
        break;
    default:
        strcpy(age_str, "Unknown");
        break;
    }

    strcpy(diff_str, "Unknown");
    this->get_string(0x2BD0 + this->difficulty(), &diff_str[0], 0x100);
    sprintf(str, "    resources=%s, age=%s, victory=%s, difficulty=%s", res_str, age_str, vic_str, diff_str);
    run_log(str, 0);

    sprintf(str, "    fulltech=%d, revealmap=%d", this->fullTechTree(), this->fullVisibility());
    run_log(str, 0);

    sprintf(str, "    numplayers=%d", this->world->player_num - 1);
    strcat(str, " players=");
    for (i = 1; i < this->world->player_num; ++i) {
        sprintf(int_str, "%d", this->playerColor(i - 1));
        strcat(str, int_str);
    }

    strcat(str, " teams=");
    for (i = 1; i < this->world->player_num; ++i) {
        sprintf(int_str, "%d", this->playerTeam(i - 1) - 1);
        strcat(str, int_str);
    }

    strcat(str, " civs=");
    for (i = 1; i < this->world->player_num; ++i) {
        sprintf(int_str, "%d ", this->civilization(i - 1));
        strcat(str, int_str);
    }
    run_log(str, 0);

    TMusic_System* music = this->music_system;
    if (music != 0) {
        if (music->music_type == 1) {
            music->play_tracks(5, 0x0E, 1, 0, 0);
        } else if (music->music_type == 2) {
            music->play_tracks(1, music->track_count, 1, 0, 0);
        } else if (music->music_type == 3) {
            music->stop_track();
        }
        this->started_menu_music = 0;
    }

    this->reset_timings();
    this->set_prog_mode(4);
    if (this->singlePlayerGame() == 1) {
        this->set_paused(0, 0);
    }
    this->auto_paused = 0;
    chat->ClearChat();
    chat->setInChatGroup(this->world->curr_player, 1);
    if (this->mouse_pointer != 0 && this->prog_active != 0) {
        if (IsIconic(this->prog_window) == 0) {
            this->mouse_pointer->center();
        }
    }
    this->enable_input();
}

int TRIBE_Game::start_scenario_editor(char* scenario_name_in, int is_multi_player_in) {
    this->disable_input();
    panel_system.destroyPanel("Scenario Editor Screen");

    TRIBE_Screen_Sed* editor = new TRIBE_Screen_Sed(scenario_name_in, is_multi_player_in);
    if (editor != 0 && editor->error_code == 0) {
        if (this->music_system != 0) {
            this->music_system->stop_track();
            this->started_menu_music = 0;
        }

        panel_system.setCurrentPanel("Scenario Editor Screen", 0);
        panel_system.destroyPanel("Scenario Editor Open");
        panel_system.destroyPanel("Scenario Editor Menu");
        panel_system.destroyPanel("Status Screen");
        this->mouse_pointer->center();
        this->enable_input();
        return 1;
    }

    if (panel_system.panel("Scenario Editor Open") != 0) {
        panel_system.setCurrentPanel("Scenario Editor Open", 0);
    } else if (panel_system.panel("Scenario Editor Menu") != 0) {
        panel_system.setCurrentPanel("Scenario Editor Menu", 0);
    } else {
        panel_system.setCurrentPanel("Blank Screen", 0);
    }

    panel_system.destroyPanel("Scenario Editor Screen");
    panel_system.destroyPanel("Status Screen");
    this->enable_input();
    return 0;
}

void TRIBE_Game::send_game_options(void) {
    TRIBE_Game_Combined_Options combined_options;

    if (this->comm_handler != 0) {
        this->get_game_options(&combined_options.base);
        this->get_tribe_options(&combined_options.tribe);
        this->comm_handler->SetMyGameOptions(reinterpret_cast<char*>(&combined_options), 0x114);
    }
}

void TRIBE_Game::receive_game_options(void) {
    if (this->comm_handler != 0) {
        unsigned long size = 0;
        TRIBE_Game_Combined_Options* options =
            static_cast<TRIBE_Game_Combined_Options*>(this->comm_handler->GetMyGameOptions(&size));
        if (options != 0 && size == 0x114) {
            this->set_game_options(&options->base);
            this->set_tribe_options(&options->tribe);
        }
    }
}

void TRIBE_Game::set_tribe_options(TRIBE_Game_Options* options) {
    int i;

    this->setMapSize(options->mapSizeValue);
    this->setMapType(options->mapTypeValue);
    this->setAnimals(options->animalsValue);
    this->setPredators(options->predatorsValue);
    this->setVictoryType(options->victoryTypeValue, options->victoryAmountValue);

    for (i = 0; i < 9; i++) {
        this->setCivilization(i, options->civilizationValue[i]);
        this->setScenarioPlayer(i, options->scenarioPlayerValue[i]);
        this->setPlayerColor(i, options->playerColorValue[i]);
        this->setComputerName(i, options->computerNameValue[i]);
    }

    this->setAllowTrading(options->allowTradingValue);
    this->setLongCombat(options->longCombatValue);
    this->setRandomizePositions(options->randomizePositionsValue);
    this->setFullTechTree(options->fullTechTreeValue);
    this->setResourceLevel(options->resourceLevelValue);
    this->setStartingAge(options->startingAgeValue);
    this->setStartingUnits(options->startingUnitsValue);
    this->setDeathMatch(options->deathMatchValue);
    this->setPopLimit(options->popLimitValue);
}

void TRIBE_Game::get_tribe_options(TRIBE_Game_Options* options) {
    int i;

    options->mapSizeValue = mapSize();
    options->mapTypeValue = mapType();
    options->animalsValue = animals();
    options->predatorsValue = predators();
    options->victoryTypeValue = victoryType();
    options->victoryAmountValue = victoryAmount();

    for (i = 0; i < 9; i++) {
        options->civilizationValue[i] = static_cast<unsigned char>(civilization(i));
        options->scenarioPlayerValue[i] = scenarioPlayer(i);
        options->playerColorValue[i] = static_cast<unsigned char>(playerColor(i));
        options->computerNameValue[i] = static_cast<unsigned char>(computerName(i));
    }

    options->allowTradingValue = static_cast<unsigned char>(allowTrading());
    options->longCombatValue = static_cast<unsigned char>(longCombat());
    options->randomizePositionsValue = static_cast<unsigned char>(randomizePositions());
    options->fullTechTreeValue = static_cast<unsigned char>(fullTechTree());
    options->resourceLevelValue = resourceLevel();
    options->startingAgeValue = startingAge();
    options->startingUnitsValue = static_cast<unsigned char>(startingUnits());
    options->deathMatchValue = deathMatch();
    options->popLimitValue = popLimit();
}

TRIBE_Game::MapSize TRIBE_Game::mapSize() const {
    return static_cast<TRIBE_Game::MapSize>(this->tribe_game_options.mapSizeValue);
}

void TRIBE_Game::setMapSize(MapSize v) {
    this->tribe_game_options.mapSizeValue = v;
    switch (v) {
    case Tiny:
        this->RGE_Base_Game::setMapSize(0x48, 0x48, 8);
        break;
    case Small:
        this->RGE_Base_Game::setMapSize(0x60, 0x60, 8);
        break;
    case Medium:
        this->RGE_Base_Game::setMapSize(0x78, 0x78, 8);
        break;
    case Large:
        this->RGE_Base_Game::setMapSize(0x90, 0x90, 8);
        break;
    case Huge:
        this->RGE_Base_Game::setMapSize(0xC8, 0xC8, 8);
        break;
    case Humongous:
        this->RGE_Base_Game::setMapSize(0xFA, 0xFA, 8);
        break;
    }
}

TRIBE_Game::MapType TRIBE_Game::mapType() const {
    return static_cast<TRIBE_Game::MapType>(this->tribe_game_options.mapTypeValue);
}

void TRIBE_Game::setMapType(TRIBE_Game::MapType v) {
    this->tribe_game_options.mapTypeValue = v;
}

int TRIBE_Game::animals() const {
    return this->tribe_game_options.animalsValue;
}

void TRIBE_Game::setAnimals(int v) {
    this->tribe_game_options.animalsValue = v;
}

int TRIBE_Game::predators() const {
    return this->tribe_game_options.predatorsValue;
}

void TRIBE_Game::setPredators(int v) {
    this->tribe_game_options.predatorsValue = v;
}

TRIBE_Game::VictoryType TRIBE_Game::victoryType() const {
    return static_cast<TRIBE_Game::VictoryType>(this->tribe_game_options.victoryTypeValue);
}

int TRIBE_Game::victoryAmount() const {
    return this->tribe_game_options.victoryAmountValue;
}

void TRIBE_Game::setVictoryType(TRIBE_Game::VictoryType victory_type_in, int amount_in) {
    this->tribe_game_options.victoryTypeValue = victory_type_in;
    this->tribe_game_options.victoryAmountValue = amount_in;
}

int TRIBE_Game::civilization(int player_num) {
    return this->tribe_game_options.civilizationValue[player_num];
}

void TRIBE_Game::setCivilization(int player_num, int civilization) {
    this->tribe_game_options.civilizationValue[player_num] = static_cast<unsigned char>(civilization);
}

int TRIBE_Game::scenarioPlayer(int player_num) {
    return this->tribe_game_options.scenarioPlayerValue[player_num];
}

void TRIBE_Game::setScenarioPlayer(int player_num, int scenario_player) {
    this->tribe_game_options.scenarioPlayerValue[player_num] = scenario_player;
}

int TRIBE_Game::playerColor(int player_num) {
    return this->tribe_game_options.playerColorValue[player_num];
}

void TRIBE_Game::setPlayerColor(int player_num, int color) {
    this->tribe_game_options.playerColorValue[player_num] = color;
}

int TRIBE_Game::computerName(int player_num) {
    return this->tribe_game_options.computerNameValue[player_num];
}

void TRIBE_Game::setComputerName(int player_num, int val) {
    this->tribe_game_options.computerNameValue[player_num] = val;
}

int TRIBE_Game::allowTrading() {
    return this->tribe_game_options.allowTradingValue;
}

int TRIBE_Game::longCombat() {
    return this->tribe_game_options.longCombatValue;
}

int TRIBE_Game::randomizePositions() {
    return this->tribe_game_options.randomizePositionsValue;
}

int TRIBE_Game::fullTechTree() {
    return this->tribe_game_options.fullTechTreeValue;
}

TRIBE_Game::ResourceLevel TRIBE_Game::resourceLevel() {
    return static_cast<TRIBE_Game::ResourceLevel>(this->tribe_game_options.resourceLevelValue);
}

TRIBE_Game::Age TRIBE_Game::startingAge() {
    return static_cast<TRIBE_Game::Age>(this->tribe_game_options.startingAgeValue);
}

int TRIBE_Game::startingUnits() {
    return this->tribe_game_options.startingUnitsValue;
}

unsigned char TRIBE_Game::deathMatch() {
    return this->tribe_game_options.deathMatchValue;
}

unsigned char TRIBE_Game::popLimit() {
    if (this->multiplayerGame()) {
        return this->tribe_game_options.popLimitValue;
    }
    return 50;
}

unsigned char TRIBE_Game::quickStartGame() {
    return this->quick_start_game;
}

int TRIBE_Game::randomStartValue() {
    return this->random_start_value;
}

void TRIBE_Game::setAllowTrading(int val) {
    this->tribe_game_options.allowTradingValue = static_cast<unsigned char>(val);
}

void TRIBE_Game::setLongCombat(int val) {
    this->tribe_game_options.longCombatValue = static_cast<unsigned char>(val);
}

void TRIBE_Game::setRandomizePositions(int val) {
    this->tribe_game_options.randomizePositionsValue = static_cast<unsigned char>(val);
}

void TRIBE_Game::setFullTechTree(int val) {
    this->tribe_game_options.fullTechTreeValue = static_cast<unsigned char>(val);
}

void TRIBE_Game::setResourceLevel(TRIBE_Game::ResourceLevel val) {
    this->tribe_game_options.resourceLevelValue = val;
}

void TRIBE_Game::setStartingAge(TRIBE_Game::Age val) {
    this->tribe_game_options.startingAgeValue = val;
}

void TRIBE_Game::setStartingUnits(int val) {
    this->tribe_game_options.startingUnitsValue = static_cast<unsigned char>(val);
}

void TRIBE_Game::setDeathMatch(unsigned char val) {
    this->tribe_game_options.deathMatchValue = val;
}

void TRIBE_Game::setPopLimit(unsigned char val) {
    this->tribe_game_options.popLimitValue = val;
}

void TRIBE_Game::setQuickStartGame(unsigned char val) {
    this->quick_start_game = val;
}

void TRIBE_Game::setRandomStartValue(int val) {
    this->random_start_value = val;
}

char* TRIBE_Game::gameSummary() {
    static char temp[1];
    temp[0] = 0;
    return temp;
}

long __stdcall TRIBE_Game::wnd_proc(void* wnd, unsigned int msg, unsigned int wparam, long lparam) {
    if (msg <= 0x200) {
        if (msg != 0x200) {
            if (msg == 7) {
                if (this->input_enabled == 0) {
                    this->disable_input();
                } else {
                    this->enable_input();
                }
            }
        } else {
            if (this->prog_mode == 1) {
                SetCursor(0);
            }
        }
    } else {
        switch (msg) {
        case 0x201:
        case 0x204:
            if (this->prog_mode == 1) {
                this->stop_video(1);
                return 0;
            }
            break;
        }
    }

    return this->RGE_Base_Game::wnd_proc(reinterpret_cast<HWND>(wnd), msg, wparam, lparam);
}

#include <string.h>

extern void color_log(unsigned char first, unsigned char second, int level);

int TRIBE_Game::handle_idle() {
    static int last_wait_time;
    int retval;
    char str[100];
    char msg[2304];

    retval = RGE_Base_Game::handle_idle();
    if (retval == 0) {
        return 0;
    }

    if (this->inHandleIdle != 0) {
        L->Log("Already in handle_idle, wT=%ld.", this->world->world_time);
        return 0;
    }

    this->inHandleIdle = 1;
    color_log(0x4C, 0x4C, 5);
    color_log(0x4C, 0x16, 5);

    if (this->prog_mode == 1 && this->video_window != 0) {
        unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0x1381);
        if (now - this->last_video_time >= 1000) {
            SendMessageA(this->video_window, 0x46A, 100, reinterpret_cast<long>(str));
            if (str[0] == 0 || strcmp(str, "stopped") == 0) {
                this->stop_video(1);
            } else if (this->video_paused == 0 && strcmp(str, "paused") == 0) {
                SendMessageA(this->video_window, 0x855, 0, 0);
            }
            this->last_video_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0x138D);
        }
    } else if (this->prog_mode == 3) {
        if (this->comm_handler->MultiplayerGameStart() != 0) {
            color_log(0x4C, 0x24, 5);
            this->let_game_begin();
        } else {
            color_log(0x4C, 0x54, 5);
            unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0x139C);
            if (now - last_wait_time >= 500) {
                this->get_string(0x454, msg, 0x900);
                strcat(msg, "\n");

                int player;
                for (player = 1; player < 9; ++player) {
                    if (player != this->comm_handler->WhoAmI() && this->comm_handler->IsPlayerHuman(player) != 0) {
                        strcat(msg, "\n");
                        strcat(msg, this->comm_handler->WaitingOnNamedInfo(player));
                    }
                }

                TRIBE_Screen_Wait* wait =
                    static_cast<TRIBE_Screen_Wait*>(panel_system.panel("Multiplayer Wait Screen"));
                if (wait != 0) {
                    wait->set_text(msg);
                }
                last_wait_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0x13AC);
            }
        }
    } else if (this->prog_mode == 4 || this->prog_mode == 6 || this->prog_mode == 5) {
        color_log(0x4C, 0x32, 5);
        if (out_of_sync2 == 0 && this->game_screen != 0) {
            this->game_screen->handle_game_update();
        }
    }

    color_log(0x4C, 0x5F, 5);
    this->inHandleIdle = 0;
    return retval;
}

int TRIBE_Game::handle_query_new_palette(void* wnd, unsigned int msg, unsigned int wparam, long lparam) {
    int result;
    int mode;

    result = 1;
    mode = this->prog_mode;
    if (mode == result) {
        if (this->video_window != 0 && this->video_hi_color == 0) {
            SendMessageA(this->video_window, 0x476, 0, 0);
        }
    } else {
        result = RGE_Base_Game::handle_query_new_palette(wnd, msg, wparam, lparam);
    }

    return result;
}

int TRIBE_Game::handle_activate(void* wnd, unsigned int msg, unsigned int wparam, long lparam) {
    RGE_Base_Game::handle_activate(wnd, msg, wparam, lparam);

    if (this->prog_mode == 1 && this->video_window != 0) {
        if (wparam == 1) {
            if (this->video_paused != 0) {
                SendMessageA(this->video_window, 0x855, 0, 0);
                this->video_paused = 0;
                return 1;
            }
        } else {
            if (this->video_paused == 0) {
                SendMessageA(this->video_window, 0x809, 0, 0);
                this->video_paused = 1;
            }
        }
    }

    return 1;
}

extern "C" int __cdecl sprintf(char*, const char*, ...);

extern int do_debug_random;
extern int out_of_sync;
extern int out_of_sync2;
extern int player_dropped[9];
extern void debug_random_write();
extern void dump_vismap_log();

int TRIBE_Game::action_user_command(unsigned long val1, unsigned long val2) {
    char msg[256];
    char temp_str[260];
    TEasy_Panel* panel;
    int player;

    if (this->prog_mode == 3) {
        switch (val1) {
        case 0x17a8:
        case 0x17a9:
        case 0x17aa:
        case 0x17ab:
        case 0x17b2:
        case 0x17b6:
            this->quit_game();
            panel_system.destroyPanel("Multiplayer Wait Screen");
            panel_system.destroyPanel("Status Screen");
            panel = static_cast<TEasy_Panel*>(panel_system.currentPanel());
            if (panel == 0) {
                break;
            }
            goto dropped_from_game;

        case 0x17ac:
        case 0x17b7:
            this->reset_comm();
            this->setSinglePlayerGame(1);
            this->quit_game();
            panel_system.destroyPanel("Multiplayer Wait Screen");
            panel_system.destroyPanel("Status Screen");
            panel = static_cast<TEasy_Panel*>(panel_system.currentPanel());
            if (panel == 0) {
                break;
            }
        dropped_from_game:
            panel->popupOKDialog(IDS_PLAYER_DROPPED_NOTICE, 0, 0x1c2, 100);
            break;
        }
    } else if (this->prog_mode == 4 || this->prog_mode == 6 || this->prog_mode == 5) {
        switch (val1) {
        case 0x17b2:
            if (this->game_screen == 0) {
                break;
            }
            this->world->players[this->world->curr_player]->loss_if_game_on();
            this->do_game_over();
            panel = static_cast<TEasy_Panel*>(panel_system.currentPanel());
            if (panel != 0) {
                panel->popupOKDialog(IDS_PLAYER_DROPPED_NOTICE, 0, 0x1c2, 100);
            }
            break;

        case 0x17b0:
            if (this->game_screen != 0) {
                this->play_sound(2);
                this->game_screen->display_system_message("Out of sync detected by communications.");
            }
            if (this->check_prog_argument("SKIPSYNCSAVE") == 0) {
                if (out_of_sync == 0) {
                    out_of_sync = 1;
                    if (this->comm_handler->IsHost() != 0) {
                        static_cast<TRIBE_Command*>(this->world->commands)->command_save_game();
                    }
                }
            } else if (out_of_sync == 0) {
                if (this->comm_handler->IsPlayerOutOfSync(this->comm_handler->WhoAmI(), val2) != 0) {
                    out_of_sync = 1;
                    out_of_sync2 = 1;
                    new TRIBE_Screen_Status_Message("Temp Screen", "", 0, -1);
                    panel_system.setCurrentPanel("Temp Screen", 0);
                    this->close_game_screens(1);
                    if (do_debug_random != 0) {
                        debug_random_write();
                        dump_vismap_log();
                    }
                    player = this->comm_handler->WhoAmI();
                    sprintf(msg, "syncerr%d.gam", player);
                    this->save_game(msg);
                    this->world->players[this->world->curr_player]->loss_if_game_on();
                    this->do_game_over();
                    panel = static_cast<TEasy_Panel*>(panel_system.currentPanel());
                    if (panel != 0) {
                        panel->popupOKDialog(0x966, 0, 0x1c2, 100);
                    }
                    panel_system.destroyPanel("Temp Screen");
                }
            }
            break;

        case 0x17a2:
            if (this->game_screen != 0) {
                this->game_screen->handle_pause();
            }
            break;

        case 0x17a3:
            if (this->game_screen != 0) {
                this->game_screen->handle_resume();
            }
            break;

        case CHAT_RECEIVED:
            if (this->game_screen != 0) {
                this->play_sound(2);
                this->game_screen->handleChatReceived(val2);
            }
            break;

        case 0x17bd: {
            player = this->playerID(val2);
            if (player != this->world->curr_player && this->game_screen != 0 && this->playerID(val2) > 0 &&
                player_dropped[val2] == 0) {
                this->play_sound(2);
                this->get_string(0x4c1, temp_str + 4, 0x100);
                player = this->playerID(val2);
                sprintf(msg, temp_str + 4, this->world->players[player]->name);
                this->game_screen->display_system_message(msg);
                player = this->playerID(val2);
                L->Log("$$$ PROBLEM COMMUNICATING WITH %s", this->world->players[player]->name);
            }
            break;
        }
        }
    }

    return 1;
}

int TRIBE_Game::action_key_down(unsigned long key, int repeat_count, int ctrl_key, int alt_key, int shift_key) {
    if (this->prog_mode == 1) {
        switch (key) {
        case 0x0D:
        case 0x20:
            this->stop_video(1);
            return 0;
        case 0x1B:
            this->stop_video(0);
            return 0;
        }
        return 1;
    }

    if (key != 0x70) {
        return 1;
    }
    if (!this->multiplayerGame() ||
        (this->prog_mode != 4 && this->prog_mode != 6 && this->prog_mode != 7 && this->prog_mode != 5)) {
        WinHelpA(this->prog_window, "empires.hlp", 3, 0);
    }
    return 0;
}

int TRIBE_Game::action_close() {
    if (this->comm_handler) {
        this->disconnect_multiplayer_game();
        this->prog_mode = 0;
    }
    return 1;
}

#pragma warning(disable : 4234)

char* TRIBE_Game::game_over_msg() {
    static char msg[256];
    RGE_Game_World* world = this->world;
    RGE_Player* player = world->players[world->curr_player];
    if (player->game_status == 1) {
        this->get_string(0x47E, msg, 0x100);
        return msg;
    }
    this->get_string(0x47F, msg, 0x100);
    return msg;
}

long TRIBE_Game::get_achievement_info(unsigned char achievement, char** info) {
    if (!this->world)
        return 0;
    return static_cast<TRIBE_World*>(this->world)->get_achievement(achievement, info);
}

extern "C" int atoi(const char*);
extern int debug_rand(char* file, int line);

int TRIBE_Game::randomComputerName(int civ) {
    char scount[10];
    int max;
    int slot;
    int i;
    int tries;

    this->get_string((civ + 0x1B7) * 10, scount, 10);
    max = atoi(scount);

    tries = 0;

    do {
        int r = debug_rand("C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0x1521);
        slot = r % max;
        if (slot > max - 1)
            slot = max - 1;
        if (this->computerNameUsed[civ][slot] == 0)
            break;
        tries++;
    } while (tries < 20);

    if (this->computerNameUsed[civ][slot] == 1) {
        for (i = 0; i < 10; i++) {
            if (this->computerNameUsed[civ][i] == 0) {
                slot = i;
                break;
            }
        }
    }

    this->computerNameUsed[civ][slot] = 1;
    return slot + civ * 10 - 9;
}

void TRIBE_Game::resetRandomComputerName() {
    int i;

    for (i = 0; i < 16; ++i) {
        memset(this->computerNameUsed[i], 0, sizeof(this->computerNameUsed[i]));
    }
}

extern "C" __declspec(dllimport) void* __stdcall SetCursor(void* cursor);

long TRIBE_Game::video_wnd_proc(void* hwnd, unsigned int msg, unsigned int wParam, long lParam) {
    switch (msg) {
    case 0x200:
        SetCursor(0);
        return 0;
    case 0x201:
    case 0x204:
        this->stop_video(1);
        return 0;
    }

    return CallWindowProcA(reinterpret_cast<FARPROC>(this->old_video_wnd_proc), reinterpret_cast<HWND>(hwnd), msg,
                           wParam, lParam);
}

void TRIBE_Game::SetClickTables(MouseClickInfo* RC, int RCS, MouseClickInfo* LC, int LCS) {
    this->MouseRightClickTable = RC;
    this->MouseRightClickTableSize = RCS;
    this->MouseLeftClickTable = LC;
    this->MouseLeftClickTableSize = LCS;
}

void TRIBE_Game::set_interface_messages() {
    if (this->prog_info->interface_style == 1) {
        this->SetClickTables(Tribe1btnMouseRightClickTable, Tribe1btnMouseRightClickTableSize,
                             Tribe1btnMouseLeftClickTable, Tribe1btnMouseLeftClickTableSize);
        return;
    }
    this->SetClickTables(Tribe2btnMouseRightClickTable, Tribe2btnMouseRightClickTableSize, Tribe2btnMouseLeftClickTable,
                         Tribe2btnMouseLeftClickTableSize);
}

int TRIBE_Game::setup_video_system() {
    if (this->video_setup != 0) {
        return 1;
    }

    panel_system.setCurrentPanel("Blank Screen", 0);
    this->mouse_off();

    this->video_double_size = 1;
    this->video_changed_res = 0;
    this->video_hi_color = 0;
    this->video_save_palette = this->draw_system->Pal;

    if (this->draw_system->ScreenMode == 2) {
        SetCursor(0);
        SetClassLongA(this->prog_window, -12, 0);
        this->mouse_pointer->Shutdown_Mouse();

        this->video_save_res_wid = this->draw_system->ScreenWidth;
        this->video_save_res_hgt = this->draw_system->ScreenHeight;
        if (this->check_prog_argument("8BITVIDEO") == 0) {
            if (this->draw_system->IsModeAvail(0x280, 0x1E0, 0x10) != 0) {
                L->Log("640x480 16bit");
                this->video_changed_res = this->draw_system->SetDisplaySize(0x280, 0x1E0, 0x10);
                if (this->video_changed_res != 0) {
                    this->video_double_size = 1;
                    this->video_hi_color = 1;
                    L->Log("640x480 16bit success");
                }
            }

            if (this->video_changed_res == 0 && this->draw_system->ScreenWidth != 0x280) {
                if (this->draw_system->IsModeAvail(0x280, 0x1E0, 8) != 0) {
                    L->Log("640x480 8bit");
                    this->video_changed_res = this->draw_system->SetDisplaySize(0x280, 0x1E0, 8);
                    if (this->video_changed_res != 0) {
                        this->video_double_size = 1;
                        L->Log("640x480 8bit success");
                    }
                }
            }
        }
    }

    L->Log("video_changed_res=%d, double_size=%d", this->video_changed_res, this->video_double_size);
    this->set_prog_mode(1);
    this->stop_sound_system();
    this->video_setup = 1;
    return 1;
}

extern "C" int restore_mouse_after_paint; // 62C55Ch

void TRIBE_Game::shutdown_video_system() {
    if (video_setup == 0)
        return;

    if (video_changed_res) {
        draw_system->SetDisplaySize(video_save_res_wid, video_save_res_hgt, 8);
        draw_system->ClearPrimarySurface();
        draw_system->SetPalette(video_save_palette);
        video_changed_res = 0;
        draw_system->CheckSurfaces();
        draw_system->ClearRestored();
        check_paint();
        restore_mouse_after_paint = 1;
    }

    draw_system->ClearPrimarySurface();
    draw_system->SetPalette(video_save_palette);
    set_render_all();

    InvalidateRect(this->prog_window, 0, 1);

    set_prog_mode(2);
    restart_sound_system();

    void* cursor = LoadCursorA(0, MAKEINTRESOURCEA(0x7F00));
    set_mouse_cursor(cursor);
    mouse_on();

    video_setup = 0;
}

void TRIBE_Game::disconnect_multiplayer_game() {
    if (this->multiplayerGame() == 0) {
        this->comm_handler->GameOver();
        return;
    }

    if (this->prog_mode != 4 && this->prog_mode != 6 && this->prog_mode != 7 && this->prog_mode != 5) {
        return;
    }

    this->comm_handler->SendIResignMsg();
    this->comm_handler->ShutdownGameMessages();

    if (this->comm_handler->CountWaitingMessages() > 0) {
        this->disable_input();
        this->show_status_message(0x4C0, 0, -1);

        unsigned long start_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0x15F8);
        unsigned long last_time = start_time;

        while (this->world != 0 && this->world->game_state != 1) {
            this->comm_handler->ShutdownGameMessages();
            if (debug_timeGetTime("C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0x1601) - last_time < 500) {
                continue;
            }

            if (this->comm_handler->CountWaitingMessages() == 0) {
                break;
            }

            last_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0x1605);
            if (last_time - start_time >= 15000) {
                break;
            }
        }
    }

    this->comm_handler->GameOver();
    this->comm_handler->UnlinkToLevel(SERVICE_AVAILABLE);
}

void TRIBE_Game::add_notification_loc(long x, long y) {
    long current;
    current = this->current_notification_loc;
    if (current < 0 || this->notification_loc_x[current] != x || this->notification_loc_y[current] != y) {
        this->current_notification_loc = current + 1;
        if (this->current_notification_loc >= 5) {
            this->current_notification_loc = 0;
        }
        this->notification_loc_x[this->current_notification_loc] = x;
        this->notification_loc_y[this->current_notification_loc] = y;
    }
    this->current_notification_recalled = this->current_notification_loc;
}

void TRIBE_Game::goto_notification_loc() {
    if (this->current_notification_recalled == -1)
        return;

    long x = this->notification_loc_x[this->current_notification_recalled];
    long y = this->notification_loc_y[this->current_notification_recalled];

    this->current_notification_recalled--;

    if (this->current_notification_recalled < 0)
        this->current_notification_recalled = 4;

    if (this->notification_loc_x[this->current_notification_recalled] == -1 ||
        this->notification_loc_y[this->current_notification_recalled] == -1) {
        this->current_notification_recalled = this->current_notification_loc;
    }

    this->get_player()->set_view_loc(static_cast<float>(x), static_cast<float>(y));
}
