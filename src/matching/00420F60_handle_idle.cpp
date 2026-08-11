// VA: 00420F60 RGE_Base_Game::handle_idle (431 B)
// PDB source: basegame.cpp
// Attempt log:
// - Baseline used a packet-grounded free-function/raw-offset scaffold; it had
//   the correct broad behavior but emitted wrapper call identities and a raw
//   vtable call, leaving a 463-byte / 21-call mismatch.
// - Probe 2: restored the period typed member surfaces for RGE_Base_Game,
//   TDrawSystem, TSound_Driver, TPanelSystem, TPanel, and communications. The
//   field ownership remains named; the original panel palette member and
//   virtual show_comm/show_ai calls are used instead of raw vtable plumbing.

extern void color_log(unsigned char a, unsigned char b, int c);
extern "C" unsigned long __cdecl debug_timeGetTime(char* file, int line);
extern int do_restore_palette;
extern int restore_palette_timer;

struct PALETTEENTRY {
    unsigned char peRed;
    unsigned char peGreen;
    unsigned char peBlue;
    unsigned char peFlags;
};

class TDrawSystem {
public:
    char gap_00[0x78];
    PALETTEENTRY palette[256];

    void ModifyPalette(int start, int count, PALETTEENTRY* entries);
};

class TSound_Driver {
public:
    unsigned int handle_messages(void* hwnd, unsigned int msg,
                                  unsigned int wparam, long lparam);
};

class TPanel;
class TDrawArea;
typedef int PositionMode;
typedef int RedrawMode;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long,
                       unsigned char);
    virtual void set_rect(struct tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(PositionMode, long, long, long, long,
                                 long, long, long, TPanel*, TPanel*,
                                 TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(RedrawMode);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, RedrawMode);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(struct tagRECT*);
    virtual void draw_offset(long, long, struct tagRECT*);
    virtual void draw_rect2(struct tagRECT*);
    virtual void draw_offset2(long, long, struct tagRECT*);
    virtual void paint();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual long handle_idle();
};

class TPanelSystem {
public:
    TPanel* currentPanel();
};

extern TPanelSystem panel_system;

class TCommunications_Handler {
public:
    void ReceiveGameMessages();
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short);
    virtual int get_error_code();
    virtual char* get_string(int, long, char*, int);
    virtual char* get_string(long, char*, int);
    virtual char* get_string(long);
    virtual char* get_string2(int, long, long, char*, int);
    virtual void* get_view_panel();
    virtual void* get_map_panel();
    virtual void* new_scenario_header(void*);
    virtual void* new_scenario_header(int);
    virtual void* new_scenario_info(int);
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
    virtual void* create_world();
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

    char gap_04[0x0C];
    void* prog_window;                         // +0x10
    int prog_ready;                            // +0x14
    int prog_active;                           // +0x18
    char gap_1C[0x2C];
    TDrawSystem* draw_system;                  // +0x48
    char gap_4C[0x14];
    TSound_Driver* sound_system;               // +0x60
    char gap_64[0x128];
    TCommunications_Handler* comm_handler;     // +0x18C
    char gap_190[0x75C];
    int do_show_comm;                          // +0x8EC
    int do_show_ai;                            // +0x8F0

    int multiplayerGame();
};

int RGE_Base_Game::handle_idle()
{
    if (!this->prog_ready || !this->prog_window)
        return 0;

    color_log(0x16, 0x16, 2);

    if (do_restore_palette && this->prog_active) {
        int delay = 0xFA;
        if (do_restore_palette > 5)
            delay = 0x1F4;

        unsigned long t = debug_timeGetTime((char*)0x57FB08, 0xF9A);
        if ((t - restore_palette_timer) >= (unsigned long)delay) {
            if (this->draw_system) {
                this->draw_system->ModifyPalette(0, 0x100,
                    this->draw_system->palette);
            }
            do_restore_palette--;
            restore_palette_timer = debug_timeGetTime((char*)0x57FB08,
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
