#include "../../include/tvictory_context.h"

void TRIBE_Victory_Conditions::handle_condition(RGE_Victory_Entry* entry) {
    if (entry->command != 'd') {
        RGE_Victory_Conditions::handle_condition(entry);
        return;
    }
    handle_tech(entry);
}
