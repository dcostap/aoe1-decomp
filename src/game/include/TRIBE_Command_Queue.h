#pragma once
#include "common.h"

struct TRIBE_Command_Queue {
    uchar command;
    long bldg_id;
    short train_id;
    short train_count;
};
static_assert(sizeof(TRIBE_Command_Queue) == 0xC, "Size mismatch");
