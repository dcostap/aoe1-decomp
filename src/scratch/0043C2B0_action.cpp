// VA: 0043C2B0 TribeConfigDialog::action (1659B)
// PDB source: dlg_conf.cpp lines 377-647
// Attempt log:
// 1: natural reconstruction from the binary/decompiler, with the proven dialog layout,
//    typed member-call surfaces, and local absolute views for fixed globals.
// Earlier work restored the typed dialog layout and concrete button/slider
// comparisons. The clean checkpoint had 47/47 calls, but two ordered call gaps.
// Reversed mouse-state assignment to match the original constant-2/event stores.
// Ordered the >=99 music-disable arm before the enable arm; this aligns vf5C.
// Used direct play_tracks arms for music types 1 and 2; VC5 merges their tail.
// Reconstructed slider behavior: music changes also apply newSoundVolume, while
// sound changes apply param_3 through one shared sound-slider tail.
// Removed aliases and register qualifiers. A base-action label relocation aligned
// all calls but introduced EBX and a 37-byte overflow, so it was rolled back.
// Current clean source: frame 0x104, saved regs match, 47/47 calls, -1/+1 ordered
// call sites, code is 13B short, and strict diff is 1518B (91.5009%).
// Checker stage remains STRUCTURAL RECONSTRUCTION. The remaining lead is the
// entry parameter-home and early block layout mismatch, not register coloring.
// r2: explicit null-panel return/goto and a flattened dispatch worsened frame,
//     size, or saved-register parity; restored the clean wrapper.
// r2: returning event from speed buttons, nested speed gates, an ok predicate,
//     and direct duplicate slider calls produced no improvement or large drift.
// r3: replaced all seven fixed-address global macros with typed externs.  Exact
//     donors confirm C++ linkage for rge_base_game, comm, Regs, panel_system,
//     allow_user_commands, and do_color_log, plus C linkage for the path counter.
// r3: adding the same-TU game_globals.h include was a codegen duplicate.
// Left the clean typed reconstruction in place. The remaining evidence is the
// original event/p3 parameter homes and separate speed-return blocks.
// r4: restored param_3 for the interface-style write; this made the code size
//     exact and moved the diff one byte closer, but VC5 still delayed the home.
// r4: returned event from the three speed-button arms to mirror original mov
//     eax,edi return blocks; retained the typed-data surfaces unchanged.
// r4: restored the binary-documented register parameter qualifiers while
//     keeping direct param_3/event use; this tests parameter homes without an
//     alias or a typed-data address replacement.
// r5: completed 20 focused probes. The clean source remains the metric-best
//     natural form: exact size/frame/saved registers, 47 calls, 1493-byte diff.
// BINARY NOTE: the original null-panel edge targets base action at 0043C80D;
//     explicit guard forms fixed behavior but added EBX or large structural drift.
// BINARY NOTE: null music/sound slider objects target the shared destroy tail at
//     0043C91A, not a direct return; retain those fault and cleanup edges.
// Next: recover the original parameter homes and separate speed-return blocks
//     without retaining metric-only control-flow or register-steering forms.

#include "..\..\include\game_globals.h"
#include "..\..\include\rge_base_game_global.h"
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
    char gap_68[0x148];
    int prog_mode;
    char gap_1B4[0x240];
    RGE_Game_World* world;
    char gap_3F8[0x608];
    int save_paused;
    char gap_A04[0x1AC];

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

// These declarations follow the exact dlg_conf/basegame donor linkage.  The
// object build keeps each image-global relocation named, rather than embedding
// a local address view in this translation unit.
extern TCommunications_Handler* comm;
extern TRegistry* Regs;
extern TPanelSystem panel_system;
extern int allow_user_commands;
extern unsigned char do_color_log;
extern "C" int numberPathingIterations;

long TribeConfigDialog::action(TPanel* panel, register long event,
    register unsigned long param_3, unsigned long param_4)
{
    char msg[256];
    float new_speed;
    TSound_Driver* slider_sound;
    if (panel != 0) {
        if ((TButtonPanel*)panel == this->okButton && event == 1) {
            if (this->modeValue == 0) {
                if (rge_base_game->singlePlayerGame() == event && rge_base_game->save_paused == 0) {
                    rge_base_game->set_paused(0, 0);
                }

                if (this->mouseButton[0]->get_state() != 0) {
                    rge_base_game->prog_info->interface_style = 2;
                } else {
                    rge_base_game->prog_info->interface_style = param_3;
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
                    if (this->newMusicVolume >= 99) {
                        if (info->use_music != 0) {
                            info->use_music = 0;
                            rge_base_game->vf5C();
                        }
                    } else if (info->use_music == 0) {
                        info->use_music = 1;
                        Regs->RegSetInt(1, (const char*)0x5801D0, this->newMusicVolume * 100);
                        rge_base_game->vf58();
                        music = rge_base_game->music_system;
                        if (music != 0) {
                            if (music->music_type == 1) {
                                music->play_tracks(5, music->track_count, 1, 0, 0);
                            } else if (music->music_type == 2) {
                                music->play_tracks(1, music->track_count, 1, 0, 0);
                            }
                        }
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
                    goto destroy;
                }
                music->set_volume(param_3 * -100, 1);
                TSound_Driver* sound = rge_base_game->sound_system;
                if (sound == 0) {
                    goto destroy;
                }
                slider_sound = sound;
                param_3 = this->newSoundVolume;
                goto slider_sound_call;
            }
            if ((TVerticalSliderPanel*)panel == this->soundSlider && event == 4) {
                this->newSoundVolume = param_3;
                slider_sound = rge_base_game->sound_system;
                if (slider_sound == 0) {
                    goto destroy;
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
                    if (rge_base_game->singlePlayerGame() == event && rge_base_game->save_paused == 0) {
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
    return TPanel::action(panel, event, param_3, param_4);
}
