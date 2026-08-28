#include "../third_party/directplay/include/dplay.h"
#include "../include/tribegam.h"
#include "../include/main.h"
#include "../include/game_globals.h"
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
#include "../include/scr_mps_types.h"
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
#include "../include/com_hand.h"
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

// PDB source order for C:\\msdev\\work\\age1_x1\\tribegam.cpp.

// The module keeps the recovered period source in original PDB order.

// PDB lines 160-191; VA 00520FC0 encrypt_codes.

extern const int encrypt_table[];

void encrypt_codes(char* src, char* dst, int max_len) {
    char c = *src;
    char* out = dst;
    int count = 0;
    char* p = src + 1;

    while (c != 0 && count < max_len) {
        if (c < 'A' || c > '_') {
            *out = c;
            out++;
            count++;
        } else {
            int val = encrypt_table[static_cast<int>(c)];
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

// PDB lines 199-224; VA 00521020 run_log.

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

extern int do_run_log;         // 0x62C4F4
extern int run_log_created;    // 0x86BDFC
extern _iobuf* run_log_file;   // 0x86BDF8

void __cdecl run_log(char* param_1, int param_2)
{
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

    if (param_2) {
        long timestamp = param_2;
        time(&timestamp);
        char stime[26];
        memset(stime, 0, sizeof(stime));
        strncpy(stime, ctime(&timestamp), 0x18);
        fprintf(run_log_file, "%s - %s\n", stime, param_1);
    } else {
        fprintf(run_log_file, "%s\n", param_1);
    }

    fclose(run_log_file);
}

// PDB lines 230-232; VA 00523AE0 video_sub_wnd_proc.

static long __stdcall video_sub_wnd_proc(void* hwnd, unsigned int msg,
                                         unsigned int wparam, long lparam) {
    return static_cast<TRIBE_Game*>(rge_base_game)->video_wnd_proc(
        hwnd, msg, wparam, lparam);
}

// PDB lines 256-342; VA 00521120 TRIBE_Game::TRIBE_Game.

extern void* StringTableX;
extern int disable_terrain_sounds;
extern int out_of_sync;
extern int out_of_sync2;
extern int player_dropped[9];
extern int video_codec_available;
extern void __cdecl debug_srand(char* file, int line, unsigned int seed);
extern MouseClickInfo Tribe1btnMouseRightClickTable[40];
extern MouseClickInfo Tribe1btnMouseLeftClickTable[40];
extern int Tribe1btnMouseRightClickTableSize;
extern int Tribe1btnMouseLeftClickTableSize;
extern MouseClickInfo Tribe2btnMouseRightClickTable[40];
extern MouseClickInfo Tribe2btnMouseLeftClickTable[40];
extern int Tribe2btnMouseRightClickTableSize;
extern int Tribe2btnMouseLeftClickTableSize;

// The VC5 SDK headers do not publish this Video for Windows record.
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

extern "C" int __stdcall ICInfo(unsigned long fccType,
                                  unsigned long fccHandler, ICINFO* info);

TRIBE_Game::TRIBE_Game(RGE_Prog_Info* prog_info, int setup_game)
    : RGE_Base_Game(prog_info, 0),
      video_window(0),
      cur_video(-1),
      old_video_wnd_proc(0),
      video_paused(0),
      last_video_time(0),
      video_setup(0),
      video_double_size(0),
      video_changed_res(0),
      video_hi_color(0),
      video_save_res_wid(0),
      video_save_res_hgt(0),
      video_save_palette(0),
      started_menu_music(0),
      show_object_id(0),
      game_screen(0),
      inHandleIdle(0)
{
    int i;
    int player;
    int civilization;

    this->is_mouse_on = 1;
    this->windows_mouse = 0;
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

    civilization = 1;
    for (player = 0; player < 9; ++player) {
        this->setCivilization(player, civilization);
        ++civilization;
        if (civilization > 16) {
            civilization = 1;
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

    if (setup_game != 0) {
        if (this->setup() == 0 && this->error_code == 0) {
            this->error_code = 1;
        }
    }
}

// PDB lines 347-413; VA 005213A0 TRIBE_Game::~TRIBE_Game.

extern void* StringTableX;
extern void __cdecl RESFILE_close_new_resource_file(const char* name);

TRIBE_Game::~TRIBE_Game()
{
    this->inHandleIdle = 0;
    this->prog_mode = 0;

    if (this->windows_mouse != 0) {
        DestroyWindow(reinterpret_cast<HWND>(this->windows_mouse));
        this->windows_mouse = 0;
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

// PDB lines 419-447; VA 00521620 TRIBE_Game::close_game_screens.

void TRIBE_Game::close_game_screens(int destroyGameScreen)
{
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

    if (destroyGameScreen != 0) {
        this->game_screen = 0;
        panel_system.destroyPanel("Game Screen");
    }
}

// PDB lines 453-685; VA 00521790 TRIBE_Game::setup.

#include <string.h>
#include <windows.h>
extern char* __pgmptr;

int TRIBE_Game::setup()
{
    HANDLE h;
    int cmd;

    if (this->error_code)
        return 0;

    if (strstr(this->prog_info->cmd_line, "makeres") != 0 ||
        strstr(this->prog_info->cmd_line, "Makeres") != 0 ||
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

    if (this->RGE_Base_Game::setup() == 0)
        return 0;

    WIN32_FIND_DATAA file_data;
    char cmd_line[256];
    char str[0x400];
    ICINFO ici;
    strncpy(&cmd_line[4], this->prog_info->cmd_line, 0xFF);
    str[3] = 0;
    CharUpperA(&cmd_line[4]);

    unsigned char* p = _mbsstr(reinterpret_cast<unsigned char*>(&cmd_line[4]),
                               reinterpret_cast<const unsigned char*>("STRING="));
    char new_string_dll_name[100] = "languagex.dll";
    if (p != 0) {
        while (*p != '=') {
            p = _mbsninc(p, 1);
        }
        p = _mbsninc(p, 1);
        while (!_ismbcspace(static_cast<unsigned char>(*p)) && *p) {
            _mbsncat(reinterpret_cast<unsigned char*>(new_string_dll_name), p, 1);
            p = _mbsninc(p, 1);
        }
    }
    StringTableX = LoadLibraryA(new_string_dll_name);
    if (!StringTableX) {
        this->error_code = 1;
        return 0;
    }

    PALETTEENTRY pal_entries[7] = {
        {0x17, 0x27, 0x7C, 0x00},
        {0x27, 0x3F, 0x90, 0x00},
        {0x3F, 0x5F, 0x9F, 0x00},
        {0x57, 0x7B, 0xB4, 0x00},
        {0x3F, 0x5F, 0xA0, 0x00},
        {0x27, 0x3F, 0x91, 0x00},
        {0x17, 0x27, 0x7B, 0x00}
    };
    SetPaletteEntries(this->prog_palette, 0xF8, 7, pal_entries);

    this->input_disabled_window = CreateWindowExA(0, "STATIC", "InputDisabledWindow", 0x40000000,
                                       0, 0, 1, 1, this->prog_window, 0,
                                       this->prog_info->instance, 0);

    video_codec_available = ICInfo(0x63646976, 0x31347669, &ici);

    int setup_mp = 0;
    if (this->check_prog_argument("LOBBY") != 0) {
        new TRIBE_Screen_Status_Message("Status Screen", 0x4BF, "scr1", 0xC383);
        panel_system.setCurrentPanel("Status Screen", 0);
        cmd = this->comm_handler->LaunchLobbyGame();
        if (cmd == 1) {
            this->setMultiplayerGame(1);
            TribeMPSetupScreen* mp = new TribeMPSetupScreen;
            if (!mp || mp->error_code)
                return 0;
            setup_mp = 1;
        } else if (cmd == -1) {
            TRIBE_Screen_Main_Error* err = new TRIBE_Screen_Main_Error;
            if (!err || err->error_code)
                return 0;
            err->set_text(0x96A);
            panel_system.setCurrentPanel("Main Error Screen", 0);
            panel_system.destroyPanel("Status Screen");
        } else {
            this->close();
            return 1;
        }
    } else {
        cmd = this->comm_handler->LaunchLobbyGame();
        if (cmd == 1) {
            this->setMultiplayerGame(1);
            new TribeMPSetupScreen;
            setup_mp = 1;
        } else if (!this->startup_scenario[0]) {
            if (!this->startup_game[0]) {
                if (!this->prog_info->skip_startup) {
                    this->start_video(0, "logo1");
                } else {
                    cmd = this->start_menu();
                    if (cmd == 0)
                        return 0;
                }
            } else {
                cmd = this->load_game(this->startup_game);
                if (cmd == 0) {
                    cmd = this->start_menu();
                    if (cmd == 0)
                        return 0;
                    TEasy_Panel* q = static_cast<TEasy_Panel*>(
                        panel_system.panel("Main Menu"));
                    if (q)
                        q->popupOKDialog(0x961, 0, 0x1C2, 0x64);
                }
            }
        } else {
            cmd = this->start_scenario(this->startup_scenario);
            if (cmd == 0) {
                cmd = this->start_menu();
                if (cmd == 0)
                    return 0;
                TEasy_Panel* q = static_cast<TEasy_Panel*>(
                    panel_system.panel("Main Menu"));
                if (q)
                    q->popupOKDialog(0x961, 0, 0x1C2, 0x64);
            }
        }
    }

    if (setup_mp) {
        panel_system.setCurrentPanel("MP Setup Screen", 0);
        panel_system.destroyPanel("Status Screen");
    }

    this->set_interface_messages();

    run_log("------------------------------", 0);
    run_log("", 1);

    h = FindFirstFileA(__pgmptr, &file_data);
    if (h != INVALID_HANDLE_VALUE) {
        SYSTEMTIME st;
        memset(&st, 0, sizeof(st));
        FileTimeToSystemTime(&file_data.ftLastWriteTime, &st);
        sprintf(&str[4], "program=%s, size=%d, date=%d/%d/%d, time=%d:%d:%d",
                __pgmptr, file_data.nFileSizeLow,
                st.wMonth, st.wMonth, st.wYear, st.wHour, st.wMinute, st.wSecond);
        run_log(&str[4], 0);
        FindClose(h);
    }

    h = FindFirstFileA(this->prog_info->game_data_file, &file_data);
    if (h != INVALID_HANDLE_VALUE) {
        SYSTEMTIME st;
        memset(&st, 0, sizeof(st));
        FileTimeToSystemTime(&file_data.ftLastWriteTime, &st);
        sprintf(&str[4], "data=%s, size=%d, date=%d/%d/%d, time=%d:%d:%d",
                this->prog_info->game_data_file, file_data.nFileSizeLow,
                st.wMonth, st.wMonth, st.wYear, st.wHour, st.wMinute, st.wSecond);
        run_log(&str[4], 0);
        FindClose(h);
    }

    sprintf(&str[4], "options=%s", this->prog_info->cmd_line);
    run_log(&str[4], 0);

    return 1;
}

// PDB lines 691-797; VA 00521FA0 TRIBE_Game::setup_cmd_options.

// BINARY NOTE: The oracle loads [p+1], then increments p in each scan body.

#include <string.h>

extern "C" {
    __declspec(dllimport) char* __stdcall CharUpperA(char* string);
    char* __cdecl strncpy(char* destination, const char* source,
                          unsigned int count);
    long __cdecl atol(const char* string);
    char* __cdecl strstr(const char* string, const char* substring);
    char* __cdecl strchr(const char* string, int character);
}

void encrypt_codes(char* source, char* destination, int limit);

extern int disable_terrain_sounds;
extern int quick_start_game_mode;

int TRIBE_Game::setup_cmd_options()
{
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

// PDB lines 803-822; VA 00522200 TRIBE_Game::setup_palette.

#include <windows.h>

int TRIBE_Game::setup_palette() {
    if (!RGE_Base_Game::setup_palette()) {
        return 0;
    }

    {
        PALETTEENTRY pal_entries[7] = {
            { 0x17, 0x27, 0x7C, 0x00 },
            { 0x27, 0x3F, 0x90, 0x00 },
            { 0x3F, 0x5F, 0x9F, 0x00 },
            { 0x57, 0x7B, 0xB4, 0x00 },
            { 0x3F, 0x5F, 0xA0, 0x00 },
            { 0x27, 0x3F, 0x91, 0x00 },
            { 0x17, 0x27, 0x7B, 0x00 }
        };

        SetPaletteEntries(prog_palette, 0xF8, 7, pal_entries);
    }
    return 1;
}

// PDB lines 828-866; VA 005222C0 TRIBE_Game::setup_sounds.

extern "C" void* __cdecl calloc(unsigned int num, unsigned int size);
extern void* operator new(unsigned int size);

int TRIBE_Game::setup_sounds()
{
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

// PDB lines 872-874; VA 00522770 TRIBE_Game::create_world.

#include "../include/game_globals.h"
#include "../include/game_types.h"

RGE_Game_World* TRIBE_Game::create_world() {
    return new TRIBE_World;
}

// PDB lines 880-892; VA 005227D0 TRIBE_Game::set_game_mode.

void TRIBE_Game::set_game_mode(int a, int b) {
    int old_mode = this->game_mode;
    this->RGE_Base_Game::set_game_mode(a, b);
    if (this->game_screen != 0) {
        this->game_screen->game_mode_changed(old_mode, this->game_mode);
    }
}

// PDB lines 898-913; VA 00522810 TRIBE_Game::set_player.

#include "../include/game_globals.h"

void TRIBE_Game::set_player(short player) {
    short oldPlayer;
    if (this->world) {
        oldPlayer = this->world->curr_player;
    } else {
        oldPlayer = 0;
    }

    RGE_Base_Game::set_player(player);

    if (this->world && this->game_screen) {
        this->game_screen->player_changed(oldPlayer, this->world->curr_player);
    }
}

// PDB lines 919-924; VA 00522860 TRIBE_Game::set_save_game_name.

extern "C" char* strcpy(char* dst, const char* src);

void TRIBE_Game::set_save_game_name(char* text) {
    if (text != 0) {
        strcpy(this->save_game_name, text);
    } else {
        this->save_game_name[0] = 0;
    }
}

// PDB lines 930-935; VA 005228A0 TRIBE_Game::set_load_game_name.

#include <string.h>

void TRIBE_Game::set_load_game_name(char* param_1) {
    if (param_1 != 0) {
        strcpy(this->load_game_name, param_1);
        return;
    }

    this->load_game_name[0] = 0;
}

// PDB lines 942-951; VA 005228E0 TRIBE_Game::get_string.

#include <windows.h>

extern void* StringTableX;

char* TRIBE_Game::get_string(long string_id, char* buffer, int buffer_size) {
    if (LoadStringA(StringTableX, static_cast<int>(string_id), buffer,
                    buffer_size) == 0) {
        return this->RGE_Base_Game::get_string(string_id, buffer, buffer_size);
    }
    buffer[buffer_size - 1] = '\0';
    return buffer;
}

// PDB lines 957-1118; VA 00522930 TRIBE_Game::get_string2.

char* TRIBE_Game::get_string2(int param_1, long param_2, long param_3, char* param_4, int param_5)
{
    *param_4 = 0;

    switch (param_1) {
    case 100:
        switch (param_2) {
        case 0: case 0x0F: case 0x10: case 0x11:
            return this->get_string(0x10CD, param_4, param_5);
        case 1:
            return this->get_string(0x10CE, param_4, param_5);
        case 2:
            return this->get_string(0x10CF, param_4, param_5);
        case 3:
            return this->get_string(0x10D0, param_4, param_5);
        case 9:
            return this->get_string(0x10DB, param_4, param_5);
        }
        break;
    case 101:
        switch (param_2) {
        case 1:
            return this->get_string(0x1069, param_4, param_5);
        case 2:
            return this->get_string(0x106A, param_4, param_5);
        case 3:
            return this->get_string(0x106B, param_4, param_5);
        case 4:
            return this->get_string(0x106C, param_4, param_5);
        }
        break;
    case 105:
        switch (param_2) {
        case 1:
            this->get_string(0x27F7, param_4, param_5);
            break;
        case 2:
            this->get_string(0x27F8, param_4, param_5);
            break;
        case 3:
            this->get_string(0x27F9, param_4, param_5);
            break;
        case 4:
            this->get_string(0x27FA, param_4, param_5);
            break;
        case 5:
            this->get_string(0x27FB, param_4, param_5);
            break;
        case 6:
            this->get_string(0x27FC, param_4, param_5);
            break;
        case 7:
            this->get_string(0x27FD, param_4, param_5);
            break;
        case 8:
            this->get_string(0x27FE, param_4, param_5);
            break;
        case 9:
            this->get_string(0x27FF, param_4, param_5);
            break;
        case 10:
            this->get_string(0x2800, param_4, param_5);
            break;
        case 11:
            this->get_string(0x2801, param_4, param_5);
            break;
        case 12:
            this->get_string(0x2802, param_4, param_5);
            break;
        case 13:
            this->get_string(0x2806, param_4, param_5);
            break;
        case 14:
            this->get_string(0x2807, param_4, param_5);
            break;
        case 15:
            this->get_string(0x2809, param_4, param_5);
            break;
        case 16:
            this->get_string(0x2808, param_4, param_5);
            break;
        default:
            this->get_string(0x2804, param_4, param_5);
            break;
        }
        break;
    case 102:
        switch (param_2) {
        case 1:
            return this->get_string(0x1005, param_4, param_5);
        case 2:
            return this->get_string(0x1006, param_4, param_5);
        case 3:
            return this->get_string(0x1007, param_4, param_5);
        case 4:
            return this->get_string(0x1008, param_4, param_5);
        case 5:
            return this->get_string(0x1009, param_4, param_5);
        case 6:
            return this->get_string(0x100A, param_4, param_5);
        case 7:
            return this->get_string(0x100B, param_4, param_5);
        case 8:
            return this->get_string(0x100C, param_4, param_5);
        case 9:
            return this->get_string(0x100D, param_4, param_5);
        case 10:
            return this->get_string(0x100E, param_4, param_5);
        case 11:
            return this->get_string(0x100F, param_4, param_5);
        case 12:
            return this->get_string(0x1010, param_4, param_5);
        case 13:
            return this->get_string(0x1011, param_4, param_5);
        case 14:
            return this->get_string(0x1012, param_4, param_5);
        case 15:
            return this->get_string(0x1013, param_4, param_5);
        case 16:
            return this->get_string(0x1014, param_4, param_5);
        case 17:
            return this->get_string(0x1015, param_4, param_5);
        case 18:
            return this->get_string(0x1016, param_4, param_5);
        case 19:
            return this->get_string(0x1017, param_4, param_5);
        case 20:
            return this->get_string(0x1018, param_4, param_5);
        case 21:
            return this->get_string(0x1019, param_4, param_5);
        case 22:
            return this->get_string(0x101A, param_4, param_5);
        case 23:
            return this->get_string(0x101B, param_4, param_5);
        case 0x1C:
            return this->get_string(0x101C, param_4, param_5);
        case 0x1D:
            return this->get_string(0x101D, param_4, param_5);
        case 0x1E:
            return this->get_string(0x101E, param_4, param_5);
        case 0x1F:
            return this->get_string(0x101F, param_4, param_5);
        case 0x19:
            return this->get_string(0x1020, param_4, param_5);
        case 0x1A:
            return this->get_string(0x1021, param_4, param_5);
        case 0x1B:
            return this->get_string(0x1022, param_4, param_5);
        case 0x20:
            return this->get_string(0x1025, param_4, param_5);
        case 0x21:
            return this->get_string(0x1026, param_4, param_5);
        }
        break;
    case 1:
        switch (param_2) {
        case 0x64: case 0x65: case 0x66:
            return this->get_string(0x961, param_4, param_5);
        case 0x67:
            return this->get_string(0x962, param_4, param_5);
        case 0x68:
            return this->get_string(0x963, param_4, param_5);
        case 0x69:
            return this->get_string(0x964, param_4, param_5);
        case 0x6A:
            return this->get_string(0x965, param_4, param_5);
        default:
            return RGE_Base_Game::get_string2(param_1, param_2, param_3, param_4, param_5);
        }
    case 103:
        switch (param_2) {
        case 1:
            switch (param_3) {
            case 4:
                return this->get_string(0xBBD, param_4, param_5);
            case 0:
                return this->get_string(0xBB9, param_4, param_5);
            case 1:
                return this->get_string(0xBBA, param_4, param_5);
            case 2:
                return this->get_string(0xBBB, param_4, param_5);
            case 3:
                return this->get_string(0xBBC, param_4, param_5);
            case 0x20:
                return this->get_string(0xBE6, param_4, param_5);
            }
            break;
        case 0x68:
            return this->get_string(0xBC1, param_4, param_5);
        case 1000:
            return this->get_string(0xBC2, param_4, param_5);
        case 0x65:
            return this->get_string(0xBBE, param_4, param_5);
        case 0x66:
            return this->get_string(0xBBF, param_4, param_5);
        case 0x67:
            return this->get_string(0xBC0, param_4, param_5);
        case 0x69:
            return this->get_string(0xBC3, param_4, param_5);
        case 0x6A:
            return this->get_string(0xBCA, param_4, param_5);
        }
        break;
    case 104:
        switch (param_2) {
        case 2:
            return this->get_string(0x10D1, param_4, param_5);
        case 3:
            return this->get_string(0x10D2, param_4, param_5);
        case 4:
            return this->get_string(0x10D3, param_4, param_5);
        case 1:
            return this->get_string(0x10D4, param_4, param_5);
        case 5:
            return this->get_string(0x10D5, param_4, param_5);
        case 6:
            return this->get_string(0x10D6, param_4, param_5);
        case 7:
            return this->get_string(0x10D7, param_4, param_5);
        case 8:
            return this->get_string(0x10D8, param_4, param_5);
        case 9:
            return this->get_string(0x10D9, param_4, param_5);
        case 10:
            return this->get_string(0x10DA, param_4, param_5);
        case 11:
            return this->get_string(0x10DC, param_4, param_5);
        }
        break;
    default:
        return RGE_Base_Game::get_string2(param_1, param_2, param_3, param_4, param_5);
    }

    param_4[param_5 - 1] = 0;
    return param_4;
}

// PDB lines 1124-1139; VA 00523450 TRIBE_Game::get_view_panel.

TPanel* TRIBE_Game::get_view_panel()
{
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

// PDB lines 1145-1160; VA 005234A0 TRIBE_Game::get_map_panel.

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

// PDB lines 1166-1168; VA 005234F0 TRIBE_Game::get_save_game_name.

char * TRIBE_Game::get_save_game_name() { return this->save_game_name; }

// PDB lines 1174-1176; VA 00523500 TRIBE_Game::get_load_game_name.

char * TRIBE_Game::get_load_game_name() { return this->load_game_name; }

// PDB lines 1182-1184; VA 00523510 TRIBE_Game::new_scenario_header.

RGE_Scenario_Header* TRIBE_Game::new_scenario_header(int param_1) {
    return new TRIBE_Scenario_Header(param_1);
}

// PDB lines 1190-1192; VA 00523570 TRIBE_Game::new_scenario_header.

#include "../include/game_types.h"

RGE_Scenario_Header* TRIBE_Game::new_scenario_header(RGE_Scenario* param_1) {
    return new TRIBE_Scenario_Header(static_cast<T_Scenario*>(param_1));
}

// PDB lines 1198-1200; VA 005235D0 TRIBE_Game::new_scenario_info.

RGE_Scenario* TRIBE_Game::new_scenario_info(int param_1) {
    return new T_Scenario(param_1, 0);
}

// PDB lines 1206-1211; VA 00523640 TRIBE_Game::show_error_message.

extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void* hWnd, const char* lpText, const char* lpCaption, unsigned int uType);

void TRIBE_Game::show_error_message(int param_1) {
    char title[256];
    char msg[256];
    this->get_string(0xFA8, title, 256);
    this->get_string2(1, param_1, 0, msg, 256);
    MessageBoxA(this->prog_window, msg, title, 0x10);
}

// PDB lines 1216-1230; VA 005236A0 TRIBE_Game::show_status_message.

static char status_screen[] = "Status Screen";

void TRIBE_Game::show_status_message(char* s1, char* s2, long p3) {
    TRIBE_Screen_Status_Message* panel;
    panel = static_cast<TRIBE_Screen_Status_Message*>(
        panel_system.panel(status_screen));
    if (panel) {
        panel->set_text(s1);
        this->draw_window();
    } else {
        panel = new TRIBE_Screen_Status_Message(status_screen, s1, s2, p3);
    }
    panel_system.setCurrentPanel(status_screen, 0);
}

// PDB lines 1235-1239; VA 00523750 TRIBE_Game::show_status_message.

void TRIBE_Game::show_status_message(int string_id, char* param_2, long param_3) {
    char str[0x100];
    this->get_string(string_id, str, 0x100);
    this->show_status_message(str, param_2, param_3);
}

// PDB lines 1244-1249; VA 005237A0 TRIBE_Game::close_status_message.

void TRIBE_Game::close_status_message() {
    panel_system.restorePreviousPanel(1);
}

// PDB lines 1255-1443; VA 005237B0 TRIBE_Game::start_video.

#include <stdio.h>
#include <string.h>
#include <windows.h>

extern "C" int __cdecl __open(const char* path, int flags, ...);
extern "C" void* __cdecl MCIWndCreateA(void* parent, void* instance,
                                         unsigned long style,
                                         const char* file);
static long __stdcall video_sub_wnd_proc(
    void* hwnd, unsigned int message, unsigned int wparam, long lparam);

int TRIBE_Game::start_video(int video, char* file)
{
    if (this->video_window != 0) {
        char str[100];
        SendMessageA(this->video_window, 0x46A, 100,
                     reinterpret_cast<long>(str));
        if (str[0] != 0 && strcmp(str, "stopped") != 0) {
            SendMessageA(this->video_window, 0x808, 0, 0);
        }
        SendMessageA(this->video_window, 0x10, 0, 0);
        this->video_window = 0;
    }

    this->cur_video = video;
    if (this->rge_game_options.multiplayerGameValue != 1 &&
        file != 0 && *file != 0) {
        char temp_name[260];
        sprintf(temp_name, "%s%s.avi", this->prog_info->avi_dir, file);
        int file_handle = __open(temp_name, 0, 0x100);
        if (file_handle == -1) {
            char* cd_path = this->registry->RegGetAscii(0, "CDPath");
            if (cd_path != 0) {
                sprintf(temp_name, "%sgame\\avi\\%s.avi", cd_path,
                        file);
                file_handle = __open(temp_name, 0, 0x100);
            }
            if (file_handle == -1) {
                this->stop_video(1);
                return 0;
            }
        }

        if (video_codec_available != 0 &&
            (this->video_setup != 0 || this->setup_video_system() != 0)) {
            this->video_window = MCIWndCreateA(
                this->prog_window, this->prog_info->instance, 0x50001F0A,
                temp_name);
            if (this->video_window != 0) {
                RECT video_rect;
                this->old_video_wnd_proc = reinterpret_cast<int (__stdcall *)()>(
                    GetWindowLongA(
                        this->video_window, -4));
                SetWindowLongA(this->video_window, -4,
                               reinterpret_cast<long>(::video_sub_wnd_proc));

                if (this->video_hi_color == 0) {
                    void* palette = reinterpret_cast<void*>(SendMessageA(
                        this->video_window, 0x47E, 0, 0));
                    this->draw_system->SetPalette(palette);
                }

                GetClientRect(this->video_window, &video_rect);
                if (this->video_double_size != 0) {
                    video_rect.right = video_rect.right * 2;
                    video_rect.bottom = video_rect.bottom * 2;
                }

                MoveWindow(
                    this->video_window,
                    this->prog_info->main_wid / 2 - video_rect.right / 2,
                    this->prog_info->main_hgt / 2 - video_rect.bottom / 2,
                    video_rect.right, video_rect.bottom, 0);
                this->set_render_all();
                InvalidateRect(this->prog_window, 0, 1);
                SendMessageA(this->prog_window, 0x0F, 0, 0);
                this->draw_system->ClearPrimarySurface();
                this->video_paused = 0;
                this->last_video_time = debug_timeGetTime(
                    "C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0x598);
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

// PDB lines 1449-1555; VA 00523B10 TRIBE_Game::stop_video.

#include <new.h>
#include <string.h>
#include <windows.h>

typedef long (__stdcall *SendMessageFn)(
    void* hwnd, unsigned int message, unsigned int wparam, long lparam);

void TRIBE_Game::stop_video(unsigned char do_stop)
{
    int save_vid_num;
    char str[100];
    int show_menu_after_video = 0;

    save_vid_num = this->cur_video;
    this->cur_video = -1;

    if (this->video_window != 0) {
        SendMessageFn send_message = SendMessageA;

        send_message(this->video_window, 0x46A, 100,
                     reinterpret_cast<long>(str));
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
        if (do_stop != 0) {
            this->start_video(1, "logo2");
            return;
        }
        show_menu_after_video = 1;
        break;

    case 1:
        if (do_stop != 0) {
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
            if (description != 0 && description[0] != 0 &&
                this->multiplayerGame() == 0 &&
                (this->randomGame() == 0 || this->campaignGame() != 0)) {
                TRIBE_Mission_Screen* screen =
                    new TRIBE_Mission_Screen(description, 0,
                                              this->world->scenario->mission_picture);
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

            TribeAchievementsScreen* screen =
                new TribeAchievementsScreen(this->game_over_msg(), 1);
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

// PDB lines 1560-1596; VA 00523F10 TRIBE_Game::start_campaign_menu.

int TRIBE_Game::start_campaign_menu()
{
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

// PDB lines 1601-1636; VA 00524030 TRIBE_Game::start_menu.

#include <new.h>

extern TPanelSystem panel_system;

int TRIBE_Game::start_menu()
{
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

// PDB lines 1642-1733; VA 00524150 TRIBE_Game::quit_game.

extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);
extern int do_debug_random;
extern void debug_random_write();
extern void dump_vismap_log();

void TRIBE_Game::quit_game()
{
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
            if (this->player_game_info->set_current_person(
                    this->world->campaign_player) != 0 &&
                this->player_game_info->set_current_campaign(
                    this->world->campaign) != 0) {
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

                sprintf(temp_test_scenario, "%s%s.scn",
                        this->prog_info->scenario_dir,
                        this->testing_scenario);
                if (_findfirst(temp_test_scenario, &file_info) == -1) {
                    sprintf(temp_test_scenario, "%s.scx",
                            this->testing_scenario);
                } else {
                    sprintf(temp_test_scenario, "%s.scn",
                            this->testing_scenario);
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
            this->testing_scenario[0] = 0;
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

// PDB lines 1739-1842; VA 005243A0 TRIBE_Game::restart_game.

void TRIBE_Game::restart_game()
{
    char temp_name[260];
    _finddata_t file_info;
    int result;

    this->show_status_message(0x451, 0, -1);
    this->close_game_screens(0);
    this->game_screen = 0;
    panel_system.destroyPanel("Game Screen");
    this->prog_mode = 0;
    this->world->del_game_info();

    for (int player = 1; player < 9; ++player) {
        this->comm_handler->SetPlayerHumanity(
            player, static_cast<PLAYERHUMANITY>(this->save_humanity[player]));
    }

    if (this->savedGame() != 0) {
        sprintf(temp_name, "%s%s.gmx", this->prog_info->save_dir,
                this->load_game_name);
        if (_findfirst(temp_name, &file_info) == -1) {
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

        TEasy_Panel* panel = static_cast<TEasy_Panel*>(
            panel_system.panel("Main Menu"));
        if (panel != 0) {
            static_cast<TEasy_Panel*>(panel)->popupOKDialog(0x961, 0, 0x1C2,
                                                            100);
        }
    }
}

// PDB lines 1850-1879; VA 00524530 TRIBE_Game::load_db_files.

int TRIBE_Game::load_db_files()
{
    this->disable_input();
    this->show_status_message(0x44d, 0, -1);

    int result = 0;
    if (this->world != 0) {
        delete this->world;
        this->world = 0;
    }

    this->world = this->createGameWorld();
    if (this->world != 0) {
        if (this->world->data_load(this->prog_info->game_data_file,
                                   this->prog_info->world_db_file)) {
            result = 1;
        }
        delete this->world;
        this->world = 0;
    }

    this->close_status_message();
    this->enable_input();
    return result;
}

// PDB lines 1887-1903; VA 005245D0 TRIBE_Game::load_game_data.

#include "../include/game_globals.h"

int TRIBE_Game::load_game_data()
{
    if (this->world == 0) {
        this->world = this->createGameWorld();
        if (this->world == 0)
            return 0;

        if (!this->world->init(this->prog_info->game_data_file,
                               this->sound_system, this->comm_handler)) {
            if (this->world != 0)
                delete this->world;
            this->world = 0;
            return 0;
        }
    }
    return 1;
}

// PDB lines 1909-1959; VA 00524640 TRIBE_Game::save_game.

extern "C" char* __cdecl strcpy(char* destination, const char* source);
extern "C" char* __cdecl strchr(const char* source, int character);

extern int ENABLE_COMPRESSION; // 00585A6C

int TRIBE_Game::save_game(char* filename)
{
    if (this->prog_mode != 4 && this->prog_mode != 6 &&
        this->prog_mode != 7 && this->prog_mode != 5) {
        return 0;
    }

    this->disable_input();
    this->show_status_message(0x453, 0, -1);

    if (this->check_prog_argument("DEBUGSAVEGAME") != 0) {
        ENABLE_COMPRESSION = 0;
    }

    int result = this->world->save_game(filename);
    ENABLE_COMPRESSION = 1;
    if (result == 0) {
        this->close_status_message();
        this->enable_input();
        return 0;
    }

    char fileNameNoExt[260];
    strcpy(fileNameNoExt, filename);
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

// PDB lines 1965-1997; VA 00524790 TRIBE_Game::save_scenario.

int TRIBE_Game::save_scenario(char* filename)
{
    if (this->prog_mode != 4 && this->prog_mode != 6 &&
        this->prog_mode != 7 && this->prog_mode != 5) {
        return 0;
    }

    this->disable_input();
    this->show_status_message(0x450, 0, -1);

    for (int i = 1; i < this->world->player_num; i++) {
        this->world->scenario->Set_player_Active(i - 1, 1);
    }

    if (this->world->save_scenario(filename) == 0) {
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

// PDB lines 2003-2069; VA 00524880 TRIBE_Game::calc_timing_text.

extern "C" char* __cdecl strcpy(char* destination, const char* source);
extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);

extern int show_timing_max;

void TRIBE_Game::calc_timing_text()
{
    if ((DAT_0086bcd0 & 1) == 0) {
        DAT_0086bcd0 |= 1;
        DAT_0086bcd8 = debug_timeGetTime(
            "C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0x7D4);
    }

    DAT_0086bcd8 = debug_timeGetTime(
        "C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0x7D6);

    if (this->world_update_count == 0) {
        strcpy(this->timing_text2, "f?");
    } else if (show_timing_max == 0) {
        sprintf(
            this->timing_text2,
            "t%lu,f%lu,avg(r(v%lu,m%lu,o%lu),s%lu,u%lu,c%lu,l%lu,p%lu,o%lu)",
            this->world_update_fps,
            this->view_update_fps,
            this->timings[6].last_time / this->world_update_count,
            this->timings[7].last_time / this->world_update_count,
            this->timings[17].last_time / this->world_update_count,
            this->timings[3].last_time / this->world_update_count,
            this->timings[1].last_time / this->world_update_count,
            this->timings[14].last_time / this->world_update_count,
            (this->timings[10].last_time + this->timings[12].last_time) /
                this->world_update_count,
            this->timings[13].last_time / this->world_update_count,
            this->timings[4].last_time / this->world_update_count);
    } else {
        sprintf(
            this->timing_text2,
            "t%lu,f%lu,max(r(v%lu,m%lu,o%lu),s%lu,u%lu,c%lu,ls%lu,lg%lu,p%lu,o%lu)",
            this->world_update_fps,
            this->view_update_fps,
            this->timings[6].last_max_time,
            this->timings[7].last_max_time,
            this->timings[17].last_max_time,
            this->timings[3].last_max_time,
            this->timings[1].last_max_time,
            this->timings[14].last_max_time,
            this->timings[10].last_max_time,
            this->timings[12].last_max_time,
            this->timings[13].last_max_time,
            this->timings[4].last_max_time);
    }

    if (this->view_update_count == 0) {
        strcpy(this->timing_text, "avg view time=???");
        return;
    }

    sprintf(this->timing_text, "avg view time=%lu, count=%lu",
            this->timings[6].last_time / this->view_update_count,
            this->view_update_count);
}

// PDB lines 2075-2079; VA 00524A60 TRIBE_Game::show_timings.

void TRIBE_Game::show_timings() {
    if (this->game_screen)
        this->game_screen->show_timings(this->timing_text,
                                        this->timing_text2);
}

// PDB lines 2085-2095; VA 00524A80 TRIBE_Game::show_comm.

void TRIBE_Game::show_comm() {
    if (this->game_screen == 0) return;

    this->game_screen->show_comm(
        this->comm_handler->GetCommInfo(1),
        this->comm_handler->GetCommInfo(2),
        this->comm_handler->GetCommInfo(3),
        this->comm_handler->GetCommInfo(4),
        this->comm_handler->GetCommInfo(5),
        this->comm_handler->GetCommInfo(6)
    );
}

// PDB lines 2100-2137; VA 00524AF0 TRIBE_Game::show_ai.

#include <string.h>
#include <stdio.h>

void TRIBE_Game::show_ai()
{
    int i;
    char s[6][256];
    if (this->world->players == 0) {
        return;
    }
    RGE_Player* player = this->world->players[this->world->curr_player];

    if (player->computerPlayer() == 1) {
        const char* n = player->aiStatus(1);
        if (n == 0) {
            sprintf(s[0], "Player #%d: AI is not functional.",
                    this->world->curr_player);
        } else {
            sprintf(s[0], "Player #%d: %s",
                    this->world->curr_player, n);
        }
        i = 2;
        char (*destination)[256] = &s[2];
        for (; i <= 6; ++i) {
            const char* p = player->aiStatus(i);
            char* output = destination[-1];
            const char* source = "";
            if (p != 0) {
                source = p;
            }
            strcpy(output, source);
            ++destination;
        }
    } else {
        const char* p = player->aiStatus(0);
        strcpy(s[0], p);
        sprintf(s[1], "Player #%d is not a computer player.",
                this->world->curr_player);
        strcpy(s[2], "");
        strcpy(s[3], "");
        strcpy(s[4], "");
        strcpy(s[5], "");
    }

    if (this->game_screen != 0) {
        if (player->computerPlayer() == 1) {
            this->game_screen->show_ai(s[5], s[4], s[3], s[2], s[1], s[0]);
        } else {
            this->game_screen->show_ai(s[0], s[1], s[2], s[3], s[4], s[5]);
        }
    }
}

// PDB lines 2143-2580; VA 00524D70 TRIBE_Game::notification.

#include <stdio.h>

extern int player_dropped[9];

void TRIBE_Game::notification(int type, long player, long value,
                              long value2, long value3)
{
    char msg[256];
    char temp_str[256];
    TRIBE_World* world = static_cast<TRIBE_World*>(this->world);

    switch (type) {
    case 0x7E:
        if (player == this->world->curr_player && this->game_screen != 0) {
            this->play_sound(0x10);
            this->add_notification_loc(value2, value3);
            return;
        }
        break;

    case 0x7C:
        if (player == this->world->curr_player && this->game_screen != 0) {
            this->game_screen->setup_buttons();
            return;
        }
        break;

    case 0x7D:
        if (player == this->world->curr_player && this->game_screen != 0) {
            this->get_string2(0x67, 1, value, msg, 256);
            this->game_screen->show_message(TMessagePanel::BadMessage, msg,
                                            0x55, 0);
            return;
        }
        break;

    case 0x64:
        if (player == this->world->curr_player && this->game_screen != 0) {
            int sound;
            if (value == 0x65 || value == 0x66 || value == 0x67) {
                sound = 5;
            }
            else {
                sound = 0x0F;
            }
            this->play_sound(sound);
            this->game_screen->setup_buttons();
            this->add_notification_loc(value2, value3);
            return;
        }
        break;

    case 0x66:
    case 0x69:
        if (player == this->world->curr_player && this->game_screen != 0) {
            this->game_screen->setup_buttons();
            this->add_notification_loc(value2, value3);
            return;
        }
        break;

    case 0x68:
        if (player == this->world->curr_player && this->game_screen != 0) {
            this->play_sound(3);
            this->get_string2(0x67, 1000, value, msg, 256);
            this->game_screen->show_message(TMessagePanel::BadMessage, msg,
                                            0x55, 0);
            return;
        }
        break;

    case 0x6B:
        if (player == this->world->curr_player && this->game_screen != 0) {
            this->play_sound(3);
            this->get_string2(0x67, 0x6A, 0, msg, 256);
            this->game_screen->show_message(TMessagePanel::BadMessage, msg,
                                            0x55, 0);
            return;
        }
        break;

    case 1:
        if (player == this->world->curr_player && this->game_screen != 0) {
            this->play_sound(3);
            this->get_string2(0x67, 0x66, 0, msg, 256);
            this->game_screen->show_message(TMessagePanel::BadMessage, msg,
                                            0x55, 0);
            return;
        }
        break;

    case 2:
        if (player == this->world->curr_player && this->game_screen != 0) {
            this->play_sound(3);
            this->get_string2(0x67, 0x69, 0, msg, 256);
            this->game_screen->show_message(TMessagePanel::BadMessage, msg,
                                            0x55, 0);
            return;
        }
        break;

    case 3:
        if (player == this->world->curr_player && this->game_screen != 0) {
            this->play_sound(3);
            this->get_string2(0x67, 0x67, 0, msg, 256);
            this->game_screen->show_message(TMessagePanel::BadMessage, msg,
                                            0x55, 0);
            return;
        }
        break;

    case 4:
        if (this->playerID(player) != this->world->curr_player &&
            this->game_screen != 0 && player_dropped[player] == 0) {
            player_dropped[player] = 1;
            this->play_sound(7);
            if (this->playerID(player) > 0) {
                this->get_string(0xBC4, temp_str, 256);
                sprintf(msg, temp_str,
                        this->world->players[this->playerID(player)]->name);
                this->game_screen->display_system_message(msg);
                return;
            }
        }
        break;

    case 5:
        if (player != this->world->curr_player && this->game_screen != 0 &&
            player > 0) {
            this->play_sound(6);
            if (value == 0) {
                this->get_string(0xBC5, temp_str, 256);
            }
            else {
                this->get_string(0xBC4, temp_str, 256);
            }
            sprintf(msg, temp_str, this->world->players[player]->name);
            this->game_screen->display_system_message(msg);
            return;
        }
        break;

    case 6:
        if (player != this->world->curr_player && this->game_screen != 0) {
            this->play_sound(6);
            if (player > 0) {
                this->get_string(0xBC6, temp_str, 256);
                sprintf(msg, temp_str,
                        this->world->players[player]->name);
                this->game_screen->display_system_message(msg);
                return;
            }
        }
        break;

    case 7:
        if (value == this->world->curr_player && this->game_screen != 0) {
            this->play_sound(4);
            if (value2 == 0) {
                this->get_string(0xBC8, temp_str, 256);
            }
            else if (value2 == 1) {
                this->get_string(0xBC7, temp_str, 256);
            }
            else if (value2 == 3) {
                this->get_string(0xBC1, temp_str, 256);
            }
            else {
                this->get_string(0xBC9, temp_str, 256);
            }
            sprintf(msg, temp_str,
                    this->world->players[player]->name, value3);
            this->game_screen->display_system_message(msg);
            return;
        }
        break;

    case 8:
        if (this->game_screen != 0) {
            this->game_screen->reset_clocks();
        }
        if (value != this->world->curr_player) {
            return;
        }
        if (this->game_screen == 0) {
            return;
        }
        if (value2 == 0) {
            this->get_string(0xBD2, temp_str, 256);
        }
        else {
            if (value2 != 1) {
                if (value2 == 3) {
                    this->get_string(0xBD3, temp_str, 256);
                }
            }
            else {
                this->get_string(0xBD1, temp_str, 256);
            }
        }
        sprintf(msg, temp_str, this->world->players[player]->name);
        this->game_screen->display_system_message(msg);
        return;

    case 0x6C:
        if (this->game_screen != 0) {
            this->play_sound(8);
            if (player == this->world->curr_player) {
                this->get_string(0xBF2, msg, 256);
                this->game_screen->display_system_message(msg);
            }
            else {
                this->get_string(0xBCB, temp_str, 256);
                sprintf(msg, temp_str,
                        this->world->players[player]->name);
                this->game_screen->display_system_message(msg);
            }
            this->add_notification_loc(value2, value);
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
        p1 = this->world->players[player];
        p2 = this->world->players[this->world->curr_player];
        if (p1 == p2) {
            if (world->victory_type == 0) {
                this->get_string(0xBCC, msg, 256);
            }
            else {
                this->get_string(0xBEE, msg, 256);
            }
        }
        else {
            if ((p1->allied_victory == 0 ||
                 p1->relation(p2->id) != 0) ||
                (p2->allied_victory == 0 ||
                 p2->relation(p1->id) != 0)) {
                if (world->victory_type == 0) {
                    this->get_string(0xBCE, temp_str, 256);
                } else {
                    this->get_string(0xBEF, temp_str, 256);
                }
            } else if (world->victory_type == 0) {
                this->get_string(0xBCD, temp_str, 256);
            } else {
                this->get_string(0xBEF, temp_str, 256);
            }
            sprintf(msg, temp_str, p1->name);
        }
        this->add_notification_loc(value2, value);
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
        if (world->victory_type != 0) {
            return;
        }
        this->play_sound(10);
        p1 = this->world->players[player];
        p2 = this->world->players[this->world->curr_player];
        if (p1 == p2) {
            this->get_string(0xBCF, msg, 256);
        }
        else {
            if ((p1->allied_victory == 0 ||
                 p1->relation(p2->id) != 0) ||
                (p2->allied_victory == 0 ||
                 p2->relation(p1->id) != 0)) {
                this->get_string(0xBD0, temp_str, 256);
            } else {
                this->get_string(0xBD0, temp_str, 256);
            }
            sprintf(msg, temp_str, p1->name);
        }
        this->add_notification_loc(value2, value);
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
        p1 = this->world->players[player];
        p2 = this->world->players[this->world->curr_player];
        if (world->victory_type == 0) {
            if (p1 == p2) {
                this->get_string(0xBD4, msg, 256);
            }
            else {
                if ((p1->allied_victory == 0 ||
                     p1->relation(p2->id) != 0) ||
                    (p2->allied_victory == 0 ||
                     p2->relation(p1->id) != 0)) {
                    this->get_string(0xBD5, msg, 256);
                }
                else {
                    this->get_string(0xBD4, msg, 256);
                }
            }
        }
        else {
            this->get_string(0xBF0, msg, 256);
        }
        this->game_screen->display_system_message(msg);
        this->game_screen->reset_clocks();
        i = 1;
        if (i < this->world->player_num) {
            do {
                this->world->players[i]->notify(p1->id, i, 0x72,
                                                0, 0, 0);
                ++i;
            } while (i < this->world->player_num);
        }
        return;
    }

    case 0x73:
        if (this->game_screen == 0) {
            return;
        }
        if (world->victory_type != 0) {
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
        p1 = this->world->players[player];
        p2 = this->world->players[this->world->curr_player];
        if (world->victory_type == 0) {
            if (p1 == p2) {
                this->get_string(0xBD9, msg, 256);
            }
            else {
                if ((p1->allied_victory == 0 ||
                     p1->relation(p2->id) != 0) ||
                    (p2->allied_victory == 0 ||
                     p2->relation(p1->id) != 0)) {
                    this->get_string(0xBDA, msg, 256);
                }
                else {
                    this->get_string(0xBD9, msg, 256);
                }
            }
        }
        else {
            this->get_string(0xBF1, msg, 256);
        }
        this->game_screen->display_system_message(msg);
        this->game_screen->reset_clocks();
        i = 1;
        if (i < this->world->player_num) {
            do {
                this->world->players[i]->notify(p1->id, i, 0x74,
                                                0, 0, 0);
                ++i;
            } while (i < this->world->player_num);
        }
        return;
    }

    case 0x75:
        if (this->game_screen == 0) {
            return;
        }
        if (world->victory_type != 0) {
            return;
        }
        this->play_sound(0x0C);
        this->get_string(0xBDB, msg, 256);
        this->game_screen->display_system_message(msg);
        this->game_screen->reset_clocks();
        return;

    case 0x76:
        if (player == this->world->curr_player && this->game_screen != 0) {
            this->play_sound(3);
            this->get_string(0xBE7, msg, 256);
            this->game_screen->show_message(TMessagePanel::BadMessage, msg,
                                            0x55, 0);
            return;
        }
        break;

    case 0x77:
        if (player == this->world->curr_player && this->game_screen != 0) {
            this->play_sound(3);
            this->get_string(0xBE8, msg, 256);
            this->game_screen->show_message(TMessagePanel::BadMessage, msg,
                                            0x55, 0);
            return;
        }
        break;

    case 0x78:
        if (player == this->world->curr_player && this->game_screen != 0) {
            this->play_sound(3);
            this->get_string(0xBE9, msg, 256);
            this->game_screen->show_message(TMessagePanel::BadMessage, msg,
                                            0x55, 0);
            return;
        }
        break;

    case 0x79:
        if (player == this->world->curr_player && this->game_screen != 0) {
            this->play_sound(3);
            this->get_string(0xBEA, msg, 256);
            this->game_screen->show_message(TMessagePanel::BadMessage, msg,
                                            0x55, 0);
            return;
        }
        break;

    case 0x7A:
        if (player == this->world->curr_player && this->game_screen != 0) {
            this->play_sound(3);
            this->get_string(0xBEB, msg, 256);
            this->game_screen->show_message(TMessagePanel::BadMessage, msg,
                                            0x55, 0);
            return;
        }
        break;

    case 0x7B:
        if (this->game_screen != 0 && player != this->world->curr_player &&
            value == this->world->curr_player) {
            this->play_sound(0x0D);
        }
        break;

    }
}

// PDB lines 2586-2638; VA 00525D20 TRIBE_Game::start_game.

#include <string.h>
#include <stdio.h>

int TRIBE_Game::start_game(int param_1)
{
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

    if (param_1 != 0)
        return this->create_game_screen();

    this->start_video(3, this->world->scenario->Get_Cine_PreGame());
    return 1;
}

// PDB lines 2646-2662; VA 00525E50 TRIBE_Game::test_scenario.

#include <string.h>

int TRIBE_Game::test_scenario(char* name)
{
    strcpy(this->testing_scenario, name);
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

// PDB lines 2670-2781; VA 00525EE0 TRIBE_Game::start_scenario.

extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);

int TRIBE_Game::start_scenario(char* scenario)
{
    char scenario_file2[256];
    _finddata_t file_info;
    int first_any_player;
    int player_count;
    RGE_Scenario* scenario_info;

    this->disable_input();
    this->setSinglePlayerGame(1);
    this->setCampaignGame(0);
    this->setSavedGame(0);
    this->setScenarioGame(1);
    this->setScenarioName(scenario);
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
    sprintf(scenario_file2, "%s%s.scn", this->prog_info->scenario_dir,
            scenario);
    if (_findfirst(scenario_file2, &file_info) == -1) {
        sprintf(scenario_file2, "%s.scx", scenario);
    } else {
        sprintf(scenario_file2, "%s.scn", scenario);
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
            if (first_any_player == -1 &&
                scenario_info->Get_player_Type(i) == 1) {
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

// PDB lines 2787-3184; VA 00526170 TRIBE_Game::load_game.

#include <stdio.h>
#include <string.h>

extern "C" char* __cdecl __mbschr(const char* text, int character);
extern "C" int numberPathingIterations;
extern int ENABLE_COMPRESSION;

int TRIBE_Game::load_game(char* file_name)
{
    TPanel* old_panel;
    int loaded;
    RGE_Object_Node* list;
    RGE_Action_Node* act_node;
    long action_checksum;
    long num2;
    long num3;
    float temp_position_checksum;
    int i;
    long total_action_checksum;
    long total_checksum;
    long checksum;
    long num1;
    long num4;
    char target_name_1[50];
    char target_name_2[50];
    char target_name[50];
    char debug_file_name[260];
    char fn[260];

    this->inHandleIdle = 0;
    old_panel = panel_system.currentPanel();
    this->disable_input();

    if (this->prog_mode == 4 || this->prog_mode == 6 ||
        this->prog_mode == 5) {
        this->world->del_game_info();
        this->prog_mode = 0;
        this->game_screen = 0;
        panel_system.destroyPanel("Game Screen");
    }

    this->show_status_message(0x44D, 0, -1);
    if (this->load_game_data() == 0) {
        char* panel_name = old_panel == 0 ? 0 : old_panel->panelName();
        if (panel_name != 0 && *panel_name != 0) {
            panel_system.setCurrentPanel(panel_name, 0);
            panel_system.destroyPanel("Status Screen");
            this->enable_input();
            return 0;
        }
        this->close_status_message();
        this->enable_input();
        return 0;
    }

    this->show_status_message(0x452, 0, -1);
    if (this->sound_system != 0)
        this->sound_system->mute = 1;

    if (this->check_prog_argument("DEBUGSAVEGAME") != 0)
        ENABLE_COMPRESSION = 0;

    loaded = this->world->load_game(file_name);
    for (i = 0; i < this->world->player_num; ++i) {
        this->reset_countdown_timer(i);
    }

    ENABLE_COMPRESSION = 1;
    if (this->sound_system != 0)
        this->sound_system->mute = 0;

    if (loaded == 0) {
        char* panel_name = old_panel == 0 ? 0 : old_panel->panelName();
        if (panel_name != 0 && *panel_name != 0) {
            panel_system.setCurrentPanel(panel_name, 0);
            panel_system.destroyPanel("Status Screen");
            this->enable_input();
            return 0;
        }
        this->close_status_message();
        this->enable_input();
        return 0;
    }

    {
        this->setFullVisibility(this->world->map->map_visible_flag);
        this->setFogOfWar(this->world->map->fog_flag);
        this->setAllowCheatCodes(1);
        this->setSavedGame(1);
        this->setNumberPlayers(this->world->player_num - 1);

        loaded = this->pathFinding();
        switch (loaded) {
        case 1:
            numberPathingIterations = 5000;
            break;
        case 2:
            numberPathingIterations = 0x1D4C;
            break;
        default:
            numberPathingIterations = 0x9C4;
            break;
        }

        for (i = 0; i < 9; ++i) {
            if (i < this->world->player_num) {
                this->setPlayerID(i, i);
                if (i > 0) {
                    this->comm_handler->SetPlayerName(
                        i, this->world->players[i]->name);
                    if (i == 1)
                        this->comm_handler->SetPlayerHumanity(i, ME_HUMAN);
                    else
                        this->comm_handler->SetPlayerHumanity(i, ME_COMPUTER);
                } else {
                    this->comm_handler->SetPlayerHumanity(i, ME_ABSENT);
                }
            } else {
                this->setPlayerID(i, 0);
                this->comm_handler->SetPlayerHumanity(i, ME_ABSENT);
            }
        }

        strcpy(fn, file_name);
        char* dot = __mbschr(fn, '.');
        if (dot != 0)
            *dot = 0;
        this->set_save_game_name(fn);
        this->set_load_game_name(fn);

        if (this->check_prog_argument("DEBUGLOAD") != 0) {
            sprintf(debug_file_name, "c:\\%s.txt", fn);
            FILE* debug_file = fopen(debug_file_name, "w");
            if (debug_file != 0) {
                total_action_checksum = 0;
                total_checksum = 0;
                fprintf(debug_file, "world_time=%u\n", this->world->world_time);
                fprintf(debug_file, "old_world_time=%u\n",
                        this->world->old_world_time);
                fprintf(debug_file, "game_speed %6.2f\n",
                        this->world->game_speed);

                for (i = 0; i < this->world->player_num; ++i) {
                    RGE_Player* player = this->world->players[i];
                    fprintf(debug_file,
                            "player %d, civ=%d, score=%d, %s\n",
                            i, player->culture,
                            player->victory_conditions->get_victory_points(),
                            player->name);
                    fprintf(debug_file, "  Writing=%f\n",
                            player->attributes[200]);
                    fprintf(debug_file, "  num_sleep_obj=%d\n",
                            player->sleeping_objects->number_of_objects);
                    fprintf(debug_file, "  num_dopple_obj=%d\n",
                            player->doppleganger_objects->number_of_objects);

                    action_checksum = 0;
                    num1 = 0;
                    temp_position_checksum = 0.0f;
                    num3 = player->sleeping_objects->number_of_objects +
                        player->doppleganger_objects->number_of_objects + player->id;
                    num4 = 0;
                    while (num4 < player->attribute_num) {
                        num1 += static_cast<int>(player->attributes[num4]);
                        fprintf(debug_file, "  p#%d attr[%d]=%12.8f\n",
                                player->id, num4,
                                player->attributes[num4]);
                        ++num4;
                    }
                    num2 = 0;
                    list = player->objects->list;
                    while (list != 0) {
                        RGE_Static_Object* object = list->node;
                        int attribute_value =
                            static_cast<int>(object->attribute_amount_held);
                        num1 += object->object_state + attribute_value;
                        ++num2;
                        num3 += object->master_obj->id + num2 +
                            object->object_state + attribute_value;
                        temp_position_checksum += object->world_x;
                        temp_position_checksum += object->world_y;
                        temp_position_checksum += object->world_z;
                        action_checksum += object->get_action_checksum();
                        RGE_Static_Object* target = object->get_target_obj();
                        if (target != 0) {
                            target_name_1[0] = 0;
                            strcpy(target_name_1, target->master_obj->name);
                            num4 = target->id;
                        } else {
                            target_name_1[0] = 0;
                            num4 = -1;
                        }
                        fprintf(debug_file,
                                "  p#%d ob=%d (%s), st=%d, at=%8.4f, pos=%6.2f,%6.2f,%6.2f, tar=%d (%s)\n",
                                player->id, object->id,
                                object->master_obj->name,
                                object->object_state,
                                object->attribute_amount_held,
                                object->world_x, object->world_y,
                                object->world_z, num4, target_name_1);

                        RGE_Action_Object* moving_object =
                            static_cast<RGE_Action_Object*>(object);
                        if (object->master_obj->master_type >= 0x1E &&
                            object->master_obj->master_type != 0x5A) {
                            Path* path = &moving_object->pathValue;
                            if (path->numberOfWaypoints() > 0) {
                                path->initToStart();
                                fprintf(debug_file,
                                        "    path: s=%6.2f,%6.2f,%6.2f,g=%6.2f,%6.2f,%6.2f,cc=%d,wd=%d\n",
                                        moving_object->startValue.x,
                                        moving_object->startValue.y,
                                        moving_object->startValue.z,
                                        moving_object->goalValue.x,
                                        moving_object->goalValue.y,
                                        moving_object->goalValue.z,
                                        moving_object->continueCounter,
                                        moving_object->numberWaitDelays);
                                int waypoint_index = 0;
                                int waypoint_count = path->numberOfWaypoints();
                                while (waypoint_index < waypoint_count) {
                                    unsigned char facet =
                                        path->currentWaypoint()->facetToNextWaypoint;
                                    double y = path->currentWaypoint()->y;
                                    double x = path->currentWaypoint()->x;
                                    fprintf(debug_file,
                                            "        w%i=%6.2f,%6.2f,%d\n",
                                            waypoint_index, x, y, facet);
                                    ++waypoint_index;
                                    path->moveToNextWaypoint();
                                    waypoint_count = path->numberOfWaypoints();
                                }
                                path->initToStart();
                                path->moveToNextWaypoint();
                            }
                        }

                        if (object->master_obj->master_type >= 0x28 &&
                            object->master_obj->master_type != 0x5A &&
                            moving_object->actions != 0) {
                            act_node = moving_object->actions->list;
                            while (act_node != 0) {
                                RGE_Action* action = act_node->action;
                                if (action != 0) {
                                    fprintf(debug_file,
                                            "    action: typ=%d, st=%d, tar1=%d, tar2=%d, tp=%6.2f,%6.2f,%6.2f, subac=%d, tim=%6.2f\n",
                                            action->action_type, action->state,
                                            action->targetID, action->target2ID,
                                            action->targetX(), action->targetY(),
                                            action->targetZ(), action->subAction(),
                                            action->timer);
                                }
                                act_node = act_node->next;
                            }
                        }
                        list = list->next;
                    }

                    list = player->sleeping_objects->list;
                    while (list != 0) {
                        RGE_Static_Object* object = list->node;
                        int attribute_value =
                            static_cast<int>(object->attribute_amount_held);
                        num1 += object->object_state + attribute_value;
                        ++num2;
                        num3 += object->master_obj->id + num2 +
                            object->object_state + attribute_value;
                        temp_position_checksum += object->world_x;
                        temp_position_checksum += object->world_y;
                        temp_position_checksum += object->world_z;
                        action_checksum += object->get_action_checksum();
                        RGE_Doppleganger_Object* dopple =
                            static_cast<RGE_Doppleganger_Object*>(object);
                        RGE_Static_Object* target = object->get_target_obj();
                        if (target != 0) {
                            target_name_2[0] = 0;
                            strcpy(target_name_2, target->master_obj->name);
                            num4 = target->id;
                        } else {
                            target_name_2[0] = 0;
                            num4 = -1;
                        }
                        fprintf(debug_file,
                                "  p#%d ob=%d (%s), st=%d, at=%8.4f, pos=%6.2f,%6.2f,%6.2f, tar=%d (%s)\n",
                                player->id, object->id,
                                object->master_obj->name, object->object_state,
                                object->attribute_amount_held, object->world_x,
                                object->world_y, object->world_z, num4,
                                target_name_2);
                        if (dopple->doppled_master_obj != 0) {
                            fprintf(debug_file,
                                    "    Doppled master obj:  %s, %d.\n",
                                    dopple->doppled_master_obj->name,
                                    dopple->doppled_master_obj->master_type);
                        } else {
                            fprintf(debug_file,
                                    "    NULL doppled master obj.\n");
                        }
                        list = list->next;
                    }

                    list = player->doppleganger_objects->list;
                    while (list != 0) {
                            RGE_Static_Object* target =
                                list->node->get_target_obj();
                            if (target != 0) {
                                target_name[0] = 0;
                                strcpy(target_name, target->master_obj->name);
                                num4 = target->id;
                            } else {
                                target_name[0] = 0;
                                num4 = -1;
                            }
                            fprintf(debug_file,
                                    "  p#%d ob=%d (%s), st=%d, at=%8.4f, pos=%6.2f,%6.2f,%6.2f, tar=%d (%s)\n",
                                    player->id, list->node->id,
                                    list->node->master_obj->name,
                                    list->node->object_state,
                                    list->node->attribute_amount_held,
                                    list->node->world_x,
                                    list->node->world_y,
                                    list->node->world_z,
                                    num4, target_name);
                        list = list->next;
                    }

                    checksum = (((num3 * 0x100 + num2) * 0x100 +
                                 action_checksum) * 0x100) + num1;
                    total_action_checksum += checksum;
                    total_checksum += action_checksum;
                    fprintf(debug_file,
                            "  p#%d checksum=%d, 1=%d, 2=%d, 3=%d, 4=%d, act=%d\n",
                            player->id, checksum, num1, action_checksum, num2,
                            num3, action_checksum);
                }

                fprintf(debug_file, "total checksum=%d, act=%d\n",
                        total_checksum, total_action_checksum);
                fclose(debug_file);
            }
        }

        this->close_game_screens(0);
        return this->create_game_screen();
    }
}

// PDB lines 3191-3220; VA 00526DC0 TRIBE_Game::do_game_over.

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
                start_video(4, this->world->scenario->Get_Cine_Victory());
                return;
            }
            start_video(4, this->world->scenario->Get_Cine_Loss());
        }
    }
}

// PDB lines 3234-3697; VA 00526E60 TRIBE_Game::create_game.

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int TRIBE_Game::create_game(int param_1)
{
    int i;
    int scenario_player;
    RGE_Scenario* scenario_info;
    unsigned char pathfinding;
    int humanity;
    int position_used[8];
    long* player_hash;
    short* player_color;
    RGE_Player_Info player_info;
    char scenario_file[260];
    _finddata_t file_info;
    RGE_Map_Gen_Info map_info;

    i = 0;
    this->inHandleIdle = 0;
    for (; i < 5; ++i) {
        this->notification_loc_x[i] = -1;
        this->notification_loc_y[i] = -1;
    }
    this->current_notification_loc = -1;
    this->current_notification_recalled = -1;

    if (this->check_prog_argument("QUICKBUILD")) {
        this->quick_build = 1;
    }
    else {
        this->quick_build = 0;
    }
    this->do_show_timings = 0;
    this->do_show_comm = 0;
    this->do_show_ai = 0;
    this->set_map_visible(0);
    this->set_map_fog(0);

    for (i = 1; i < 9; ++i) {
        this->resigned[i] = 0;
        DAT_0086bcac[i - 1] = 0;
        this->queue_is_waiting_on_pop_counter[i] = 0;
    }
    out_of_sync = 0;
    out_of_sync2 = 0;
    DAT_0086be00 = 0;

    if (this->quickStartGame()) {
        if (quick_start_game_mode == 1) {
            this->setMapSize(TRIBE_Game::Medium);
            this->setMapType(static_cast<TRIBE_Game::MapType>(4));
        }
        else {
            TRIBE_Game::MapType map_type;
            this->setMapSize(TRIBE_Game::Large);
            int random_map_type = debug_rand(
                "C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0xCDD) % 10;
            if (random_map_type < 2) {
                map_type = static_cast<TRIBE_Game::MapType>(4);
            }
            else if (random_map_type == 2) {
                map_type = static_cast<TRIBE_Game::MapType>(3);
            }
            else if (random_map_type == 3) {
                map_type = static_cast<TRIBE_Game::MapType>(2);
            }
            else if (random_map_type == 4) {
                map_type = static_cast<TRIBE_Game::MapType>(1);
            }
            else if (random_map_type == 5) {
                map_type = static_cast<TRIBE_Game::MapType>(random_map_type);
            }
            else if (random_map_type == 6) {
                map_type = static_cast<TRIBE_Game::MapType>(random_map_type);
            }
            else if (random_map_type == 7) {
                map_type = static_cast<TRIBE_Game::MapType>(random_map_type);
            }
            else {
                map_type = static_cast<TRIBE_Game::MapType>((random_map_type == 8) ? 8 : 0);
            }
            this->setMapType(map_type);
        }
        this->resetRandomComputerName();
        for (i = 0; i < this->numberPlayers(); ++i) {
            int civ = debug_rand(
                "C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0xCF8) % 16 + 1;
            this->setCivilization(i, civ);
            this->setComputerName(i, this->randomComputerName(civ));
        }
    }

    memset(player_info.name, 0, sizeof(player_info));
    memset(&map_info, 0, sizeof(map_info));

    if (this->campaignGame()) {
        player_info.campaign = 1;
    }
    else if (this->scenarioGame()) {
        if (this->scenarioName() == 0) {
            return 0;
        }
        sprintf(scenario_file, "%s%s.scn",
                this->prog_info->scenario_dir, this->scenarioName());
        if (_findfirst(scenario_file, &file_info) == -1) {
            sprintf(scenario_file, "%s.scx", this->scenarioName());
        }
        else {
            sprintf(scenario_file, "%s.scn", this->scenarioName());
        }
        player_info.scenario = scenario_file;
    }
    else {
        player_info.map_info = &map_info;
        player_info.map_type = this->mapType();
        player_info.map_width = this->mapXSize();
        player_info.map_height = this->mapYSize();
    }

    if (this->multiplayerGame()) {
        debug_srand("C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0xD24,
                    this->comm_handler->GetRandomSeed());
    }
    else if (this->random_game_seed == -1) {
        debug_srand("C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0xD2A,
                    debug_rand("C:\\msdev\\work\\age1_x1\\tribegam.cpp",
                               0xD2A));
    }
    else {
        debug_srand("C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0xD28,
                    this->random_game_seed);
    }

    player_info.player_num = 0;
    long* player_hashes = player_info.player_id_hash;
    short* player_colors = player_info.color;
    for (i = 0; i < 9; ++i) {
        player_info.type[i] = -1;
        player_info.name[i][0] = 0;
        player_hashes[i] = i;
        player_info.tribe[i] = 1;
        player_colors[i] = -1;
        this->random_civ[i] = 0;

        int civ = this->civilization(i);
        if (civ > 16 || this->civilization(i) < 0) {
            this->setCivilization(
                i, (debug_rand("C:\\msdev\\work\\age1_x1\\tribegam.cpp",
                               0xD3B) * 16) / 0x7FFF + 1);
            this->random_civ[i] = 1;
        }
    }

    this->resetRandomComputerName();
    for (i = 0; i < this->numberPlayers(); ++i) {
        int player = i + 1;
        if (this->comm_handler->GetPlayerHumanity(player) == ME_COMPUTER) {
            this->setComputerName(i, this->randomComputerName(this->civilization(i)));
        }
    }

    int scenario_mode = -1;
    char* scenario_name = 0;
    scenario_info = 0;
    if (this->campaignGame()) {
        scenario_mode = 1;
        scenario_name = 0;
    } else if (this->scenarioGame()) {
        scenario_mode = 0;
        scenario_name = player_info.scenario;
    }
    if (scenario_mode != -1) {
        scenario_info = this->get_scenario_info(scenario_name, scenario_mode);
        if (scenario_info == 0) {
            return 0;
        }
    }

    for (i = 0; i < 9; ++i) {
        position_used[i] = -1;
        this->setPlayerID(i, 0);
    }

    scenario_player = 0;
    i = 1;
    while (i <= this->numberPlayers()) {
        if (this->comm_handler->GetPlayerHumanity(i) == ME_HUMAN) {
            int color = this->playerColor(i - 1) - 1;
            if (position_used[color] == -1) {
                position_used[color] = scenario_player;
                ++scenario_player;
            }
            this->setPlayerID(i, position_used[color] + 1);
        }
        else if (this->comm_handler->GetPlayerHumanity(i) == ME_COMPUTER) {
            int* position = &position_used[1];
            for (int color = 0; color < 8; ++color, ++position) {
                if (*position != -1) {
                    continue;
                }
                int found = 0;
                for (int j = 1; j < 9; ++j) {
                    if (this->comm_handler->GetPlayerHumanity(j) == ME_HUMAN &&
                        this->playerColor(j - 1) - 1 == color) {
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    this->setPlayerColor(i - 1, color + 1);
                    *position = scenario_player;
                    ++scenario_player;
                    this->setPlayerID(i, *position + 1);
                    break;
                }
            }
        }
        ++i;
    }

    this->resetRandomComputerName();
    player_color = player_info.color;
    player_hash = player_info.player_id_hash + 1;
    i = 0;
    do {
        int player = i + 1;
        scenario_player = 0;
        int slot = 1;
        while (slot < 9) {
            if (this->playerID(slot) == player) {
                scenario_player = slot;
                break;
            }
            ++slot;
        }
        if (scenario_player == 0) {
            break;
        }

        humanity = this->comm_handler->GetPlayerHumanity(scenario_player);
        int color = this->playerColor(scenario_player - 1) - 1;
        if (humanity == ME_COMPUTER || all_cp == 1 ||
            (all_cp == 2 && i > 0)) {
            player_info.type[i] = 4;
        }
        else {
            player_info.type[i] = 0;
        }

        if (this->campaignGame()) {
            player_info.tribe[i] = scenario_info->Get_player_Civ(color);
        }
        else {
            player_info.tribe[i] = this->civilization(scenario_player - 1);
        }

        char* source_name = 0;
        if (this->multiplayerGame() && humanity == 2) {
            strncpy(player_info.name[i],
                    this->comm_handler->GetPlayerName(scenario_player), 0x40);
        }
        else {
            if (this->campaignGame() == 0 && player_info.type[i] == 0) {
                source_name = this->player_game_info->get_current_player_name();
            }
            else if (this->campaignGame() == 0 && this->randomGame() != 0 && player_info.type[i] == 0) {
                this->get_string(0x286D, player_info.name[i], 0x41);
            }
            else if (this->campaignGame() != 0 || this->scenarioGame() != 0) {
                source_name = scenario_info->GetPlayerName(color);
            }
            if (source_name != 0) {
                strcpy(player_info.name[i], source_name);
            }
        }

        if (player_info.name[i][0] == 0) {
            if (player_info.type[i] == 0) {
                this->get_string(0x286D, player_info.name[i], 0x41);
            }
            else if (this->campaignGame() == 0 && this->computerName(scenario_player) != 0) {
                this->get_string(this->computerName(scenario_player) + 0x1130,
                                 player_info.name[i], 0x41);
            }
            else {
            this->get_string(this->randomComputerName(player_info.tribe[i]) + 0x1130,
                                 player_info.name[i], 0x41);
            }
        }
        this->comm_handler->SetPlayerName(scenario_player, player_info.name[i]);

        *player_hash = color + 1;
        *player_color = color;
        ++player_hash;
        ++player_color;
        ++player_info.player_num;
        ++i;
    } while (i < 8);

    if (scenario_info != 0) {
        delete scenario_info;
    }
    if (player_info.player_num == 0) {
        return 0;
    }

    if (this->sound_system != 0) {
        this->sound_system->mute = 1;
    }

    unsigned char result;
    int local_player;
    if (this->multiplayerGame()) {
        local_player = this->comm_handler->WhoAmI();
    }
    else {
        local_player = 1;
    }
    result = this->world->new_game(
        player_info, this->playerID(local_player));
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
    if (this->fullVisibility() != 0) {
        for (i = 1; i < this->world->player_num; ++i) {
            if (this->world->players[i]->computerPlayer() == 0) {
                this->world->players[i]->visible->explore_all();
            }
        }
    }
    this->set_map_fog(this->fogOfWar());

    if (this->multiplayerGame()) {
        pathfinding = this->mpPathFinding();
    }
    else {
        pathfinding = this->pathFinding();
    }
    switch (pathfinding) {
    case 1:
        numberPathingIterations = 5000;
        break;
    case 2:
        numberPathingIterations = 0x1D4C;
        break;
    default:
        numberPathingIterations = 0x9C4;
        break;
    }

    for (i = 1; i < 9; ++i) {
        this->save_humanity[i] = this->comm_handler->GetPlayerHumanity(i);
    }
    return result;
}

// PDB lines 3703-3767; VA 00527830 TRIBE_Game::create_game_screen.

int TRIBE_Game::create_game_screen()
{
    this->disable_input();
    this->set_game_mode(0, 0);

    TRIBE_Screen_Game* screen = new TRIBE_Screen_Game;
    this->game_screen = screen;

    if (screen != 0 && screen->error_code == 0) {
        int waiting_for_players = 0;
        int multiplayer_started = this->comm_handler->MultiplayerGameStart();
        if (multiplayer_started == 0) {
            TRIBE_Screen_Wait* wait = new TRIBE_Screen_Wait;
            if (wait != 0) {
                wait->set_text(0x454);
                panel_system.setCurrentPanel("Multiplayer Wait Screen", 0);
                panel_system.destroyPanel("Status Screen");
                this->set_prog_mode(3);
                waiting_for_players = 1;
            }
        } else {
            panel_system.setCurrentPanel("Game Screen", 0);
            panel_system.destroyPanel("Status Screen");
        }

        if (waiting_for_players || multiplayer_started != 0) {
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
    }

    if (this->game_screen != 0) {
        delete this->game_screen;
        this->game_screen = 0;
    }

    this->world->del_game_info();
    this->close_status_message();
    this->enable_input();
    return 0;
}

// PDB lines 3773-4202; VA 00527A70 TRIBE_Game::processCheatCode.

extern "C" char* __cdecl strcpy(char*, const char*);
extern "C" char* __cdecl strstr(const char*, const char*);
extern "C" int __cdecl strcmp(const char*, const char*);
extern "C" int __cdecl sscanf(const char*, const char*, ...);
extern "C" unsigned char* __cdecl __mbsupr(unsigned char*);

extern void __cdecl encrypt_codes(char* src, char* dst, int max_len);

int TRIBE_Game::processCheatCode(int player_id, char* cheat) {
    int target;
    int commander;
    char encstr[512];
    char str[256];
    char tempStr1[256];
    char playName[256];

    if (cheat == 0 || player_id < 0 || player_id >= this->world->player_num) {
        return 0;
    }

    strcpy(str, cheat);
    __mbsupr(reinterpret_cast<unsigned char*>(str));
    encrypt_codes(str, encstr, 0x200);

    if (this->allowCheatCodes() == 0) {
        return 0;
    }

    int cheat_code = -1;
    if (strcmp(encstr, "@)%^%cAm %%_jdW") == 0 &&
        this->singlePlayerGame() != 0) cheat_code = 0x66;
    else if (strstr(str, "STORMBILLY") != 0) cheat_code = 0x0e;
    else if (strstr(str, "CONVERT THIS!") != 0) cheat_code = 0x0f;
    else if (strstr(str, "BIG MOMMA") != 0) cheat_code = 0x10;
    else if (strstr(str, "MINIWINSETT") != 0) cheat_code = 0x11;
    else if (strstr(str, "GRANTLINKSPENCE") != 0) cheat_code = 0x12;
    else if (strstr(str, "KING ARTHUR") != 0) cheat_code = 0x13;
    else if (strcmp(encstr, "w>@)%^ ^%^dW %chxdW") == 0) cheat_code = 0;
    else if (strcmp(encstr, "Am=%c3C2  ^%%%^%^w>Am%%") == 0) cheat_code = 1;
    else if (strcmp(encstr, "}{hx3CcW *_Am dW#L%c*_+!Am") == 0) cheat_code = 2;
    else if (strcmp(encstr, "*_#L1Z *_Am%% ^@)hx") == 0) cheat_code = 3;
    else if (strcmp(encstr, "Jm+!::#LdW1Z ?>_j ^3C@)%chxdW") == 0) cheat_code = 4;
    else if (strcmp(encstr, "_jw>1$#L?>Jm+!#LdW ^%c%^*_#L+!Am") == 0) cheat_code = 7;
    else if (strcmp(encstr, "@)%^::%^@)%^::%^") == 0) cheat_code = 8;
    else if (strcmp(encstr, "?>hx%%cW %%hx#LdW") == 0) cheat_code = 10;
    else if (strcmp(encstr, "*_+!hx3CcW %%#L?>Am%%") == 0) cheat_code = 11;
    else if (strcmp(encstr, "%cAm?>_j1$hx") == 0) cheat_code = 12;
    else if (strcmp(encstr, "#L3C*_%c") == 0) cheat_code = 13;
    else {
        if (this->singlePlayerGame() != 0) {
            if (strcmp(encstr, "?>#LAm?>#LAm?>#LAm") == 0) cheat_code = 100;
            else if (strcmp(encstr, "cW#L+!+!1") == 0) cheat_code = 0xc9;
            else if (strcmp(encstr, "cW#L+!+!2") == 0) cheat_code = 0xca;
            else if (strcmp(encstr, "cW#L+!+!3") == 0) cheat_code = 0xcb;
            else if (strcmp(encstr, "cW#L+!+!4") == 0) cheat_code = 0xcc;
            else if (strcmp(encstr, "cW#L+!+!5") == 0) cheat_code = 0xcd;
            else if (strcmp(encstr, "cW#L+!+!6") == 0) cheat_code = 0xce;
            else if (strcmp(encstr, "cW#L+!+!7") == 0) cheat_code = 0xcf;
            else if (strcmp(encstr, "cW#L+!+!9") == 0) cheat_code = 0xd0;
        }
        if (cheat_code == -1 && strcmp(encstr, "@)hx%%#L cWhx%%#L") == 0)
            cheat_code = 0x65;
    else if (cheat_code == -1 && strcmp(encstr, "%%Am1$#L1ZdW") == 0)
        cheat_code = 0x67;
    else if (cheat_code == -1 && strcmp(encstr, "1Zhx#Lhx") == 0) {
        this->get_player()->unselect_object();
        if (this->world->game_state == 6 && this->sub_game_mode == 1)
            this->set_game_mode(0, 0);
        this->set_player(0);
        return 1;
    }
    else if (cheat_code == -1 && strcmp(encstr, "w>Amw>w>Am%%%^dW#L w>#LS?S?hx") == 0) { this->get_player()->command_add_attribute(0, 1000.0f); return 1; }
    else if (cheat_code == -1 && strcmp(encstr, "3C%^#LdWhx1ZAm") == 0) { this->get_player()->command_add_attribute(3, 1000.0f); return 1; }
    else if (cheat_code == -1 && strcmp(encstr, "43%^%^?>1$ ^%^3CcW") == 0) { this->get_player()->command_add_attribute(1, 1000.0f); return 1; }
    else if (cheat_code == -1 && strcmp(encstr, "hx_jhx%%%%::") == 0) { this->get_player()->command_add_attribute(2, 1000.0f); return 1; }
    else if (cheat_code == -1 && strcmp(encstr, "1$ ^Am%%%^#L?>1$") == 0) {
        static_cast<TRIBE_Command*>(this->world->commands)->command_quick_build(
            static_cast<short>(this->quick_build == 0));
        return 1;
    }
    else if (cheat_code == -1 && strcmp(encstr, "*_#L1Z?>hx?>?>::") == 0) cheat_code = 0xdc;
    else if (cheat_code == -1 && strcmp(encstr, "%%Am&TAmhx+! %chxw>") == 0) cheat_code = 0xe6;
    else if (cheat_code == -1 && strcmp(encstr, "dW%^ Jm%^1Z") == 0) cheat_code = 0xe7;
    else if (cheat_code == -1) {
        sscanf(str, "%s ", tempStr1);
        if (strcmp(tempStr1, "SELECTOBJ") == 0) {
            sscanf(cheat, "%*s %d ", &commander);
            RGE_Static_Object* obj = this->world->object(commander);
            if (obj != 0) {
                obj->selected = 1;
                this->world->players[player_id]->selected_obj = obj;
            }
        }
        if (strcmp(tempStr1, "RUNPLAY") == 0) {
            sscanf(cheat, "%*s %d %s %d ", &target, playName, &commander);
            int play = this->world->playbook->playNumber(playName);
            if (play != -1) {
                this->world->players[player_id]->sendPlayCommand(
                    target, commander, play);
                return 1;
            }
        }
        else {
            if (strcmp(encstr, "S?Am_j1$") != 0) {
                return 0;
            }
            this->world->players[player_id]->sendAICommand(
                player_id, 0, 0, 0, 0);
        }
        return 1;
    }

    if (cheat_code >= 0) {
        static_cast<TRIBE_World*>(this->world)->send_cheat(
            static_cast<short>(cheat_code));
        return 1;
    }
    }
    return 0;
}

// PDB lines 4208-4359; VA 00528670 TRIBE_Game::let_game_begin.

#include <stdio.h>
#include <string.h>

extern void __cdecl run_log(char* text, int level);
extern "C" __declspec(dllimport) int __stdcall IsIconic(void* window);

extern TPanelSystem panel_system;
extern TChat* chat;

void TRIBE_Game::let_game_begin()
{
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

    sprintf(str, "    randomgame=%d, randommap=%d, mapsize=%s, maptype=%s",
            this->randomGame(), this->random_map_seed != -1,
            map_size_str, map_type_str);
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
    sprintf(str, "    resources=%s, age=%s, victory=%s, difficulty=%s",
            res_str, age_str, vic_str, diff_str);
    run_log(str, 0);

    sprintf(str, "    fulltech=%d, revealmap=%d", this->fullTechTree(),
            this->fullVisibility());
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

// PDB lines 4365-4412; VA 00528DE0 TRIBE_Game::start_scenario_editor.

int TRIBE_Game::start_scenario_editor(char* scenario_filename, int mode)
{
    this->disable_input();
    panel_system.destroyPanel("Scenario Editor Screen");

    TRIBE_Screen_Sed* editor =
        new TRIBE_Screen_Sed(scenario_filename, mode);
    if (editor != 0 && editor->need_to_save_flag == 0) {
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

// PDB lines 4418-4431; VA 00528F60 TRIBE_Game::send_game_options.

void TRIBE_Game::send_game_options(void) {
    TRIBE_Game_Combined_Options combined_options;

    if (this->comm_handler != 0) {
        this->get_game_options(&combined_options.base);
        this->get_tribe_options(&combined_options.tribe);
        this->comm_handler->SetMyGameOptions(
            reinterpret_cast<char*>(&combined_options), 0x114);
    }
}

// PDB lines 4437-4455; VA 00528FB0 TRIBE_Game::receive_game_options.

void TRIBE_Game::receive_game_options(void) {
    if (this->comm_handler != 0) {
        unsigned long size = 0;
        TRIBE_Game_Combined_Options* options =
            static_cast<TRIBE_Game_Combined_Options*>(
                this->comm_handler->GetMyGameOptions(&size));
        if (options != 0 && size == 0x114) {
            this->set_game_options(&options->base);
            this->set_tribe_options(&options->tribe);
        }
    }
}

// PDB lines 4461-4487; VA 00529000 TRIBE_Game::set_tribe_options.

void TRIBE_Game::set_tribe_options(TRIBE_Game_Options* options) {
    int i;

    this->setMapSize(options->mapSizeValue);
    this->setMapType(options->mapTypeValue);
    this->setAnimals(options->animalsValue);
    this->setPredators(options->predatorsValue);
    this->setVictoryType(options->victoryTypeValue,
                         options->victoryAmountValue);

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

// PDB lines 4493-4520; VA 00529100 TRIBE_Game::get_tribe_options.

void TRIBE_Game::get_tribe_options(TRIBE_Game_Options* opt)
{
    int i;

    opt->mapSizeValue = mapSize();
    opt->mapTypeValue = mapType();
    opt->animalsValue = animals();
    opt->predatorsValue = predators();
    opt->victoryTypeValue = victoryType();
    opt->victoryAmountValue = victoryAmount();

    for (i = 0; i < 9; i++) {
        opt->civilizationValue[i] = static_cast<unsigned char>(civilization(i));
        opt->scenarioPlayerValue[i] = scenarioPlayer(i);
        opt->playerColorValue[i] = static_cast<unsigned char>(playerColor(i));
        opt->computerNameValue[i] = static_cast<unsigned char>(computerName(i));
    }

    opt->allowTradingValue = static_cast<unsigned char>(allowTrading());
    opt->longCombatValue = static_cast<unsigned char>(longCombat());
    opt->randomizePositionsValue = static_cast<unsigned char>(randomizePositions());
    opt->fullTechTreeValue = static_cast<unsigned char>(fullTechTree());
    opt->resourceLevelValue = resourceLevel();
    opt->startingAgeValue = startingAge();
    opt->startingUnitsValue = static_cast<unsigned char>(startingUnits());
    opt->deathMatchValue = deathMatch();
    opt->popLimitValue = popLimit();
}

// PDB lines 4525-4527; VA 005291F0 TRIBE_Game::mapSize.

TRIBE_Game::MapSize TRIBE_Game::mapSize() const {
    return static_cast<TRIBE_Game::MapSize>(
        this->tribe_game_options.mapSizeValue);
}

// PDB lines 4532-4554; VA 00529200 TRIBE_Game::setMapSize.

void TRIBE_Game::setMapSize(MapSize size) {
    this->tribe_game_options.mapSizeValue = size;
    switch (size) {
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

// PDB lines 4559-4561; VA 005292A0 TRIBE_Game::mapType.

TRIBE_Game::MapType TRIBE_Game::mapType() const {
    return static_cast<TRIBE_Game::MapType>(
        this->tribe_game_options.mapTypeValue);
}

// PDB lines 4566-4568; VA 005292B0 TRIBE_Game::setMapType.

void TRIBE_Game::setMapType(TRIBE_Game::MapType val) {
    this->tribe_game_options.mapTypeValue = val;
}

// PDB lines 4573-4575; VA 005292C0 TRIBE_Game::animals.

int TRIBE_Game::animals() const { return this->tribe_game_options.animalsValue; }

// PDB lines 4580-4583; VA 005292D0 TRIBE_Game::setAnimals.

void TRIBE_Game::setAnimals(int val) { this->tribe_game_options.animalsValue = val; }

// PDB lines 4588-4590; VA 005292E0 TRIBE_Game::predators.

int TRIBE_Game::predators() const { return this->tribe_game_options.predatorsValue; }

// PDB lines 4595-4598; VA 005292F0 TRIBE_Game::setPredators.

void TRIBE_Game::setPredators(int val) { this->tribe_game_options.predatorsValue = val; }

// PDB lines 4603-4605; VA 00529300 TRIBE_Game::victoryType.

TRIBE_Game::VictoryType TRIBE_Game::victoryType() const {
    return static_cast<TRIBE_Game::VictoryType>(
        this->tribe_game_options.victoryTypeValue);
}

// PDB lines 4610-4612; VA 00529310 TRIBE_Game::victoryAmount.

int TRIBE_Game::victoryAmount() const { return this->tribe_game_options.victoryAmountValue; }

// PDB lines 4617-4620; VA 00529320 TRIBE_Game::setVictoryType.

void TRIBE_Game::setVictoryType(TRIBE_Game::VictoryType type, int amount) {
    this->tribe_game_options.victoryTypeValue = type;
    this->tribe_game_options.victoryAmountValue = amount;
}

// PDB lines 4626-4628; VA 00529340 TRIBE_Game::civilization.

int TRIBE_Game::civilization(int i) {
    return this->tribe_game_options.civilizationValue[i];
}

// PDB lines 4634-4636; VA 00529350 TRIBE_Game::setCivilization.

void TRIBE_Game::setCivilization(int player, int civ) {
    this->tribe_game_options.civilizationValue[player] =
        static_cast<unsigned char>(civ);
}

// PDB lines 4642-4644; VA 00529370 TRIBE_Game::scenarioPlayer.

int TRIBE_Game::scenarioPlayer(int idx) { return this->tribe_game_options.scenarioPlayerValue[idx]; }

// PDB lines 4650-4652; VA 00529380 TRIBE_Game::setScenarioPlayer.

void TRIBE_Game::setScenarioPlayer(int i, int v) {
    this->tribe_game_options.scenarioPlayerValue[i] = v;
}

// PDB lines 4658-4660; VA 005293A0 TRIBE_Game::playerColor.

int TRIBE_Game::playerColor(int i) {
    return this->tribe_game_options.playerColorValue[i];
}

// PDB lines 4666-4668; VA 005293B0 TRIBE_Game::setPlayerColor.

void TRIBE_Game::setPlayerColor(int i, int v) {
    this->tribe_game_options.playerColorValue[i] = v;
}

// PDB lines 4674-4676; VA 005293D0 TRIBE_Game::computerName.

int TRIBE_Game::computerName(int i) {
    return this->tribe_game_options.computerNameValue[i];
}

// PDB lines 4682-4684; VA 005293E0 TRIBE_Game::setComputerName.

void TRIBE_Game::setComputerName(int i, int v) {
    this->tribe_game_options.computerNameValue[i] = v;
}

// PDB lines 4690-4692; VA 00529400 TRIBE_Game::allowTrading.

int TRIBE_Game::allowTrading() { return this->tribe_game_options.allowTradingValue; }

// PDB lines 4698-4700; VA 00529410 TRIBE_Game::longCombat.

int TRIBE_Game::longCombat() { return this->tribe_game_options.longCombatValue; }

// PDB lines 4706-4708; VA 00529420 TRIBE_Game::randomizePositions.

int TRIBE_Game::randomizePositions() { return this->tribe_game_options.randomizePositionsValue; }

// PDB lines 4714-4716; VA 00529430 TRIBE_Game::fullTechTree.

int TRIBE_Game::fullTechTree() { return this->tribe_game_options.fullTechTreeValue; }

// PDB lines 4722-4724; VA 00529440 TRIBE_Game::resourceLevel.

TRIBE_Game::ResourceLevel TRIBE_Game::resourceLevel() {
    return static_cast<TRIBE_Game::ResourceLevel>(
        this->tribe_game_options.resourceLevelValue);
}

// PDB lines 4730-4732; VA 00529450 TRIBE_Game::startingAge.

TRIBE_Game::Age TRIBE_Game::startingAge() {
    return static_cast<TRIBE_Game::Age>(
        this->tribe_game_options.startingAgeValue);
}

// PDB lines 4738-4740; VA 00529460 TRIBE_Game::startingUnits.

int TRIBE_Game::startingUnits() { return this->tribe_game_options.startingUnitsValue; }

// PDB lines 4746-4748; VA 00529470 TRIBE_Game::deathMatch.

unsigned char TRIBE_Game::deathMatch() { return this->tribe_game_options.deathMatchValue; }

// PDB lines 4754-4759; VA 00529480 TRIBE_Game::popLimit.

unsigned char TRIBE_Game::popLimit() {
    return this->tribe_game_options.popLimitValue;
}

// PDB lines 4766-4768; VA 005294A0 TRIBE_Game::quickStartGame.

unsigned char TRIBE_Game::quickStartGame() { return this->quick_start_game; }

// PDB lines 4774-4776; VA 005294B0 TRIBE_Game::randomStartValue.

int TRIBE_Game::randomStartValue() { return this->random_start_value; }

// PDB lines 4782-4784; VA 005294C0 TRIBE_Game::setAllowTrading.

void TRIBE_Game::setAllowTrading(int val) {
    this->tribe_game_options.allowTradingValue = static_cast<unsigned char>(val);
}

// PDB lines 4790-4792; VA 005294D0 TRIBE_Game::setLongCombat.

void TRIBE_Game::setLongCombat(int val) {
    this->tribe_game_options.longCombatValue = static_cast<unsigned char>(val);
}

// PDB lines 4798-4800; VA 005294E0 TRIBE_Game::setRandomizePositions.

void TRIBE_Game::setRandomizePositions(int val) {
    this->tribe_game_options.randomizePositionsValue =
        static_cast<unsigned char>(val);
}

// PDB lines 4806-4808; VA 005294F0 TRIBE_Game::setFullTechTree.

void TRIBE_Game::setFullTechTree(int val) {
    this->tribe_game_options.fullTechTreeValue = static_cast<unsigned char>(val);
}

// PDB lines 4814-4816; VA 00529500 TRIBE_Game::setResourceLevel.

void TRIBE_Game::setResourceLevel(TRIBE_Game::ResourceLevel val) {
    this->tribe_game_options.resourceLevelValue = val;
}

// PDB lines 4822-4824; VA 00529510 TRIBE_Game::setStartingAge.

void TRIBE_Game::setStartingAge(TRIBE_Game::Age val) {
    this->tribe_game_options.startingAgeValue = val;
}

// PDB lines 4830-4832; VA 00529520 TRIBE_Game::setStartingUnits.

void TRIBE_Game::setStartingUnits(int val) {
    this->tribe_game_options.startingUnitsValue = static_cast<unsigned char>(val);
}

// PDB lines 4838-4840; VA 00529530 TRIBE_Game::setDeathMatch.

void TRIBE_Game::setDeathMatch(unsigned char val) { this->tribe_game_options.deathMatchValue = val; }

// PDB lines 4846-4848; VA 00529540 TRIBE_Game::setPopLimit.

void TRIBE_Game::setPopLimit(unsigned char val) { this->tribe_game_options.popLimitValue = val; }

// PDB lines 4854-4856; VA 00529550 TRIBE_Game::setQuickStartGame.

void TRIBE_Game::setQuickStartGame(unsigned char val) { this->quick_start_game = val; }

// PDB lines 4862-4864; VA 00529560 TRIBE_Game::setRandomStartValue.

void TRIBE_Game::setRandomStartValue(int val) { this->random_start_value = val; }

// PDB lines 4869-4908; VA 00529570 TRIBE_Game::gameSummary.

char* TRIBE_Game::gameSummary() {
    DAT_0086bca0 = 0;
    return reinterpret_cast<char*>(&DAT_0086bca0);
}

// PDB lines 4914-4942; VA 00529580 TRIBE_Game::wnd_proc.

long __stdcall TRIBE_Game::wnd_proc(void* hWnd, unsigned int msg,
                                    unsigned int wParam, long lParam)
{
    if (msg <= 0x200) {
        if (msg != 0x200) {
            if (msg == 7) {
                if (this->is_mouse_on == 0) {
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

    return this->RGE_Base_Game::wnd_proc(
        reinterpret_cast<HWND>(hWnd), msg, wParam, lParam);
}

// PDB lines 4948-5060; VA 00529610 TRIBE_Game::handle_idle.

#include <string.h>

extern void color_log(unsigned char first, unsigned char second, int level);

int TRIBE_Game::handle_idle()
{
    int retval;
    char str[100];
    char msg[2304];

    retval = RGE_Base_Game::handle_idle();
    if (retval == 0) {
        return 0;
    }

    if (this->inHandleIdle != 0) {
        L->Log("Already in handle_idle, wT=%ld.",
               this->world->world_time);
        return 0;
    }

    this->inHandleIdle = 1;
    color_log(0x4C, 0x4C, 5);
    color_log(0x4C, 0x16, 5);

    if (this->prog_mode == 1 && this->video_window != 0) {
        unsigned long now = debug_timeGetTime(
            "C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0x1381);
        if (now - this->last_video_time >= 1000) {
            SendMessageA(this->video_window, 0x46A, 100,
                         reinterpret_cast<long>(str));
            if (str[0] == 0 || strcmp(str, "stopped") == 0) {
                this->stop_video(1);
            } else if (this->video_paused == 0 &&
                       strcmp(str, "paused") == 0) {
                SendMessageA(this->video_window, 0x855, 0, 0);
            }
            this->last_video_time = debug_timeGetTime(
                "C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0x138D);
        }
    } else if (this->prog_mode == 3) {
        if (this->comm_handler->MultiplayerGameStart() != 0) {
            color_log(0x4C, 0x24, 5);
            this->let_game_begin();
        } else {
            color_log(0x4C, 0x54, 5);
            unsigned long now = debug_timeGetTime(
                "C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0x139C);
            if (now - DAT_0086be04 >= 500) {
                this->get_string(0x454, msg, 0x900);
                strcat(msg, "\n");

                int player;
                for (player = 1; player < 9; ++player) {
                    if (player != this->comm_handler->WhoAmI() &&
                        this->comm_handler->IsPlayerHuman(player) != 0) {
                        strcat(msg, "\n");
                        strcat(msg,
                               this->comm_handler->WaitingOnNamedInfo(player));
                    }
                }

                TRIBE_Screen_Wait* wait = static_cast<TRIBE_Screen_Wait*>(
                    panel_system.panel("Multiplayer Wait Screen"));
                if (wait != 0) {
                    wait->set_text(msg);
                }
                DAT_0086be04 = debug_timeGetTime(
                    "C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0x13AC);
            }
        }
    } else if (this->prog_mode == 4 || this->prog_mode == 6 ||
               this->prog_mode == 5) {
        color_log(0x4C, 0x32, 5);
        if (out_of_sync2 == 0 && this->game_screen != 0) {
            this->game_screen->handle_game_update();
        }
    }

    color_log(0x4C, 0x5F, 5);
    this->inHandleIdle = 0;
    return retval;
}

// PDB lines 5066-5079; VA 00529980 TRIBE_Game::handle_query_new_palette.

int TRIBE_Game::handle_query_new_palette(void* param_1, unsigned int param_2, unsigned int param_3, long param_4) {
    int result;
    int mode;

    result = 1;
    mode = this->prog_mode;
    if (mode == result) {
        if (this->video_window != 0 && this->video_hi_color == 0) {
            SendMessageA(this->video_window, 0x476, 0, 0);
        }
    }
    else {
        result = RGE_Base_Game::handle_query_new_palette(param_1, param_2, param_3, param_4);
    }

    return result;
}

// PDB lines 5085-5109; VA 005299E0 TRIBE_Game::handle_activate.

int TRIBE_Game::handle_activate(void* param_1, unsigned int param_2, unsigned int param_3, long param_4) {
    RGE_Base_Game::handle_activate(param_1, param_2, param_3, param_4);

    if (this->prog_mode == 1 && this->video_window != 0) {
        if (param_3 == 1) {
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

// PDB lines 5115-5280; VA 00529A70 TRIBE_Game::action_user_command.

extern "C" int __cdecl sprintf(char*, const char*, ...);

extern int do_debug_random;
extern int out_of_sync;
extern int out_of_sync2;
extern int player_dropped[9];
extern void debug_random_write();
extern void dump_vismap_log();

int TRIBE_Game::action_user_command(unsigned long param_1,
                                    unsigned long param_2)
{
    char msg[256];
    char temp_str[260];
    TPanel* panel;
    int player;

    if (this->prog_mode == 3) {
        switch (param_1) {
        case 0x17a8:
        case 0x17a9:
        case 0x17aa:
        case 0x17ab:
        case 0x17b2:
        case 0x17b6:
            this->quit_game();
            panel_system.destroyPanel("Multiplayer Wait Screen");
            panel_system.destroyPanel("Status Screen");
            panel = panel_system.currentPanel();
            if (panel != 0) {
                static_cast<TEasy_Panel*>(panel)->popupOKDialog(0x25c9, 0,
                                                                0x1c2, 100);
            }
            break;

        case 0x17ac:
        case 0x17b7:
            this->reset_comm();
            this->setSinglePlayerGame(1);
            this->quit_game();
            panel_system.destroyPanel("Multiplayer Wait Screen");
            panel_system.destroyPanel("Status Screen");
            panel = panel_system.currentPanel();
            if (panel == 0) {
                break;
            }
            static_cast<TEasy_Panel*>(panel)->popupOKDialog(0x25c9, 0,
                                                            0x1c2, 100);
            break;
        }
    } else if (this->prog_mode == 4 || this->prog_mode == 6 ||
               this->prog_mode == 5) {
        switch (param_1) {
        case 0x17b2:
            if (this->game_screen == 0) {
                break;
            }
            this->world->players[this->world->player_num]
                ->loss_if_game_on();
            this->do_game_over();
            panel = panel_system.currentPanel();
            if (panel != 0) {
                static_cast<TEasy_Panel*>(panel)->popupOKDialog(0x25c9, 0,
                                                                0x1c2, 100);
            }
            break;

        case 0x17b0:
            if (this->game_screen != 0) {
                this->play_sound(2);
                this->game_screen->display_system_message(
                    "Out of sync detected by communications.");
            }
            if (this->check_prog_argument("SKIPSYNCSAVE") == 0) {
                if (out_of_sync == 0) {
                    out_of_sync = 1;
                    if (this->comm_handler->IsHost() != 0) {
                        static_cast<TRIBE_Command*>(this->world->commands)
                            ->command_save_game();
                    }
                }
            } else if (out_of_sync == 0) {
                player = this->comm_handler->WhoAmI();
                if (this->comm_handler->IsPlayerOutOfSync(
                        player, param_2) != 0) {
                    out_of_sync = 1;
                    out_of_sync2 = 1;
                    new TRIBE_Screen_Status_Message(
                        "Temp Screen", "", 0, -1);
                    panel_system.setCurrentPanel("Temp Screen", 0);
                    this->close_game_screens(1);
                    if (do_debug_random != 0) {
                        debug_random_write();
                        dump_vismap_log();
                    }
                    player = this->comm_handler->WhoAmI();
                    sprintf(msg, "syncerr%d.gam", player);
                    this->save_game(msg);
                    this->world->players[this->world->player_num]
                        ->loss_if_game_on();
                    this->do_game_over();
                    panel = panel_system.currentPanel();
                    if (panel != 0) {
                        static_cast<TEasy_Panel*>(panel)->popupOKDialog(
                            0x966, 0, 0x1c2, 100);
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

        case 0x17d5:
            if (this->game_screen != 0) {
                this->play_sound(2);
                this->game_screen->handleChatReceived(param_2);
            }
            break;

        case 0x17bd:
        {
            player = this->playerID(param_2);
            if (player != this->world->player_num &&
                this->game_screen != 0 &&
                this->playerID(param_2) > 0 && player_dropped[param_2] == 0) {
                this->play_sound(2);
                this->get_string(0x4c1, temp_str + 4, 0x100);
                player = this->playerID(param_2);
                sprintf(msg, temp_str + 4,
                        this->world->players[player]->name);
                this->game_screen->display_system_message(msg);
                player = this->playerID(param_2);
                L->Log("$$$ PROBLEM COMMUNICATING WITH %s",
                       this->world->players[player]->name);
            }
            break;
        }
        }
    }

    return 1;
}

// PDB lines 5286-5315; VA 00529F60 TRIBE_Game::action_key_down.

extern void (__stdcall *WinHelpA_tribe)(int, const char*, int, int);

int TRIBE_Game::action_key_down(unsigned long key, int param_2, int param_3,
                                int param_4, int param_5)
{
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
    if (!this->multiplayerGame() || (this->prog_mode != 4 && this->prog_mode != 6 && this->prog_mode != 7 && this->prog_mode != 5)) {
        WinHelpA_tribe(reinterpret_cast<int>(this->prog_window),
                       "empires.hlp", 3, 0);
    }
    return 0;
}

// PDB lines 5321-5365; VA 0052A000 TRIBE_Game::action_close.

int TRIBE_Game::action_close() {
    if (this->comm_handler) {
        this->disconnect_multiplayer_game();
        this->prog_mode = 0;
    }
    return 1;
}

// PDB lines 5371-5380; VA 0052A030 TRIBE_Game::game_over_msg.

#pragma warning(disable:4234)

char* TRIBE_Game::game_over_msg() {
    RGE_Game_World* world = this->world;
    RGE_Player* player = world->players[world->curr_player];
    if (player->game_status == 1) {
        this->get_string(0x47E, DAT_0086BCE0, 0x100);
        return DAT_0086BCE0;
    }
    this->get_string(0x47F, DAT_0086BCE0, 0x100);
    return DAT_0086BCE0;
}

// PDB lines 5386-5391; VA 0052A080 TRIBE_Game::get_achievement_info.

long TRIBE_Game::get_achievement_info(unsigned char param_1, char** param_2) {
    if (!this->world)
        return 0;
    return static_cast<TRIBE_World*>(this->world)->get_achievement(
        param_1, param_2);
}

// PDB lines 5397-5431; VA 0052A0B0 TRIBE_Game::randomComputerName.

extern "C" int atoi(const char*);
extern "C" int debug_rand(const char* file, int line);

int TRIBE_Game::randomComputerName(int param1) {
    char s[12];
    int max;
    int slot;
    int i;
    int tries;

    this->get_string((param1 + 0x1B7) * 10, s, 10);
    max = atoi(s);

    tries = 0;

    do {
        int r = debug_rand("C:\\msdev\\work\\age1_x1\\tribegam.cpp",
                           0x1521);
        slot = r % max;
        if (slot > max - 1) slot = max - 1;
        if (this->computerNameUsed[param1][slot] == 0) break;
        tries++;
    } while (tries < 20);

    if (this->computerNameUsed[param1][slot] == 1) {
        for (i = 0; i < 10; i++) {
            if (this->computerNameUsed[param1][i] == 0) {
                slot = i;
                break;
            }
        }
    }

    this->computerNameUsed[param1][slot] = 1;
    return slot + param1 * 10 - 9;
}

// PDB lines 5437-5443; VA 0052A170 TRIBE_Game::resetRandomComputerName.

void TRIBE_Game::resetRandomComputerName() {
    memset(this->computerNameUsed, 0, sizeof(this->computerNameUsed));
}

// PDB lines 5449-5463; VA 0052A190 TRIBE_Game::video_wnd_proc.

extern "C" __declspec(dllimport) void* __stdcall SetCursor(void* cursor);

long TRIBE_Game::video_wnd_proc(void* hwnd, unsigned int msg, unsigned int wparam, long lparam) {
    switch (msg) {
    case 0x200:
        SetCursor(0);
        return 0;
    case 0x201:
    case 0x204:
        this->stop_video(1);
        return 0;
    }

    return CallWindowProcA(
        reinterpret_cast<FARPROC>(this->old_video_wnd_proc),
        reinterpret_cast<HWND>(hwnd), msg, wparam, lparam);
}

// PDB lines 5470-5478; VA 0052A1E0 TRIBE_Game::SetClickTables.

void TRIBE_Game::SetClickTables(MouseClickInfo* a, int b,
                                MouseClickInfo* c, int d) {
    this->MouseRightClickTable = a;
    this->MouseRightClickTableSize = b;
    this->MouseLeftClickTable = c;
    this->MouseLeftClickTableSize = d;
}

// PDB lines 5484-5495; VA 0052A210 TRIBE_Game::set_interface_messages.

void TRIBE_Game::set_interface_messages() {
    if (this->prog_info->interface_style == 1) {
        this->SetClickTables(Tribe1btnMouseRightClickTable,
                             Tribe1btnMouseRightClickTableSize,
                             Tribe1btnMouseLeftClickTable,
                             Tribe1btnMouseLeftClickTableSize);
        return;
    }
    this->SetClickTables(Tribe2btnMouseRightClickTable,
                         Tribe2btnMouseRightClickTableSize,
                         Tribe2btnMouseLeftClickTable,
                         Tribe2btnMouseLeftClickTableSize);
}

// PDB lines 5501-5569; VA 0052A260 TRIBE_Game::setup_video_system.

int TRIBE_Game::setup_video_system()
{
    if (this->video_setup != 0) {
        return 1;
    }

    panel_system.setCurrentPanel("Blank Screen", 0);
    this->mouse_off();

    this->video_double_size = 1;
    this->video_changed_res = 0;
    this->video_hi_color = 0;
    this->video_save_palette = this->draw_system->palette;

    if (this->draw_system->ScreenMode == 2) {
        SetCursor(0);
        SetClassLongA(this->prog_window, -12, 0);
        this->mouse_pointer->Shutdown_Mouse();

        this->video_save_res_wid = this->draw_system->ScreenWidth;
        this->video_save_res_hgt = this->draw_system->ScreenHeight;
        if (this->check_prog_argument("8BITVIDEO") == 0) {
            if (this->draw_system->IsModeAvail(0x280, 0x1E0, 0x10) != 0) {
                L->Log("640x480 16bit");
                this->video_changed_res =
                    this->draw_system->SetDisplaySize(0x280, 0x1E0, 0x10);
                if (this->video_changed_res != 0) {
                    this->video_double_size = 1;
                    this->video_hi_color = 1;
                    L->Log("640x480 16bit success");
                }
            }

            if (this->video_changed_res == 0 &&
                this->draw_system->ScreenWidth != 0x280) {
                if (this->draw_system->IsModeAvail(0x280, 0x1E0, 8) != 0) {
                    L->Log("640x480 8bit");
                    this->video_changed_res =
                        this->draw_system->SetDisplaySize(0x280, 0x1E0, 8);
                    if (this->video_changed_res != 0) {
                        this->video_double_size = 1;
                        L->Log("640x480 8bit success");
                    }
                }
            }
        }
    }

    L->Log("video_changed_res=%d, double_size=%d",
        this->video_changed_res, this->video_double_size);
    this->set_prog_mode(1);
    this->stop_sound_system();
    this->video_setup = 1;
    return 1;
}

// PDB lines 5575-5605; VA 0052A430 TRIBE_Game::shutdown_video_system.

extern "C" int restore_mouse_after_paint;  // 62C55Ch

void TRIBE_Game::shutdown_video_system()
{
    if (video_setup == 0) return;

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

// PDB lines 5611-5649; VA 0052A510 TRIBE_Game::disconnect_multiplayer_game.

void TRIBE_Game::disconnect_multiplayer_game()
{
    if (this->multiplayerGame()) {
        if (this->prog_mode == 4 || this->prog_mode == 6 ||
            this->prog_mode == 7 || this->prog_mode == 5) {
            this->comm_handler->SendIResignMsg();
            this->comm_handler->ShutdownGameMessages();

            if (this->comm_handler->CountWaitingMessages() > 0) {
                this->disable_input();
                this->show_status_message(0x4C0, 0, -1);

                unsigned long start_time = debug_timeGetTime(
                    "C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0x15F8);
                unsigned long elapsed_start = start_time;

                int disconnected = 0;
                while (!disconnected) {
                    unsigned long now;
                    if (this->world == 0 || this->world->game_state == 1) {
                        break;
                    }

                    this->comm_handler->ShutdownGameMessages();
                    now = debug_timeGetTime(
                        "C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0x1601);
                    if (now - elapsed_start < 500) {
                        continue;
                    }

                    if (this->comm_handler->CountWaitingMessages() == 0) {
                        break;
                    }
                    elapsed_start = debug_timeGetTime(
                        "C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0x1605);
                    if (elapsed_start - start_time >= 15000) {
                        disconnected = 1;
                    }
                }
            }

            this->comm_handler->GameOver();
            this->comm_handler->UnlinkToLevel(SERVICE_AVAILABLE);
        }
    } else {
        this->comm_handler->GameOver();
    }
}

// PDB lines 5653-5667; VA 0052A630 TRIBE_Game::add_notification_loc.

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

// PDB lines 5671-5691; VA 0052A6A0 TRIBE_Game::goto_notification_loc.

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

    this->get_player()->set_view_loc(static_cast<float>(x),
                                     static_cast<float>(y));
}
