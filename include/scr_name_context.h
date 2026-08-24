#ifndef AOE1_SCR_NAME_CONTEXT_H
#define AOE1_SCR_NAME_CONTEXT_H

// Authentic shared declaration surface for C:\\msdev\\work\\age1_x1\\scr_name.cpp.
// The wrapper preserves PDB owner order.  This header only joins the existing
// owner bodies into one compiling module; it does not claim exact codegen.

#include <windows.h>

class TDrawArea;
class TPanel;
class TTextPanel;
class TEditPanel;
class TListPanel;
class TScrollBarPanel;
class TButtonPanel;
class RGE_Game_Info;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long,
                       unsigned char);
    virtual void set_rect(RECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(long, long, long, long, long, long, long,
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
    // VC5 places the array overload at +0xC8 with this declaration order.
    virtual void set_tab_order(TPanel**, short);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual unsigned char get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();
    virtual void draw_background(int);

    union {
        struct {
            char panel_gap_04[0x1C];
            TDrawArea* render_area;
            char panel_gap_24[0x1C];
            TPanel* parent_panel;
            char panel_gap_44[0xB0];
        };
        struct {
            char gap_04[0xD4];
            int setup_error;
            char gap_DC[0x18];
        };
    };

    TDrawArea* renderArea() const;
    char* panelName();
    char* get_string(int);
    void delete_panel(TPanel**);
    void delete_panel(TTextPanel**);
    void delete_panel(TEditPanel**);
    void delete_panel(TListPanel**);
    void delete_panel(TScrollBarPanel**);
    void delete_panel(TButtonPanel**);
    void set_help_info(long, long);
    void set_curr_child(TPanel*);
    void setup_shadow_area(int);
    void set_ideal_size(long, long);
};

class TTextPanel : public TPanel {
public:
    char gap_F4[0x68];
    int flag_15c;

    virtual ~TTextPanel();
    void empty_list();
    int append_line(char*, long);
    long get_line();
    long get_line(long);
    void set_line(long);
    long get_id();
    long get_id(long);
    char* get_text();
    char* get_text(long);
    int numberLines();
};

class TListPanel : public TTextPanel {
};

class TScrollBarPanel : public TPanel {
};

class TButtonPanel : public TPanel {
public:
    char gap_F4[0x1A4];
    long hotkey;
    long hotkey_shift;

    void set_disabled(int);
};

class TEditPanel : public TTextPanel {
public:
    enum FormatType {
        FormatText = 0,
        FormatNumber = 1,
        FormatInteger = 2,
        FormatUnsignedInt = 3,
        FormatFile = 4,
        FormatFileNoExt = 5,
        FormatPath = 6,
        FormatMultiLine = 7,
        FormatPercent = 8
    };
    virtual ~TEditPanel();
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];

    virtual ~TEasy_Panel();
    long action(TPanel*, long, unsigned long, unsigned long);
    long setup(TDrawArea*, TPanel*, char*, long, int, long, long, long, long, int);
    long setup(TDrawArea*, TPanel*, long, long, char*, long, int);
    void setup_shadow_area(int);
    void set_ideal_size(long, long);
    int create_text(TPanel*, TTextPanel**, int, long, long, long, long, long,
                    int, int, int);
    int create_edit(TPanel*, TEditPanel**, char*, short, TEditPanel::FormatType,
                    long, long, long, long, long, int, int);
    int create_list(TPanel*, TListPanel**, long, long, long, long, long);
    int create_auto_scrollbar(TScrollBarPanel**, TTextPanel*, long);
    int create_button(TPanel*, TButtonPanel**, long, long, long, long, long,
                      long, long, long, long);
    char* get_popup_info_file();
    long get_popup_info_id();
    void popupYesNoDialog(char*, char*, long, long);
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char*);
    virtual ~TScreenPanel();
};

class TDialogPanel : public TEasy_Panel {
public:
    char gap_478[0x18];
    TDialogPanel(char*);
    virtual ~TDialogPanel();
};

class RGE_Game_Info {
public:
    long get_people_list(char***, long&);
    unsigned char set_current_person(long);
    void remove_player(long);
    unsigned char add_new_person(char*);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    RGE_Game_Info* player_game_info;
    char gap_08[0x44];
    TDrawArea* draw_area;
    char gap_50[0x188];
    int input_enabled;

    void enable_input();
    void disable_input();
    void close();
};

extern RGE_Base_Game* rge_base_game;
extern "C" void __cdecl free(void*);

class TPanelSystem {
public:
    int setCurrentPanel(char*, int);
    int destroyPanel(char*);
    TPanel* panel(char*);
};

extern TPanelSystem panel_system;

class TRIBE_Screen_Campaign_Selection {
public:
    char data[0x4CC];
    TRIBE_Screen_Campaign_Selection();
};

class TribeSPMenuScreen {
public:
    char data[0x49C];
    TribeSPMenuScreen();
};

class TRIBE_Screen_Name : public TScreenPanel {
public:
    TTextPanel* title;
    TTextPanel* name_text;
    TListPanel* name_list;
    TScrollBarPanel* name_scrollbar;
    TButtonPanel* new_button;
    TButtonPanel* remove_button;
    TButtonPanel* ok_button;
    TButtonPanel* cancel_button;
    TButtonPanel* close_button;
    int started_input;

    TRIBE_Screen_Name();
    virtual ~TRIBE_Screen_Name();
    void init_vars();
    void get_player_names();
    void setup_tab_order();
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual long handle_idle();
};

class TRIBE_Dialog_Name : public TDialogPanel {
public:
    TTextPanel* title;
    TTextPanel* name_text;
    TEditPanel* name_input;
    TButtonPanel* ok_button;
    TButtonPanel* cancel_button;

    TRIBE_Dialog_Name(TScreenPanel*);
    virtual ~TRIBE_Dialog_Name();
    long action(TPanel*, long, unsigned long, unsigned long);
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
};

#endif
