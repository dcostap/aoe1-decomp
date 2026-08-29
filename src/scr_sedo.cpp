
#include "../include/scr_sedo.h"
#include "../include/main.h"
#include "../include/tribegam.h"
#include "../include/pnl_btn.h"
#include "../include/pnl_lst.h"
#include "../include/Pnl_scbr.h"
#include "../include/scr_sedm.h"
#include "../include/rge_base_game_global.h"
#include <io.h>
#include <new.h>
#include <stdio.h>
#include <string.h>

// The constructor owns the +0x478-+0x48C panel slots and keeps
// the original setup and child-creation order.
TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open()
    : TScreenPanel("Scenario Editor Open")
{
    TPanel* tabList[5];
    char info_file[260];

    title = 0;
    list = 0;
    scrollbar = 0;
    okButton = 0;
    cancelButton = 0;
    deleteButton = 0;

    tabList[0] = panel_system.currentPanel();
    strcpy(info_file,
           static_cast<TEasy_Panel*>(tabList[0])->get_info_file());

    TDrawArea* draw_area = rge_base_game->draw_area;

    if (!setup(draw_area, info_file,
                   static_cast<TEasy_Panel*>(tabList[0])->get_info_id(), 1)) {
        error_code = 1;
        return;
    }

    setup_shadow_area(0);
    set_ideal_size(0x280, 0x1E0);

    if (!create_text(this, &title, 0x24CD, 0x14, 0x14, 600, 0x1E, 1, 1, 0, 0))
        return;

    if (!create_list(this, &list, 0x14, 0x46, 600, 0x154, 0x0B))
        return;

    if (!create_auto_scrollbar(&scrollbar, list, 0x14))
        return;

    if (!create_button(this, &okButton, 0xFA1, 0, 0x1E, 0x1B8, 0xB4, 0x1E, 0, 0, 0))
        return;

    if (!create_button(this, &deleteButton, 0x24C9, 0, 0xE6, 0x1B8, 0xB4, 0x1E, 0, 0, 0))
        return;

    if (!create_button(this, &cancelButton, 0xFA2, 0, 0x1AE, 0x1B8, 0xB4, 0x1E, 0, 0, 0))
        return;

    TButtonPanel* cancel = cancelButton;
    cancel->hotkey = 0x1B;
    cancel->hotkey_shift = 0;
    TButtonPanel* delete_button = deleteButton;
    delete_button->hotkey_shift = 0;
    delete_button->hotkey = 0x2E;

    fillList();

    if (list->currentLine()[0] == 0) {
        okButton->set_disabled(1);
        deleteButton->set_disabled(1);
    }

    set_curr_child(list);

    tabList[1] = list;
    tabList[2] = okButton;
    tabList[3] = deleteButton;
    tabList[4] = cancelButton;
    set_tab_order(tabList + 1, 4);
}

TRIBE_Screen_Sed_Open::~TRIBE_Screen_Sed_Open() {
    delete title;
    title = 0;
    delete list;
    list = 0;
    delete scrollbar;
    scrollbar = 0;
    delete okButton;
    okButton = 0;
    delete cancelButton;
    cancelButton = 0;
    delete deleteButton;
    deleteButton = 0;
}

void TRIBE_Screen_Sed_Open::fillList()
{
    char file_name[260];
    _finddata_t fileInfo;
    long handle;
    int len;

    this->list->empty_list();
    this->list->sorted = 1;

    sprintf(file_name, "%s*.scn", rge_base_game->prog_info->scenario_dir);
    handle = _findfirst(file_name, &fileInfo);
    while (handle != -1) {
        len = strlen(fileInfo.name + 4) - 4;
        strncpy(file_name, fileInfo.name + 4, len);
        file_name[len] = 0;
        this->list->append_line(file_name, 0);
        if (_findnext(handle, &fileInfo) == -1) {
            break;
        }
    }

    sprintf(file_name, "%s*.scx", rge_base_game->prog_info->scenario_dir);
    handle = _findfirst(file_name, &fileInfo);
    while (handle != -1) {
        len = strlen(fileInfo.name + 4) - 4;
        strncpy(file_name, fileInfo.name + 4, len);
        file_name[len] = 0;
        this->list->append_line(file_name, 0);
        if (_findnext(handle, &fileInfo) == -1) {
            break;
        }
    }
}

// The action keeps the shipped delete, open, panel-transition,
// cleanup, and return paths in their original order.
long TRIBE_Screen_Sed_Open::action(TPanel* param_1, long param_2,
                                   unsigned long param_3,
                                   unsigned long param_4)
{
    OFSTRUCT of;
    char file_name[260];
    char format[256];
    char text[560];
    char* line;
    RGE_Prog_Info* prog_info;
    long curr_line;
    const char* file_format;

    if (param_1 != 0) {
        if (param_1->panelName() != 0 &&
            strcmp(param_1->panelName(), "Cancel Dialog") == 0) {
            panel_system.destroyPanel("Cancel Dialog");
            if (param_2 == 0) {
                prog_info = rge_base_game->prog_info;
                char* scenario_dir = prog_info->scenario_dir;
                sprintf(file_name, "%s%s.scn",
                        scenario_dir, list->currentLine());
                _unlink(file_name);

                prog_info = rge_base_game->prog_info;
                char* scenario_dir_scx = prog_info->scenario_dir;
                line = list->currentLine();
                sprintf(file_name, "%s%s.scx",
                        scenario_dir_scx, line);
                _unlink(file_name);

                curr_line = list->get_line();
                list->delete_line(curr_line);

                line = list->currentLine();
                if (line[0] == 0) {
                    okButton->set_disabled(1);
                    deleteButton->set_disabled(1);
                    return 1;
                }
            }
            return 1;
        }

        if (param_1 == deleteButton && param_2 == 1) {
            line = list->currentLine();
            if (line[0] != 0) {
                get_string(0x24CA, format, 0x100);
                sprintf(text, format, list->currentLine());
                popupYesNoDialog(text, "Cancel Dialog", 0x1C2, 100);
            }
        }

        if (param_1 == list) {
            if (param_2 == 3) {
                action(okButton, 1, 0, 0);
                return 1;
            }
        }
        else if (param_1 == okButton) {
            if (param_2 == 1) {
                if (list->numberLines() > 0) {
                    prog_info = rge_base_game->prog_info;
                    char* scenario_dir_open = prog_info->scenario_dir;
                    line = list->currentLine();
                    sprintf(file_name, "%s%s.scn",
                            scenario_dir_open, line);

                    if (OpenFile(file_name, &of, 0x4000) != -1) {
                        line = list->currentLine();
                        file_format = "%s.scn";
                    }
                    else {
                        prog_info = rge_base_game->prog_info;
                        line = list->currentLine();
                        sprintf(file_name, "%s%s.scx",
                                prog_info->scenario_dir, line);
                        if (OpenFile(file_name, &of, 0x4000) != -1) {
                            line = list->currentLine();
                            file_format = "%s.scx";
                        }
                        else {
                            popupOKDialog(0x24CF, 0, 0x1C2, 100);
                            return 1;
                        }
                    }
                    sprintf(file_name, file_format, line);
                    static_cast<TRIBE_Game*>(rge_base_game)
                        ->start_scenario_editor(file_name, 0);
                    return 1;
                }
                return 1;
            }
        }
        else if (param_1 == cancelButton && param_2 == 1) {
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
