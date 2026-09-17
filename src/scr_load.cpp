
#include "../include/scr_load.h"
#include "../include/resource_ids.h"
#include "../include/pnl_btn.h"
#include "../include/pnl_lst.h"
#include "../include/Pnl_scbr.h"
#include "../include/main.h"
#include "../include/basegame.h"
#include "../include/rge_base_game_global.h"
#include "../include/tribegam.h"
#include "../include/scr_sing.h"

#include <io.h>
#include <stdio.h>
#include <string.h>

TribeLoadSavedGameScreen::TribeLoadSavedGameScreen() : TScreenPanel("Load Saved Game Screen") {
    TPanel* tabList[5];
    char info_file[260];

    this->screenTitle = 0;
    this->listTitle = 0;
    this->list = 0;
    this->scrollbar = 0;
    this->okButton = 0;
    this->cancelButton = 0;
    this->deleteButton = 0;

    tabList[0] = panel_system.currentPanel();
    strcpy(info_file, static_cast<TEasy_Panel*>(tabList[0])->get_info_file());

    TDrawArea* draw_area = rge_base_game->draw_area;
    if (this->setup(draw_area, info_file,
                    static_cast<TEasy_Panel*>(tabList[0])->get_info_id(),
                    1) == 0) {
        this->error_code = 1;
        return;
    }

    this->setup_shadow_area(0);
    this->set_ideal_size(0x280, 0x1E0);

    if (this->create_text(this, &this->screenTitle, IDS_SAVED_GAMES_TITLE,
                          0x14, 0x0A, 0x258, 0x1E, 1, 1, 0, 0) == 0) {
        return;
    }
    if (this->create_text(this, &this->listTitle, IDS_SELECT_SAVED_GAME_TITLE,
                          0x14, 0x2D, 0x258, 0x14, 4, 0, 0, 0) == 0) {
        return;
    }
    if (this->create_list(this, &this->list,
                          0x14, 0x41, 0x258, 0x160, 0x0B) == 0) {
        return;
    }
    if (this->create_auto_scrollbar(&this->scrollbar, this->list, 0x14) == 0) {
        return;
    }

    this->scrollbar->set_help_info(IDS_HELP_SAVED_GAME_NAME, -1);

    TButtonPanel** ok_button = &this->okButton;
    if (this->create_button(this, ok_button, IDS_BUTTON_OK,
                            0, 0x1E, 0x1B8, 0xB4, 0x1E, 0, 0, 0) == 0) {
        return;
    }
    if (this->create_button(this, &this->deleteButton, IDS_BUTTON_DELETE,
                            0, 0xE6, 0x1B8, 0xB4, 0x1E, 0, 0, 0) == 0) {
        return;
    }
    if (this->create_button(this, &this->cancelButton, IDS_BUTTON_CANCEL,
                            0, 0x1AE, 0x1B8, 0xB4, 0x1E, 0, 0, 0) == 0) {
        return;
    }

    (*ok_button)->set_help_info(IDS_HELP_OK, -1);
    this->cancelButton->set_help_info(IDS_HELP_CANCEL, -1);
    TButtonPanel* cancel_button = this->cancelButton;
    cancel_button->hotkey = 0x1B;
    cancel_button->hotkey_shift = 0;
    TButtonPanel* delete_button = this->deleteButton;
    delete_button->hotkey_shift = 0;
    delete_button->hotkey = 0x2E;

    this->fillList();
    if (this->list->currentLine()[0] == 0) {
        (*ok_button)->set_disabled(1);
        this->deleteButton->set_disabled(1);
    }

    long line = this->list->get_line(
        static_cast<TRIBE_Game*>(rge_base_game)->get_save_game_name());
    if (line != -1) {
        this->list->scroll_cur_line(1, (short)line, 1);
    }

    this->set_curr_child(this->list);
    tabList[1] = this->list;
    tabList[2] = this->okButton;
    tabList[3] = this->deleteButton;
    tabList[4] = this->cancelButton;
    this->set_tab_order(tabList + 1, 4);
}

TribeLoadSavedGameScreen::~TribeLoadSavedGameScreen() {
    this->delete_panel((TPanel**)&this->screenTitle);
    this->delete_panel((TPanel**)&this->listTitle);
    this->delete_panel((TPanel**)&this->list);
    this->delete_panel((TPanel**)&this->scrollbar);
    this->delete_panel((TPanel**)&this->okButton);
    this->delete_panel((TPanel**)&this->cancelButton);
    this->delete_panel((TPanel**)&this->deleteButton);
}

void TribeLoadSavedGameScreen::fillList() {
    char file_name[260];
    _finddata_t fileInfo;
    long find_handle;
    int name_length;

    this->list->empty_list();
    this->list->sorted = 1;

    sprintf(file_name, "%s*.gam", rge_base_game->prog_info->save_dir);
    find_handle = _findfirst(file_name, &fileInfo);
    while (find_handle != -1) {
        name_length = strlen(fileInfo.name) - 4;
        strncpy(file_name, fileInfo.name, name_length);
        file_name[name_length] = 0;
        this->list->append_line(file_name, 0);
        if (_findnext(find_handle, &fileInfo) == -1) {
            break;
        }
    }

    sprintf(file_name, "%s*.gmx", rge_base_game->prog_info->save_dir);
    find_handle = _findfirst(file_name, &fileInfo);
    while (find_handle != -1) {
        name_length = strlen(fileInfo.name) - 4;
        strncpy(file_name, fileInfo.name, name_length);
        file_name[name_length] = 0;
        this->list->append_line(file_name, 0);
        if (_findnext(find_handle, &fileInfo) == -1) {
            break;
        }
    }
}

long TribeLoadSavedGameScreen::handle_idle() {
    if (rge_base_game->input_enabled == 0) {
        rge_base_game->enable_input();
    }
    return TPanel::handle_idle();
}

long TribeLoadSavedGameScreen::action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2) {
    char fileName[260];
    char fileNameNoExt[260];

    if (fromPanel != 0) {
        if (fromPanel->panelName() != 0 &&
            strcmp(fromPanel->panelName(), "Cancel Dialog") == 0) {
            panel_system.destroyPanel("Cancel Dialog");

            if (actionIn == 0) {
                char* save_dir = rge_base_game->prog_info->save_dir;
                sprintf(fileName, "%s%s.gam", save_dir, this->list->currentLine());
                _unlink(fileName);

                // Reload before the second selected-line lookup.
                save_dir = rge_base_game->prog_info->save_dir;
                sprintf(fileName, "%s%s.gmx", save_dir, this->list->currentLine());
                _unlink(fileName);

                this->list->delete_line(this->list->get_line());
                if (*this->list->currentLine() == 0) {
                    this->okButton->set_disabled(1);
                    this->deleteButton->set_disabled(1);
                    return 1;
                }
            }
            return 1;
        }

        if (fromPanel == this->deleteButton && actionIn == 1) {
            if (*this->list->currentLine() != 0) {
                char text[556];

                this->get_string(IDS_CONFIRM_DELETE_FILE, fileName, 256);
                sprintf(text, fileName, this->list->currentLine());
                this->popupYesNoDialog(text, "Cancel Dialog", TEASY_POPUP_WIDTH, 100);
            }
        }

        if (fromPanel == this->list) {
            if (actionIn == 3) {
                this->action(this->okButton, 1, 0, 0);
                return 1;
            }
            goto fallback;
        }

        if (fromPanel == this->okButton) {
            if (actionIn != 1) {
                goto fallback;
            }

            if (this->list->numberLines() > 0) {
                _finddata_t fileInfo;
                long find_handle;
                int loaded;

                strcpy(fileNameNoExt, this->list->currentLine());
                sprintf(fileName, "%s%s.gmx",
                        rge_base_game->prog_info->save_dir,
                        fileNameNoExt);
                find_handle = _findfirst(fileName, &fileInfo);
                if (find_handle == -1) {
                    sprintf(fileName, "%s.gam", fileNameNoExt);
                } else {
                    sprintf(fileName, "%s.gmx", fileNameNoExt);
                }
                loaded = static_cast<TRIBE_Game*>(rge_base_game)->load_game(fileName);
                if (loaded == 0) {
                    this->popupOKDialog(IDS_ERROR_CANNOT_LOAD_SAVED_GAME, 0, TEASY_POPUP_WIDTH, 100);
                    return 1;
                }
            }
        } else {
            if (fromPanel != this->cancelButton || actionIn != 1) {
                goto fallback;
            }

            if (panel_system.panel("Game Screen") != 0) {
                if (rge_base_game->singlePlayerGame() == 1 &&
                    rge_base_game->save_paused == 0) {
                    rge_base_game->set_paused(0, 0);
                }
                panel_system.setCurrentPanel("Game Screen", 0);
            } else {
                rge_base_game->disable_input();
                new TribeSPMenuScreen;
                panel_system.setCurrentPanel("Single Player Menu", 0);
            }
            panel_system.destroyPanel("Load Saved Game Screen");
        }
        return 1;
    }

fallback:
    return this->TEasy_Panel::action(fromPanel, actionIn, a1, a2);
}
