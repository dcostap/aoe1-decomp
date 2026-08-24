#include "../../include/tvictory_context.h"

void TRIBE_Victory_Conditions::handle_tech(RGE_Victory_Entry* entry) {
    TRIBE_Player* player = static_cast<TRIBE_Player*>(this->player);
    if ((player != 0) && (entry->state == 0)) {
        if (player->tech_tree->get_tech_state(entry->count) == 3) {
            entry->state = 2;
        }
    }
}
