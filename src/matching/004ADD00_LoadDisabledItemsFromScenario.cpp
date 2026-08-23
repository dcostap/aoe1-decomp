// 004ADD00 TRIBE_Screen_Sed::LoadDisabledItemsFromScenario
// The PDB line change puts the scenario getter on line 361 and its test on
// line 362. A named result recovers that source split and the register map.
//
// Tried: variable type (int/unsigned/short), declaration order,
// initialization order (comma operator, separate statements),
// loop structure (for/do-while), variable naming (i/idx/loop).
// All produce the same ESI/EDI swap without the named getter result.
// Exact finish: a 20-form natural sweep found only the named result exact.
// Removing it restores the seven-byte register recolor.

#include "../../include/scr_sed2_context.h"

void TRIBE_Screen_Sed::LoadDisabledItemsFromScenario(void) {
    TButtonPanel** button;
    int i;
    int disabled;

    for (i = 0, button = this->options_disable_button; i < 16; i++, button++) {
        disabled = this->world->scenario->GetDisabledTechnology(this->player_num - 1, i);
        if (disabled != 0) {
            (*button)->set_state(0);
        }
        else {
            (*button)->set_state(1);
        }
    }
}
