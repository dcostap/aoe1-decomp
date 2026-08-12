// VA: 0049F370 TribeMPStartupScreen constructor (1278B)
// scr_mp.cpp lines 68-220
//
// Baseline reconstruction: the period screen factory sequence, named panel
// ownership, local registry buffers, and the observed browser/Zone setup.
//
// Probe 1 baseline: exact frame and 33-call set; 1104 differing bytes.
// Probe 2 removed an unsupported Data owner store; diff 711.
// Probe 3 reversed the registry-name branch and improved local buffer order;
// diff 646.
// Probe 4 grouped the three proven adjacent buffers; diff 639.
// Probe 5 kept top-level output pointers and reached the best diff, 616.
// Probes 6 and 9 changed pointer lifetime and returned to the same basin.
// Probe 10 added the decompiler Data prefix store; it widened the diff and was
// restored to probe 5.
// Left in scratch: frame, size, CFG, and call set match. Remaining drift is
// VC5 local-home and register assignment around the constructor prologue and
// registry window. No evidence-backed source lead remains in this session.
// FLAGS: config/flags/0049F370_TribeMPStartupScreen.rsp (/GX for EH cleanup).

#include <string.h>

struct tagRECT;
class TDrawArea;
class TTextPanel;
class TListPanel;
class TScrollBarPanel;
class TButtonPanel;

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

    char gap_04[0xD4];
    int setup_error;                         // +0xD8
    char gap_DC[0x18];                       // sizeof(TPanel) == 0xF4

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
    virtual void vf45();
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

    void set_help_info(long id, long value);
    void set_curr_child(TPanel* child);
    void set_tab_order(TPanel** panels, short count);
};

class TTextPanel : public TPanel {
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
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];

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
};

class RGE_Base_Game {
public:
    char gap_00[0x4C];
    TDrawArea* draw_area;

    void setMultiplayerGame(int value);
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

class TribeMPStartupScreen : public TScreenPanel {
public:
    TTextPanel* title;                 // +0x478
    TTextPanel* inputTitle;            // +0x47C
    TEditPanel* input;                 // +0x480
    TTextPanel* connectionTitle;       // +0x484
    TButtonPanel* okButton;            // +0x488
    TButtonPanel* cancelButton;        // +0x48C
    TButtonPanel* help_button;         // +0x490
    TButtonPanel* close_button;        // +0x494
    TListPanel* list;                  // +0x498
    TScrollBarPanel* scrollbar;        // +0x49C
    char zone_exec[0xFF];              // +0x4A0
    char browser_exec[0x101];          // +0x59F

    virtual ~TribeMPStartupScreen();
    TribeMPStartupScreen();
    void fillList();
};

extern TRegistry* Regs;
extern RGE_Base_Game* rge_base_game;

TribeMPStartupScreen::TribeMPStartupScreen()
    : TScreenPanel("MP Startup Screen")
{
    TButtonPanel** cancel_button;
    TListPanel** list;
    TButtonPanel** ok_button;
    HKEY ghUserKey;
    unsigned long dwSize;
    unsigned long dwType;
    TPanel* tabList[5];
    unsigned long gdwDisp;
    struct LocalStrings {
        char Data[255];
        char pad_Data;
        char temp_str[255];
        char pad_temp;
        char str[256];
    } strings;

    cancel_button = &this->cancelButton;
    list = &this->list;
    this->help_button = 0;
    this->okButton = 0;
    *cancel_button = 0;
    this->close_button = 0;

    rge_base_game->setMultiplayerGame(0);
    if (this->setup(rge_base_game->draw_area, "scr3", 0xC385, 1) == 0) {
        this->setup_error = 1;
        return;
    }

    this->setup_shadow_area(0);
    this->set_ideal_size(0x280, 0x1E0);

    if (this->create_text(this, &this->title, 0x258B,
                          0x14, 0x14, 600, 0x1E, 1, 1, 0, 0) &&
        this->create_text(this, &this->inputTitle, 0x258C,
                          0x14, 0x4B, 500, 0x14, 4, 0, 0, 0)) {
        char* player_name = Regs->RegGetAscii(
            1, "Default Age Of Empires Player Name");
        if (player_name != 0) {
            strcpy(strings.str + 4, Regs->RegGetAscii(
                1, "Default Age Of Empires Player Name"));
        } else {
            strings.str[4] = 0;
        }

        if (this->create_edit(this, &this->input, strings.str + 4, 0x0F, 0,
                              0x14, 100, 600, 0x17, 0x0B, 1, 0)) {
            this->input->set_help_info(0x7595, -1);
            if (this->create_text(this, &this->connectionTitle, 0x258D,
                                  0x14, 0xA5, 600, 0x14, 4, 0, 0, 0) &&
                this->create_list(this, list,
                                  0x14, 0xBE, 600, 0xD2, 0x0B) &&
                this->create_auto_scrollbar(&this->scrollbar, *list, 0x14)) {
                (*list)->set_help_info(0x7596, 0x25F08);
                ok_button = &this->okButton;
                if (this->create_button(this, ok_button, 0x0FA1,
                                        0, 0x46, 0x1B8, 0xF0, 0x1E,
                                        0, 0, 0)) {
                    (*ok_button)->set_help_info(0x7531, -1);
                    TButtonPanel* cancel = *cancel_button;
                    if (this->create_button(this, cancel_button, 0x0FA2,
                                            0, 0x14A, 0x1B8, 0xF0, 0x1E,
                                            0, 0, 0)) {
                        cancel->set_help_info(0x7532, -1);
                        cancel->hotkey = 0x1B;
                        cancel->hotkey_shift = 0;
                        if (this->create_button(this, &this->help_button,
                                                0x0FA9, 0, 0x244, 0x1B8,
                                                0x1E, 0x1E, 0, 0, 0)) {
                            cancel_button = &this->close_button;
                            if (this->create_button(this, cancel_button,
                                                    0x03EA, 0, 0, 0, 0, 0,
                                                    -1, -1, 0)) {
                                (*cancel_button)->set_active(1);
                                (*cancel_button)->set_positioning(
                                    9, 4, 4, 4, 4, 0x11, 0x11,
                                    0x11, 0x11, 0, 0, 0, 0);

                                this->zone_exec[0] = 0;
                                this->browser_exec[0] = 0;
                                RegCreateKeyExA(
                                    (HKEY)0x80000000,
                                    "http\\shell\\open\\command", 0, 0, 0,
                                    0xF003F, 0, &ghUserKey, &gdwDisp);
                                dwType = 1;
                                dwSize = 0xFF;
                                int result = RegQueryValueExA(
                                    ghUserKey, 0, 0, &dwType,
                                    (unsigned char*)(strings.Data + 4), &dwSize);
                                if (ghUserKey != 0) {
                                    RegCloseKey(ghUserKey);
                                    ghUserKey = 0;
                                }

                                if (result == 0) {
                                    strncpy(strings.temp_str + 4,
                                            strings.Data + 4,
                                            strlen(strings.Data + 4) - 1);
                                    char* quote = strchr(strings.temp_str + 4,
                                                         0x22);
                                    if (quote != 0) {
                                        int length = quote -
                                            (strings.temp_str + 4) + 1;
                                        strncpy(this->browser_exec,
                                                strings.temp_str + 4,
                                                length - 1);
                                        this->browser_exec[length - 1] = 0;
                                    }

                                    char* zone = Regs->RegGetAscii(0, "Zone");
                                    if (zone != 0) {
                                        strcpy(strings.temp_str + 4, zone);
                                        strcpy(this->zone_exec,
                                               strings.temp_str + 4);
                                    }
                                }

                                this->fillList();
                                this->set_curr_child(this->input);
                                tabList[3] = this->okButton;
                                tabList[1] = this->input;
                                tabList[2] = *list;
                                tabList[4] = *cancel_button;
                                this->set_tab_order(tabList + 1, 5);
                            }
                        }
                    }
                }
            }
        }
    }
}
