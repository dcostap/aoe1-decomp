#ifndef AOE1_PNL_LST_H
#define AOE1_PNL_LST_H

// Recovered declarations for Pnl_lst.cpp.
// TTextPanel owns the text list and selection fields.
// TListPanel owns the list interaction fields.

#include <windows.h>

struct PanelNode;
class TShape;

class TDrawArea {
public:
    void* DrawSystem;
    void* Wnd;

    void* GetDc(char* name);
    void ReleaseDc(char* name);
    unsigned char* Lock(char* name, int mode);
    void Unlock(char* name);
    void DrawRect(long x1, long y1, long x2, long y2,
                  unsigned char color);
    void DrawBevel(long x1, long y1, long x2, long y2,
                   unsigned char color1, unsigned char color2);
    void DrawBevel2(long x1, long y1, long x2, long y2,
                    unsigned char color1, unsigned char color2,
                    unsigned char color3, unsigned char color4);
    void DrawBevel3(long x1, long y1, long x2, long y2,
                    unsigned char color1, unsigned char color2,
                    unsigned char color3, unsigned char color4,
                    unsigned char color5, unsigned char color6);
};

extern "C" {
__declspec(dllimport) int __stdcall SelectClipRgn(void*, void*);
__declspec(dllimport) void* __stdcall SelectObject(void*, void*);
__declspec(dllimport) int __stdcall SetBkMode(void*, int);
}

extern char s_pnl_lst__draw[];
extern char s_pnl_lst__draw_highlight_bar[];
extern "C" unsigned long __cdecl debug_timeGetTime(const char*, int);

typedef int PositionMode;
typedef int RedrawMode;

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
    virtual void set_positioning(PositionMode, long, long, long, long,
                                 long, long, long, long,
                                 TPanel*, TPanel*, TPanel*, TPanel*);
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

    // These are nonvirtual Panel.cpp helpers.  Their declarations are part of
    // the canonical owner surface because the list event bodies call them.
    int capture_mouse();
    void release_mouse();

    TPanel* previousPanelValue;       // +0x04
    TPanel* previousModalPanelValue;  // +0x08
    long pnl_x;                        // +0x0C
    long pnl_y;                        // +0x10
    long pnl_wid;                      // +0x14
    long pnl_hgt;                      // +0x18
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
    PanelNode* node;                  // +0x54
    PanelNode* first_child_node;      // +0x58
    PanelNode* last_child_node;       // +0x5C
    TPanel* tab_prev_panel;           // +0x60
    TPanel* tab_next_panel;           // +0x64
    int mouse_captured;               // +0x68
    int active;                       // +0x6C
    int visible;                      // +0x70
    int tab_stop;                     // +0x74
    union { int have_focus; int field_78; }; // +0x78
    int overlapping_children;         // +0x7C
    union { int handle_mouse_input; int field_80; }; // +0x80
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
    union { long mouse_move_tolerance; long field_C0; }; // +0xC0
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
    union { unsigned char panel_type; unsigned char field_EE; }; // +0xEE
    unsigned char color;              // +0xEF
    unsigned char fill_in_background; // +0xF0
    unsigned char clip_to_parent;     // +0xF1
    unsigned char draw_rect2_flag;    // +0xF2
    unsigned char need_restore;       // +0xF3
};

typedef char pnl_lst_tpanel_size_check[(sizeof(TPanel) == 0xF4) ? 1 : -1];

class TScrollBarPanel : public TPanel {
public:
    void set_list_len(int length, int top_line);
};

class TTextPanel : public TPanel {
public:
    class TextNode {
    public:
        char* text;                    // +0x00
        char* text2;                   // +0x04
        long id;                       // +0x08
        union { TextNode* next_node; TextNode* next; }; // +0x0C
    };

    TTextPanel();
    virtual ~TTextPanel();
    virtual void set_rect(long, long, long, long);
    virtual void set_active(int);
    virtual void draw();
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void set_text(char**, short);
    virtual void set_text(long);
    virtual void set_text(char*);
    virtual void set_bevel_info(int, int, int, int, int, int, int);

    TextNode* list;                    // +0xF4
    short num_lines;                   // +0xF8
    short draw_lines;                  // +0xFA
    union { short top_line; short item_min; }; // +0xFC
    union { short bot_line; short item_max; }; // +0xFE
    short cur_line;                    // +0x100
    short cur_col;                     // +0x102
    void* font;                        // +0x104
    long font_wid;                     // +0x108
    long font_hgt;                     // +0x10C
    long vert_align;                   // +0x110
    long horz_align;                   // +0x114
    int word_wrap;                     // +0x118
    long text_style;                   // +0x11C
    unsigned long text_color1;         // +0x120
    unsigned long text_color2;         // +0x124
    union { unsigned long highlightTextColor1; unsigned long highlight_text_color1; }; // +0x128
    union { unsigned long highlightTextColor2; unsigned long highlight_text_color2; }; // +0x12C
    TScrollBarPanel* scbar_panel;      // +0x130
    int auto_scbar;                    // +0x134
    short fixed_len;                   // +0x138
    unsigned char pad_13A[2];          // +0x13A
    long text_wid;                     // +0x13C
    long text_hgt;                     // +0x140
    TShape* back_pic;                  // +0x144
    short back_pic_wid;                // +0x148
    short back_pic_hgt;                // +0x14A
    int fill_back;                     // +0x14C
    unsigned char back_color;           // +0x150
    unsigned char pad_151[3];          // +0x151
    int outline;                       // +0x154
    unsigned char outline_color;       // +0x158
    unsigned char pad_159[3];          // +0x159
    int sorted;                        // +0x15C
    long second_column_pos;            // +0x160
    long full_width;                   // +0x164
    long scbar_width;                  // +0x168
    int scbar_active;                  // +0x16C
    union { int bevel_type; int field_170; }; // +0x170
    unsigned char bevel_color1;        // +0x174
    unsigned char bevel_color2;        // +0x175
    unsigned char bevel_color3;        // +0x176
    unsigned char bevel_color4;        // +0x177
    unsigned char bevel_color5;        // +0x178
    unsigned char bevel_color6;        // +0x179
    unsigned char pad_17A[2];          // +0x17A
    void* clip_rgn2;                  // +0x17C
    int border_size;                    // +0x180
    int spacer_size;                    // +0x184

    void set_scrollbar(TScrollBarPanel*, int);
    void calc_draw_info(int);
    void scroll(int, short, int);
    void draw_background();
    void draw_border();
    void draw_line(void*, short, short, unsigned long, unsigned long);
    void calc_line_pos(void*, short, short, tagRECT*, long*);
};

typedef char pnl_lst_textnode_size_check[
    (sizeof(TTextPanel::TextNode) == 0x10) ? 1 : -1];
typedef char pnl_lst_ttextpanel_size_check[
    (sizeof(TTextPanel) == 0x188) ? 1 : -1];

// The original owner bodies use the historic global TextNode spelling.
typedef TTextPanel::TextNode TextNode;

class TListPanel : public TTextPanel {
public:
    // Declaration order follows the period TListPanel header. VC5 register
    // scheduling for item_at depends on this complete virtual surface.
    TListPanel();
    virtual ~TListPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long,
                       unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(PositionMode, long, long, long, long,
                                 long, long, long, long,
                                 TPanel*, TPanel*, TPanel*, TPanel*);
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
    virtual void set_text(char**, short);
    virtual void set_text(long);
    virtual void set_text(char*);
    virtual void set_bevel_info(int, int, int, int, int, int, int);

    union { int auto_track; int field_188; }; // +0x188
    unsigned long mouse_scroll_last_time; // +0x18C
    unsigned long mouse_scroll_interval;   // +0x190
    int mouse_scroll_up;                   // +0x194
    int mouse_scroll_down;                 // +0x198
    union { int drawHighlightBar; int field_19C; }; // +0x19C

    void set_auto_track(int);
    void setDrawHighlightBar(int);
    void scroll_cur_line(unsigned char, short, int);
    short item_at(long, long);
    void goto_item(long, long);
    void draw_highlight_bar();
};

typedef char pnl_lst_tlistpanel_size_check[
    (sizeof(TListPanel) == 0x1A0) ? 1 : -1];

#endif
