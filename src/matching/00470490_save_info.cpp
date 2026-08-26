#ifndef PLAYER_GROUPED_TU
#include "../player_tu_context.h"
#endif

void RGE_Player::save_info(int param) {
    this->victory_conditions->save(param);
}
