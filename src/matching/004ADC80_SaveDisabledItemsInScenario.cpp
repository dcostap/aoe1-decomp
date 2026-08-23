// VA: 004ADC80 TRIBE_Screen_Sed::SaveDisabledItemsInScenario()
// PDB source: scr_sed2.cpp lines 343-352
// Default flags
//
// __thiscall: this in ecx, no stack params. void return.

#include "../../include/scr_sed2_context.h"

void TRIBE_Screen_Sed::SaveDisabledItemsInScenario() {
    // Load this into local pointer to influence register choice
    TRIBE_Screen_Sed* th = this;
    short pn0 = th->player_num;
    if (pn0 == 0) {
        th->player_num = 1;
    }

    for (int i = 0; i < 16; i++) {
        int state = th->options_disable_button[i]->get_state();
        if (state != 0) {
            int player_idx = (int)(short)th->player_num - 1;
            void* scenario = *(void**)((int)th->world + 0x5C);
            ((T_Scenario*)scenario)->SetDisabledTechnology(player_idx, i, 0);
        } else {
            int player_idx = (int)(short)th->player_num - 1;
            void* scenario = *(void**)((int)th->world + 0x5C);
            ((T_Scenario*)scenario)->SetDisabledTechnology(player_idx, i, 1);
        }
    }

    long line = th->options_player_list->get_line();
    th->player_num = (short)(line + 1);
}
