#pragma once
#include "common.h"

struct Item_Avail {
    char* name;
    short id;
    short pict;
    short inventory_item_1;
    float inventory_cost_1;
    short inventory_item_2;
    float inventory_cost_2;
    short inventory_item_3;
    float inventory_cost_3;
    long help_string_id;
    long help_page_id;
};
static_assert(sizeof(Item_Avail) == 0x28, "Size mismatch");
