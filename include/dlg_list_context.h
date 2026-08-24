#ifndef AOE1_DLG_LIST_CONTEXT_H
#define AOE1_DLG_LIST_CONTEXT_H

// Authentic dlg_list.cpp context. The class surface follows the recovered
// TPanel, TEasy_Panel, TDialogPanel, and TListDialog virtual slots.

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea;
class TPanel;
class TTextPanel;
class TListPanel;
class TScrollBarPanel;
class TButtonPanel;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(long, long, long, long, long, long, long, long,
                                 long, TPanel*, TPanel*, TPanel*, TPanel*);
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
    virtual long wnd_proc(void*, unsigned long, unsigned long, long);
    virtual long handle_idle();
    virtual long handle_size(long, long);
    virtual long handle_paint();
    virtual long handle_key_down(long, short, int, int, int);
    virtual long handle_char(long, short);
    virtual long handle_command(unsigned long, long);
    virtual long handle_user_command(unsigned long, long);
    virtual long handle_timer_command(unsigned long, long);
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

    long xPosition();
    long yPosition();
    long width();
    long height();
    TDrawArea* renderArea();
    void get_string(int, char*, int);
    void set_curr_child(TPanel*);

    char gap_04[0x3C];
    TPanel* parent;             // +0x40
    char gap_44[0xB0];           // through +0xF4
};

typedef char dlg_list_tpanel_size_check[(sizeof(TPanel) == 0xF4) ? 1 : -1];

class TEasy_Panel : public TPanel {
public:
    virtual ~TEasy_Panel();
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void draw_background(int);
    virtual void set_ideal_size(long, long);
    virtual int create_button(TPanel*, TButtonPanel**, long, long, long, long,
                              long, long, long, long, long);
    virtual int create_button(TPanel*, TButtonPanel**, char*, char*, long, long,
                              long, long, long, long, long);
    virtual int create_check_box(TPanel*, TButtonPanel**, long, long, long, long,
                                 long, long);
    virtual int create_radio_button(TPanel*, TButtonPanel**, long, long, long,
                                    long, long, long);
    virtual int create_text(TPanel*, TTextPanel**, int, long, long, long, long,
                            long, int, int, int);
    virtual int create_text(TPanel*, TTextPanel**, char**, long, long, long,
                            long, long, long, int, int);
    virtual int create_text(TPanel*, TTextPanel**, char*, long, long, long, long,
                            long, long, long, long);
    virtual int create_input(TPanel*, TPanel**, char*, short, long, long, long,
                             long, long, long);
    virtual int create_edit(TPanel*, TPanel**, char*, short, long, long, long,
                            long, long, long, int, int);
    virtual int create_drop_down(TPanel*, TPanel**, long, long, long, long,
                                 long, long, long);
    virtual int create_list(TPanel*, TListPanel**, long, long, long, long, long);
    virtual int create_scrollbar(TPanel*, TScrollBarPanel**, TTextPanel*, long,
                                 long, long, long, long);
    virtual int create_auto_scrollbar(TPanel**, TTextPanel*, long);
    virtual int create_vert_slider(TPanel*, TPanel**, long, long, long, long,
                                   long, long, long, long);
    virtual int create_horz_slider(TPanel*, TPanel**, long, long, long, long,
                                   long, long, long, long);
    virtual void position_panel(TPanel*, long, long, long, long);

    char gap_F4[0x384];          // through +0x478
};

typedef char dlg_list_teasy_size_check[(sizeof(TEasy_Panel) == 0x478) ? 1 : -1];

class TDialogPanel : public TEasy_Panel {
public:
    TDialogPanel(char*);
    virtual ~TDialogPanel();
    virtual int setup(TDrawArea*, TPanel*, long, long, unsigned char, int);
    virtual int setup(TDrawArea*, TPanel*, long, long, char*, long, int);

    char gap_478[0x18];         // through +0x490
};

typedef char dlg_list_tdialog_size_check[(sizeof(TDialogPanel) == 0x490) ? 1 : -1];

class TTextPanel : public TPanel {
public:
    virtual ~TTextPanel();
    int currentLineNumber();
    char* currentLine();
};

class TListPanel : public TTextPanel {
public:
    virtual ~TListPanel();
    virtual void set_text(char**, short);
    void scroll_cur_line(unsigned char, short, int);
};

class TScrollBarPanel : public TPanel {
public:
    virtual ~TScrollBarPanel();
};

class TButtonPanel : public TPanel {
public:
    virtual ~TButtonPanel();
    char gap_F4[0x1A4];
    union {
        int hotkey;
        int field_298;
    };
    union {
        int hotkey_shift;
        int field_29C;
    };
};

typedef char dlg_list_tbutton_size_check[(sizeof(TButtonPanel) == 0x2A0) ? 1 : -1];

class TListDialog : public TDialogPanel {
public:
    TListDialog(char*);
    virtual ~TListDialog();
    virtual long setup(TPanel*, char*, long, long, long, long, long, long, long,
                       char*, long, long, long, long, char**, short, short,
                       long, long, long, long, long);
    virtual long setup(TPanel*, char*, long, long, long, long, long, long, long,
                       int, long, long, long, long, char**, short, short,
                       long, long, long, long, long);
    virtual long key_down_action(long, short, int, int, int);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual short get_list_id();
    virtual char* get_list_name();

    TTextPanel* title;             // +0x490
    TListPanel* list;              // +0x494
    union {
        TScrollBarPanel* scroll_bar;
        TScrollBarPanel* extra_scroll;
    };                             // +0x498
    TButtonPanel* ok_btn;          // +0x49C
    TButtonPanel* cancel_btn;      // +0x4A0
    short list_id;                 // +0x4A4
    char gap_4A6[2];
    char* list_name;               // +0x4A8
};

typedef char dlg_list_dialog_size_check[(sizeof(TListDialog) == 0x4AC) ? 1 : -1];

#endif
