// VA: 00524790 TRIBE_Game::save_scenario (228 B)
// PDB source: tribegam.cpp (lines 1965-1997)
// Attempt log:
// baseline (sa-e31ff4e8): canonical reconstruction from packet + exact donors.
//   - prog_mode at RGE_Base_Game+0x1B0 must be one of {4,6,7,5} (je chain into body)
//   - world (RGE_Game_World*) at +0x3F4; player_num (short) at world+0x3C;
//     scenario (RGE_Scenario*) at world+0x5C (matches RGE_Game_World layout and
//     the 004A8060 world->scenario access pattern)
//   - RGE_Game_World::save_scenario(char*) is the virtual at vtable+0xE4 (slot 57),
//     returns uchar tested via al (matches 004A8060's [eax+0E4h] virtual save)
//   - loop activates players 1..player_num-1 via Set_player_Active(i-1, 1)
//     (0048BC00), world kept in eax across the loop, reloaded after the call
//   - panel_system global 0x62E870 setCurrentPanel/destroyPanel string calls

#ifndef TRIBEGAM_TU_CONTEXT
#include "../tribegam_context_local.h"
#define TRIBEGAM_TU_CONTEXT 1
#endif

int TRIBE_Game::save_scenario(char* filename)
{
    if (this->prog_mode != 4 && this->prog_mode != 6 &&
        this->prog_mode != 7 && this->prog_mode != 5) {
        return 0;
    }

    this->disable_input();
    this->show_status_message(0x450, 0, -1);

    for (int i = 1; i < this->world->player_num; i++) {
        this->world->scenario->Set_player_Active(i - 1, 1);
    }

    if (this->world->save_scenario(filename) == 0) {
        this->enable_input();
        return 0;
    }

    if (this->singlePlayerGame() == 1) {
        this->set_paused(0, 0);
    }

    panel_system.setCurrentPanel("Game Screen", 0);
    panel_system.destroyPanel("Save Game Screen");
    panel_system.destroyPanel("Status Screen");

    this->enable_input();
    return 1;
}
