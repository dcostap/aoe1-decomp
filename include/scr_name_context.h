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
    long setup(TDrawArea*, TPanel*, long, long, char*, long, int);
    long setup(TDrawArea*, TPanel*, char*, long, int, long, long, long,
               long, int);
    virtual void set_tab_order(TPanel**, short);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_positioning(long, long, long, long, long, long, long, long,
                                 long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual long handle_idle();
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);

    void set_help_info(long, long);
    void set_curr_child(TPanel*);
    void delete_panel(TTextPanel**);
    void delete_panel(TEditPanel**);
    void delete_panel(TListPanel**);
    void delete_panel(TScrollBarPanel**);
    void delete_panel(TButtonPanel**);
    void setup_shadow_area(int);
    void set_ideal_size(long, long);
    TDrawArea* renderArea() const;
    char* panelName();
    char* get_string(int);
    int setup_error;
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
    virtual long action(TPanel*, long, unsigned long, unsigned long);
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
    char gap_00[4];
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
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
};

#endif
