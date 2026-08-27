#ifndef AOE1_SCR_CJ_H
#define AOE1_SCR_CJ_H

// Declarations owned by scr_cj.cpp.
// It overlays the proven +0x20 render-area and +0x40 parent fields with the
// shared TPanel +0xD8 error layout.
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
    int RegSetAscii(int, const char*, unsigned char*, unsigned long);
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

// BINARY NOTE: TEditPanel is a direct TPanel child.
class TEditPanel : public TPanel {
public:
    int is_blank();
    char* currentLine();
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

struct _GUID {
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
};

class TCommunications_Handler {
public:
    char gap_000[0x12DC];
    _GUID ServiceGUID;
    char gap_12EC[0xD0];
    unsigned long PlayerStopTurn[10];

    void SetPlayerHumanity(unsigned int player, int humanity);
    int JoinMultiplayerGame(_GUID* guid);
    void UnlinkToLevel(int param);
    int SetGameTitle(char*);
    int CreateMultiplayerGame();
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
    void show_status_message(int, char*, long);
};

class TRIBE_Game : public RGE_Base_Game {
};

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int param);
    int destroyPanel(char* name);
};

class TDebuggingLog {
public:
    void Log(char*, ...);
};

extern TCommunications_Handler* comm;
extern TCommunications_Sessions* Sess;
extern TRIBE_Game* rge_base_game;
extern TPanelSystem panel_system;
extern TRegistry* Regs;
extern TDebuggingLog* L;

extern "C" void* __cdecl operator_delete(void* ptr);
extern "C" unsigned long __cdecl debug_timeGetTime(char* file, int line);
extern "C" const _GUID DPSPGUID_TCPIP;
extern "C" int (__stdcall* const WinExec)(char*, int);
extern "C" void* (__stdcall* const FindWindowA)(char*, char*);
extern "C" int (__stdcall* const SendMessageA)(void*, int, int, int);

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
protected:
    virtual long action(TPanel*, long, unsigned long, unsigned long);
};

class IDirectDraw {
public:
    virtual long __stdcall QueryInterface();
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall Compact();
    virtual long __stdcall CreateClipper(unsigned long, void**, void*);
    virtual long __stdcall CreatePalette(unsigned long, void*, void**, void*);
    virtual long __stdcall CreateSurface();
    virtual long __stdcall DuplicateSurface();
    virtual long __stdcall EnumDisplayModes();
    virtual long __stdcall EnumSurfaces();
    virtual long __stdcall FlipToGDISurface();
};

class TDrawSystem {
public:
    IDirectDraw* gap_00;
    char gap_04[0x14];
    IDirectDraw* DirDraw;
    char gap_1C[0x45C];
    unsigned char DrawType;
    unsigned char ScreenMode;
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;
};

#endif
