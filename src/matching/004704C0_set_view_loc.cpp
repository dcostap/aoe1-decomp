// 004704C0 RGE_Player::set_view_loc
// Source: player.cpp lines 1384-1397
// Size: 163 bytes
//
// Attempt log:
// Probe 1: natural C++

#ifndef PLAYER_GROUPED_TU
#include "../player_tu_context.h"
#endif

void RGE_Player::set_view_loc(float x, float y)
{
    this->view_x = x;
    this->view_y = y;

    if (x < 0.0f)
        this->view_x = 0.0f;
    else if (x > (float)(this->world->map->map_width - 1))
        this->view_x = (float)(this->world->map->map_width - 1);

    if (y < 0.0f)
        this->view_y = 0.0f;
    else if (y > (float)(this->world->map->map_height - 1))
        this->view_y = (float)(this->world->map->map_height - 1);
}
