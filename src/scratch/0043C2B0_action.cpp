// VA: 0043C2B0 TribeConfigDialog::action (1659B)
// PDB source: dlg_conf.cpp lines 377-647
// Attempt log:
// 1: natural reconstruction from the binary/decompiler, with the proven dialog layout,
//    typed member-call surfaces, and local absolute views for fixed globals.
// 2-7: restored concrete button/slider comparisons, the third size-button arm, and
//    a single play_tracks/sound-slider call site; call set reached 47/47.
// 8: entry action/value locals improved the strict diff, but VC5 still homes param_3
//    in EDI instead of the original EBP; reversing the event comparison and register
//    qualifiers (9-10) made no further change.
// Best bounded state: frame 0x104 and saved regs match; call target counts are 47/47
// but ordered alignment is only 95.74% with -2/+2 site gaps. Meaningful code is 17B
// short, exact-block coverage is 48.15%, and strict diff is 1465B (88.3062%).
// Paused after 10 hypotheses. Checker stage remains STRUCTURAL RECONSTRUCTION: locate
// the unmatched ordered calls and size/CFG divergence before tuning entry liveness.
// EBP=param_3 / EDI=param_2 at the +000D prologue remains a secondary codegen clue.

#include <stdio.h>

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)

class TPanel {
public:
    VPAD4(0)
    virtual void vpad4();
    virtual void set_active(int);
    VPAD32(6)
    VPAD4(38)
    VPAD2(42)
    VPAD1(44)
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    char* get_string(int);
};

class TEasy_Panel : public TPanel {
public:
    char gap_04[0x478 - 4];
    void prepare_for_close();
};

class TDialogPanel : public TEasy_Panel {
public:
    char gap_478[0x490 - 0x478];
};

class TButtonPanel {
public:
    int get_state();
};

class TVerticalSliderPanel;

class TSound_Driver {
public:
    void set_volume(long, int);
};

class TMusic_System {
public:
    char gap_00[0x104];
    unsigned char music_type;
    char gap_105[3];
    char gap_108[0x140];
    int track_count;

    void set_volume(long, int);
    int play_tracks(int, int, int, int, unsigned long);
};

class TCommunications_Handler {
public:
    int WhoAmI();
    char* GetPlayerName(unsigned int);
    void SendChatMsgAll(const char*);
};

class TRegistry {
public:
    int RegSetInt(int, const char*, int);
};

class RGE_Prog_Info {
public:
    char gap_000[0x8A4];
    int use_music;
    char gap_8A8[0x20];
    unsigned long mouse_scroll_interval;
    char gap_8CC[4];
    unsigned long key_scroll_interval;
    char gap_8D4[8];
    short interface_style;
    char gap_8DE[0x12A];
    int rollover;
};

class TRIBE_Command {
public:
    void command_game_speed(float);
};

class RGE_Game_World {
public:
    char gap_00[0x58];
    TRIBE_Command* commands;
};

class RGE_Base_Game {
public:
    VPAD16(0)
    VPAD4(16)
    VPAD2(20)
    virtual void vf58();
    virtual void vf5C();
    VPAD32(24)
    VPAD16(56)
    VPAD8(72)
    virtual void vf140();

    char gap_04[8];
    RGE_Prog_Info* prog_info;
    char gap_10[0x50];
    TSound_Driver* sound_system;
    TMusic_System* music_system;
    char gap_68[0x38C];
    RGE_Game_World* world;
    char gap_3F8[0x608];
    int save_paused;
    char gap_A04[0x1AC];
    int prog_mode;

    int singlePlayerGame();
    int multiplayerGame();
    void set_paused(int, int);
    void setPathFinding(unsigned char);
    void set_game_speed(float);
    void set_screen_size(long, long);
};

class TPanelSystem {
public:
    int setCurrentPanel(char*, int);
    int destroyPanel(char*);
};

class TribeConfigDialog : public TDialogPanel {
public:
    int modeValue;
    TPanel* title;
    TPanel* speedTitle[4];
    TButtonPanel* speedButton[3];
    TPanel* musicTitle[3];
    TVerticalSliderPanel* musicSlider;
    TPanel* soundTitle[3];
    TVerticalSliderPanel* soundSlider;
    TPanel* scrollSpeedTitle[3];
    TVerticalSliderPanel* scrollSpeedSlider;
    TPanel* sizeTitle[4];
    TButtonPanel* sizeButton[3];
    TPanel* mouseTitle[3];
    TButtonPanel* mouseButton[2];
    TPanel* rolloverTitle[3];
    TButtonPanel* rolloverButton[2];
    TPanel* pathFindingTitle[4];
    TButtonPanel* pathFindingButton[3];
    TButtonPanel* okButton;
    TButtonPanel* cancelButton;
    long musicVolume;
    long soundVolume;
    float gameSpeed;
    long scrollSpeed;
    long newMusicVolume;
    long newSoundVolume;

    virtual long action(TPanel*, long, unsigned long, unsigned long);
};

#define rge_base_game (*(RGE_Base_Game**)0x62C574)
#define comm (*(TCommunications_Handler**)0x62C4C0)
#define Regs (*(TRegistry**)0x62C4A8)
#define panel_system (*(TPanelSystem*)0x62E870)
#define allow_user_commands (*(int*)0x58631C)
#define do_color_log (*(unsigned char*)0x62C584)
#define numberPathingIterations (*(int*)0x57F9F4)

long TribeConfigDialog::action(TPanel* panel, register long event,
    register unsigned long param_3, unsigned long param_4)
{
    char msg[256];
    float new_speed;
    TSound_Driver* slider_sound;
    int start_track;
    int end_track;
    long action_event = event;
    unsigned long action_value = param_3;

    if (panel != 0) {
        if ((TButtonPanel*)panel == this->okButton && action_event == 1) {
            if (this->modeValue == 0) {
                if (rge_base_game->singlePlayerGame() == action_event && rge_base_game->save_paused == 0) {
                    rge_base_game->set_paused(0, 0);
                }

                if (this->mouseButton[0]->get_state() == 0) {
                    rge_base_game->prog_info->interface_style = 1;
                } else {
                    rge_base_game->prog_info->interface_style = 2;
                }
                rge_base_game->vf140();

                if (this->rolloverButton[0]->get_state() == 0) {
                    rge_base_game->prog_info->rollover = 0;
                } else {
                    rge_base_game->prog_info->rollover = 1;
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
                        rge_base_game->world->commands->command_game_speed(new_speed);
                        if (rge_base_game->singlePlayerGame() != 0) {
                            rge_base_game->set_game_speed(new_speed);
                        }
                    }
                }

                if (this->newMusicVolume != this->musicVolume) {
                    RGE_Prog_Info* info = rge_base_game->prog_info;
                    TMusic_System* music;
                    if (this->newMusicVolume < 99) {
                        if (info->use_music == 0) {
                            info->use_music = 1;
                            Regs->RegSetInt(1, (const char*)0x5801D0, this->newMusicVolume * 100);
                            rge_base_game->vf58();
                            music = rge_base_game->music_system;
                            if (music != 0) {
                                start_track = 0;
                                if (music->music_type == 1) {
                                    end_track = music->track_count;
                                    start_track = 5;
                                } else if (music->music_type == 2) {
                                    end_track = music->track_count;
                                    start_track = 1;
                                }
                                if (start_track != 0) {
                                    music->play_tracks(start_track, end_track, 1, 0, 0);
                                }
                            }
                        }
                    } else if (info->use_music != 0) {
                        info->use_music = 0;
                        rge_base_game->vf5C();
                    }

                    if (rge_base_game->sound_system != 0) {
                        rge_base_game->sound_system->set_volume(this->newSoundVolume * -100, 1);
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

                panel_system.setCurrentPanel((char*)0x5842CC, 0);
                this->set_active(0);
                this->prepare_for_close();
                if (do_color_log == 0) {
                    rge_base_game->set_screen_size(width, height);
                }
                goto destroy;
            }
        } else {
            if ((TButtonPanel*)panel == this->speedButton[0] && action_event == 1) {
                return 1;
            }
            if ((TButtonPanel*)panel == this->speedButton[1] && action_event == 1) {
                return 1;
            }
            if ((TButtonPanel*)panel == this->speedButton[2] && action_event == 1) {
                return 1;
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
            if ((TVerticalSliderPanel*)panel == this->musicSlider && action_event == 4) {
                this->newMusicVolume = action_value;
                TMusic_System* music = rge_base_game->music_system;
                if (music == 0) {
                    return 1;
                }
                music->set_volume(action_value * -100, 1);
                TSound_Driver* sound = rge_base_game->sound_system;
                if (sound == 0) {
                    return 1;
                }
                slider_sound = sound;
                action_value = this->newSoundVolume;
                goto slider_sound_call;
            }
            if ((TVerticalSliderPanel*)panel == this->soundSlider && action_event == 4) {
                this->newSoundVolume = action_value;
                slider_sound = rge_base_game->sound_system;
                if (slider_sound == 0) {
                    return 1;
                }
                goto slider_sound_call;
            }
            if ((TVerticalSliderPanel*)panel == this->scrollSpeedSlider && action_event == 4) {
                rge_base_game->prog_info->mouse_scroll_interval = action_value + 10;
                rge_base_game->prog_info->key_scroll_interval = action_value + 10;
                goto base_action;
            }
            if ((TButtonPanel*)panel == this->cancelButton && action_event == 1) {
                if (rge_base_game->music_system != 0) {
                    rge_base_game->music_system->set_volume(this->musicVolume * -100, 1);
                }
                if (rge_base_game->sound_system != 0) {
                    rge_base_game->sound_system->set_volume(this->soundVolume * -100, 1);
                }
                rge_base_game->prog_info->mouse_scroll_interval = this->scrollSpeed;
                rge_base_game->prog_info->key_scroll_interval = this->scrollSpeed;
                if (this->modeValue == 0) {
                    if (rge_base_game->singlePlayerGame() == action_event && rge_base_game->save_paused == 0) {
                        rge_base_game->set_paused(0, 0);
                    }
                    panel_system.setCurrentPanel((char*)0x5842CC, 0);
                    this->set_active(0);
                    goto destroy;
                }
            }
        }
        panel_system.setCurrentPanel((char*)0x5842E8, 0);
        goto destroy;
    }

slider_sound_call:
    slider_sound->set_volume(param_3 * -100, 1);
    return 1;

destroy:
    panel_system.destroyPanel((char*)0x5842D8);
    return 1;

base_action:
    return TPanel::action(panel, action_event, action_value, param_4);
}
