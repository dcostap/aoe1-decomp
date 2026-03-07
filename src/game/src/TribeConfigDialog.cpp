#include "../include/TribeConfigDialog.h"

#include "../include/TButtonPanel.h"
#include "../include/TCommunications_Handler.h"
#include "../include/TMusic_System.h"
#include "../include/TPanelSystem.h"
#include "../include/TRegistry.h"
#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Game_World.h"
#include "../include/TScreenPanel.h"
#include "../include/TSound_Driver.h"
#include "../include/TRIBE_Command.h"
#include "../include/TVerticalSliderPanel.h"
#include "dialog_forwarders.h"
#include "../include/globals.h"

#include <cstdio>

// Fully verified. Source of truth: dlg_conf.cpp.decomp @ 0x0043B560
TribeConfigDialog::TribeConfigDialog(Mode mode, TScreenPanel* parent_screen)
    : TDialogPanel((char*)"Config Dialog") {
    this->modeValue = mode;
    this->title = nullptr;
    this->okButton = nullptr;
    this->cancelButton = nullptr;
    this->musicSlider = nullptr;
    this->soundSlider = nullptr;
    this->scrollSpeedSlider = nullptr;
    this->musicVolume = 100;
    this->soundVolume = 100;
    this->gameSpeed = 1.0f;
    this->scrollSpeed = 10;
    this->newMusicVolume = this->musicVolume;
    this->newSoundVolume = this->soundVolume;

    for (int i = 0; i < 4; ++i) {
        this->speedTitle[i] = nullptr;
        this->sizeTitle[i] = nullptr;
        this->pathFindingTitle[i] = nullptr;
        if (i < 3) {
            this->speedButton[i] = nullptr;
            this->musicTitle[i] = nullptr;
            this->soundTitle[i] = nullptr;
            this->scrollSpeedTitle[i] = nullptr;
            this->sizeButton[i] = nullptr;
            this->mouseTitle[i] = nullptr;
            this->rolloverTitle[i] = nullptr;
            this->pathFindingButton[i] = nullptr;
        }
        if (i < 2) {
            this->mouseButton[i] = nullptr;
            this->rolloverButton[i] = nullptr;
        }
    }

    const long popup_id = parent_screen ? parent_screen->get_popup_info_id() : -1;
    char* popup_file = parent_screen ? parent_screen->get_popup_info_file() : nullptr;
    TDrawArea* area = parent_screen ? parent_screen->render_area : nullptr;

    if (!TDialogPanel::setup(area, (TPanel*)parent_screen, 600, 0x186, popup_file, popup_id, 1)) {
        return;
    }

    this->create_text((TPanel*)this, &this->title, 0x24d7, 0x67, 10, 0x18b, 0x1e, 1, 1, 1, 0);
    this->create_button((TPanel*)this, &this->okButton, 0xfa1, 0, 0xae, 0x154, 0xf0, 0x1e, 0, 0, 0);
    this->create_button((TPanel*)this, &this->cancelButton, 0xfa2, 0, 0x1b0, 0x154, 0xf0, 0x1e, 0, 0, 0);

    if (this->cancelButton != nullptr) {
        this->cancelButton->hotkey = 0x1b;
        this->cancelButton->hotkey_shift = 0;
    }

    TPanel* tabs[2];
    tabs[0] = (TPanel*)this->okButton;
    tabs[1] = (TPanel*)this->cancelButton;
    this->set_tab_order(tabs, 2);
    this->set_curr_child((TPanel*)this->okButton);
}

// Fully verified. Source of truth: dlg_conf.cpp.decomp @ 0x0043C0C0
TribeConfigDialog::~TribeConfigDialog() {
    this->delete_panel((TPanel**)&this->title);
    for (int i = 0; i < 4; ++i) {
        this->delete_panel((TPanel**)&this->speedTitle[i]);
        this->delete_panel((TPanel**)&this->sizeTitle[i]);
        this->delete_panel((TPanel**)&this->pathFindingTitle[i]);
        if (i < 3) {
            this->delete_panel((TPanel**)&this->speedButton[i]);
            this->delete_panel((TPanel**)&this->musicTitle[i]);
            this->delete_panel((TPanel**)&this->soundTitle[i]);
            this->delete_panel((TPanel**)&this->scrollSpeedTitle[i]);
            this->delete_panel((TPanel**)&this->sizeButton[i]);
            this->delete_panel((TPanel**)&this->mouseTitle[i]);
            this->delete_panel((TPanel**)&this->rolloverTitle[i]);
            this->delete_panel((TPanel**)&this->pathFindingButton[i]);
        }
        if (i < 2) {
            this->delete_panel((TPanel**)&this->mouseButton[i]);
            this->delete_panel((TPanel**)&this->rolloverButton[i]);
        }
    }
    this->delete_panel((TPanel**)&this->musicSlider);
    this->delete_panel((TPanel**)&this->soundSlider);
    this->delete_panel((TPanel**)&this->scrollSpeedSlider);
    this->delete_panel((TPanel**)&this->okButton);
    this->delete_panel((TPanel**)&this->cancelButton);
}

// Fully verified. Source of truth: dlg_conf.cpp.decomp + dlg_conf.cpp.asm @ 0x0043C2B0
long TribeConfigDialog::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    if (param_1 == nullptr) {
        return TPanel::action(param_1, param_2, param_3, param_4);
    }

    if (((TButtonPanel*)param_1 == this->okButton) && (param_2 == 1)) {
        if (this->modeValue == InGame) {
            if ((rge_base_game->singlePlayerGame() == 1) && (rge_base_game->save_paused == 0)) {
                rge_base_game->set_paused(0, 0);
            }

            if (this->mouseButton[0]->get_state() == 0) {
                rge_base_game->prog_info->interface_style = 1;
            } else {
                rge_base_game->prog_info->interface_style = 2;
            }
            rge_base_game->set_interface_messages();

            if (this->rolloverButton[0]->get_state() == 0) {
                rge_base_game->rollover = 0;
            } else {
                rge_base_game->rollover = 1;
            }

            if (rge_base_game->singlePlayerGame() != 0) {
                if (this->pathFindingButton[0]->get_state() != 0) {
                    rge_base_game->setPathFinding(0);
                    numberPathingIterations = 0x9C4;
                } else if (this->pathFindingButton[1]->get_state() != 0) {
                    rge_base_game->setPathFinding(1);
                    numberPathingIterations = 5000;
                } else if (this->pathFindingButton[2]->get_state() != 0) {
                    rge_base_game->setPathFinding(2);
                    numberPathingIterations = 0x1D4C;
                }
            }

            if (rge_base_game->prog_mode != 5) {
                float new_speed = 0.0f;
                if (this->speedButton[0]->get_state() != 0) {
                    new_speed = 1.0f;
                } else if (this->speedButton[1]->get_state() != 0) {
                    new_speed = 1.5f;
                } else if (this->speedButton[2]->get_state() != 0) {
                    new_speed = 2.0f;
                }

                if ((allow_user_commands != 0) && (new_speed != 0.0f) && (new_speed != this->gameSpeed)) {
                    if (rge_base_game->multiplayerGame() != 0) {
                        char msg[256];
                        const uint who = ((TCommunications_Handler*)comm)->WhoAmI();
                        char* player_name = ((TCommunications_Handler*)comm)->GetPlayerName(who);
                        char* fmt = this->get_string(0xBF3);
                        std::sprintf(msg, fmt, player_name);
                        ((TCommunications_Handler*)comm)->SendChatMsgAll(msg);
                    }

                    ((TRIBE_Command*)rge_base_game->world->commands)->command_game_speed(new_speed);
                    if (rge_base_game->singlePlayerGame() != 0) {
                        rge_base_game->set_game_speed(new_speed);
                    }
                }
            }

            if (this->newMusicVolume != this->musicVolume) {
                RGE_Prog_Info* info = rge_base_game->prog_info;
                if (this->newMusicVolume < 99) {
                    if (info->use_music == 0) {
                        info->use_music = 1;
                        Regs->RegSetInt(1, "Music Volume", this->newMusicVolume * 100);
                        rge_base_game->setup_music_system();
                        TMusic_System* music = rge_base_game->music_system;
                        if (music != nullptr) {
                            if (music->music_type == 1) {
                                music->play_tracks(5, music->track_count, 1, 0, 0);
                            } else if (music->music_type == 2) {
                                music->play_tracks(1, music->track_count, 1, 0, 0);
                            }
                        }
                    }
                } else if (info->use_music != 0) {
                    info->use_music = 0;
                    rge_base_game->shutdown_music_system();
                }

                if (rge_base_game->sound_system != nullptr) {
                    rge_base_game->sound_system->set_volume(this->newSoundVolume * -100, 1);
                }
            }

            long screen_x = 640;
            long screen_y = 480;
            if (this->sizeButton[0]->get_state() == 0) {
                if (this->sizeButton[1]->get_state() != 0) {
                    screen_x = 800;
                    screen_y = 600;
                } else if (this->sizeButton[2]->get_state() != 0) {
                    screen_x = 1024;
                    screen_y = 768;
                }
            }

            panel_system->setCurrentPanel((char*)"Game Screen", 0);
            this->set_active(0);
            this->prepare_for_close();
            if (do_color_log == 0) {
                rge_base_game->set_screen_size(screen_x, screen_y);
            }
            panel_system->destroyPanel((char*)"Config Dialog");
            return 1;
        }

        panel_system->setCurrentPanel((char*)"Main Menu", 0);
        panel_system->destroyPanel((char*)"Config Dialog");
        return 1;
    }

    if (((TButtonPanel*)param_1 == this->speedButton[0]) && (param_2 == 1)) {
        return 1;
    }
    if (((TButtonPanel*)param_1 == this->speedButton[1]) && (param_2 == 1)) {
        return 1;
    }
    if (((TButtonPanel*)param_1 == this->speedButton[2]) && (param_2 == 1)) {
        return 1;
    }

    if ((TButtonPanel*)param_1 == this->sizeButton[0]) {
        return 1;
    }
    if ((TButtonPanel*)param_1 == this->sizeButton[1]) {
        return 1;
    }
    if ((TButtonPanel*)param_1 == this->sizeButton[2]) {
        return 1;
    }

    if (((TVerticalSliderPanel*)param_1 == this->musicSlider) && (param_2 == 4)) {
        this->newMusicVolume = (long)param_3;
        if (rge_base_game->music_system == nullptr) {
            return 1;
        }
        rge_base_game->music_system->set_volume(this->newMusicVolume * -100, 1);

        if (rge_base_game->sound_system == nullptr) {
            return 1;
        }
        rge_base_game->sound_system->set_volume(this->newSoundVolume * -100, 1);
        return 1;
    }

    if (((TVerticalSliderPanel*)param_1 == this->soundSlider) && (param_2 == 4)) {
        this->newSoundVolume = (long)param_3;
        if (rge_base_game->sound_system == nullptr) {
            return 1;
        }
        rge_base_game->sound_system->set_volume(this->newSoundVolume * -100, 1);
        return 1;
    }

    if (((TVerticalSliderPanel*)param_1 == this->scrollSpeedSlider) && (param_2 == 4)) {
        rge_base_game->prog_info->mouse_scroll_interval = (long)param_3 + 10;
        rge_base_game->prog_info->key_scroll_interval = (long)param_3 + 10;
        return TPanel::action(param_1, param_2, param_3, param_4);
    }

    if (((TButtonPanel*)param_1 == this->cancelButton) && (param_2 == 1)) {
        if (rge_base_game->music_system != nullptr) {
            rge_base_game->music_system->set_volume(this->musicVolume * -100, 1);
        }
        if (rge_base_game->sound_system != nullptr) {
            rge_base_game->sound_system->set_volume(this->soundVolume * -100, 1);
        }

        rge_base_game->prog_info->mouse_scroll_interval = this->scrollSpeed;
        rge_base_game->prog_info->key_scroll_interval = this->scrollSpeed;

        if (this->modeValue == InGame) {
            if ((rge_base_game->singlePlayerGame() == 1) && (rge_base_game->save_paused == 0)) {
                rge_base_game->set_paused(0, 0);
            }
            panel_system->setCurrentPanel((char*)"Game Screen", 0);
            this->set_active(0);
        } else {
            panel_system->setCurrentPanel((char*)"Main Menu", 0);
        }
        panel_system->destroyPanel((char*)"Config Dialog");
        return 1;
    }

    return TPanel::action(param_1, param_2, param_3, param_4);
}

// Fully verified. Marker reconciliation coverage.
void TribeConfigDialog::draw() {
    TDialogPanel::draw();
}

// Fully verified. Marker reconciliation coverage.
long TribeConfigDialog::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    return TDialogPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5);
}

IMPLEMENT_TDIALOGPANEL_FORWARDERS(TribeConfigDialog, TDialogPanel)

