#ifndef SCR_CJ_CONTEXT_H
#define SCR_CJ_CONTEXT_H

// PDB and binary-supported scr_cj.cpp context.
// TPanel is 0xF4; TEasy_Panel is 0x478; TScreenPanel is 0x478; and
// TDialogPanel is 0x490. TribeJoinScreen owns fields at +0x478..+0x4AC.
// The virtual declarations retain the proven action (+0xB4) and string
// (+0xE4) slots. Unknown slots use period class declarations, not a manual
// vtable or an absolute function pointer.

#include <stdio.h>
#include <string.h>

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

typedef int PositionMode;
typedef int RedrawMode;

class TDrawArea;
class TButtonPanel;
class TTextPanel;
class TListPanel;
class TScrollBarPanel;
class TEditPanel;

class TRegistry {
public:
    char* RegGetAscii(int, char*);
};

class TPanel {
public:
    virtual ~TPanel();
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
    virtual void set_tab_order_array(TPanel**, short);
    virtual unsigned char get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();
    virtual void set_string(long id);
    virtual void set_string(char* text);

    char gap_04[0xD4];
    int setup_error;
    char gap_DC[0x18];

    TDrawArea* renderArea();
    void delete_panel(TPanel** panel);
    void set_tab_order(TPanel** list, short count);
    void set_curr_child(TPanel* child);
    int get_string(int resid, char* buffer, int len);
};

class TTextPanel : public TPanel {
public:
    void empty_list();
    int append_line(char* line, long param);
    int currentLineNumber() const;
    char* currentLine();
};

class TListPanel : public TTextPanel {
};

class TScrollBarPanel : public TPanel {
};

class TEditPanel : public TTextPanel {
};

class TButtonPanel : public TPanel {
public:
    char gap_F4[0x1A4];
    long hotkey;
    long hotkey_shift;
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];

    virtual ~TEasy_Panel();
    virtual long action(TPanel*, long, unsigned long, unsigned long);

    void popupOKDialog(long text_id, char* panel_name, int param_4, int param_5);
    void popupOKDialog(char* text, char* panel_name, int param_4, int param_5);
    void setup_shadow_area(int force_rebuild);
    void set_ideal_size(long width, long height);
    int create_text(TPanel* parent, TTextPanel** output, long string_id,
                    long x, long y, long width, long height,
                    long font, long align, long center, long wrap);
    int create_list(TPanel* parent, TListPanel** output,
                    long x, long y, long width, long height, long lines);
    int create_auto_scrollbar(TScrollBarPanel** output,
                              TTextPanel* text, long width);
    int create_button(TPanel* parent, TButtonPanel** output,
                      long string_id, long text2, long x, long y,
                      long width, long height, long p9, long p10,
                      long p11);
    int create_edit(TPanel* parent, TEditPanel** output, char* text,
                    short text_len, long format, long x, long font,
                    long width, long height, long max, long p11, long p12);
    long get_popup_info_id();
    char* get_popup_info_file();
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char* name);
    virtual ~TScreenPanel();
    virtual long handle_idle();
    virtual long handle_user_command(unsigned int, long);
    long setup(TDrawArea* draw_area, char* info_file, long info_id, int param);
};

class TDialogPanel : public TEasy_Panel {
public:
    char gap_478[0x18];
    virtual ~TDialogPanel();
    TDialogPanel(char* title);
    int setup(TDrawArea* draw_area, TPanel* parent, long width, long height,
              char* file, long id, int flag);
};

struct _GUID;

class TCommunications_Handler {
public:
    void SetPlayerHumanity(unsigned int player, int humanity);
    int JoinMultiplayerGame(_GUID* guid);
    void UnlinkToLevel(int param);
};

class TCommunications_Sessions {
public:
    char data[0x457B0];
    TCommunications_Sessions(TCommunications_Handler* handler);
    ~TCommunications_Sessions();
    void Refresh();
    long GetSessionCount();
    long GetSessionMaxPlayers(long index);
    long GetSessionCurrentPlayers(long index);
    char* GetSessionName(long index);
    _GUID* GetSessionGUID(int index);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[0x48];
    TDrawArea* draw_area;
    char gap_50[0x188];
    int input_enabled;
    void disable_input();
    void enable_input();
    void draw_window();
    void close();
};

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int param);
    int destroyPanel(char* name);
};

extern TCommunications_Handler* comm;
extern TCommunications_Sessions* Sess;
extern RGE_Base_Game* rge_base_game;
extern TPanelSystem panel_system;
extern TRegistry* Regs;

extern "C" void* __cdecl operator_delete(void* ptr);
extern "C" unsigned long __cdecl debug_timeGetTime(char* file, int line);

class TribeJoinScreen : public TScreenPanel {
public:
    int startedSession;
    int listFilled;
    TTextPanel* title;
    TTextPanel* listTitle;
    TListPanel* list;
    TScrollBarPanel* scrollbar;
    TButtonPanel* joinButton;
    TButtonPanel* createButton;
    TButtonPanel* cancelButton;
    TButtonPanel* refreshButton;
    TButtonPanel* close_button;
    int game_count;
    int waitingToStart;
    unsigned long joinTime;

    TribeJoinScreen();
    virtual ~TribeJoinScreen();
    virtual long handle_idle();
    virtual long handle_user_command(unsigned int, long);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
protected:
    void fillList();
};

class TribeMPSetupScreen {
public:
    TribeMPSetupScreen();
    char data[0x890];
};

class TribeMPStartupScreen : public TScreenPanel {
public:
    TTextPanel* title;
    TTextPanel* inputTitle;
    TEditPanel* input;
    TTextPanel* connectionTitle;
    TButtonPanel* okButton;
    TButtonPanel* cancelButton;
    TButtonPanel* help_button;
    TButtonPanel* close_button;
    TListPanel* list;
    TScrollBarPanel* scrollbar;
    char zone_exec[255];
    char browser_exec[255];
    unsigned char pad_end[2];

    virtual ~TribeMPStartupScreen();
    TribeMPStartupScreen();
};

class TribeMPCreateDialog : public TDialogPanel {
public:
    TTextPanel* title;
    TTextPanel* input_title;
    TEditPanel* inputGamename;
    TButtonPanel* okButton;
    TButtonPanel* cancelButton;
    virtual ~TribeMPCreateDialog();
    TribeMPCreateDialog(TPanel* parent);
};

#endif
