#pragma once
#include "common.h"

struct TRIBE_Command_Give_Attribute {
    uchar command;
    uchar player_id;
    uchar to_player_id;
    uchar attr_id;
    float attr_amount;
    float attr_cost;
};
static_assert(sizeof(TRIBE_Command_Give_Attribute) == 0xC, "Size mismatch");
