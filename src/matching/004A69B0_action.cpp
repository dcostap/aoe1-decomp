// VA: 004A69B0 TRIBE_Screen_Name::action
// FLAGS: config/flags/004A69B0_action.rsp (/GX for the original new/constructor EH frame)
// Attempt log:
// prior attempts used guessed save-options/message-box APIs and a flattened
// TEasy_Panel base; they were broad mismatches despite the nominal 914-byte size.
// baseline candidate: restored scr_name.cpp's canonical TPanel -> TEasy_Panel ->
// TScreenPanel ownership, real action/popup/get_string member surfaces, the
// executable's disable_input/set_current_person/remove_player calls, and the
// two natural panel-name dispatch predicates.  The source follows the packet's
// branch topology and keeps the typed child-panel fields at +0x480..+0x498.
// exact: /GX was required through the target-slug response file; a canonical
// player-info local fixed the removal call's global/load evaluation order.  The
// compiler's natural local placement makes the plain 256-byte message buffer
// land at the oracle's two popup/sprintf addresses; retaining the decompiler's
// str+4 spelling left only those two LEA displacements wrong. Result: MATCH.

#include <string.h>
#include <stdio.h>

#ifdef SCR_NAME_TU_CONTEXT
#include "../../include/scr_name_context.h"
#else
#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)

class TPanel {
public:
    virtual ~TPanel();
    VPAD32(0)
    VPAD8(32)
    VPAD4(40)
    virtual long action(TPanel*, long, unsigned long, unsigned long);

    char gap_04[0xF0];

    char* panelName();
    char* get_string(int id);
};

class TTextPanel : public TPanel {
public:
    long get_line();
    char* get_text();
    long get_id();
    long get_id(long line);
};

class TListPanel : public TTextPanel {
};

class TButtonPanel : public TPanel {
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];

    virtual long action(TPanel*, long, unsigned long, unsigned long);
    void popupYesNoDialog(char* text, char* name, long type, long timeout);
};

class TScreenPanel : public TEasy_Panel {
};

class RGE_Game_Info {
public:
    unsigned char set_current_person(long person);
    void remove_player(long person);
};

class RGE_Base_Game {
public:
    char gap_00[4];
    RGE_Game_Info* player_game_info;

    void disable_input();
    void close();
};

extern RGE_Base_Game* rge_base_game;

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int mode);
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;

class TRIBE_Screen_Campaign_Selection : public TEasy_Panel {
public:
    char data[0x54];
    TRIBE_Screen_Campaign_Selection();
    virtual ~TRIBE_Screen_Campaign_Selection();
};

class TribeSPMenuScreen : public TScreenPanel {
public:
    char data[0x24];
    TribeSPMenuScreen();
    virtual ~TribeSPMenuScreen();
};

class TDialogPanel : public TEasy_Panel {
public:
    char gap_478[0x18];
    virtual ~TDialogPanel();
    TDialogPanel(char* name);
};

class TRIBE_Dialog_Name : public TDialogPanel {
public:
    char data[0x14];
    TRIBE_Dialog_Name(TScreenPanel* parent);
    virtual ~TRIBE_Dialog_Name();
};

class TRIBE_Screen_Name : public TScreenPanel {
public:
    TPanel* title;                 // +0x478
    TPanel* name_text;             // +0x47C
    TListPanel* name_list;         // +0x480
    TPanel* name_scrollbar;        // +0x484
    TButtonPanel* new_button;      // +0x488
    TButtonPanel* remove_button;   // +0x48C
    TButtonPanel* ok_button;       // +0x490
    TButtonPanel* cancel_button;   // +0x494
    TButtonPanel* close_button;    // +0x498

    virtual long action(TPanel* panel, long event, unsigned long p3,
                        unsigned long p4);
    void get_player_names();
    void setup_tab_order();
};
#endif

long TRIBE_Screen_Name::action(TPanel* panel, long event, unsigned long p3,
                               unsigned long p4)
{
    long line;
    char str[256];

    if (panel != 0) {
        if (panel == this->ok_button && event == 1) {
            line = this->name_list->get_line();
            if (line == -1) {
                return event;
            } else {
                rge_base_game->disable_input();
                RGE_Game_Info* info = rge_base_game->player_game_info;
                info->set_current_person(this->name_list->get_id());
                new TRIBE_Screen_Campaign_Selection;
                panel_system.setCurrentPanel("Campaign Selection Screen", 0);
                panel_system.destroyPanel("Name Selection Screen");
            }
            return 1;
        }

        if (panel == this->cancel_button && event == 1) {
            rge_base_game->disable_input();
            new TribeSPMenuScreen;
            panel_system.setCurrentPanel("Single Player Menu", 0);
            panel_system.destroyPanel("Name Selection Screen");
            return 1;
        }

        if (panel == this->close_button) {
            rge_base_game->close();
            return 1;
        }

        if (panel == this->name_list && event == 3) {
            this->action(this->ok_button, 1, 0, 0);
            return 1;
        }

        if (panel == this->new_button && event == 1) {
            new TRIBE_Dialog_Name(this);
            panel_system.setCurrentPanel("New Name Dialog", 0);
            return 1;
        }

        if (panel == this->remove_button && event == 1) {
            if (this->name_list->get_line() != -1) {
                sprintf(str, this->get_string(0x2A02),
                        this->name_list->get_text());
                this->popupYesNoDialog(str, 0, 0x1C2, 100);
                return event;
            }
            return 1;
        } else {
            if (panel->panelName() != 0 &&
                strcmp(panel->panelName(), "New Name Dialog") == 0) {
                if (event == 1) {
                    this->get_player_names();
                }
                panel_system.setCurrentPanel("Name Selection Screen", 0);
                panel_system.destroyPanel("New Name Dialog");
                this->setup_tab_order();
                return 1;
            }

            if (panel->panelName() != 0 &&
                strcmp(panel->panelName(), "YesNoDialog") == 0) {
                if (event == 0) {
                    line = this->name_list->get_line();
                    if (line != -1) {
                        RGE_Game_Info* info = rge_base_game->player_game_info;
                        info->remove_player(this->name_list->get_id(line));
                        this->get_player_names();
                    }
                }
                panel_system.destroyPanel("YesNoDialog");
                this->setup_tab_order();
                return 1;
            }
        }
    }

    return this->TEasy_Panel::action(panel, event, p3, p4);
}
