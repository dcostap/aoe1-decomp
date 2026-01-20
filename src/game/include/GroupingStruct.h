#pragma once
#include "common.h"

struct GroupingStruct {
    int id;
    uchar groupID;
    uchar type;
};
static_assert(sizeof(GroupingStruct) == 0x8, "Size mismatch");
