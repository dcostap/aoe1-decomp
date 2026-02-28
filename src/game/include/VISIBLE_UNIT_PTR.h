#pragma once
#include "common.h"
#include "VISIBLE_UNIT_REC.h"

struct VISIBLE_UNIT_PTR {
    VISIBLE_UNIT_REC* unit_list;
    short list_size;
    short used;
};
static_assert(sizeof(VISIBLE_UNIT_PTR) == 0x8, "Size mismatch");
