#ifndef PLAYER_GROUPED_TU
#include "../player_tu_context.h"
#endif

unsigned char RGE_Player::command_create_group(int a, int* b, int c, float d) {
    int pid = (int)this->id;
    this->world->command->command_create_group(pid, a, b, c, d);
    return 1;
}
