// Authentic scr_mp.cpp translation-unit context.
//
// The PDB source order is the order of the six owner bodies included by
// src/scr_mp_tu.cpp.  This declaration surface combines the period class
// and API declarations used by those bodies.  It keeps one compiler-facing
// type for each object while retaining the proven virtual-slot positions.
#ifndef AOE1_SCR_MP_CONTEXT_H
#define AOE1_SCR_MP_CONTEXT_H

#include <string.h>

struct tagRECT;
class TDrawArea;
class TTextPanel;
class TListPanel;
class TScrollBarPanel;
class TButtonPanel;
class TEditPanel;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup();
    virtual void set_rect(tagRECT rect);
    virtual void set_rect(long left, long top, long right, long bottom);
    virtual void set_color(unsigned char color);
    virtual void set_active(int active);
    virtual void set_positioning(long mode, long a2, long a3, long a4,
                                 long a5, long a6, long a7, long a8,
                                 long a9, TPanel* a10, TPanel* a11,
                                 TPanel* a12, TPanel* a13);

    virtual void set_fixed_position(long left, long top, long right,
                                    long bottom);
    virtual void set_redraw(int mode);
    virtual void set_overlapped_redraw(TPanel* first, TPanel* second,
                                       int mode);
    virtual void draw_setup(int force_rebuild);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(tagRECT* rect);
    virtual void draw_offset(long x, long y, tagRECT* rect);
    virtual void draw_rect2(tagRECT* rect);
    virtual void draw_offset2(long x, long y, tagRECT* rect);
    virtual void paint();
    virtual long wnd_proc(void* message, unsigned int message_id,
                          unsigned int wparam, long lparam);
    virtual long handle_idle();
    virtual long handle_size(long width, long height);
    virtual long handle_paint();
    virtual long handle_key_down(long key, short scan_code, int a3, int a4,
                                 int a5);
    virtual long handle_char(long key, short scan_code);
    virtual long handle_command(unsigned int command, long value);
    virtual long handle_user_command(unsigned int command, long value);
    virtual long handle_timer_command(unsigned int command, long value);
    virtual long handle_scroll(long value, long direction);
    virtual long handle_mouse_down(unsigned char button, long x, long y,
                                   int a4, int a5);
    virtual long handle_mouse_move(long x, long y, int a3, int a4);
    virtual long handle_mouse_up(unsigned char button, long x, long y,
                                 int a4, int a5);
    virtual long handle_mouse_dbl_click(unsigned char button, long x, long y,
                                        int a4, int a5);
    virtual long mouse_move_action(long x, long y, int a3, int a4);
    virtual long mouse_left_down_action(long x, long y, int a3, int a4);
    virtual long mouse_left_hold_action(long x, long y, int a3, int a4);
    virtual long mouse_left_move_action(long x, long y, int a3, int a4);
    virtual long mouse_left_up_action(long x, long y, int a3, int a4);
    virtual long mouse_left_dbl_click_action(long x, long y, int a3, int a4);
    virtual long mouse_right_down_action(long x, long y, int a3, int a4);
    virtual long mouse_right_hold_action(long x, long y, int a3, int a4);
    virtual long mouse_right_move_action(long x, long y, int a3, int a4);
    virtual long mouse_right_up_action(long x, long y, int a3, int a4);
    virtual long mouse_right_dbl_click_action(long x, long y, int a3, int a4);
    virtual long key_down_action(long key, short scan_code, int a3, int a4,
                                 int a5);
    virtual long char_action(long key, short scan_code);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void get_true_render_rect(tagRECT* rect);
    virtual int is_inside(long x, long y);
    virtual void set_focus(int focus);
    virtual void set_tab_order(TPanel* first, TPanel* second);
    virtual void set_tab_order(TPanel** panels, short count);
    virtual unsigned char get_help_info(char** text, long* page,
                                        long a3, long a4);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();
    virtual void draw_background(int force_rebuild);

    char gap_04[0xD4];
    int setup_error;
    char gap_DC[0x18];

    char* panelName();
    void set_help_info(long id, long value);
    void set_curr_child(TPanel* child);
    void delete_panel(TPanel** panel);
};

class TTextPanel : public TPanel {
public:
    int numberLines();
    long get_id();
    char* get_text();
    void empty_list();
    int append_line(char* line, long param);
    int append_line(long string_id, long param);
    long get_line(long index);
    void set_line(long line);
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
};

class TEditPanel : public TPanel {
public:
    char* get_text();
    char* currentLine();
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];

    virtual long action(TPanel*, long, unsigned long, unsigned long);
    void setup_shadow_area(int force_rebuild);
    virtual void set_ideal_size(long width, long height);
    virtual int create_button(TPanel* parent, TButtonPanel** output,
                              long string_id, long text2, long x, long y,
                              long width, long height, long p9, long p10,
                              long p11);
    virtual int create_button(TPanel* parent, TButtonPanel** output,
                              char* string_id, char* text2, long x, long y,
                              long width, long height, long p9, long p10,
                              long p11);
    virtual int create_check_box(TPanel* parent, TButtonPanel** output,
                                 long string_id, long x, long y, long width,
                                 long height, long p8);
    virtual int create_radio_button(TPanel* parent, TButtonPanel** output,
                                    long string_id, long x, long y, long width,
                                    long height, long p8);
    virtual int create_text(TPanel* parent, TTextPanel** output, long string_id,
                    long x, long y, long width, long height,
                    long font, long align, long center, long wrap);
    virtual int create_text(TPanel* parent, TTextPanel** output, char** text,
                            long x, long y, long width, long height,
                            long font, long align, int center, int wrap);
    virtual int create_text(TPanel* parent, TTextPanel** output, char* text,
                            long x, long y, long width, long height,
                            long font, int align, int center, int wrap);
    virtual int create_input(TPanel* parent, TPanel** output, char* text,
                             short width, int format, long a6, long a7,
                             long a8, long a9, long a10);
    virtual int create_edit(TPanel* parent, TEditPanel** output, char* text,
                    short width, int format, int a6, int a7, int a8,
                    int a9, int a10, int a11, int a12);
    virtual int create_drop_down(TPanel* parent, TPanel** output, long a3,
                                 long a4, long a5, long a6, long a7, long a8,
                                 long a9);
    virtual int create_list(TPanel* parent, TListPanel** output,
                    long x, long y, long width, long height, long lines);
    virtual int create_scrollbar(TPanel* parent, TScrollBarPanel** output,
                                 TTextPanel* text, long a4, long a5, long a6,
                                 long a7, long a8);
    virtual int create_auto_scrollbar(TScrollBarPanel** output,
                              TTextPanel* text, long width);
    virtual int create_vert_slider(TPanel* parent, TPanel** output, long a3,
                                   long a4, long a5, long a6, long a7, long a8,
                                   long a9);
    virtual int create_horz_slider(TPanel* parent, TPanel** output, long a3,
                                   long a4, long a5, long a6, long a7, long a8,
                                   long a9);
    virtual void position_panel(TPanel* panel, long a2, long a3, long a4,
                                long a5);
    void popupOKDialog(long text_id, char* panel_name, int width, int height);
    void popupYesNoDialog(long text_id, char* panel_name, int width, int height);
    void setup_popup_help();
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char* name);
    virtual ~TScreenPanel();
    long setup(TDrawArea* draw_area, char* info_file, long info_id,
               int param);
};

class TRegistry {
public:
    char* RegGetAscii(int use_user, char* name);
    int RegSetAscii(int use_user, const char* name, unsigned char* value,
                    unsigned long size);
};

typedef struct HKEY__* HKEY;
typedef long (__stdcall *RegCreateKeyExA_t)(
    HKEY, const char*, unsigned long, const char*, unsigned long,
    unsigned long, void*, HKEY*, unsigned long*);
typedef long (__stdcall *RegQueryValueExA_t)(
    HKEY, const char*, unsigned long*, unsigned long*, unsigned char*,
    unsigned long*);
typedef long (__stdcall *RegCloseKey_t)(HKEY);

extern "C" RegCreateKeyExA_t const RegCreateKeyExA;
extern "C" RegQueryValueExA_t const RegQueryValueExA;
extern "C" RegCloseKey_t const RegCloseKey;

class RGE_Base_Game {
public:
    char gap_00[0x4C];
    TDrawArea* draw_area;
    char gap_50[0x188];
    int input_enabled;

    void setMultiplayerGame(int value);
    void disable_input();
    void close();
    void enable_input();
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
    char zone_exec[0xFF];
    char browser_exec[0x101];

    virtual ~TribeMPStartupScreen();
    TribeMPStartupScreen();
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual long handle_idle();
    virtual long handle_user_command(unsigned int p0, long p1);

protected:
    void fillList();
};

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int mode);
    int destroyPanel(char* name);
};

struct _GUID {
    unsigned long Data1;
    unsigned long Data2;
    unsigned long Data3;
    unsigned long Data4;
};

class TCommunications_Services {
public:
    char data[0x2584];
    TCommunications_Services();
    ~TCommunications_Services();
    _GUID GetServiceGUID(int index);
    int GetServiceCount();
    int GetServiceActive(int index);
    char* GetServiceName(int index);
};

class TCommunications_Handler {
public:
    void SetMyPlayerName(char* name);
    void SetServiceGUID(_GUID guid);
    void InitJoinGame();
    void UnlinkToLevel(int level);
};

class TribeJoinScreen : public TScreenPanel {
public:
    char data[0x38];
    TribeJoinScreen();
};

class TRIBE_Screen_Main_Menu : public TScreenPanel {
public:
    char data[0x38];
    TRIBE_Screen_Main_Menu();
};

struct FindDataLocal {
    char data[0x118];
};

extern "C" long __cdecl _findfirst(char* filespec, FindDataLocal* fileinfo);

extern TRegistry* Regs;
extern TCommunications_Handler* comm;
extern RGE_Base_Game* rge_base_game;
extern TPanelSystem panel_system;
extern "C" int (__stdcall* const WinExec)(char*, int);

void* __cdecl operator new(unsigned int size);

#endif
