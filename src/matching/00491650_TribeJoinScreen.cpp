// 00491650 TribeJoinScreen::TribeJoinScreen
//
// Binary-backed ownership: TScreenPanel ends at +0x478; the named screen
// fields occupy +0x478..+0x4AC, and TButtonPanel hotkeys are +0x298/+0x29C.
// The constructor's direct factory calls are the period TEasy_Panel wrappers;
// the list and close button use their inherited virtual panel surfaces.
//
// Attempt log:
// - prior scaffold used the wrong TEasy_Panel base constructor and helper
//   surfaces (resource/input/edit/default-button), producing the wrong call set.
// - baseline reset: restore the TScreenPanel hierarchy, Pnl_scr setup overload,
//   SetPlayerHumanity, create_text/list/scrollbar/button wrappers, and the
//   binary-backed positive nested factory topology. Current source is the clean
//   period-plausible reconstruction being tested.
// - liveness: keep a local cancel-button pointer across the two hotkey stores;
//   this preserves VC5's interleaving of the close-button argument pushes.
//   Result: exact 797-byte match.
// FLAGS: config/flags/00491650_TribeJoinScreen.rsp (/GX), required for the
// original constructor EH registration frame.

#include "../../include/scr_cj_context.h"

TribeJoinScreen::TribeJoinScreen()
    : TScreenPanel((char*)0x0058617C)
{
    this->startedSession = 0;
    this->listFilled = 0;
    Sess = 0;
    this->game_count = 0;
    this->waitingToStart = 0;
    this->joinTime = 0;
    this->close_button = 0;

    comm->SetPlayerHumanity(1, 2);
    for (int player = 2; player <= 9; ++player) {
        comm->SetPlayerHumanity(player, 0);
    }

    if (this->setup(rge_base_game->draw_area, (char*)0x00586174,
                    0xC385, 1) == 0) {
        this->setup_error = 1;
        return;
    }

    this->setup_shadow_area(0);
    this->set_ideal_size(0x280, 0x1E0);

    if (this->create_text(this, &this->title, 0x259F,
                          0x14, 0x14, 0x258, 0x1E, 1, 1, 0, 0)) {
        this->create_text(this, &this->listTitle, 0x25A8,
                          0x14, 0x41, 0x258, 0x14, 4, 0, 0, 0);
        if (this->create_list(this, &this->list,
                              0x14, 0x5A, 0x258, 0x10E, 0x0B)) {
            if (this->create_auto_scrollbar(&this->scrollbar,
                                            this->list, 0x14)) {
                this->listFilled = 1;
                this->list->set_string(0x25AB);
                if (this->create_button(this, &this->refreshButton,
                                        0x25A1, 0, 0xD2, 0x172,
                                        0xDC, 0x1E, 0, 0, 0)) {
                    if (this->create_button(this, &this->joinButton,
                                            0x25A0, 0, 0x0A, 0x1B8,
                                            0xC8, 0x1E, 0, 0, 0)) {
                        if (this->create_button(this, &this->createButton,
                                                0x25A2, 0, 0xDC, 0x1B8,
                                                0xC8, 0x1E, 0, 0, 0)) {
                            if (this->create_button(this, &this->cancelButton,
                                                    0x0FA2, 0, 0x1AE,
                                                    0x1B8, 0xC8, 0x1E,
                                                    0, 0, 0)) {
                                TButtonPanel* cancel = this->cancelButton;
                                cancel->hotkey = 0x1B;
                                cancel->hotkey_shift = 0;

                                if (this->create_button(this,
                                                        &this->close_button,
                                                        0x03EA, 0, 0, 0, 0,
                                                        0, -1, -1, 0)) {
                                    this->close_button->set_active(1);
                                    this->close_button->set_positioning(
                                        9, 4, 4, 4, 4, 0x11, 0x11,
                                        0x11, 0x11, 0, 0, 0, 0);
                                    this->set_curr_child(this->refreshButton);

                                    TPanel* tabList[5];
                                    tabList[0] = this->list;
                                    tabList[1] = this->refreshButton;
                                    tabList[2] = this->joinButton;
                                    tabList[3] = this->createButton;
                                    tabList[4] = this->cancelButton;
                                    this->set_tab_order(tabList, 5);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
