#include "../include/TribeMenuDialog.h"

#include "../include/TButtonPanel.h"
#include "../include/TEasy_Panel.h"
#include "../include/TPanelSystem.h"
#include "../include/TScreenPanel.h"
#include "../include/TribeAboutDialog.h"
#include "../include/TribeAchievementsScreen.h"
#include "../include/TribeConfigDialog.h"
#include "../include/TribeSaveGameScreen.h"
#include "../include/TRIBE_Mission_Screen.h"
#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Scenario.h"
#include "dialog_forwarders.h"
#include "../include/globals.h"

#include <new>

// Fully verified. Source of truth: dlg_menu.cpp.decomp @ 0x0043F340
TribeMenuDialog::TribeMenuDialog(TScreenPanel* parent_screen)
    : TDialogPanel((char*)"Menu Dialog") {
    for (int i = 0; i < 11; ++i) {
        this->button[i] = nullptr;
    }

    const long popup_id = parent_screen ? parent_screen->get_popup_info_id() : -1;
    char* popup_file = parent_screen ? parent_screen->get_popup_info_file() : nullptr;
    TDrawArea* area = parent_screen ? parent_screen->render_area : nullptr;

    if (!TDialogPanel::setup(area, (TPanel*)parent_screen, 400, 300, popup_file, popup_id, 1)) {
        return;
    }

    this->create_button((TPanel*)this, &this->button[0], 0x2439, 0, 0x14, 0x0f, 0x168, 0x1e, 0, 0, 4);
    this->create_button((TPanel*)this, &this->button[1], 0x2437, 0, 0x14, 0x41, 0x168, 0x1e, 0, 0, 7);
    this->create_button((TPanel*)this, &this->button[2], 0x243e, 0, 0x14, 0x64, 0x168, 0x1e, 0, 0, 9);
    this->create_button((TPanel*)this, &this->button[3], 0x243a, 0, 0x14, 0x87, 0x168, 0x1e, 0, 0, 5);
    this->create_button((TPanel*)this, &this->button[4], 0x23f5, 0, 0x14, 0xaa, 0x168, 0x1e, 0, 0, 8);
    this->create_button((TPanel*)this, &this->button[5], 0x23f9, 0, 0x14, 0xcd, 0x168, 0x1e, 0, 0, 10);
    this->create_button((TPanel*)this, &this->button[6], 0x243b, 0, 0x14, 0xf0, 0x168, 0x1e, 0, 0, 6);

    if (this->button[6] != nullptr) {
        this->button[6]->hotkey = 0x1b;
        this->button[6]->hotkey_shift = 0;
    }

    TPanel* tabs[7];
    for (int i = 0; i < 7; ++i) {
        tabs[i] = (TPanel*)this->button[i];
    }
    this->set_tab_order(tabs, 7);
    this->set_curr_child((TPanel*)this->button[0]);
}

// Fully verified. Source of truth: dlg_menu.cpp.decomp @ 0x0043F6B0
TribeMenuDialog::~TribeMenuDialog() {
    for (int i = 0; i < 11; ++i) {
        this->delete_panel((TPanel**)&this->button[i]);
    }
}

// Fully verified. Source of truth: dlg_menu.cpp.decomp @ 0x0043F720, dlg_menu.cpp.asm @ 0x0043F720
long TribeMenuDialog::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    if (param_1 != nullptr && param_2 == 1) {
        if (param_3 == 1) {
            (void)new (std::nothrow) TribeSaveGameScreen(TribeSaveGameScreen::SaveGame, (char*)0, 0);
            panel_system->setCurrentPanel((char*)"Save Game Screen", 0);
            panel_system->destroyPanel((char*)"Menu Dialog");
            return 1;
        }

        if (param_3 == 2) {
            (void)new (std::nothrow) TribeSaveGameScreen(TribeSaveGameScreen::SaveScenario, (char*)0, 0);
            panel_system->setCurrentPanel((char*)"Save Game Screen", 0);
            return 1;
        }

        if (param_3 == 3) {
            panel_system->destroyPanel((char*)"Menu Dialog");
            panel_system->setCurrentPanel((char*)"Game Screen", 0);
            ((TEasy_Panel*)this->parent_panel)->popupYesNoDialog(0x0C1C, (char*)"QuitAndLoadDialog", 0x1C2, 100);
            return 1;
        }

        if (param_3 == 8) {
            if (rge_base_game->singlePlayerGame() == 1 && rge_base_game->save_paused == 0) {
                rge_base_game->set_paused(0, 0);
            }
            panel_system->destroyPanel((char*)"Menu Dialog");
            panel_system->setCurrentPanel((char*)"Game Screen", 0);
            WinHelpA((HWND)rge_base_game->prog_window, "empires.hlp", HELP_FINDER, 0);
            return 1;
        }

        if (param_3 == 4) {
            confirmed_close = 1;
            panel_system->destroyPanel((char*)"Menu Dialog");
            panel_system->setCurrentPanel((char*)"Game Screen", 0);
            ((TEasy_Panel*)this->parent_panel)->popupYesNoDialog(0x0C1D, (char*)"QuitGameDialog", 0x1C2, 100);
            return 1;
        }

        if (param_3 == 5) {
            panel_system->destroyPanel((char*)"Menu Dialog");
            panel_system->setCurrentPanel((char*)"Game Screen", 0);
            (void)new (std::nothrow) TribeConfigDialog(TribeConfigDialog::InGame, (TScreenPanel*)this->parent_panel);
            return 1;
        }

        if (param_3 == 7) {
            (void)new (std::nothrow) TribeAchievementsScreen(this->get_string(0x269E), 0);
            panel_system->setCurrentPanel((char*)"Achievements Screen", 0);
            panel_system->destroyPanel((char*)"Menu Dialog");
            return 1;
        }

        if (param_3 == 10) {
            panel_system->destroyPanel((char*)"Menu Dialog");
            panel_system->setCurrentPanel((char*)"Game Screen", 0);
            (void)new (std::nothrow) TribeAboutDialog((TScreenPanel*)this->parent_panel);
            return 1;
        }

        if (param_3 == 0x0B) {
            panel_system->destroyPanel((char*)"Menu Dialog");
            panel_system->setCurrentPanel((char*)"Game Screen", 0);
            ((TEasy_Panel*)this->parent_panel)->popupYesNoDialog(0x0C1E, (char*)"RestartDialog", 0x1C2, 100);
            return 1;
        }

        if (param_3 == 9) {
            (void)new (std::nothrow) TRIBE_Mission_Screen((char*)0, 1, rge_base_game->world->scenario->mission_picture);
            panel_system->setCurrentPanel((char*)"Mission Dialog", 0);
            panel_system->destroyPanel((char*)"Menu Dialog");
            return 1;
        }

        if (param_3 == 6) {
            if (rge_base_game->singlePlayerGame() == 1 && rge_base_game->save_paused == 0) {
                rge_base_game->set_paused(0, 0);
            }
            panel_system->setCurrentPanel((char*)"Game Screen", 0);
            panel_system->destroyPanel((char*)"Menu Dialog");
            return 1;
        }

        if (param_3 == 0x0C) {
            panel_system->destroyPanel((char*)"Menu Dialog");
            panel_system->setCurrentPanel((char*)"Game Screen", 0);
            ((TEasy_Panel*)this->parent_panel)->popupYesNoDialog(0x0C1F, (char*)"ResignDialog", 0x1C2, 100);
            return 1;
        }
    }

    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}

// Fully verified. Marker reconciliation coverage.
void TribeMenuDialog::draw() {
    TDialogPanel::draw();
}

// Fully verified. Marker reconciliation coverage.
long TribeMenuDialog::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    return TDialogPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5);
}

IMPLEMENT_TDIALOGPANEL_FORWARDERS(TribeMenuDialog, TDialogPanel)

