#pragma once
#include "common.h"

struct TRIBE_Command_Trade_Attribute {
    uchar command;
    uchar unit_num;
    long attribute;
};
static_assert(sizeof(TRIBE_Command_Trade_Attribute) == 0x8, "Size mismatch");
