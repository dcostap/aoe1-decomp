
#include "../include/dlg_sedm.h"
#include "../include/pnl_btn.h"
#include "../include/scr_sed.h"
#include "../include/scr_sedo.h"
#include "../include/tribegam.h"
#include "../include/rge_base_game_global.h"
#include "../include/resource_ids.h"
#include <string.h>

TRIBE_Dialog_Sed_Menu::TRIBE_Dialog_Sed_Menu(TRIBE_Screen_Sed* scenario_editor_in)
    : TDialogPanel("Scenario Menu Dialog"), scenario_editor(scenario_editor_in), title(0) {
    int i;

    i = 0;
    while (i < 7) {
        this->buttons[i] = 0;
        i++;
    }

    if (this->setup(scenario_editor_in->renderArea(), scenario_editor_in, 0x1CC, 0x190,
                    scenario_editor_in->get_popup_info_file(),
                    scenario_editor_in->get_popup_info_id(), 1) == 0)
        return;

    if (this->create_button(this, &this->buttons[0], IDS_SCENARIO_MENU_QUIT_TO_MAIN_MENU, 0, 0x1E, 0x14,
                            0x190, 0x28, 0, 0, 0) == 0)
        return;
    if (this->create_button(this, &this->buttons[1], IDS_SCENARIO_MENU_SAVE, 0, 0x1E, 0x46,
                            0x190, 0x28, 0, 0, 0) == 0)
        return;
    if (this->create_button(this, &this->buttons[2], IDS_SCENARIO_MENU_SAVE_AS, 0, 0x1E, 0x78,
                            0x190, 0x28, 0, 0, 0) == 0)
        return;
    if (this->create_button(this, &this->buttons[3], IDS_SCENARIO_MENU_EDIT_SCENARIO, 0, 0x1E, 0xAA,
                            0x190, 0x28, 0, 0, 0) == 0)
        return;
    if (this->create_button(this, &this->buttons[4], IDS_SCENARIO_MENU_CREATE_SCENARIO, 0, 0x1E, 0xDC,
                            0x190, 0x28, 0, 0, 0) == 0)
        return;
    if (this->create_button(this, &this->buttons[5], IDS_SCENARIO_MENU_TEST, 0, 0x1E, 0x10E,
                            0x190, 0x28, 0, 0, 0) == 0)
        return;
    if (this->create_button(this, &this->buttons[6], IDS_SCENARIO_MENU_CANCEL, 0, 0x1E, 0x154,
                            0x190, 0x28, 0, 0, 0) == 0)
        return;

    TButtonPanel* cancel = this->buttons[6];
    cancel->hotkey = 0x1B;
    cancel->hotkey_shift = 0;
}

TRIBE_Dialog_Sed_Menu::~TRIBE_Dialog_Sed_Menu() {
    panel_system.destroyPanel("Open Dialog");
    panel_system.destroyPanel("New Dialog");

    this->delete_panel((TPanel**)&this->title);

    TButtonPanel** buttons = this->buttons;
    int count = 7;
    do {
        this->delete_panel((TPanel**)buttons);
        ++buttons;
        --count;
    } while (count != 0);
}

long TRIBE_Dialog_Sed_Menu::action(TPanel* from_panel, long action_in, unsigned long action_val1, unsigned long action_val2) {
    TRIBE_Screen_Sed* sed = this->scenario_editor;
    if (action_in == 1) {
        if (from_panel == this->buttons[0]) {
            panel_system.setCurrentPanel("Scenario Editor Screen", 0);
            panel_system.destroyPanel("Scenario Menu Dialog");
            sed->command_quit();
            return 1;
        }

        if (from_panel == this->buttons[1]) {
            panel_system.setCurrentPanel("Scenario Editor Screen", 0);
            panel_system.destroyPanel("Scenario Menu Dialog");
            sed->command_save(1, 0);
            return 1;
        }

        if (from_panel == this->buttons[2]) {
            panel_system.setCurrentPanel("Scenario Editor Screen", 0);
            panel_system.destroyPanel("Scenario Menu Dialog");
            sed->command_save_as(0);
            return 1;
        }

        if (from_panel == this->buttons[3]) {
            panel_system.setCurrentPanel("Scenario Editor Screen", 0);
            panel_system.destroyPanel("Scenario Menu Dialog");
            sed->command_open();
            return 1;
        }

        if (from_panel == this->buttons[4]) {
            panel_system.setCurrentPanel("Scenario Editor Screen", 0);
            panel_system.destroyPanel("Scenario Menu Dialog");
            sed->command_new();
            return 1;
        }

        if (from_panel == this->buttons[5]) {
            panel_system.setCurrentPanel("Scenario Editor Screen", 0);
            panel_system.destroyPanel("Scenario Menu Dialog");
            char* scenario = sed->scenario_save_defaulted();
            if (scenario != 0) {
                static_cast<TRIBE_Game*>(rge_base_game)->test_scenario(scenario);
            } else {
                panel_system.destroyPanel("Scenario Menu Dialog");
            }
            return 1;
        } else if (from_panel == this->buttons[6]) {
            panel_system.setCurrentPanel("Scenario Editor Screen", 0);
            panel_system.destroyPanel("Scenario Menu Dialog");
            return 1;
        }
    }

    if (from_panel != 0) {
        if (from_panel->panelName() != 0 &&
            strcmp(from_panel->panelName(), "New Dialog") == 0) {
            panel_system.setCurrentPanel("Scenario Editor Screen", 0);
            panel_system.destroyPanel("New Dialog");
            panel_system.destroyPanel("Scenario Menu Dialog");

            if (action_in == 0) {
                sed->command_quick_save();
            }
            if (action_in == 0 || action_in == 1) {
                panel_system.destroyPanel("Scenario Menu Dialog");
                static_cast<TRIBE_Game*>(rge_base_game)
                    ->start_scenario_editor(0, 0);
            }
            if (action_in == 2) {
                panel_system.destroyPanel("Scenario Menu Dialog");
            }
            return 1;
        }

        if (from_panel->panelName() != 0 &&
            strcmp(from_panel->panelName(), "Open Dialog") == 0) {
            panel_system.setCurrentPanel("Scenario Editor Screen", 0);
            panel_system.destroyPanel("Open Dialog");
            panel_system.destroyPanel("Scenario Menu Dialog");

            if (action_in == 0) {
                sed->command_quick_save();
            }
            if (action_in == 0 || action_in == 1) {
                new TRIBE_Screen_Sed_Open;
                panel_system.setCurrentPanel("Scenario Editor Open", 0);
                panel_system.destroyPanel("Scenario Menu Dialog");
            }
            if (action_in == 2) {
                panel_system.destroyPanel("Scenario Menu Dialog");
            }
            return 1;
        }
    }

    return 0;
}
