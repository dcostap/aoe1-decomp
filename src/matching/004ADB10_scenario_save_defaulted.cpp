// VA: 004ADB10 TRIBE_Screen_Sed::scenario_save_defaulted
// Attempt log:
// baseline: natural typed save flow from scr_sed.cpp line bands; world/scenario
// ownership is named and the 0x86bad8 buffer is the proven shared output buffer.

#include "../../include/scr_sed_context.h"

char* TRIBE_Screen_Sed::scenario_save_defaulted() {
    this->set_scenario_mode(ScenarioModeSave);
    this->world->scenario->Save_victory_conditions_into_players(1);
    if (((RGE_Scenario*)this->world->scenario)->active_player_count() < 1) {
        this->popupOKDialog(0x2742, 0, 0x1c2, 100);
        return 0;
    }
    if (((RGE_Scenario*)this->world->scenario)->any_player_count() < 1) {
        this->popupOKDialog(0x2743, 0, 0x1c2, 100);
        return 0;
    }

    ((TRIBE_Game*)rge_base_game)->show_status_message(0x450, 0, -1);
    sprintf(DAT_0086bad8, "default%d.scx",
            rge_base_game->registry->RegGetInt(0, (char*)"Game File Number"));
    if (this->world->save(DAT_0086bad8) == 0) {
        ((TRIBE_Game*)rge_base_game)->close_status_message();
        this->popupOKDialog(0x963, 0, 0x1c2, 100);
        return 0;
    }

    sprintf(DAT_0086bad8, "default%d",
            rge_base_game->registry->RegGetInt(0, (char*)"Game File Number"));
    return DAT_0086bad8;
}
