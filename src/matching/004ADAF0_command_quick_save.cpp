

#include "../../include/scr_sed_context.h"

void TRIBE_Screen_Sed::command_quick_save(void) {
    this->scenario_get_default_name();
    this->command_save(0, 0);
}
