#pragma once
#include "common.h"

struct TRIBE_Player_Tech {
    Tech_Player_Tree* tech_player_tree;
    short tech_player_tree_num;
    TRIBE_Tech* base_tech;
    RGE_Player* owner;
};
static_assert(sizeof(TRIBE_Player_Tech) == 0x10, "Size mismatch");
