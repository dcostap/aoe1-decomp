#pragma once
#include "common.h"

class RGE_Color_Table {
public:
    // Virtuals (best-effort)
    virtual ~RGE_Color_Table(); // vt[0] (0x0)

    char color_table_name[30];
    short resource_id;
    unsigned char type;
    unsigned char map_color;
    short id;
    unsigned char table[256];
};
static_assert(sizeof(RGE_Color_Table) == 0x128, "Size mismatch");
