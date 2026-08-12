// VA: 0049F9D0 TribeMPStartupScreen::action (1265B)
// scr_mp.cpp lines 258-365
//
// Baseline reconstruction: named startup-screen fields, typed panel calls,
// the local communications-services lifetime, and the three panel-name
// dispatch paths from the executable.
//
// Probe 1 baseline: natural typed reconstruction reached 1173 differing bytes.
// Probe 2 flags: /GX restored the 0x2598 EH frame and reduced the diff to 1161.
// Probe 3 control-flow: outer non-null dispatch and a shared close tail reached
// 1029 differing bytes with exact call order and frame size.
// Probe 4 control-flow: direct returns from popup, join, and cancel arms reached
// exact size and 1 differing byte.
// Probe 5 control-flow: separate zone acceptance and close labels reached MATCH.
// The shared close labels preserve the binary's event-zero WinExec gate.
// Exact: positional bytes match. VC5 emits its __chkstk/__alloca_probe alias.
// FLAGS: config/flags/0049F9D0_action.rsp (/GX for local EH cleanup).

#include <string.h>

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)

class TPanel {
public:
    virtual ~TPanel();
    VPAD32(0)
    VPAD8(32)
    VPAD4(40)
    virtual long action(TPanel*, long, unsigned long, unsigned long);

    char gap_04[0xF0];

    char* panelName();
    void set_curr_child(TPanel* child);
};

class TTextPanel : public TPanel {
public:
    int numberLines();
    long get_id();
    char* get_text();
};

class TListPanel : public TTextPanel {
};

class TEditPanel : public TPanel {
public:
    char* get_text();
    char* currentLine();
};

class TButtonPanel : public TPanel {
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];

    virtual long action(TPanel*, long, unsigned long, unsigned long);
    void popupOKDialog(long text_id, char* panel_name, int width, int height);
    void popupYesNoDialog(long text_id, char* panel_name, int width, int height);
    void setup_popup_help();
};

class TScreenPanel : public TEasy_Panel {
};

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
    TPanel* scrollbar;                 // +0x49C
    char zone_exec[0x100];             // +0x4A0

    virtual long action(TPanel*, long, unsigned long, unsigned long);
};

class TRegistry {
public:
    int RegSetAscii(int use_user, const char* name, unsigned char* value,
                    unsigned long size);
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
};

class TCommunications_Handler {
public:
    void SetMyPlayerName(char* name);
    void SetServiceGUID(_GUID guid);
    void InitJoinGame();
    void UnlinkToLevel(int level);
};

class RGE_Base_Game {
public:
    void setMultiplayerGame(int multiplayer);
    void disable_input();
    void close();
};

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int mode);
    int destroyPanel(char* name);
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

extern TRegistry* Regs;
extern TCommunications_Handler* comm;
extern RGE_Base_Game* rge_base_game;
extern TPanelSystem panel_system;
extern "C" int (__stdcall* const WinExec)(char*, int);

void* __cdecl operator new(unsigned int size);

long TribeMPStartupScreen::action(TPanel* panel, long event,
                                  unsigned long param3, unsigned long param4)
{
    if (panel != 0) {
        if (panel == this->list && event == 3) {
            this->action(this->okButton, 1, 0, 0);
            return 1;
        }

        if (panel == this->close_button && event == 1) {
            goto close_action;
        } else {
            if (panel == this->okButton && event == 1) {
                rge_base_game->setMultiplayerGame(1);
                if (*this->input->get_text() == 0) {
                    this->popupOKDialog(0x258F, "Name Error", 0x1C2, 100);
                    return event;
                } else if (this->list->numberLines() == 0) {
                    this->popupOKDialog(0x2592, "List Error", 0x1C2, 100);
                    return 1;
                } else if (this->zone_exec[0] == 0 || this->list->get_id() != -1) {
                    rge_base_game->disable_input();
                    Regs->RegSetAscii(1,
                        "Default Age Of Empires Player Name",
                        (unsigned char*)this->input->currentLine(),
                        strlen(this->input->currentLine()) + 1);
                    Regs->RegSetAscii(1,
                        "Default Age Of Empires Multiplayer Service",
                        (unsigned char*)this->list->get_text(),
                        strlen(this->list->get_text()) + 1);
                    comm->SetMyPlayerName(this->input->currentLine());

                    TCommunications_Services services;
                    comm->SetServiceGUID(services.GetServiceGUID(this->list->get_id()));
                    comm->InitJoinGame();

                    new TribeJoinScreen;
                    panel_system.setCurrentPanel("Join Screen", 0);
                    panel_system.destroyPanel("MP Startup Screen");
                    return 1;
                } else {
                    this->popupYesNoDialog(0x2593, "Start Zone", 0x1C2, 100);
                    return 1;
                }
            }

            if ((panel == this->cancelButton && event == 1) ||
                (panel == this->input && event == 1)) {
                rge_base_game->disable_input();
                comm->UnlinkToLevel(2);
                new TRIBE_Screen_Main_Menu;
                panel_system.setCurrentPanel("Main Menu", 0);
                panel_system.destroyPanel("MP Startup Screen");
                return 1;
            }

        if (panel == this->help_button && event == 1) {
            this->setup_popup_help();
            return event;
        }

        if (panel->panelName() != 0 &&
            strcmp(panel->panelName(), "List Error") == 0) {
            panel_system.destroyPanel("List Error");
            this->set_curr_child(this->list);
            event = 1;
            return event;
        }

        if (panel->panelName() != 0 &&
            strcmp(panel->panelName(), "Name Error") == 0) {
            panel_system.destroyPanel("Name Error");
            this->set_curr_child(this->input);
            event = 1;
            return event;
        }

            if (panel->panelName() != 0 &&
                strcmp(panel->panelName(), "Start Zone") == 0) {
                panel_system.destroyPanel("Start Zone");
                this->set_curr_child(this->list);
                if (event == 0) {
                    rge_base_game->disable_input();
                    WinExec(this->zone_exec, 3);
                    goto close_action;
                }
                goto success;
            }
        }
    }

    goto fallback;

close_action:
    rge_base_game->close();

success:
    return 1;

fallback:
    return this->TEasy_Panel::action(panel, event, param3, param4);
}
