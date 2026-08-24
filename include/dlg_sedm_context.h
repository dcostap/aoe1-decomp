#ifndef AOE1_DLG_SEDM_CONTEXT_H
#define AOE1_DLG_SEDM_CONTEXT_H

// Authentic shared surface for dlg_sedm.cpp.
// The target module uses the period panel hierarchy and the inherited
// TPanel/TEasy_Panel virtual surface.  Only methods used by this module are
// named below; known virtual slots are retained from the reviewed panel ABI.

#include "game_globals.h"

class TDrawArea;
class TPanel;
class TButtonPanel;
class TRIBE_Screen_Sed;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long,
                       unsigned char);
    virtual void set_rect(RECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                 long, long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
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
    virtual void get_true_render_rect(RECT*);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual unsigned char get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    char _gap_04[0x1C];
    void* render_area;
    char _gap_24[0x1C];
    TPanel* parent_panel;
    char _gap_44[0x28];
    int active;
    int visible;
    char _gap_74[0x14];
    void* clip_rgn;
    RECT render_rect;
    char _gap_9C[0x44];
    int display_changed_count;
    char _gap_E4[0x10];

    void delete_panel(TPanel** panel_ptr);
    void* renderArea();
    char* panelName();
};

typedef char dlg_sedm_tpanel_size_check[(sizeof(TPanel) == 0xF4) ? 1 : -1];

class TButtonPanel : public TPanel {
public:
    char _gap_F4[0x1A4];
    int field_298;
    int field_29C;
    virtual ~TButtonPanel();
};

class TEasy_Panel : public TPanel {
public:
    char _gap_F4[0x384];

    virtual ~TEasy_Panel();
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    char* get_popup_info_file();
    long get_popup_info_id();
    int create_button(TPanel* parent, TButtonPanel** button_ptr,
                      long string_id, long x, long y, long w, long h,
                      long a, long b, long c, long d);
};

typedef char dlg_sedm_teasy_size_check[(sizeof(TEasy_Panel) == 0x478) ? 1 : -1];

class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
};

class TDialogPanel : public TEasy_Panel {
public:
    int dlg_wnd;
    int save_parent_child;
    int text_font_id;
    int input_font_id;
    int button_font_id;
    int button_sound_id;

    TDialogPanel(char* name);
    virtual ~TDialogPanel();
    int setup(void* render_area, void* parent, int width, int height,
              char* file, int info_id, int modal);
};

typedef char dlg_sedm_tdialog_size_check[(sizeof(TDialogPanel) == 0x490) ? 1 : -1];

class TRIBE_Screen_Sed : public TScreenPanel {
public:
    virtual ~TRIBE_Screen_Sed();
    virtual void draw();
    virtual long handle_size(long, long);
    virtual long handle_idle();
    virtual long key_down_action(long, short, int, int, int);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void set_focus(int);
    void command_quit();
    void command_save(unsigned char save, unsigned char close);
    void command_save_as(unsigned char close);
    void command_open();
    void command_new();
    char* scenario_save_defaulted();
    void command_quick_save();
};

class TRIBE_Screen_Sed_Open : public TScreenPanel {
public:
    TPanel* title;
    TPanel* list;
    TPanel* scrollbar;
    TPanel* okButton;
    TPanel* cancelButton;
    TPanel* deleteButton;

    TRIBE_Screen_Sed_Open();
    virtual ~TRIBE_Screen_Sed_Open();
    virtual long action(TPanel*, long, unsigned long, unsigned long);
};

typedef char dlg_sedm_open_size_check[(sizeof(TRIBE_Screen_Sed_Open) == 0x490) ? 1 : -1];

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int mode);
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;

class TRIBE_Game {
public:
    int test_scenario(char* scenario);
    int start_scenario_editor(char* scenario, int mode);
};

extern TRIBE_Game* rge_base_game;

extern char s_Scenario_Editor_Screen[];
extern char s_Scenario_Menu_Dialog[];
extern char s_New_Dialog[];
extern char s_Open_Dialog[];
extern char s_Scenario_Editor_Open[];

class TRIBE_Dialog_Sed_Menu : public TDialogPanel {
public:
    TRIBE_Screen_Sed* scenario_editor; // +0x490
    TPanel* title;                      // +0x494
    TButtonPanel* buttons[7];           // +0x498

    TRIBE_Dialog_Sed_Menu(TRIBE_Screen_Sed* param_1);
    virtual ~TRIBE_Dialog_Sed_Menu();
    virtual long action(TPanel* panel, long event, unsigned long param_3,
                        unsigned long param_4);
};

typedef char dlg_sedm_dialog_size_check[(sizeof(TRIBE_Dialog_Sed_Menu) == 0x4B4) ? 1 : -1];

#endif
