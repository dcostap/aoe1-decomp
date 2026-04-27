// TRIBE_Screen_Sed_Menu::action
// VA: 004B31D0
// PDB: scr_sedm.cpp:114-154
// FLAGS: /GX (EH-framed)
//
// Attempt log:
// - initial (empty body): compiler optimized to 160 bytes, no EH frame
// - draft with new/panel calls: EH frame works, 58% diff
// - cmp operand order fix + added start_scenario_editor call: 5.98% diff
// - removed <new.h>, direct operator new decl: same 5.98%
//
// Remaining diff (~6%):
// - Jump target displacements differ by 0x0E (14 bytes) due to cascade from
//   slightly different end-of-function layout
// - New-result stack slot at [esp+20h] vs original [esp+14h] (+0xC offset)
// - All other diffs are relocations (39 masked): exception handler address,
//   string addresses, call targets, globals (panel_system, rge_base_game)
//
// Likely needs TU-context / donor-file include context to fix the stack/scheduling
// basin. Left in scratch as a near-match.

#include "..\..\include\game_globals.h"
#include <new.h>

class TPanel {
public:
    char gap_00[0x54];
    virtual ~TPanel() {}
    virtual long action(TPanel* p1, long p2, unsigned long p3, unsigned long p4) { return 0; }
};

class TEasy_Panel : public TPanel {
public:
    char gap_58[0x420];
    virtual long action(TPanel* p1, long p2, unsigned long p3, unsigned long p4);
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char* name);
    ~TScreenPanel();
};

class TButtonPanel : public TPanel {
public:
};

class TTextPanel : public TPanel {
public:
};

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int flags);
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;

class RGE_Base_Game_Local {
public:
    char gap_00[0x4C];
    void start_scenario_editor(char*, long);
    void disable_input();
    void close();
};

static const char s_Scenario_Editor_Menu[] = "Scenario Editor Menu";
static const char s_Scenario_Editor_Open[] = "Scenario Editor Open";
static const char s_Campaign_Editor_Screen[] = "Campaign Editor Screen";
static const char s_Main_Menu[] = "Main Menu";

class TRIBE_Screen_Sed_Open {
public:
    char gap_00[0x490];
    TRIBE_Screen_Sed_Open();
};

class TRIBE_Campaign_Editor_Screen {
public:
    char gap_00[0x4C4];
    TRIBE_Campaign_Editor_Screen();
};

class TRIBE_Screen_Main_Menu {
public:
    char gap_00[0x4B0];
    TRIBE_Screen_Main_Menu();
};

class TRIBE_Screen_Sed_Menu : public TScreenPanel {
public:
    TTextPanel* title;
    TButtonPanel* button[4];
    TButtonPanel* close_button;

    virtual long handle_idle();
    virtual long action(TPanel* p1, long p2, unsigned long p3, unsigned long p4);
};

long TRIBE_Screen_Sed_Menu::action(
    TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4)
{
    if (!param_1 || param_2 != 1)
        return TEasy_Panel::action(param_1, param_2, param_3, param_4);

    if (param_1 == (TPanel*)button[0]) {
        ((RGE_Base_Game_Local*)rge_base_game)->start_scenario_editor(0, 0);
        return 1;
    }

    if (param_1 == (TPanel*)button[1]) {
        new TRIBE_Screen_Sed_Open();
        panel_system.setCurrentPanel((char*)s_Scenario_Editor_Open, 0);
        panel_system.destroyPanel((char*)s_Scenario_Editor_Menu);
        return 1;
    }

    if (param_1 == (TPanel*)button[2]) {
        new TRIBE_Campaign_Editor_Screen();
        panel_system.setCurrentPanel((char*)s_Campaign_Editor_Screen, 0);
        panel_system.destroyPanel((char*)s_Scenario_Editor_Menu);
        return 1;
    }

    if (param_1 == (TPanel*)button[3]) {
        ((RGE_Base_Game_Local*)rge_base_game)->disable_input();
        new TRIBE_Screen_Main_Menu();
        panel_system.setCurrentPanel((char*)s_Main_Menu, 0);
        panel_system.destroyPanel((char*)s_Scenario_Editor_Menu);
        return 1;
    }

    if (param_1 == (TPanel*)close_button) {
        ((RGE_Base_Game_Local*)rge_base_game)->close();
        return 1;
    }

    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}
