// 004704C0 RGE_Game_State::set_view_loc
// Source: player.cpp lines 1384-1397
// Size: 163 bytes
//
// Attempt log:
// Probe 1: natural C++

#ifndef PLAYER_GROUPED_TU
#include "..\..\include\game_globals.h"
#endif

struct RGE_Terrain_Sub {
    char _gap_00[0x08];
    int map_width;              // +0x08
    int map_height;             // +0x0C
};

class RGE_Terrain {
public:
    char _gap_00[0x28];
    RGE_Terrain_Sub* sub;       // +0x28
};

class RGE_Game_State {
public:
    char _gap_00[0x3C];
    RGE_Terrain* terrain;       // +0x3C
    char _gap_40[0xD4];
    float view_x;               // +0x114
    float view_y;               // +0x118

    void set_view_loc(float x, float y);
};

void RGE_Game_State::set_view_loc(float x, float y)
{
    this->view_x = x;
    this->view_y = y;

    if (x < 0.0f)
        this->view_x = 0.0f;
    else if (x > (float)(this->terrain->sub->map_width - 1))
        this->view_x = (float)(this->terrain->sub->map_width - 1);

    if (y < 0.0f)
        this->view_y = 0.0f;
    else if (y > (float)(this->terrain->sub->map_height - 1))
        this->view_y = (float)(this->terrain->sub->map_height - 1);
}
