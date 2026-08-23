// VA: 00492DB0 TRIBE_Credits_Screen::close_screen
// PDB donor: scr_cred.cpp lines 420-433
// The original uses the absolute panel-system and game globals.

#include "../../include/scr_cred_context.h"

#define panel_system (*(TPanelSystem*)0x62E870)
#define rge_base_game (*(RGE_Base_Game**)0x62C574)

void TRIBE_Credits_Screen::close_screen()
{
    if (panel_system.panel((char*)0x5842CC)) {
        if (rge_base_game->singlePlayerGame() == 1 &&
            rge_base_game->save_paused == 0) {
            rge_base_game->set_paused(0, 0);
        }
        panel_system.setCurrentPanel((char*)0x5842CC, 0);
    } else {
        new TRIBE_Screen_Main_Menu();
        panel_system.setCurrentPanel((char*)0x5842E8, 0);
    }
    panel_system.destroyPanel((char*)0x5842BC);
}
