#ifndef AOE1_DLG_HELP_H
#define AOE1_DLG_HELP_H

// Declarations recovered for the original dlg_help.cpp translation unit.
// The panel hierarchy keeps the observed object offsets and virtual slots used
// by the six normal owners.

#include "game_globals.h"
#include "rge_base_game_global.h"
#include <stdlib.h>

class TDrawArea;
class TButtonPanel;
class TTextPanel;
class THelpDialog;
typedef unsigned char uchar;

struct HelpDialogMember {
    virtual ~HelpDialogMember() {}
};

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int param);
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;

typedef int (__stdcall *GDI_WinHelpA)(int, char*, unsigned int, char*);
extern GDI_WinHelpA _WinHelpA;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(struct tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long, long,
                                 long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(struct tagRECT*);
    virtual void draw_offset(long, long, struct tagRECT*);
    virtual void draw_rect2(struct tagRECT*);
    virtual void draw_offset2(long, long, struct tagRECT*);
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
    virtual void get_true_render_rect(struct tagRECT*);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual unsigned char get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    long xPosition() const;
    long yPosition() const;
    long width() const;
    long height() const;
    TDrawArea* renderArea();
    char* get_string(int id);
    void set_curr_child(TPanel* child);

    char gap_04[0xB0 - 4];
    long field_B0;
    char gap_B4[4];
    long field_B8;
    char gap_BC[0xF4 - 0xBC];
};

typedef char dlg_help_tpanel_size_check[(sizeof(TPanel) == 0xF4) ? 1 : -1];

class TEasy_Panel : public TPanel {
public:
    virtual ~TEasy_Panel();
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long action(TPanel*, long, unsigned long, unsigned long);

    long get_popup_info_id();
    char* get_popup_info_file();

    char gap_F4[0x478 - 0xF4];
};

typedef char dlg_help_teasy_size_check[(sizeof(TEasy_Panel) == 0x478) ? 1 : -1];

class TDialogPanel : public TEasy_Panel {
public:
    TDialogPanel(char* name);
    virtual ~TDialogPanel();
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
    virtual int create_input(TPanel*, void**, char*, short, int, long, long, long,
                             long, long);
    virtual int create_edit(TPanel*, void**, char*, short, int, long, long, long,
                            long, long, int, int);
    virtual int create_drop_down(TPanel*, void**, long, long, long, long, long,
                                 long, long);
    virtual int create_list(TPanel*, void**, long, long, long, long, long, long,
                            long);
    virtual int create_scrollbar(TPanel*, void**, TTextPanel*, long, long, long,
                                 long, long);
    virtual int create_auto_scrollbar(void**, TTextPanel*, long);
    virtual int create_vert_slider(TPanel*, void**, long, long, long, long, long,
                                   long, long, long);
    virtual int create_horz_slider(TPanel*, void**, long, long, long, long, long,
                                   long, long, long);
    virtual void position_panel(TPanel*, long, long, long, long);
    virtual int setup(TDrawArea*, TPanel*, long, long, unsigned char, int);
    virtual int setup(TDrawArea*, TPanel*, long, long, char*, long, int);
    char gap_478[0x490 - 0x478];
};

typedef char dlg_help_tdialog_size_check[(sizeof(TDialogPanel) == 0x490) ? 1 : -1];

class RGE_Font {
public:
    void* font;
    long font_wid;
    long font_hgt;
};

class RGE_Base_Game {
public:
    char gap_00[0x10];
    int prog_window;
    RGE_Font* get_font(int id);
    int singlePlayerGame();
};

class TTextPanel : public TPanel {
public:
    char gap_F4[0x188 - 0xF4];
};

class TButtonPanel : public TPanel {
public:
    char gap_F4[0x1A4];
    int hotkey;
    int hotkey_shift;
};

class THelpDialog : public TDialogPanel {
public:
    int help_page_id;
    char parent_panel[0x100];
    union {
        TTextPanel* title;
        HelpDialogMember* member_obj1;
    };
    union {
        TTextPanel* list;
        HelpDialogMember* member_obj2;
    };
    union {
        TButtonPanel* ok_button;
        HelpDialogMember* member_obj3;
    };
    union {
        TButtonPanel* encyclopedia_button;
        HelpDialogMember* member_obj4;
    };

    THelpDialog(TEasy_Panel*, char*, long, long, long, long);
    THelpDialog(TEasy_Panel*, char*, char*, long, long, long);
    virtual ~THelpDialog();
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual long handle_mouse_down(unsigned char, long, long, int, int);

protected:
    void setup_help(TEasy_Panel*, char*, char*, long, long, long);
};

typedef char dlg_help_dialog_size_check[(sizeof(THelpDialog) == 0x5A4) ? 1 : -1];

#endif
