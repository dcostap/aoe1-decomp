// TRIBE_Screen_Sed::activate_victory_panel
// VA: 004B29E0
// Retry 2026-05-26: real thiscall member with padded virtual surfaces.

#include "../../include/scr_sed2_context.h"

void TRIBE_Screen_Sed::activate_victory_panel(int flag)
{
    int i = 0;
    register TButtonPanel** pp = this->victory_button;
    do {
        (*pp)->set_active(flag);
        int val = ((this->world->scenario->GetSPVictoryType(i) ? -1 : 0) & 2) + (this->CurrentVictory == i);
        if (flag) {
            (*pp)->set_state(val);
        }
        ++i;
        ++pp;
    } while (i < 12);

    this->victory_drop_down->set_active(flag);
    this->victory_condition_text->set_active(flag);
    this->victory_player_list->set_active(flag);
    if (flag) {
        this->victory_player_list->set_line((int)this->player_num - 1);
    } else {
        this->player_num = (short)(this->victory_player_list->get_line() + 1);
    }
}
