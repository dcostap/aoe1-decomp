#pragma once
#include "common.h"

struct TRIBE_Command_Game {
    uchar command;
    uchar game_command;
    short var1;
    short var2;
    float var3;
    short var4;
};
static_assert(sizeof(TRIBE_Command_Game) == 0x10, "Size mismatch");
