// PDB source module: C:\msdev\work\age1_x1\scr_mps.cpp.
// Definitions follow the original PDB source order.

#include "../include/scr_mps.h"
#include "../include/scr_set_screen.h"
#include "../include/scr_main.h"
#include "../include/scr_sing.h"
#include "../include/scr_sels.h"
#include "../include/scr_cj.h"
#include "../include/main.h"
#include "../include/pnl_dlg.h"
#include "../include/panel_ez.h"
#include "../include/panel.h"
#include "../include/basegame.h"
#include "../include/tribegam.h"
#include "../include/drawarea.h"
#include "../include/Shape.h"
#include "../include/Picture.h"
#include "../include/pnl_btn.h"
#include "../include/pnl_lst.h"
#include "../include/Pnl_txt.h"
#include "../include/Pnl_scbr.h"
#include "../include/pnl_drop.h"
#include "../include/pnl_edit.h"
#include "../include/chat.h"
#include "../include/debuglog.h"
#include "../include/com_hand.h"
#include "../include/com_addr.h"
#include "../include/scenario.h"
#include "../include/tscenaro.h"
#include "../include/player.h"
#include "../include/world.h"
#include "../include/rge_base_game_global.h"
#include <io.h>

class TribeSelectScenarioScreen;
class TribeJoinScreen;

extern TChat* chat;
extern TDebuggingLog* L;
extern TCommunications_Handler* comm;
extern char s_Multiplayer_Disconnect_Screen[];
extern char s_scr3[];
extern char s_Status_Screen[];
extern const char s_C__msdev_work_age1_x1_scr_mps_cp[];

extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" char* __cdecl strcat(char*, const char*);
extern "C" char* __cdecl strcpy(char*, const char*);
extern "C" unsigned long __cdecl debug_timeGetTime(const char*, int);
extern "C" void __cdecl debug_srand(char*, int, unsigned long);
extern "C" int __cdecl debug_rand(char*, int);
extern "C" void __cdecl Log(TDebuggingLog*, const char*, ...);

// PDB-order owner source: 004A00B0_TribeMPSetupScreen.cpp.

// VA: 004A00B0 TribeMPSetupScreen::TribeMPSetupScreen
// PDB donor: scr_mps.cpp:203-437
// Baseline reconstruction: period-plausible screen construction with the
// proven TScreenPanel/TEasy_Panel hierarchy, named panel arrays, and natural
// creation/setup call order.  The response file supplies /GX for the original
// constructor EH frame.
//
// Attempt log:
// - baseline: canonical panel ownership from the destructor and generated class
//   layout; direct TEasy_Panel helper calls, TPanel/TTextPanel virtual surfaces,
//   and natural single/multiplayer setup branches.
// - context: hoisted the proven draw_area member before nested setup-id
//   evaluation; VC5 then reproduced the original setup argument push order.
// - liveness: removing the synthetic row-index and scenario-pointer homes did
//   not change code until the row was expressed as a contiguous cursor.
// - layout: the named row arrays proved contiguous around playerCivDrop; using
//   those neighboring row offsets restored the 0x10C frame and removed 120
//   emitted bytes while substantially improving block coverage.
// - control-flow: a guarded for loop for the eight player rows removed VC5's
//   peeled duplicate dropdown site and aligned the static row call topology.
// - behavior: spelling the title resource as a conditional -1/0 offset matched
//   the original neg/sbb/add lowering and moved the first useful frontier deeper.
// - final control-flow (prior session): the settings rows use one guarded loop
//   site; the old remaining drift was a missing create_button site and late
//   branch gaps.
// - control-flow: reversed the host/nonhost dispatch arms.  The host arm now
//   follows IsHost in source order, with the nonhost arm as the fallback.  This
//   restored all 127 ordered calls, exact function size, and the original host
//   and nonhost block placement; the row setup still differs locally.
// - source recovery: removed an unused multiplayer declaration; emitted output
//   stayed unchanged, and the natural source no longer carries dead machinery.
// - unresolved pass: twenty source hypotheses were compiled and checked.  The
//   clean baseline remains 3240 bytes, 0x10C frame, and 127 ordered calls.
// - BINARY NOTE: the shipped row setup stores y at entry-relative [esp+10],
//   then loads playerCivDrop and carries the row cursor through the calls.
//   The clean source still emits a three-instruction local-order drift there.
// - BINARY NOTE: the final row virtual call dereferences the player-CD output
//   slot before calling vslot +0x14.  Direct typed and base-pointer forms add
//   nine bytes, so the clean baseline remains pinned until a better source
//   model explains that register reuse.
// - LIKELY INTENT: the row cursor is one contiguous panel family centered on
//   playerCivDrop.  This explains the proven negative pointer offsets, but it
//   does not prove the original local declarations.
// - indexed-row recovery: direct indexed member arrays with one for-loop body,
//   a separate next_button_id, and the stack buffer base reduced the checked
//   difference from 2452 to 1478 bytes.  The frame, size, and 127 ordered calls
//   remain exact in this source model.
// - BINARY NOTE: the indexed source now reproduces the row setup through the
//   team-text block at +0x5A4, and reproduces the final CD-text virtual block.
//   The first remaining row mismatch is the y+2 register/arithmetic lowering.
// - BINARY NOTE: the shipped coordinates are y, y+2, and y+3.  The current
//   source uses text_y = y + 2 and text_y + 1 for the last two panels.
// - unresolved pass: direct indexed arrays are a strong shape lead, but the
//   remaining add ebx,2 versus lea ebx,[ebp+2] basin is not exact.
// - Authentic scr_mps.cpp context used the canonical screen layout and /GX.
//   PDB-ordered compilation kept 3240 bytes, 127 calls, and the 1478-byte diff.


TribeMPSetupScreen::TribeMPSetupScreen()
    : TScreenPanel("MP Setup Screen")
{
    int row;
    char str[256];
    int y;
    int button_id;

    Log(L, "$$$ CHAT SCREEN: CONSTRUCTOR BEGIN");
    init_vars();
    chat->ClearChat();
    for (int i = 1; i < 9; i++) {
        chat->setInChatGroup(i, 1);
    }

    char* setup_file;
    if (rge_base_game->multiplayerGame()) {
        setup_file = (char*)"scr3";
    } else {
        setup_file = (char*)"scr2";
    }

    TDrawArea* draw_area = rge_base_game->draw_area;
    if (this->TEasy_Panel::setup(
            draw_area, 0, setup_file,
            (rge_base_game->multiplayerGame() != 0) + 0xC384,
            1, 0, 0, 0, 0, 1) == 0) {
        this->error_code = 1;
        return;
    }

    this->setup_shadow_area(0);
    this->set_ideal_size(0x280, 0x1E0);

    if (this->create_text(this, &this->title,
                          0x25CF + (rge_base_game->multiplayerGame() ? -1 : 0),
                          0x14, 6, 600, 0x1E, 1, 1, 0, 0) == 0) {
        return;
    }
    if (this->create_text(this, &this->playerTitle, 0x25D0,
                          0x1A, 0x32, 0xA0, 0x1E, 0, 0, 1, 0) == 0) {
        return;
    }
    if (this->create_text(this, &this->civTitle, 0x25D1,
                          0xBD, 0x32, 0xA0, 0x1E, 0, 0, 1, 0) == 0) {
        return;
    }

    if (!rge_base_game->singlePlayerGame() && !comm->IsHost()) {
        if (this->create_text(this, &this->settingsTitle, 0x25D2,
                              0x1A4, 0x32, 0xD2, 0x1E, 0, 0, 1, 0) == 0) {
            return;
        }
    }

    if (this->create_text(this, &this->colorTitle, 0x25AE,
                          0xF0, 0x32, 100, 0x1E, 0, 0, 1, 0) == 0) {
        return;
    }
    this->colorTitle->set_alignment((TTextPanel::Alignment)0,
                                    (TTextPanel::Alignment)2);
    if (this->create_text(this, &this->teamTitle, 0x25AF,
                          0x136, 0x32, 100, 0x1E, 0, 0, 1, 0) == 0) {
        return;
    }
    this->teamTitle->set_alignment((TTextPanel::Alignment)0,
                                   (TTextPanel::Alignment)2);

    y = 0x55;
    row = 0;
    for (; y < 0x115; ++row, y += 0x18) {
        if (this->create_drop_down(this, &this->playerNameDrop[row],
                                   0x9E, 100, 7, y - 1,
                                   0x9E, 0x18, 0x0B) == 0) {
            return;
        }
        this->playerNameDrop[row]->set_draw_style(
            (TDropDownPanel::DrawStyle)1);
        this->playerNameDrop[row]->set_draw_val_rect(0);
        this->playerNameDrop[row]->set_help_info(0x75F9, -1);
        this->playerNameDrop[row]->empty_list();
        if (rge_base_game->multiplayerGame()) {
            this->playerNameDrop[row]->append_line(0x25D3, 4);
            this->playerNameDrop[row]->append_line(0x25D4, 1);
            this->playerNameDrop[row]->append_line(0x25D5, 0);
        } else {
            this->playerNameDrop[row]->append_line(0x25D3, 4);
            this->playerNameDrop[row]->append_line(0x25D6, 0);
        }

        if (this->create_drop_down(this, &this->playerCivDrop[row],
                                   0x80, 100, 0xAA, y - 1,
                                   0x80, 0x18, 0x0B) == 0) {
            return;
        }
        this->playerCivDrop[row]->set_draw_style(
            (TDropDownPanel::DrawStyle)1);
        this->playerCivDrop[row]->set_draw_val_rect(0);
        this->playerCivDrop[row]->set_help_info(0x75FA, 0x25F09);
        this->playerCivDrop[row]->empty_list();
        this->playerCivDrop[row]->append_line(0x27F7, 1);
        this->playerCivDrop[row]->append_line(0x27F8, 2);
        this->playerCivDrop[row]->append_line(0x27F9, 3);
        this->playerCivDrop[row]->append_line(0x27FA, 4);
        this->playerCivDrop[row]->append_line(0x27FB, 5);
        this->playerCivDrop[row]->append_line(0x27FC, 6);
        this->playerCivDrop[row]->append_line(0x27FD, 7);
        this->playerCivDrop[row]->append_line(0x27FE, 8);
        this->playerCivDrop[row]->append_line(0x27FF, 9);
        this->playerCivDrop[row]->append_line(0x2800, 10);
        this->playerCivDrop[row]->append_line(0x2801, 0x0B);
        this->playerCivDrop[row]->append_line(0x2802, 0x0C);
        this->playerCivDrop[row]->append_line(0x2806, 0x0D);
        this->playerCivDrop[row]->append_line(0x2807, 0x0E);
        this->playerCivDrop[row]->append_line(0x2809, 0x0F);
        this->playerCivDrop[row]->append_line(0x2808, 0x10);
        this->playerCivDrop[row]->append_line(0x280A, 0x11);

        if (this->create_drop_down(this, &this->scenarioPlayerDrop[row],
                                   0x28, 100, 0x144, y - 1,
                                   0x28, 0x18, 0x0B) == 0) {
            return;
        }
        this->scenarioPlayerDrop[row]->set_draw_style(
            (TDropDownPanel::DrawStyle)1);
        this->scenarioPlayerDrop[row]->set_draw_val_rect(0);
        this->scenarioPlayerDrop[row]->set_help_info(0x75FB, -1);

        if (this->create_button(this, &this->playerColor[row], "", 0,
                                0x136, y, 0x1E, 0x14, 0x0B, 0, 1) == 0) {
            return;
        }
        this->playerColor[row]->set_help_info(0x7604, -1);

        if (this->create_text(this, &this->playerColorText[row], "",
                              0x131, y, 0x28, 0x16, 0x0B, 1, 1, 0) == 0) {
            return;
        }

        TButtonPanel** team = &this->playerTeam[row];
        if (this->create_button(this, team, 0x25B0,
                                0, 0x17C, y, 0x1E, 0x14, 0x0B, 0, 1) == 0) {
            return;
        }
        (*team)->set_help_info(0x7603, -1);
        (*team)->set_state_info(5);

        button_id = 1;
        do {
            sprintf(str, "%d", button_id);
            (*team)->set_text((short)button_id, str);
            int next_button_id = button_id + 1;
            (*team)->set_id((short)button_id, next_button_id, 0);
            button_id = next_button_id;
        } while (button_id < 5);

        int text_y = y + 2;
        if (this->create_text(this, &this->playerTeamText[row], "",
                              0x177, y, 0x28, 0x16, 0x0B, 1, 1, 0) == 0) {
            return;
        }
        if (this->create_text(this, &this->playerNameText[row], "",
                              0x1C, text_y, 0x8B, 0x16, 0x0B, 0, 0, 0) == 0) {
            return;
        }
        if (this->create_text(this, &this->playerCivText[row], "",
                              0xBF, text_y, 0x6D, 0x16, 0x0B, 0, 0, 0) == 0) {
            return;
        }
        if (this->create_text(this, &this->scenarioPlayerText[row], "",
                              0x159, text_y, 0x28, 0x16, 0x0B, 0, 0, 0) == 0) {
            return;
        }
        TTextPanel** player_cd = &this->playerCDText[row];
        if (this->create_text(this, player_cd, 0x25DF,
                              0x151, text_y + 1, 0x14, 0x16, 6, 0, 0, 0) == 0) {
            return;
        }
        if (this->create_text(this, &this->playerVersionText[row], "",
                              0x161, text_y + 1, 0x1D, 0x16, 6, 0, 0, 0) == 0) {
            return;
        }

        (*player_cd)->set_active(0);
    }

    if (rge_base_game->singlePlayerGame() || comm->IsHost()) {
        if (this->create_button(this, &this->gameSettingsButton, 0x25D2,
                                0, 0x1A4, 0x32, 0xD2, 0x1E, 0, 0, 0) == 0) {
            return;
        }
        this->gameSettingsButton->set_help_info(0x75FC, -1);
    }

    if (this->create_text(this, &this->scenarioName, "",
                          0x1A4, 0x54, 0xDC, 0x44, 0x0B, 0, 0, 1) == 0) {
        return;
    }

    y = 0x53;
    TTextPanel** setting = this->settingText;
    for (; y < 0x233; ++setting, y += 0x18) {
        if (this->create_text(this, setting, "",
                              0x1A4, y, 0xDC, 0x14, 0x0B, 0, 0, 0) == 0) {
            return;
        }
    }

    if (rge_base_game->multiplayerGame()) {
        if (this->create_text(this, &this->chatTitle, 0x25D7,
                              10, 0x118, 100, 0x14, 4, 0, 1, 0) == 0) {
            return;
        }
        if (this->create_text(this, &this->chatBox, "",
                              10, 300, 400, 0x60, 10, 0, 0, 0) == 0) {
            return;
        }
        if (this->create_auto_scrollbar(&this->chatScrollbar,
                                        this->chatBox, 0x14) == 0) {
            return;
        }
        if (this->create_edit(this, &this->chatInput, "", 0xF7,
                              (TEditPanel::FormatType)0,
                              10, 0x192, 400, 0x17, 10, 1, 0) == 0) {
            return;
        }
        this->chatInput->set_help_info(0x75FE, -1);
        this->chatBox->set_bevel_info(3,
                                      this->bevel_color1,
                                      this->bevel_color2,
                                      this->bevel_color3,
                                      this->bevel_color4,
                                      this->bevel_color5,
                                      this->bevel_color6);
        this->chatBox->set_help_info(0x75FD, -1);
        this->chatBox->empty_list();
    }

    if (rge_base_game->singlePlayerGame()) {
        if (this->create_text(this, &this->numberPlayersTitle, 0x25D8,
                              0x1A, 0x127, 0x14F, 0x14, 0, 0, 1, 0) == 0) {
            return;
        }
        if (this->create_drop_down(this, &this->numberPlayersDrop,
                                   0x46, 100, 0x1F, 0x142,
                                   0x46, 0x18, 0x0B) == 0) {
            return;
        }
        this->numberPlayersDrop->set_help_info(0x7600, -1);
    }

    this->i_am_ready = 0;

    if (rge_base_game->singlePlayerGame()) {
        if (this->create_button(this, &this->startButton, "", 0,
                                0x46, 0x1B8, 0xF0, 0x1E, 0, 0, 0) == 0) {
            return;
        }
        this->startButton->set_text(0, 0x25EE);
        this->startButton->set_help_info(0x75FF, -1);
        this->set_curr_child(this->startButton);
        if (this->create_button(this, &this->cancelButton, 0xFA2,
                                0, 0x14A, 0x1B8, 0xF0, 0x1E, 0, 0, 0) == 0) {
            return;
        }
        this->cancelButton->set_help_info(0x7532, -1);
    } else if (comm->IsHost()) {
        if (this->create_check_box(this, &this->ready_button,
                                   10, 0x1B8, 0x1E, 0x1E, 0, 0) == 0) {
            return;
        }
        if (this->create_text(this, &this->ready_button_label, 0x25BF,
                              0x2D, 0x1B8, 0x96, 0x1E, 0, 0, 1, 0) == 0) {
            return;
        }
        this->ready_button->set_help_info(0x7602, -1);
        if (this->create_button(this, &this->startButton, "", 0,
                                0xC3, 0x1B8, 200, 0x1E, 0, 0, 0) == 0) {
            return;
        }
        this->startButton->set_text(0, 0x25EE);
        this->startButton->set_help_info(0x75FF, -1);
        this->startButton->set_disabled(1);
        if (this->create_button(this, &this->cancelButton, 0xFA2,
                                0, 0x195, 0x1B8, 0xB4, 0x1E, 0, 0, 0) == 0) {
            return;
        }
        this->cancelButton->set_help_info(0x7532, -1);
        if (this->create_button(this, &this->netInfoButton, 0x25EF,
                                0, 600, 400, 0x1E, 0x1E, 0, 0, 0) == 0) {
            return;
        }
        this->netInfoButton->set_help_info(0x7601, -1);
        comm->SetMyReadiness(0, 0, 0, 0, 0, 0, 0, 0);
    } else {
        if (this->create_check_box(this, &this->ready_button,
                                   100, 0x1B8, 0x1E, 0x1E, 0, 0) == 0) {
            return;
        }
        if (this->create_text(this, &this->ready_button_label, 0x25BF,
                              0x87, 0x1B8, 0x96, 0x1E, 0, 0, 1, 0) == 0) {
            return;
        }
        this->ready_button->set_help_info(0x7602, -1);
        if (this->create_button(this, &this->cancelButton, 0xFA2,
                                0, 0x14A, 0x1B8, 0xF0, 0x1E, 0, 0, 0) == 0) {
            return;
        }
        this->cancelButton->set_help_info(0x7532, -1);
    }

    if (this->create_button(this, &this->help_button, 0xFA9,
                            0, 600, 0x1B8, 0x1E, 0x1E, 0, 0, 0) == 0) {
        return;
    }
    if (this->create_button(this, &this->close_button, 0x3EA,
                            0, 0, 0, 0, 0, -1, -1, 0) == 0) {
        return;
    }
    this->close_button->set_active(1);
    this->close_button->set_positioning((TPanel::PositionMode)9, 4, 4, 4, 4,
                                        0x11, 0x11, 0x11, 0x11,
                                        0, 0, 0, 0);
    this->cancelButton->hotkey = 0x1B;
    this->cancelButton->hotkey_shift = 0;
    this->setupTabOrder();
    Log(L, "$$$ CHAT SCREEN: UPDATE SUMMARY");
    this->updateSummary();
    if (rge_base_game->singlePlayerGame()) {
        this->setupSinglePlayerPlayers();
        this->fillPlayers();
    }
    Log(L, "$$$ CHAT SCREEN: CONSTRUCTOR DONE");
}

// PDB-order owner source: 004A0D80_init_vars.cpp.

// VA: 004A0D80 TribeMPSetupScreen::init_vars
// PDB donor: scr_mps.cpp:443-663
//
// Canonical typed reconstruction of the screen's pointer/member initialization
// and the single-player/multiplayer game-default setup paths.
// Attempt log:
// - typed parallel member-array loops replaced raw offset/cursor scaffolding;
//   the proven screen base gap places the first fields at +0x478.
// - corrected +0x728 ownership, saveScenarioName[0], and adjacent default
//   assignment order; the fixed zero loop reproduces the +0x868 rep-stosd.
// - int,int setPlayerColor reproduces the caller's explicit zero extension.
// - kept the random remainder separate from its mapped result for the exact
//   VC5 branch shape; only map-size/type setup is scenario-game guarded.
// - exact: 1403/1403 bytes, 62/62 calls, all relocations and CFG signals.


void TribeMPSetupScreen::init_vars() {
    int i;

    this->title = 0;
    this->playerTitle = 0;
    this->civTitle = 0;
    this->settingsTitle = 0;
    this->colorTitle = 0;
    this->teamTitle = 0;

    for (i = 0; i < 8; ++i) {
        this->playerNameDrop[i] = 0;
        this->playerCivDrop[i] = 0;
        this->scenarioPlayerDrop[i] = 0;
        this->playerColor[i] = 0;
        this->playerTeam[i] = 0;
        this->playerNameText[i] = 0;
        this->playerCivText[i] = 0;
        this->scenarioPlayerText[i] = 0;
        this->playerCDText[i] = 0;
        this->playerVersionText[i] = 0;
        this->playerColorText[i] = 0;
        this->playerTeamText[i] = 0;
    }

    this->chatInput = 0;
    this->chatTitle = 0;
    this->chatScrollbar = 0;
    this->chatBox = 0;
    this->gameSettingsButton = 0;
    this->scenarioName = 0;
    this->victoryFixedText = 0;

    for (i = 0; i < 20; ++i) {
        this->settingText[i] = 0;
        this->settingValue[i] = 0;
    }

    this->mapSizeLabel = 0;
    this->mapSizeDrop = 0;
    this->mapTypeLabel = 0;
    this->mapTypeDrop = 0;
    this->numberPlayersTitle = 0;
    this->numberPlayersDrop = 0;
    this->numberPlayersText = 0;
    this->hiddenMapButton = 0;
    this->hiddenMapText = 0;
    this->victoryTypeLabel = 0;
    this->victoryTypeDrop = 0;
    this->victoryAmountLabel = 0;
    this->victoryAmountInput = 0;
    this->ready_button_label = 0;
    this->startButton = 0;
    this->readyButtons[0] = 0;
    this->readyButtons[1] = 0;
    this->cancelButton = 0;
    this->help_button = 0;
    this->ready_button = 0;
    this->close_button = 0;
    this->cancelMode = 0;
    this->playerToKick = 0;
    this->myCivilization = 0;
    this->myScenarioPlayer = -1;
    this->myPlayerColor = 0;
    this->myPlayerTeam = 0;
    this->myScenarioChecksum = 0;
    this->saveScenarioName[0] = 0;
    this->saveRandomGame = rge_base_game->randomGame();
    long* zero_block = this->scenarioCheckSum;
    this->saveScenarioChecksum = 0;
    this->scenarioInfo = 0;
    this->numberAnyPlayers = 8;
    this->scenarioPlayerCount = 8;
    this->settingsFixed = 0;
    this->sent_cd_status = 0;
    this->netInfoButton = 0;
    this->i_am_ready = 0;
    for (i = 0; i < 8; ++i) {
        zero_block[i] = 0;
    }
    this->last_send_shared = 0;
    this->resend_game_options = 0;

    if (rge_base_game->multiplayerGame() != 0) {
        rge_base_game->setCampaignGame(0);
        rge_base_game->setSavedGame(0);
        rge_base_game->setScenarioGame(0);
        rge_base_game->setScenarioName("");
        ((TRIBE_Game*)rge_base_game)->setMapSize((TRIBE_Game::MapSize)3);
        ((TRIBE_Game*)rge_base_game)->setMapType((TRIBE_Game::MapType)3);
        ((TRIBE_Game*)rge_base_game)->setVictoryType(
            (TRIBE_Game::VictoryType)0, 0);
        ((TRIBE_Game*)rge_base_game)->setAnimals(1);
        ((TRIBE_Game*)rge_base_game)->setPredators(1);
        rge_base_game->setNumberPlayers(8);
        rge_base_game->setFullVisibility(0);
        rge_base_game->setFogOfWar(1);
        rge_base_game->setAllowCheatCodes(0);
        ((TRIBE_Game*)rge_base_game)->setRandomizePositions(0);
        ((TRIBE_Game*)rge_base_game)->setLongCombat(0);
        ((TRIBE_Game*)rge_base_game)->setAllowTrading(1);
        ((TRIBE_Game*)rge_base_game)->setFullTechTree(0);
        ((TRIBE_Game*)rge_base_game)->setResourceLevel(
            (TRIBE_Game::ResourceLevel)0);
        ((TRIBE_Game*)rge_base_game)->setStartingAge((TRIBE_Game::Age)0);
        ((TRIBE_Game*)rge_base_game)->setStartingUnits(0);
        rge_base_game->setDifficulty(
            rge_base_game->get_single_player_difficulty());
        ((TRIBE_Game*)rge_base_game)->setDeathMatch(0);
        ((TRIBE_Game*)rge_base_game)->setQuickStartGame(0);
        unsigned long now = debug_timeGetTime(
            "C:\\msdev\\work\\age1_x1\\scr_mps.cpp", 0x243);
        debug_srand("C:\\msdev\\work\\age1_x1\\scr_mps.cpp", 0x243, now);

        for (i = 0; i < 8; ++i) {
            this->defaultColor[i] = (unsigned char)(i + 1);
            ((TRIBE_Game*)rge_base_game)->setCivilization(
                i,
                debug_rand("C:\\msdev\\work\\age1_x1\\scr_mps.cpp", 0x248) %
                        16 +
                    1);
            ((TRIBE_Game*)rge_base_game)->setScenarioPlayer(i, i);
            ((TRIBE_Game*)rge_base_game)->setPlayerHasCD(i, 0);
            ((TRIBE_Game*)rge_base_game)->setPlayerVersion(i, 0);
            ((TRIBE_Game*)rge_base_game)->setPlayerColor(
                i, this->defaultColor[i]);
            ((TRIBE_Game*)rge_base_game)->setPlayerTeam(i, 1);
            ((TRIBE_Game*)rge_base_game)->setComputerName(i, 0);
        }

        if (((TCommunications_Handler*)comm)->IsHost() != 0) {
            ((TRIBE_Game*)rge_base_game)->setPlayerVersion(0, 1);
            rge_base_game->send_game_options();
            this->resend_game_options = 0;
            return;
        }
    } else {
        if (rge_base_game->scenarioGame() == 0) {
            ((TRIBE_Game*)rge_base_game)->setMapSize((TRIBE_Game::MapSize)3);
            int random_map = debug_rand(
                                  "C:\\msdev\\work\\age1_x1\\scr_mps.cpp", 0x26A) %
                              10;
            int map_type;
            if (random_map < 2) {
                map_type = 4;
            } else if (random_map == 2) {
                map_type = 3;
            } else if (random_map == 3) {
                map_type = 2;
            } else if (random_map == 4) {
                map_type = 1;
            } else if (random_map == 5) {
                map_type = random_map;
            } else if (random_map == 6) {
                map_type = random_map;
            } else if (random_map == 7) {
                map_type = random_map;
            } else {
                map_type = (random_map == 8) ? 8 : 0;
            }
            ((TRIBE_Game*)rge_base_game)->setMapType(
                (TRIBE_Game::MapType)map_type);
        }
        ((TRIBE_Game*)rge_base_game)->setVictoryType(
            (TRIBE_Game::VictoryType)0, 0);
        rge_base_game->setNumberPlayers(4);
        rge_base_game->setCampaignGame(0);
        rge_base_game->setSavedGame(0);
        ((TRIBE_Game*)rge_base_game)->setAnimals(1);
        ((TRIBE_Game*)rge_base_game)->setPredators(1);
        rge_base_game->setFullVisibility(0);
        rge_base_game->setFogOfWar(1);
        rge_base_game->setAllowCheatCodes(1);
        ((TRIBE_Game*)rge_base_game)->setRandomizePositions(0);
        ((TRIBE_Game*)rge_base_game)->setLongCombat(0);
        ((TRIBE_Game*)rge_base_game)->setAllowTrading(1);
        ((TRIBE_Game*)rge_base_game)->setFullTechTree(0);
        ((TRIBE_Game*)rge_base_game)->setResourceLevel(
            (TRIBE_Game::ResourceLevel)0);
        ((TRIBE_Game*)rge_base_game)->setStartingAge((TRIBE_Game::Age)0);
        ((TRIBE_Game*)rge_base_game)->setStartingUnits(0);
        rge_base_game->setDifficulty(
            rge_base_game->get_single_player_difficulty());
        ((TRIBE_Game*)rge_base_game)->setQuickStartGame(0);
    }
}

// PDB-order owner source: 004A1300_TribeMPSetupScreen.cpp.

// VA: 004A1300 TribeMPSetupScreen::~TribeMPSetupScreen
// scr_mps.cpp lines 669-753
// Attempt log:
// initial natural destructor surface: delete scenarioInfo, destroy five named panels,
// delete panel pointer fields in binary-observed order; uses /GX for EH-framed dtor.


TribeMPSetupScreen::~TribeMPSetupScreen()
{
    if (this->scenarioInfo != 0) {
        delete this->scenarioInfo;
        this->scenarioInfo = 0;
    }

    panel_system.destroyPanel("Game Settings Screen");
    panel_system.destroyPanel("Select Tribe Screen");
    panel_system.destroyPanel("Kick Dialog");
    panel_system.destroyPanel("OKDialog");
    panel_system.destroyPanel("YesNoDialog");

    this->delete_panel((TPanel**)&this->title);
    this->delete_panel((TPanel**)&this->playerTitle);
    this->delete_panel((TPanel**)&this->civTitle);
    this->delete_panel((TPanel**)&this->settingsTitle);
    this->delete_panel((TPanel**)&this->colorTitle);
    this->delete_panel((TPanel**)&this->teamTitle);

    for (int i = 0; i < 8; i++) {
        this->delete_panel((TPanel**)&this->playerNameDrop[i]);
        this->delete_panel((TPanel**)&this->playerCivDrop[i]);
        this->delete_panel((TPanel**)&this->scenarioPlayerDrop[i]);
        this->delete_panel((TPanel**)&this->playerColor[i]);
        this->delete_panel((TPanel**)&this->playerTeam[i]);
        this->delete_panel((TPanel**)&this->playerNameText[i]);
        this->delete_panel((TPanel**)&this->playerCivText[i]);
        this->delete_panel((TPanel**)&this->scenarioPlayerText[i]);
        this->delete_panel((TPanel**)&this->playerCDText[i]);
        this->delete_panel((TPanel**)&this->playerVersionText[i]);
        this->delete_panel((TPanel**)&this->playerColorText[i]);
        this->delete_panel((TPanel**)&this->playerTeamText[i]);
    }

    this->delete_panel((TPanel**)&this->chatInput);
    this->delete_panel((TPanel**)&this->chatTitle);
    this->delete_panel((TPanel**)&this->chatBox);
    this->delete_panel((TPanel**)&this->gameSettingsButton);
    this->delete_panel((TPanel**)&this->scenarioName);
    this->delete_panel((TPanel**)&this->victoryFixedText);

    for (int j = 0; j < 20; j++) {
        this->delete_panel((TPanel**)&this->settingText[j]);
        this->delete_panel((TPanel**)&this->settingValue[j]);
    }

    this->delete_panel((TPanel**)&this->mapSizeLabel);
    this->delete_panel((TPanel**)&this->mapSizeDrop);
    this->delete_panel((TPanel**)&this->mapTypeLabel);
    this->delete_panel((TPanel**)&this->mapTypeDrop);
    this->delete_panel((TPanel**)&this->numberPlayersTitle);
    this->delete_panel((TPanel**)&this->numberPlayersDrop);
    this->delete_panel((TPanel**)&this->numberPlayersText);
    this->delete_panel((TPanel**)&this->hiddenMapButton);
    this->delete_panel((TPanel**)&this->hiddenMapText);
    this->delete_panel((TPanel**)&this->victoryTypeLabel);
    this->delete_panel((TPanel**)&this->victoryTypeDrop);
    this->delete_panel((TPanel**)&this->victoryAmountLabel);
    this->delete_panel((TPanel**)&this->victoryAmountInput);
    this->delete_panel((TPanel**)&this->startButton);
    this->delete_panel((TPanel**)&this->cancelButton);
    this->delete_panel((TPanel**)&this->close_button);
    this->delete_panel((TPanel**)&this->ready_button);
    this->delete_panel((TPanel**)&this->ready_button_label);
    this->delete_panel((TPanel**)&this->netInfoButton);
    this->delete_panel((TPanel**)&this->help_button);
}

// PDB-order owner source: 004A1640_handle_idle.cpp.

// 004A1640 TribeMPSetupScreen::handle_idle
// Working pass: use real member-call surfaces and real object layout. last_send_shared is +0x888,
// debug file must be an array symbol (push immediate address), not `const char*` (load then push).


long TribeMPSetupScreen::handle_idle() {
    if (rge_base_game->input_enabled == 0) {
        rge_base_game->enable_input();
    }
    if (rge_base_game->multiplayerGame()) {
        if (last_send_shared == 0) {
            last_send_shared = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_mps_cp, 0x2FE);
        }
        else {
            unsigned long t = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_mps_cp, 0x301);
            if (t - last_send_shared != 0) {
                comm->SendSharedData(0);
                last_send_shared = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_mps_cp, 0x304);
            }
        }
    }
    return TPanel::handle_idle();
}

// PDB-order owner source: 004A16D0_key_down_action.cpp.

long TribeMPSetupScreen::key_down_action(long p0, short p1, int p2, int p3, int p4) { return 0; }

// PDB-order owner source: 004A16E0_action.cpp.

// VA: 004A16E0 TribeMPSetupScreen::action
// scr_mps.cpp lines 812-1134
//
// Attempt log:
// - Recovered the typed panel arrays, helper ABIs, 0x220 EH frame, and 105 direct calls.
// - BINARY NOTE: The fallback is shared by null input, nonzero param_2, and exhausted loops.
//   Keep the TEasy_Panel call as one emitted tail. The source keeps a natural base-action
//   return in the non-null arm and a second null-path return; VC5 merges the call itself.
// - BINARY NOTE: All four scenario filename LEAs are four bytes before file_name+4.
//   Direct file_name access restores the three scenario blocks without changing calls.
// - BINARY NOTE: The final player loop has one initial numberPlayers call and one bottom call.
//   A do-while loop recovers the signed bottom-test shape better than an explicit break.
// - Tested 15 additional hypotheses across fallback structure, loop form, cursor ownership,
//   local order, filename base, CD evaluation, and liveness. The natural fallback form reduced
//   the strict diff from 2159 to 1641 bytes and raised exact-block coverage to 91.60%.
//   A cursor variant reached 1607 bytes but lost exact blocks and produced call-target drift;
//   it was discarded. The current source keeps the behavior-correct do-while and direct base.
//
// Current unresolved result: 1641 strict differing bytes, 96.93% shape similarity,
// 91.60% exact-block coverage, and 105/105 ordered calls. The main gaps are the shared
// fallback tail size, the file_info stack home, and final-loop register coloring.
// Authentic scr_mps.cpp context selected the PDB virtual symbol and reduced the
// body to 2468 bytes. It kept 105 calls and reduced the strict diff to 1639 bytes.
// BINARY NOTE: The ready-version dialog target is TEasy_Panel::popupOKDialog(long,
// char*, int, int). Explicit base qualification preserves that target in the wrapper.
// BINARY NOTE: Readiness payload arguments use the unsigned-long overload. Explicit
// casts preserve the direct target when the wrapper has an extra int overload.
// GROUPED BLOCKER: The shared wrapper TEditPanel surface places active at +0x130, but
// the executable reads the inherited TPanel active field at +0x6C. Do not replace this
// proven field with a raw local offset view; the shared context needs main-agent repair.

long TribeMPSetupScreen::action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4)
{
    char file_name[260];
    _finddata_t file_info;

    if (param_1 != 0) {
        if (param_1 == this->startButton && param_2 == 1) {
            if (this->chatInput != 0 && this->chatInput->active != 0) {
                this->set_curr_child(this->chatInput);
            }
            this->startGame();
            return 1;
        }

        if (param_1 == this->ready_button && param_2 == 1) {
            if (this->ready_button->get_state() != 0) {
                L->Log("$$$ SELECTED I'M READY");
                if (comm->IsHost()) {
                    comm->SetMyReadiness(1, (unsigned long)0, (unsigned long)0,
                        (unsigned long)0, (unsigned long)0, (unsigned long)0,
                        (unsigned long)0, (unsigned long)0);
                } else {
                    if (rge_base_game->playerVersion(0) != 1) {
                        this->ready_button->set_state(0);
                        this->TEasy_Panel::popupOKDialog(0x25E3, 0, 0x1C2, 100);
                        return 1;
                    }
                    int me = comm->WhoAmI() - 1;
                    L->Log("$$$ SAVING MYCIV & MYTEAM");
                    this->myCivilization = this->playerCivDrop[me]->get_id();
                    this->myScenarioPlayer = this->scenarioPlayerDrop[me]->get_id();
                    this->myPlayerColor = this->playerColor[me]->get_id();
                    this->myPlayerTeam = this->playerTeam[me]->get_state() + 1;
                    if (rge_base_game->scenarioGame()) {
                        char* dir = rge_base_game->prog_info->scenario_dir;
                        sprintf(file_name, "%s%s.scn", dir,
                                rge_base_game->scenarioName());
                        if (_findfirst(file_name, (struct _finddata_t*)&file_info.time_create) == -1) {
                            sprintf(file_name, "%s.scx", rge_base_game->scenarioName());
                        } else {
                            sprintf(file_name, "%s.scn", rge_base_game->scenarioName());
                        }
                        this->myScenarioChecksum = rge_base_game->get_scenario_checksum(file_name);
                    } else {
                        this->myScenarioChecksum = 0;
                    }
                    comm->SetMyReadiness(1, (unsigned long)this->myCivilization,
                        (unsigned long)(this->myScenarioPlayer + 1),
                        (unsigned long)(rge_base_game->check_for_cd(0) + 1),
                        (unsigned long)this->myPlayerColor, (unsigned long)this->myPlayerTeam,
                        (unsigned long)this->myScenarioChecksum, (unsigned long)1);
                }
                if (this->chatInput != 0 && this->chatInput->active != 0) {
                    this->set_curr_child(this->chatInput);
                }
                this->i_am_ready = 1;
            } else {
                L->Log("$$$ SELECTED NOT READY");
                int cd = 0;
                if (!comm->IsHost()) {
                    cd = rge_base_game->check_for_cd(0) + 1;
                }
                comm->SetMyReadiness(0, (unsigned long)0, (unsigned long)0,
                    (unsigned long)cd, (unsigned long)0, (unsigned long)0,
                    (unsigned long)0, (unsigned long)0);
                if (this->chatInput != 0 && this->chatInput->active != 0) {
                    this->set_curr_child(this->chatInput);
                }
                this->i_am_ready = 0;
            }
            this->fillPlayers();
            if (comm->IsHost()) {
                this->gameSettingsButton->set_disabled(this->i_am_ready);
                this->startButton->set_disabled(this->i_am_ready == 0);
                rge_base_game->send_game_options();
                this->resend_game_options = 0;
                comm->SendSharedData(1);
                return 1;
            }
            goto L_1F6B;
        }

        if (param_1 == this->gameSettingsButton && param_2 == 1) {
            if (this->chatInput != 0 && this->chatInput->active != 0) {
                this->set_curr_child(this->chatInput);
            }
            if (panel_system.panel("Game Settings Screen") == 0) {
                rge_base_game->disable_input();
                new TribeGameSettingsScreen();
            }
            panel_system.setCurrentPanel("Game Settings Screen", 0);
            return 1;
        }

        if (param_1 == this->help_button && param_2 == 1) {
            this->setup_popup_help();
            return 1;
        }

        if (param_1 == this->close_button && param_2 == 1) {
            rge_base_game->close();
            return 1;
        }

        if (param_1 == this->cancelButton && param_2 == 1) {
            if (this->chatInput != 0 && this->chatInput->active != 0) {
                this->set_curr_child(this->chatInput);
            }
            this->cancelScreen(0);
            return 1;
        }

        if (param_1 == this->netInfoButton) {
            if (param_2 == 1) {
                this->showNetInfo();
                return 1;
            }
        } else if (param_2 == 1) {
            for (int i = 0; i < 8; i++) {
                if (param_1 == this->playerColor[i]) {
                    ((TRIBE_Game*)rge_base_game)->setPlayerColor(i, this->playerColor[i]->get_id());
                    if (rge_base_game->multiplayerGame() && !comm->IsHost()) {
                        this->myPlayerColor = this->playerColor[i]->get_id();
                        return 1;
                    }
                    goto L_1F6B;
                }
                if (param_1 == this->playerTeam[i]) {
                    rge_base_game->setPlayerTeam(i, this->playerTeam[i]->get_state() + 1);
                    if (rge_base_game->multiplayerGame() && !comm->IsHost()) {
                        this->myPlayerTeam = this->playerTeam[i]->get_state() + 1;
                        return 1;
                    }
                    goto L_1F6B;
                }
            }
        }

        if (param_1 == this->chatInput && param_2 == 0 &&
            this->chatInput->currentLine() != 0 && this->chatInput->currentLine()[0] != 0) {
            comm->SendChatMsgAll(this->chatInput->currentLine());
            this->chatInput->set_text("");
            return 1;
        }

        if (param_1 == this->numberPlayersDrop && param_2 == 0) {
            rge_base_game->setNumberPlayers(this->numberPlayersDrop->get_id());
            this->updateSummary();
            return 1;
        }

        if (param_1->panelName() != 0 && strcmp(param_1->panelName(), "Game Settings Screen") == 0) {
            if (param_2 != 0) {
                this->updateSummary();
                if (!rge_base_game->singlePlayerGame()) {
                    rge_base_game->send_game_options();
                    this->resend_game_options = 0;
                }
            }
            panel_system.setCurrentPanel("MP Setup Screen", 0);
            return 1;
        }

        if (param_1->panelName() != 0 && strcmp(param_1->panelName(), "Kick Dialog") == 0) {
            if (param_2 == 0) {
                long id = this->playerNameDrop[this->playerToKick - 1]->get_id();
                comm->Kick(this->playerToKick);
            comm->SetPlayerHumanity(this->playerToKick,
                                    (PLAYERHUMANITY)id);
                this->playerNameDrop[this->playerToKick - 1]->set_line(
                    this->playerNameDrop[this->playerToKick - 1]->get_line(id));
            } else {
                this->playerNameDrop[this->playerToKick - 1]->set_line(0);
            }
            delete param_1;
            return 1;
        }

        if (param_2 == 0 && rge_base_game->numberPlayers() > 0) {
            int i = 0;
            do {
                if (param_1 == this->playerNameDrop[i]) {
                    if (rge_base_game->multiplayerGame() &&
                        this->playerNameDrop[i]->get_line() > 0 &&
                        comm->IsPlayerHuman(i + 1)) {
                        this->kickPlayer(i + 1);
                        return 1;
                    }
                    comm->SetPlayerHumanity(
                        i + 1,
                        (PLAYERHUMANITY)this->playerNameDrop[i]->get_id());
                    return 1;
                }
                if (param_1 == this->playerCivDrop[i]) {
                    ((TRIBE_Game*)rge_base_game)->setCivilization(i, this->playerCivDrop[i]->get_id());
                    if (rge_base_game->multiplayerGame() && !comm->IsHost()) {
                        this->myCivilization = this->playerCivDrop[i]->get_id();
                        return 1;
                    }
                    goto L_1F6B;
                }
                if (param_1 == this->scenarioPlayerDrop[i]) {
                    if (rge_base_game->multiplayerGame()) {
                        ((TRIBE_Game*)rge_base_game)->setScenarioPlayer(i, this->scenarioPlayerDrop[i]->get_id());
                        if (!comm->IsHost()) {
                            this->myScenarioPlayer = this->scenarioPlayerDrop[i]->get_id();
                            return 1;
                        }
                        goto L_1F6B;
                    }
                    ((TRIBE_Game*)rge_base_game)->setScenarioPlayer(0, this->scenarioPlayerDrop[0]->get_id());
                    int sp = 1;
                    int player = 0;
                    do {
                        if (player != ((TRIBE_Game*)rge_base_game)->scenarioPlayer(0) &&
                            ((RGE_Scenario*)this->scenarioInfo)->Get_player_Active(player) != 0) {
                            ((TRIBE_Game*)rge_base_game)->setScenarioPlayer(sp, player);
                            sp++;
                            if (sp >= rge_base_game->numberPlayers()) break;
                        }
                        player++;
                    } while (player < 8);
                    this->fillPlayers();
                    goto L_1F6B;
                }
                i++;
            } while (i < rge_base_game->numberPlayers());
        }
        return this->TEasy_Panel::action(param_1, param_2, param_3, param_4);
L_1F6B:
        return 1;
    }
L_1F72:
    return this->TEasy_Panel::action(param_1, param_2, param_3, param_4);
}

// PDB-order owner source: 004A2060_startGame.cpp.

// VA: 004A2060 TribeMPSetupScreen::startGame
// PDB source: scr_mps.cpp lines 1140-1446
// __thiscall: this in ecx, no stack params. int return (1 = ok, 0 = error).
//
// Attempt log:
// 1 baseline: natural reconstruction of the full 83-call multiplayer start sequence
//   (host/ready checks, scenario checksum + player-version scans, scenario validation,
//   scenario-player dropdown fill, player count/color uniqueness, human+CD check,
//   randomize positions, single-player humanity fill, civ/team +0x32 reset, apply
//   colors/teams/civs, destroy status screen, launch multiplayer, start_game).
//   Frame exact (0x568). diff=1617 (87.5%), shape 84.83%, calls 76/83.
// 2 control-flow: forced the scenario-checksum error handler to a cold tail at the
//   very end via goto; VC5 re-emitted identical bytes (codegen duplicate), so the
//   error tail placement is not source-controllable through goto here.
// 7 source-shape audit: msg/msg_small BASE (not +4) for all four error handlers;
//   inline sprintf arguments (right-to-left cdecl pushes the GetPlayerName result
//   BEFORE the get_string call); single numberPlayers call in the single-player fill;
//   field_88C at +0x88C (4-byte gap at +0x888); temp_team[c-1] folds to
//   [esp+eax*4+14h]; block-5 dead `cmp eax,2` comes from if(hum==2||hum==4){ if
//   (hum==2){...}else{...} }. diff=1628 -> calls 79/83.
// 8 control-flow: CHECKSUM LOOP AS FOR-HEADER (init+increments in the for clause,
//   PDB line 1192 attribution) places the checksum-mismatch error as the COLD TAIL at
//   the end exactly like the original (the do-while form kept it inline). diff=530,
//   calls 83/83, EXACT CODEGEN stage reached.
// 9 liveness: checksum init order i3,u12,pl in source order. diff=523.
// 10-12 liveness/context: variable reuse and the full typed TribeMPSetupScreen class
//   surface (TPanel/TScreenPanel bases, 004A1300 donor layout) do not change the
//   register allocation (codegen duplicate / no effect).
// 14 control-flow: full for-header init clauses for the checksum loop; version loop as
//   `for (u12 = 0; u12 < 8; u12 = u4)` (matches PDB 1208 attribution). diff=520.
// 15-17 behavior: block-12 fill loop do-while val=idx+1/idx=val; then binary-proven
//   fills: temp_team/temp_civ filled with DWORD value 1 (mov eax,1; rep stosd - NOT
//   memset(...,1,...) which emits 0x01010101); civ/team check is >= 0x32 (cmp 32h)
//   not > 0x31; block-4 numberLines compare with i3 on the left (i3 >= lines);
//   0x25c3/0x25c5 compares with i5 on the left (i5 > count / i5 != count).
//   diff=67 (3.6%), shape 99.12%, exact-blocks 93.1%, calls 83/83, size/frame exact.
//
// Final state (10 meaningful probes this claim): diff=67 bytes (3.6275%), shape 99.12%,
// calls 83/83 aligned, exact-block coverage 93.12%, code_size/frame/saved-regs exact.
// Remaining drift is a whole-function register-allocation basin only:
// - original holds `this` in EBP (spilled to [esp+14h] when EBP becomes the block-12
//   cnt counter); rebuilt holds this in EBX. Every remaining byte diff is the ebp<->ebx
//   renaming plus the role-register swaps (version-loop u12b/u4 in esi/edi vs edi/esi,
//   block-4 i3/u4b in ebx/edi vs edi/ebp, block-5 i5 ebx vs ebp), the block-12 fill
//   loop `mov edx,eax; cmp edx,8` vs `cmp eax,8; mov edx,eax` scheduling, and
//   sub eax,32h vs add eax,0FFFFFFCEh in the civ/team reset.
// Resisted: variable reuse (probe-10/12), full typed class surface (probe-13), for/
// do-while loop forms, init clause orders, declaration scopes. This looks like a
// hard VC5 allocator basin; a future worker should try function-top declarations of
// the role variables in first-use order or a variant lab before accepting the drift.
//
// Follow-up sa44_startGame_followup:
// - confirmed the clean natural no-VPAD game/panel surface, exact frame/size, and 83/83
//   ordered calls; first checker hunk remains version-loop register roles at +0100.
// - swapped version roles, reused/top-declared loop scalars, changed the block-12
//   condition to the computed value, used compound civ/team decrements, moved
//   send_options, tested natural base/derived game ownership, and tried saved-this
//   aliases; all emitted the same 67-byte mismatch.
// - focused natural variant lab (send initialization x temp_team zero-fill, 4 variants)
//   preserved size/frame/call-set but collapsed to one codegen group, still diff=67.
// - restored the canonical no-VPAD source; remaining drift is the whole-function EBP/
//   EBX allocator basin plus documented role-register swaps, not a call/layout gap.
// - Fresh claim: same-TU prologue donor search confirms the remaining gap is
//   the allocator basin, not a missing call, layout, or declaration identity.
//
// Follow-up sa-f81e3ed5-r1 (21 meaningful probes, 2026-08-17):
// - bool send_options changed the frame shape and size. A split declaration did not.
// - A saved-this alias, top-scope role declarations, register hints, and scalar-first
//   declaration order kept the 67-byte result. The same held for TEasy inheritance.
// - Reviewed base/derived game ownership and extern global forms kept the same bytes.
//   They changed relocation counts only. Keep the current local macro for this target.
// - Explicit version and color loop forms moved control flow or grew the diff.
//   Compound civ/team decrements, zero-fill loops, and standard-header additions did not.
// - A 64-sample ambient declaration lab made one codegen group. A five-flag lab made
//   four default groups and one wrong-frame /O1-style group. No exact result appeared.
// - BINARY NOTE: the clean source remains 1847 bytes, frame 0x568, 83/83 ordered calls,
//   and 67 differing bytes. The first mismatch is the original EBP receiver versus
//   rebuilt EBX receiver at +0009. The remaining drift is register allocation only.
// ACCEPTED DRIFT: The residual exchanges the receiver, loop indexes, and counters
// between saved registers. One loop schedules a copy around its compare, and the
// civ/team reset uses `sub 0x32` versus `add -0x32`; its flags are dead. All 83
// calls, pushed values, branches, fills, memory effects, returns, and fault order
// match. The frame, saved registers, EH state, and function boundary also match.
// Authentic scr_mps.cpp context kept 1847 bytes, 83 calls, and the 67-byte diff.
// - DIA private symbols prove scoped msg[1024], playerColorUsed[8], msg[256],
//   temp_team[8], temp_color[8], and temp_civ[8]. The two int arrays share
//   the original EBP-1376 home because their lifetimes do not overlap.
// - Adding exact 004A0D80, 004A1300, and 004A1640 owners preserved this result.
//   The reviewed RGE_Base_Game* global type is required. TRIBE_Game* changed
//   the target to a 563-byte register-allocation basin.


int TribeMPSetupScreen::startGame()
{
    int send_options = 0;

    if (rge_base_game->multiplayerGame()) {
        char msg[1024];
        if (!comm->IsHost()) {
            return 0;
        }
        if (!comm->AllPlayersReady()) {
            this->popupOKDialog(0x25c1, 0, 0x1c2, 100);
            return 0;
        }
        int u12;
        if (rge_base_game->scenarioGame()) {
            int i3;
            long* pl;
            for (i3 = 0, u12 = 1, pl = this->scenarioCheckSum; u12 < 9; i3++, pl++, u12++) {
                if (u12 != comm->WhoAmI() &&
                    comm->GetPlayerHumanity(u12) == 2) {
                    if (*pl != this->myScenarioChecksum) {
                        sprintf(msg, this->get_string(0x25e1), comm->GetPlayerName(i3 + 1));
                        this->popupOKDialog(msg, 0, 0x1c2, 100);
                        return 0;
                    }
                }
            }
        }
        int u4;
        for (u12 = 0; u12 < 8; u12 = u4) {
            u4 = u12 + 1;
            if (u4 != comm->WhoAmI() &&
                comm->GetPlayerHumanity(u4) == 2) {
                if (rge_base_game->playerVersion(u12) != 1) {
                    sprintf(msg, this->get_string(0x25e2), comm->GetPlayerName(u12 + 1));
                    this->popupOKDialog(msg, 0, 0x1c2, 100);
                    return 0;
                }
            }
        }
    }

    if (rge_base_game->scenarioGame() && this->scenarioInfo == 0) {
        this->popupOKDialog(0x25c2, 0, 0x1c2, 100);
        return 0;
    }

    if (rge_base_game->multiplayerGame() && rge_base_game->scenarioGame()) {
        int i3 = 0;
        int u12 = 0;
        int u4b;
        do {
            u4b = u12 + 1;
            int hum = comm->GetPlayerHumanity(u4b);
            if (hum == 2 || hum == 4) {
                long id = this->scenarioPlayerDrop[0]->get_id(i3);
                ((TRIBE_Game*)rge_base_game)->setScenarioPlayer(u12, id);
                i3++;
                if (i3 >= this->scenarioPlayerDrop[0]->list_panel->numberLines()) {
                    i3 = 0;
                }
            }
            u12 = u4b;
        } while (u4b < 8);
    }

    if (rge_base_game->multiplayerGame()) {
        int playerColorUsed[8];
        char msg[256];
        memset(playerColorUsed, 0, sizeof(playerColorUsed));
        int i5 = 0;
        int u12 = 0;
        int num = rge_base_game->numberPlayers();
        if (num > 0) {
            int u4c;
            do {
                u4c = u12 + 1;
                int hum = comm->GetPlayerHumanity(u4c);
                if (hum == 2 || hum == 4) {
                    if (hum == 2) {
                        int c = ((TRIBE_Game*)rge_base_game)->playerColor(u12);
                        if (playerColorUsed[c - 1] == 0) {
                            i5++;
                            c = ((TRIBE_Game*)rge_base_game)->playerColor(u12);
                            playerColorUsed[c - 1] = 1;
                        }
                    } else {
                        i5++;
                    }
                }
                u12 = u4c;
            } while (u4c < rge_base_game->numberPlayers());
        }
        if (i5 < 2) {
            this->popupOKDialog(0x25c6, 0, 0x1c2, 100);
            return 0;
        }
        if (rge_base_game->scenarioGame() && i5 > this->scenarioPlayerCount) {
            sprintf(msg, this->get_string(0x25c3), this->scenarioPlayerCount);
            this->popupOKDialog(msg, 0, 0x1c2, 100);
            return 0;
        }
        if (rge_base_game->scenarioGame() && this->settingsFixed != 0 &&
            i5 != this->scenarioPlayerCount) {
            sprintf(msg, this->get_string(0x25c5), this->scenarioPlayerCount);
            this->popupOKDialog(msg, 0, 0x1c2, 100);
            return 0;
        }

        int i5h = 0;
        int u12c = 0;
        int nump = rge_base_game->numberPlayers();
        if (nump > 0) {
            do {
                u12c++;
                if (comm->GetPlayerHumanity(u12c) == 2) {
                    i5h++;
                }
            } while (u12c < rge_base_game->numberPlayers());
        }
        int cd = rge_base_game->check_for_cd(0);
        rge_base_game->setPlayerHasCD(comm->WhoAmI() - 1, cd);
        int cd2 = rge_base_game->check_for_cd(i5h);
        if (cd2 == 0) {
            this->popupOKDialog(0x7d9, 0, 0x1c2, 100);
            return 0;
        }
    }

    if (rge_base_game->scenarioGame() && ((TRIBE_Game*)rge_base_game)->randomizePositions()) {
        this->calcRandomPositions();
        if (rge_base_game->multiplayerGame()) {
            send_options = 1;
        }
    }

    if (rge_base_game->singlePlayerGame()) {
        int num = rge_base_game->numberPlayers();
        if (num < 8) {
            int u12 = num + 1;
            do {
                comm->SetPlayerHumanity(u12, ME_ABSENT);
                u12++;
            } while (u12 < 9);
        }
    }

    if (rge_base_game->multiplayerGame()) {
        int i5 = 0;
        int num = rge_base_game->numberPlayers();
        if (num > 0) {
            do {
                int civ = ((TRIBE_Game*)rge_base_game)->civilization(i5);
                if (civ >= 0x32) {
                    Log(L, (char*)0x00586894);
                    civ = ((TRIBE_Game*)rge_base_game)->civilization(i5);
                    ((TRIBE_Game*)rge_base_game)->setCivilization(i5, civ - 0x32);
                    send_options = 1;
                }
                int team = rge_base_game->playerTeam(i5);
                if (team >= 0x32) {
                    Log(L, (char*)0x0058687C);
                    team = rge_base_game->playerTeam(i5);
                    rge_base_game->setPlayerTeam(i5, team - 0x32);
                    send_options = 1;
                }
                i5++;
            } while (i5 < rge_base_game->numberPlayers());
        }
    }

    if (rge_base_game->multiplayerGame()) {
        int temp_team[8];
        int temp_color[8];
        int temp_civ[8];
        int idx = 0;
        for (int i = 0; i < 8; i++) temp_team[i] = 1;
        for (int j = 0; j < 8; j++) temp_civ[j] = 1;
        do {
            int val = idx + 1;
            temp_color[idx] = val;
            idx = val;
        } while (idx < 8);
        int cnt = 0;
        for (int u12 = 1; u12 < 9; u12++) {
            int hum = comm->GetPlayerHumanity(u12);
            if (hum == 2 || hum == 4) {
                int p = u12 - 1;
                temp_color[cnt] = ((TRIBE_Game*)rge_base_game)->playerColor(p);
                temp_civ[cnt] = ((TRIBE_Game*)rge_base_game)->civilization(p);
                temp_team[cnt] = rge_base_game->playerTeam(p);
                cnt++;
            }
        }
        if (cnt > 0) {
            for (int i = 0; i < 8; i++) {
                ((TRIBE_Game*)rge_base_game)->setPlayerColor(i, temp_color[i]);
                ((TRIBE_Game*)rge_base_game)->setCivilization(i, temp_civ[i]);
                rge_base_game->setPlayerTeam(i, temp_team[i]);
            }
            send_options = 1;
        }
    }

    panel_system.destroyPanel((char*)0x00586218);

    if (rge_base_game->multiplayerGame()) {
        if (send_options || this->resend_game_options != 0) {
            rge_base_game->send_game_options();
            this->resend_game_options = 0;
        }
        comm->LaunchMultiplayerGame();
        chat->setWindowHandle(AppWnd);
        comm->SetWindowHandle(AppWnd);
    }

    if (!((TRIBE_Game*)rge_base_game)->start_game(0)) {
        this->popupOKDialog(0x961, 0, 0x1c2, 100);
        return 0;
    }
    return 1;
}

// PDB-order owner source: 004A27A0_calcRandomPositions.cpp.

// VA: 004A27A0 calcRandomPositions
// PDB donor: scr_mps.cpp:1452-1526
//
// Baseline reconstruction: the routine counts human players, records the
// currently available scenario-player positions, and assigns each human a
// random unused position.  position_used[0] is the per-iteration player
// scratch slot; entries 1..8 are the eight dropdown positions.
//
// Attempt log (sa64f8-calc):
// - Baseline named the screen/dropdown/game/communications surfaces and
//   recovered the 0x2C frame, four saved registers, and all nine call sites.
// - Swapping local declaration order, scoping the zero-based player counter,
//   and separating its one-based humanity query recovered the original saved
//   this home, second-loop register roles, player argument, and most block
//   placement.  The setScenarioPlayer/store values are intentionally zero
//   based; only GetPlayerHumanity receives player+1.
// - An explicit bounded pointer for-loop is the best source basin.  Guarded
//   do/while, unguarded for, pointer-base/preincrement, and explicit-continue
//   variants grew the frame or moved the whole function; rolled back.
// - Caching scenarioPlayerCount and reversing the random product/retry
//   spellings were codegen duplicates.  Best current result is 372 rebuilt
//   bytes versus 366, 94.31% shape, 165 positional diff bytes, 9/9 calls;
//   remaining structural drift starts at the nested count scan (duplicated
//   test/LEA layout), followed by the random-loop tail.
// - Fresh pass isolated guarded do/while scans (pointer, indexed, reused-index,
//   and declaration-order forms); all added a 0x30 frame and broad drift.
//   while/short-circuit forms retained the duplicate count test. A for-header
//   retry loop improved structural shape to 97.54% and resync similarity to
//   91.08% (370 bytes), but strict drift was 171 bytes; compound random
//   multiplication was codegen-neutral. Removing only the nested count guard
//   preserved size but moved the whole local basin (220-byte drift). Restored
//   the validated 372-byte natural candidate.
// - Fresh claim probes: guarded do/while scans with the original polarity
//   entered a +0x30-frame compiler basin; indexed, infinite, and labeled forms
//   were duplicate variants of that basin. Removing the guard alone also moved
//   the frame/register basin. Adding <stdio.h> (and <stdlib.h>) was neutral.
// - The natural inverted-predicate do/while (`*position != -1` advances,
//   otherwise records the index) restores the original single count test,
//   0x2C frame, and nested scan block: 368 bytes, 95.87% shape, 76 diff bytes,
//   9/9 calls. Swapping/compounding the random product was codegen-neutral;
//   the remaining 2-byte size/tail drift is in the magic random division.
// - Fresh claim: reusing the debug_rand result for the quotient and adding a
//   natural product temporary were codegen duplicates. A combined retry
//   predicate improved the retry jump but worsened the local block topology;
//   restored the pinned inverted-scan source.
// - Fresh bounded pass: inlining debug_rand in the scaling expression matches
//   the oracle's ECX-held magic-division schedule and improves diff 76 -> 66.
//   Combined retry, explicit else, and infinite-loop spellings were worse or
//   duplicate; keep the natural do/while.  A bounded for-header retry loop
//   instead reproduces the oracle's direct JL backedge, exact size, CFG, and
//   every byte except the final player-count compare (cmp esi,eax vs ebp,eax).
// ACCEPTED_DRIFT: main-agent adjudication confirmed EBP is copied from ESI
// before numberPlayers. That call preserves ESI. Both compares therefore use
// the same value and set identical flags. No memory or call effect differs.


void TribeMPSetupScreen::calcRandomPositions() {
    int selected_position;
    int position_used[9];
    int human_players = 0;
    int i = 0;
    int players = rge_base_game->numberPlayers();

    if (players > 0) {
        do {
            ++i;
            int humanity = comm->GetPlayerHumanity(i);
            if (humanity == 2 || humanity == 4) {
                ++human_players;
            }
            players = rge_base_game->numberPlayers();
        } while (i < players);
    }

    int available = 0;
    i = 0;
    do {
        long line = this->scenarioPlayerDrop[0]->get_line(i);
        if (line == -1) {
            position_used[i + 1] = -2;
        } else {
            position_used[i + 1] = -1;
            ++available;
        }
        ++i;
    } while (i < 8);

    if (human_players <= available) {
        int player = 0;
        for (; player < rge_base_game->numberPlayers(); player = position_used[0]) {
                position_used[0] = player + 1;
                int humanity = comm->GetPlayerHumanity(position_used[0]);
                if (humanity == 2 || humanity == 4) {
                    int j = 0;
                    int count = this->scenarioPlayerCount;
                    if (count > 0) {
                        int* position = &position_used[1];
                        do {
                            if (*position != -1) {
                                ++j;
                                ++position;
                            } else {
                                selected_position = j;
                                break;
                            }
                        } while (j < count);
                    }

                    int tries = 0;
                    int new_position;
                    for (; tries < 1000; ++tries) {
                        int count = this->scenarioPlayerCount;
                        new_position =
                            (debug_rand("C:\\msdev\\work\\age1_x1\\scr_mps.cpp", 0x5E4) * count) /
                            0x7FFF;
                        if (new_position >= count) {
                            new_position = count - 1;
                        } else if (new_position < 0) {
                            new_position = 0;
                        }
                        if (position_used[new_position + 1] == -1) {
                            selected_position = new_position;
                            break;
                        }
                    }

                    ((TRIBE_Game*)rge_base_game)->setScenarioPlayer(player, selected_position);
                    position_used[selected_position + 1] = player;
                }
        }
    }
}

// PDB-order owner source: 004A2910_showNetInfo.cpp.

// VA: 004A2910 TribeMPSetupScreen::showNetInfo
// Attempt log:
// 1: natural reconstruction from packet using real new/ctor/delete and strcat/sprintf.
// 2: /GX required for original EH frame; class size padded to 0x224 to match operator new size.
// 3: The two dialogs are inherited TEasy_Panel::popupOKDialog overloads. The
// message overload takes (message,title,line,height), not the decompiler order.


void TribeMPSetupScreen::showNetInfo()
{
    char message[1024];
    char temp_str[256];

    RGE_Communications_Addresses* addresses = new RGE_Communications_Addresses(comm);
    if (addresses) {
        unsigned int num_addr = *(unsigned int*)((char*)addresses + 0x218);
        message[0] = 0;
        if (num_addr > 0) {
            strcat(message, (char*)0x005868AC);
            sprintf(temp_str, this->get_string(0x238c), addresses->GetHostName());
            strcat(message, temp_str);
            strcat(message, (char*)0x00583994);
            for (unsigned int i = 0; i < num_addr; i++) {
                if (addresses->GetAddress(i)) {
                    strcat(message, addresses->GetAddress(i));
                    strcat(message, (char*)0x00580460);
                }
                if (addresses->GetAlias(i)) {
                    strcat(message, addresses->GetAlias(i));
                }
                strcat(message, (char*)0x00583994);
            }
            this->TEasy_Panel::popupOKDialog(
                message, (char*)0x584eb4, 0x1c2, num_addr * 18 + 100);
        } else {
            this->TEasy_Panel::popupOKDialog(0x238d, 0, 0x1c2, 100);
        }
        addresses->~RGE_Communications_Addresses();
        operator delete(addresses);
    }
}

// PDB-order owner source: 004A2BA0_cancelScreen.cpp.

// VA: 004A2BA0 TribeMPSetupScreen::cancelScreen(int)
// PDB donor: scr_mps.cpp:1576-1622
//
// The argument is the lobby timeout flag.  The routine selects the next
// screen for single-player, lobby, and ordinary multiplayer cancellation;
// the constructor sizes and the setup-state field below are binary-proven.
//
// Attempt log (sa64f8-cancel):
// - Natural typed new/constructor branches recovered all 18 direct calls and
//   the correct allocation sizes, but default flags omitted the original EH
//   registration and produced a 312-byte body.
// - /GX is required, matching the exact same-TU constructor donors.  A common
//   panel-name local preserved call count but changed EH-state/string-argument
//   scheduling.  Keeping the ordinary setCurrentPanel call in each successful
//   source branch lets VC5 cross-jump the common call/destroy tail and emits
//   the original single call site with each branch's literal push.
// - MATCH: 429/429 bytes, 18/18 calls, 100% shape and relocation identity.
// FLAGS: config/flags/004A2BA0_cancelScreen.rsp (/GX)


void TribeMPSetupScreen::cancelScreen(int timed_out) {
    if (rge_base_game->singlePlayerGame() != 0) {
        rge_base_game->disable_input();
        if (rge_base_game->scenarioGame() != 0) {
            new TribeSelectScenarioScreen;
            panel_system.setCurrentPanel("Select Scenario Screen", 0);
        } else {
            new TribeSPMenuScreen;
            panel_system.setCurrentPanel("Single Player Menu", 0);
        }
    } else if (comm->IsLobbyLaunched() != 0) {
        if (timed_out != 0) {
            TRIBE_Screen_Main_Error* error = new TRIBE_Screen_Main_Error;
            if (error != 0 && error->error_code == 0) {
                error->set_text(0x96A);
                panel_system.setCurrentPanel("Main Error Screen", 0);
            } else {
                rge_base_game->close();
                return;
            }
        } else {
            rge_base_game->close();
            return;
        }
    } else {
        rge_base_game->disable_input();
        comm->UnlinkToLevel((COMMSTATUS)5);
        new TribeJoinScreen;
        panel_system.setCurrentPanel("Join Screen", 0);
    }

    panel_system.destroyPanel("MP Setup Screen");
}

// PDB-order owner source: 004A2D50_handle_user_command.cpp.

// VA: 004A2D50 TribeMPSetupScreen::handle_user_command
// scr_mps.cpp lines 1628-1924 (157 line records)
//
// Canonical reconstruction: large virtual switch over MP-setup user commands.
// Class surface follows the exact donor 004A37D0 (fillPlayers); TPanel vtable
// follows the exact 004A16E0 action surface (set_redraw at +0x20,
// handle_user_command at +0x64). Case order follows the physical body layout
// of the original (17BB, 17A4, 17D5, 17A6, 17A7, 17A8, 17A9, 17B2, 17AA,
// 17B3, 17B7, 17B6, 17B9, 17AE, default).
//
// Attempt log:
// - Baseline (full surface, do-while loops, walking checksum pointer): frame
//   0x128 vs 0x12C; message base E-0x104 confirmed from GetClientReadiness
//   out0 lea + sprintf/popup message+4 leas.
// - message[260] (not 256): exact 0x12C frame; Ghidra's [256] rounds the real
//   260-byte buffer that spans E-0x104..E-1.
// - Case 17BB: nested if(IsHost){int i=0; if(n>0){do..while}} + SINGLE return
//   after the if. All three exits (not-host, n<=0, loop-done) share one return
//   statement; VC5 tail-duplicates it into the case return + the shared 36D1
//   (ebx) return. This + the 17B9 if/else form unlocked the ebx basin that
//   hoists `mov ebx,1` before the first branch (2DC2/33D0/36AA).
// - Case 17A6: updateSummary + if(!IsHost){ if(!(sent_cd && checksums &&
//   ready)) { sync; } } + single return after the if. The INVERTED ready
//   condition (fall-through to the shared return on ready-match, sync in the
//   else) fixed the ready-match je target (3410 -> 36D1). Positive IsHost
//   early-return / explicit sync return forms regressed to 73B.
// - Case 17B9: `if (IsLobbyLaunched) { cancelScreen(1); } else {
//   handleKickedPlayer(0); } return 1;` — if/else with a single shared return
//   duplicates the ebx return into both branches (36B9/36D1) and hoists
//   `mov ebx,1` before the je (36AA). This was the basin-breaking fix.
// - 17A4: declare int i=0 before int* checksum to schedule xor esi before
//   add edi (004A2F12).
// - TPanel gap_04[0xF0] (TPanel = 0xF4) added so TribeMPSetupScreen fields
//   land at the canonical +0x72C..+0x88C offsets (was 0xF0 low).
// - resend_game_options needs a 4-byte pad at +0x888 (after scenarioCheckSum[8])
//   to land at +0x88C.
// - user locals: homes are VC5-internal and declaration-invariant (6 orders
//   tested); ready cast as (unsigned long*)&ready per Ghidra.
//
// LEFT IN SCRATCH: 6 bytes (0.2352%) of stack-home displacement drift in the
// GetClientReadiness argument block. Original homes user2@+2C, user6@+30,
// ready@+34; rebuilt keeps ready@+2C, user2@+30, user6@+34. 3 lea + 3 load
// displacement bytes only; size/frame/calls/CFG all exact (2551/2551, 769/769,
// 104/104). Declaration order, local types, scope, and check shapes were swept
// without moving the homes; the internal ordering that assigns these three
// stack homes is not reachable from the natural source forms tried.
// ACCEPTED_DRIFT: manual instruction review confirms that all six differing
// bytes are only the displacements of three independent address-taken locals
// passed to GetClientReadiness and reloaded under their corresponding semantic
// names. Calls, argument order, branches, memory effects outside this frame,
// and every later instruction are identical; only the private stack-home
// permutation differs.


long TribeMPSetupScreen::handle_user_command(unsigned int command, long param)
{
    char message[260];
    int ready;
    unsigned long user6, user2, user7, user3, user1, user4;

    if (rge_base_game->singlePlayerGame()) {
        return 1;
    }

    switch (command) {
    case 0x17BB:  // COMM_SHARED_DATA_SENT
        L->Log("$$$ USER_COMMAND: COMM_SHARED_DATA_SENT (%d,%d)", command, param);
        if (comm->IsHost()) {
            int i = 0;
            if (rge_base_game->numberPlayers() > 0) {
                do {
                    if (((TRIBE_Game*)rge_base_game)->civilization(i) >= 0x32) {
                        L->Log("$$$ HOST RESET CIV+50");
                        ((TRIBE_Game*)rge_base_game)->setCivilization(i,
                            ((TRIBE_Game*)rge_base_game)->civilization(i) - 0x32);
                        this->resend_game_options = 1;
                    }
                    if (rge_base_game->playerTeam(i) >= 0x32) {
                        L->Log("$$$ HOST RESET TEAM+50");
                        rge_base_game->setPlayerTeam(i, rge_base_game->playerTeam(i) - 0x32);
                        this->resend_game_options = 1;
                    }
                    ++i;
                } while (i < rge_base_game->numberPlayers());
            }
        }
        return 1;

    case 0x17A4:  // COMM_UPDATE_PLAYERS
        L->Log("$$$ USER_COMMAND: COMM_UPDATE_PLAYERS (%d,%d)", command, param);
        {
            int changed = 0;
            if (comm->IsHost() && this->sent_cd_status == 0) {
                this->sent_cd_status = 1;
                if (rge_base_game->check_for_cd(0)) {
                    changed = 1;
                    rge_base_game->setPlayerHasCD(comm->WhoAmI() - 1, 1);
                }
            }
            if (comm->IsHost()) {
                int i = 0;
                long* checksum = this->scenarioCheckSum;
                int player;
                do {
                    player = i + 1;
                    int humanity = comm->GetPlayerHumanity(player);
                    if (comm->WhoAmI() != player && humanity == 2) {
                        comm->GetClientReadiness(player, (int*)message,
                                                 &user3, &user6, &user7,
                                                 &user1, &user4, (unsigned long*)&ready, &user2);
                        if (user3 != 0 && user3 != ((TRIBE_Game*)rge_base_game)->civilization(i)) {
                            ((TRIBE_Game*)rge_base_game)->setCivilization(i, user3);
                            changed = 1;
                        }
                        if (user6 != 0) {
                            int sp = user6 - 1;
                            if (sp != ((TRIBE_Game*)rge_base_game)->scenarioPlayer(i)) {
                                ((TRIBE_Game*)rge_base_game)->setScenarioPlayer(i, sp);
                                changed = 1;
                            }
                        }
                        if (user7 != 0) {
                            if (user7 == 1) {
                                if (rge_base_game->playerHasCD(i) == 1) {
                                    rge_base_game->setPlayerHasCD(i, 0);
                                    changed = 1;
                                }
                            } else if (user7 == 2) {
                                if (rge_base_game->playerHasCD(i) == 0) {
                                    rge_base_game->setPlayerHasCD(i, 1);
                                    changed = 1;
                                }
                            }
                        }
                        if (user1 != 0 && user1 != ((TRIBE_Game*)rge_base_game)->playerColor(i)) {
                            ((TRIBE_Game*)rge_base_game)->setPlayerColor(i, user1);
                            changed = 1;
                        }
                        if (user4 != 0 && user4 != rge_base_game->playerTeam(i)) {
                            rge_base_game->setPlayerTeam(i, user4);
                            changed = 1;
                        }
                        if (ready != 0) {
                            *checksum = ready;
                        }
                        if (user2 != 0) {
                            rge_base_game->setPlayerVersion(i, (unsigned char)user2);
                            changed = 1;
                        }
                    } else if (humanity != 2 && humanity != 4) {
                        int r = debug_rand("C:\\msdev\\work\\age1_x1\\scr_mps.cpp", 0x6D6) % 16 + 1;
                        if (((TRIBE_Game*)rge_base_game)->civilization(i) != r) {
                            ((TRIBE_Game*)rge_base_game)->setCivilization(i, r);
                            changed = 1;
                        }
                        if (((TRIBE_Game*)rge_base_game)->scenarioPlayer(i) != i) {
                            ((TRIBE_Game*)rge_base_game)->setScenarioPlayer(i, i);
                            changed = 1;
                        }
                        if (rge_base_game->playerHasCD(i)) {
                            rge_base_game->setPlayerHasCD(i, 0);
                            changed = 1;
                        }
                        if (((TRIBE_Game*)rge_base_game)->playerColor(i) != this->defaultColor[i]) {
                            ((TRIBE_Game*)rge_base_game)->setPlayerColor(i, this->defaultColor[i]);
                            changed = 1;
                        }
                        if (rge_base_game->playerTeam(i) != 1) {
                            rge_base_game->setPlayerTeam(i, 1);
                            changed = 1;
                        }
                        if (rge_base_game->playerVersion(i) != 0) {
                            rge_base_game->setPlayerVersion(i, 0);
                            changed = 1;
                        }
                        *checksum = 0;
                    }
                    checksum++;
                    i = player;
                } while (player < 8);
                if (changed) {
                    rge_base_game->send_game_options();
                    this->resend_game_options = 0;
                }
            }
            this->fillPlayers();
            this->set_redraw((TPanel::RedrawMode)1);
            return 1;
        }

    case 0x17D5:  // CHAT_RECEIVED
        L->Log("$$$ USER_COMMAND: CHAT_RECEIVED (%d,%d)", command, param);
        this->fillChat(param);
        return 1;

    case 0x17A6:  // COMM_UPDATE_PARAMS
        L->Log("$$$ USER_COMMAND: COMM_UPDATE_PARAMS (%d,%d)", command, param);
        rge_base_game->receive_game_options();
        {
            int i = 0;
            if (rge_base_game->numberPlayers() > 0) {
                do {
                    if (((TRIBE_Game*)rge_base_game)->civilization(i) >= 0x32) {
                        L->Log("$$$ CIV2>50");
                        ((TRIBE_Game*)rge_base_game)->setCivilization(i,
                            ((TRIBE_Game*)rge_base_game)->civilization(i) - 0x32);
                        if (i + 1 == comm->WhoAmI()) {
                            this->myCivilization = 0;
                            L->Log("$$$ RESETTING MYCIV2");
                        }
                    }
                    if (rge_base_game->playerTeam(i) >= 0x32) {
                        L->Log("$$$ TEAM2>50");
                        rge_base_game->setPlayerTeam(i, rge_base_game->playerTeam(i) - 0x32);
                        if (i + 1 == comm->WhoAmI()) {
                            this->myPlayerTeam = 0;
                            L->Log("$$$ RESETTING MYTEAM2");
                        }
                    }
                    ++i;
                } while (i < rge_base_game->numberPlayers());
            }
        }
        if (this->myScenarioPlayer != 0) {
            if (strcmp(this->saveScenarioName, rge_base_game->scenarioName()) != 0) {
                this->myScenarioPlayer = -1;
            }
        }
        this->updateSummary();
        if (!comm->IsHost()) {
            if (!(this->sent_cd_status != 0 &&
                  this->myScenarioChecksum == this->saveScenarioChecksum &&
                  comm->IsPlayerReady(comm->WhoAmI()) == this->i_am_ready)) {
                int checksum = this->myScenarioChecksum;
                this->sent_cd_status = 1;
                this->saveScenarioChecksum = checksum;
                comm->SetMyReadiness(this->i_am_ready, 0, 0,
                                     rge_base_game->check_for_cd(0) + 1, 0, 0, checksum, 1);
            }
        }
        return 1;

    case 0x17A7:  // COMM_LAUNCH_GAME
        L->Log("$$$ USER_COMMAND: COMM_LAUNCH_GAME (%d,%d)", command, param);
        chat->setWindowHandle(AppWnd);
        comm->SetWindowHandle(AppWnd);
        ((TRIBE_Game*)rge_base_game)->start_game(0);
        return 1;

    case 0x17A8:  // COMM_CANCEL_GAME
        L->Log("$$$ USER_COMMAND: COMM_CANCEL_GAME (%d,%d)", command, param);
        this->handleKickedPlayer(0);
        return 1;

    case 0x17A9:  // COMM_HOST_EXITED
        L->Log("$$$ USER_COMMAND: COMM_HOST_EXITED (%d,%d)", command, param);
        this->handleKickedPlayer(0);
        return 1;

    case 0x17B2:  // COMM_PLAYER_DROPPED
        L->Log("$$$ USER_COMMAND: COMM_PLAYER_DROPPED (%d,%d)", command, param);
        this->handleKickedPlayer(1);
        return 1;

    case 0x17AA:  // COMM_PLAYER_KICKED
        L->Log("$$$ USER_COMMAND: COMM_PLAYER_KICKED (%d,%d)", command, param);
        this->handleKickedPlayer(1);
        return 1;

    case 0x17B3:  // COMM_OTHER_PLAYER_DROPPED
        L->Log("$$$ USER_COMMAND: COMM_OTHER_PLAYER_DROPPED (%d,%d)", command, param);
        this->fillPlayers();
        return 1;

    case 0x17B7:  // COMM_PLAYER_SERVICE_ERROR
        L->Log("$$$ USER_COMMAND: COMM_PLAYER_SERVICE_ERROR (%d,%d)", command, param);
        sprintf(message + 4, this->get_string(0x25DE), comm->GetPlayerName(param));
        this->popupOKDialog(message + 4, 0, 0x1C2, 100);
        return 1;

    case 0x17B6:  // COMM_BAD_VERSION
        L->Log("$$$ USER_COMMAND: COMM_BAD_VERSION (%d,%d)", command, param);
        sprintf(message + 4, this->get_string(0x25DD), comm->GetPlayerName(param));
        this->popupOKDialog(message + 4, 0, 0x1C2, 100);
        return 1;

    case 0x17B9:  // COMM_HOST_BUSY
        L->Log("$$$ USER_COMMAND: COMM_HOST_BUSY (%d,%d)", command, param);
        if (comm->IsLobbyLaunched()) {
            this->cancelScreen(1);
        } else {
            this->handleKickedPlayer(0);
        }
        return 1;

    case 0x17AE:  // COMM_NO_LINK
        L->Log("$$$ USER_COMMAND: COMM_NO_LINK (%d,%d)", command, param);
        this->cancelScreen(0);
        return 1;

    default:
        L->Log("$$$ USER_COMMAND: UNKNOWN (%d, %d)", command, param);
        return 1;
    }
}

// PDB-order owner source: 004A37C0_handle_timer_command.cpp.

long TribeMPSetupScreen::handle_timer_command(unsigned int p0, long p1) { return 1; }

// PDB-order owner source: 004A37D0_fillPlayers.cpp.

// VA: 004A37D0 TribeMPSetupScreen::fillPlayers
// PDB donor: scr_mps.cpp:1940-2203
//
// Baseline reconstruction: preserve the proven player-panel arrays, the two
// source loops, and the natural typed panel/game/communications surfaces.
//
// Attempt log:
// - established the +0x490..+0x5F0 panel arrays and +0x72C/+0x738/+0x85C
//   fields; the natural typed baseline has the correct 0x14 frame and 116 calls.
// - corrected the panel integer/string virtual slots, +0x610 layout gap, and
//   setPlayerTeam(int,int); this removed the call-count and relocation gaps.
// - tested humanity/is_me declaration order, function-scope homes, pointer and
//   union reuse, and bool predicate forms.  Bool forms moved the whole register
//   basin and pointer/union forms either duplicated the clean code or grew the
//   frame; none fixed the original humanity stack home.
// - audited the packet's 116 calls: player/color/team/version calls, dropdown
//   line effects, and all virtual panel slots/arities are represented; the clean
//   candidate keeps the exact frame and call count.
// - corrected donor ABI spellings for const game queries, long dropdown indices,
//   and unsigned-long text colors; these are source-correct but codegen-neutral.
// - diagnostic volatile humanity reproduced the original humanity stack store
//   but added non-source volatile traffic; rolled back.
// - MATCH (2026-08): the basin-breaking fix was to stop reassigning humanity
//   mid-loop.  set_state_by_id takes a SEPARATE color temp (myPlayerColor or
//   playerColor(i)), so the top-of-loop humanity value stays spilled at
//   [esp+10h] while is_me earns EBP; the old single-variable form forced
//   humanity into EBP and reversed both homes.
// - the original mixes `is_me == 1` (cmp ebp,1) at the color/team/single-name
//   sites with plain `is_me` (test ebp,ebp) at the boolean sites; spelled both.
// - name_color is inverted vs naive reading: not-ready -> 0xFF, ready -> 0xFF00.
// - name-drop block: multiplayer branch inline first, single-player is_me==1
//   branch as the late je target (matches L2113-L2127 layout).
// - civ/scenarioPlayer mode!=2 blocks need the get_line/set_line call duplicated
//   in both arms so ecx=[drop] stays live across the if-arm and VC5 tail-merges
//   at `call get_line` (if-arm: push eax; jmp join).


void TribeMPSetupScreen::fillPlayers()
{
    if (rge_base_game->multiplayerGame() && comm->IsHost()) {
        int color2 = 0;
        TTextPanel** text1 = 0;
        int i = 0;
        if (rge_base_game->numberPlayers() > 0) {
            text1 = this->playerNameText;
            do {
                int player = i + 1;
                if (comm->IsPlayerReady(player) && text1[0]->text_color1 == 0xFF) {
                    int j = 0;
                    int inner_players = rge_base_game->numberPlayers();
                    if (inner_players > 0) {
                        do {
                            if (i != j && comm->IsPlayerReady(j + 1)) {
                                int other_color = ((TRIBE_Game*)rge_base_game)->playerColor(j);
                                int player_color = ((TRIBE_Game*)rge_base_game)->playerColor(i);
                                if (other_color == player_color) {
                                    L->Log("$$$ SETTING CIV/TEAM+50 (%d,%d)", i, j);
                                    int civ = ((TRIBE_Game*)rge_base_game)->civilization(i);
                                    ((TRIBE_Game*)rge_base_game)->setCivilization(j, civ + 0x32);
                                    int team = rge_base_game->playerTeam(i);
                                    rge_base_game->setPlayerTeam(j, team + 0x32);
                                    color2 = 1;
                                }
                            }
                            ++j;
                            inner_players = rge_base_game->numberPlayers();
                        } while (j < inner_players);
                    }
                }
                ++i;
                ++text1;
            } while (i < rge_base_game->numberPlayers());
        }
        if (color2 != 0) {
            rge_base_game->send_game_options();
        }
    }

    int i = 0;
    int players = rge_base_game->numberPlayers();
    if (players > 0) {
        do {
            int is_me;
            int humanity;
            if (rge_base_game->multiplayerGame()) {
                int player = i + 1;
                humanity = comm->GetPlayerHumanity(player);
                is_me = comm->WhoAmI() == player;
            } else if (i == 0) {
                humanity = 2;
                is_me = 1;
            } else {
                humanity = this->playerNameDrop[i]->get_id();
                is_me = 0;
            }

            if (!rge_base_game->multiplayerGame() || humanity != 2) {
                this->playerCDText[i]->set_active(0);
                this->playerVersionText[i]->set_active(0);
            } else {
                this->playerCDText[i]->set_active(rge_base_game->playerHasCD(i));
                if (comm->IsHost() || rge_base_game->playerVersion(0) != 0) {
                    this->playerVersionText[i]->set_text(rge_base_game->playerVersionString(i));
                    this->playerVersionText[i]->set_active(1);
                } else if (i == 0) {
                    this->playerVersionText[0]->set_text(rge_base_game->playerVersionString(0));
                    this->playerVersionText[0]->set_active(1);
                } else if (is_me) {
                    rge_base_game->setPlayerVersion(i, 1);
                    this->playerVersionText[i]->set_text(rge_base_game->playerVersionString(i));
                    this->playerVersionText[i]->set_active(1);
                } else {
                    this->playerVersionText[i]->set_active(0);
                }
            }

            int color;
            if (is_me == 1 && this->myPlayerColor != 0) {
                color = this->myPlayerColor;
            } else {
                color = ((TRIBE_Game*)rge_base_game)->playerColor(i);
            }
            this->playerColor[i]->set_state_by_id(color);
            int state = this->playerColor[i]->get_state();
            char* text1;
            char* text2;
            unsigned long color1;
            unsigned long color2;
            this->playerColor[i]->get_text((short)state, &text1, &text2);
            this->playerColor[i]->get_text_color((short)state, &color1, &color2);
            this->playerColorText[i]->set_text(text1);
            this->playerColorText[i]->set_text_color(color1, color2);
            this->playerColor[i]->set_active(0);
            this->playerColorText[i]->set_active(0);

            if ((rge_base_game->multiplayerGame() && is_me && this->i_am_ready == 0) ||
                (rge_base_game->singlePlayerGame() && is_me && this->numberAnyPlayers > 1)) {
                this->playerColor[i]->set_active(1);
                this->playerColor[i]->set_disabled(0);
            } else if (humanity == 2) {
                this->playerColorText[i]->set_active(1);
            }

            if (is_me == 1 && this->myPlayerTeam != 0) {
                this->playerTeam[i]->set_state((short)this->myPlayerTeam - 1);
            } else {
                int team = rge_base_game->playerTeam(i);
                if (team >= 0x32) {
                    team -= 0x32;
                }
                this->playerTeam[i]->set_state(team - 1);
            }

            state = this->playerTeam[i]->get_state();
            this->playerTeam[i]->get_text((short)state, &text1, &text2);
            this->playerTeamText[i]->set_text(text1);
            this->playerTeam[i]->set_active(0);
            this->playerTeamText[i]->set_active(0);

            if ((rge_base_game->multiplayerGame() &&
                 ((is_me && this->i_am_ready == 0) ||
                  (comm->IsHost() && humanity == 4 && this->i_am_ready == 0))) ||
                (rge_base_game->singlePlayerGame() && (is_me || humanity == 4))) {
                this->playerTeam[i]->set_active(1);
                this->playerTeam[i]->set_disabled(0);
            } else if (humanity == 2 || humanity == 4) {
                this->playerTeamText[i]->set_active(1);
            }

            if (rge_base_game->multiplayerGame()) {
                int name_color;
                if (humanity == 2 && !comm->IsPlayerReady(i + 1)) {
                    name_color = 0xFF;
                } else {
                    name_color = 0xFF00;
                }
                this->playerNameDrop[i]->set_val_text_color(name_color, 0);
                this->playerNameText[i]->set_text_color(name_color, 0);
            }

            if (rge_base_game->multiplayerGame()) {
                if (this->playerNameDrop[i]->get_id(0) == 2) {
                    this->playerNameDrop[i]->delete_line(0);
                }
                if (humanity == 2) {
                    this->playerNameDrop[i]->insert_line(0, comm->GetPlayerName(i + 1), humanity);
                }
                this->playerNameDrop[i]->set_line(this->playerNameDrop[i]->get_line(humanity));
                this->playerNameText[i]->set_text(this->playerNameDrop[i]->get_text());
            } else {
                if (is_me == 1) {
                    this->playerNameText[i]->set_text((long)0x25B3);
                } else {
                    this->playerNameText[i]->set_text(this->playerNameDrop[i]->get_text());
                }
            }

            if (this->playerCivDrop[i]->mode != 2) {
                if (is_me == 1 && this->myCivilization != 0) {
                    this->playerCivDrop[i]->set_line(
                        this->playerCivDrop[i]->get_line(this->myCivilization));
                } else {
                    int civ = ((TRIBE_Game*)rge_base_game)->civilization(i);
                    if (civ >= 0x32) {
                        civ -= 0x32;
                    }
                    this->playerCivDrop[i]->set_line(
                        this->playerCivDrop[i]->get_line(civ));
                }
            }
            this->playerCivText[i]->set_text(this->playerCivDrop[i]->get_text());

            if (this->scenarioPlayerDrop[i]->mode != 2) {
                if (is_me == 1 && this->myScenarioPlayer != -1) {
                    this->scenarioPlayerDrop[i]->set_line(
                        this->scenarioPlayerDrop[i]->get_line(this->myScenarioPlayer));
                } else {
                    int scenario_player = ((TRIBE_Game*)rge_base_game)->scenarioPlayer(i);
                    this->scenarioPlayerDrop[i]->set_line(
                        this->scenarioPlayerDrop[i]->get_line(scenario_player));
                }
            }
            this->scenarioPlayerText[i]->set_text(this->scenarioPlayerDrop[i]->get_text());

            if (rge_base_game->multiplayerGame() && comm->IsHost() && !is_me) {
                this->playerNameDrop[i]->set_active(1);
                this->playerNameText[i]->set_active(0);
            } else {
                this->playerNameDrop[i]->set_active(0);
                this->playerNameText[i]->set_active(1);
            }
            this->playerCivDrop[i]->set_active(0);
            this->playerCivText[i]->set_active(0);

            if ((rge_base_game->multiplayerGame() &&
                 ((is_me && this->i_am_ready == 0) ||
                  (comm->IsHost() && humanity == 4 && this->i_am_ready == 0))) ||
                (rge_base_game->singlePlayerGame() && (is_me || humanity == 4))) {
                this->playerCivDrop[i]->set_active(1);
            } else if (humanity == 2 || humanity == 4) {
                this->playerCivText[i]->set_active(1);
            }
            this->scenarioPlayerDrop[i]->set_active(0);
            this->scenarioPlayerText[i]->set_active(0);

            ++i;
            players = rge_base_game->numberPlayers();
        } while (i < players);
    }

    if (i < 8) {
        TDropDownPanel** p = this->playerCivDrop + i;
        int remaining = 8 - i;
        do {
            p[-8]->set_active(0);
            p[0]->set_active(0);
            p[8]->set_active(0);
            p[-24]->set_active(0);
            p[-40]->set_active(0);
            p[-16]->set_active(0);
            p[-32]->set_active(0);
            p[-80]->set_active(0);
            p[-72]->set_active(0);
            p[-64]->set_active(0);
            p[-56]->set_active(0);
            p[-48]->set_active(0);
            ++p;
            --remaining;
        } while (remaining != 0);
    }

    this->fillPlayerColors();
}

// PDB-order owner source: 004A4100_fillChat.cpp.

// VA: 004A4100 TribeMPSetupScreen::fillChat
// scr_mps.cpp lines 2209-2232
//
// Attempt log:
// - Initial scratch used free-function wrappers and chatBox at +0; behavior was close but call/register surface was wrong.
// - SpruceGlow MATCH: use natural member calls and place `chatBox` at +0x618. Keep `need_scroll` as an int computed
//   from `lines > 0 && bot_line == lines - 1`; VC5 uses EDI and preserves the expected reloads of `chatBox`.
// Result: MATCH locally with `python tools/check_function.py --va 004A4100`.


void TribeMPSetupScreen::fillChat(int n) {
    if (!rge_base_game->singlePlayerGame()) {
        int lines = this->chatBox->numberLines();
        int need_scroll = (lines > 0 && this->chatBox->bot_line == lines - 1);
        if (lines >= 100) {
            this->chatBox->delete_line(0);
        }
        this->chatBox->word_wrap_append(chat->GetChatMsg(n));
        if (need_scroll) {
            this->chatBox->scroll(7, 0, 1);
        }
    }
}

// PDB-order owner source: 004A4190_updateSummary.cpp.

// VA: 004A4190 TribeMPSetupScreen::updateSummary
// PDB source: scr_mps.cpp lines 2241-2686
//
// Baseline reconstruction: named summary buffers, scenario/player state, and
// the settingText/scenarioPlayerDrop panel arrays.  The source follows the
// period C++ structure suggested by the executable: scenario reload first,
// random/scenario player setup, then the ordered summary-panel writes.
//
// Exact recovery notes:
// - Canonical fields include scenarioPlayerDrop at +5F0, scenarioName at
//   +624, settingText at +62C, and the scenario state at +728 through +888.
// - The authentic local order is str1, str2, file_name, str3, and file_info.
//   Each call uses the declared buffer base. The first _findfirst uses the
//   file_name storage as an existence-only scratch record.
// - The scoped player index starts before scenarioInfo cleanup. A reset before
//   the active-player scan keeps the executable's shared zero value.
// - The random setup clears settingsFixed before it publishes both counts.
//   The save-name branch writes the nonzero random case first.
// - BINARY NOTE: both game-kind summary paths publish through scenarioName at
//   +624. settingText[0] is a different panel.
// - Victory type 9 always selects string 0x10EC. It is not the default case.
// - The checksum array uses a fixed source loop. Direct memset changes VC5's
//   address setup order.
// - The first exact transition also removed one extra map-setting increment
//   and used the shipped `scenarioPlayerCount >= 3` test.
// - Walkback kept exact output after removing extra same-TU includes, narrowing
//   player_index scope, and replacing field dependencies with literal zeros.
//   Removing the player-index reset, changing save-branch order, using memset,
//   or publishing through settingText[0] broke exact output.
// - Fresh authoritative validation: 3522 bytes, frame 0x534, 150 ordered calls,
//   qualified owner, Result: MATCH, and 0.0000%.


void TribeMPSetupScreen::updateSummary()
{
    int changed = 0;
    char str1[256];
    char str2[256];
    // The first existence-only _findfirst uses file_name as its _finddata_t
    // scratch window. The extra tail reaches str3 without overlap.
    char file_name[0x118];
    char str3[256];
    struct _finddata_t file_info;
    char* scenario_dir;
    char* scenario_name;

    if (rge_base_game->scenarioGame()) {
        if (this->saveRandomGame == 0) {
            if (strcmp(rge_base_game->scenarioName(), this->saveScenarioName) != 0) {
                changed = 1;
            }
        } else {
            changed = 1;
        }
    } else if (this->saveRandomGame == 0) {
        changed = 1;
    }

    if (changed != 0) {
        if (rge_base_game->scenarioGame()) {
            int player_index = 0;
            if (this->scenarioInfo != 0) {
                delete this->scenarioInfo;
                this->scenarioInfo = 0;
            }

            scenario_dir = rge_base_game->prog_info->scenario_dir;
            scenario_name = rge_base_game->scenarioName();
            sprintf(str1, "%s%s.scn", scenario_dir, scenario_name);
            long handle = _findfirst(str1,
                                     (struct _finddata_t*)file_name);
            if (handle == -1) {
                sprintf(str1, "%s.scx",
                        rge_base_game->scenarioName());
            } else {
                sprintf(str1, "%s.scn",
                        rge_base_game->scenarioName());
            }

            if (str1[0] != '.') {
                this->scenarioInfo = (T_Scenario*)
                    rge_base_game->get_scenario_info(str1, 0);
            }

            if (this->scenarioInfo == 0) {
                rge_base_game->setScenarioGame(0);
            } else {
                for (int empty_index = 0; empty_index < 8; ++empty_index) {
                    this->scenarioPlayerDrop[empty_index]->empty_list();
                }

                this->settingsFixed = this->scenarioInfo->any_sp_victory();
                player_index = 0;
                this->numberAnyPlayers = 0;
                this->scenarioPlayerCount = 0;

                for (; player_index < 9; ++player_index) {
                    if (((RGE_Scenario*)this->scenarioInfo)->Get_player_Active(player_index) != 0) {
                        ++this->scenarioPlayerCount;
                        sprintf(str2, "%d", player_index + 1);
                        if (rge_base_game->multiplayerGame() ||
                            (rge_base_game->singlePlayerGame() &&
                             ((RGE_Scenario*)this->scenarioInfo)->Get_player_Type(player_index) == 1)) {
                            ++this->numberAnyPlayers;
                            for (int append_index = 0; append_index < 8; ++append_index) {
                                this->scenarioPlayerDrop[append_index]->append_line(
                                    str2, player_index);
                            }
                        }
                    }
                }

                int player = -1;
                for (int color_index = 0; color_index < 8; ++color_index) {
                    do {
                        ++player;
                        if (player == 9) {
                            player = 0;
                        }
                    } while (((RGE_Scenario*)this->scenarioInfo)->Get_player_Active(player) == 0);

                    this->defaultColor[color_index] = (unsigned char)player + 1;
                    ((TRIBE_Game*)rge_base_game)->setScenarioPlayer(color_index, player);
                    ((TRIBE_Game*)rge_base_game)->setPlayerColor(
                        color_index, this->defaultColor[color_index]);
                    rge_base_game->setPlayerTeam(color_index, 1);
                }
            }
        }

        if (rge_base_game->randomGame()) {
            for (int random_empty_index = 0; random_empty_index < 8; ++random_empty_index) {
                this->scenarioPlayerDrop[random_empty_index]->empty_list();
            }
            this->settingsFixed = 0;
            this->scenarioPlayerCount = 8;
            this->numberAnyPlayers = 8;

            for (int random_index = 0; random_index < 8; ++random_index) {
                this->defaultColor[random_index] = (unsigned char)random_index + 1;
                ((TRIBE_Game*)rge_base_game)->setScenarioPlayer(random_index, random_index);
                ((TRIBE_Game*)rge_base_game)->setPlayerColor(
                    random_index, this->defaultColor[random_index]);
                rge_base_game->setPlayerTeam(random_index, 1);
                sprintf(str2, "%d", random_index + 1);
                for (int random_append_index = 0; random_append_index < 8;
                     ++random_append_index) {
                    this->scenarioPlayerDrop[random_append_index]->append_line(
                        str2, random_index);
                }
            }
        }

        if (rge_base_game->singlePlayerGame()) {
            this->setupSinglePlayerPlayers();
        }

        this->saveRandomGame = rge_base_game->randomGame();
        if (this->saveRandomGame != 0) {
            this->saveScenarioName[0] = 0;
        } else {
            strcpy(this->saveScenarioName, rge_base_game->scenarioName());
        }

        for (int checksum_index = 0; checksum_index < 8; ++checksum_index) {
            this->scenarioCheckSum[checksum_index] = 0;
        }

        if (rge_base_game->scenarioGame()) {
            scenario_dir = rge_base_game->prog_info->scenario_dir;
            scenario_name = rge_base_game->scenarioName();
            sprintf(file_name, "%s%s.scn", scenario_dir, scenario_name);
            long handle = _findfirst(file_name, &file_info);
            if (handle == -1) {
                sprintf(file_name, "%s.scx",
                        rge_base_game->scenarioName());
            } else {
                sprintf(file_name, "%s.scn",
                        rge_base_game->scenarioName());
            }
            this->myScenarioChecksum = rge_base_game->get_scenario_checksum(file_name);
        } else {
            this->myScenarioChecksum = 0;
        }
    }

    int setting;
    for (int i = 0; i < 20; ++i) {
        this->settingText[i]->set_active(0);
    }

    if (rge_base_game->scenarioGame()) {
        sprintf(str2, this->get_string(0x25ED),
                rge_base_game->scenarioName());
        this->scenarioName->set_text(str2);
        setting = 3;
    } else {
        if (((TRIBE_Game*)rge_base_game)->deathMatch()) {
            this->get_string(0x2617, str1, 0x100);
        } else {
            this->get_string(0x25B5, str1, 0x100);
        }
        sprintf(str2, this->get_string(0x25ED), str1);
        this->scenarioName->set_text(str2);
        setting = 1;
    }

    if (rge_base_game->randomGame()) {
        switch (((TRIBE_Game*)rge_base_game)->mapSize()) {
        case 0: strcpy(str1, this->get_string(0x2973)); break;
        case 1: strcpy(str1, this->get_string(0x2974)); break;
        case 2: strcpy(str1, this->get_string(0x2975)); break;
        case 3: strcpy(str1, this->get_string(0x2976)); break;
        case 4: strcpy(str1, this->get_string(0x2977)); break;
        case 5: strcpy(str1, this->get_string(0x2978)); break;
        }
        sprintf(str2, this->get_string(0x25DA), str1);
        this->settingText[setting]->set_text(str2);
        this->settingText[setting]->set_active(1);
        ++setting;

        switch (((TRIBE_Game*)rge_base_game)->mapType()) {
        case 0: strcpy(str1, this->get_string(0x296A)); break;
        case 1: strcpy(str1, this->get_string(0x296B)); break;
        case 2: strcpy(str1, this->get_string(0x296C)); break;
        case 3: strcpy(str1, this->get_string(0x296D)); break;
        case 4: strcpy(str1, this->get_string(0x296E)); break;
        case 5: strcpy(str1, this->get_string(0x296F)); break;
        case 6: strcpy(str1, this->get_string(0x2970)); break;
        case 7: strcpy(str1, this->get_string(0x2971)); break;
        case 8: strcpy(str1, this->get_string(0x2972)); break;
        }
        sprintf(str2, this->get_string(0x25B6), str1);
        this->settingText[setting]->set_text(str2);
        this->settingText[setting]->set_active(1);
        ++setting;
    }

    if (rge_base_game->scenarioGame()) {
        if (this->settingsFixed == 0 && this->scenarioPlayerCount != 2) {
            sprintf(str2, "%s %d - %d", this->get_string(0x25B7),
                    2, this->scenarioPlayerCount);
        } else {
            sprintf(str2, "%s %d", this->get_string(0x25B7),
                    this->scenarioPlayerCount);
        }
    } else {
        sprintf(str2, "%s 2 - 8", this->get_string(0x25B7));
    }
    this->settingText[setting]->set_text(str2);
    this->settingText[setting]->set_active(1);
    ++setting;

    switch (((TRIBE_Game*)rge_base_game)->victoryType()) {
    case 1:
        strcpy(str1, this->get_string(0x10E1));
        goto victory_plain;
    case 7:
        strcpy(str1, this->get_string(0x10E9));
        goto victory_amount;
    case 8:
        strcpy(str1, this->get_string(0x10EA));
victory_amount:
        sprintf(str2, this->get_string(0x25BE), str1,
                ((TRIBE_Game*)rge_base_game)->victoryAmount());
        goto victory_done;
    case 9:
        strcpy(str1, this->get_string(0x10EC));
        goto victory_plain;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    default:
        if (rge_base_game->randomGame()) {
            strcpy(str1, this->get_string(0x10EC));
        } else {
            strcpy(str1, this->get_string(0x10E7));
        }
        goto victory_plain;
    victory_plain:
        sprintf(str2, this->get_string(0x25BC), str1);
victory_done:
        break;
    }
    this->settingText[setting]->set_text(str2);
    this->settingText[setting]->set_active(1);
    ++setting;

    int age = ((TRIBE_Game*)rge_base_game)->startingAge();
    if (age == 0) {
        this->get_string(0x10E7, str1, 0x100);
    } else if (age == 1) {
        this->get_string(0x106E, str1, 0x100);
    } else {
        this->get_string(age + 0x1067, str1, 0x100);
    }
    sprintf(str2, this->get_string(0x25E4), str1);
    this->settingText[setting]->set_text(str2);
    this->settingText[setting]->set_active(1);
    ++setting;

    int resources = ((TRIBE_Game*)rge_base_game)->resourceLevel();
    if (resources == 0) {
        this->get_string(0x10E7, str1, 0x100);
    } else {
        this->get_string(resources + 0x25E5, str1, 0x100);
    }
    sprintf(str2, this->get_string(0x25E5), str1);
    this->settingText[setting]->set_text(str2);
    this->settingText[setting]->set_active(1);
    ++setting;

    rge_base_game->difficulty();
    this->get_string(rge_base_game->difficulty() + 0x2BD0, str1, 0x100);
    this->get_string(0x25E0, str2, 0x100);
    sprintf(str3, str2, str1);
    this->settingText[setting]->set_text(str3);
    this->settingText[setting]->set_active(1);
    ++setting;

    if (((TRIBE_Game*)rge_base_game)->randomizePositions()) {
        this->get_string(0xFA4, str1, 0x100);
    } else {
        this->get_string(0xFA3, str1, 0x100);
    }
    sprintf(str2, this->get_string(0x25E9), str1);
    this->settingText[setting]->set_text(str2);
    this->settingText[setting]->set_active(1);
    ++setting;

    if (rge_base_game->fullVisibility()) {
        strcpy(str1, this->get_string(0xFA3));
    } else {
        strcpy(str1, this->get_string(0xFA4));
    }
    sprintf(str2, this->get_string(0x25B8), str1);
    this->settingText[setting]->set_text(str2);
    this->settingText[setting]->set_active(1);
    ++setting;

    if (((TRIBE_Game*)rge_base_game)->fullTechTree()) {
        this->get_string(0xFA3, str1, 0x100);
    } else {
        this->get_string(0xFA4, str1, 0x100);
    }
    sprintf(str2, this->get_string(0x25EC), str1);
    this->settingText[setting]->set_text(str2);
    this->settingText[setting]->set_active(1);
    ++setting;

    if (rge_base_game->multiplayerGame()) {
        if (rge_base_game->allowCheatCodes()) {
            strcpy(str1, this->get_string(0xFA3));
        } else {
            strcpy(str1, this->get_string(0xFA4));
        }
        sprintf(str2, this->get_string(0x25BB), str1);
        this->settingText[setting]->set_text(str2);
        this->settingText[setting]->set_active(1);
        ++setting;
    }

    if (rge_base_game->multiplayerGame()) {
        this->get_string(((TRIBE_Game*)rge_base_game)->mpPathFinding() + 0x260E,
                         str1, 0x100);
    } else {
        this->get_string(rge_base_game->pathFinding() + 0x260E,
                         str1, 0x100);
    }
    sprintf(str2, this->get_string(0x25F1), str1);
    this->settingText[setting]->set_text(str2);
    this->settingText[setting]->set_active(1);
    ++setting;

    sprintf(str2, this->get_string(0x25F0),
            ((TRIBE_Game*)rge_base_game)->popLimit());
    this->settingText[setting]->set_text(str2);
    this->settingText[setting]->set_active(1);

    if (rge_base_game->singlePlayerGame()) {
        if (rge_base_game->scenarioGame() == 0 ||
            (this->settingsFixed == 0 && this->scenarioPlayerCount >= 3)) {
            this->numberPlayersTitle->set_active(1);
            this->numberPlayersDrop->set_active(1);
        } else {
            this->numberPlayersTitle->set_active(0);
            this->numberPlayersDrop->set_active(0);
        }
    }

    this->fillPlayers();
}

// PDB-order owner source: 004A4FC0_kickPlayer.cpp.

// first pass: straight stack-buffer helper with the comm/name/string calls in packet order
// if this sticks, the remaining work is likely just the exact local-buffer and call-site shape

void TribeMPSetupScreen::kickPlayer(int param_1) {
    char text[256];

    this->playerToKick = param_1;
    sprintf(text, this->get_string(0x25C8), comm->GetPlayerName((unsigned int)param_1));
    this->popupYesNoDialog(text, (char*)0x5867E8, 0x1C2, 0x64);
}

// PDB-order owner source: 004A5020_handleKickedPlayer.cpp.

// VA: 004A5020 handleKickedPlayer (55B)
// Match the neg/sbb/add trick for conditional decrement


void TribeMPSetupScreen::handleKickedPlayer(int player_index) {
    this->cancelScreen(0);
    TEasy_Panel* panel = (TEasy_Panel*)panel_system.currentPanel();
    if (panel != 0) {
        ((TEasy_Panel*)panel)->popupOKDialog(
            0x25CA + (player_index != 0 ? -1 : 0), 0, 0x1C2, 100);
    }
}

// PDB-order owner source: 004A5060_activateVictoryPanels.cpp.

// 004A5060 activateVictoryPanels
// 181 bytes, __thiscall, TribeMPSetupScreen method
// The named TPanel surface preserves the proven +0x14 and +0xE4 slots.


void TribeMPSetupScreen::activateVictoryPanels() {
    int id = victoryTypeDrop->get_id();
    if (id == 1 || victoryTypeDrop->get_id() == 0) {
        victoryAmountLabel->set_active(0);
        victoryAmountInput->set_active(0);
    } else {
        victoryAmountLabel->set_active(1);
        victoryAmountInput->set_active(1);
        switch (victoryTypeDrop->get_id()) {
        case 2:
            victoryAmountLabel->set_text(0x25CB);
            return;
        case 3:
        case 4:
        case 5:
            victoryAmountLabel->set_text(0x25CC);
            return;
        case 6:
            victoryAmountLabel->set_text(0x25CD);
            return;
        }
    }
}

// PDB-order owner source: 004A5130_setupTabOrder.cpp.

// 004A5130 TribeMPSetupScreen::setupTabOrder
// 223 bytes, __thiscall, scr_mps.cpp lines 2752-2787
// The named panel surface preserves the proven +0xC8 tab-order slot.


void TribeMPSetupScreen::setupTabOrder()
{
    TPanel* tabList[4];

    if (rge_base_game->singlePlayerGame()) {
        tabList[0] = startButton;
        tabList[1] = cancelButton;
        tabList[2] = gameSettingsButton;
        set_tab_order(tabList, 3);
        set_curr_child(startButton);
        return;
    }

    tabList[0] = chatInput;
    if (gameSettingsButton) {
        tabList[1] = startButton;
        tabList[2] = cancelButton;
        tabList[3] = gameSettingsButton;
        set_tab_order(tabList, 4);
        set_curr_child(chatInput);
        return;
    }

    tabList[1] = ready_button;
    tabList[2] = cancelButton;
    set_tab_order(tabList, 3);
    set_curr_child(chatInput);
}

// PDB-order owner source: 004A5210_setupSinglePlayerPlayers.cpp.

// VA: 004A5210 setupSinglePlayerPlayers
// PDB donor: scr_mps.cpp:2793-2886
//
// Natural reconstruction of the single-player/scenario player initialization.
// The screen fields and the narrow game/communications setter parameters use
// the period ABI surfaces established by same-TU donors.
//
// Recovery notes:
// - PDB evidence assigns this method to scr_mps.cpp lines 2793-2886.
// - The screen owns scenarioPlayerCount (+0x728) and scenarioInfo (+0x848).
// - The game and communications objects own the player publication calls.
// - The executable uses int setter arguments and PLAYERHUMANITY values.
// - The executable publishes scenario players, civilizations, colors, teams,
//   and humanity in the order shown below.
// - BINARY NOTE: the decompiler-only first_any_player copy is not needed.
//   first_any_civ carries that value through the later lookup and publication.
// - Removing that copy changed the saved-register assignment to the original:
//   EBX holds this and EBP holds the active-player count.
// - Exact-finish walkback restored the copy and returned to the 15-byte drift.
// - Removing the screen pointer alias also kept the exact result.
// - Fresh exact check: 556 bytes, 27 ordered calls, correct owner, and 0 bytes
//   differ. The checker reported MATCH and 0.0000%.


void TribeMPSetupScreen::setupSinglePlayerPlayers() {
    int first_any_civ;
    int first_any_color;
    int first_any_color_index;
    if (rge_base_game->scenarioGame() != 0) {
        first_any_civ = -1;
        first_any_color = -1;
        first_any_color_index = -1;

        if (this->scenarioInfo != 0) {
            int player_count = 0;
            int scenario_player = 0;
            do {
                if (this->scenarioInfo->Get_player_Active(scenario_player) != 0) {
                    ((TRIBE_Game*)rge_base_game)->setScenarioPlayer(
                        player_count, scenario_player);
                    int civilization =
                        this->scenarioInfo->Get_player_Civ(scenario_player);
                    ((TRIBE_Game*)rge_base_game)->setCivilization(
                        player_count, civilization);
                    ((TRIBE_Game*)rge_base_game)->setPlayerColor(
                        player_count, scenario_player + 1);

                    if (this->scenarioInfo->Get_player_Type(scenario_player) == 1 &&
                        first_any_civ == -1) {
                        first_any_civ = scenario_player;
                        first_any_color =
                            this->scenarioInfo->Get_player_Civ(scenario_player);
                        first_any_color_index = scenario_player + 1;
                    }
                    ++player_count;
                }
                ++scenario_player;
            } while (scenario_player < 9);
        }

        rge_base_game->setNumberPlayers(this->scenarioPlayerCount);
        if (first_any_civ != -1) {
            int player = 1;
            if (this->scenarioPlayerCount > 1) {
                while (player < this->scenarioPlayerCount) {
                    if (((TRIBE_Game*)rge_base_game)->scenarioPlayer(player) ==
                        first_any_civ) {
                        int scenario_player =
                            ((TRIBE_Game*)rge_base_game)->scenarioPlayer(0);
                        ((TRIBE_Game*)rge_base_game)->setScenarioPlayer(
                            player, scenario_player);
                        int civilization =
                            ((TRIBE_Game*)rge_base_game)->civilization(0);
                        ((TRIBE_Game*)rge_base_game)->setCivilization(
                            player, civilization);
                        int color =
                            ((TRIBE_Game*)rge_base_game)->playerColor(0);
                        ((TRIBE_Game*)rge_base_game)->setPlayerColor(
                            player, color);
                        break;
                    }
                    ++player;
                }
            }

            ((TRIBE_Game*)rge_base_game)->setScenarioPlayer(0, first_any_civ);
            ((TRIBE_Game*)rge_base_game)->setCivilization(0, first_any_color);
            ((TRIBE_Game*)rge_base_game)->setPlayerColor(
                0, first_any_color_index);
        }
    } else {
        int player = 0;
        do {
            int civilization =
                debug_rand("C:\\msdev\\work\\age1_x1\\scr_mps.cpp", 0xB31) %
                    16 + 1;
            ((TRIBE_Game*)rge_base_game)->setCivilization(player, civilization);
            ((TRIBE_Game*)rge_base_game)->setPlayerColor(
                player, player + 1);
            player = player + 1;
        } while (player < 8);
    }

    int player = 0;
    do {
        rge_base_game->setPlayerTeam(player, 1);
        ++player;
    } while (player < 8);

    comm->SetPlayerHumanity(1, ME_HUMAN);
    player = 2;
    do {
        comm->SetPlayerHumanity(player, ME_COMPUTER);
        ++player;
    } while (player <= 8);
    comm->SetPlayerHumanity(9, ME_ABSENT);
    this->fillNumberPlayers();
}

// PDB-order owner source: 004A5440_fillNumberPlayers.cpp.

// VA: 004A5440 TribeMPSetupScreen::fillNumberPlayers()
// PDB source: scr_mps.cpp lines 2892-2904
// Default flags
//
// __thiscall: this in ecx, no stack params. void return.
// Loop filling dropdown panel with player counts.



void TribeMPSetupScreen::fillNumberPlayers() {
    this->numberPlayersDrop->empty_list();

    int max_players = this->scenarioPlayerCount;
    if (max_players >= 2) {
        char str[16];
        int i = 2;
        do {
            sprintf(str, "%d", i);
            this->numberPlayersDrop->append_line(str, i);
            i++;
        } while (i <= this->scenarioPlayerCount);
    }

    int num = rge_base_game->numberPlayers();
    int line = this->numberPlayersDrop->get_line(num);
    this->numberPlayersDrop->set_line(line);
}

// PDB-order owner source: 004A54C0_fillPlayerColors.cpp.

// VA: 004A54C0 TribeMPSetupScreen::fillPlayerColors
// PDB donor: scr_mps.cpp:2910-2943
//
// Baseline reconstruction: the screen owns eight color-button panels.  Each
// panel receives the currently eligible scenario players, with the fixed
// player-color palette selected by the inner index.
// Main-agent audit restored canonical scenario/game/screen destructor surfaces;
// emitted code remains exact.



void TribeMPSetupScreen::fillPlayerColors() {
    TButtonPanel** buttons = this->playerColor;
    int remaining = 8;
    char str[16];

    do {
        int player = 0;
        int state = 0;

        do {
            if (rge_base_game->scenarioGame() == 0 ||
                this->scenarioInfo == 0 ||
                (this->scenarioInfo->Get_player_Active(player) != 0 &&
                 (rge_base_game->singlePlayerGame() == 0 ||
                  this->scenarioInfo->Get_player_Type(player) == 1))) {
                sprintf(str, "%d", player + 1);
                buttons[0]->set_text((short)state, str);
                buttons[0]->set_id((short)state, player + 1, 0);

                switch (player) {
                case 0:
                    buttons[0]->set_text_color(state, 0xFF0000, 0);
                    break;
                case 1:
                    buttons[0]->set_text_color(state, 0x0000FF, 0);
                    break;
                case 2:
                    buttons[0]->set_text_color(state, 0x00FFFF, 0);
                    break;
                case 3:
                    buttons[0]->set_text_color(state, 0x284673, 0);
                    break;
                case 4:
                    buttons[0]->set_text_color(state, 0x0764F0, 0);
                    break;
                case 5:
                    buttons[0]->set_text_color(state, 0x00FF00, 0);
                    break;
                case 6:
                    buttons[0]->set_text_color(state, 0xB4B4B4, 0);
                    break;
                case 7:
                    buttons[0]->set_text_color(state, 0x93BF2B, 0);
                    break;
                }
                state++;
            }
            player++;
        } while (player < 8);

        buttons[0]->set_state_info((short)state);
        buttons++;
    } while (--remaining != 0);
}

// PDB-order owner source: 004A5610_TRIBE_Screen_Wait.cpp.

// 004A5610 TRIBE_Screen_Wait::TRIBE_Screen_Wait
// PDB source: scr_mps.cpp lines 2950-3225 (134 line records)
//
// Reconstruction notes:
// - Large /GX EH-framed screen constructor following the proven pattern of
//   the exact sibling ctor 004A71F0 (TribeSaveGameScreen): TScreenPanel base
//   ctor, compiler-emitted derived-vftable store, setup() guard writing +0xD8 on
//   failure, then panel creation and per-game-option text fill.
// - Text/button panels use vtable slots set_active(+0x14), set_positioning
//   (+0x18), set_text(+0xE8) through a local polymorphic TPanel view.
// - create_text/create_button/set_ideal_size/setup/get_string are direct
//   thiscall calls (relocation identity with the original targets).
// - Value strings are fetched either via get_string(id, buf, 0x100) or via
//   strcpy(buf, get_string(id)) exactly as the original alternates; formatted
//   lines land in a second buffer via sprintf and are pushed with
//   settingText[index]->set_text(...) + set_active(1).
// - mapSize/mapType/victoryType switches keep the per-case get_string+strcpy
//   so VC5 tail-merges them like the original shared strcpy blocks.
// FLAGS: /GX (original has the fs:[0] EH registration frame; all sibling
// scr_mps/scr_save screen ctors match only with /GX)


TRIBE_Screen_Wait::TRIBE_Screen_Wait() : TScreenPanel("Multiplayer Wait Screen")
{
    char str1[0x100];
    char str2[0x100];
    char str3[0x100];
    int i;

    this->message = 0;
    this->cancel_button = 0;
    this->close_button = 0;
    this->scenarioName = 0;
    for (i = 0; i < 20; i++) {
        this->settingText[i] = 0;
    }

    if (this->setup(rge_base_game->draw_area, "scr3", 0xC385, 0) == 0) {
        this->error_code = 1;
        return;
    }

    this->set_ideal_size(0x280, 0x1E0);

    this->create_text((TPanel*)this, &this->message, "",
                     0x14, 0x28, 0x17C, 0x190, 4, 1, 1, 1);
    if (this->create_button((TPanel*)this, &this->close_button, 0x3EA,
                            0, 0, 0, 0, 0, -1, -1, 0) == 0) {
        return;
    }
    this->close_button->set_active(1);
    this->close_button->set_positioning((TPanel::PositionMode)9, 4, 4, 4,
                                        4, 0x11, 0x11, 0x11,
                                        0x11, 0, 0, 0, 0);

    if (this->create_text((TPanel*)this, &this->scenarioName, "",
                          0x1A4, 0x54, 0xDC, 0x44, 0xB, 0, 0, 1) == 0) {
        return;
    }

    int y = 0x53;
    int k = 0;
    for (; y < 0x233; y += 0x18, k++) {
        if (this->create_text((TPanel*)this, &this->settingText[k], "",
                              0x1A4, y, 0xDC, 0x14, 0xB, 0, 0, 0) == 0) {
            return;
        }
    }

    for (k = 0; k < 20; k++) {
        this->settingText[k]->set_active(0);
    }

    if (rge_base_game->scenarioGame()) {
        sprintf(str2, get_string(0x25ED), rge_base_game->scenarioName());
        this->scenarioName->set_text(str2);
        i = 3;
    } else {
        if (((TRIBE_Game*)rge_base_game)->deathMatch()) {
            get_string(0x2617, str1, 0x100);
        } else {
            get_string(0x25B5, str1, 0x100);
        }
        sprintf(str2, get_string(0x25ED), str1);
        this->scenarioName->set_text(str2);
        i = 1;
    }

    if (rge_base_game->randomGame()) {
        switch (((TRIBE_Game*)rge_base_game)->mapSize()) {
        case 0: strcpy(str1, get_string(0x2973)); break;   // Tiny
        case 1: strcpy(str1, get_string(0x2974)); break;   // Small
        case 2: strcpy(str1, get_string(0x2975)); break;   // Medium
        case 3: strcpy(str1, get_string(0x2976)); break;   // Large
        case 4: strcpy(str1, get_string(0x2977)); break;   // Huge
        case 5: strcpy(str1, get_string(0x2978)); break;   // Gigantic
        }
        sprintf(str2, get_string(0x25DA), str1);           // "Map Size: %s"
        this->settingText[i]->set_text(str2);
        this->settingText[i]->set_active(1);
        i++;

        switch (((TRIBE_Game*)rge_base_game)->mapType()) {
        case 0: strcpy(str1, get_string(0x296A)); break;   // All Water
        case 1: strcpy(str1, get_string(0x296B)); break;   // Mostly Water
        case 2: strcpy(str1, get_string(0x296C)); break;   // Water & Land
        case 3: strcpy(str1, get_string(0x296D)); break;   // Mostly Land
        case 4: strcpy(str1, get_string(0x296E)); break;   // All Land
        case 5: strcpy(str1, get_string(0x296F)); break;   // Continental
        case 6: strcpy(str1, get_string(0x2970)); break;   // Lake
        case 7: strcpy(str1, get_string(0x2971)); break;   // Hilly
        case 8: strcpy(str1, get_string(0x2972)); break;   // Narrows
        }
        sprintf(str2, get_string(0x25B6), str1);           // "Map Type: %s"
        this->settingText[i]->set_text(str2);
        this->settingText[i]->set_active(1);
        i++;
    }
    i++;

    switch (((TRIBE_Game*)rge_base_game)->victoryType()) {
    case 1:                            // Conquest
        strcpy(str1, get_string(0x10E1));
        goto victory_plain;
    case 7:                            // Time
        strcpy(str1, get_string(0x10E9));
        goto victory_amount;
    case 8:                            // Score
        strcpy(str1, get_string(0x10EA));
    victory_amount:
        sprintf(str2, get_string(0x25BE), str1,
                ((TRIBE_Game*)rge_base_game)->victoryAmount()); // "Victory: %s (%d)"
        goto victory_done;
    default:
        if (rge_base_game->randomGame()) {
            strcpy(str1, get_string(0x10EC));
        } else {
            strcpy(str1, get_string(0x10E7));
        }
        goto victory_plain;
    case 9:                            // Standard
        strcpy(str1, get_string(0x10E7));
    victory_plain:
        sprintf(str2, get_string(0x25BC), str1);            // "Victory: %s"
    victory_done:
        break;
    }
    this->settingText[i]->set_text(str2);
    this->settingText[i]->set_active(1);
    i++;

    int age = ((TRIBE_Game*)rge_base_game)->startingAge();
    if (age == 0) {
        get_string(0x10E7, str1, 0x100);                    // Default
    } else if (age == 1) {
        get_string(0x106E, str1, 0x100);                    // Nomad
    } else {
        get_string(age + 0x1067, str1, 0x100);
    }
    sprintf(str2, get_string(0x25E4), str1);                // "Age: %s"
    this->settingText[i]->set_text(str2);
    this->settingText[i]->set_active(1);
    i++;

    int level = ((TRIBE_Game*)rge_base_game)->resourceLevel();
    if (level == 0) {
        get_string(0x10E7, str1, 0x100);                    // Default
    } else {
        get_string(level + 0x25E5, str1, 0x100);
    }
    sprintf(str2, get_string(0x25E5), str1);                // "Resources: %s"
    this->settingText[i]->set_text(str2);
    this->settingText[i]->set_active(1);
    i++;

    rge_base_game->difficulty();
    get_string(rge_base_game->difficulty() + 0x2BD0, str1, 0x100);
    get_string(0x25E0, str2, 0x100);                        // "Difficulty Level: %s"
    sprintf(str3, str2, str1);
    this->settingText[i]->set_text(str3);
    this->settingText[i]->set_active(1);
    i++;

    if (((TRIBE_Game*)rge_base_game)->randomizePositions()) {
        get_string(0xFA4, str1, 0x100);
    } else {
        get_string(0xFA3, str1, 0x100);
    }
    sprintf(str2, get_string(0x25E9), str1);                // "Fixed Positions: %s"
    this->settingText[i]->set_text(str2);
    this->settingText[i]->set_active(1);
    i++;

    if (rge_base_game->fullVisibility()) {
        strcpy(str1, get_string(0xFA3));
    } else {
        strcpy(str1, get_string(0xFA4));
    }
    sprintf(str2, get_string(0x25B8), str1);                // "Reveal Map: %s"
    this->settingText[i]->set_text(str2);
    this->settingText[i]->set_active(1);
    i++;

    if (((TRIBE_Game*)rge_base_game)->fullTechTree()) {
        get_string(0xFA3, str1, 0x100);
    } else {
        get_string(0xFA4, str1, 0x100);
    }
    sprintf(str2, get_string(0x25EC), str1);                // "Full Tech Tree: %s"
    this->settingText[i]->set_text(str2);
    this->settingText[i]->set_active(1);
    i++;

    if (rge_base_game->multiplayerGame()) {
        if (rge_base_game->allowCheatCodes()) {
            strcpy(str1, get_string(0xFA3));
        } else {
            strcpy(str1, get_string(0xFA4));
        }
        sprintf(str2, get_string(0x25BB), str1);            // "Enable Cheating: %s"
        this->settingText[i]->set_text(str2);
        this->settingText[i]->set_active(1);
        i++;
    }

    if (rge_base_game->multiplayerGame()) {
        get_string(rge_base_game->mpPathFinding() + 0x260E, str1, 0x100);
    } else {
        get_string(rge_base_game->pathFinding() + 0x260E, str1, 0x100);
    }
    sprintf(str2, get_string(0x25F1), str1);                // "Path Finding: %s"
    this->settingText[i]->set_text(str2);
    this->settingText[i]->set_active(1);
    i++;

    sprintf(str2, get_string(0x25F0),
            ((TRIBE_Game*)rge_base_game)->popLimit());
    this->settingText[i]->set_text(str2);                   // "Population Limit: %d"
    this->settingText[i]->set_active(1);
}

// PDB-order owner source: 004A6050_TRIBE_Screen_Wait.cpp.

// attempt 3: natural destructor with helper on screen-panel base and exact field offsets
TRIBE_Screen_Wait::~TRIBE_Screen_Wait() {
    this->delete_panel((TPanel**)&this->message);
    this->delete_panel((TPanel**)&this->close_button);
    this->delete_panel((TPanel**)&this->scenarioName);
    for (int i = 0; i < 20; ++i) {
        this->delete_panel((TPanel**)&this->settingText[i]);
    }
}

// PDB-order owner source: 004A60E0_set_text.cpp.

void TRIBE_Screen_Wait::set_text(char* param) {
    this->message->set_text(param);
}

// PDB-order owner source: 004A6100_set_text.cpp.

void TRIBE_Screen_Wait::set_text(long param) {
    this->message->set_text(param);
}

// PDB-order owner source: 004A6120_action.cpp.

long TRIBE_Screen_Wait::action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4) {
    if ((param_1 != 0) && (param_1 == (TPanel*)this->close_button) && (param_2 == 1)) {
        rge_base_game->close();
        return 1;
    }
    return this->TScreenPanel::action(param_1, param_2, param_3, param_4);
}

// PDB-order owner source: 004A6170_handle_idle.cpp.

long TRIBE_Screen_Wait::handle_idle() {
    if (!rge_base_game->input_enabled)
        rge_base_game->enable_input();
    return TPanel::handle_idle();
}

// PDB-order owner source: 004A61A0_TRIBE_Screen_Disconnect.cpp.

// 004A61A0 TRIBE_Screen_Disconnect::TRIBE_Screen_Disconnect
//
// Attempt log:
// - Earlier raw-wrapper scaffold had the right broad effects but no constructor
//   EH/vptr surface and an extra draw-area helper call.
// - Baseline candidate: natural TScreenPanel-derived constructor, named fields,
//   real panel member-call surfaces, and the proven rge_base_game draw_area.
// - Direct setup predicate removed the named result and recovered the exact
//   prologue/setup call sequence through the conditional (best codegen: 91
//   positional bytes, 219-byte rebuilt body, exact four-call set).
// - Shared-goto, arm-order, destructor-surface, qualified-call, virtuality, and
//   switch probes did not improve the remaining branch tail.
// - Final unresolved drift is structural: VC5 duplicates the normal EH cleanup
//   epilogue on the setup-failure path instead of the original short jump to the
//   shared epilogue. No call or field-ownership discrepancy remains.
// - Fresh pass inspected the /GX exact same-TU constructor/dtor family first.
//   Canonicalized the local TPanel/TEasy_Panel inheritance, proven 0xF4 base
//   size, inherited virtual surface, and nonvirtual TScreenPanel setup helper;
//   this preserved the exact four-call set and 31-instruction prefix.
// - Same-TU donor control-flow forms tried: explicit setup-failure return with
//   and without else, inverted guard, do-while(0) break, both-arm returns, and
//   unary ! guard. All landed in the same 219-byte VC5 basin; no further blind
//   branch-tail variants remain productive under this pass.
// - Final source keeps the period-plausible unary ! guard and explicit failure
//   return; remaining drift is the duplicated normal EH cleanup epilogue.
// - Fresh bounded probes: /O1 and /Os left the EH basin (181 bytes plus an
//   eh_prolog call); explicit labels and a one-shot loop were unchanged or
//   worse; stdio/string context and volatile field_D8 were unchanged. An
//   inline success helper virtualized the two calls, while direct
//   TScreenPanel method declarations left the 91-byte drift unchanged.
// - Fresh ABI/layout checks used the original TDrawArea* setup signature,
//   TPanel-owned +0xD8 field, and explicit TEasy_Panel destructor/full virtual
//   surface; all emitted the same 219-byte basin.
// - Final validated reconstruction is the ordinary setup-failure return with
//   named panel fields and inherited TEasy calls. Remaining drift is the
//   compiler's duplicated 19-byte EH cleanup tail; no further source lead is
//   justified in this bounded pass.
// - Follow-up ABI probe mirrored the exact donor's no-argument TPanel setup
//   slot while retaining the real TScreenPanel setup overload; emitted code
//   was unchanged, so the canonical source was restored.
// - Fresh worker probes: inverted setup if/else, an implicit derived
//   destructor, an explicit final constructor return, one-shot common labels,
//   and a setup-result switch all failed to change or improve the EH-tail
//   basin; the switch worsened the first branch hunk. A diagnostic throw()
//   declaration surface was also unchanged. All variants were restored.
// - Current pass restored the exact sibling's no-argument TPanel setup slot
//   and complete child-panel declarations; bytes were unchanged. Failure-first
//   setup if/else, unbraced failure assignment, explicit common exits, and
//   success-first arm order did not remove the duplicated EH cleanup. Member
//   initializers worsened the prefix by 15 bytes and were restored to body
//   assignments. The remaining blocker is the 19-byte compiler EH-tail basin.

// - Exact 004A5610 same-TU stdio/string includes and TPanel/TEasy/TScreen
//   declarations produced the unchanged 91-byte diff and 219-byte body;
//   restored the canonical source. The EH-tail lead is negative.
// - Final source-plausibility review retained the named fields, ordinary
//   setup conditional, direct period-style calls, and /GX virtual surface.
//   No unsupported codegen steering remained. Proven layout, four calls,
//   setup-failure assignment, EH, and partial construction are preserved.
// - ABI2 corrected TPanel::setup to the seven-argument TDrawArea*/parent
//   surface and set_positioning to PositionMode plus long parameters.
//   The executable vtable at 00573518 confirms those slots at +04 and +18.
//   Its TEasy slots use the inherited create_button and create_text methods;
//   removed the spurious TScreenPanel child declarations. TEasy create_text
//   keeps int trailing alignment, centering, and wrap parameters.
// - ABI2 baseline and child-surface removal were codegen duplicates: 91-byte
//   positional drift and the 19-byte duplicated EH cleanup remain unchanged.
// - Added the binary-proven handle_idle (+4C) and action (+B4) overrides to
//   the local class surface; the constructor code remains unchanged.
// - Executable vtable 00573518 and exact panel donors prove five inherited
//   owners: TEasy_Panel::draw_setup (+28) and handle_mouse_down (+70), plus
//   TScreenPanel::draw (+30), handle_paint (+54), and set_focus (+C0).
//   The complete emitted vtable was checked against every original slot.
// - Full slot comparison also found VC5 reverses overloaded declarations in
//   the emitted table. Reversed set_rect, set_tab_order, create_button, and
//   create_text declarations so every slot follows executable 00573518.
// - Exact translation-unit finish: the real earlier scr_mps.cpp owner at
//   004A16D0 selects the original constructor EH tail. The reviewed natural
//   source then matches all 200 bytes and four calls. Target-only compilation
//   emits the prior duplicated-cleanup drift.
// - The extended PDB-ordered scr_mps.cpp wrapper keeps this 200-byte match.


TRIBE_Screen_Disconnect::TRIBE_Screen_Disconnect(int mode)
    : TScreenPanel(s_Multiplayer_Disconnect_Screen)
{
    this->mode = mode;
    this->message = 0;
    this->cancel_button = 0;
    this->close_button = 0;

    if (this->setup(rge_base_game->draw_area, s_scr3, 0xC385, 0) == 0) {
        this->error_code = 1;
    } else {
        this->set_ideal_size(0x280, 0x1E0);
        this->create_text((TPanel*)this, &this->message, 0x4C0,
                          0x28, 0x28, 0x230, 0x190, 4, 1, 1, 1);
    }
}

// PDB-order owner source: 004A6290_TRIBE_Screen_Disconnect.cpp.

// attempt 8: natural member delete_panel call on derived screen panel
TRIBE_Screen_Disconnect::~TRIBE_Screen_Disconnect() {
    this->delete_panel((TPanel**)&this->message);
}

// PDB-order owner source: 004A62F0_set_text.cpp.

void TRIBE_Screen_Disconnect::set_text(char* param) {
    this->message->set_text(param);
}

// PDB-order owner source: 004A6310_set_text.cpp.

void TRIBE_Screen_Disconnect::set_text(long param) {
    this->message->set_text(param);
}

// PDB-order owner source: 004A6330_action.cpp.

// 004A6330 TRIBE_Screen_Disconnect::action
//
// Attempt log:
// - Initial scratch used free-function wrappers for quit/close/destroy/base action. Behavior was right, but VC5 emitted
//   cdecl-style pushes/add esp and the wrong tail size.
// - SpruceGlow MATCH: use natural typed member-call surfaces for TRIBE_Game::quit_game, RGE_Base_Game::close,
//   TPanelSystem::destroyPanel, and base TEasy_Panel::action, with `panel_system` as an object rather than a pointer.
//   This gives the original thiscall call sequence and fallback argument passing.
// Result: MATCH locally with `python tools/check_function.py --va 004A6330`.


long TRIBE_Screen_Disconnect::action(TPanel* p1, long p2, unsigned long p3, unsigned long p4) {
    if (p1 != 0) {
        if (p1 == this->cancel_button && p2 == 1) {
            ((TRIBE_Game*)rge_base_game)->quit_game();
            panel_system.destroyPanel(s_Multiplayer_Disconnect_Screen);
            panel_system.destroyPanel(s_Status_Screen);
            return 1;
        }
        if (p1 == this->close_button && p2 == 1) {
            rge_base_game->close();
            return 1;
        }
    }
    return TEasy_Panel::action(p1, p2, p3, p4);
}

// PDB-order owner source: 004A63C0_handle_idle.cpp.

long TRIBE_Screen_Disconnect::handle_idle() { return TPanel::handle_idle(); }
