// 004ADA70 TRIBE_Screen_Sed::scenario_get_default_name
// Size: 116 bytes

#include "../../include/scr_sed_context.h"

char* TRIBE_Screen_Sed::scenario_get_default_name() {
    char temp_name[260];
    char* name;

    name = this->world->scenario->Get_scenario_name();
    if (name == 0 || name[0] == 0) {
        int file_num = rge_base_game->registry->RegGetInt(0, (char*)"Game File Number");
        sprintf(temp_name, "default%d.scx", file_num);
        this->world->scenario->Set_scenario_name(temp_name);
    }
    return this->world->scenario->Get_scenario_name();
}
