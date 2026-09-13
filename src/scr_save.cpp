#include <io.h>
#include <stdio.h>
#include <string.h>

#include "../include/scr_save.h"
#include "../include/scr_sed.h"
#include "../include/scr_sedo.h"

TribeSaveGameScreen::TribeSaveGameScreen(Mode mode, char* name, int quit)
    : TScreenPanel("Save Game Screen"), modeValue(mode) {
    TPanel* fromPanel;
    TPanel* tabList[5];
    char info_file[260];

    this->quit_after_save = quit;
    this->title = 0;
    this->input = 0;
    this->list = 0;
    this->scrollbar = 0;
    this->okButton = 0;
    this->cancelButton = 0;
    this->deleteButton = 0;

    if (name == 0 && mode == SaveGame) {
        name = static_cast<TRIBE_Game*>(rge_base_game)->get_save_game_name();
    }

    fromPanel = panel_system.currentPanel();
    strcpy(info_file, static_cast<TEasy_Panel*>(fromPanel)->get_popup_info_file());

    TDrawArea* draw_area = rge_base_game->draw_area;
    if (!this->setup(draw_area,
                     info_file,
                     static_cast<TEasy_Panel*>(fromPanel)->get_popup_info_id(),
                     1)) {
        this->error_code = 1;
        return;
    }

    this->setup_shadow_area(0);
    this->set_ideal_size(640, 480);

    TTextPanel** titlePtr = &this->title;
    if (!this->create_text(this, titlePtr,
                           (this->modeValue != SaveGame) + 0x24C3,
                           20, 20, 600, 30, 1, 1, 0, 0)) {
        return;
    }

    unsigned int width;
    if (0x7A - strlen(rge_base_game->work_dir) > 0x50) {
        width = 0x50;
    } else {
        width = 0x7A - strlen(rge_base_game->work_dir);
    }

    if (!this->create_edit(this, &this->input, name, static_cast<short>(width),
                           TEditPanel::FormatFileNoExt,
                           20, 70, 600, 23, 11, 1, 1)) {
        return;
    }
    this->input->set_help_info(0x7670, -1);

    if (!this->create_list(this, &this->list, 20, 0x6E, 600, 300, 11)) {
        return;
    }
    if (!this->create_auto_scrollbar(&this->scrollbar, this->list, 20)) {
        return;
    }
    this->scrollbar->set_help_info(0x7671, -1);

    if (!this->create_button(this, &this->okButton, 0xFA1, 0,
                             30, 440, 180, 30, 0, 0, 0)) {
        return;
    }
    if (!this->create_button(this, &this->deleteButton, 0x24C9, 0,
                             230, 440, 180, 30, 0, 0, 0)) {
        return;
    }
    if (!this->create_button(this, &this->cancelButton, 0xFA2, 0,
                             430, 440, 180, 30, 0, 0, 0)) {
        return;
    }

    this->okButton->set_help_info(0x7531, -1);
    this->cancelButton->set_help_info(0x7532, -1);
    TButtonPanel* cancelLocal = this->cancelButton;
    int zero = 0;
    cancelLocal->hotkey = 0x1B;
    cancelLocal->hotkey_shift = zero;
    TButtonPanel* deleteLocal = this->deleteButton;
    deleteLocal->hotkey_shift = zero;
    deleteLocal->hotkey = 0x2E;

    this->fillList();
    if (this->list->currentLine()[0] == 0) {
        this->deleteButton->set_disabled(1);
    }

    this->set_curr_child(this->input);
    tabList[0] = this->input;
    tabList[1] = this->list;
    tabList[2] = this->okButton;
    tabList[3] = this->deleteButton;
    tabList[4] = this->cancelButton;
    this->set_tab_order(tabList, 5);
}

TribeSaveGameScreen::~TribeSaveGameScreen() {
    this->delete_panel((TPanel**)&this->title);
    this->delete_panel((TPanel**)&this->input);
    this->delete_panel((TPanel**)&this->list);
    this->delete_panel((TPanel**)&this->scrollbar);
    this->delete_panel((TPanel**)&this->okButton);
    this->delete_panel((TPanel**)&this->cancelButton);
    this->delete_panel((TPanel**)&this->deleteButton);
}

void TribeSaveGameScreen::fillList() {
    char file_name[260];
    struct _finddata_t fileInfo;

    this->list->empty_list();
    this->list->sorted = 1;

    long handle;
    if (this->modeValue == SaveGame) {
        sprintf(file_name, "%s*.gam", rge_base_game->prog_info->save_dir);
        handle = _findfirst(file_name, &fileInfo);
    } else {
        sprintf(file_name, "%s*.scn", rge_base_game->prog_info->scenario_dir);
        handle = _findfirst(file_name, &fileInfo);
    }

    if (handle != -1) {
        do {
            char* name = fileInfo.name;
            int count = strlen(name) - 4;
            strncpy(file_name, name, count);
            file_name[count] = 0;
            this->list->append_line(file_name, 0);
        } while (_findnext(handle, &fileInfo) != -1);
    }

    if (this->modeValue == SaveGame) {
        sprintf(file_name, "%s*.gmx", rge_base_game->prog_info->save_dir);
        handle = _findfirst(file_name, &fileInfo);
    } else {
        sprintf(file_name, "%s*.scx", rge_base_game->prog_info->scenario_dir);
        handle = _findfirst(file_name, &fileInfo);
    }

    if (handle != -1) {
        do {
            char* name = fileInfo.name;
            int count = strlen(name) - 4;
            strncpy(file_name, name, count);
            file_name[count] = 0;
            this->list->append_line(file_name, 0);
        } while (_findnext(handle, &fileInfo) != -1);
    }
}

long TribeSaveGameScreen::action(TPanel* panel, long message,
                                 unsigned long param_3,
                                 unsigned long param_4) {
    char tempFileName[260];
    char text[556];
    uchar exist_flag;
    char* directory;
    char* line;
    RGE_Prog_Info* prog_info;
    Mode mode;

    if (panel != 0) {
        if (panel->panelName() != 0 &&
            strcmp(panel->panelName(), "Cancel Dialog") == 0) {
            panel_system.destroyPanel("Cancel Dialog");
            if (message == 0) {
                if (this->modeValue == SaveGame) {
                    directory = rge_base_game->prog_info->save_dir;
                    line = this->list->currentLine();
                    sprintf(tempFileName, "%s%s.gam",
                            directory, line);
                } else {
                    directory = rge_base_game->prog_info->scenario_dir;
                    line = this->list->currentLine();
                    sprintf(tempFileName, "%s%s.scn",
                            directory, line);
                }
                _unlink(tempFileName);

                mode = this->modeValue;
                prog_info = rge_base_game->prog_info;
                if (mode == SaveGame) {
                    directory = prog_info->save_dir;
                    sprintf(tempFileName, "%s%s.gmx",
                            directory, this->list->currentLine());
                } else {
                    directory = prog_info->scenario_dir;
                    sprintf(tempFileName, "%s%s.scx",
                            directory, this->list->currentLine());
                }
                _unlink(tempFileName);

                this->list->delete_line(this->list->get_line());
                this->input->set_text(this->list->currentLine());
                if (this->list->currentLine()[0] == 0) {
                    this->deleteButton->set_disabled(1);
                }
            }
            return 1;
        }

        if (panel == this->deleteButton && message == 1 &&
            this->list->currentLine()[0] != 0) {
            this->get_string(0x24CA, tempFileName, 0x100);
            sprintf(text, tempFileName, this->list->currentLine());
            this->popupYesNoDialog(text, "Cancel Dialog", 0x1C2, 100);
        }

        if (panel == this->list) {
            if (message == 1) {
                this->input->set_text(this->list->currentLine());
                return 1;
            }
        }

        if ((panel == this->okButton && message == 1) ||
            (panel == this->input && message == 0) ||
            (panel == this->list && message == 3)) {
            this->input->get_trimmed_str(this->fileNameNoExt, 0x104);
            if (strlen(this->fileNameNoExt) == 0) {
                if (this->modeValue == SaveGame) {
                    this->popupOKDialog(0x24C6, 0, 0x1C2, 100);
                } else {
                    this->popupOKDialog(0x24C7, 0, 0x1C2, 100);
                }
                return 1;
            }

            exist_flag = 0;
            if (this->modeValue == SaveGame) {
                sprintf(this->fileName, "%s.gam", this->fileNameNoExt);
                sprintf(tempFileName, "%s%s",
                        rge_base_game->prog_info->save_dir,
                        this->fileName);
            } else {
                sprintf(this->fileName, "%s.scn", this->fileNameNoExt);
                sprintf(tempFileName, "%s%s",
                        rge_base_game->prog_info->scenario_dir,
                        this->fileName);
            }

            FILE* file = fopen(tempFileName, "rb");
            if (file != 0) {
                exist_flag = 1;
                fclose(file);
            }

            if (this->modeValue == SaveGame) {
                sprintf(this->fileName, "%s.gmx", this->fileNameNoExt);
                sprintf(tempFileName, "%s%s",
                        rge_base_game->prog_info->save_dir,
                        this->fileName);
            } else {
                sprintf(this->fileName, "%s.scx", this->fileNameNoExt);
                sprintf(tempFileName, "%s%s",
                        rge_base_game->prog_info->scenario_dir,
                        this->fileName);
            }

            if (exist_flag == 0) {
                file = fopen(tempFileName, "rb");
                if (file != 0) {
                    exist_flag = 1;
                    fclose(file);
                }
            }

            if (exist_flag == 0) {
                if (this->modeValue == SaveGame) {
                    if (static_cast<TRIBE_Game*>(rge_base_game)->
                            save_game(this->fileName) == 0) {
                        this->popupOKDialog(0x962, 0, 0x1C2, 100);
                        return 1;
                    }
                } else if (this->modeValue == SaveScenario) {
                    if (static_cast<TRIBE_Game*>(rge_base_game)->
                            save_scenario(this->fileName) == 0) {
                        this->popupOKDialog(0x963, 0, 0x1C2, 100);
                        return 1;
                    }
                } else if (this->modeValue == SaveScenarioEdit) {
                    this->save_for_scenario_editor();
                }
                return 1;
            }

            this->popupYesNoDialog(0x24C8, 0, 0x1C2, 100);
            return 1;
        }

        if ((panel == this->cancelButton && message == 1) ||
            (panel == this->input && message == 1)) {
            if (rge_base_game->singlePlayerGame() == 1 &&
                rge_base_game->save_paused == 0) {
                rge_base_game->set_paused(0, 0);
            }
            if (this->modeValue == SaveScenarioEdit) {
                panel_system.setCurrentPanel("Scenario Editor Screen", 0);
            } else {
                panel_system.setCurrentPanel("Game Screen", 0);
            }
            panel_system.destroyPanel("Save Game Screen");
            return 1;
        }

        if (panel->panelName() != 0 &&
            strcmp(panel->panelName(), "OKDialog") == 0) {
            panel_system.destroyPanel("OKDialog");
            this->set_curr_child(this->input);
            return 1;
        }

        if (panel->panelName() != 0 &&
            strcmp(panel->panelName(), "YesNoDialog") == 0) {
            if (message != 0) {
                panel_system.destroyPanel("YesNoDialog");
                this->set_curr_child(this->input);
                return 1;
            }

            panel_system.destroyPanel("YesNoDialog");
            if (this->modeValue == SaveGame) {
                this->input->get_trimmed_str(this->fileNameNoExt, 0x104);
                sprintf(tempFileName, "%s%s.gam",
                        rge_base_game->prog_info->save_dir,
                        this->fileNameNoExt);
                _unlink(tempFileName);
                if (static_cast<TRIBE_Game*>(rge_base_game)->
                        save_game(this->fileName) == 0) {
                    this->popupOKDialog(0x962, 0, 0x1C2, 100);
                }
            } else if (this->modeValue == SaveScenario) {
                this->input->get_trimmed_str(this->fileNameNoExt, 0x104);
                sprintf(tempFileName, "%s%s.scn",
                        rge_base_game->prog_info->scenario_dir,
                        this->fileNameNoExt);
                _unlink(tempFileName);
                if (static_cast<TRIBE_Game*>(rge_base_game)->
                        save_scenario(this->fileName) == 0) {
                    this->popupOKDialog(0x963, 0, 0x1C2, 100);
                }
            } else if (this->modeValue == SaveScenarioEdit) {
                this->input->get_trimmed_str(this->fileNameNoExt, 0x104);
                sprintf(tempFileName, "%s%s.scn",
                        rge_base_game->prog_info->scenario_dir,
                        this->fileNameNoExt);
                _unlink(tempFileName);
                this->save_for_scenario_editor();
            }
            return 1;
        }
    }

    return this->TEasy_Panel::action(panel, message, param_3, param_4);
}

void TribeSaveGameScreen::save_for_scenario_editor() {
    static_cast<TRIBE_Game*>(rge_base_game)->show_status_message(0x450, 0, -1);

    rge_base_game->world->scenario->Set_scenario_name(this->fileName);
    if (!rge_base_game->world->save_scenario(this->fileName)) {
        this->popupOKDialog(0x963, 0, 0x1C2, 100);
        return;
    }

    TRIBE_Screen_Sed* scenario_editor = static_cast<TRIBE_Screen_Sed*>(
        panel_system.panel("Scenario Editor Screen"));
    if (scenario_editor != 0) {
        scenario_editor->need_to_save_flag = 0;
    }

    int quit = this->quit_after_save;
    if (quit == 1) {
        if (!static_cast<TRIBE_Game*>(rge_base_game)->start_menu()) {
            static_cast<TRIBE_Game*>(rge_base_game)->close();
            return;
        }
        panel_system.destroyPanel("Scenario Editor Screen");
    } else if (quit == 2) {
        TRIBE_Screen_Sed_Open* p = new TRIBE_Screen_Sed_Open;
        panel_system.setCurrentPanel("Scenario Editor Open", 0);
    } else if (quit == 3) {
        static_cast<TRIBE_Game*>(rge_base_game)->start_scenario_editor(0, 0);
    } else {
        panel_system.setCurrentPanel("Scenario Editor Screen", 0);
    }

    panel_system.destroyPanel("Status Screen");
    panel_system.destroyPanel("Save Game Screen");
}
