// PDB source module: C:\\msdev\\work\\age1_x1\\dlg_sedm.cpp.
// The definitions follow the original source-line and address order.

#include "../include/dlg_sedm.h"
#include "../include/pnl_btn.h"
#include "../include/scr_sed.h"
#include "../include/scr_sedo.h"
#include "../include/tribegam.h"
#include "../include/rge_base_game_global.h"
#include <string.h>

TRIBE_Dialog_Sed_Menu::TRIBE_Dialog_Sed_Menu(TRIBE_Screen_Sed* param_1)
    : TDialogPanel("Scenario Menu Dialog"), scenario_editor(param_1), title(0)
{
    int i;

    i = 0;
    while (i < 7) {
        this->buttons[i] = 0;
        i++;
    }

    if (this->setup(param_1->renderArea(), param_1, 0x1CC, 0x190,
                    param_1->get_popup_info_file(),
                    param_1->get_popup_info_id(), 1) == 0)
        return;

    if (this->create_button(this, &this->buttons[0], 0x2443, 0, 0x1E, 0x14,
                            0x190, 0x28, 0, 0, 0) == 0)
        return;
    if (this->create_button(this, &this->buttons[1], 0x2441, 0, 0x1E, 0x46,
                            0x190, 0x28, 0, 0, 0) == 0)
        return;
    if (this->create_button(this, &this->buttons[2], 0x2442, 0, 0x1E, 0x78,
                            0x190, 0x28, 0, 0, 0) == 0)
        return;
    if (this->create_button(this, &this->buttons[3], 0x2445, 0, 0x1E, 0xAA,
                            0x190, 0x28, 0, 0, 0) == 0)
        return;
    if (this->create_button(this, &this->buttons[4], 0x242E, 0, 0x1E, 0xDC,
                            0x190, 0x28, 0, 0, 0) == 0)
        return;
    if (this->create_button(this, &this->buttons[5], 0x2446, 0, 0x1E, 0x10E,
                            0x190, 0x28, 0, 0, 0) == 0)
        return;
    if (this->create_button(this, &this->buttons[6], 0x2444, 0, 0x1E, 0x154,
                            0x190, 0x28, 0, 0, 0) == 0)
        return;

    TButtonPanel* cancel = this->buttons[6];
    cancel->hotkey = 0x1B;
    cancel->hotkey_shift = 0;
}

TRIBE_Dialog_Sed_Menu::~TRIBE_Dialog_Sed_Menu()
{
    panel_system.destroyPanel("Open Dialog");
    panel_system.destroyPanel("New Dialog");

    delete this->title;
    this->title = 0;

    for (int i = 0; i < 7; ++i) {
        delete this->buttons[i];
        this->buttons[i] = 0;
    }
}

long TRIBE_Dialog_Sed_Menu::action(
    TPanel* panel, long event, unsigned long param_3, unsigned long param_4)
{
    TRIBE_Screen_Sed* sed = this->scenario_editor;
    if (event == 1) {
        if (panel == this->buttons[0]) {
            panel_system.setCurrentPanel("Scenario Editor Screen", 0);
            panel_system.destroyPanel("Scenario Menu Dialog");
            sed->command_quit();
            return 1;
        }

        if (panel == this->buttons[1]) {
            panel_system.setCurrentPanel("Scenario Editor Screen", 0);
            panel_system.destroyPanel("Scenario Menu Dialog");
            sed->command_save(1, 0);
            return 1;
        }

        if (panel == this->buttons[2]) {
            panel_system.setCurrentPanel("Scenario Editor Screen", 0);
            panel_system.destroyPanel("Scenario Menu Dialog");
            sed->command_save_as(0);
            return 1;
        }

        if (panel == this->buttons[3]) {
            panel_system.setCurrentPanel("Scenario Editor Screen", 0);
            panel_system.destroyPanel("Scenario Menu Dialog");
            sed->command_open();
            return 1;
        }

        if (panel == this->buttons[4]) {
            panel_system.setCurrentPanel("Scenario Editor Screen", 0);
            panel_system.destroyPanel("Scenario Menu Dialog");
            sed->command_new();
            return 1;
        }

        if (panel == this->buttons[5]) {
            panel_system.setCurrentPanel("Scenario Editor Screen", 0);
            panel_system.destroyPanel("Scenario Menu Dialog");
            char* scenario = sed->scenario_save_defaulted();
            if (scenario != 0) {
                static_cast<TRIBE_Game*>(rge_base_game)->test_scenario(scenario);
            } else {
                panel_system.destroyPanel("Scenario Menu Dialog");
            }
            return 1;
        }

        else if (panel == this->buttons[6]) {
            panel_system.setCurrentPanel("Scenario Editor Screen", 0);
            panel_system.destroyPanel("Scenario Menu Dialog");
            return 1;
        }
    }

    if (panel != 0) {
        if (panel->panelName() != 0 &&
            strcmp(panel->panelName(), "New Dialog") == 0) {
            panel_system.setCurrentPanel("Scenario Editor Screen", 0);
            panel_system.destroyPanel("New Dialog");
            panel_system.destroyPanel("Scenario Menu Dialog");

            if (event == 0) {
                sed->command_quick_save();
            }
            if (event == 0 || event == 1) {
                panel_system.destroyPanel("Scenario Menu Dialog");
                static_cast<TRIBE_Game*>(rge_base_game)
                    ->start_scenario_editor(0, 0);
            }
            if (event == 2) {
                panel_system.destroyPanel("Scenario Menu Dialog");
            }
            return 1;
        }

        if (panel->panelName() != 0 &&
            strcmp(panel->panelName(), "Open Dialog") == 0) {
            panel_system.setCurrentPanel("Scenario Editor Screen", 0);
            panel_system.destroyPanel("Open Dialog");
            panel_system.destroyPanel("Scenario Menu Dialog");

            if (event == 0) {
                sed->command_quick_save();
            }
            if (event == 0 || event == 1) {
                new TRIBE_Screen_Sed_Open;
                panel_system.setCurrentPanel("Scenario Editor Open", 0);
                panel_system.destroyPanel("Scenario Menu Dialog");
            }
            if (event == 2) {
                panel_system.destroyPanel("Scenario Menu Dialog");
            }
            return 1;
        }
    }

    return 0;
}
