// PDB source module: C:\msdev\work\age1_x1\scr_load.cpp.
// Normal owners follow PDB source order.

#include "../include/scr_load.h"
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

TribeLoadSavedGameScreen::TribeLoadSavedGameScreen()
    : TScreenPanel("Load Saved Game Screen")
{
    TPanel* tab_list[5];
    char info_file[260];

    this->screenTitle = 0;
    this->listTitle = 0;
    this->list = 0;
    this->scrollbar = 0;
    this->okButton = 0;
    this->cancelButton = 0;
    this->deleteButton = 0;

    tab_list[0] = panel_system.currentPanel();
    strcpy(info_file,
           static_cast<TEasy_Panel*>(tab_list[0])->get_info_file());

    TDrawArea* draw_area = rge_base_game->draw_area;
    if (this->setup(draw_area, info_file,
                    static_cast<TEasy_Panel*>(tab_list[0])->get_info_id(),
                    1) == 0) {
        this->error_code = 1;
        return;
    }

    this->setup_shadow_area(0);
    this->set_ideal_size(0x280, 0x1E0);

    if (this->create_text(this, &this->screenTitle, 0x24FF,
                          0x14, 0x0A, 0x258, 0x1E, 1, 1, 0, 0) == 0) {
        return;
    }
    if (this->create_text(this, &this->listTitle, 0x2502,
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

    this->scrollbar->set_help_info(0x7670, -1);

    TButtonPanel** ok_button = &this->okButton;
    if (this->create_button(this, ok_button, 0x0FA1,
                            0, 0x1E, 0x1B8, 0xB4, 0x1E, 0, 0, 0) == 0) {
        return;
    }
    if (this->create_button(this, &this->deleteButton, 0x24C9,
                            0, 0xE6, 0x1B8, 0xB4, 0x1E, 0, 0, 0) == 0) {
        return;
    }
    if (this->create_button(this, &this->cancelButton, 0x0FA2,
                            0, 0x1AE, 0x1B8, 0xB4, 0x1E, 0, 0, 0) == 0) {
        return;
    }

    (*ok_button)->set_help_info(0x7531, -1);
    this->cancelButton->set_help_info(0x7532, -1);
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
    tab_list[1] = this->list;
    tab_list[2] = this->okButton;
    tab_list[3] = this->deleteButton;
    tab_list[4] = this->cancelButton;
    this->set_tab_order(tab_list + 1, 4);
}

TribeLoadSavedGameScreen::~TribeLoadSavedGameScreen()
{
    this->delete_panel((TPanel**)&this->screenTitle);
    this->delete_panel((TPanel**)&this->listTitle);
    this->delete_panel((TPanel**)&this->list);
    this->delete_panel((TPanel**)&this->scrollbar);
    this->delete_panel((TPanel**)&this->okButton);
    this->delete_panel((TPanel**)&this->cancelButton);
    this->delete_panel((TPanel**)&this->deleteButton);
}

void TribeLoadSavedGameScreen::fillList()
{
    char file_name[260];
    _finddata_t file_info;
    long find_handle;
    int name_length;

    this->list->empty_list();
    this->list->sorted = 1;

    sprintf(file_name, "%s*.gam", rge_base_game->prog_info->save_dir);
    find_handle = _findfirst(file_name, &file_info);
    while (find_handle != -1) {
        name_length = strlen(file_info.name) - 4;
        strncpy(file_name, file_info.name, name_length);
        file_name[name_length] = 0;
        this->list->append_line(file_name, 0);
        if (_findnext(find_handle, &file_info) == -1) {
            break;
        }
    }

    sprintf(file_name, "%s*.gmx", rge_base_game->prog_info->save_dir);
    find_handle = _findfirst(file_name, &file_info);
    while (find_handle != -1) {
        name_length = strlen(file_info.name) - 4;
        strncpy(file_name, file_info.name, name_length);
        file_name[name_length] = 0;
        this->list->append_line(file_name, 0);
        if (_findnext(find_handle, &file_info) == -1) {
            break;
        }
    }
}

long TribeLoadSavedGameScreen::handle_idle()
{
    if (rge_base_game->input_enabled == 0) {
        rge_base_game->enable_input();
    }
    return TPanel::handle_idle();
}

long TribeLoadSavedGameScreen::action(TPanel* panel, long message,
                                      unsigned long param_3,
                                      unsigned long param_4)
{
    char file_name[260];
    char file_name_no_extension[260];

    if (panel != 0) {
        if (panel->panelName() != 0 &&
            strcmp(panel->panelName(), "Cancel Dialog") == 0) {
            panel_system.destroyPanel("Cancel Dialog");

            if (message == 0) {
                char* save_dir = rge_base_game->prog_info->save_dir;
                sprintf(file_name, "%s%s.gam", save_dir,
                        this->list->currentLine());
                _unlink(file_name);

                // BINARY NOTE: Reload before the second selected-line lookup.
                save_dir = rge_base_game->prog_info->save_dir;
                sprintf(file_name, "%s%s.gmx", save_dir,
                        this->list->currentLine());
                _unlink(file_name);

                this->list->delete_line(this->list->get_line());
                if (*this->list->currentLine() == 0) {
                    this->okButton->set_disabled(1);
                    this->deleteButton->set_disabled(1);
                    return 1;
                }
            }
            return 1;
        }

        if (panel == this->deleteButton && message == 1) {
            if (*this->list->currentLine() != 0) {
                char confirmation[512];

                this->get_string(0x24CA, file_name, 0x100);
                sprintf(confirmation, file_name, this->list->currentLine());
                this->popupYesNoDialog(confirmation, "Cancel Dialog", 0x1C2,
                                       100);
            }
        }

        if (panel == this->list) {
            if (message == 3) {
                this->action(this->okButton, 1, 0, 0);
                return 1;
            }
            goto fallback;
        }

        if (panel == this->okButton) {
            if (message != 1) {
                goto fallback;
            }

            if (this->list->numberLines() > 0) {
                _finddata_t file_info;
                long find_handle;
                int loaded;

                strcpy(file_name_no_extension, this->list->currentLine());
                sprintf(file_name, "%s%s.gmx",
                        rge_base_game->prog_info->save_dir,
                        file_name_no_extension);
                find_handle = _findfirst(file_name, &file_info);
                if (find_handle == -1) {
                    sprintf(file_name, "%s.gam", file_name_no_extension);
                } else {
                    sprintf(file_name, "%s.gmx", file_name_no_extension);
                }
                loaded =
                    static_cast<TRIBE_Game*>(rge_base_game)->load_game(file_name);
                if (loaded == 0) {
                    this->popupOKDialog(0x2501, 0, 0x1C2, 100);
                    return 1;
                }
            }
        } else {
            if (panel != this->cancelButton || message != 1) {
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
    return this->TEasy_Panel::action(panel, message, param_3, param_4);
}
