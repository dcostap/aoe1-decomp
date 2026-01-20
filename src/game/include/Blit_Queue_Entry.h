#pragma once
#include "common.h"

struct Blit_Queue_Entry {
    tagRECT src;
    tagRECT dest;
};
static_assert(sizeof(Blit_Queue_Entry) == 0x20, "Size mismatch");
