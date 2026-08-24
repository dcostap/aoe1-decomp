#ifndef AOE1_DLG_MSG_CONTEXT_H
#define AOE1_DLG_MSG_CONTEXT_H

// Authentic declaration context for C:\\msdev\\work\\age1_x1\\Dlg_msg.cpp.
//
// The owner files in this module keep their function bodies and recovery
// notes.  The wrapper includes this header once, so the compiler sees one
// class surface in PDB order.  The panel base is 0xF4 bytes.  TMessageDialog
// fields begin at +0x490, as shown by the constructor, setup, and action
// address ranges.

typedef unsigned char uchar;

class TDrawArea;
class TTextPanel;
class TButtonPanel;

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, uchar);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(uchar);
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
    virtual long handle_mouse_down(uchar, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(uchar, long, long, int, int);
    virtual long handle_mouse_dbl_click(uchar, long, long, int, int);
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
    virtual uchar get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    TDrawArea* renderArea();
    int get_string(int id, char* buffer, int max_len);
    void set_curr_child(TPanel* child);

    TPanel* previous_panel;       // +0x04
    TPanel* previous_modal_panel; // +0x08
    long pnl_x;                   // +0x0C
    long pnl_y;                   // +0x10
    long width;                   // +0x14
    long height;                  // +0x18
    char* panel_name;             // +0x1C
    TDrawArea* render_area;       // +0x20
    tagRECT clip_rect;            // +0x24
    long position_mode;           // +0x34
    long need_redraw;             // +0x38
    TPanel* curr_child;           // +0x3C
    TPanel* parent;               // +0x40
    TPanel* left_panel;           // +0x44
    TPanel* top_panel;            // +0x48
    TPanel* right_panel;           // +0x4C
    TPanel* bottom_panel;          // +0x50
    void* node;                    // +0x54
    void* first_child_node;        // +0x58
    void* last_child_node;         // +0x5C
    TPanel* tab_prev_panel;        // +0x60
    TPanel* tab_next_panel;        // +0x64
    long mouse_captured;           // +0x68
    long active;                   // +0x6C
    long visible;                  // +0x70
    long tab_stop;                 // +0x74
    long have_focus;               // +0x78
    long overlapping_children;     // +0x7C
    long handle_mouse_input;       // +0x80
    long just_drawn;               // +0x84
    void* clip_rgn;                // +0x88
    tagRECT render_rect;            // +0x8C
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
    long mouse_down_ctrl;          // +0xCC
    long mouse_down_shift;         // +0xD0
    unsigned long mouse_down_time; // +0xD4
    long error_code;               // +0xD8
    long z_order;                  // +0xDC
    long display_changed_count;    // +0xE0
    long help_string_id;           // +0xE4
    long help_page_id;             // +0xE8
    uchar mouse_action;             // +0xEC
    uchar mouse_down_button;        // +0xED
    uchar panel_type;               // +0xEE
    uchar color;                    // +0xEF
    uchar fill_in_background;       // +0xF0
    uchar clip_to_parent;           // +0xF1
    uchar draw_rect2_flag;          // +0xF2
    uchar need_restore;             // +0xF3
};

typedef char dlg_msg_tpanel_size_check[(sizeof(TPanel) == 0xF4) ? 1 : -1];

class TEasy_Panel : public TPanel {
public:
    virtual ~TEasy_Panel();
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
                            long, long, long, int, int);

    char gap_F4[0x478 - 0xF4];
};

typedef char dlg_msg_teasy_size_check[(sizeof(TEasy_Panel) == 0x478) ? 1 : -1];

class TDialogPanel : public TEasy_Panel {
public:
    TDialogPanel(char* name);
    virtual ~TDialogPanel();
    virtual int setup(TDrawArea*, TPanel*, long, long, uchar, int);
    virtual int setup(TDrawArea*, TPanel*, long, long, char*, long, int);

    char gap_478[0x490 - 0x478];
};

typedef char dlg_msg_tdialog_size_check[(sizeof(TDialogPanel) == 0x490) ? 1 : -1];

class TTextPanel : public TPanel {
public:
    char gap_F4[0x188 - 0xF4];
};

class TButtonPanel : public TPanel {
public:
    char gap_F4[0x298 - 0xF4];
    int hotkey;       // +0x298
    int hotkey_shift; // +0x29C
    void set_text(short state, long string_id);
};

class TMessageDialog : public TDialogPanel {
public:
    uchar dlg_type;             // +0x490
    uchar _pad_491[3];          // +0x491..+0x493
    TTextPanel* text;            // +0x494
    TButtonPanel* button[3];     // +0x498..+0x4A0

    TMessageDialog(char* name);
    virtual ~TMessageDialog();
    long setup(TPanel*, char*, long, long, long, uchar, char*, long, long);
    long setup(TPanel*, char*, long, long, long, uchar, int, long, long);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual long key_down_action(long, short, int, int, int);
    virtual long handle_idle();
};

typedef char dlg_msg_dialog_size_check[(sizeof(TMessageDialog) == 0x4A4) ? 1 : -1];

class RGE_Base_Game {
public:
    char gap_00[0x1D8];
    int input_enabled;
    void enable_input();
};

extern RGE_Base_Game* rge_base_game;
extern char s_592A40[];

#endif
