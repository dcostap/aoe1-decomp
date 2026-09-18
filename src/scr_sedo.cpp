
#include "../include/scr_sedo.h"
#include "../include/resource_ids.h"
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
    : TScreenPanel("Scenario Editor Open") {
    TPanel* tabList[5];
    char info_file[260];

    title = 0;
    list = 0;
    scrollbar = 0;
    okButton = 0;
    cancelButton = 0;
    deleteButton = 0;

    tabList[0] = panel_system.currentPanel();
    strcpy(info_file, static_cast<TEasy_Panel*>(tabList[0])->get_info_file());

    TDrawArea* draw_area = rge_base_game->draw_area;

    if (!setup(draw_area, info_file, static_cast<TEasy_Panel*>(tabList[0])->get_info_id(), 1)) {
        error_code = 1;
        return;
    }

    setup_shadow_area(0);
    set_ideal_size(640, 480);

    if (!create_text(this, &title, STRING_ID_SCENARIO_OPEN_TITLE, 20, 20, 600, 30, RGE_FONT_COPPERPLATE_21_BOLD, 1, 0, 0))
        return;

    if (!create_list(this, &list, 20, 70, 600, 340, RGE_FONT_STANDARD))
        return;

    if (!create_auto_scrollbar(&scrollbar, list, 20))
        return;

    if (!create_button(this, &okButton, STRING_ID_BUTTON_OK, 0, 30, 440, 180, 30, RGE_FONT_COPPERPLATE_12_BOLD, 0, 0))
        return;

    if (!create_button(this, &deleteButton, STRING_ID_BUTTON_DELETE, 0, 230, 440, 180, 30, RGE_FONT_COPPERPLATE_12_BOLD, 0, 0))
        return;

    if (!create_button(this, &cancelButton, STRING_ID_BUTTON_CANCEL, 0, 430, 440, 180, 30, RGE_FONT_COPPERPLATE_12_BOLD, 0, 0))
        return;

    TButtonPanel* cancel = cancelButton;
    cancel->hotkey = VK_ESCAPE;
    cancel->hotkey_shift = 0;
    TButtonPanel* delete_button = deleteButton;
    delete_button->hotkey_shift = 0;
    delete_button->hotkey = VK_DELETE;

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
    this->delete_panel((TPanel**)&this->title);
    this->delete_panel((TPanel**)&this->list);
    this->delete_panel((TPanel**)&this->scrollbar);
    this->delete_panel((TPanel**)&this->okButton);
    this->delete_panel((TPanel**)&this->cancelButton);
    this->delete_panel((TPanel**)&this->deleteButton);
}

void TRIBE_Screen_Sed_Open::fillList() {
    char file_name[260];
    _finddata_t fileInfo;
    long handle;
    int len;

    this->list->empty_list();
    this->list->sorted = 1;

    sprintf(file_name, "%s*.scn", rge_base_game->prog_info->scenario_dir);
    handle = _findfirst(file_name, &fileInfo);
    while (handle != -1) {
        len = strlen(fileInfo.name) - 4;
        strncpy(file_name, fileInfo.name, len);
        file_name[len] = 0;
        this->list->append_line(file_name, 0);
        if (_findnext(handle, &fileInfo) == -1) {
            break;
        }
    }

    sprintf(file_name, "%s*.scx", rge_base_game->prog_info->scenario_dir);
    handle = _findfirst(file_name, &fileInfo);
    while (handle != -1) {
        len = strlen(fileInfo.name) - 4;
        strncpy(file_name, fileInfo.name, len);
        file_name[len] = 0;
        this->list->append_line(file_name, 0);
        if (_findnext(handle, &fileInfo) == -1) {
            break;
        }
    }
}

// The action keeps the shipped delete, open, panel-transition,
// cleanup, and return paths in their original order.
long TRIBE_Screen_Sed_Open::action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2) {
    char fileName[260];
    char* line;
    RGE_Prog_Info* prog_info;
    long curr_line;

    if (fromPanel != 0) {
        if (fromPanel->panelName() != 0 && strcmp(fromPanel->panelName(), "Cancel Dialog") == 0) {
            panel_system.destroyPanel("Cancel Dialog");
            if (actionIn == 0) {
                char str[256];
                prog_info = rge_base_game->prog_info;
                char* scenario_dir = prog_info->scenario_dir;
                sprintf(str, "%s%s.scn", scenario_dir, list->currentLine());
                _unlink(str);

                prog_info = rge_base_game->prog_info;
                char* scenario_dir_scx = prog_info->scenario_dir;
                line = list->currentLine();
                sprintf(str, "%s%s.scx", scenario_dir_scx, line);
                _unlink(str);

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

        if (fromPanel == deleteButton && actionIn == 1) {
            line = list->currentLine();
            if (line[0] != 0) {
                char str[256];
                char text[556];
                get_string(STRING_ID_CONFIRM_DELETE_FILE, str, 256);
                sprintf(text, str, list->currentLine());
                popupYesNoDialog(text, "Cancel Dialog", TEASY_POPUP_WIDTH, 100);
            }
        }

        if (fromPanel == list) {
            if (actionIn == 3) {
                action(okButton, 1, 0, 0);
                return 1;
            }
        } else if (fromPanel == okButton) {
            if (actionIn == 1) {
                if (list->numberLines() > 0) {
                    OFSTRUCT of;
                    prog_info = rge_base_game->prog_info;
                    char* scenario_dir = prog_info->scenario_dir;
                    line = list->currentLine();
                    sprintf(fileName, "%s%s.scn", scenario_dir, line);

                    if (OpenFile(fileName, &of, OF_EXIST) != -1) {
                        sprintf(fileName, "%s.scn", list->currentLine());
                        static_cast<TRIBE_Game*>(rge_base_game)->
                            start_scenario_editor(fileName, 0);
                        return 1;
                    } else {
                        prog_info = rge_base_game->prog_info;
                        scenario_dir = prog_info->scenario_dir;
                        line = list->currentLine();
                        sprintf(fileName, "%s%s.scx", scenario_dir, line);
                    if (OpenFile(fileName, &of, OF_EXIST) != -1) {
                            sprintf(fileName, "%s.scx", list->currentLine());
                            static_cast<TRIBE_Game*>(rge_base_game)->
                                start_scenario_editor(fileName, 0);
                            return 1;
                        } else {
                            popupOKDialog(STRING_ID_ERROR_CANNOT_LOAD_SCENARIO, 0, TEASY_POPUP_WIDTH, 100);
                            return 1;
                        }
                    }
                    return 1;
                }
                return 1;
            }
        } else if (fromPanel == cancelButton && actionIn == 1) {
            TPanel* target = panel_system.panel("Scenario Editor Screen");
            if (target != 0) {
                panel_system.setCurrentPanel("Scenario Editor Screen", 0);
            } else {
                new TRIBE_Screen_Sed_Menu();
                panel_system.setCurrentPanel("Scenario Editor Menu", 0);
            }
            panel_system.destroyPanel("Scenario Editor Open");
            return 1;
        }
    }

    return TEasy_Panel::action(fromPanel, actionIn, a1, a2);
}
