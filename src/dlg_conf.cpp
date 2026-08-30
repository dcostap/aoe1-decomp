
#include "../include/dlg_conf.h"
#include "../include/panel.h"
#include "../include/Pnl_txt.h"
#include "../include/pnl_btn.h"
#include "../include/pnl_sld.h"
#include "../include/Pnl_scr.h"
#include "../include/drawarea.h"
#include "../include/basegame.h"
#include "../include/main.h"
#include "../include/world.h"
#include "../include/tcommand.h"
#include "../include/music.h"
#include "../include/sounddrv.h"
#include "../include/com_hand.h"
#include "../include/registry.h"
#include "../include/rge_base_game_global.h"
#include "../include/tribegam.h"
#include <string.h>
#include <stdio.h>

extern TCommunications_Handler* comm;
extern TRegistry* Regs;
extern int allow_user_commands;
extern unsigned char do_color_log;
extern "C" int numberPathingIterations;

TribeConfigDialog::TribeConfigDialog(Mode mode, TScreenPanel* parent)
    : TDialogPanel("Config Dialog"), modeValue(mode)
{
    TPanel* tab_list[10];
    int i;
    int string_id;
    int y;
    unsigned char path_finding;

    this->title = 0;
    memset(this->speedTitle, 0, sizeof(this->speedTitle));
    memset(this->speedButton, 0, sizeof(this->speedButton));
    memset(this->musicTitle, 0, sizeof(this->musicTitle));
    this->musicSlider = 0;
    memset(this->soundTitle, 0, sizeof(this->soundTitle));
    this->soundSlider = 0;
    memset(this->scrollSpeedTitle, 0, sizeof(this->scrollSpeedTitle));
    this->scrollSpeedSlider = 0;
    memset(this->sizeTitle, 0, sizeof(this->sizeTitle));
    memset(this->sizeButton, 0, sizeof(this->sizeButton));
    memset(this->mouseTitle, 0, sizeof(this->mouseTitle));
    memset(this->mouseButton, 0, sizeof(this->mouseButton));
    memset(this->rolloverTitle, 0, sizeof(this->rolloverTitle));
    memset(this->rolloverButton, 0, sizeof(this->rolloverButton));
    memset(this->pathFindingTitle, 0, sizeof(this->pathFindingTitle));
    memset(this->pathFindingButton, 0, sizeof(this->pathFindingButton));
    this->okButton = 0;
    this->cancelButton = 0;

    if (!this->setup(parent->renderArea(), parent, 600, 390,
                     parent->get_popup_info_file(),
                     parent->get_popup_info_id(), 1))
        return;

    if (!this->create_text(this, &this->title, 0x24D7, 0x67, 0x0A,
                           0x18B, 0x1E, 1, 1, 1, 0))
        return;
    if (!this->create_text(this, &this->speedTitle[0], 0x24DF, 0x14,
                           0x32, 0x6E, 0x1E, 0x0B, 0, 1, 0))
        return;

    for (i = 0; i < 3; ++i) {
        switch (i) {
        case 0:
            string_id = 0x24D8;
            break;
        case 1:
            string_id = 0x24D9;
            break;
        case 2:
            string_id = 0x24DA;
            break;
        default:
            string_id = 0x24D8;
            break;
        }
        y = i * 0x23 + 0x55;
        if (!this->create_text(this, &this->speedTitle[i + 1], string_id,
                               0x37, y, 0x6E, 0x1E, 0x0B, 0, 1, 0))
            return;
        if (!this->create_radio_button(this, &this->speedButton[i],
                                       0x14, y, 0x1E, 0x1E, 0, 0))
            return;
    }

    for (i = 0; i < 3; ++i)
        this->speedButton[i]->set_radio_info(this->speedButton, 3);

    if (rge_base_game->prog_mode == 5) {
        for (i = 0; i < 3; ++i)
            this->speedButton[i]->set_disabled(1);
    }

    float speed;
    this->gameSpeed = speed = rge_base_game->world->game_speed;
    // these values lower as the three fixed .rdata float literals.
    if (speed == 2.0f) {
        this->speedButton[2]->set_radio_button();
    } else if (speed == 1.5f) {
        this->speedButton[1]->set_radio_button();
    } else if (speed == 1.0f) {
        this->speedButton[0]->set_radio_button();
    }

    if (!this->create_text(this, this->musicTitle, 0x24DB, 0xA5, 0x2D,
                           0x6E, 0x28, 0x0B, 0, 1, 1))
        return;
    if (!this->create_text(this, &this->musicTitle[1], 0x24DC, 0xBE,
                           0x55, 0x6E, 0x14, 0x0B, 0, 1, 0))
        return;
    if (!this->create_text(this, &this->musicTitle[2], 0x24DD, 0xBE,
                           0xA5, 0x6E, 0x14, 0x0B, 0, 1, 0))
        return;
    if (!this->create_vert_slider(this, &this->musicSlider, 100, 10,
                                  0x14, 0xAA, 0x55, 0x14, 100))
        return;

    TMusic_System* music_system = rge_base_game->music_system;
    if (music_system != 0)
        this->musicVolume = music_system->volume / -100;
    else
        this->musicVolume = 99;
    this->musicSlider->set_tab_pos(this->musicVolume);
    this->newMusicVolume = this->musicVolume;

    if (!this->create_text(this, this->soundTitle, 0x24DE, 0x131, 0x2D,
                           0x6E, 0x28, 0x0B, 0, 1, 1))
        return;
    if (!this->create_text(this, &this->soundTitle[1], 0x24DC, 0x14A,
                           0x55, 0x6E, 0x14, 0x0B, 0, 1, 0))
        return;
    if (!this->create_text(this, &this->soundTitle[2], 0x24DD, 0x14A,
                           0xA5, 0x6E, 0x14, 0x0B, 0, 1, 0))
        return;
    if (!this->create_vert_slider(this, &this->soundSlider, 100, 10,
                                  0x14, 0x136, 0x55, 0x14, 100))
        return;

    TSound_Driver* sound_system = rge_base_game->sound_system;
    if (sound_system != 0)
        this->soundVolume = sound_system->get_volume() / -100;
    else
        this->soundVolume = 99;
    this->soundSlider->set_tab_pos(this->soundVolume);
    this->newSoundVolume = this->soundVolume;

    if (!this->create_text(this, this->scrollSpeedTitle, 0x24F0, 0x1BD,
                           0x2D, 0x6E, 0x28, 0x0B, 0, 1, 1))
        return;
    if (!this->create_text(this, &this->scrollSpeedTitle[1], 0x24F1,
                           0x1D6, 0x55, 0x6E, 0x14, 0x0B, 0, 1, 0))
        return;
    if (!this->create_text(this, &this->scrollSpeedTitle[2], 0x24F2,
                           0x1D6, 0xA5, 0x6E, 0x14, 0x0B, 0, 1, 0))
        return;
    if (!this->create_vert_slider(this, &this->scrollSpeedSlider, 100, 10,
                                  0x14, 0x1C2, 0x55, 0x14, 100))
        return;

    this->scrollSpeed = rge_base_game->prog_info->mouse_scroll_interval;
    this->scrollSpeedSlider->set_tab_pos(this->scrollSpeed - 10);

    if (!this->create_text(this, this->sizeTitle, 0x24E0, 0x14, 0xBE,
                           200, 0x1E, 0x0B, 0, 1, 0))
        return;
    for (i = 0; i < 3; ++i) {
        switch (i) {
        case 0:
            string_id = 0x24E7;
            break;
        case 1:
            string_id = 0x24E8;
            break;
        case 2:
            string_id = 0x24E9;
            break;
        }
        y = i * 0x23 + 0xE1;
        if (!this->create_text(this, &this->sizeTitle[i + 1], string_id,
                               0x37, y, 100, 0x1E, 0x0B, 0, 1, 0))
            return;
        if (!this->create_radio_button(this, &this->sizeButton[i],
                                       0x14, y, 0x1E, 0x1E, 0, 0))
            return;
    }
    for (i = 0; i < 3; ++i)
        this->sizeButton[i]->set_radio_info(this->sizeButton, 3);

    int screen_width = this->render_area->DrawSystem->ScreenWidth;
    switch (screen_width) {
    case 0x280:
        this->sizeButton[0]->set_radio_button();
        break;
    case 0x320:
        this->sizeButton[1]->set_radio_button();
        break;
    case 0x400:
        this->sizeButton[2]->set_radio_button();
        break;
    }

    if (!this->render_area->DrawSystem->IsModeAvail(0x280, 0, 8))
        this->sizeButton[0]->set_disabled(1);
    if (!this->render_area->DrawSystem->IsModeAvail(0x320, 0, 8))
        this->sizeButton[1]->set_disabled(1);
    if (!this->render_area->DrawSystem->IsModeAvail(0x400, 0, 8))
        this->sizeButton[2]->set_disabled(1);

    if (!this->create_text(this, this->mouseTitle, 0x24EA, 0xAA, 0xBE,
                           0xD2, 0x1E, 0x0B, 0, 1, 0))
        return;
    for (i = 0; i < 2; ++i) {
        if (i == 0) {
            if (!this->create_text(this, &this->mouseTitle[i + 1],
                                   0x24EB, 0xCD, 0xE1, 0x78, 0x1E,
                                   0x0B, 0, 1, 0))
                return;
        } else {
            if (!this->create_text(this, &this->mouseTitle[i + 1],
                                   0x24EC, 0xCD, i * 0x23 + 0xE1,
                                   0x78, 0x1E, 0x0B, 0, 1, 0))
                return;
        }
        if (!this->create_radio_button(this, &this->mouseButton[i],
                                       0xAA, i * 0x23 + 0xE1,
                                       0x1E, 0x1E, 0, 0))
            return;
    }
    for (i = 0; i < 2; ++i)
        this->mouseButton[i]->set_radio_info(this->mouseButton, 2);
    if (rge_base_game->prog_info->interface_style == 2)
        this->mouseButton[0]->set_radio_button();
    else
        this->mouseButton[1]->set_radio_button();

    if (!this->create_text(this, this->rolloverTitle, 0x24ED, 0x14A,
                           0xBE, 0xD2, 0x1E, 0x0B, 0, 1, 0))
        return;
    for (i = 0; i < 2; ++i) {
        if (i == 0) {
            if (!this->create_text(this, &this->rolloverTitle[i + 1],
                                   0x24EE, 0x16D, 0xE1, 0x78, 0x1E,
                                   0x0B, 0, 1, 0))
                return;
        } else {
            if (!this->create_text(this, &this->rolloverTitle[i + 1],
                                   0x24EF, 0x16D, i * 0x23 + 0xE1,
                                   0x78, 0x1E, 0x0B, 0, 1, 0))
                return;
        }
        if (!this->create_radio_button(this, &this->rolloverButton[i],
                                       0x14A, i * 0x23 + 0xE1,
                                       0x1E, 0x1E, 0, 0))
            return;
    }
    for (i = 0; i < 2; ++i)
        this->rolloverButton[i]->set_radio_info(this->rolloverButton, 2);
    if (rge_base_game->rollover != 0)
        this->rolloverButton[0]->set_radio_button();
    else
        this->rolloverButton[1]->set_radio_button();

    if (!this->create_text(this, this->pathFindingTitle, 0x260D, 0x1CC,
                           0xBE, 0xD2, 0x1E, 0x0B, 0, 1, 0))
        return;
    y = 0xE1;
    for (i = 0; i < 3; ++i) {
        string_id = 0x260E + i;
        if (!this->create_text(this, &this->pathFindingTitle[i + 1],
                               string_id, 0x1EF, y, 0x78, 0x1E,
                               0x0B, 0, 1, 0))
            return;
        if (!this->create_radio_button(this, &this->pathFindingButton[i],
                                       0x1CC, y, 0x1E, 0x1E, 0, 0))
            return;
        if (rge_base_game->multiplayerGame())
            this->pathFindingButton[i]->set_disabled(1);
        y += 0x23;
    }
    for (i = 0; i < 3; ++i)
        this->pathFindingButton[i]->set_radio_info(this->pathFindingButton, 3);

    if (rge_base_game->multiplayerGame())
        path_finding = rge_base_game->mpPathFinding();
    else
        path_finding = rge_base_game->pathFinding();
    if (path_finding <= 2)
        this->pathFindingButton[path_finding]->set_radio_button();

    if (!this->create_button(this, &this->okButton, 0xFA1, 0, 0x78,
                             0x159, 0xAA, 0x1E, 0, 0, 0))
        return;
    if (!this->create_button(this, &this->cancelButton, 0xFA2, 0,
                             0x136, 0x159, 0xAA, 0x1E, 0, 0, 0))
        return;

    this->cancelButton->hotkey = 0x1B;
    this->cancelButton->hotkey_shift = 0;
    this->set_curr_child(this->okButton);
    tab_list[0] = this->okButton;
    tab_list[1] = this->cancelButton;
    this->set_tab_order(tab_list, 2);
}

TribeConfigDialog::~TribeConfigDialog()
{
    this->delete_panel((TPanel**)&this->title);

    TTextPanel** text_panels;
    TButtonPanel** button_panels;
    int count;

    text_panels = this->speedTitle;
    count = 4;
    do {
        this->delete_panel((TPanel**)text_panels);
        ++text_panels;
        --count;
    } while (count != 0);

    button_panels = this->speedButton;
    count = 3;
    do {
        this->delete_panel((TPanel**)button_panels);
        ++button_panels;
        --count;
    } while (count != 0);

    text_panels = this->musicTitle;
    count = 3;
    do {
        this->delete_panel((TPanel**)text_panels);
        ++text_panels;
        --count;
    } while (count != 0);

    this->delete_panel((TPanel**)&this->musicSlider);

    text_panels = this->soundTitle;
    count = 3;
    do {
        this->delete_panel((TPanel**)text_panels);
        ++text_panels;
        --count;
    } while (count != 0);

    this->delete_panel((TPanel**)&this->soundSlider);

    text_panels = this->scrollSpeedTitle;
    count = 3;
    do {
        this->delete_panel((TPanel**)text_panels);
        ++text_panels;
        --count;
    } while (count != 0);

    this->delete_panel((TPanel**)&this->scrollSpeedSlider);

    text_panels = this->sizeTitle;
    count = 4;
    do {
        this->delete_panel((TPanel**)text_panels);
        ++text_panels;
        --count;
    } while (count != 0);

    button_panels = this->sizeButton;
    count = 3;
    do {
        this->delete_panel((TPanel**)button_panels);
        ++button_panels;
        --count;
    } while (count != 0);

    text_panels = this->mouseTitle;
    count = 3;
    do {
        this->delete_panel((TPanel**)text_panels);
        ++text_panels;
        --count;
    } while (count != 0);

    button_panels = this->mouseButton;
    count = 2;
    do {
        this->delete_panel((TPanel**)button_panels);
        ++button_panels;
        --count;
    } while (count != 0);

    text_panels = this->rolloverTitle;
    count = 3;
    do {
        this->delete_panel((TPanel**)text_panels);
        ++text_panels;
        --count;
    } while (count != 0);

    button_panels = this->rolloverButton;
    count = 2;
    do {
        this->delete_panel((TPanel**)button_panels);
        ++button_panels;
        --count;
    } while (count != 0);

    text_panels = this->pathFindingTitle;
    count = 4;
    do {
        this->delete_panel((TPanel**)text_panels);
        ++text_panels;
        --count;
    } while (count != 0);

    button_panels = this->pathFindingButton;
    count = 3;
    do {
        this->delete_panel((TPanel**)button_panels);
        ++button_panels;
        --count;
    } while (count != 0);

    this->delete_panel((TPanel**)&this->okButton);
    this->delete_panel((TPanel**)&this->cancelButton);
}

long TribeConfigDialog::action(TPanel* panel, long event,
    unsigned long param_3, unsigned long param_4)
{
    char msg[256];
    float new_speed;
    TSound_Driver* slider_sound;
    if (panel == 0)
        goto base_action;

    if ((TButtonPanel*)panel == this->okButton && event == 1) {
            int mode = this->modeValue;
            if (mode == 0) {
                if (rge_base_game->singlePlayerGame() == param_3 && rge_base_game->save_paused == 0) {
                    rge_base_game->set_paused(0, 0);
                }

                if (this->mouseButton[0]->get_state() != 0) {
                    rge_base_game->prog_info->interface_style = 2;
                } else {
                    rge_base_game->prog_info->interface_style = event;
                }
                static_cast<TRIBE_Game*>(rge_base_game)->set_interface_messages();

                if (this->rolloverButton[0]->get_state() == 0) {
                    rge_base_game->rollover = 0;
                } else {
                    rge_base_game->rollover = event;
                }

                if (rge_base_game->singlePlayerGame() != 0) {
                    if (this->pathFindingButton[0]->get_state() != 0) {
                        rge_base_game->setPathFinding(0);
                        numberPathingIterations = 0x9C4;
                    } else if (this->pathFindingButton[1]->get_state() != 0) {
                        rge_base_game->setPathFinding(event);
                        numberPathingIterations = 5000;
                    } else if (this->pathFindingButton[2]->get_state() != 0) {
                        rge_base_game->setPathFinding(2);
                        numberPathingIterations = 0x1D4C;
                    }
                }

                if (rge_base_game->prog_mode != 5) {
                    new_speed = 0.0f;
                    if (this->speedButton[0]->get_state() != 0) {
                        new_speed = 1.0f;
                    } else if (this->speedButton[1]->get_state() != 0) {
                        new_speed = 1.5f;
                    } else if (this->speedButton[2]->get_state() != 0) {
                        new_speed = 2.0f;
                    }

                    if (allow_user_commands != 0 && new_speed != 0.0f && new_speed != this->gameSpeed) {
                        if (rge_base_game->multiplayerGame() != 0) {
                            sprintf(msg + 4, this->get_string(0xBF3),
                                comm->GetPlayerName(comm->WhoAmI()));
                            comm->SendChatMsgAll(msg + 4);
                        }
                        static_cast<TRIBE_Command*>(rge_base_game->world->commands)
                            ->command_game_speed(new_speed);
                        if (rge_base_game->singlePlayerGame() != 0) {
                            rge_base_game->set_game_speed(new_speed);
                        }
                    }
                }

                if (this->newMusicVolume != this->musicVolume) {
                    RGE_Prog_Info* info = rge_base_game->prog_info;
                    TMusic_System* music;
                    if (this->newMusicVolume >= 99) {
                        if (info->use_music != 0) {
                            info->use_music = 0;
                            rge_base_game->shutdown_music_system();
                        }
                    } else if (info->use_music == 0) {
                        info->use_music = 1;
                        Regs->RegSetInt(event, "Music Volume", this->newMusicVolume * 100);
                        rge_base_game->setup_music_system();
                        music = rge_base_game->music_system;
                        if (music != 0) {
                            if (music->music_type == 1) {
                                music->play_tracks(5, music->track_count, event, 0, 0);
                            } else if (music->music_type == 2) {
                                music->play_tracks(1, music->track_count, event, 0, 0);
                            }
                        }
                    }

                    if (rge_base_game->sound_system != 0) {
                        rge_base_game->sound_system->set_volume(this->newSoundVolume * -100, event);
                    }
                }

                long width;
                long height;
                if (this->sizeButton[0]->get_state() == 0) {
                    if (this->sizeButton[1]->get_state() != 0) {
                        width = 0x320;
                        height = 0x258;
                    } else if (this->sizeButton[2]->get_state() != 0) {
                        width = 0x400;
                        height = 0x300;
                    } else {
                        width = 0x280;
                        height = 0x1E0;
                    }
                } else {
                    width = 0x280;
                    height = 0x1E0;
                }

                panel_system.setCurrentPanel("Game Screen", 0);
                this->set_active(0);
                this->prepare_for_close();
                if (do_color_log == 0) {
                    rge_base_game->set_screen_size(width, height);
                }
                goto destroy;
            }
        } else {
            if ((TButtonPanel*)panel == this->speedButton[0] && event == 1) {
                return event;
            }
            if ((TButtonPanel*)panel == this->speedButton[1] && event == 1) {
                return event;
            }
            if ((TButtonPanel*)panel == this->speedButton[2] && event == 1) {
                return event;
            }
            if ((TButtonPanel*)panel == this->sizeButton[0]) {
                return 1;
            }
            if ((TButtonPanel*)panel == this->sizeButton[1]) {
                return 1;
            }
            if ((TButtonPanel*)panel == this->sizeButton[2]) {
                return 1;
            }
            if ((TVerticalSliderPanel*)panel == this->musicSlider && event == 4) {
                this->newMusicVolume = param_3;
                TMusic_System* music = rge_base_game->music_system;
                if (music == 0) {
                    return 1;
                }
                music->set_volume(param_3 * -100, 1);
                TSound_Driver* sound = rge_base_game->sound_system;
                if (sound == 0) {
                    return 1;
                }
                slider_sound = sound;
                param_3 = this->newSoundVolume;
                goto slider_sound_call;
            }
            if ((TVerticalSliderPanel*)panel == this->soundSlider && event == 4) {
                this->newSoundVolume = param_3;
                slider_sound = rge_base_game->sound_system;
                if (slider_sound == 0) {
                    return 1;
                }
                goto slider_sound_call;
            }
            if ((TVerticalSliderPanel*)panel == this->scrollSpeedSlider && event == 4) {
                rge_base_game->prog_info->mouse_scroll_interval = param_3 + 10;
                rge_base_game->prog_info->key_scroll_interval = param_3 + 10;
                goto base_action;
            }
            if ((TButtonPanel*)panel == this->cancelButton && event == 1) {
                if (rge_base_game->music_system != 0) {
                    rge_base_game->music_system->set_volume(this->musicVolume * -100, 1);
                }
                if (rge_base_game->sound_system != 0) {
                    rge_base_game->sound_system->set_volume(this->soundVolume * -100, 1);
                }
                rge_base_game->prog_info->mouse_scroll_interval = this->scrollSpeed;
                rge_base_game->prog_info->key_scroll_interval = this->scrollSpeed;
                if (this->modeValue == 0) {
                    if (rge_base_game->singlePlayerGame() == 1 && rge_base_game->save_paused == 0) {
                        rge_base_game->set_paused(0, 0);
                    }
                    panel_system.setCurrentPanel("Game Screen", 0);
                    this->set_active(0);
                    goto destroy;
                }
            }
    }
    panel_system.setCurrentPanel("Main Menu", 0);
    goto destroy;

base_action:
    return TPanel::action(panel, event, param_3, param_4);

slider_sound_call:
    slider_sound->set_volume(param_3 * -100, 1);
    return 1;

destroy:
    panel_system.destroyPanel("Config Dialog");
    return 1;
}
