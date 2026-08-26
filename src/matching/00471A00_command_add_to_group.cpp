#ifndef PLAYER_GROUPED_TU
#include "../player_tu_context.h"
#endif

unsigned char RGE_Player::command_add_to_group(int a, int b, float c) {
    int pid = (int)this->id;
    this->world->command->command_add_to_group(pid, a, b, c);
    return 1;
}
