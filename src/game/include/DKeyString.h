#pragma once
#include "common.h"

struct DKeyString {
    DString keyValue;
    DString valueValue;
};
static_assert(sizeof(DKeyString) == 0x28, "Size mismatch");
