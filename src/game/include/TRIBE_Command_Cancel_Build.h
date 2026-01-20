#pragma once
#include "common.h"

struct TRIBE_Command_Cancel_Build {
    uchar command;
    int unit_id;
};
static_assert(sizeof(TRIBE_Command_Cancel_Build) == 0x8, "Size mismatch");
