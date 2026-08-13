// VA: 00496800 TRIBE_Screen_Game::handle_game_update (2206B)
// PDB source: scr_game.cpp lines 1589-1996
// EH frame (/GX): function contains `new TDigital(...)` expressions.
//
// Attempt log:
// baseline: canonical packet reconstruction. TRIBE_Screen_Game is a
// TScreenPanel-derived screen; world is TRIBE_World at +0x5B4 with inherited
// player_num/players/curr_player fields; main_view/map_view are at +0x4B8/+0x4BC.
// The named TPanel, RGE_View, RGE_Game_World, RGE_Base_Game, TRIBE_Game, and
// TTextPanel surfaces model the proven period layouts and virtual slots.
// The body preserves the x87 ratio calculation, 0x18 frame, 100 calls, /GX
// TDigital construction, update loop, timeout scan, game-over, and close paths.
//
// probes (2026-08):
// - rebuilt the provisional declarations as named ABI/layout surfaces and
//   replaced all provisional dispatch placeholders; the emitted code stayed in the
//   same VC5 basin while the source became auditable.
// - typed score_panel access through TPanel::active; no codegen change.
// - tested direct returns and inverted timeout-arm order; both were neutral or
//   worse, so the natural goto cold-tail form is retained.
// - named the single-time sum and initialized calc_game_time before the ratio;
//   this recovered the best 2192-byte / 1880-diff basin while retaining the
//   original x87 ratio behavior.
// - natural outer update-interval/mode guards and explicit initializations did
//   not change the useful codegen. The current source is the clean canonical
//   reconstruction, not a compiler-only variant.
// - tested the behavior-backed rare call region: inlining the game-over and
//   auto-exit bodies changed size or shape but kept the same -6/+6 call-site
//   gap, so it was restored. Direct exit logging and a negative multiplayer
//   guard were also codegen-neutral or worse; the observed shared-exit gotos
//   remain the best source form.
//
// unresolved structural lead: original materializes an early EBX zero and
// later uses EBP=-1 before the loop, while this basin keeps EBP=0 and the
// single-time sum in a stack home. That register cascade changes the initial
// store, loop-exit polarity, and placement of the rare game-over/close tails.
// The original places those tails after the common epilogue; VC5 places them
// before the current-panel block for the remaining natural source forms.

extern "C" void __cdecl color_log(unsigned char, unsigned char, unsigned char);
extern "C" unsigned long __cdecl debug_timeGetTime(char*, int);
extern "C" long __cdecl __ftol(void);

void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* ptr);

class RGE_Static_Object;
class RGE_Game_World;
class RGE_Scenario;
class RGE_Player_Info;
class RGE_Sound;
class RGE_Map;
class RGE_Scenario_Header;
class TDrawArea;
class TSound_Driver;
class TCommunications_Handler;
class TButtonPanel;
class TDropDownPanel;
class TEditPanel;
class TInputPanel;
class TListPanel;
class TScrollBarPanel;
class TTextPanel;
class TVerticalSliderPanel;
class THorizontalSliderPanel;

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x4C];
    float* attributes;             // +0x50
    unsigned char culture;         // +0x54
    char gap_55[0x80 - 0x55];
    unsigned char game_status;    // +0x80
    char gap_81[0x130 - 0x81];
    RGE_Static_Object* selected_obj; // +0x130
    char gap_134[0x19C - 0x134];
    short sel_count;              // +0x19C
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
    virtual void set_positioning(int, long, long, long, long, long, long,
                                 long, long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
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
    virtual long handle_key_down(long, short, int, int, int);
    virtual long handle_char(long, short);
    virtual long handle_command(unsigned int, long);
    virtual long handle_user_command(unsigned int, long);
    virtual long handle_timer_command(unsigned int, long);
    virtual long handle_scroll(long, long);
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(unsigned char, long, long, int, int);
    virtual long handle_mouse_dbl_click(unsigned char, long, long, int, int);
    virtual long mouse_move_action(long, long, int, int);
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long mouse_left_hold_action(long, long, int, int);
    virtual long mouse_left_move_action(long, long, int, int);
    virtual long mouse_left_up_action(long, long, int, int);
    virtual long mouse_left_dbl_click_action(long, long, int, int);
    virtual long mouse_right_down_action(long, long, int, int);
    virtual long mouse_right_hold_action(long, long, int, int);
    virtual long mouse_right_move_action(long, long, int, int);
    virtual long mouse_right_up_action(long, long, int, int);
    virtual long mouse_right_dbl_click_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long char_action(long, short);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void get_true_render_rect(tagRECT*);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual unsigned char get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    TPanel* previousPanelValue;       // +0x04
    TPanel* previousModalPanelValue;  // +0x08
    long pnl_x;                       // +0x0C
    long pnl_y;                       // +0x10
    long pnl_wid;                     // +0x14
    long pnl_hgt;                     // +0x18
    char* panelNameValue;             // +0x1C
    TDrawArea* render_area;           // +0x20
    tagRECT clip_rect;                // +0x24
    int position_mode;                // +0x34
    int need_redraw;                  // +0x38
    TPanel* curr_child;               // +0x3C
    TPanel* parent_panel;             // +0x40
    TPanel* left_panel;               // +0x44
    TPanel* top_panel;                // +0x48
    TPanel* right_panel;              // +0x4C
    TPanel* bottom_panel;             // +0x50
    void* node;                       // +0x54
    void* first_child_node;           // +0x58
    void* last_child_node;            // +0x5C
    TPanel* tab_prev_panel;            // +0x60
    TPanel* tab_next_panel;            // +0x64
    int mouse_captured;               // +0x68
    int active;                       // +0x6C
    int visible;                      // +0x70
    int tab_stop;                     // +0x74
    int have_focus;                   // +0x78
    int overlapping_children;          // +0x7C
    int handle_mouse_input;            // +0x80
    int just_drawn;                   // +0x84
    void* clip_rgn;                   // +0x88
    tagRECT render_rect;              // +0x8C
    long left_border;                 // +0x9C
    long top_border;                  // +0xA0
    long right_border;                // +0xA4
    long bottom_border;               // +0xA8
    long min_wid;                     // +0xAC
    long max_wid;                     // +0xB0
    long min_hgt;                     // +0xB4
    long max_hgt;                     // +0xB8
    long mouse_hold_interval;         // +0xBC
    long mouse_move_tolerance;        // +0xC0
    long mouse_down_x;                // +0xC4
    long mouse_down_y;                // +0xC8
    int mouse_down_ctrl;              // +0xCC
    int mouse_down_shift;             // +0xD0
    unsigned long mouse_down_time;    // +0xD4
    int error_code;                   // +0xD8
    int z_order;                      // +0xDC
    int display_changed_count;        // +0xE0
    long help_string_id;              // +0xE4
    long help_page_id;                // +0xE8
    unsigned char mouse_action;       // +0xEC
    unsigned char mouse_down_button;  // +0xED
    unsigned char panel_type;         // +0xEE
    unsigned char color;              // +0xEF
    unsigned char fill_in_background; // +0xF0
    unsigned char clip_to_parent;     // +0xF1
    unsigned char draw_rect2_flag;    // +0xF2
    unsigned char need_restore;       // +0xF3

    void set_curr_child(TPanel* child);
    int get_focus();
    void release_mouse();
};

class RGE_View : public TPanel {
public:
    char gap_F4[0x360 - 0xF4];

    virtual int pick_through_fog(RGE_Static_Object*);
    virtual int pick_weight(RGE_Static_Object*, int);
    virtual int start_scroll_view(unsigned char, long, long, int, int);
    virtual int handle_scroll_view(long, long);
    virtual void end_scroll_view();
    virtual int do_paint(long, long, long, long, int);

    void set_selection_area(long left, long top, long right, long bottom);
};

class RGE_Main_View : public RGE_View {
public:
    char gap_360[0x20];
    virtual void draw_multi_object_outline();
    virtual int command_place_object(long, long, int);
    virtual int command_make_do(long, long, int, short);
    virtual int command_make_move(long, long);
    virtual int command_make_work(long, long);
    virtual int command_place_multi_object(long, long, long, long, int);
};

class TRIBE_Main_View : public RGE_Main_View {
};

class TMessagePanel : public TPanel {
public:
    void remove_message();
};

class TTextPanel : public TPanel {
public:
    virtual ~TTextPanel();
    virtual void set_text(char**, short);
    virtual void set_text(long);
    virtual void set_text(char*);
    virtual void set_bevel_info(int, int, int, int, int, int, int);
    char gap_F4[0x188 - 0xF4];
};

class TRIBE_Panel_Object : public TPanel {
public:
    void set_object(RGE_Static_Object* object);
};

class TSound_Driver;

class TDigital {
public:
    TSound_Driver* sound_system;  // +0x00
    TDigital* owner;              // +0x04
    unsigned char loaded;         // +0x08
    unsigned char failed;         // +0x09
    char sound_file[13];          // +0x0A
    unsigned char pad_17;         // +0x17
    long resource_id;             // +0x18
    long volume;                  // +0x1C
    unsigned long pitch;          // +0x20
    long pan;                     // +0x24
    int loop;                     // +0x28
    unsigned char* wave_data;     // +0x2C
    void* wave_info;              // +0x30
    void* sound_buffer;           // +0x34
    unsigned long data_size;      // +0x38

    TDigital(TSound_Driver* driver, char* file, long resource_id);
    ~TDigital();
    int load(char* name, long param);
    int play();
};

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(void*);
    virtual unsigned char data_load_terrain_tables(char*);
    virtual unsigned char data_load_players(char*);
    virtual unsigned char data_load_objects(char*);
    virtual unsigned char data_load_sounds(char*);
    virtual unsigned char data_load_color_tables(char*);
    virtual unsigned char data_load_sprites(char*);
    virtual void data_load_players_type(short, short, void*);
    virtual void data_load_effects(char*);
    virtual void data_load_map(char*, char*, char*, char*, short, short, short,
                               RGE_Sound**, char*);
    virtual void data_load_random_map(char*, char*, char*, char*);
    virtual unsigned char init_player_type(int, short, unsigned char);
    virtual unsigned char init_player(int);
    virtual void load_player(int, unsigned char, short);
    virtual void color_table_init(int);
    virtual void terrain_tables_init(int);
    virtual void init_sounds(int, TSound_Driver*);
    virtual void init_sprites(int);
    virtual void map_init(int, TSound_Driver*);
    virtual void effects_init(int);
    virtual void master_player_init(int);
    virtual void command_init(int, TCommunications_Handler*);
    virtual void world_init(int, TSound_Driver*, TCommunications_Handler*);
    virtual void setup_gaia();
    virtual void setup_players(RGE_Player_Info*);
    virtual unsigned char new_random_game(RGE_Player_Info*);
    virtual void save(int);
    virtual void scenario_make_player(short, unsigned char, unsigned char,
                                      unsigned char, char*);
    virtual void scenario_make_map(int);
    virtual unsigned char load_scenario(RGE_Player_Info*);
    virtual unsigned char load_scenario(char*, RGE_Player_Info*);
    virtual void load_scenario1(int, RGE_Player_Info*);
    virtual void load_scenario2(int, RGE_Player_Info*);
    virtual void load_scenario3(int, RGE_Player_Info*);
    virtual void load_scenario4(int, RGE_Player_Info*);
    virtual void load_scenario5(int, RGE_Player_Info*);
    virtual void load_scenario6(int, RGE_Player_Info*);
    virtual void load_scenario7(int, RGE_Player_Info*);
    virtual void load_scenario8(int, RGE_Player_Info*);
    virtual void logStatus(void*, int);
    virtual ~RGE_Game_World();
    virtual void setup_player_colors();
    virtual void setup_player_colors(RGE_Player_Info*);
    virtual unsigned char data_load(char*, char*);
    virtual unsigned char init(char*, TSound_Driver*, TCommunications_Handler*);
    virtual void turn_sound_off();
    virtual void del_game_info();
    virtual unsigned char update();
    virtual unsigned char get_game_state();
    virtual unsigned char check_game_state();
    virtual unsigned char load_world(int);
    virtual unsigned char load_game(char*);
    virtual unsigned char new_game(RGE_Player_Info*, int);
    virtual unsigned char new_scenario(RGE_Player_Info*, int);
    virtual unsigned char save_game(char*);
    virtual void base_save(char*);
    virtual void base_save(int);
    virtual unsigned char save_scenario(char*);
    virtual RGE_Scenario* get_scenario_info(char*);
    virtual void pause(unsigned char);
    virtual void scenario_init(RGE_Game_World*);
    virtual void scenario_init(int, RGE_Game_World*);
    virtual int addObject(RGE_Static_Object*);
    virtual int removeObject(int);

    unsigned long world_time;         // +0x04
    unsigned long old_world_time;     // +0x08
    unsigned long world_time_delta;   // +0x0C
    float timer;                       // +0x10
    unsigned long old_time;            // +0x14
    float game_speed;                  // +0x18
    unsigned char temp_pause;          // +0x1C
    unsigned char game_state;          // +0x1D
    unsigned char game_end_condition;  // +0x1E
    unsigned char gap_1F;              // +0x1F
    char gap_20[0x3C - 0x20];
    short player_num;                  // +0x3C
    unsigned char gap_3E[2];           // +0x3E
    RGE_Player** players;              // +0x40
    char gap_44[0x7C - 0x44];
    short curr_player;                 // +0x7C
    unsigned char gap_7E[2];
};

class TRIBE_World : public RGE_Game_World {
public:
    void* tech;                         // +0x104
    int victory_type;                   // +0x108
    int artifact_count;                 // +0x10C
    int ruin_count;                     // +0x110
    unsigned char countdown_victory;    // +0x114
    unsigned char gap_115[3];           // +0x115
    float countdown_clock;              // +0x118
    unsigned char score_displayed;      // +0x11C
    unsigned char controllingComputerPlayer; // +0x11D
    unsigned char gap_11E[2];           // +0x11E
    int sent_zone_score;                // +0x120

    void send_zone_score_info();
};

class TCommunications_Speed {
public:
    char gap_00[0x1BC];
    unsigned long PlayerAvgFramesMsec[8];  // +0x1BC
};

class TCommunications_Handler {
public:
    char gap_00[0x14D4];
    TCommunications_Speed* Speed;     // +0x14D4
    int WhoAmI();
};

class RGE_Prog_Info {
public:
    char gap_00[0x8A8];
    int use_sound;                    // +0x8A8
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int mode);              // slot 3 (+0xC)
    virtual void set_game_mode(int mode, int value);   // slot 4 (+0x10)

    char gap_04[8];
    RGE_Prog_Info* prog_info;         // +0x0C
    char gap_10[0x50];
    TSound_Driver* sound_system;      // +0x60
    char gap_64[0x1B0 - 0x64];
    int prog_mode;                    // +0x1B0
    char gap_1B4[0xA24 - 0x1B4];

    int multiplayerGame();
    unsigned long get_last_single_time(int i);
    int get_last_world_update_count();
    unsigned long get_last_time(int i);
    void set_last_single_time(int i, unsigned long v);
    void add_to_timing(int index, unsigned long value);
    void increment_world_update_count();
    RGE_Player* get_player();
    int get_paused();
    void set_map_visible(int param);
    void set_map_fog(int param);
    void close();
    void draw_window();
    void close_game_screens(int param);
    void do_game_over();
};

class TRIBE_Game : public RGE_Base_Game {
public:
    char gap_A24[0xE60 - 0xA24];
    unsigned long auto_exit_time;       // +0xE60
};

class TPanelSystem {
public:
    TPanel* currentPanel();
    TPanel* mouseOwner();
    TPanel* panel(char* name);
    int setCurrentPanel(char* name, int mode);
};

extern RGE_Base_Game* rge_base_game;
extern TPanelSystem panel_system;
extern int start_paused;

#define comm (*(TCommunications_Handler**)0x0062C4C0)
#define out_of_sync2 (*(int*)0x0062C564)
#define multi_updates (*(int*)0x00586318)

#define s_scr_game_cpp ((const char*)0x58637C)
#define s_Game_Screen ((const char*)0x5842CC)
#define s_Send_Quick_Message_Dialog ((const char*)0x584458)
#define s_Help_Dialog ((const char*)0x58432C)
#define s_won_wav ((const char*)0x5863AC)
#define s_lost_wav ((const char*)0x5863A0)

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x478 - 0xF4];
    virtual void draw_background(int);
    virtual void set_ideal_size(long, long);
    virtual int create_button(TPanel*, TButtonPanel**, long, long, long,
                               long, long, long, long, long, long);
    virtual int create_button(TPanel*, TButtonPanel**, char*, char*, long,
                               long, long, long, long, long, long);
    virtual int create_check_box(TPanel*, TButtonPanel**, long, long, long,
                                 long, long, long);
    virtual int create_radio_button(TPanel*, TButtonPanel**, long, long, long,
                                    long, long, long);
    virtual int create_text(TPanel*, TTextPanel**, int, long, long, long,
                            long, long, int, int, int);
    virtual int create_text(TPanel*, TTextPanel**, char**, long, long, long,
                            long, long, long, int, int);
    virtual int create_text(TPanel*, TTextPanel**, char*, long, long, long,
                            long, long, int, int, int);
    virtual int create_input(TPanel*, TInputPanel**, char*, short, int, long,
                             long, long, long, long);
    virtual int create_edit(TPanel*, TEditPanel**, char*, short, int, long,
                            long, long, long, long, int, int);
    virtual int create_drop_down(TPanel*, TDropDownPanel**, long, long, long,
                                 long, long, long, long);
    virtual int create_list(TPanel*, TListPanel**, long, long, long, long,
                            long);
    virtual int create_scrollbar(TPanel*, TScrollBarPanel*, TTextPanel*, long,
                                 long, long, long, long);
    virtual int create_auto_scrollbar(TScrollBarPanel**, TTextPanel*, long);
    virtual int create_vert_slider(TPanel*, TVerticalSliderPanel**, long, long,
                                   long, long, long, long, long);
    virtual int create_horz_slider(TPanel*, THorizontalSliderPanel**, long,
                                   long, long, long, long, long, long);
    virtual void position_panel(TPanel*, long, long, long, long);
};

class TScreenPanel : public TEasy_Panel {
};

class TRIBE_Screen_Game : public TScreenPanel {
public:
    char* game_screen_pic;             // +0x478
    char* button_border1_pic;          // +0x47C
    char* button_other_pic;            // +0x480
    char* button_border2_pic;           // +0x484
    char* button_border3_pic;           // +0x488
    char* button_cmd_pic;              // +0x48C
    char* button_tech_pic;             // +0x490
    char* button_unit_pic;             // +0x494
    char* button_bldg_pics[5];          // +0x498
    char* more_cancel_pic;              // +0x4AC
    short more_frame;                   // +0x4B0
    short cancel_frame;                 // +0x4B2
    short unselect_frame;               // +0x4B4
    unsigned char gap_4B6[2];           // +0x4B6
    TRIBE_Main_View* main_view;         // +0x4B8
    TRIBE_Main_View* map_view;          // +0x4BC
    void* inven_panel;                  // +0x4C0
    TRIBE_Panel_Object* object_panel;   // +0x4C4
    void* button_panel[17];             // +0x4C8
    TMessagePanel* text_line_panel;     // +0x50C
    TTextPanel* quit_message_panel;     // +0x510
    char gap_514[0x540 - 0x514];
    TPanel* pop_panel;                  // +0x540
    TMessagePanel* message_panel;       // +0x544
    TMessagePanel* message_panel2;      // +0x548
    TMessagePanel* message_panel3;      // +0x54C
    TMessagePanel* message_panel4;      // +0x550
    TMessagePanel* message_panel5;      // +0x554
    TMessagePanel* message_panel6;      // +0x558
    char gap_55C[0x584 - 0x55C];
    TTextPanel* pause_text;             // +0x584
    TTextPanel* fps_panel;              // +0x588
    TMessagePanel* score_panel[8];      // +0x58C
    char gap_5AC[0x5B4 - 0x5AC];
    TRIBE_World* world;                 // +0x5B4
    unsigned long update_interval;    // +0x5B8
    unsigned long last_update_time;   // +0x5BC
    unsigned long map_redraw_interval; // +0x5C0
    unsigned long last_map_redraw_time; // +0x5C4
    RGE_Static_Object* game_obj;      // +0x5C8
    short sel_count;                  // +0x5CC
    unsigned char gap_5CE[0x710 - 0x5CE];
    int save_age;                     // +0x710
    int save_culture;                 // +0x714
    long save_screen_width;           // +0x718
    unsigned long game_over_time;     // +0x71C
    int showing_game_over;            // +0x720
    int chat_line;                    // +0x724
    unsigned long view_interval;      // +0x728
    unsigned long last_view_time;     // +0x72C
    int player_quit;                  // +0x730
    unsigned char gap_734[0x7A4 - 0x734];
    int reset_after_update;           // +0x7A4
    unsigned long score_interval;     // +0x7A8
    unsigned long last_score_time;    // +0x7AC
    int watch_mode;                   // +0x7B0
    int game_ended;                   // +0x7B4
    TDigital* game_over_sound;        // +0x7B8

    void handle_game_update();
    void command_unselect();
    void command_view_selected();
    void reset_clocks();
    void object_changed();
    void age_changed();
    void reset_score_display();
    void command_cancel();
};

void TRIBE_Screen_Game::handle_game_update(void)
{
    unsigned long t;
    unsigned long now;
    unsigned char update_flag;
    int mode;
    int calc_game_time;
    int update_counter;
    int loop_i;
    int i;

    update_flag = 0;
    update_counter = 0;
    color_log(0x24, 0x24, 5);

    t = debug_timeGetTime((char*)s_scr_game_cpp, 0x63F);
    if (t - this->last_update_time >= this->update_interval) {
        mode = rge_base_game->prog_mode;
        if ((char)mode != 6) {
            color_log(0x24, 0x32, 5);
            if (rge_base_game->multiplayerGame()) {
        unsigned long st2 = rge_base_game->get_last_single_time(2);
        unsigned long sum = st2 + rge_base_game->get_last_single_time(3);
        unsigned long per;

        if (rge_base_game->get_last_world_update_count() == 0) {
            per = 1;
        } else {
            unsigned long wc2 = rge_base_game->get_last_world_update_count();
            unsigned long lt = rge_base_game->get_last_time(1);
            per = lt / wc2;
            if (per == 0) {
                per = 1;
            }
        }
        {
            int who = comm->WhoAmI();
            unsigned long avg = comm->Speed->PlayerAvgFramesMsec[who];
            calc_game_time = 2;
            if (multi_updates == 0 || avg < 0x43 || avg > 0x7D ||
                (float)per / (float)(int)sum > 2.0f) {
                calc_game_time = 1;
            }
        }
        rge_base_game->set_last_single_time(2, 0);
        rge_base_game->set_last_single_time(3, 0);
    } else {
        calc_game_time = 1;
    }

    loop_i = 0;
    if (calc_game_time > 0) {
        do {
            color_log(0x24, 0x4C, 5);
            color_log(0x24, 0x24, 1);
            now = debug_timeGetTime((char*)s_scr_game_cpp, 0x692);
            if (start_paused) {
                update_flag = 0;
                rge_base_game->set_prog_mode(6);
            } else if (this->game_ended == 0) {
                update_flag = this->world->update();
                if (out_of_sync2) {
                    return;
                }
                if (update_flag == 1) {
                    this->game_ended = 1;
                    this->main_view->end_scroll_view();
                    this->main_view->set_selection_area(-1, -1, -1, -1);
                    rge_base_game->set_game_mode(0, 0);
                    this->command_unselect();
                    if (rge_base_game->multiplayerGame()) {
                        this->world->send_zone_score_info();
                    }
                }
            } else {
                update_flag = 1;
            }
            if (out_of_sync2) {
                return;
            }

            this->last_update_time = debug_timeGetTime((char*)s_scr_game_cpp, 0x6BB);
            if (this->world->world_time_delta != 0) {
                rge_base_game->add_to_timing(1, this->last_update_time - now);
                rge_base_game->increment_world_update_count();
            }
            color_log(0x24, 0xBA, 1);

            if (this->reset_after_update != 0) {
                this->reset_clocks();
                this->reset_after_update = 0;
            }
            if (this->watch_mode != 0) {
                this->command_view_selected();
            }
            {
                RGE_Player* p = rge_base_game->get_player();
                if (this->game_obj != p->selected_obj ||
                    this->sel_count != rge_base_game->get_player()->sel_count) {
                    this->object_panel->set_object(
                        rge_base_game->get_player()->selected_obj);
                    this->object_changed();
                }
            }
            color_log(0x24, 0x54, 5);
            if (start_paused == 0 &&
                (update_flag == 1 ||
                 this->world->players[this->world->curr_player]->game_status == 2 ||
                 this->player_quit == 1)) {
                if ((char)mode != 5) {
                    color_log(0x24, 0x45, 5);
                    this->command_cancel();
                    this->command_unselect();
                    this->text_line_panel->remove_message();
                    this->message_panel->remove_message();
                    this->message_panel2->remove_message();
                    this->message_panel3->remove_message();
                    this->message_panel4->remove_message();
                    this->message_panel5->remove_message();
                    this->message_panel6->remove_message();
                    rge_base_game->set_prog_mode(5);
                    if (panel_system.mouseOwner() != 0) {
                        panel_system.mouseOwner()->release_mouse();
                    }
                    panel_system.setCurrentPanel((char*)s_Game_Screen, 0);
                    this->set_curr_child(this->main_view);
                    rge_base_game->close_game_screens(0);
                    this->pause_text->set_active(1);
                    {
                        RGE_Player* p = rge_base_game->get_player();
                        if (p->game_status == 1) {
                            this->pause_text->set_text((long)0x232C);
                        } else {
                            this->pause_text->set_text((long)0x232D);
                        }
                    }
                    this->main_view->set_redraw(1);
                    if (rge_base_game->prog_info->use_sound != 0 &&
                        rge_base_game->sound_system != 0) {
                        TDigital* old = this->game_over_sound;
                        if (old != 0) {
                            old->~TDigital();
                            operator delete(old);
                        }
                        {
                            RGE_Player* p = rge_base_game->get_player();
                            if (p->game_status == 1) {
                                this->game_over_sound =
                                    new TDigital(rge_base_game->sound_system,
                                                 (char*)s_won_wav, 0xC490);
                            } else {
                                this->game_over_sound =
                                    new TDigital(rge_base_game->sound_system,
                                                 (char*)s_lost_wav, 0xC491);
                            }
                        }
                        if (this->game_over_sound != 0) {
                            this->game_over_sound->load(0, -1);
                            this->game_over_sound->play();
                        }
                    }
                    this->game_over_time = debug_timeGetTime((char*)s_scr_game_cpp, 0x72C);
                    this->showing_game_over = 1;
                } else {
                    if (this->showing_game_over != 0) {
                        if (debug_timeGetTime((char*)s_scr_game_cpp, 0x734) -
                                               this->game_over_time > 5000) {
                            color_log(0x24, 0x16, 5);
                            this->showing_game_over = 0;
                        if (rge_base_game->multiplayerGame()) {
                            if (rge_base_game->get_paused() == 0) {
                                this->pause_text->set_active(0);
                            }
                                rge_base_game->set_map_visible(1);
                                rge_base_game->set_map_fog(0);
                                this->main_view->set_redraw(2);
                                this->map_view->set_redraw(2);
                                this->quit_message_panel->set_active(1);
                                this->pop_panel->set_active(0);
                        } else {
                            goto game_over;
                        }
                        }
                    } else {
                        for (i = 1; i < this->world->player_num; i++) {
                            update_flag =
                                this->world->players[i]->game_status;
                            if (update_flag == 0) {
                                break;
                            }
                        }
                    }
                }
            }
            if (this->world->world_time_delta != 0 &&
                ((TRIBE_Game*)rge_base_game)->auto_exit_time != 0 &&
                (unsigned long)this->world->world_time >=
                    (unsigned long)((TRIBE_Game*)rge_base_game)->auto_exit_time) {
                goto L_close;
            }
            update_counter += this->world->world_time_delta;
            loop_i++;
        } while (loop_i < calc_game_time);
    }
        }
    }

    if (panel_system.currentPanel() != this) {
        goto L_exit;
    }
    color_log(0x16, 0x4C, 5);
    now = debug_timeGetTime((char*)s_scr_game_cpp, 0x79C);
    if (update_counter != 0) {
        RGE_Player* p = rge_base_game->get_player();
        if ((int)p->attributes[6] != this->save_age) {
            this->age_changed();
        }
        if (this->score_panel[0] != 0 &&
            this->score_panel[0]->active != 0 &&
            now - this->last_score_time >= this->score_interval) {
            this->reset_score_display();
            this->last_score_time = debug_timeGetTime((char*)s_scr_game_cpp, 0x7A8);
        }
    }
    if (this->main_view->get_focus() != 0 ||
        this->curr_child == panel_system.panel((char*)s_Send_Quick_Message_Dialog) ||
        this->curr_child == panel_system.panel((char*)s_Help_Dialog)) {
        color_log(0x16, 0x54, 5);
        if (update_counter != 0 ||
            now - this->last_view_time >= this->view_interval) {
            this->main_view->set_redraw(1);
            this->last_view_time = now;
        }
        if (update_counter != 0 &&
            now - this->last_map_redraw_time >= this->map_redraw_interval) {
            this->map_view->set_redraw(1);
            this->last_map_redraw_time = now;
        }
        color_log(0x16, 0x24, 5);
        if (this->main_view->need_redraw != 0) {
            rge_base_game->draw_window();
        }
    }

L_exit:
    color_log(0x24, 0x5F, 5);
    return;

game_over:
    this->main_view->end_scroll_view();
    this->main_view->set_selection_area(-1, -1, -1, -1);
    rge_base_game->set_game_mode(0, 0);
    this->command_unselect();
    rge_base_game->do_game_over();
    goto L_exit;

L_close:
    rge_base_game->close();
    goto L_exit;
}
