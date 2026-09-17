
#include "../include/scr_sedm.h"
#include "../include/pnl_btn.h"
#include "../include/Pnl_txt.h"
#include "../include/basegame.h"
#include "../include/tribegam.h"
#include "../include/scr_sedo.h"
#include "../include/scr_cam.h"
#include "../include/scr_main.h"
#include "../include/rge_base_game_global.h"
#include "../include/resource_ids.h"

extern char s_Scenario_Editor_Menu[];
extern char s_scr4[];
extern char s_592A40[];
extern char s_Scenario_Editor_Open[];
extern char s_Campaign_Editor_Screen[];
extern char s_Main_Menu[];
extern TPanelSystem panel_system;

TRIBE_Screen_Sed_Menu::TRIBE_Screen_Sed_Menu()
    : TScreenPanel(s_Scenario_Editor_Menu) {
    title = 0;
    for (int j = 0; j < 4; j++)
        button[j] = 0;
    close_button = 0;

    if (!setup(rge_base_game->draw_area, s_scr4, 0xC386, 1)) {
        error_code = 1;
        return;
    }

    set_ideal_size(640, 480);

    if (!create_text(this, &title, IDS_SCENARIO_EDITOR_TITLE, 20, 20, 600, 30, 1, 1, 0, 0))
        return;

    for (int i = 0; i < 4; i++) {
        if (!create_button(this, &button[i], s_592A40, 0, 170, 170 + i * 50, 300, 40, 0, 0, 0))
            return;
    }

    if (!create_button(this, &close_button, IDS_BUTTON_CLOSE, 0, 0, 0, 0, 0, -1, -1, 0))
        return;

    close_button->set_active(1);
    close_button->set_positioning(TPanel::PositionRightTop, 4, 4, 4, 4, 17, 17, 17, 17, 0, 0, 0, 0);

    button[0]->set_text(0, IDS_SCENARIO_MENU_CREATE_SCENARIO);
    button[1]->set_text(0, IDS_BUTTON_EDIT_SCENARIO);
    button[2]->set_text(0, IDS_MENU_CAMPAIGN_EDITOR);
    button[3]->set_text(0, IDS_SCENARIO_EDITOR_CANCEL);

    TButtonPanel* cancel = button[3];
    cancel->hotkey = VK_ESCAPE;
    cancel->hotkey_shift = 0;

    set_tab_order(reinterpret_cast<TPanel**>(button), 4);
    set_curr_child(button[0]);
}

TRIBE_Screen_Sed_Menu::~TRIBE_Screen_Sed_Menu() {
    delete_panel(reinterpret_cast<TPanel**>(&title));
    for (int i = 0; i < 4; i++)
        delete_panel(reinterpret_cast<TPanel**>(&button[i]));
    delete_panel(reinterpret_cast<TPanel**>(&close_button));
}

long TRIBE_Screen_Sed_Menu::handle_idle() {
    if (!rge_base_game->input_enabled)
        rge_base_game->enable_input();
    return TPanel::handle_idle();
}

long TRIBE_Screen_Sed_Menu::action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2) {
    if (fromPanel != 0 && actionIn == 1) {
        if (fromPanel == button[0]) {
            static_cast<TRIBE_Game*>(rge_base_game)->start_scenario_editor(0, 0);
            return 1;
        }

        if (fromPanel == button[1]) {
            new TRIBE_Screen_Sed_Open();
            panel_system.setCurrentPanel(s_Scenario_Editor_Open, 0);
            panel_system.destroyPanel(s_Scenario_Editor_Menu);
            return 1;
        }

        if (fromPanel == button[2]) {
            new TRIBE_Campaign_Editor_Screen();
            panel_system.setCurrentPanel(s_Campaign_Editor_Screen, 0);
            panel_system.destroyPanel(s_Scenario_Editor_Menu);
            return 1;
        }

        if (fromPanel == button[3]) {
            rge_base_game->disable_input();
            new TRIBE_Screen_Main_Menu();
            panel_system.setCurrentPanel(s_Main_Menu, 0);
            panel_system.destroyPanel(s_Scenario_Editor_Menu);
            return 1;
        }

        if (fromPanel == close_button) {
            rge_base_game->close();
            return 1;
        }
    }

    return TEasy_Panel::action(fromPanel, actionIn, a1, a2);
}
