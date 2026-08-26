// VA: 004B38A0 TRIBE_Screen_Sed_Open::action
// PDB source: scr_sedo.cpp
//
// The shared surface keeps the period panel ABI and the proven +0x47C list
// ownership. Residual drift is local scheduling around the OpenFile paths.
// BINARY NOTE: The PDB span is scr_sedo.cpp lines 155-245. The natural
// source keeps all 38 ordered calls, file-path effects, panel transitions,
// cleanup paths, and return values.
//
// Attempt log:
// - The first natural source used separate extension sprintf calls. It kept
//   all 38 calls but emitted seven bytes after the target boundary.
// - A branch-selected format pointer and one common sprintf tail recover the
//   original 1003-byte boundary and 265-instruction count.
// - Reversed OpenFile predicates and explicit labels were tested. They moved
//   the hot block or restored the seven-byte size drift, so they were rejected.
// - Current result: 1003 bytes, 265 instructions, 38/38 ordered calls,
//   matching owner and boundary, and 126 strict differing bytes. The remaining
//   drift is a local format-tail register and block-shape difference.

#include <new.h>
#include <string.h>
#include <stdio.h>
#include "../../include/scr_sedo_context.h"

struct _OFSTRUCT {
    char Reserved1[252];
};

class TRIBE_Screen_Sed_Menu {
public:
    char pad[0x490];
    TRIBE_Screen_Sed_Menu();
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
    char* file_format;
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
                        line = ((TTextPanel*)list)->currentLine();
                        file_format = "%s.scn";
                    }
                    else {
                        prog_info = rge_base_game->prog_info;
                        line = ((TTextPanel*)list)->currentLine();
                        sprintf(fileName + 4, "%s%s.scx",
                                prog_info->scenario_dir, line);
                        if (open_file(fileName + 4, &of.Reserved1, 0x4000) != -1) {
                            line = ((TTextPanel*)list)->currentLine();
                            file_format = "%s.scx";
                        }
                        else {
                            popupOKDialog(0x24CF, 0, 0x1C2, 100);
                            return 1;
                        }
                    }
                    sprintf(fileName + 4, file_format, line);
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
