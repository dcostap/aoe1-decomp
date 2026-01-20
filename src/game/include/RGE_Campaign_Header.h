#pragma once
#include "common.h"

struct RGE_Campaign_Header {
    long version;
    char name[255];
    long scenario_num;
};
static_assert(sizeof(RGE_Campaign_Header) == 0x108, "Size mismatch");
