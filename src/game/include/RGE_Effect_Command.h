#pragma once
#include "common.h"

struct RGE_Effect_Command {
    uchar command;
    short change_num1;
    short change_num2;
    short change_num3;
    float change_amount;
};
static_assert(sizeof(RGE_Effect_Command) == 0xC, "Size mismatch");
