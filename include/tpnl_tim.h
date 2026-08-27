#ifndef AOE1_TPNL_TIM_H
#define AOE1_TPNL_TIM_H

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

struct HRGN__;
typedef HRGN__* HRGN;

class TDrawSystem {
public:
    char gap_00[0x18];
    long width;
};

class PlayerCivInfo {
public:
    char gap_00[0x26];
    short civ_id;
};

class RGE_Player {
public:
    char gap_00[0x4A];
    short player_id;
    char gap_4C[0xBC];
    PlayerCivInfo* civ_info;
    char gap_10C[0x734];
    float ruin_held_time;
    float artifact_held_time;
};

class RGE_Game_World {
public:
    char gap_00[0x4];
    unsigned long world_time;
    char gap_08[0x10];
    float game_speed;
    char gap_1C[0x24];
    RGE_Player** players;
    char gap_44[0xD4];
    float field_118;
};

class RGE_Base_Game {
public:
    char gap_00[0x1E4];
    void* font_ptr;
    char gap_1E8[0x20C];
    RGE_Game_World* world;

    void* get_font(int index);
    void get_countdown_timer(int player_id, long* out_value);
};

extern RGE_Base_Game* rge_base_game;

class TDrawArea {
public:
    TDrawSystem* DrawSystem;
    char gap_04[0x14];
    long width;
    long height;
    char gap_20[0x18];
    void* DrawDc;
    void* DrawSurface;
    char gap_40[0x14];
    long Width;
    long Height;

    TDrawArea(char* name, int flags);
    ~TDrawArea();
    int Init(TDrawSystem* system, long width, long height, int a5, int a6);
    void PtrClear(tagRECT* rect, int color);
    void* GetDc(char* name);
    void ReleaseDc(char* name);
    void SetTrans(int enabled, unsigned char color);
    void Copy(TDrawArea* source, long x, long y, tagRECT* rect, int mode);
    void SetClipRect(tagRECT* rect);

    char gap_5C[0xA4];
};

typedef char tdrawarea_size_check[(sizeof(TDrawArea) == 0x100) ? 1 : -1];

class TPanel {
public:
    virtual ~TPanel();
    TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long,
                       unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                 long, long, TPanel*, TPanel*, TPanel*,
                                 TPanel*);
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
    virtual void get_true_render_rect(tagRECT&);
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
    HRGN clip_rgn;
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

class TRIBE_Panel_Time : public TPanel {
public:
    void* font;
    unsigned int color1;
    unsigned int color2;
    int clock_type;
    int old_clock_type;
    int clock_format;
    int old_clock_format;
    int player_id;
    RGE_Game_World* world;
    RGE_Player* player;
    unsigned long start_real_time;
    unsigned long current_display_value;
    unsigned long last_display_value;
    unsigned long display_time;
    int old_display_time;
    HRGN image_clip_region;
    TDrawArea* image_buffer;
    tagRECT image_rect;
    tagRECT used_image_rect;
    tagRECT used_screen_rect;
    int image_text_active;
    long last_ib_width;
    long last_ib_height;

    TRIBE_Panel_Time(TDrawArea*, TPanel*);
    virtual ~TRIBE_Panel_Time();
    void set_rect(long, long, long, long);
    void startup();
    void set_clock_type(int, int);
    int get_clock_type();
    int get_player_id();
    virtual void draw();
    virtual void get_true_render_rect(tagRECT&);
    virtual long handle_idle();

protected:
    int render_to_image_buffer();
};

typedef char tribe_panel_time_size_check[
    (sizeof(TRIBE_Panel_Time) == 0x174) ? 1 : -1];

extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" __declspec(dllimport) int __stdcall DeleteObject(void*);
extern "C" __declspec(dllimport) HRGN __stdcall CreateRectRgn(int, int, int,
                                                                int);
extern "C" __declspec(dllimport) int __stdcall SelectClipRgn(void*, void*);
extern "C" __declspec(dllimport) void* __stdcall SelectObject(void*, void*);
extern "C" __declspec(dllimport) int __stdcall SetBkMode(void*, int);
extern "C" __declspec(dllimport) unsigned int __stdcall SetTextColor(
    void*, unsigned int);
extern "C" __declspec(dllimport) int __stdcall DrawTextA(
    void*, const char*, int, void*, unsigned int);
extern "C" __declspec(dllimport) int __stdcall SetRect(
    void*, int, int, int, int);
extern "C" unsigned long __cdecl debug_timeGetTime(const char*, int);

void* operator new(unsigned int size);
void operator delete(void* ptr);

extern char s_time_message_panel[];
extern const char s_tpnl_tim_draw[];
extern const char s_tpnl_tim_render_to_image_buffer[];
extern const char s_clock_hms_fmt[];

#endif
