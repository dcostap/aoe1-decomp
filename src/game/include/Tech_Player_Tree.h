#pragma once
#include "common.h"

struct Tech_Player_Tree {
    float research_done;
    short state;
};
static_assert(sizeof(Tech_Player_Tree) == 0x8, "Size mismatch");
