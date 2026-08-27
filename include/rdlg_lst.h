#ifndef AOE1_RDLG_LST_H
#define AOE1_RDLG_LST_H

// Authentic declaration surface for C:\\msdev\\work\\age1_x1\\rdlg_lst.cpp.
// This header owns the class ABI for the complete recovered source module.

#include <stdlib.h>
#include <string.h>

struct tagRECT;

class TPanel {
public:
    virtual ~TPanel();
    virtual void setup();
    virtual void set_rect_1();
    virtual void set_rect_2();
    virtual void set_color();
    virtual void set_active();
    virtual void set_positioning();
    virtual void set_fixed_position();
    virtual void set_redraw();
    virtual void set_overlapped_redraw();
    virtual void draw_setup();
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect();
    virtual void draw_offset();
    virtual void draw_rect2();
    virtual void draw_offset2();
    virtual void paint();
    virtual void wnd_proc();
    virtual void handle_idle();
    virtual void handle_size();
    virtual void handle_paint();
    virtual void handle_key_down();
    virtual void handle_char();
    virtual void handle_command();
    virtual void handle_user_command();
    virtual void handle_timer_command();
    virtual void handle_scroll();
    virtual void handle_mouse_down();
    virtual void handle_mouse_move();
    virtual void handle_mouse_up();
    virtual void handle_mouse_dbl_click();
    virtual void mouse_move_action();
    virtual void mouse_left_down_action();
    virtual void mouse_left_hold_action();
    virtual void mouse_left_move_action();
    virtual void mouse_left_up_action();
    virtual void mouse_left_dbl_click_action();
    virtual void mouse_right_down_action();
    virtual void mouse_right_hold_action();
    virtual void mouse_right_move_action();
    virtual void mouse_right_up_action();
    virtual void mouse_right_dbl_click_action();
    virtual void key_down_action();
    virtual void char_action();
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

    char gap_04[0xD4];
    int error_code;
    char gap_DC[0x18];
};

class TEasy_Panel : public TPanel {
public:
    virtual ~TEasy_Panel();
    virtual void draw_background(int);
    virtual void set_ideal_size(long, long);
    virtual int create_button(TPanel*, void**, long, long, long, long, long,
                              long, long, long, long);
    virtual int create_button_text(TPanel*, void**, char*, char*, long, long,
                                   long, long, long, long, long, long);
    virtual int create_check_box(TPanel*, void**, long, long, long, long,
                                 long, long);
    virtual int create_radio_button(TPanel*, void**, long, long, long, long,
                                    long, long);
    virtual int create_text_number(TPanel*, void**, int, long, long, long,
                                   long, long, int, int, int);
    virtual int create_text_list(TPanel*, void**, char**, long, long, long,
                                 long, long, long, int, int);
    virtual int create_text(TPanel*, void**, char*, long, long, long, long,
                            long, int, int, int);
    virtual int create_input(TPanel*, void**, char*, short, long, long, long,
                             long, long, long);
    virtual int create_edit(TPanel*, void**, char*, short, long, long, long,
                            long, long, long, int, int);
    virtual int create_drop_down(TPanel*, void**, long, long, long, long, long,
                                 long, long);
    virtual int create_list(TPanel*, void**, long, long, long, long, long);
    virtual int create_scrollbar(TPanel*, void**, TPanel*, long, long, long,
                                 long, long);
    virtual int create_auto_scrollbar(void**, TPanel*, long);
    virtual int create_vert_slider(TPanel*, void**, long, long, long, long,
                                   long, long, long);
    virtual int create_horz_slider(TPanel*, void**, long, long, long, long,
                                   long, long, long);
    virtual void position_panel(TPanel*, long, long, long, long);
};

class TDialogPanel : public TEasy_Panel {
public:
    TDialogPanel(char*);
    virtual ~TDialogPanel();

    char gap_F4[0x384];
    void* dlg_wnd;
    TPanel* save_parent_child;
    int text_font_id;
    int input_font_id;
    int button_font_id;
    int button_sound_id;

    virtual int setup(TPanel*, TPanel*, long, long, unsigned char, int);
    virtual int setup(TPanel*, TPanel*, long, long, char*, long, int);
};

class TListDialog : public TDialogPanel {
public:
    TListDialog(char*);
    virtual ~TListDialog();

    void* title;
    void* list;
    void* scroll_bar;
    void* ok_btn;
    void* cancel_btn;
    short selected_index;
    char gap_4A6[2];
    char* list_name;

    virtual short get_list_id();
    virtual char* get_list_name();

    long setup(TPanel*, char*, long, long, long, long, long, long, long,
               char*, long, long, long, long, char**, short, short, long,
               long, long, long, long);
};

class TScreenPanel : public TEasy_Panel {
};

struct rdlg_list_info {
    char text[100];
    short id;
};

class RGE_Game_Object {
public:
    char gap_00[8];
    char* name;
    short icon_id;
    char gap_0E[0x4E - 0x0E];
    unsigned char field_4E;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x1E];
    short master_object_num;
    RGE_Game_Object** master_objects;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short);
    virtual int get_error_code();
    virtual char* get_string(int, long, char*, int);
    char gap_04[0x3F8];
    short master_obj_id;
    RGE_Player* get_player();
};

extern RGE_Base_Game* rge_base_game;

extern "C" __declspec(dllimport) int __stdcall CompareStringA(
    unsigned long locale, unsigned long flags, const char* string1,
    int length1, const char* string2, int length2);

int __cdecl rdlg_list_compare(const void*, const void*);

class RGE_Dialog_List : public TListDialog {
public:
    RGE_Dialog_List(char*);
    virtual ~RGE_Dialog_List();
    virtual short get_list_id();

    int setup(TScreenPanel*, char*, long, int, char*);

    int list_type;
    short list_size;
    short list_line;
    rdlg_list_info* list_info;
    char** list_text;

protected:
    virtual int create_list();
    int create_object_list();
    void sort_list();
    void calc_list_line();
    virtual short get_cur_id();
};

#endif
