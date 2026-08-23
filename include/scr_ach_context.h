#ifndef SCR_ACH_CONTEXT_H
#define SCR_ACH_CONTEXT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea;
class DrawSurface;
class TShape;
class TTextPanel;
class TButtonPanel;
class TScrollBarPanel;
class Time_Line_Panel;
class RGE_Player;
class RGE_Game_World;
class RGE_Scenario;
class RGE_Civilization;
class RGE_Victory_Conditions;

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

    TPanel* previousPanelValue;
    TPanel* previousModalPanelValue;
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panelNameValue;
    union {
        TDrawArea* render_area;
        DrawSurface* draw_surface;
    };
    tagRECT clip_rect;
    int position_mode;
    int need_redraw;
    TPanel* curr_child;
    TPanel* parent_panel;
    TPanel* left_panel;
    TPanel* top_panel;
    TPanel* right_panel;
    TPanel* bottom_panel;
    void* node;
    void* first_child_node;
    void* last_child_node;
    TPanel* tab_prev_panel;
    TPanel* tab_next_panel;
    int mouse_captured;
    int active;
    int visible;
    int tab_stop;
    int have_focus;
    int overlapping_children;
    int handle_mouse_input;
    int just_drawn;
    void* clip_rgn;
    tagRECT render_rect;
    long left_border;
    long top_border;
    long right_border;
    long bottom_border;
    long min_wid;
    long max_wid;
    long min_hgt;
    long max_hgt;
    long mouse_hold_interval;
    long mouse_move_tolerance;
    long mouse_down_x;
    long mouse_down_y;
    int mouse_down_ctrl;
    int mouse_down_shift;
    unsigned long mouse_down_time;
    union {
        int error_code;
        int field_D8;
    };
    int z_order;
    int display_changed_count;
    long help_string_id;
    long help_page_id;
    unsigned char mouse_action;
    unsigned char mouse_down_button;
    unsigned char panel_type;
    unsigned char color;
    unsigned char fill_in_background;
    unsigned char clip_to_parent;
    unsigned char draw_rect2_flag;
    unsigned char need_restore;

    char* panelName();
    long xPosition();
    long yPosition();
    char* get_string(int id);
    void set_curr_child(TPanel* child);
    void vf_0C4(int first, int second);
    void delete_panel(TPanel** panel);
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x22C];
    unsigned char desc[6];
    char gap_326[0x152];
    virtual ~TEasy_Panel();
    virtual void set_ideal_size(long width, long height);
    virtual int create_button(TPanel* parent, TButtonPanel** output, int lang,
                              int a4, int x, int y, int w, int h,
                              int font, int center_h, int center_v);
    virtual int create_text(TPanel* parent, TTextPanel** output, int lang,
                            int x, int y, int w, int h, int font,
                            int center_h, int center_v, int word_wrap);
    virtual int create_text(TPanel* parent, TTextPanel** output, char* text,
                            int x, int y, int w, int h, int font,
                            int center_h, int center_v, int word_wrap);
    virtual int create_auto_scrollbar(TScrollBarPanel** output,
                                      TTextPanel* text, int param);
    virtual int create_edit(TPanel*, void*, char*, short, int, int, int, int,
                            int, int, int, int);
    virtual int create_drop_down(TPanel*, void*, int, int, int, int, int, int,
                                 int);
    virtual int create_list(TPanel*, void*, int, int, int, int, int);
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    long action(TPanel*, long, unsigned long, unsigned long);
    void popupYesNoDialog(char*, void*, int, int);
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char* name);
    virtual ~TScreenPanel();
    int setup(TDrawArea* draw_area, char* info_file, long info_id, int param);
    virtual void draw();
    virtual long handle_idle();
};

class TTextPanel : public TPanel {
public:
    virtual ~TTextPanel();
    virtual void set_rect(long, long, long, long);
    virtual void set_active(int);
    virtual void draw();
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void set_text(char*);
    virtual void set_text(long);
    virtual void set_text(char**, short);
    virtual void set_bevel_info(int, int, int, int, int, int, int);
    virtual void setText(char* text);
    virtual void textExtra(int, int, int, int, int, int, int);

    void* list;
    short num_lines;
    short draw_lines;
    short top_line;
    short bot_line;
    short cur_line;
    short cur_col;
    void* font;
    long font_wid;
    long font_hgt;
    long vert_align;
    long horz_align;
    int word_wrap;
    long text_style;
    unsigned long text_color1;
    unsigned long text_color2;
    unsigned long highlight_text_color1;
    unsigned long highlight_text_color2;
    TScrollBarPanel* scbar_panel;
    int auto_scbar;
    short fixed_len;
    char gap_13A[2];
    long text_wid;
    long text_hgt;
    void* back_pic;
    short back_pic_wid;
    short back_pic_hgt;
    int fill_back;
    unsigned char back_color;
    char gap_151[3];
    int outline;
    unsigned char outline_color;
    char gap_159[3];
    int sorted;
    long second_column_pos;
    long full_width;
    long scbar_width;
    int scbar_active;
    int bevel_type;
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;
    char gap_17A[2];
    void* clip_rgn2;
    int border_size;
    int spacer_size;

    void set_alignment(int horizontal, int vertical);
    void set_text_color(int color, int flags);
};

class TButtonPanel : public TPanel {
public:
    virtual ~TButtonPanel();
    char gap_F4[0x1A4];
    int hotkey;
    int hotkey_shift;
    virtual void vf_018(int, int, int, int, int, int, int, int);
};

class TScrollBarPanel : public TPanel {
public:
    virtual ~TScrollBarPanel();
};

class Time_Line_Panel : public TPanel {
public:
    virtual ~Time_Line_Panel();
    long create_timeline(TPanel* parent, Time_Line_Panel** output,
                         long x, long y, long w, long h, long font,
                         long a, long b, long c);
    void set_bevel_info(int type, int c1, int c2, int c3, int c4, int c5,
                        int c6);
    int set_special_events(char* name);
};

class TDrawArea {
public:
    unsigned char* Lock(char* name, int wait);
    void Unlock(char* name);
};

class DrawSurface {
public:
    void* vtbl;
    void* hwnd;
};

class TShape {
public:
    char gap_00[0x20];
    TShape(char* name, int id);
    ~TShape();
    unsigned char shape_draw(TDrawArea*, long, long, long, unsigned char,
                             unsigned char*);
};

class RGE_Civilization {
public:
    char gap_00[0x26];
    short color;
};

class RGE_Victory_Conditions {
public:
    char gap_00[0x14];
    int get_victory_points_group(unsigned char group);
    int get_attribute_id(unsigned char id);
    int get_victory_points_id(unsigned char id);
    int get_victory_points();
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x30];
    RGE_Victory_Conditions* victory_conditions;
    char gap_38[0x0C];
    char* name;
    char gap_48[8];
    float* attributes;
    char gap_54[0x2C];
    union {
        unsigned char game_status;
        unsigned char active;
    };
    char gap_81[0x87];
    RGE_Civilization* civilization;
};

class RGE_Scenario {
public:
    char* Get_scenario_name();
    char* Get_message(long id);
};

class RGE_Game_World {
public:
    virtual void data_load_world();
    unsigned long world_time;
    char gap_08[0x34];
    short player_num;
    char gap_3E[2];
    RGE_Player** players;
    char gap_44[0x18];
    RGE_Scenario* scenario;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[0x48];
    TDrawArea* draw_area;
    char gap_50[0x160];
    int prog_mode;
    char gap_1B4[0x24];
    int input_enabled;
    char gap_1DC[0x218];
    RGE_Game_World* world;
    char gap_3F8[0x608];
    int save_paused;

    RGE_Player* get_player();
    int singlePlayerGame();
    void set_paused(int paused, int non_user_pause);
    void disable_input();
    void enable_input();
    void close();
};

class TRIBE_Game : public RGE_Base_Game {
public:
    void quit_game();
    void restart_game();
};

extern int confirmed_close;
extern TRIBE_Game* rge_base_game;

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int param);
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;
extern "C" __declspec(dllimport) int __stdcall IsIconic(void* hWnd);

class TribeAchievementsScreen : public TScreenPanel {
public:
    int end_game_flag;
    int current_mode;
    int size;
    TTextPanel* title;
    TTextPanel* summary_text;
    TTextPanel* instruction;
    TTextPanel* win_loss_text;
    TTextPanel* time;
    TTextPanel* title_bar[7];
    TTextPanel* achievement_choice[5];
    TTextPanel* statistics[8][7];
    TTextPanel* player_names[8];
    TScrollBarPanel* summary_text_bar;
    TScrollBarPanel* instruction_bar;
    TScrollBarPanel* win_loss_text_bar;
    TButtonPanel* okButton;
    TButtonPanel* backButton;
    TButtonPanel* backButton2;
    TButtonPanel* timelineButton;
    TButtonPanel* aftermathButton;
    TButtonPanel* restartButton;
    TButtonPanel* close_button;
    TShape* win_decal;
    Time_Line_Panel* time_line;

    TribeAchievementsScreen(char* title_text, int end_game_flag);
    virtual ~TribeAchievementsScreen();
    void set_mode(long mode);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual void draw();
    virtual long handle_idle();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
};

#endif
