

#include "../../include/scr_sed_context.h"

void TRIBE_Screen_Sed::set_player_active(short player, int active) {
    this->world->scenario->Set_player_Active((int)player, active);
}
