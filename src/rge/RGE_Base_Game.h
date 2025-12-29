#pragma once
#include <windows.h>
#include "RGE_Prog_Info.h"
#include <cctype>
#include <cstring>
#include <string>

// Forward Declarations
struct RGE_Game_Info;
struct RGE_Scenario_File_Info;
struct TDrawSystem;
struct TDrawArea;
struct TShape;
struct TSound_Driver;
struct TMusic_System;
struct TDigital;
struct TCommunications_Handler;
struct TDebuggingLog;
struct TRegistry;
struct TMousePointer;
struct RGE_Font;
struct RGE_Game_World;
struct TChat;
struct DriveInformation;

struct RGE_Timing_Info {
    unsigned long last_time;
    unsigned long accum_time;
    unsigned long _pad[6]; 
};

struct RGE_Game_Options {
    char _data[0xA8]; 
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();                 // [00]
    virtual int  run();                       // [01]
    virtual long wnd_proc(HWND, UINT, WPARAM, LPARAM); // [02]
    virtual void set_prog_mode();             // [03]
    virtual void set_game_mode();             // [04]
    virtual void set_player();                // [05]
    virtual int  get_error_code();            // [06]

    // [07], [08], [09], [10] MUST match these signatures and order:
    virtual char* get_string(long id);                                // [07]
    virtual char* get_string(long id, char* out, int outLen);         // [08]
    virtual char* get_string(int mode, long code, char* out, int outLen); // [09]
    virtual char* get_string2(int mode, long code, long extra, char* out, int outLen); // [10]

    virtual void* get_view_panel();           // [11]   

    virtual void get_map_panel(); // [12]
    virtual void new_scenario_header_13(); // [13]
    virtual void new_scenario_header_14(); // [14]
    virtual void new_scenario_info(); // [15]
    virtual void notification(); // [16]
    virtual void reset_comm(); // [17]
    virtual void send_game_options(); // [18]
    virtual void receive_game_options(); // [19]
    virtual void gameSummary(); // [20]
    virtual void processCheatCode(); // [21]
    virtual int setup_music_system(); // [22]
    virtual void shutdown_music_system(); // [23]
    virtual int setup(); // [24]
    virtual int setup_cmd_options(); // [25]
    virtual int setup_class(); // [26]
    virtual int setup_main_window(); // [27]
    virtual int setup_graphics_system(); // [28]
    virtual int setup_palette(); // [29]
    virtual int setup_mouse(); // [30]
    virtual int setup_registry(); // [31]
    virtual int setup_debugging_log(); // [32]
    virtual int setup_chat(); // [33]
    virtual int setup_comm(); // [34]
    virtual int setup_sound_system(); // [35]
    virtual int setup_fonts(); // [36]
    virtual int setup_sounds(); // [37]
    virtual int setup_shapes(); // [38]
    virtual int setup_blank_screen(); // [39]
    virtual int setup_timings(); // [40]
    virtual void stop_sound_system(); // [41]
    virtual void restart_sound_system(); // [42]
    virtual void stop_music_system(); // [43]
    virtual void restart_music_system(); // [44]
    virtual void create_world(); // [45]
    virtual int handle_message(MSG* msg); // [46] 
    virtual int handle_idle(); // [47]
    virtual void handle_mouse_move(); // [48]
    virtual void handle_key_down(); // [49]
    virtual void handle_user_command(); // [50]
    virtual void handle_command(); // [51]
    virtual void handle_music_done(); // [52]
    virtual void handle_paint(); // [53]
    virtual void handle_activate(); // [54]
    virtual void handle_init_menu(); // [55]
    virtual void handle_exit_menu(); // [56]
    virtual void handle_size(); // [57]
    virtual void handle_palette_changed(); // [58]
    virtual void handle_query_new_palette(); // [59]
    virtual void handle_close(); // [60]
    virtual void handle_destroy(); // [61]
    virtual void action_update(); // [62]
    virtual void action_mouse_move(); // [63]
    virtual void action_key_down(); // [64]
    virtual void action_user_command(); // [65]
    virtual void action_command(); // [66]
    virtual void action_music_done(); // [67]
    virtual void action_activate(); // [68]
    virtual void action_deactivate(); // [69]
    virtual void action_init_menu(); // [70]
    virtual void action_exit_menu(); // [71]
    virtual void action_size(); // [72]
    virtual void action_close(); // [73]
    virtual void calc_timings(); // [74]
    virtual void calc_timing_text(); // [75]
    virtual void show_timings(); // [76]
    virtual void show_comm(); // [77]
    virtual void show_ai(); // [78]
    virtual int setup_map_save_area(); // [79]
    virtual void set_interface_messages(); // [80]

    // -------------------------------------------------------------------------
    // MEMBERS
    // -------------------------------------------------------------------------
    /* 0x0004 */ RGE_Game_Info* player_game_info;
    /* 0x0008 */ RGE_Scenario_File_Info* scenario_info;
    /* 0x000C */ RGE_Prog_Info* prog_info;
    /* 0x0010 */ HWND prog_window; // Changed void* to HWND for clarity
    /* 0x0014 */ int prog_ready;
    /* 0x0018 */ int prog_active;
    /* 0x001C */ void* prog_palette;
    /* 0x0020 */ void* prog_mutex;
    /* 0x0024 */ long window_style;
    /* 0x0028 */ int random_game_seed;
    /* 0x002C */ int random_map_seed;
    /* 0x0030 */ int save_random_game_seed;
    /* 0x0034 */ int save_random_map_seed;
    /* 0x0038 */ int screen_saver_enabled;
    /* 0x003C */ int low_power_enabled;
    /* 0x0040 */ int error_code;
    /* 0x0044 */ int is_timer;
    /* 0x0048 */ TDrawSystem* draw_system;
    /* 0x004C */ TDrawArea* draw_area;
    /* 0x0050 */ unsigned char outline_type;
    /* 0x0051 */ char _pad_0051[3]; 
    /* 0x0054 */ int custom_mouse;
    /* 0x0058 */ short shape_num;
    /* 0x005A */ char _pad_005A[2]; 
    /* 0x005C */ TShape** shapes;
    /* 0x0060 */ TSound_Driver* sound_system;
    /* 0x0064 */ TMusic_System* music_system;
    /* 0x0068 */ short sound_num;
    /* 0x006A */ char _pad_006A[2];
    /* 0x006C */ TDigital** sounds;
    /* 0x0070 */ unsigned char save_music_type;
    /* 0x0071 */ char _pad_0071[3];
    /* 0x0074 */ int save_music_track_from;
    /* 0x0078 */ int save_music_track_to;
    /* 0x007C */ int save_music_cur_track;
    /* 0x0080 */ char save_music_file[260];
    /* 0x0184 */ int save_music_loop;
    /* 0x0188 */ unsigned long save_music_pos;
    /* 0x018C */ TCommunications_Handler* comm_handler;
    /* 0x0190 */ int comm_syncstop;
    /* 0x0194 */ int comm_droppackets;
    /* 0x0198 */ int comm_syncmsg;
    /* 0x019C */ int comm_stepmode;
    /* 0x01A0 */ int comm_speed;
    /* 0x01A4 */ TDebuggingLog* debugLog;
    /* 0x01A8 */ int log_comm;
    /* 0x01AC */ TRegistry* registry;
    /* 0x01B0 */ int prog_mode;
    /* 0x01B4 */ int game_mode;
    /* 0x01B8 */ int sub_game_mode;
    /* 0x01BC */ int paused;
    /* 0x01C0 */ TMousePointer* mouse_pointer;
    /* 0x01C4 */ int erase_mouse;
    /* 0x01C8 */ int mouse_blit_sync;
    /* 0x01CC */ int is_mouse_on;
    /* 0x01D0 */ int windows_mouse;
    /* 0x01D4 */ void* mouse_cursor;
    /* 0x01D8 */ int input_enabled;
    /* 0x01DC */ void* input_disabled_window;
    /* 0x01E0 */ short font_num;
    /* 0x01E2 */ char _pad_01E2[2];
    /* 0x01E4 */ RGE_Font* fonts;
    /* 0x01E8 */ char work_dir[261];
    /* 0x02ED */ char string_dll_name[261];
    /* 0x03F2 */ char _pad_03F2[2];
    /* 0x03F4 */ RGE_Game_World* world;
    /* 0x03F8 */ int render_all;
    /* 0x03FC */ short master_obj_id;
    /* 0x03FE */ short terrain_id;
    /* 0x0400 */ short elevation_height;
    /* 0x0402 */ short brush_size;
    /* 0x0404 */ char timing_text[256];
    /* 0x0504 */ unsigned long frame_count;
    /* 0x0508 */ unsigned long world_update_count;
    /* 0x050C */ unsigned long view_update_count;
    /* 0x0510 */ unsigned long last_frame_count;
    /* 0x0514 */ unsigned long last_world_update_count;
    /* 0x0518 */ unsigned long last_view_update_count;
    /* 0x051C */ unsigned long fps;
    /* 0x0520 */ unsigned long world_update_fps;
    /* 0x0524 */ unsigned long view_update_fps;
    /* 0x0528 */ RGE_Timing_Info timings[30];
    /* 0x08E8 */ int do_show_timings;
    /* 0x08EC */ int do_show_comm;
    /* 0x08F0 */ int do_show_ai;
    /* 0x08F4 */ unsigned long last_view_time;
    /* 0x08F8 */ RGE_Game_Options rge_game_options;
    /* 0x09A0 */ int campaignGameValue;
    /* 0x09A4 */ int savedGameValue;
    /* 0x09A8 */ int quick_build;
    /* 0x09AC */ int save_check_for_cd;
    /* 0x09B0 */ int playerIDValue[9];
    /* 0x09D4 */ int display_selected_ids;
    /* 0x09D8 */ long countdown_timer[9];
    /* 0x09FC */ int auto_paused;
    /* 0xA00 */ int save_paused;
    /* 0xA04 */ int non_user_pause;
    /* 0xA08 */ int rollover;
    /* 0xA0C */ float game_speed;
    /* 0xA10 */ int single_player_difficulty;
    /* 0xA14 */ unsigned char pathFindingValue;
    /* 0xA15 */ unsigned char resigned[9];
    /* 0xA1E */ char _pad_0A1E[2];
    /* 0xA20 */ TDrawArea* map_save_area;
    
    // Constructor
    RGE_Base_Game(RGE_Prog_Info* info, int param_2);
    
    // Helper Methods
    void setVersion(float v);
    void setScenarioGame(int v);
    void setCampaignGame(int v);
    void setSavedGame(int v);
    void setSinglePlayerGame(int v);
    void setMultiplayerGame(int v);
    void setMapSize(int w, int h, int d);
    void setAllowCheatCodes(int v);
    void setCheatNotification(int v);
    void setFullVisibility(int v);
    void setFogOfWar(int v);
    void setColoredChat(int v);
    void setGameDeveloperMode(int v);
    void setDifficulty(int v);
    void setPlayerCDAndVersion(int p, char v);
    void setPlayerHasCD(int p, int v);
    void setPlayerVersion(int p, char v);
    void setPlayerTeam(int p, int v);
    void setPathFinding(char v);
    void setMpPathFinding(char v);
    void setNumberPlayers(int v);
    void setScenarioName(char* s);

    // New Helpers needed for setup()
    int check_expiration();
    int check_multi_copies();
    int check_for_cd(int v);
    unsigned char check_prog_argument(char* arg);
    void close(); // Referred to in TRIBE_Game::setup as RGE_Base_Game::close? Likely VTable [60] handle_close? Or separate. Decomp says RGE_Base_Game::close((RGE_Base_Game *)this);
    void mouse_on();

protected:
    static void force_terminate(char* out, int outLen) {
        if (!out || outLen <= 0) return;
        out[outLen - 1] = '\0';
    }

    static void clear(char* out) {
        if (out) out[0] = '\0';
    }


    static inline void ForceTerminate(char* s, int n) {
        if (s && n > 0) s[n - 1] = '\0';
    }

    static bool ContainsI(const char* haystack, const char* needle) {
        if (!haystack || !needle) return false;
        const size_t nlen = std::strlen(needle);
        if (nlen == 0) return true;

        for (const char* p = haystack; *p; ++p) {
            size_t i = 0;
            while (i < nlen) {
                char a = p[i];
                char b = needle[i];
                if (!a) return false;
                a = (char)std::toupper((unsigned char)a);
                b = (char)std::toupper((unsigned char)b);
                if (a != b) break;
                ++i;
            }
            if (i == nlen) return true;
        }
        return false;
    }

    // Extracts the token after "KEY=" until whitespace.
    // Example: cmd "... STRING=language_fre.dll ..." -> "language_fre.dll"
    static std::string CmdValueToken(const char* cmdLine, const char* keyUpper /* e.g. "STRING=" */) {
        if (!cmdLine || !keyUpper) return {};

        // Make an uppercased copy to locate the key (matches CharUpperA+__mbsstr intent)
        std::string up(cmdLine);
        for (char& c : up) c = (char)std::toupper((unsigned char)c);

        const char* found = std::strstr(up.c_str(), keyUpper);
        if (!found) return {};

        size_t pos = (size_t)(found - up.c_str());
        pos += std::strlen(keyUpper); // after '='

        // Now walk the ORIGINAL cmdLine at the same position to preserve original bytes
        const char* p = cmdLine + pos;

        // skip spaces
        while (*p && std::isspace((unsigned char)*p)) ++p;

        // read token until whitespace
        std::string out;
        while (*p && !std::isspace((unsigned char)*p)) {
            out.push_back(*p++);
        }
        return out;
    }

    // Loads a resource-only string DLL so LoadStringA works.
    // Tries "<workDir>\dllName" first (matches typical AoE behavior), then bare name.
    static HMODULE LoadStringDll(const char* workDir, const char* dllName) {
        if (!dllName || !dllName[0]) return nullptr;

        char path[MAX_PATH]{};
        if (workDir && workDir[0]) {
            // workDir is usually the current directory (no trailing slash)
            _snprintf(path, sizeof(path), "%s\\%s", workDir, dllName);
            HMODULE h = LoadLibraryExA(path, nullptr, LOAD_LIBRARY_AS_DATAFILE);
            if (h) return h;
        }

        HMODULE h = LoadLibraryExA(dllName, nullptr, LOAD_LIBRARY_AS_DATAFILE);
        if (h) return h;

        // last resort
        return LoadLibraryA(dllName);
    }

};

static_assert(sizeof(RGE_Base_Game) == 0xA24, "RGE_Base_Game size mismatch");