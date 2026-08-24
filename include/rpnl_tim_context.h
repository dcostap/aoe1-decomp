#ifndef AOE1_RPNL_TIM_CONTEXT_H
#define AOE1_RPNL_TIM_CONTEXT_H

// Recovered rpnl_tim.cpp translation-unit surface.
// TPanel is 0xF4 bytes; RGE_Panel_Time adds five fields at +0xF4.

#include <windows.h>

class TDrawArea;
class TPanel;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long,
                       unsigned char);
    virtual void set_rect(RECT);
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
    virtual void draw_rect(RECT*);
    virtual void draw_offset(long, long, RECT*);
    virtual void draw_rect2(RECT*);
    virtual void draw_offset2(long, long, RECT*);
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
    virtual void get_true_render_rect(RECT*);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual unsigned char get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    char gap_04[0x1C];
    TDrawArea* render_area;       // +0x20
    char gap_24[0x1C];
    TPanel* parent_panel;         // +0x40
    char gap_44[0x28];
    int active;                   // +0x6C
    int visible;                  // +0x70
    char gap_74[0x0C];
    int field_80;                 // +0x80
    char gap_84[4];
    void* clip_rgn;               // +0x88
    RECT render_rect;             // +0x8C
    char gap_9C[0x3C];
    int field_D8;                 // +0xD8
    char gap_DC[4];
    int display_changed_count;    // +0xE0
    char gap_E4[0x10];

    TPanel();
    char* get_string(int id);
};

typedef char rpnl_tim_tpanel_size_check[(sizeof(TPanel) == 0xF4) ? 1 : -1];

class TDrawArea {
public:
    char gap_00[0x38];
    HDC DrawDc;                   // +0x38
    void* GetDc(const char* name);
    void ReleaseDc(const char* name);
};

class RGE_Game_World {
public:
    char gap_00[4];
    unsigned long world_time;     // +0x04
    char gap_08[0x0C];
    unsigned long old_time;       // +0x14
    float game_speed;             // +0x18
    char gap_1C[0x20];
    short player_num;             // +0x3C
    char pad_3E[2];
    void** players;               // +0x40
};

class RGE_Base_Game {
public:
    char gap_00[0x48];
    void* draw_system;            // +0x48
    char gap_4C[0x170];
    int paused;                   // +0x1BC
    char gap_1C0[0x234];
    RGE_Game_World* world;        // +0x3F4

    int get_paused();
    void get_countdown_timer(long player_index, long& result);
};

extern RGE_Base_Game* rge_base_game;

class RGE_Panel_Time : public TPanel {
public:
    void* font;                   // +0xF4
    long game_time;               // +0xF8
    long last_game_time;          // +0xFC
    long old_time;                // +0x100
    long real_time;               // +0x104

    virtual ~RGE_Panel_Time();
    virtual void draw();
    virtual long handle_idle();

    RGE_Panel_Time(TDrawArea* draw_area, TPanel* parent, void* font_arg);
};

typedef char rpnl_tim_panel_size_check[
    (sizeof(RGE_Panel_Time) == 0x108) ? 1 : -1];

#endif
