// The handwritten owners follow the original source-line order.
// The vector-deleting destructor is compiler generated.

#include "../include/scr_sing.h"
#include "../include/scr_mps.h"
#include "../include/scr_sels.h"
#include "../include/scr_name.h"
#include "../include/scr_load.h"
#include "../include/scr_main.h"
#include "../include/basegame.h"
#include "../include/tribegam.h"
#include "../include/gameinfo.h"
#include "../include/pnl_btn.h"
#include "../include/pnl_lst.h"
#include <stdlib.h>

TribeSPMenuScreen::TribeSPMenuScreen()
    : TScreenPanel("Single Player Menu")
{
    rge_base_game->setSinglePlayerGame(1);
    rge_base_game->setScenarioName("");

    if (!setup(rge_base_game->draw_area, "scr2", 0xC384, 1)) {
        error_code = 1;
        return;
    }

    for (int i = 0; i < 7; i++)
        button[i] = 0;
    close_button = 0;

    set_ideal_size(0x280, 0x1E0);

    if (create_text(this, &title, 0x2404, 0x14, 0x14, 600,
                    0x1E, 1, 1, 0, 0)) {
        for (int id = 0x76, i = 0; id < 0x1A2; id += 0x32, i++) {
            if (!create_button(this, &button[i], "", 0,
                               0xAA, id, 300, 0x28, 0, 0, 0))
                return;
        }

        if (create_button(this, &close_button, 0x3EA, 0, 0, 0, 0,
                          0, -1, -1, 0)) {
            close_button->set_active(1);
            close_button->set_positioning(TPanel::PositionRightTop, 4, 4, 4,
                                          4, 0x11, 0x11, 0x11, 0x11,
                                          0, 0, 0, 0);

            button[0]->set_text(0, 0x240A);
            button[1]->set_text(0, 0x2408);
            button[2]->set_text(0, 0x240B);
            button[3]->set_text(0, 0x2405);
            button[4]->set_text(0, 0x2407);
            button[5]->set_text(0, 0x2409);

            // Keep one local receiver for the two hotkey stores.
            TButtonPanel* cancel = button[5];
            cancel->hotkey = 0x1B;
            cancel->hotkey_shift = 0;

            set_curr_child(button[0]);

            TPanel* tabList[6];
            for (int i = 0; i < 6; i++)
                tabList[i] = button[i];
            set_tab_order(tabList, 6);
        }
    }
}

TribeSPMenuScreen::~TribeSPMenuScreen()
{
    TPanel* panel = title;
    delete_panel(&panel);
    title = 0;

    for (int i = 0; i < 7; i++) {
        panel = button[i];
        delete_panel(&panel);
        button[i] = 0;
    }

    panel = close_button;
    delete_panel(&panel);
    close_button = 0;
}

long TribeSPMenuScreen::handle_idle()
{
    if (rge_base_game->input_enabled == 0)
        rge_base_game->enable_input();
    return TPanel::handle_idle();
}

long TribeSPMenuScreen::action(TPanel* panel, long code,
                               unsigned long a3, unsigned long a4)
{
    if (panel != 0 && code == 1) {
        if (panel == button[0]) {
            rge_base_game->setCampaignGame(0);
            rge_base_game->setSavedGame(0);
            rge_base_game->setScenarioGame(0);
            static_cast<TRIBE_Game*>(rge_base_game)->setDeathMatch(0);
            static_cast<TRIBE_Game*>(rge_base_game)->setQuickStartGame(0);
            rge_base_game->disable_input();
            new TribeMPSetupScreen;
            panel_system.setCurrentPanel("MP Setup Screen", 0);
            panel_system.destroyPanel("Single Player Menu");
            return 1;
        }

        if (panel == button[2]) {
            rge_base_game->setCampaignGame(0);
            rge_base_game->setSavedGame(0);
            rge_base_game->setScenarioGame(0);
            static_cast<TRIBE_Game*>(rge_base_game)->setDeathMatch(1);
            static_cast<TRIBE_Game*>(rge_base_game)->setQuickStartGame(0);
            rge_base_game->disable_input();
            new TribeMPSetupScreen;
            panel_system.setCurrentPanel("MP Setup Screen", 0);
            panel_system.destroyPanel("Single Player Menu");
            return 1;
        }

        if (panel == button[3]) {
            rge_base_game->setCampaignGame(0);
            rge_base_game->setSavedGame(0);
            rge_base_game->setScenarioGame(1);
            static_cast<TRIBE_Game*>(rge_base_game)->setDeathMatch(0);
            static_cast<TRIBE_Game*>(rge_base_game)->setQuickStartGame(0);
            rge_base_game->disable_input();
            new TribeSelectScenarioScreen;
            panel_system.setCurrentPanel("Select Scenario Screen", 0);
            panel_system.destroyPanel("Single Player Menu");
            return 1;
        }

        if (panel == button[4]) {
            rge_base_game->disable_input();
            new TribeLoadSavedGameScreen;
            panel_system.setCurrentPanel("Load Saved Game Screen", 0);
            panel_system.destroyPanel("Single Player Menu");
            return 1;
        }

        if (panel == button[1]) {
            rge_base_game->disable_input();

            RGE_Game_Info* info = rge_base_game->player_game_info;
            char** list = 0;
            long count;
            long result = info->get_people_list(&list, count);

            if (result > 0) {
                for (int i = 0; i < result; i++)
                    free(list[i]);
                free(list);
            }

            if (result > 0) {
                new TRIBE_Screen_Name;
                panel_system.setCurrentPanel("Name Selection Screen", 0);
                panel_system.destroyPanel("Single Player Menu");
                return 1;
            }

            new TRIBE_Dialog_Name(this);
            return 1;
        }

        if (panel == button[5]) {
            rge_base_game->disable_input();
            new TRIBE_Screen_Main_Menu;
            panel_system.setCurrentPanel("Main Menu", 0);
            panel_system.destroyPanel("Single Player Menu");
            return 1;
        }

        if (panel == close_button) {
            rge_base_game->close();
            return 1;
        }
    }

    return TEasy_Panel::action(panel, code, a3, a4);
}
