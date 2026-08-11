// VA: 00529610 TRIBE_Game::handle_idle (867 B)
// PDB source: tribegam.cpp:4948-5060
//
// Attempt log:
// - Initial scratch was an incomplete raw-offset dispatcher and did not model
//   the base result, video path, multiplayer wait path, or common cleanup.
// - baseline candidate: reconstructed the period typed TRIBE_Game/base,
//   communications, panel, video, and local-buffer surfaces from the oracle's
//   ordered calls and field offsets.  The source keeps the natural positive
//   mode guards and the original string-building calls.
// - layout: a function-scope return local before the two buffers reproduces
//   the 0x968 frame and msg/str homes; the world vptr restores world_time +4.
// - behavior: spelling the player inequality as `player != WhoAmI()` selects
//   the oracle's final cmp operand order.  Result: exact 867-byte match.

#include <string.h>

extern "C" void __cdecl color_log(unsigned char first, unsigned char second,
                                   int level);
extern "C" unsigned long __cdecl debug_timeGetTime(char* file, int line);
extern "C" __declspec(dllimport) long __stdcall SendMessageA(
    void* hwnd, unsigned int message, unsigned int wparam, long lparam);

#define last_wait_time (*(unsigned long*)0x0086BE04)
#define out_of_sync2   (*(int*)0x0062C564)

class TDebuggingLog {
public:
    void __cdecl Log(char* format, ...);
};

#define L (*(TDebuggingLog**)0x0062C4FC)

class TCommunications_Handler {
public:
    int MultiplayerGameStart();
    int WhoAmI();
    int IsPlayerHuman(unsigned int player);
    char* WaitingOnNamedInfo(unsigned int player);
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    unsigned long world_time; // +0x04
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int mode);
    virtual void set_game_mode(int mode, int value);
    virtual void set_player(short player);
    virtual int get_error_code();
    virtual char* get_string(int param_1, long param_2, char* param_3,
                             int param_4);
    virtual char* get_string(long param_1, char* param_2, int param_3);
    virtual char* get_string(long param_1);
    virtual char* get_string2(int param_1, long param_2, long param_3,
                              char* param_4, int param_5);
    virtual void* get_view_panel();
    virtual void* get_map_panel();
    virtual void* new_scenario_header(void* scenario);
    virtual void* new_scenario_header(int value);
    virtual void* new_scenario_info(int value);
    virtual void notification(int, long, long, long, long);
    virtual int reset_comm();
    virtual void send_game_options();
    virtual void receive_game_options();
    virtual char* gameSummary();
    virtual int processCheatCode(int, char*);
    virtual int setup_music_system();
    virtual void shutdown_music_system();
    virtual int setup();
    virtual int setup_cmd_options();
    virtual int setup_class();
    virtual int setup_main_window();
    virtual int setup_graphics_system();
    virtual int setup_palette();
    virtual int setup_mouse();
    virtual int setup_registry();
    virtual int setup_debugging_log();
    virtual int setup_chat();
    virtual int setup_comm();
    virtual int setup_sound_system();
    virtual int setup_fonts();
    virtual int setup_sounds();
    virtual int setup_shapes();
    virtual int setup_blank_screen();
    virtual void setup_timings();
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void stop_music_system();
    virtual int restart_music_system();
    virtual RGE_Game_World* create_world();
    virtual int handle_message(void*);
    virtual int handle_idle();
    virtual int handle_mouse_move(void*, unsigned int, unsigned int, long);
    virtual int handle_key_down(void*, unsigned int, unsigned int, long);
    virtual int handle_user_command(void*, unsigned int, unsigned int, long);
    virtual int handle_command(void*, unsigned int, unsigned int, long);
    virtual int handle_music_done(void*, unsigned int, unsigned int, long);
    virtual int handle_paint(void*, unsigned int, unsigned int, long);
    virtual int handle_activate(void*, unsigned int, unsigned int, long);
    virtual int handle_init_menu(void*, unsigned int, unsigned int, long);
    virtual int handle_exit_menu(void*, unsigned int, unsigned int, long);
    virtual int handle_size(void*, unsigned int, unsigned int, long);
    virtual int handle_palette_changed(void*, unsigned int, unsigned int, long);
    virtual int handle_query_new_palette(void*, unsigned int, unsigned int, long);
    virtual int handle_close(void*, unsigned int, unsigned int, long);
    virtual int handle_destroy(void*, unsigned int, unsigned int, long);
    virtual int action_update();
    virtual int action_mouse_move(long, long, int, int, int, int);
    virtual int action_key_down(unsigned long, int, int, int, int);
    virtual int action_user_command(unsigned long, unsigned long);
    virtual int action_command(unsigned long, unsigned long);
    virtual int action_music_done();
    virtual int action_activate();
    virtual int action_deactivate();
    virtual int action_init_menu();
    virtual int action_exit_menu();
    virtual int action_size();
    virtual int action_close();
    virtual void calc_timings();
    virtual void calc_timing_text();
    virtual void show_timings();
    virtual void show_comm();
    virtual void show_ai();

    char gap_04[0x188];
    TCommunications_Handler* comm_handler; // +0x18C
    char gap_190[0x20];
    int prog_mode; // +0x1B0
    char gap_1B4[0x240];
    RGE_Game_World* world; // +0x3F4
    char gap_3F8[0x62C];
};

class TRIBE_Screen_Game {
public:
    void handle_game_update();
};

class TRIBE_Screen_Wait {
public:
    char gap_00[0x478];
    void set_text(char* text);
};

class TPanelSystem {
public:
    void* panel(char* name);
};

extern TPanelSystem panel_system;

class TRIBE_Game : public RGE_Base_Game {
public:
    char gap_A24[0x1C8];
    void* video_window; // +0xBEC
    char gap_BF0[8];
    int video_paused; // +0xBF8
    unsigned long last_video_time; // +0xBFC
    char gap_C00[0x24];
    TRIBE_Screen_Game* game_screen; // +0xC24
    char gap_C28[0x628];
    int inHandleIdle; // +0x1250

    void stop_video(unsigned char do_stop);
    void let_game_begin();
    int handle_idle();
};

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
            SendMessageA(this->video_window, 0x46A, 100, (long)str);
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
            if (now - last_wait_time >= 500) {
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

                TRIBE_Screen_Wait* wait =
                    (TRIBE_Screen_Wait*)panel_system.panel(
                        "Multiplayer Wait Screen");
                if (wait != 0) {
                    wait->set_text(msg);
                }
                last_wait_time = debug_timeGetTime(
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
