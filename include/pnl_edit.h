#ifndef AOE1_PNL_EDIT_H
#define AOE1_PNL_EDIT_H

#ifndef _WINDOWS_
typedef void* HWND;
typedef void* HMENU;
typedef void* HINSTANCE;
typedef void* HBRUSH;
typedef void* HPALETTE;
typedef void* HDC;
typedef void* HGDIOBJ;
typedef void* HRGN;
typedef unsigned long COLORREF;
typedef void* FARPROC;
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};
typedef struct tagRECT RECT;
#endif

#ifndef _WINUSER_
typedef long (__stdcall *WNDPROC)(HWND, unsigned int, unsigned int, long);
#endif

struct PanelNode;

struct TDrawSystem {
    void* Inst;
    void* Wnd;
    HPALETTE Pal;
};

struct TDrawArea {
    TDrawSystem* DrawSystem;
    void* Wnd;
    char gap_08[0x100 - 0x08];

    void Clear(tagRECT*, int);
    unsigned char* Lock(char*, int);
    void Unlock(char*);
    HDC GetDc(char*);
    void ReleaseDc(char*);
    void DrawRect(long, long, long, long, unsigned char);
    void DrawBevel(long, long, long, long, unsigned char, unsigned char);
    void DrawBevel2(long, long, long, long, unsigned char, unsigned char,
                    unsigned char, unsigned char);
    void DrawBevel3(long, long, long, long, unsigned char, unsigned char,
                    unsigned char, unsigned char, unsigned char, unsigned char);
};

typedef int PositionMode;

class TPanel {
public:
    enum RedrawMode {
        RedrawNone = 0,
        RedrawNormal = 1,
        RedrawImmediate = 2
    };

    virtual ~TPanel();
    TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(PositionMode, long, long, long, long, long, long,
                                 long, long, TPanel*, TPanel*, TPanel*, TPanel*);
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

    TPanel* previous_panel;
    TPanel* previous_modal_panel;
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panel_name;
    TDrawArea* render_area;
    tagRECT clip_rect;
    int position_mode;
    int need_redraw;
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
    int error_code;
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
};

class TEditPanel : public TPanel {
public:
    TEditPanel();
    virtual ~TEditPanel();

    HWND edit_wnd;
    short fixed_len;
    unsigned char pad_FA[2];
    char* text;
    int text_len;
    int hidden;
    HBRUSH brush;
    int stock_brush;
    WNDPROC old_sub_wnd_proc;
    unsigned long text_color1;
    unsigned long text_color2;
    unsigned long highlight_text_color1;
    unsigned long highlight_text_color2;
    unsigned long back_color;
    int format;
    HGDIOBJ font;
    int multi_line;
    tagRECT draw_rect;
    unsigned int draw_format;
    int auto_sel;
    int sel_len;
    int bevel_type;
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;
    unsigned char pad_15A[2];
    int bevel_size;
    unsigned long imc;
    int enable_ime;
    int turn_ime_on;

    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long,
                       void*, short, char*, int, int);
    long sub_wnd_proc(void*, unsigned int, unsigned int, long);
    void set_text(char*);
    void update_text();
    char* get_text();
    char* get_input_buffer();
    char* currentLine();
    virtual void set_active(int);
    virtual void set_focus(int);
    int verify_char(int);
    virtual void draw();
    virtual void paint();
    int is_blank();
    char* get_trimmed_str(char*, int);
    virtual void handle_reactivate();
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_redraw(RedrawMode);
    void set_text_color(unsigned long, unsigned long);
    void set_highlight_text_color(unsigned long, unsigned long);
    void set_back_color(void*, unsigned long, unsigned char);
    void set_bevel_info(int, int, int, int, int, int, int);
    void set_ime_info(int, int);
};

class RGE_Base_Game {
public:
    char gap_00[0x1D0];
    int windows_mouse;
    void mouse_off();
};

extern RGE_Base_Game* rge_base_game;

class TPanelSystem {
public:
    TPanel* currentPanel();
};

extern TPanelSystem panel_system;
extern int DAT_0086b240;
extern int DAT_0062c4c4;
extern unsigned int DAT_0086b244;
extern int imc_retval;

#endif
