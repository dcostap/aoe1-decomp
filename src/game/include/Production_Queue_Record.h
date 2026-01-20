#pragma once
#include "common.h"

struct Production_Queue_Record {
    short master_id;
    short unit_count;
};
static_assert(sizeof(Production_Queue_Record) == 0x4, "Size mismatch");
