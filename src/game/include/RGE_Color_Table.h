#pragma once
#include "common.h"

class RGE_Color_Table {
public:
    // Virtuals
    virtual ~RGE_Color_Table(); // vt[0] (0x0)

    // Source of truth: `src/game/decomp/color.cpp.decomp` + `src/game/decomp/color.cpp.asm`.
    RGE_Color_Table();
    RGE_Color_Table(FILE* infile, short id);
    RGE_Color_Table(int fd);
    RGE_Color_Table(char* name);
    RGE_Color_Table(struct TDrawArea* area, long amount_percent, struct tagPALETTEENTRY* base_color_or_null, struct tagPALETTEENTRY* palette_or_null);

    void save(int fd);

    char color_table_name[30];
    short resource_id;
    unsigned char type;
    unsigned char map_color;
    short id;
    unsigned char table[256];
};
static_assert(sizeof(RGE_Color_Table) == 0x128, "Size mismatch");
