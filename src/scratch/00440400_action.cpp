// VA: 00440400 TRIBE_Dialog_Sed_Menu::action
// PDB source: dlg_sedm.cpp, lines 81-274
// FLAGS: /GX (the constructor in the Open Dialog path has EH cleanup)
//
// Attempt log:
// - Prior scaffold used virtual placeholder methods and an artificial EH scope.
//   It produced virtual calls and missed the direct Panel.cpp/scr_sed.cpp calls.
// - Fresh reconstruction: use the typed dialog fields, direct period method
//   declarations, strcmp dialog gates, and a natural Open Dialog allocation.
//   This is the baseline for the direct-call and panel-ownership check.
// - The proven layout is scenario_editor at +0x490, title at +0x494, and
//   buttons[0..6] at +0x498..+0x4B0.
// - Direct typed member declarations restored all 40 original call targets.
//   Virtual placeholder methods were not retained.
// - Button actions run only for event 1. New/Open dialog actions inspect the
//   panel name for every event. Event 0 quick-saves, event 1 continues, and
//   event 2 closes the menu. Matched actions return 1; other actions return 0.
// - A shared result tail matches the original return topology. Its gotos are
//   retained because the binary has one common epilogue for all return values.
// - Narrow result state and alternate class layouts changed the call surface
//   or emitted no new code. The current source keeps typed ownership and calls.
// - The button-5 null-scenario path is a success path: it destroys the menu,
//   sets the shared result, and skips the button-6 test before the fallback.
// - This probe reduced the positional diff from 929 to 847 bytes and raised
//   exact-block coverage from 60.25% to 65.98%; shared-tail drift remains.
// - Initializing the long result to zero emitted identical code; retain the
//   natural initialized declaration while the shared-tail drift remains.
// - Narrowed the shared result state to unsigned char; VC5 restored one common
//   success tail, reducing rebuilt size to 911 and the diff to 446 bytes.
// - Rewrote the button-5 success/null split as an explicit if/else; VC5 emitted
//   identical code and still merged the button-6 cleanup into a shared call.
// - Made button 6 an else-if continuation of button 5; VC5 emitted identical
//   code, retaining one shared cleanup call and one missing button cleanup site.

#include <string.h>

typedef unsigned long ulong;

class TPanel {
public:
    virtual ~TPanel();
    char gap_004[0x3C];
    char* panelName();
};

class TButtonPanel : public TPanel {
};

class TDialogPanel {
public:
    virtual ~TDialogPanel();
    char gap_004[0x48C];
};

class TRIBE_Screen_Sed {
public:
    virtual ~TRIBE_Screen_Sed();
    void command_quit();
    void command_save(unsigned char save, unsigned char close);
    void command_save_as(unsigned char close);
    void command_open();
    void command_new();
    char* scenario_save_defaulted();
    void command_quick_save();
};

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int mode);
    int destroyPanel(char* name);
};

class TRIBE_Game {
public:
    void test_scenario(char* scenario);
    int start_scenario_editor(char* scenario, int mode);
};

class TRIBE_Screen_Sed_Open {
public:
    virtual ~TRIBE_Screen_Sed_Open();
    char gap_004[0x48C];
    TRIBE_Screen_Sed_Open();
};

extern TPanelSystem panel_system;
extern TRIBE_Game* rge_base_game;

extern char s_Scenario_Editor_Screen[];
extern char s_Scenario_Menu_Dialog[];
extern char s_New_Dialog[];
extern char s_Open_Dialog[];
extern char s_Scenario_Editor_Open[];

class TRIBE_Dialog_Sed_Menu : public TDialogPanel {
public:
    TRIBE_Screen_Sed* scenario_editor; // +0x490
    TPanel* title;                      // +0x494
    TPanel* buttons[7];                 // +0x498

    virtual long action(TPanel* panel, long event, ulong param_3, ulong param_4);
};

long TRIBE_Dialog_Sed_Menu::action(
    TPanel* panel, long event, ulong param_3, ulong param_4)
{
    TRIBE_Screen_Sed* sed = this->scenario_editor;
    unsigned char result = 0;

    if (event == 1) {
        if (panel == this->buttons[0]) {
            panel_system.setCurrentPanel(s_Scenario_Editor_Screen, 0);
            panel_system.destroyPanel(s_Scenario_Menu_Dialog);
            sed->command_quit();
            result = 1;
            goto action_done;
        }

        if (panel == this->buttons[1]) {
            panel_system.setCurrentPanel(s_Scenario_Editor_Screen, 0);
            panel_system.destroyPanel(s_Scenario_Menu_Dialog);
            sed->command_save(1, 0);
            result = 1;
            goto action_done;
        }

        if (panel == this->buttons[2]) {
            panel_system.setCurrentPanel(s_Scenario_Editor_Screen, 0);
            panel_system.destroyPanel(s_Scenario_Menu_Dialog);
            sed->command_save_as(0);
            result = 1;
            goto action_done;
        }

        if (panel == this->buttons[3]) {
            panel_system.setCurrentPanel(s_Scenario_Editor_Screen, 0);
            panel_system.destroyPanel(s_Scenario_Menu_Dialog);
            sed->command_open();
            result = 1;
            goto action_done;
        }

        if (panel == this->buttons[4]) {
            panel_system.setCurrentPanel(s_Scenario_Editor_Screen, 0);
            panel_system.destroyPanel(s_Scenario_Menu_Dialog);
            sed->command_new();
            result = 1;
            goto action_done;
        }

        if (panel == this->buttons[5]) {
            panel_system.setCurrentPanel(s_Scenario_Editor_Screen, 0);
            panel_system.destroyPanel(s_Scenario_Menu_Dialog);
            char* scenario = sed->scenario_save_defaulted();
            if (scenario != 0) {
                rge_base_game->test_scenario(scenario);
            } else {
                panel_system.destroyPanel(s_Scenario_Menu_Dialog);
            }
            result = 1;
            goto action_done;
        }

        else if (panel == this->buttons[6]) {
            panel_system.setCurrentPanel(s_Scenario_Editor_Screen, 0);
            panel_system.destroyPanel(s_Scenario_Menu_Dialog);
            result = 1;
            goto action_done;
        }
    }

    if (panel != 0) {
        if (panel->panelName() != 0 &&
            strcmp(panel->panelName(), s_New_Dialog) == 0) {
            panel_system.setCurrentPanel(s_Scenario_Editor_Screen, 0);
            panel_system.destroyPanel(s_New_Dialog);
            panel_system.destroyPanel(s_Scenario_Menu_Dialog);

            if (event == 0) {
                sed->command_quick_save();
            }
            if (event == 0 || event == 1) {
                panel_system.destroyPanel(s_Scenario_Menu_Dialog);
                rge_base_game->start_scenario_editor(0, 0);
            }
            if (event == 2) {
                panel_system.destroyPanel(s_Scenario_Menu_Dialog);
            }
            result = 1;
            goto action_done;
        }

        if (panel->panelName() != 0 &&
            strcmp(panel->panelName(), s_Open_Dialog) == 0) {
            panel_system.setCurrentPanel(s_Scenario_Editor_Screen, 0);
            panel_system.destroyPanel(s_Open_Dialog);
            panel_system.destroyPanel(s_Scenario_Menu_Dialog);

            if (event == 0) {
                sed->command_quick_save();
            }
            if (event == 0 || event == 1) {
                TRIBE_Screen_Sed_Open* open = new TRIBE_Screen_Sed_Open;
                (void)open;
                panel_system.setCurrentPanel(s_Scenario_Editor_Open, 0);
                panel_system.destroyPanel(s_Scenario_Menu_Dialog);
            }
            if (event == 2) {
                panel_system.destroyPanel(s_Scenario_Menu_Dialog);
            }
            result = 1;
            goto action_done;
        }
    }

    result = 0;

action_done:
    return result;
}
