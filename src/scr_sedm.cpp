// PDB source module: C:\\msdev\\work\\age1_x1\\scr_sedm.cpp.
// The definitions follow the original source-line and address order.

#include "../include/scr_sedm.h"
#include "../include/pnl_btn.h"
#include "../include/Pnl_txt.h"
#include "../include/basegame.h"
#include "../include/tribegam.h"
#include "../include/scr_sedo.h"
#include "../include/scr_cam.h"
#include "../include/scr_main.h"
#include "../include/rge_base_game_global.h"

extern char s_Scenario_Editor_Menu[];
extern char s_scr4[];
extern char s_empty[];
extern char s_Scenario_Editor_Open[];
extern char s_Campaign_Editor_Screen[];
extern char s_Main_Menu[];
extern TPanelSystem panel_system;

TRIBE_Screen_Sed_Menu::TRIBE_Screen_Sed_Menu()
    : TScreenPanel(s_Scenario_Editor_Menu)
{
    title = 0;
    for (int j = 0; j < 4; j++)
        button[j] = 0;
    close_button = 0;

    if (!setup(rge_base_game->draw_area, s_scr4, 0xC386, 1)) {
        error_code = 1;
        return;
    }

    set_ideal_size(0x280, 0x1E0);

    if (!create_text(this, &title, 0x242D, 0x14, 0x14, 0x258, 0x1E,
                     1, 1, 0, 0))
        return;

    for (int i = 0; i < 4; i++) {
        if (!create_button(this, &button[i], s_empty, 0,
                           0xAA, 0xAA + i * 0x32, 0x12C, 0x28,
                           0, 0, 0))
            return;
    }

    if (!create_button(this, &close_button, 0x3EA, 0,
                       0, 0, 0, 0, -1, -1, 0))
        return;

    close_button->set_active(1);
    close_button->set_positioning(TPanel::PositionRightTop, 4, 4, 4, 4,
                                  0x11, 0x11, 0x11, 0x11,
                                  0, 0, 0, 0);

    button[0]->set_text(0, 0x242E);
    button[1]->set_text(0, 0x242F);
    button[2]->set_text(0, 0x2431);
    button[3]->set_text(0, 0x2430);

    TButtonPanel* cancel = button[3];
    cancel->hotkey = 0x1B;
    cancel->hotkey_shift = 0;

    set_tab_order(reinterpret_cast<TPanel**>(button), 4);
    set_curr_child(button[0]);
}

TRIBE_Screen_Sed_Menu::~TRIBE_Screen_Sed_Menu()
{
    delete_panel(reinterpret_cast<TPanel**>(&title));
    for (int i = 0; i < 4; i++)
        delete_panel(reinterpret_cast<TPanel**>(&button[i]));
    delete_panel(reinterpret_cast<TPanel**>(&close_button));
}

long TRIBE_Screen_Sed_Menu::handle_idle()
{
    if (!rge_base_game->input_enabled)
        rge_base_game->enable_input();
    return TPanel::handle_idle();
}

long TRIBE_Screen_Sed_Menu::action(
    TPanel* param_1, long param_2, unsigned long param_3,
    unsigned long param_4)
{
    if (param_1 != 0 && param_2 == 1) {
        if (param_1 == button[0]) {
            static_cast<TRIBE_Game*>(rge_base_game)
                ->start_scenario_editor(0, 0);
            return 1;
        }

        if (param_1 == button[1]) {
            new TRIBE_Screen_Sed_Open();
            panel_system.setCurrentPanel(s_Scenario_Editor_Open, 0);
            panel_system.destroyPanel(s_Scenario_Editor_Menu);
            return 1;
        }

        if (param_1 == button[2]) {
            new TRIBE_Campaign_Editor_Screen();
            panel_system.setCurrentPanel(s_Campaign_Editor_Screen, 0);
            panel_system.destroyPanel(s_Scenario_Editor_Menu);
            return 1;
        }

        if (param_1 == button[3]) {
            rge_base_game->disable_input();
            new TRIBE_Screen_Main_Menu();
            panel_system.setCurrentPanel(s_Main_Menu, 0);
            panel_system.destroyPanel(s_Scenario_Editor_Menu);
            return 1;
        }

        if (param_1 == close_button) {
            rge_base_game->close();
            return 1;
        }
    }

    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}
