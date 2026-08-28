// PDB source module: C:\\msdev\\work\\age1_x1\\dlg_menu.cpp.
// The handwritten owners follow the original source-line and address order.

#include "../include/dlg_menu.h"
#include "../include/scr_save.h"
#include "../include/dlg_conf.h"
#include "../include/scr_ach.h"
#include "../include/dlg_abt.h"
#include "../include/scr_vc.h"
#include "../include/player.h"
#include "../include/world.h"
#include "../include/scenario.h"

extern int confirmed_close;

TribeMenuDialog::TribeMenuDialog(TScreenPanel* parent)
    : TDialogPanel("Menu Dialog")
{
    int i;
    for (i = 0; i < 11; ++i)
        this->button[i] = 0;
    int bi = 0;

    int y = 300;

    if (rge_base_game->multiplayerGame()) {
        if (rge_base_game->get_player()->game_status == 0)
            y = 0x14F;
    }

    if (rge_base_game->singlePlayerGame())
        y += 0x69;

    if (!this->setup(parent->renderArea(), parent, 400, y,
                     parent->get_popup_info_file(), parent->get_popup_info_id(), 1))
        return;

    if (!this->create_button(this, &this->button[bi++], 0x2439, 0, 0x14,
                             0x0F, 0x168, 0x1E, 0, 0, 4))
        return;

    int by = 0x41;
    if (rge_base_game->multiplayerGame()) {
        if (rge_base_game->get_player()->game_status == 0) {
            if (!this->create_button(this, &this->button[bi++], 0x2440, 0,
                                     0x14, by, 0x168, 0x1E, 0, 0, 0x0C))
                return;
            by = 100;
        }
    }

    if (!this->create_button(this, &this->button[bi++], 0x2437, 0, 0x14,
                             by, 0x168, 0x1E, 0, 0, 7))
        return;
    by += 0x23;

    if (!this->create_button(this, &this->button[bi++], 0x243E, 0, 0x14,
                             by, 0x168, 0x1E, 0, 0, 9))
        return;
    int by2 = by;
    by2 += 0x23;

    if (rge_base_game->singlePlayerGame()) {
        if (!this->create_button(this, &this->button[bi++], 0x2438, 0,
                                 0x14, by2, 0x168, 0x1E, 0, 0, 1))
            return;
        by2 += 0x23;
        if (!this->create_button(this, &this->button[bi++], 0x243C, 0,
                                 0x14, by2, 0x168, 0x1E, 0, 0, 3))
            return;
        by2 += 0x23;
        if (!this->create_button(this, &this->button[bi++], 0x243F, 0,
                                 0x14, by2, 0x168, 0x1E, 0, 0, 0x0B))
            return;
        by2 += 0x23;
    }

    if (!this->create_button(this, &this->button[bi++], 0x243A, 0, 0x14,
                             by2, 0x168, 0x1E, 0, 0, 5))
        return;
    by2 += 0x23;

    if (!this->create_button(this, &this->button[bi++], 0x23F5, 0, 0x14,
                             by2, 0x168, 0x1E, 0, 0, 8))
        return;
    by2 += 0x23;

    if (!this->create_button(this, &this->button[bi++], 0x23F9, 0, 0x14,
                             by2, 0x168, 0x1E, 0, 0, 10))
        return;
    by2 += 0x23;

    if (!this->create_button(this, &this->button[bi++], 0x243B, 0, 0x14,
                             by2 + 0x0F, 0x168, 0x1E, 0, 0, 6))
        return;

    TButtonPanel* p = this->button[bi - 1];
    p->hotkey_shift = 0;
    p->hotkey = 0x1B;

    this->set_curr_child(this->button[0]);
    TPanel* tab_order[11];
    for (i = 0; i < 11; ++i)
        tab_order[i] = this->button[i];
    this->set_tab_order(tab_order, static_cast<short>(bi));
}

TribeMenuDialog::~TribeMenuDialog()
{
    for (int i = 0; i < 11; ++i) {
        TPanel* panel = this->button[i];
        this->delete_panel(&panel);
        this->button[i] = 0;
    }
}

long TribeMenuDialog::action(TPanel* panel, long id, unsigned long param3,
                             unsigned long param4)
{
    if (panel != 0) {
        if (id == 1) {
            if (param3 == 1) {
                TribeSaveGameScreen* obj =
                    new TribeSaveGameScreen(TribeSaveGameScreen::SaveGame, 0, 0);
                panel_system.setCurrentPanel("Save Game Screen", 0);
                panel_system.destroyPanel("Menu Dialog");
                return 1;
            }

            if (param3 == 2) {
                TribeSaveGameScreen* obj = new TribeSaveGameScreen(
                    TribeSaveGameScreen::SaveScenario, 0, 0);
                panel_system.setCurrentPanel("Save Game Screen", 0);
                return 1;
            }

            if (param3 == 3) {
                TScreenPanel* ep =
                    static_cast<TScreenPanel*>(this->parent_panel);
                panel_system.destroyPanel("Menu Dialog");
                panel_system.setCurrentPanel("Game Screen", 0);
                ep->popupYesNoDialog(0xC1C, "QuitAndLoadDialog", 0x1C2, 100);
                return 1;
            }

            if (param3 == 8) {
                if (rge_base_game->singlePlayerGame() == 1 &&
                    rge_base_game->save_paused == 0) {
                    rge_base_game->set_paused(0, 0);
                }
                panel_system.destroyPanel("Menu Dialog");
                panel_system.setCurrentPanel("Game Screen", 0);
                WinHelpA(rge_base_game->prog_window, "empires.hlp", 3, 0);
                return 1;
            }

            if (param3 == 4) {
                confirmed_close = 1;
                TScreenPanel* ep =
                    static_cast<TScreenPanel*>(this->parent_panel);
                panel_system.destroyPanel("Menu Dialog");
                panel_system.setCurrentPanel("Game Screen", 0);
                ep->popupYesNoDialog(0xC1D, "QuitGameDialog", 0x1C2, 100);
                return 1;
            }

            if (param3 == 5) {
                TScreenPanel* ep =
                    static_cast<TScreenPanel*>(this->parent_panel);
                panel_system.destroyPanel("Menu Dialog");
                panel_system.setCurrentPanel("Game Screen", 0);
                TribeConfigDialog* obj =
                    new TribeConfigDialog(TribeConfigDialog::InGame, ep);
                return 1;
            }

            if (param3 == 7) {
                TribeAchievementsScreen* obj =
                    new TribeAchievementsScreen(this->get_string(0x269E), 0);
                panel_system.setCurrentPanel("Achievements Screen", 0);
                panel_system.destroyPanel("Menu Dialog");
                return 1;
            }

            if (param3 == 10) {
                TScreenPanel* ep =
                    static_cast<TScreenPanel*>(this->parent_panel);
                panel_system.destroyPanel("Menu Dialog");
                panel_system.setCurrentPanel("Game Screen", 0);
                TribeAboutDialog* obj = new TribeAboutDialog(ep);
                return 1;
            }

            if (param3 == 11) {
                TScreenPanel* ep =
                    static_cast<TScreenPanel*>(this->parent_panel);
                panel_system.destroyPanel("Menu Dialog");
                panel_system.setCurrentPanel("Game Screen", 0);
                ep->popupYesNoDialog(0xC1E, "RestartDialog", 0x1C2, 100);
                return 1;
            }

            if (param3 == 9) {
                TRIBE_Mission_Screen* obj = new TRIBE_Mission_Screen(
                    0, 1, rge_base_game->world->scenario->mission_picture);
                panel_system.setCurrentPanel("Mission Dialog", 0);
                panel_system.destroyPanel("Menu Dialog");
                return 1;
            }

            if (param3 == 6) {
                if (rge_base_game->singlePlayerGame() == 1 &&
                    rge_base_game->save_paused == 0) {
                    rge_base_game->set_paused(0, 0);
                }
                panel_system.setCurrentPanel("Game Screen", 0);
                panel_system.destroyPanel("Menu Dialog");
                return 1;
            }

            if (param3 == 12) {
                TScreenPanel* ep =
                    static_cast<TScreenPanel*>(this->parent_panel);
                panel_system.destroyPanel("Menu Dialog");
                panel_system.setCurrentPanel("Game Screen", 0);
                ep->popupYesNoDialog(0xC1F, "ResignDialog", 0x1C2, 100);
                return 1;
            }

        }
    }

    return TEasy_Panel::action(panel, id, param3, param4);
}
