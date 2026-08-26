#ifndef PLAYER_GROUPED_TU
#include "../player_tu_context.h"
#endif

void RGE_Player::load_info(int infile) {
    this->load_victory(infile, 0, 1);
    this->objects->rehook_list();
    this->sleeping_objects->rehook_list();
    this->doppleganger_objects->rehook_list();
}
