#pragma once
#include "common.h"

struct NAME {
    char Text[128];
};
static_assert(sizeof(NAME) == 0x80, "Size mismatch");
