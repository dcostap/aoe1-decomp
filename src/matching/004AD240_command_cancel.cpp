

#include "../../include/scr_sed_context.h"

void TRIBE_Screen_Sed::command_cancel() {
    ((RGE_Player*)rge_base_game->get_player())->unselect_object();
    ((RGE_Player*)rge_base_game->get_player())->unselect_area();
}
