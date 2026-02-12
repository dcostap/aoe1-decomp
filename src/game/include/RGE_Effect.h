#pragma once
#include "common.h"
#include "RGE_Effect_Command.h"

struct RGE_Effect {
    short id;
    char name[31];
    short string_table_id;
    short effect_list_num;
    RGE_Effect_Command* effect_list;
};
static_assert(sizeof(RGE_Effect) == 0x2C, "Size mismatch");
