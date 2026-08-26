#ifndef PLAYER_GROUPED_TU
#include "../player_tu_context.h"
#endif

unsigned char RGE_Player::command_resign(int a, int b) {
    if (!this->game_status) {
        this->world->command->command_resign((int)this->id, a, b);
        return 1;
    }
    return 0;
}
