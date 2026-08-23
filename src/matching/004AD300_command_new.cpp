// tried the direct need_to_save / popupYesNoCancelDialog / start_scenario_editor shape; still off in early branch layout

#include "../../include/scr_sed_context.h"

void TRIBE_Screen_Sed::command_new(void) {
    if (this->need_to_save()) {
        this->popupYesNoCancelDialog(0x2447, s_NewSaveDialog, 0x1C2, 100);
        return;
    }
    ((TRIBE_Game*)rge_base_game)->start_scenario_editor((char*)0, 0);
}
