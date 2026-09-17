
#include "../include/dlg_menu.h"
#include "../include/resource_ids.h"
#include "../include/scr_save.h"
#include "../include/dlg_conf.h"
#include "../include/scr_ach.h"
#include "../include/dlg_abt.h"
#include "../include/scr_vc.h"
#include "../include/player.h"
#include "../include/world.h"
#include "../include/scenario.h"

extern int confirmed_close;

TribeMenuDialog::TribeMenuDialog(TScreenPanel* parentPanel)
    : TDialogPanel("Menu Dialog") {
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

    if (!this->setup(parentPanel->renderArea(), parentPanel, 400, y,
                     parentPanel->get_popup_info_file(), parentPanel->get_popup_info_id(), 1))
        return;

    if (!this->create_button(this, &this->button[bi++], IDS_MENU_QUIT_GAME, 0, 0x14,
                             0x0F, 0x168, 0x1E, 0, 0, 4))
        return;

    int by = 0x41;
    if (rge_base_game->multiplayerGame()) {
        if (rge_base_game->get_player()->game_status == 0) {
            if (!this->create_button(this, &this->button[bi++], IDS_MENU_RESIGN, 0,
                                     0x14, by, 0x168, 0x1E, 0, 0, 0x0C))
                return;
            by = 100;
        }
    }

    if (!this->create_button(this, &this->button[bi++], IDS_MENU_ACHIEVEMENTS, 0, 0x14,
                             by, 0x168, 0x1E, 0, 0, 7))
        return;
    by += 0x23;

    if (!this->create_button(this, &this->button[bi++], IDS_MENU_SCENARIO_INSTRUCTIONS, 0, 0x14,
                             by, 0x168, 0x1E, 0, 0, 9))
        return;
    int by2 = by;
    by2 += 0x23;

    if (rge_base_game->singlePlayerGame()) {
        if (!this->create_button(this, &this->button[bi++], IDS_MENU_SAVE, 0,
                                 0x14, by2, 0x168, 0x1E, 0, 0, 1))
            return;
        by2 += 0x23;
        if (!this->create_button(this, &this->button[bi++], IDS_MENU_LOAD, 0,
                                 0x14, by2, 0x168, 0x1E, 0, 0, 3))
            return;
        by2 += 0x23;
        if (!this->create_button(this, &this->button[bi++], IDS_MENU_RESTART, 0,
                                 0x14, by2, 0x168, 0x1E, 0, 0, 0x0B))
            return;
        by2 += 0x23;
    }

    if (!this->create_button(this, &this->button[bi++], IDS_MENU_GAME_SETTINGS, 0, 0x14,
                             by2, 0x168, 0x1E, 0, 0, 5))
        return;
    by2 += 0x23;

    if (!this->create_button(this, &this->button[bi++], IDS_MENU_HELP, 0, 0x14,
                             by2, 0x168, 0x1E, 0, 0, 8))
        return;
    by2 += 0x23;

    if (!this->create_button(this, &this->button[bi++], IDS_MENU_ABOUT, 0, 0x14,
                             by2, 0x168, 0x1E, 0, 0, 10))
        return;
    by2 += 0x23;

    if (!this->create_button(this, &this->button[bi++], IDS_MENU_CANCEL, 0, 0x14,
                             by2 + 0x0F, 0x168, 0x1E, 0, 0, 6))
        return;

    TButtonPanel* p = this->button[bi - 1];
    p->hotkey_shift = 0;
    p->hotkey = 0x1B;

    this->set_curr_child(this->button[0]);
    this->set_tab_order(reinterpret_cast<TPanel**>(this->button), bi);
}

TribeMenuDialog::~TribeMenuDialog() {
    int count = 11;
    TButtonPanel** pp = this->button;

    do {
        this->delete_panel(reinterpret_cast<TPanel**>(pp));
        pp++;
        count--;
    } while (count != 0);
}

long TribeMenuDialog::action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2) {
    if (fromPanel != 0) {
        if (actionIn == 1) {
            if (a1 == 1) {
                TribeSaveGameScreen* obj =
                    new TribeSaveGameScreen(TribeSaveGameScreen::SaveGame, 0, 0);
                panel_system.setCurrentPanel("Save Game Screen", 0);
                panel_system.destroyPanel("Menu Dialog");
                return 1;
            }

            if (a1 == 2) {
                TribeSaveGameScreen* obj = new TribeSaveGameScreen(
                    TribeSaveGameScreen::SaveScenario, 0, 0);
                panel_system.setCurrentPanel("Save Game Screen", 0);
                return 1;
            }

            if (a1 == 3) {
                TScreenPanel* ep =
                    static_cast<TScreenPanel*>(this->parent_panel);
                panel_system.destroyPanel("Menu Dialog");
                panel_system.setCurrentPanel("Game Screen", 0);
                ep->popupYesNoDialog(IDS_CONFIRM_QUIT_AND_LOAD, "QuitAndLoadDialog", TEASY_POPUP_WIDTH, 100);
                return 1;
            }

            if (a1 == 8) {
                if (rge_base_game->singlePlayerGame() == 1 &&
                    rge_base_game->save_paused == 0) {
                    rge_base_game->set_paused(0, 0);
                }
                panel_system.destroyPanel("Menu Dialog");
                panel_system.setCurrentPanel("Game Screen", 0);
                WinHelpA(rge_base_game->prog_window, "empires.hlp", 3, 0);
                return 1;
            }

            if (a1 == 4) {
                confirmed_close = 1;
                TScreenPanel* ep =
                    static_cast<TScreenPanel*>(this->parent_panel);
                panel_system.destroyPanel("Menu Dialog");
                panel_system.setCurrentPanel("Game Screen", 0);
                ep->popupYesNoDialog(IDS_CONFIRM_QUIT_GAME, "QuitGameDialog", TEASY_POPUP_WIDTH, 100);
                return 1;
            }

            if (a1 == 5) {
                TScreenPanel* ep =
                    static_cast<TScreenPanel*>(this->parent_panel);
                panel_system.destroyPanel("Menu Dialog");
                panel_system.setCurrentPanel("Game Screen", 0);
                TribeConfigDialog* obj =
                    new TribeConfigDialog(TribeConfigDialog::InGame, ep);
                return 1;
            }

            if (a1 == 7) {
                TribeAchievementsScreen* obj =
                    new TribeAchievementsScreen(this->get_string(IDS_ACHIEVEMENTS_TITLE), 0);
                panel_system.setCurrentPanel("Achievements Screen", 0);
                panel_system.destroyPanel("Menu Dialog");
                return 1;
            }

            if (a1 == 10) {
                TScreenPanel* ep =
                    static_cast<TScreenPanel*>(this->parent_panel);
                panel_system.destroyPanel("Menu Dialog");
                panel_system.setCurrentPanel("Game Screen", 0);
                TribeAboutDialog* obj = new TribeAboutDialog(ep);
                return 1;
            }

            if (a1 == 11) {
                TScreenPanel* ep =
                    static_cast<TScreenPanel*>(this->parent_panel);
                panel_system.destroyPanel("Menu Dialog");
                panel_system.setCurrentPanel("Game Screen", 0);
                ep->popupYesNoDialog(IDS_CONFIRM_RESTART_GAME, "RestartDialog", TEASY_POPUP_WIDTH, 100);
                return 1;
            }

            if (a1 == 9) {
                TRIBE_Mission_Screen* obj = new TRIBE_Mission_Screen(
                    0, 1, rge_base_game->world->scenario->mission_picture);
                panel_system.setCurrentPanel("Mission Dialog", 0);
                panel_system.destroyPanel("Menu Dialog");
                return 1;
            }

            if (a1 == 6) {
                if (rge_base_game->singlePlayerGame() == 1 &&
                    rge_base_game->save_paused == 0) {
                    rge_base_game->set_paused(0, 0);
                }
                panel_system.setCurrentPanel("Game Screen", 0);
                panel_system.destroyPanel("Menu Dialog");
                return 1;
            }

            if (a1 == 12) {
                TScreenPanel* ep =
                    static_cast<TScreenPanel*>(this->parent_panel);
                panel_system.destroyPanel("Menu Dialog");
                panel_system.setCurrentPanel("Game Screen", 0);
                ep->popupYesNoDialog(IDS_CONFIRM_RESIGN, "ResignDialog", TEASY_POPUP_WIDTH, 100);
                return 1;
            }

        }
    }

    return TEasy_Panel::action(fromPanel, actionIn, a1, a2);
}
