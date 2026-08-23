// VA 004905D0 TRIBE_Campaign_Editor_Screen::action
// scr_cam.cpp:549-658
// Attempt log:
// 1: Natural source from packet/decompiler, using related scr_cam/scr_cams matching surfaces.
// 2: Implemented null-panel base dispatch; filename dropdown child switching; add/remove on double-click; load dropdown path with dirty-save prompt; ok/save/cancel/add/remove/up/down button handling.
// 3: Implemented Cancel Dialog and Load Dialog name handling, including panel_system destroyPanel/setCurrentPanel, TRIBE_Screen_Sed_Menu allocation/constructor, make_campaign/load_campaign, and base action fallback.
// 4: Modeled large local buffers `str[256]` and `text[300]`, popupYesNoCancelDialog string formatting, and panel_system global surface.
// 5: Default /O2 /Oy build was structurally short; same-TU /GX donors established the likely EH flag context.
// 6: Restored the explicit null-panel base-action return, recovering the original parameter-push block and exact frame/CFG family.
// 7: Spelled the byte save flag as > 0, selecting the oracle's jbe polarity in both save-prompt guards.
// 8: Used independent code==0 and code==0-or-1 guards for the Cancel Dialog path, reproducing its post-make retest and shared allocation.
// 9: Mirrored the same independent guards for Load Dialog; /GX build now MATCHES 1019/1019 bytes.
// MATCH: natural typed source with direct new, intrinsic strcmp, explicit null return, and period /GX context.

#include <string.h>

#include "../../include/scr_cam_context.h"

#if 0

class TPanel {
public:
    virtual void v00();
    char* panelName();
    void set_curr_child(TPanel* child);
};
class TTextPanel : public TPanel { public: int numberLines(); };
class TEditPanel : public TPanel { public: char* get_text(); void set_text(char*); };
class TDropDownPanel : public TPanel { public: char* get_text(); };
class TEasy_Panel {
public:
#define EPAD(n) virtual void e##n();
    EPAD(0) EPAD(1) EPAD(2) EPAD(3) EPAD(4) EPAD(5) EPAD(6) EPAD(7)
    EPAD(8) EPAD(9) EPAD(10) EPAD(11) EPAD(12) EPAD(13) EPAD(14) EPAD(15)
    EPAD(16) EPAD(17) EPAD(18) EPAD(19) EPAD(20) EPAD(21) EPAD(22) EPAD(23)
    EPAD(24) EPAD(25) EPAD(26) EPAD(27) EPAD(28) EPAD(29) EPAD(30) EPAD(31)
    EPAD(32) EPAD(33) EPAD(34) EPAD(35) EPAD(36) EPAD(37) EPAD(38) EPAD(39)
    EPAD(40) EPAD(41) EPAD(42) EPAD(43) EPAD(44)
#undef EPAD
    virtual long vB4(TPanel*, long, unsigned long, unsigned long);
    long action(TPanel*, long, unsigned long, unsigned long);
    int get_string(int, char*, int);
    void popupYesNoCancelDialog(char*, char*, int, int);
    void set_curr_child(TPanel* child);
};
class TPanelSystem { public: int destroyPanel(char*); int setCurrentPanel(char*, int); };
extern TPanelSystem panel_system;
void* __cdecl operator new(unsigned int);
inline void* operator new(unsigned int, void* p) { return p; }
int __cdecl sprintf(char*, const char*, ...);

class TRIBE_Screen_Sed_Menu {
public:
    char gap_000[0x490];
    TRIBE_Screen_Sed_Menu();
};

class TRIBE_Campaign_Editor_Screen : public TEasy_Panel {
public:
    char gap_004[0x474];
    unsigned char need_to_save; // +478
    char gap_479[0x13];
    TTextPanel* scenarios; // +48C
    TTextPanel* campaign_scenarios; // +490
    char gap_494[8];
    TEditPanel* filename; // +49C
    TPanel* ok_button; // +4A0
    TPanel* cancel_button; // +4A4
    TPanel* save_button; // +4A8
    TPanel* add_button; // +4AC
    TPanel* remove_button; // +4B0
    TPanel* up_button; // +4B4
    TPanel* down_button; // +4B8
    TDropDownPanel* filename_drop; // +4BC

    void add_scenario();
    void remove_scenario();
    void move_scenario_up();
    void move_scenario_down();
    void make_campaign();
    void load_campaign();
    long action(TPanel*, long, unsigned long, unsigned long);
};
#endif

long TRIBE_Campaign_Editor_Screen::action(TPanel* panel, long code, unsigned long p3, unsigned long p4)
{
    char str[256];
    char text[300];

    if (panel == 0)
        return this->TEasy_Panel::action(panel, code, p3, p4);

    if (panel == this->filename_drop && code == 2) {
            this->filename_drop->set_curr_child(this->filename);
            this->set_curr_child(this->filename_drop);
    }

    if (code == 3) {
        if (panel == this->scenarios) {
            this->add_scenario();
        } else if (panel == this->campaign_scenarios) {
            this->remove_scenario();
        }
    }

    if (panel == this->filename_drop && code == 0) {
        if (this->need_to_save > 0 && this->campaign_scenarios->numberLines() > 0) {
            this->get_string(0x2bc9, str, 0x100);
            sprintf(text, str, this->filename->get_text());
            this->popupYesNoCancelDialog(text, "Load Dialog", 0x1c2, 100);
        } else {
            this->filename->set_text(this->filename_drop->get_text());
            this->load_campaign();
        }
    }

    if (code == 1) {
        if (panel == this->ok_button) {
            if (this->need_to_save > 0 && this->campaign_scenarios->numberLines() > 0) {
                this->get_string(0x2bc9, str, 0x100);
                sprintf(text, str, this->filename->get_text());
                this->popupYesNoCancelDialog(text, "Cancel Dialog", 0x1c2, 100);
            } else {
                new TRIBE_Screen_Sed_Menu;
                panel_system.setCurrentPanel("Scenario Editor Menu", 0);
                panel_system.destroyPanel("Campaign Editor Screen");
                return 1;
            }
        } else if (panel == this->save_button) {
            this->make_campaign();
        } else if (panel == this->cancel_button) {
            new TRIBE_Screen_Sed_Menu;
            panel_system.setCurrentPanel("Scenario Editor Menu", 0);
            panel_system.destroyPanel("Campaign Editor Screen");
            return 1;
        } else if (panel == this->add_button) {
            this->add_scenario();
        } else if (panel == this->remove_button) {
            this->remove_scenario();
        } else if (panel == this->move_scenario_up_button) {
            this->move_scenario_up();
        } else if (panel == this->move_scenario_down_button) {
            this->move_scenario_down();
        }

    }

        if (panel->panelName() && strcmp(panel->panelName(), "Cancel Dialog") == 0) {
            panel_system.destroyPanel("Cancel Dialog");
            if (code == 0) {
                this->make_campaign();
            }
            if (code == 0 || code == 1) {
                new TRIBE_Screen_Sed_Menu;
                panel_system.setCurrentPanel("Scenario Editor Menu", 0);
                panel_system.destroyPanel("Campaign Editor Screen");
            }
            return 1;
        }

    if (panel->panelName() && strcmp(panel->panelName(), "Load Dialog") == 0) {
        panel_system.destroyPanel("Load Dialog");
        if (code == 0) {
            this->make_campaign();
        }
        if (code == 0 || code == 1) {
            this->filename->set_text(this->filename_drop->get_text());
            this->load_campaign();
        }
        return 1;
    }

    return this->TEasy_Panel::action(panel, code, p3, p4);
}
