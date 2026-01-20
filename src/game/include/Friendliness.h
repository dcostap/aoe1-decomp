#pragma once
#include "common.h"

struct Friendliness {
    int Attitude[16];
};
static_assert(sizeof(Friendliness) == 0x40, "Size mismatch");
