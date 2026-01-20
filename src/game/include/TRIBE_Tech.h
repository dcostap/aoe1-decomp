#pragma once
#include "common.h"

struct TRIBE_Tech {
    Tech_Tree* tech_tree;
    short tech_tree_num;
    TRIBE_World* world;
};
static_assert(sizeof(TRIBE_Tech) == 0xC, "Size mismatch");
