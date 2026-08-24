#ifndef AOE1_TPNL_POP_CONTEXT_H
#define AOE1_TPNL_POP_CONTEXT_H

// Authentic declaration surface for C:\\msdev\\work\\age1_x1\\tpnl_pop.cpp.
// The owner wrapper includes source bodies in PDB line order.

#include <windows.h>
#include <stdio.h>
#include <new.h>

class TDrawArea;
class RGE_Game_World;
class RGE_Player;

class RGE_Font {
public:
    void* font_data;
};

class RGE_Base_Game {
public:
    char gap_000[0x3F4];
    RGE_Game_World* world;
    char gap_3F8[0x63C];
    int need_counts[0x100];

    RGE_Font* get_font(int id);
    RGE_Player* get_player();
};

extern RGE_Base_Game* rge_base_game;

extern "C" void __cdecl operator_delete(void* ptr);

class RGE_Game_World {
public:
    char gap_000[0x84];
    float world_time_delta_seconds;
};

class RGE_Player {
public:
    char gap_000[0x3C];
    RGE_Game_World* world;
    char gap_040[0x0A];
    union {
        short player_id;
        short field_4A;
    };
    char gap_04C[4];
    float* attributes;
};

typedef int PositionMode;
typedef int RedrawMode;
struct PanelNode;

class TDrawArea {
public:
    void* draw_sys;
    char gap_04[0x14];
    long width;
    char gap_1C[0x1C];
    HDC DrawDc;

    TDrawArea(const char* name, int param);
    ~TDrawArea();
    int Init(void* draw_sys, int width, int height, int x, int y);
    void PtrClear(RECT* rect, int color);
    void* GetDc(char* name);
    void SetClipRect(RECT* rect);
    void ReleaseDc(char* name);
    void SetTrans(int enabled, unsigned char color);
    void Copy(TDrawArea* area, long x, long y, RECT* rect, int mode);
};

class TPanel {
public:
    virtual ~TPanel();
    TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long,
                       unsigned char);
    virtual void set_rect(RECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(PositionMode, long, long, long, long, long,
                                 long, long, long, TPanel*, TPanel*, TPanel*,
                                 TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(RedrawMode);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, RedrawMode);
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
    virtual void get_true_render_rect(RECT&);
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
    TDrawArea* render_area;
    int clip_left;
    int clip_top;
    int clip_right;
    int clip_bottom;
    PositionMode position_mode;
    RedrawMode need_redraw;
    TPanel* curr_child;
    TPanel* parent_panel;
    TPanel* left_panel;
    TPanel* top_panel;
    TPanel* right_panel;
    TPanel* bottom_panel;
    PanelNode* node;
    PanelNode* first_child_node;
    PanelNode* last_child_node;
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
    HRGN clip_rgn;
    RECT render_rect;
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
    long mouse_down_ctrl;
    long mouse_down_shift;
    unsigned long mouse_down_time;
    long error_code;
    long z_order;
    long display_changed_count;
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

    char* get_string(int string_id);
};

class TRIBE_Panel_Pop : public TPanel {
public:
    void* font;
    unsigned long color1;
    unsigned long color2;
    unsigned long color3;
    int player_id;
    RGE_Game_World* world;
    union {
        RGE_Player* player;
        RGE_Player* member_10C;
    };
    int pop;
    int max_pop;
    unsigned char mode;
    unsigned char gap_119[3];
    float timer;
    HRGN image_clip_region;
    TDrawArea* ImageBuffer;
    RECT ImageRect;
    RECT UsedImageRect;
    RECT UsedScreenRect;
    int ImageTextActive;
    long LastIBWidth;
    long LastIBHeight;

    TRIBE_Panel_Pop(TDrawArea* area, TPanel* parent);
    virtual ~TRIBE_Panel_Pop();
    virtual void set_rect(long, long, long, long);
    void startup();
    int get_player_id();
    virtual void draw();
    virtual void get_true_render_rect(RECT&);
    virtual long handle_idle();

protected:
    int render_to_image_buffer();
};

#endif
