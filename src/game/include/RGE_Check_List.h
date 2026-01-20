#pragma once
#include "common.h"

struct RGE_Check_List {
    RGE_Check_Node* list;
};
static_assert(sizeof(RGE_Check_List) == 0x4, "Size mismatch");
