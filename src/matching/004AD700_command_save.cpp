// VA: 004AD700 TRIBE_Screen_Sed::command_save
// Attempt log:
// initial natural implementation from packet/decompiler with /GX and local stubs.

#include "../../include/scr_sed_context.h"

void TRIBE_Screen_Sed::command_save(unsigned char closeMenu, unsigned char postAction)
{
    char temp_name[260];

    this->set_scenario_mode(ScenarioModeSave);
    this->world->scenario->Save_victory_conditions_into_players(1);
    if (((RGE_Scenario*)this->world->scenario)->active_player_count() < 1) {
        panel_system.destroyPanel((char*)0x005843CC);
        this->popupOKDialog(0x2742, 0, 0x1c2, 100);
    } else if (((RGE_Scenario*)this->world->scenario)->any_player_count() < 1) {
        panel_system.destroyPanel((char*)0x005843CC);
        this->popupOKDialog(0x2743, 0, 0x1c2, 100);
    } else {
        char* name = ((RGE_Scenario*)this->world->scenario)->Get_scenario_name();
        if (*name == 0) {
            this->command_save_as(postAction);
        } else {
            ((TRIBE_Game*)rge_base_game)->show_status_message(0x450, 0, -1);
            if (closeMenu != 0) {
                panel_system.destroyPanel((char*)0x005843CC);
            }
            if (this->world->save(name) == 0) {
                ((TRIBE_Game*)rge_base_game)->close_status_message();
                this->popupOKDialog(0x963, 0, 0x1c2, 100);
            } else {
                ((TRIBE_Game*)rge_base_game)->close_status_message();
                sprintf(temp_name, (char*)0x00586D38, rge_base_game->registry->RegGetInt(0, (char*)0x0057FA58));
                if (strcmp(name, temp_name) != 0) {
                    this->need_to_save_flag = 0;
                }
                if (postAction == 1) {
                    if (((TRIBE_Game*)rge_base_game)->start_menu() == 0) {
                        ((TRIBE_Game*)rge_base_game)->close();
                    } else {
                        panel_system.destroyPanel((char*)0x00584414);
                    }
                } else if (postAction == 2) {
                    TRIBE_Screen_Sed_Open* p = new TRIBE_Screen_Sed_Open;
                    panel_system.setCurrentPanel((char*)0x005843FC, 0);
                } else if (postAction == 3) {
                    ((TRIBE_Game*)rge_base_game)->start_scenario_editor(0, 0);
                }
            }
        }
    }
}
