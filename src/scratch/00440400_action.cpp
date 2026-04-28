// VA: 00440400 TRIBE_Dialog_Sed_Menu::action
// PDB source: dlg_sedm.cpp, 919 bytes
// FLAGS: /GX (EH required by original)
//
// Attempt log:
// - Probe 1: default flags, no EH frame (missing FS:[0] prologue)
// - Probe 2: added /GX, still no EH frame (no stack objects with dtors)
// - Probe 3: class layout with padding fixes; strcmp worse than inline
// - Probe 4: new keyword instead of operator_new+ctor; ballooned to 1568
// - Probe 5: struct dtor at function scope -> EH frame working, 70.1%
// - Probe 6: proper operator new + <new.h> -> no EH frame
// - Probe 7: check_stack(off) + dtor trigger -> 67.8% (check_stack didn't materially help)
// - Probe 8: double panelName()+inline byte-byte strcmp, dtor trigger -> 67.7%
//   EH frame works, first 25 bytes match (after relocation masking)
//   Prologue: VC5 saves regs before loading params (differs from original)
//   Virtual dispatch: through vtable (original has devirtualized direct calls)
// Left in scratch: VC5 register allocation and devirtualization limitations

#include <string.h>
#include <new.h>

struct TPanel {
    char gap[4];
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

struct TPanel_gap_0x488 { char pad[0x488]; };
struct TDialogPanel : public TPanel, public TPanel_gap_0x488 {};

struct TRIBE_Screen_Sed : public TPanel {
    virtual void command_quit() {}
    virtual void command_save(unsigned char, unsigned char) {}
    virtual void command_save_as(unsigned char) {}
    virtual void command_open() {}
    virtual void command_new() {}
    virtual char* scenario_save_defaulted() { return 0; }
    virtual void command_quick_save() {}
};

struct TRIBE_Screen_Sed_Open : public TPanel {};
struct TButtonPanel : public TPanel {};

struct TPanelSystem : public TPanel {
    virtual int setCurrentPanel(char*, int) { return 0; }
    virtual int destroyPanel(char*) { return 0; }
};

struct TRIBE_Game : public TPanel {
    virtual void test_scenario(char*);
    virtual void start_scenario_editor(char*, int);
};

extern char s_Scenario_Editor_Screen[];
extern char s_Scenario_Menu_Dialog[];
extern char s_New_Dialog[];
extern char s_Open_Dialog[];
extern char s_Scenario_Editor_Open[];

TPanelSystem* panel_system;
TRIBE_Game* rge_base_game;

void __fastcall TRIBE_Screen_Sed_Open_ctor(void* _this);
void* operator new(unsigned int);

class TRIBE_Dialog_Sed_Menu : public TDialogPanel {
public:
    TRIBE_Screen_Sed* scenario_editor;  // +0x490
    TButtonPanel* buttons[7];            // +0x494
    long action(TPanel* panel, long param_2, unsigned long param_3, unsigned long param_4);
};

long TRIBE_Dialog_Sed_Menu::action(TPanel* panel, long param_2, unsigned long param_3, unsigned long param_4)
{
    struct _Scope { ~_Scope() {} } _ehScope;
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
            {
                char* n = panel->panelName();
                char* t = s_New_Dialog;
                int eq = 0;
                for (;;) {
                    if (*n != *t) { eq = 0; break; }
                    if (*n == 0) { eq = 1; break; }
                    n++; t++;
                }
                if (eq) {
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
            }

            {
                char* n = panel->panelName();
                char* t = s_Open_Dialog;
                int eq = 0;
                for (;;) {
                    if (*n != *t) { eq = 0; break; }
                    if (*n == 0) { eq = 1; break; }
                    n++; t++;
                }
                if (eq) {
                    panel_system->setCurrentPanel(s_Scenario_Editor_Screen, 0);
                    panel_system->destroyPanel(s_Open_Dialog);
                    panel_system->destroyPanel(s_Scenario_Menu_Dialog);
                    if (param_2 == 0)
                        sed->command_quick_save();
                    if (param_2 == 0 || param_2 == 1) {
                        TRIBE_Screen_Sed_Open* openDlg = (TRIBE_Screen_Sed_Open*)operator new(0x490);
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
    }

    return 0;
}
