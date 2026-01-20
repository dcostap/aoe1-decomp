#pragma once
#include "common.h"

struct RGE_Doppleganger_Creator {
    RGE_Player* owner;
    int allocated_size;
    int active_size;
    RGE_Static_Object** Objects;
    ulong** Map_Addresses;
    ulong* Last_Map_Value;
    int* Object_ids;
};
static_assert(sizeof(RGE_Doppleganger_Creator) == 0x1C, "Size mismatch");
