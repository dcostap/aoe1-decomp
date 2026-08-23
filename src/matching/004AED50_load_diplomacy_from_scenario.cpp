// TRIBE_Screen_Sed::load_diplomacy_from_scenario
// VA: 004AED50
// MATCHED 2026-05-21: real member declarations for T_Scenario and TButtonPanel,
// plus a vtable-padded TButtonPanel surface placing set_value at slot +0xE0,
// recover direct thiscall and virtual call shapes. Raw offsets for overlapping UI
// button arrays avoid forcing an impossible struct layout.

#include "../../include/scr_sed2_context.h"

void TRIBE_Screen_Sed::load_diplomacy_from_scenario(int player)
{
    if (player >= 0) {
        int i = 0;
        TButtonPanel** allied = (TButtonPanel**)((char*)this + 0x908);
        TButtonPanel** boxes = (TButtonPanel**)((char*)this + 0x8AC);
        do {
            int att = this->world->scenario->Get_player_attitude(player, i);
            if (att == 0)
                boxes[-1]->set_radio_button();
            if (att == 1)
                boxes[0]->set_radio_button();
            if (att == 3)
                boxes[1]->set_radio_button();
            (*allied)->set_state(0);
            i++;
            allied++;
            boxes += 3;
        } while (i < 8);
        (*(TButtonPanel**)((char*)this + 0x908 + player * 4))->set_state(this->world->scenario->GetPlayerAlliedVictory(player));
    }
}
