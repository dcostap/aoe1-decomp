#pragma once
#include "common.h"

struct Tech_Tree {
    char* name;
    short pre_reqs[4];
    short pre_reqs_required;
    short attribute[3];
    short attribute_cost[3];
    uchar attribute_used[3];
    short research;
    short effect;
    short track;
    short icon;
    uchar button_location;
    short build_obj_id;
    short string_id;
    short string_id2;
    long help_string_id;
    long help_page_id;
    long hotkey_id;
};
static_assert(sizeof(Tech_Tree) == 0x3C, "Size mismatch");
