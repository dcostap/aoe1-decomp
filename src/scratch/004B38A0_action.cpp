// VA: 004B38A0 TRIBE_Screen_Sed_Open::action
// PDB source: scr_sedo.cpp

// Attempt log:
// - First pass (2026-04-27): wrote full action function with correct logical control flow
// - Issue: no EH frame generated (needs /GX + object with destructor to trigger)
// - Issue: completely different compiled code - compiler rearranged the entire control flow
// - Left in scratch because:
//   1. No EH frame - VC5 only adds EH frames when there are stack objects with destructors
//   2. Compiler completely restructured the control flow (early dispatch vs cascading if/else)
//   3. The original has 1003 bytes of complex string/file logic with sprintf, OpenFile, strcmp inline
//   4. Would need dozens of probes to converge

#include <string.h>
#include <stdio.h>

extern void* rge_base_game;

// Minimal _OFSTRUCT for this file (used as temp buffer)
struct _OFSTRUCT {
    char Reserved1[128];
};

class TPanel {
public:
    virtual void d00(); virtual void d04();
    virtual void d08(); virtual void d0C(); virtual void d10();
    virtual void addRef(int val);
    virtual void d1C(); virtual void d20(); virtual void d24();
    virtual void d28(); virtual void d2C(); virtual void d30();
    virtual void d34(); virtual void d38(); virtual void d3C();
    virtual void d40(); virtual void d44(); virtual void d48();
    virtual void d4C(); virtual void d50(); virtual void d54();
    virtual void d58(); virtual void d5C(); virtual void d60();
    virtual void d64(); virtual void d68(); virtual void d6C();
    virtual void d70(); virtual void d74(); virtual void d78();
    virtual void d7C(); virtual void d80(); virtual void d84();
    virtual void d88(); virtual void d8C(); virtual void d90();
    virtual void d94(); virtual void d98(); virtual void d9C();
    virtual void dA0(); virtual void dA4(); virtual void dA8();
    virtual void dAC(); virtual void dB0();
    virtual void d_B4(long a1, long a2, long a3, long a4);
    char* panelName();
    int get_string(int id, char* buf, int maxlen);
};

class TEasy_Panel : public TPanel {
public:
    long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
    void popupYesNoDialog(char* msg, char* dialog_name, int h, int w);
    void popupOKDialog(int msg_id, char* unk, int h, int w);
    char pad_TEasy[0x434];
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(const char* name);
    virtual ~TScreenPanel();
};

class TPanelSystem {
public:
    TPanel* panel(const char* name);
    int setCurrentPanel(const char* name, int val);
    int destroyPanel(const char* name);
};

extern TPanelSystem panel_system;

class TTextPanel : public TPanel {
public:
    char* currentLine();
    long get_line();
    int delete_line(long line);
    int numberLines();
};

class TButtonPanel : public TPanel {
public:
    void set_disabled(int val);
};

class TListPanel : public TPanel {
};

class RGE_Prog_Info {
public:
    char gap_00[0x0C];
    char* scenario_dir;
};

class RGE_Base_Game {
public:
    RGE_Prog_Info* prog_info; // at +0x0C
    int start_scenario_editor(char* path, int val);
};

class TRIBE_Screen_Sed_Menu {
public:
    void construct();
    char pad[0x490];
};

class TRIBE_Screen_Sed_Open : public TScreenPanel {
public:
    TPanel* title;          // +0x478
    TListPanel* list;       // +0x47C
    TPanel* scrollbar;      // +0x480
    TButtonPanel* okButton; // +0x484
    TButtonPanel* cancelButton; // +0x488
    TButtonPanel* deleteButton; // +0x48C

    TRIBE_Screen_Sed_Open();
    void fillList();
    long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
};

extern "C" void* __cdecl operator_new(unsigned long sz);
extern "C" int __cdecl __unlink(const char* path);
extern "C" int __cdecl OpenFile(const char* name, void* of, unsigned int mode);

long TRIBE_Screen_Sed_Open::action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4)
{
    char text[556];
    char fileName[257];
    _OFSTRUCT of;

    if (!param_1) {
        return TEasy_Panel::action(param_1, param_2, param_3, param_4);
    }

    char* name = param_1->panelName();
    if (name && strcmp(name, "Cancel Dialog") == 0) {
        panel_system.destroyPanel("Cancel Dialog");
        if (!param_2) {
            char* line;
            RGE_Base_Game* game = (RGE_Base_Game*)rge_base_game;

            line = ((TTextPanel*)list)->currentLine();
            sprintf(of.Reserved1, "%s%s.scn", game->prog_info->scenario_dir, line);
            __unlink(of.Reserved1);

            line = ((TTextPanel*)list)->currentLine();
            sprintf(of.Reserved1, "%s%s.scx", game->prog_info->scenario_dir, line);
            __unlink(of.Reserved1);

            long curr_line = ((TTextPanel*)list)->get_line();
            ((TTextPanel*)list)->delete_line(curr_line);

            line = ((TTextPanel*)list)->currentLine();
            if (!line[0]) {
                okButton->set_disabled(1);
                deleteButton->set_disabled(1);
                return 1;
            }
        }
        return 1;
    }

    // Delete button
    if (param_1 == (TPanel*)deleteButton && param_2 == 1) {
        char* line = ((TTextPanel*)list)->currentLine();
        if (line[0]) {
            get_string(0x24CA, of.Reserved1, 0x100);
            sprintf(text + 4, of.Reserved1, ((TTextPanel*)list)->currentLine());
            popupYesNoDialog(text + 4, "Cancel Dialog", 0x1C2, 100);
        }
    }

    // List panel - double click (param_2 == 3)
    if (param_1 == (TPanel*)list) {
        if (param_2 == 3) {
            d_B4((long)okButton, 1, 0, 0);
            return 1;
        }
        return TEasy_Panel::action(param_1, param_2, param_3, param_4);
    }

    // OK button
    if (param_1 == (TPanel*)okButton) {
        if (param_2 != 1) {
            return TEasy_Panel::action(param_1, param_2, param_3, param_4);
        }
        if (((TTextPanel*)list)->numberLines() <= 0) {
            return 1;
        }

        RGE_Base_Game* game = (RGE_Base_Game*)rge_base_game;
        char* line = ((TTextPanel*)list)->currentLine();
        sprintf(fileName + 4, "%s%s.scn", game->prog_info->scenario_dir, line);

        if (OpenFile(fileName + 4, &of, 0x4000) != -1) {
            line = ((TTextPanel*)list)->currentLine();
            sprintf(fileName + 4, "%s.scn", line);
        } else {
            line = ((TTextPanel*)list)->currentLine();
            sprintf(fileName + 4, "%s%s.scx", game->prog_info->scenario_dir, line);
            if (OpenFile(fileName + 4, &of, 0x4000) != -1) {
                line = ((TTextPanel*)list)->currentLine();
                sprintf(fileName + 4, "%s.scx", line);
            } else {
                popupOKDialog(0x24CF, 0, 0x1C2, 100);
                return 1;
            }
        }

        game->start_scenario_editor(fileName + 4, 0);
        return 1;
    }

    // Cancel button
    if (param_1 == (TPanel*)cancelButton && param_2 == 1) {
        TPanel* target = panel_system.panel("Scenario Editor Screen");
        if (target) {
            panel_system.setCurrentPanel("Scenario Editor Screen", 0);
        } else {
            void* mem = operator_new(0x490);
            if (mem) {
                ((TRIBE_Screen_Sed_Menu*)mem)->construct();
            }
            panel_system.setCurrentPanel("Scenario Editor Menu", 0);
        }
        panel_system.destroyPanel("Scenario Editor Open");
        return 1;
    }

    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}
