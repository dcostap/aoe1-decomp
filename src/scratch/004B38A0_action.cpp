// VA: 004B38A0 TRIBE_Screen_Sed_Open::action
// PDB source: scr_sedo.cpp

// Attempt log:
// - Prior scaffold used an early null return, a 128-byte OFSTRUCT stub, a
//   direct OpenFile declaration, and a manual operator_new/construct pair.
//   It had no EH frame, placed fields at +0x43C, and had the wrong OpenFile,
//   constructor, and virtual-action call surfaces.
// - Clean reconstruction: use the period TPanel vtable (action at +0xB4),
//   the proven +0x47C panel ownership, a 0x100-byte OFSTRUCT scratch window,
//   typed RGE_Base_Game/RGE_Prog_Info ownership, the IAT function-pointer
//   surface for OpenFile, and natural `new TRIBE_Screen_Sed_Menu()`.
// - Baseline: 1003 bytes/frame 0x434, but the cached panelName result removed
//   one binary-proven call.  Repeating the predicate call restored all 38
//   calls and reduced the strict diff to 678 bytes.
// - Rejected game-pointer declaration/splitting probes: they did not change
//   the emitted body or made the first path hunk worse, so the direct typed
//   global surface was restored.
// - Positive list-first dispatch restored the original ordered 38-call CFG
//   and moved the checker to block-shape/liveness work.
// - A named first-OK-path prog_info pointer improved the path preload shape;
//   a plain cancel-path scenario_dir local then recovered the original global,
//   list, path, currentLine, and sprintf ordering.  Best current result is
//   449 differing bytes (82.84% shape, exact size/frame/calls/CFG).
// - `register` on scenario_dir was a codegen duplicate and was removed from
//   the living source.  Remaining drift is localized to stack-home/address
//   offsets and late source-local scheduling; leave this target in scratch.
// - The decomp local order is `_OFSTRUCT`, fileName, then text.  A 252-byte
//   Reserved1 surface plus text[560] restores the target frame and local
//   addresses; text[556] drops the frame by four bytes.  fileName[260] is the
//   period +4 buffer form and emits the same bytes as the inferred 257 size.
// - Reusing function-scope prog_info/line and curr_line follows the decomp
//   pointer lifetimes.  A first-block scenario_dir alias fixes that paired
//   hunk.  Best is now 338 differing bytes, 95.57% shape, exact frame and
//   calls.  The second cancel-path alias and the first-open alias restore
//   exact blocks through the first OpenFile path.
// - A 20-probe pass tested source order, receiver lifetimes, imported-pointer
//   caching, branch layout, and common-tail forms.  The clean natural source
//   is pinned at 338 differing bytes with exact size, frame, calls, and CFG.
//   Remaining drift is the fallback expression order, the pre-test receiver
//   load, and the original EBX versus rebuilt EDI import-pointer color.

#include <new.h>
#include <string.h>
#include <stdio.h>

// The original source passes Reserved1 as the OFSTRUCT scratch surface.
struct _OFSTRUCT {
    char Reserved1[252];
};

class TPanel {
public:
    virtual ~TPanel();
#define VPAD1(n) virtual void v##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)
    VPAD32(1) VPAD8(33) VPAD4(41)
#undef VPAD32
#undef VPAD16
#undef VPAD8
#undef VPAD4
#undef VPAD2
#undef VPAD1
    virtual long action(TPanel* param_1, long param_2,
                       unsigned long param_3, unsigned long param_4);
    char gap_04[0xF0];
    char* panelName();
    int get_string(int id, char* buf, int maxlen);
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];
    long action(TPanel* param_1, long param_2, unsigned long param_3,
                unsigned long param_4);
    void popupYesNoDialog(char* msg, char* dialog_name, int h, int w);
    void popupOKDialog(int msg_id, char* unk, int h, int w);
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
    char gap_00[0xC17];
    char scenario_dir[261];
};

class RGE_Base_Game {
public:
    void* vtable_ptr;
    void* player_game_info;
    void* scenario_info;
    RGE_Prog_Info* prog_info;
    int start_scenario_editor(char* path, int val);
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Sed_Menu {
public:
    char pad[0x490];
    TRIBE_Screen_Sed_Menu();
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
    long action(TPanel* param_1, long param_2, unsigned long param_3,
                unsigned long param_4);
};

extern "C" int __cdecl __unlink(const char* path);
extern "C" int (__stdcall* const OpenFile)(const char* name, void* of,
                                             unsigned int mode);

long TRIBE_Screen_Sed_Open::action(TPanel* param_1, long param_2,
                                   unsigned long param_3,
                                   unsigned long param_4)
{
    _OFSTRUCT of;
    char fileName[260];
    char text[560];
    char* line;
    RGE_Prog_Info* prog_info;
    long curr_line;
    int (__stdcall *open_file)(const char*, void*, unsigned int);

    if (param_1 != 0) {
        if (param_1->panelName() != 0 &&
            strcmp(param_1->panelName(), "Cancel Dialog") == 0) {
            panel_system.destroyPanel("Cancel Dialog");
            if (param_2 == 0) {
                prog_info = rge_base_game->prog_info;
                char* scenario_dir = prog_info->scenario_dir;
                sprintf(of.Reserved1, "%s%s.scn",
                        scenario_dir, ((TTextPanel*)list)->currentLine());
                __unlink(of.Reserved1);

                prog_info = rge_base_game->prog_info;
                char* scenario_dir_scx = prog_info->scenario_dir;
                line = ((TTextPanel*)list)->currentLine();
                sprintf(of.Reserved1, "%s%s.scx",
                        scenario_dir_scx, line);
                __unlink(of.Reserved1);

                curr_line = ((TTextPanel*)list)->get_line();
                ((TTextPanel*)list)->delete_line(curr_line);

                line = ((TTextPanel*)list)->currentLine();
                if (line[0] == 0) {
                    okButton->set_disabled(1);
                    deleteButton->set_disabled(1);
                    return 1;
                }
            }
            return 1;
        }

        if (param_1 == (TPanel*)deleteButton && param_2 == 1) {
            line = ((TTextPanel*)list)->currentLine();
            if (line[0] != 0) {
                get_string(0x24CA, of.Reserved1, 0x100);
                sprintf(text + 4, of.Reserved1,
                        ((TTextPanel*)list)->currentLine());
                popupYesNoDialog(text + 4, "Cancel Dialog", 0x1C2, 100);
            }
        }

        if (param_1 == (TPanel*)list) {
            if (param_2 == 3) {
                ((TPanel*)this)->action((TPanel*)okButton, 1, 0, 0);
                return 1;
            }
        }
        else if (param_1 == (TPanel*)okButton) {
            if (param_2 == 1) {
                if (((TTextPanel*)list)->numberLines() > 0) {
                    prog_info = rge_base_game->prog_info;
                    char* scenario_dir_open = prog_info->scenario_dir;
                    line = ((TTextPanel*)list)->currentLine();
                    sprintf(fileName + 4, "%s%s.scn",
                            scenario_dir_open, line);

                    open_file = OpenFile;
                    if (open_file(fileName + 4, &of.Reserved1, 0x4000) != -1) {
                        sprintf(fileName + 4, "%s.scn",
                                ((TTextPanel*)list)->currentLine());
                    }
                    else {
                        line = ((TTextPanel*)list)->currentLine();
                        prog_info = rge_base_game->prog_info;
                        sprintf(fileName + 4, "%s%s.scx",
                                prog_info->scenario_dir, line);
                        if (open_file(fileName + 4, &of.Reserved1, 0x4000) != -1) {
                            line = ((TTextPanel*)list)->currentLine();
                            sprintf(fileName + 4, "%s.scx", line);
                        }
                        else {
                            popupOKDialog(0x24CF, 0, 0x1C2, 100);
                            return 1;
                        }
                    }

                    rge_base_game->start_scenario_editor(fileName + 4, 0);
                    return 1;
                }
                return 1;
            }
        }
        else if (param_1 == (TPanel*)cancelButton && param_2 == 1) {
            TPanel* target = panel_system.panel("Scenario Editor Screen");
            if (target != 0) {
                panel_system.setCurrentPanel("Scenario Editor Screen", 0);
            }
            else {
                new TRIBE_Screen_Sed_Menu();
                panel_system.setCurrentPanel("Scenario Editor Menu", 0);
            }
            panel_system.destroyPanel("Scenario Editor Open");
            return 1;
        }
    }

    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}
