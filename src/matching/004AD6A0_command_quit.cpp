

#include "../../include/scr_sed_context.h"

void TRIBE_Screen_Sed::command_quit() {
    if (need_to_save()) {
        popupYesNoCancelDialog(0x2447, (char*)0x586D18, 0x1C2, 0x64);
        return;
    }
    if (!((TRIBE_Game*)rge_base_game)->start_menu()) {
        ((TRIBE_Game*)rge_base_game)->close();
        return;
    }
    panel_system.destroyPanel((char*)0x584414);
}
