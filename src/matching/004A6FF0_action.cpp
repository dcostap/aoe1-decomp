// VA: 004A6FF0, TRIBE_Dialog_Name::action, 469 bytes
// Source: scr_name.cpp lines 379-423
// FLAGS: config/flags/004A6FF0_action.rsp (/GX for original EH frame around new+ctor)
// Attempt log:
// - v1: natural reconstruction from packet/decompiler with local UI classes/globals.
// - v2: added /GX to get original EH registration prologue.
// - v3: added TPanel vptr/data and screen object sizes so member offsets and operator new sizes match.
// - v4: split cancel branch setCurrentPanel calls instead of target local to match push-args-before-shared-call layout.

typedef unsigned long ulong;

#ifdef SCR_NAME_TU_CONTEXT
#include "../../include/scr_name_context.h"
static char s_campaign[] = "Campaign Selection Screen";
static char s_new_name[] = "New Name Dialog";
static char s_name[] = "Name Selection Screen";
static char s_single[] = "Single Player Menu";
#else
void* operator new(unsigned int size);

class TPanel;
class TEditPanel;
class RGE_Game_Info;
class TRIBE_Screen_Campaign_Selection;
class TribeSPMenuScreen;

class TPanel {
public:
    virtual ~TPanel();
    void set_curr_child(TPanel* child);
};

class TEasy_Panel : public TPanel {
public:
    long action(TPanel* panel, long p2, ulong p3, ulong p4);
};

class TEditPanel : public TPanel {
public:
    char* get_text();
};

class RGE_Game_Info {
public:
    unsigned char add_new_person(char* name);
};

class RGE_Base_Game {
public:
    char gap_00[4];
    RGE_Game_Info* player_game_info;
};

extern RGE_Base_Game* rge_base_game;

class TPanelSystem {
public:
    TPanel* panel(char* name);
    int setCurrentPanel(char* name, int flags);
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;

class TRIBE_Screen_Campaign_Selection {
public:
    char data[0x4cc];
    TRIBE_Screen_Campaign_Selection();
};

class TribeSPMenuScreen {
public:
    char data[0x49c];
    TribeSPMenuScreen();
};

static char s_campaign[] = "Campaign Selection Screen";
static char s_new_name[] = "New Name Dialog";
static char s_name[] = "Name Selection Screen";
static char s_single[] = "Single Player Menu";

class TRIBE_Dialog_Name : public TEasy_Panel {
public:
    char gap_04[0x498 - 4];
    TEditPanel* name_input; // +498
    TPanel* ok_button;      // +49c
    TPanel* cancel_button;  // +4a0

    long action(TPanel* panel, long p2, ulong p3, ulong p4);
};
#endif

long TRIBE_Dialog_Name::action(TPanel* panel, long p2, ulong p3, ulong p4)
{
    if (panel != 0) {
        if ((panel == this->ok_button && p2 == 1) || (panel == this->name_input && p2 == 0)) {
            if (this->name_input->get_text()[0] == 0) {
                this->set_curr_child(this->name_input);
                return 1;
            }
            RGE_Game_Info* info = rge_base_game->player_game_info;
            info->add_new_person(this->name_input->get_text());
            TRIBE_Screen_Campaign_Selection* screen = new TRIBE_Screen_Campaign_Selection;
            panel_system.setCurrentPanel(s_campaign, 0);
            panel_system.destroyPanel(s_new_name);
            panel_system.destroyPanel(s_name);
            return 1;
        }

        if ((panel == this->cancel_button && p2 == 1) || (panel == this->name_input && p2 == 1)) {
            if (panel_system.panel(s_name) != 0) {
                panel_system.setCurrentPanel(s_name, 0);
            } else {
                TribeSPMenuScreen* screen2 = new TribeSPMenuScreen;
                panel_system.setCurrentPanel(s_single, 0);
            }
            panel_system.destroyPanel(s_new_name);
            return 1;
        }
    }

    return TEasy_Panel::action(panel, p2, p3, p4);
}
