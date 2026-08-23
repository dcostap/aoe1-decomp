#ifndef AOE1_PANEL_CONTEXT_H
#define AOE1_PANEL_CONTEXT_H

// Recovered C:\msdev\work\age1_x1\Panel.cpp context.
// The class size is 0xF4, with the vptr at +0.
// PDB line bands place wnd_proc at 1425-1521 and handle_size at 1558-1670.
// The virtual order below preserves the Panel.cpp slots used by the owners.

struct PanelNode;
struct tagPOINT;

#if !defined(_WINDEF_) && !defined(_WINDOWS_)
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};
#endif

struct TDrawArea {
    void* DrawSystem; // +0x00
    void* Wnd;        // +0x04
};

enum PositionMode {
    PositionFixed = 0,
    PositionLeft = 3,
    PositionCentered = 2,
    PositionTop = 4,
    PositionLeftTop = 7,
    PositionLeftBottom = 8,
    PositionRightTop = 9
};

class TPanel;

class TPanelSystem {
public:
    TPanel* mouseOwner();
    TPanel* keyboardOwner();
    TPanel* modalPanel();
    int GetInputEnabled();
};

extern TPanelSystem panel_system;

struct PanelNode {
    TPanel* panel;
    PanelNode* prev_node;
    PanelNode* next_node;
};

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    // VC5 places the four-long overload at +0x08 and the RECT wrapper at +0x0C.
    // Keep this declaration order: the compiler's overload slot order is not
    // the source-definition order shown by the PDB.
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(PositionMode, long, long, long, long, long, long,
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

    TPanel* previous_panel;       // +0x04
    TPanel* previous_modal_panel; // +0x08
    long pnl_x;                   // +0x0C
    long pnl_y;                   // +0x10
    long pnl_wid;                 // +0x14
    long pnl_hgt;                 // +0x18
    char* panel_name;             // +0x1C
    TDrawArea* render_area;       // +0x20
    tagRECT clip_rect;            // +0x24
    PositionMode position_mode;   // +0x34
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
    int have_focus;                // +0x78
    int overlapping_children;      // +0x7C
    int handle_mouse_input;        // +0x80
    int just_drawn;                // +0x84
    void* clip_rgn;                // +0x88
    tagRECT render_rect;           // +0x8C
    long left_border;              // +0x9C
    long top_border;               // +0xA0
    long right_border;             // +0xA4
    long bottom_border;            // +0xA8
    long min_wid;                  // +0xAC
    long max_wid;                  // +0xB0
    long min_hgt;                  // +0xB4
    long max_hgt;                  // +0xB8
    long mouse_hold_interval;      // +0xBC
    long mouse_move_tolerance;     // +0xC0
    long mouse_down_x;             // +0xC4
    long mouse_down_y;             // +0xC8
    int mouse_down_ctrl;            // +0xCC
    int mouse_down_shift;           // +0xD0
    unsigned long mouse_down_time; // +0xD4
    int error_code;                 // +0xD8
    int z_order;                    // +0xDC
    int display_changed_count;      // +0xE0
    long help_string_id;            // +0xE4
    long help_page_id;              // +0xE8
    unsigned char mouse_action;     // +0xEC
    unsigned char mouse_down_button;// +0xED
    unsigned char panel_type;       // +0xEE
    unsigned char color;            // +0xEF
    unsigned char fill_in_background;// +0xF0
    unsigned char clip_to_parent;   // +0xF1
    unsigned char draw_rect2_flag;  // +0xF2
    unsigned char need_restore;     // +0xF3

    void get_mouse_info(unsigned int keys, long packed_pos, tagPOINT& point,
                        int& focus_flag, int& capture_flag);
};

typedef char panel_context_tpanel_size_check[(sizeof(TPanel) == 0xF4) ? 1 : -1];
typedef char panel_context_node_size_check[(sizeof(PanelNode) == 0x0C) ? 1 : -1];

#endif
