// VA: 00440400 TRIBE_Dialog_Sed_Menu::action
// PDB source: dlg_sedm.cpp
// Attempt log:
// - Probe 1: default flags, no EH frame generated (missing FS:[0] prolog)
// - Kept probe 1: added /GX, still no EH frame (VC5 only adds FS:[0] for stack objects with destructors)
// - Probe 2: class layout with proper padding (0x490 base + 8 bytes -> now scenario_editor at +0x490 correct)
// - Probe 3: strcmp vs custom inline comparison; strcmp worse (75.3%)
// - Probe 4: new keyword instead of operator_new+ctor; ballooned to 1568 bytes
// - All probes: consistently ~73-75% diff, 919 bytes exact match
// Left in scratch: EH frame unfixable (no stack destructors), inline strcmp pattern mismatch,
//   control flow shared-tail differences, 73% diff in deep basin

#include <string.h>

extern "C" void* __cdecl operator_new(unsigned int size);

#pragma check_stack(off)

struct TPanel {
    char gap[0x04];
    virtual ~TPanel() {}
    virtual int setup() { return 0; }
    virtual void set_rect() {}
    virtual void set_rect2() {}
    virtual void set_color() {}
    virtual void set_active() {}
    virtual void set_positioning() {}
    virtual void set_fixed_position() {}
    virtual void set_redraw() {}
    virtual void set_overlapped_redraw() {}
    virtual void draw_setup() {}
    virtual void draw_finish() {}
    virtual void draw() {}
    virtual void draw_rect() {}
    virtual void draw_offset() {}
    virtual void draw_rect2() {}
    virtual void draw_offset2() {}
    virtual void paint() {}
    virtual long wnd_proc() { return 0; }
    virtual long handle_idle() { return 0; }
    virtual long handle_size() { return 0; }
    virtual long handle_paint() { return 0; }
    virtual long handle_key_down() { return 0; }
    virtual long handle_char() { return 0; }
    virtual long handle_command() { return 0; }
    virtual long handle_user_command() { return 0; }
    virtual long handle_timer_command() { return 0; }
    virtual long handle_scroll() { return 0; }
    virtual int get_scan_code() { return 0; }
    virtual long handle_event(long, long, long) { return 0; }
    virtual char* panelName() { return 0; }
    virtual long action(TPanel*, long, unsigned long, unsigned long) { return 0; }
};

struct TPanel_gap_0x488 {
    char pad[0x488];
};

struct TDialogPanel : public TPanel, public TPanel_gap_0x488 {
    // Total: 4 (vtable) + 4 (vtable) + 0x488 = 0x490
};

struct TButtonPanel : public TPanel {
};

struct TRIBE_Screen_Sed : public TPanel {
    virtual void command_quit() {}
    virtual void command_save(unsigned char a, unsigned char b) {}
    virtual void command_save_as(unsigned char a) {}
    virtual void command_open() {}
    virtual void command_new() {}
    virtual char* scenario_save_defaulted() { return 0; }
    virtual void command_quick_save() {}
};

struct TRIBE_Screen_Sed_Open : public TPanel {
};

struct TPanelSystem : public TPanel {
    virtual int setCurrentPanel(char* name, int a) { return 0; }
    virtual int destroyPanel(char* name) { return 0; }
};

extern char s_Scenario_Editor_Screen[];
extern char s_Scenario_Menu_Dialog[];
extern char s_New_Dialog[];
extern char s_Open_Dialog[];
extern char s_Scenario_Editor_Open[];

TPanelSystem* panel_system;
struct TRIBE_Game : public TPanel {
    virtual void test_scenario(char* path) {}
    virtual void start_scenario_editor(char* a, int b) {}
};
TRIBE_Game* rge_base_game;

void __fastcall TRIBE_Screen_Sed_Open_ctor(void* _this);

class TRIBE_Dialog_Sed_Menu : public TDialogPanel {
public:
    TRIBE_Screen_Sed* scenario_editor;
    TButtonPanel* buttons[7];
    long action(TPanel* panel, long param_2, unsigned long param_3, unsigned long param_4);
};

long TRIBE_Dialog_Sed_Menu::action(TPanel* panel, long param_2, unsigned long param_3, unsigned long param_4)
{
    TRIBE_Screen_Sed* sed = scenario_editor;

    if (param_2 == 1) {
        if (panel == buttons[0]) {
            panel_system->setCurrentPanel(s_Scenario_Editor_Screen, 0);
            panel_system->destroyPanel(s_Scenario_Menu_Dialog);
            sed->command_quit();
            return 1;
        }
        if (panel == buttons[1]) {
            panel_system->setCurrentPanel(s_Scenario_Editor_Screen, 0);
            panel_system->destroyPanel(s_Scenario_Menu_Dialog);
            sed->command_save(0, 1);
            return 1;
        }
        if (panel == buttons[2]) {
            panel_system->setCurrentPanel(s_Scenario_Editor_Screen, 0);
            panel_system->destroyPanel(s_Scenario_Menu_Dialog);
            sed->command_save_as(0);
            return 1;
        }
        if (panel == buttons[3]) {
            panel_system->setCurrentPanel(s_Scenario_Editor_Screen, 0);
            panel_system->destroyPanel(s_Scenario_Menu_Dialog);
            sed->command_open();
            return 1;
        }
        if (panel == buttons[4]) {
            panel_system->setCurrentPanel(s_Scenario_Editor_Screen, 0);
            panel_system->destroyPanel(s_Scenario_Menu_Dialog);
            sed->command_new();
            return 1;
        }
        if (panel == buttons[5]) {
            panel_system->setCurrentPanel(s_Scenario_Editor_Screen, 0);
            panel_system->destroyPanel(s_Scenario_Menu_Dialog);
            char* result = sed->scenario_save_defaulted();
            if (result) {
                rge_base_game->test_scenario(result);
                return 1;
            }
        }
        if (panel == buttons[6]) {
            panel_system->setCurrentPanel(s_Scenario_Editor_Screen, 0);
            panel_system->destroyPanel(s_Scenario_Menu_Dialog);
            return 1;
        }
    }

    if (panel) {
        char* name = panel->panelName();
        if (name) {
            if (strcmp(name, s_New_Dialog) == 0) {
                panel_system->setCurrentPanel(s_Scenario_Editor_Screen, 0);
                panel_system->destroyPanel(s_New_Dialog);
                panel_system->destroyPanel(s_Scenario_Menu_Dialog);
                if (param_2 == 0)
                    sed->command_quick_save();
                if (param_2 == 0 || param_2 == 1) {
                    panel_system->destroyPanel(s_Scenario_Menu_Dialog);
                    rge_base_game->start_scenario_editor(0, 0);
                }
                if (param_2 == 2)
                    panel_system->destroyPanel(s_Scenario_Menu_Dialog);
                return 1;
            }

            if (strcmp(name, s_Open_Dialog) == 0) {
                panel_system->setCurrentPanel(s_Scenario_Editor_Screen, 0);
                panel_system->destroyPanel(s_Open_Dialog);
                panel_system->destroyPanel(s_Scenario_Menu_Dialog);
                if (param_2 == 0)
                    sed->command_quick_save();
                if (param_2 != 1) {
                    if (param_2 == 2)
                        panel_system->destroyPanel(s_Scenario_Menu_Dialog);
                    return 1;
                }
                {
                    TRIBE_Screen_Sed_Open* openDlg = (TRIBE_Screen_Sed_Open*)operator_new(0x490);
                    if (openDlg)
                        TRIBE_Screen_Sed_Open_ctor(openDlg);
                }
                panel_system->setCurrentPanel(s_Scenario_Editor_Open, 0);
                panel_system->destroyPanel(s_Scenario_Menu_Dialog);
                if (param_2 == 2)
                    panel_system->destroyPanel(s_Scenario_Menu_Dialog);
                return 1;
            }
        }
    }

    return 0;
}
