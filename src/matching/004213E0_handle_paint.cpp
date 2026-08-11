// VA: 004213E0 RGE_Base_Game::handle_paint (1096 B)
// PDB source: basegame.cpp:4319-4531
// Attempt log:
// - Replaced the packet's raw-offset/free-function scaffold with the period
//   typed RGE_Base_Game, TDrawSystem, TPanel, TMousePointer, and COM surfaces.
//   Kept the original timing/panel/mouse control-flow shape and corrected the
//   final InvalidateRect receiver to the incoming window parameter.
// - The animation deadline is updated in place before the do-loop; this is the
//   natural source form that preserves the oracle's result/deadline registers.
// - The panel test is a direct positive currentPanel() predicate, and the
//   proven panel_system global is kept at 0062E870.
// - The late timing expression keeps the panel delta on the left of the
//   inline 115B elapsed subtraction; this preserves the original x86 order.

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)
#define VPAD64(n) VPAD32(n) VPAD32(n##_32)

typedef int PositionMode;
typedef int RedrawMode;

struct tagRECT;
class TDrawArea;
class TShape;
class IDirectDrawSurface;

extern void color_log(unsigned char a, unsigned char b, int c);
extern "C" unsigned long __cdecl debug_timeGetTime(char* file, int line);
extern "C" __declspec(dllimport) int __stdcall ValidateRect(void* hwnd,
                                                               const void* rect);
extern "C" __declspec(dllimport) int __stdcall InvalidateRect(void* hwnd,
                                                                 const void* rect,
                                                                 int erase);
extern "C" __declspec(dllimport) void* __stdcall SetCursor(void* cursor);
extern "C" __declspec(dllimport) long __stdcall SetClassLongA(void* hwnd,
                                                                long index,
                                                                long value);

class IDirectDrawSurface {
public:
    virtual long __stdcall v0();
    virtual long __stdcall v1();
    virtual long __stdcall v2();
    virtual long __stdcall v3();
    virtual long __stdcall v4();
    virtual long __stdcall v5();
    virtual long __stdcall v6();
    virtual long __stdcall v7();
    virtual long __stdcall v8();
    virtual long __stdcall v9();
    virtual long __stdcall v10();
    virtual long __stdcall v11();
    virtual long __stdcall v12();
    virtual long __stdcall GetBltStatus(unsigned long flags);
};

class TDrawSystem {
public:
    void* Inst;
    void* Wnd;
    void* Pal;
    TDrawArea* DrawArea;
    TDrawArea* PrimaryArea;
    void* DrawAreaList;
    void* DirDraw;
    IDirectDrawSurface* PrimarySurface;
    char gap_20[0x458];
    unsigned char DrawType;
    unsigned char ScreenMode;

    void Paint(tagRECT* rect);
};

class TSound_Driver {
public:
    void play_list();
    void reset_play_list();
};

class TMousePointer {
public:
    void on();
    void draw(int forced);
    void erase();
    int Restore_Mouse(TDrawArea* area);
};

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long,
                       unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(PositionMode, long, long, long, long,
                                 long, long, long, long, TPanel*, TPanel*,
                                 TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(RedrawMode);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, RedrawMode);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(tagRECT*);
    virtual void draw_offset(long, long, tagRECT*);
    virtual void draw_rect2(tagRECT*);
    virtual void draw_offset2(long, long, tagRECT*);
    virtual void paint();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual long handle_idle();
    virtual long handle_size(long, long);
    virtual long handle_paint();
};

class TPanelSystem {
public:
    TPanel* currentPanel();
};

#define panel_system (*(TPanelSystem*)0x62E870)

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
    virtual TPanel* get_view_panel();
    virtual TPanel* get_map_panel();
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
    char gap_14[0x48 - 0x14];
    TDrawSystem* draw_system;                  // +0x48
    TDrawArea* draw_area;                      // +0x4C
    char gap_50[0x04];
    int custom_mouse;                          // +0x54
    char gap_58[0x08];
    TSound_Driver* sound_system;               // +0x60
    char gap_64[0x1B0 - 0x64];
    int prog_mode;                             // +0x1B0
    char gap_1B4[0x1C0 - 0x1B4];
    TMousePointer* mouse_pointer;              // +0x1C0
    int erase_mouse;                            // +0x1C4
    int mouse_blit_sync;                        // +0x1C8
    int is_mouse_on;                            // +0x1CC
    int windows_mouse;                          // +0x1D0
    void* mouse_cursor;                         // +0x1D4
    char gap_1D8[0x3F8 - 0x1D8];
    int render_all;                             // +0x3F8
    char gap_3FC[0x504 - 0x3FC];
    unsigned long frame_count;                 // +0x504
    char gap_508[0x8E8 - 0x508];
    int do_show_timings;                       // +0x8E8

    int check_paint();
    void add_to_timing(int index, unsigned long value);
    void clear_window();
};

extern RGE_Base_Game* rge_base_game;
extern int restore_mouse_after_paint;
extern unsigned long DAT_0062c578;
extern unsigned int DAT_0062c57c;

int RGE_Base_Game::handle_paint(void* param_1, unsigned int param_2,
                                unsigned int param_3, long param_4)
{
    unsigned long time_a;
    unsigned long time_b;
    unsigned long time_c;
    int result;

    color_log(0x32, 0x32, 4);

    time_a = debug_timeGetTime((char*)0x57FB08, 0x10EA);
    result = this->check_paint();
    time_b = debug_timeGetTime((char*)0x57FB08, 0x10EE);
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
        time_a = debug_timeGetTime((char*)0x57FB08, 0x10FC);
        time_a += 100;

        do {
            if (result != (int)0x8876021C)
                goto paint_done;

            surface = this->draw_system->PrimarySurface;
            result = surface->GetBltStatus(1);
            time_b = debug_timeGetTime((char*)0x57FB08, 0x1100);
        } while (time_b <= time_a);

        this->mouse_blit_sync = 0;
    }

paint_done:
    color_log(0x32, 0xBA, 4);

    time_a = debug_timeGetTime((char*)0x57FB08, 0x110C);
    TSound_Driver* sound = rge_base_game->sound_system;
    if (sound != 0) {
        sound->play_list();
        sound->reset_play_list();
    }

    time_b = debug_timeGetTime((char*)0x57FB08, 0x1115);
    this->add_to_timing(10, time_b - time_a);

    time_a = debug_timeGetTime((char*)0x57FB08, 0x111C);
    if (this->erase_mouse != 0) {
        color_log(0x32, 0x4C, 4);
        if (this->render_all == 0 && this->custom_mouse != 0)
            this->mouse_pointer->erase();
        this->erase_mouse = 0;
    }

    time_c = debug_timeGetTime((char*)0x57FB08, 0x1127) - time_a;
    time_a = debug_timeGetTime((char*)0x57FB08, 0x112A);
    color_log(0x32, 0x16, 4);

    TPanel* panel;
    if (panel_system.currentPanel() != 0) {
        color_log(0x16, 0x16, 1);
        if (this->render_all != 0) {
            panel = panel_system.currentPanel();
            panel->set_redraw(2);
        }
        panel = panel_system.currentPanel();
        panel->handle_paint();
        color_log(0x16, 0x5F, 1);
    } else {
        this->clear_window();
    }

    color_log(0x32, 0x24, 4);
    if (DAT_0062c57c != 0) {
        DAT_0062c57c = 0;
        if ((this->prog_mode == 4 || this->prog_mode == 5) &&
            this->do_show_timings != 0)
            this->show_timings();
    }

    time_b = debug_timeGetTime((char*)0x57FB08, 0x1147);
    this->add_to_timing(2, time_b - time_a);

    time_a = debug_timeGetTime((char*)0x57FB08, 0x114B);
    color_log(0x32, 0x54, 4);
    if (this->custom_mouse != 0 && this->windows_mouse == 0) {
        this->mouse_pointer->draw(1);
        this->erase_mouse = 1;
    }

    time_c += debug_timeGetTime((char*)0x57FB08, 0x115B) - time_a;
    this->add_to_timing(8, time_c);

    time_a = debug_timeGetTime((char*)0x57FB08, 0x1160);
    color_log(0x32, 0x45, 4);
    this->draw_system->Paint(0);
    ValidateRect(this->prog_window, 0);
    ValidateRect(this->prog_window, 0);
    this->render_all = 0;

    time_b = debug_timeGetTime((char*)0x57FB08, 0x1176);
    this->add_to_timing(3, time_b - time_a);

    color_log(0x32, 0x5F, 4);
    ++this->frame_count;

    time_a = debug_timeGetTime((char*)0x57FB08, 0x1182);
    if (time_a - DAT_0062c578 >= 1000) {
        this->calc_timings();
        DAT_0062c578 = time_a;
        DAT_0062c57c = 1;
    }

    if (restore_mouse_after_paint != 0) {
        if (this->mouse_pointer != 0) {
            this->mouse_pointer->Restore_Mouse(this->draw_area);
            if (this->is_mouse_on != 0) {
                if (this->custom_mouse == 0 || this->windows_mouse != 0) {
                    SetCursor(this->mouse_cursor);
                    SetClassLongA(this->prog_window, -12,
                                  (long)this->mouse_cursor);
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
