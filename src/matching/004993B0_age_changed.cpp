// VA: 004993B0 age_changed (237B)
// PDB owner: protected TRIBE_Screen_Game::age_changed, scr_game.cpp:3304-3331.
// Body: 004993B0-0049949C. 0049949D-0049949F are padding; 004994A0 is switch data.
// Do not treat the unresolved key_down_action as a sibling owner.
// FLAGS: config/flags/004993B0_age_changed.rsp (/GX; original scr_game.cpp EH context)
//
// Initial reconstruction: named age-panel/save-age ownership, the RGE player
// attribute array, and the natural get_string2/set_text/set_redraw/switch form.
// MATCH: this period-plausible reconstruction emits the original 237 bytes;
// the local class gaps preserve the proven +0x580/+0x710 ownership and do not
// use decompiler cursor arithmetic or compiler-steering code.

#if !defined(SCR_GAME_TU_CONTEXT)
 #include "../../include/scr_game_context.h"

#endif

void TRIBE_Screen_Game::age_changed() {
    char str[512];

    if (this->age_panel != 0) {
        RGE_Player* player = rge_base_game->get_player();
        this->save_age = (int)player->attributes[6];
        rge_base_game->get_string2(0x65, this->save_age, 0, str, 0x200);
        this->age_panel->set_text(str);
        this->age_panel->set_redraw(1);

        switch (this->save_age) {
        case 1:
            this->age_panel->set_help_info(0x1069, -1);
            break;
        case 2:
            this->age_panel->set_help_info(0x106A, -1);
            break;
        case 3:
            this->age_panel->set_help_info(0x106B, -1);
            break;
        case 4:
            this->age_panel->set_help_info(0x106C, -1);
            break;
        }
    }
}
