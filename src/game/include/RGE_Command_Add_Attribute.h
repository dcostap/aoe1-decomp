#pragma once
#include "common.h"

struct RGE_Command_Add_Attribute {
    uchar command;
    uchar player_id;
    uchar attr_id;
    float attr_amount;
};
static_assert(sizeof(RGE_Command_Add_Attribute) == 0x8, "Size mismatch");
