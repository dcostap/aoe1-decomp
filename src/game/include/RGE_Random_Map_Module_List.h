#pragma once
#include "common.h"

struct RGE_Random_Map_Module_List {
    RGE_Random_Map_Module* module;
    RGE_Random_Map_Module_List* next;
};
static_assert(sizeof(RGE_Random_Map_Module_List) == 0x8, "Size mismatch");
