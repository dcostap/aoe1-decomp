#pragma once
#include "common.h"

struct Player_Start_Info {
    int Gold;
    int Wood;
    int Food;
    int Stone;
};
static_assert(sizeof(Player_Start_Info) == 0x10, "Size mismatch");
