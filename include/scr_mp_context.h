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

    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void set_string_id(long id);
    virtual long handle_idle();

    char gap_04[0xD4];
    int setup_error;
    char gap_DC[0x18];

    char* panelName();
    void set_help_info(long id, long value);
    void set_curr_child(TPanel* child);
    void set_tab_order(TPanel** panels, short count);
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
    void set_ideal_size(long width, long height);
    int create_text(TPanel* parent, TTextPanel** output, long string_id,
                    long x, long y, long width, long height,
                    long font, long align, long center, long wrap);
    int create_edit(TPanel* parent, TEditPanel** output, char* text,
                    short width, int format, int a6, int a7, int a8,
                    int a9, int a10, int a11, int a12);
    int create_list(TPanel* parent, TListPanel** output,
                    long x, long y, long width, long height, long lines);
    int create_auto_scrollbar(TScrollBarPanel** output,
                              TTextPanel* text, long width);
    int create_button(TPanel* parent, TButtonPanel** output, long string_id,
                      long text2, long x, long y, long width, long height,
                      long p9, long p10, long p11);
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
    long handle_idle();
    int handle_user_command(int p0, int p1);
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
