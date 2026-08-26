#ifndef PLAYER_GROUPED_TU
#include "../player_tu_context.h"
#endif

unsigned char RGE_Player::command_remove_from_group(int a, int b) {
    int pid = (int)this->id;
    this->world->command->command_remove_from_group(pid, a, b);
    return 1;
}
