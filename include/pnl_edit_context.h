#ifndef PNL_EDIT_CONTEXT_H
#define PNL_EDIT_CONTEXT_H

struct PanelNode;
struct TDrawArea {
    void* DrawSystem;              // +0x00
    void* Wnd;                     // +0x04
    char gap_08[0x100 - 0x08];
};
typedef int PositionMode;
typedef int RedrawMode;

#ifndef _WINDOWS_
struct HWND__ { int unused; };
typedef struct HWND__ *HWND;
struct HBRUSH__ { int unused; };
typedef struct HBRUSH__ *HBRUSH;
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};
#endif

#ifndef _WINUSER_
typedef long (__stdcall *WNDPROC)(HWND, unsigned int, unsigned int, long);
#endif

// PDB-supported pnl_edit.cpp panel surface. Keep this declaration shared by
// the real pnl_edit.cpp owners. It preserves TPanel size 0xF4 and TEditPanel
// size 0x16C without adding helper state.
// Safe prefix order is 00475930, 00475690, 00475970, 00475A30, 00475AF0,
// 00475B00, 00475B10, 00475B20, and 00475B60. This order follows PDB lines.
class TPanel {
public:
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

    TPanel* previous_panel;       // +0x04
    TPanel* previous_modal_panel; // +0x08
    long pnl_x;                   // +0x0C
    long pnl_y;                   // +0x10
    long pnl_wid;                 // +0x14
    long pnl_hgt;                 // +0x18
    char* panel_name;             // +0x1C
    TDrawArea* render_area;       // +0x20
    tagRECT clip_rect;            // +0x24
    int position_mode;            // +0x34
    int need_redraw;              // +0x38
    TPanel* curr_child;           // +0x3C
    TPanel* parent_panel;          // +0x40
    TPanel* left_panel;            // +0x44
    TPanel* top_panel;             // +0x48
    TPanel* right_panel;           // +0x4C
    TPanel* bottom_panel;          // +0x50
    PanelNode* node;               // +0x54
    PanelNode* first_child_node;   // +0x58
    PanelNode* last_child_node;    // +0x5C
    TPanel* tab_prev_panel;        // +0x60
    TPanel* tab_next_panel;        // +0x64
    int mouse_captured;            // +0x68
    int active;                    // +0x6C
    int visible;                   // +0x70
    int tab_stop;                  // +0x74
    int have_focus;               // +0x78
    int overlapping_children;     // +0x7C
    int handle_mouse_input;       // +0x80
    int just_drawn;               // +0x84
    void* clip_rgn;               // +0x88
    tagRECT render_rect;           // +0x8C
    long left_border;              // +0x9C
    long top_border;               // +0xA0
    long right_border;             // +0xA4
    long bottom_border;            // +0xA8
    long min_wid;                 // +0xAC
    long max_wid;                 // +0xB0
    long min_hgt;                 // +0xB4
    long max_hgt;                 // +0xB8
    long mouse_hold_interval;     // +0xBC
    long mouse_move_tolerance;    // +0xC0
    long mouse_down_x;            // +0xC4
    long mouse_down_y;            // +0xC8
    int mouse_down_ctrl;          // +0xCC
    int mouse_down_shift;         // +0xD0
    unsigned long mouse_down_time;// +0xD4
    int error_code;               // +0xD8
    int z_order;                  // +0xDC
    int display_changed_count;    // +0xE0
    long help_string_id;          // +0xE4
    long help_page_id;            // +0xE8
    unsigned char mouse_action;   // +0xEC
    unsigned char mouse_down_button; // +0xED
    unsigned char panel_type;     // +0xEE
    unsigned char color;          // +0xEF
    unsigned char fill_in_background; // +0xF0
    unsigned char clip_to_parent; // +0xF1
    unsigned char draw_rect2_flag;// +0xF2
    unsigned char need_restore;   // +0xF3
};

class TEditPanel : public TPanel {
public:
    TEditPanel();
    virtual ~TEditPanel();

    HWND edit_wnd;                         // +0x0F4
    short fixed_len;                       // +0x0F8
    unsigned char pad_FA[2];               // +0x0FA
    char* text;                             // +0x0FC
    int text_len;                           // +0x100
    int hidden;                             // +0x104
    HBRUSH brush;                           // +0x108
    int stock_brush;                        // +0x10C
    WNDPROC old_sub_wnd_proc;              // +0x110
    unsigned long text_color1;             // +0x114
    unsigned long text_color2;             // +0x118
    unsigned long highlight_text_color1;   // +0x11C
    unsigned long highlight_text_color2;   // +0x120
    unsigned long back_color;              // +0x124
    int format;                             // +0x128
    void* font;                             // +0x12C
    int multi_line;                         // +0x130
    tagRECT draw_rect;                      // +0x134
    unsigned int draw_format;              // +0x144
    int auto_sel;                           // +0x148
    int sel_len;                            // +0x14C
    int bevel_type;                         // +0x150
    unsigned char bevel_color1;            // +0x154
    unsigned char bevel_color2;            // +0x155
    unsigned char bevel_color3;            // +0x156
    unsigned char bevel_color4;            // +0x157
    unsigned char bevel_color5;            // +0x158
    unsigned char bevel_color6;            // +0x159
    unsigned char pad_15A[2];               // +0x15A
    int bevel_size;                         // +0x15C
    unsigned long imc;                      // +0x160
    int enable_ime;                         // +0x164
    int turn_ime_on;                        // +0x168

    virtual long wnd_proc(void*, unsigned int, unsigned int, long);

    virtual int setup(TDrawArea*, TPanel*, long, long, long, long, void*, short, char*, int, int);
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
    void get_trimmed_str(char*, int);
    virtual void handle_reactivate();
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_redraw(int);
    void set_text_color(unsigned long, unsigned long);
    void set_highlight_text_color(unsigned long, unsigned long);
    void set_back_color(void*, unsigned long, unsigned char);
    void set_bevel_info(int, unsigned char, unsigned char, unsigned char,
                        unsigned char, unsigned char, unsigned char);
    void set_ime_info(int, int);
};

#endif
